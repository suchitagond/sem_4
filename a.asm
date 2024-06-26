%macro print 2
mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endmacro

%macro read 2
mov rax,0
mov rdi,0
mov rsi,%1
mov rdx,%2
syscall
%endmacro

section .data										 	;data section begins
m1 db 10d,13d,"enter a string : "						;m1 initialize with string 
l1 equ $-m1                                            ;L1 store the length of m1
m2 db 10d,13d,"entered string : "
l2 equ $-m2
m3 db 10d,13d,"length : "
l3 equ $-m3

section .bss												;buffer section
buffer resb 50											;buffer array of size 50 resever byte
size equ $-buffer
count resd 1											;resever double
dispnum resb 16											;display the 16 digit length

section .text
global _start											;move to the start
_start:
print m1,l1
read buffer,size
mov [count],rax
print m2,l2
print buffer,[count]

call display

Exit:
mov rax,60
mov rbx,0
syscall

display:
mov rsi,dispnum+15
mov rax,[count]
mov rcx,16
dec rax

up1:
mov rdx,0
mov rbx,10
div rbx
add dl,30h
mov[rsi],dl
dec rsi
loop up1

print m3,l3
print dispnum+14,2
ret



