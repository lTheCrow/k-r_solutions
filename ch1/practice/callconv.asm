caller:
    push    ebp             ; save old call frame
    mov     ebp, esp        ; initialize new call frame
    sub     esp, 12         ; reserve 12 bytes of space in the stack (4*3 bytes)
    mov     [ebp-4], 3      ; store 3 in stack ([esp+8] is the same address)
    mov     [ebp-8], 2      ; ...
    mov     [ebp-12], 1     ; ... 
    call    callee          ; call subroutine0
    
    add     esp, 12         ; remove call arguments from stack frame
    add     eax, 5          ; modify subroutine result

    mov     esp, ebp
    pop     ebp             ; restore old call frame
    ret                     ; return    
