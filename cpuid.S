; Test to see if CPUID is supported.
; Per Intel:
; The ID flag (bit 21) in the EFLAGS register indicates support for the CPUID instruction. If a software procedure can
; set and clear this flag, the processor executing the procedure supports the CPUID instruction. This instruction operates
; the same in non-64-bit modes and 64-bit mode

cpuid_supported:
    ; PUSHFD (push EFLAGS onto stack)
    ; BTS (bit test and set)
    ; BTR
    ; POPFD
    pushfd
    pop %eax
    and %eax, 0x200000 ; Set the 21st bit of EFLAGS (CPUID)
    popfd
    pushfd
    bts 
    popfd
