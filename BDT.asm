%macro print 2
mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endmacro

section .data
m1 db 10,"ALP to perform non-overlap BDT without using string related instruction",10
l1 equ $-m1

m2 db 10,"Source block contents are- "
l2 equ $-m2

m3 db 10,"Destination block content are (after transfer)- "
l3 equ $-m3

												;dstblk db 00,00,00,00,00

space db " "
spacelen equ $-space

cnt equ 05

srcblk db 10h,20h,30h,40h,50h

section .bss
ans resb 02
dstblk resb 05

section .txt
global _start
_start:

print m1,l1
print m2,l2
mov rsi,srcblk
call display

print m3,l3
mov rsi,srcblk
mov rdi,dstblk
mov rcx,05

up1:
mov al,[rsi]
mov [rdi],al
inc rsi
inc rdi
loop up1

mov rsi,dstblk
call display

exit:
mov rax,60
mov rdi,0
syscall

display:
mov rbp,cnt
back:        										;lable
mov al,[rsi]
push rsi
call disp_8
                                            ;hexa to ascii coversion method
print space,1
pop rsi
inc rsi
dec rbp
jnz back
ret

disp_8:
mov rdi,ans
mov rcx,02

up:
rol al,4
mov dl,al
and dl,0fh												
add dl,30h												
cmp dl,39h													
jbe skip													
add dl,07h													

skip:
mov [rdi],dl
inc rdi
loop up

print ans,02
ret													


