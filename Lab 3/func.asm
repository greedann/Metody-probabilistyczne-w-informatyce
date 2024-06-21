section .data
    hunded dq 100.0

section .bss

section .text
    global func

func:
	push rbp
    mov  rbp, rsp

    movsd     xmm1, [rel hunded]
    mulsd     xmm1, xmm0
    cvttsd2si eax,  xmm1
    add       eax,  50

    pop rbp
    ret

section .note.GNU-stack noexec
