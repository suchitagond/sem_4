%macro print 2
mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endmacro

section .data
	array db 11h,59h,33h,22h,44h
	
	msg1 db 10,"APL to find the largest no. in an array"
	msg1_len equ $ - msg1
	
	msg2 db 10,"The array contain the elements : "
	msg2_len equ $ - msg2
	
	msg3 db 10,"The largest element in array : "
	msg3_len equ $ - msg3
	
	space db " "
	newline db 10

section .bss
	counter resb 1
	result resb 4
	
section .text
	global _start
	_start:
		print msg1,msg1_len
		print msg2,msg2_len
		
		mov byte[counter],05
		mov rsi,array
		
	next:
		mov al,[rsi]
		push rsi
		call disp
		print space,1
		pop rsi
		inc rsi
		dec byte[counter]
		jnz next
		
	print msg3,msg3_len
	
	mov byte[counter],05
	mov rsi,array
	mov al,0
	
	repeat:
		cmp al,[rsi]
		jg skip                            ;if al>[rsi] the jmp to skip else mov
		mov al,[rsi]
		
	skip:
		inc rsi
		dec byte[counter]
		jnz repeat
		
		call disp
		
	exit:
		mov rax,60
		mov rdi,0
		syscall
		
	disp:
		mov bl,al
		mov rdi,result                    ;rdi point to result variable
		mov cx,02
		
	up:
		rol bl,04
		mov al,bl
		and al,0fh
		cmp al,09h
		jg add_37                         ;if al>09 the go to add_37
		add al,30h
		
	skip1:
		mov [rdi],al
		inc rdi
		dec cx
		jnz up                            ;jump if not 0
		print result,02
		print space,1
		print newline,1
		ret
	
	add_37:
		add al,37h
	
	
	
	
	
	
	
	
	
	
	
	
	
	
