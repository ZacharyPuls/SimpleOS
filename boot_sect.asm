; Bootloader
; Zachary Puls - 05/19/2016

ORG 0x7C00
BITS 16

JMP START

; OEM Parameter Block

bpbOEM                       DB        "SimpleOS"

bpbBytesPerSector            DW        512
bpbSectorsPerCluster         DB        1
bpbReservedSectors           DW        1
bpbNumberOfFATs              DB        2
bpbRootEntries               DW        224
bpbTotalSectors              DW        2880
bpbMedia                     DB        0xF0
bpbSectorsPerFAT             DW        9
bpbSectorsPerTrack           DW        18
bpbHeadsPerCylinder          DW        2
bpbHiddenSectors             DD        0
bpbTotalSectorsBig           DD        0
bsDriveNumber                DB        0
bsUnused                     DB        0
bsExtBootSignature           DB        0x29
bsSerialNumber               DD        0xA0A1A2A3
bsVolumeLabel                DB        "MOS FLOPPY "
bsFileSystem                 DB        "FAT12   "

; Data definitions

VERSION_STR                  DB        "SimpleOS v0.1", 0
COPYRIGHT_STR                DB        "Copyright (c) 2016 Zachary Puls", 0
BLANKLN_STR                  DB        "", 0
MISC_STR                     DB        "All rights reserved.", 0

LINE_NUMBER                  DB        1

PRINTLN:
    LODSB
	OR AL, AL                ; Are we at the end of the string?
	JZ ENDPRINTLN            ; If so, finish PRINTSTR.
	MOV AH, 0x0E             ; TTY Output
	INT 0x10
	JMP PRINTLN
	
ENDPRINTLN:
    MOV AH, 0x02
	MOV DH, [LINE_NUMBER]
	MOV DL, 0x00
	INT 0x10
	INC BYTE [LINE_NUMBER]
	RET	
	
START:
    MOV AX, 3
	INT 0x10                 ; Clear screen.
	
	XOR AX, AX
	MOV DS, AX
	MOV ES, AX
	
	MOV SI, VERSION_STR
	CALL PRINTLN
	
	MOV SI, COPYRIGHT_STR
	CALL PRINTLN
	
	MOV SI, BLANKLN_STR
	CALL PRINTLN
	
	MOV SI, MISC_STR
	CALL PRINTLN
	
	CLI
	HLT
	
times 510-($ - $$) db 0      ; Pad the file to 512 bytes.


dw 0xAA55                    ; Boot sector magic number.