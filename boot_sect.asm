; Bootloader
; Zachary Puls - 05/19/2016

ORG 0x7C00
BITS 16

JMP __START

; Data definitions

VERSION_STR                  DB        "SimpleOS v0.1", 0
COPYRIGHT_STR                DB        "Copyright (c) 2016 Zachary Puls.", 0
MISC_STR                     DB        "All rights reserved.", 0
BLANKLN_STR									 DB				 "", 0

PAGE_NUMBER									 DB					0
COL_NUMBER									 DB					0
ROW_NUMBER	                 DB					4

GETCRSR:
	MOV AH, 0x03						; AH = 0x03, Get cursor position and size
	MOV BH, [PAGE_NUMBER]		; BH = [0-7], Page number
	INT 0x10								; Get cursor location
													; DH = row, with 0x00 being the top

INITSCRN:
	MOV AX, 0x0003					; AH = 0x00, Set video mode
													; AL = 0x03, Text mode, 80 columns x 25 lines per page, 8 pages, 16 colors
	INT 0x10								; Initialize screen

CLRSCRN:
	INC BYTE [PAGE_NUMBER]
	MOV BYTE [COL_NUMBER], 0x00	; Reset cursor column
	MOV BYTE [ROW_NUMBER], 0x00	; Reset cursor row
	MOV AH, 0x02								; AH = 0x02, Set cursor position
	MOV BH, [PAGE_NUMBER]				; BH = [0-7], Page number
	MOV DX, 0x0000							; DH = 0x00, Row (0 = top)
															; DL = 0x00, Column (0 = left)
	INT 0x10										; Clear screen
	

PRINTLN:
	LODSB
	OR AL, AL               ; Are we at the end of the string?
	JZ ENDPRINTLN           ; If so, finish PRINTSTR
	MOV AH, 0x0E            ; TTY Output
	INT 0x10
	JMP PRINTLN
	
ENDPRINTLN:
	MOV AH, 0x02
	MOV DH, [ROW_NUMBER]
	MOV DL, 0x00
	INT 0x10
	INC BYTE [ROW_NUMBER]
	RET	

GLOBAL_DESCRIPTOR_TABLE:
	; Null Segment (Selector = 0x00)
	DQ		0x0000000000000000, 0x0000000000000000		; Zero everything out
	; Code Segment (Selector = 0x08)
	DW		0x04											; Segment Limit (16 low-order bits), 0x0004 pages (4KiB * 4 pages = 16KiB)
	DW		0x0000										; Base Address (16 low-order bits), 0x0000
	DB		0x01											; Base Address (bits 16-23), 0x01 makes the base address 0x10000 (64KiB)
	DB		0x9A											; Access Byte, 0x9A = code segment
	DB		0xC0											; Limit (4 high-order bits) and Flags (4 bits), 0xC0 = 4KiB page, 32-bit protected mode
	DB		0x00											; Base Address (8 high-order bits), 0x00
	; Data Segment (Selector = 0x10)
	DW		0x04											; Segment Limit (16 low-order bits), 0x0004 pages (4KiB * 4 pages = 16KiB)
	DW		0x0000										; Base Address (16 low-order bits), 0x0000
	DB		0x01											; Base Address (bits 16-23), 0x01 makes the base address 0x10000 (64KiB)
	DB		0x92											; Access Byte, 0x92 = data segment
	DB		0xC0											; Limit (4 high-order bits) and Flags (4 bits), 0xC0 = 4KiB page, 32-bit protected mode
	DB		0x00											; Base Address (8 high-order bits), 0x00
	; TSS (Selector = 0x18)
	; TODO: TSS									

GDT_SIZE		DW		$ - GLOBAL_DESCRIPTOR_TABLE

GDT_DESCRIPTOR:
	DW GDT_SIZE													; GDT size
	DQ GLOBAL_DESCRIPTOR_TABLE					; Pointer to address of GDT

__START:

	CALL INITSCRN
	CALL CLRSCRN

	CALL GETCRSR
	ADD DH, 1
	MOV BYTE [ROW_NUMBER], DH

	; MOV DS, AX
	; MOV ES, AX
	
	MOV SI, VERSION_STR
	CALL PRINTLN
	
	MOV SI, COPYRIGHT_STR
	CALL PRINTLN
	
	MOV SI, BLANKLN_STR
	CALL PRINTLN
	
	MOV SI, MISC_STR
	CALL PRINTLN
	
	MOV SI, BLANKLN_STR
	CALL PRINTLN

	; Enter Protected Mode
	CLI										; Disable interrupts
	LGDT [GDT_DESCRIPTOR] ; Load Global Descriptor Table
	MOV EAX, CR0
	OR AL, 0x01
	MOV CR0, EAX

	; Set registers and JMP to kernel
	MOV AX, 0x10
	MOV DS, AX
	MOV ES, AX
	MOV FS, AX
	MOV GS, AX
	MOV SS, AX
	JMP 8:0x10000

	
TIMES 510-($ - $$) DB 0      ; Pad the file to 512 bytes


DW 0xAA55                    ; Boot sector magic number
