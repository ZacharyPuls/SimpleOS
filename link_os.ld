OUTPUT_FORMAT("binary")
ENTRY(__start)
kernel_start = 0x00010000;
SECTIONS {
	.text kernel_start : AT(kernel_start) {
		code = .;
		*(.text)
		*(.rodata)
		. = ALIGN(4096);
	}
	.data : {
		data = .;
		*(.data)
		. = ALIGN(4096);
	}
	.bss :	{
		bss = .;
		*(.bss)
		. = ALIGN(4096);
	}
	end = .;
}
