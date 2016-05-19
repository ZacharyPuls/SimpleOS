; Bootloader
; Zachary Puls - 05/19/2016

repeat:
	jmp repeat
	
times 510-($ - $$) db 0      ; Pad the file to 512 bytes.


dw 0xaa55                    ; Boot sector magic number.