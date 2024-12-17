;Y=((В−2*C)**2
data segment 

	B dw ?
	C dw ?
	Y1 dw ?
	Y2 dw ?
	
	STOP_F dw ?
	B_STOP_F dw ?
	C_STOP_F dw ?
	
data ends 
code segment 
assume cs: code, ds: data, ss: nothing
start: 
		mov ax, data
		mov ds, ax
		
	mov STOP_F, 0
	mov B_STOP_F, 0
	mov C_STOP_F, 0

	mov ax, C
	sal ax, 1
	jo C_STOP
	
	mov bx, B
	sub bx, ax
	jo B_STOP
	
	mov ax, bx
	
	mov cx, 16 
	test ax, 8000h 
	JZ mul_A 
	not ax 
	inc ax 
	mov bx, ax;
	
mul_A: 
	rcr bx,1 
	jnc a_1 
	add dx, ax 
	
a_1: 
	rcr dx, 1 
	loop mul_A 
	rcr bx,1 
	rcr dx,1 
	mov Y1, dx 
	mov Y2, bx 
	jmp STOP

	
C_STOP:
	mov C_STOP_F, 2
	jmp quit 
		
		
B_STOP:	
	mov B_STOP_F, 3
	jmp quit 
	
	
STOP:
	mov STOP_F, 1	
		
		
quit:
	mov ax, 4c00h 
	int 21h 
	
code ends
end start