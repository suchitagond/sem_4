%macro print 2
mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endmacro

section .data
m1 db 10d,13d,"ALP to perform block data transfer without string related instruction"
l1 equ $-m1
m2 db 10d,13d,"Source block contents are- "
l2 equ $-m2
m3 db 10d,13d,"Destination block content are (after transfer)- "
l3 equ $-m3

srcblk db 10,20,30,40,50
dstblk db 00,00,00,00,00

space db " "
cnt db 05

section .bss
ans resb 02
dispbuff resb 05

section .txt
global _start
_start:
print m1,l1
print m2,l2
mov rsi,srcblk
call display

exit:
mov rax,60
syscall

display:
mov rbp,cnt
back:        										;lable
mov al,[rsi]
push rsi
call disp_8                                            ;hexa to ascii coversion method
print space,1
pop rsi
inc rsi
dec rbp
jnz back
ret

disp_8:
mov rsi,ans
mov bl,al
mov dl,bl
rol bl,04
and bl,0fh
cmp bl,09h
jbe add30
add bl,07h

add30:
add bl,30h
mov [rsi],bl
inc rsi
mov bl,al
and bl,0fh
cmp bl,09h
jbe add130
add bl,07h

add130:
add bl,30h
mov [rsi],bl
print ans,2
ret



