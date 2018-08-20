LINE_NUMBER                  DB        1

PRINTLN:
    LODSB
	OR AL, AL                ; Are we at the end of the string?
	JZ ENDPRINTLN            ; If so, finish PRINTSTR
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