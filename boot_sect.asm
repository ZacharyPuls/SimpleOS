; Bootloader
; Zachary Puls - 05/19/2016

ORG 0x7C00
BITS 16

JMP START

; BIOS Parameter Block

bpbOEM                       DB        "SimpleOS"

bpbBytesPerSector            DW        512
bpbSectorsPerCluster         DB        1
bpbReservedSectors           DW        1
bpbNumberOfFATs              DB        2
bpbRootEntries               DW        224
bpbTotalSectors              DW        2880
bpbMedia                     DB        0xF0				; Ignored for FAT12
bpbSectorsPerFAT             DW        9
bpbSectorsPerTrack           DW        18
bpbHeadsPerCylinder          DW        2
bpbHiddenSectors             DD        0				; Ignored for FAT12
bpbTotalSectorsBig           DD        0				; Always 0 for FAT12
bsDriveNumber                DB        0				; Ignored for FAT12
bsUnused                     DB        0				; Ignored for FAT12
bsExtBootSignature           DB        0x29
bsSerialNumber               DD        0xFFFFFFFF		; Should be generated. Used to detect whether the wrong disk is inserted (Volume Tracking)
bsVolumeLabel                DB        "MOS FLOPPY "	; Also helps with Volume Tracking
bsFileSystem                 DB        "FAT12   "		

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
	DW		0x04											; Segment Limit (16 low-order bits), 4 pages
	DW		0													; Base Address (16 low-order bits)
	DB		0, 0, 0, 0								; 

GDT_DESCRIPTOR:
	DW 0x27												; GDT limit
	DQ GLOBAL_DESCRIPTOR_TABLE			; Pointer to address of GDT

START:

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
	
	CLI

	
TIMES 510-($ - $$) DB 0      ; Pad the file to 512 bytes


DW 0xAA55                    ; Boot sector magic number
