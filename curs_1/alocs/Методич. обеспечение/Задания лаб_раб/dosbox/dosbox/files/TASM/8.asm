;Y=С/8+B**2
data segment
	B dw -2000
	C dw -32000
	Y1 dw ?
	Y2 dw ?
	F_STOP db ?
	F_STOP_A db ?
data ends
code segment
assume cs:code, ds:data, ss:nothing 
start:	
		mov ax,data
		mov ds,ax	
		mov F_STOP, 0
		mov F_STOP_A, 0
		mov ax, C
		sar ax, 1	;C/2
		sar ax, 1	;C/4
		sar ax, 1	;C/8
		mov bx, B
		mov cx, 15	;счётчик цикла
		xor dx, dx	;обнуление регистра dx(здесь будет записана старшая часть)
		test bx, 8000h	;если число положительное, то сразу возводим в квадрат
		jz b_2		;если отрицательное то инвертируем и прибавляем 1
		neg B
		mov bx, B
	b_2:
		rcr bx, 1	;сдвиг регистра множителя	
		jnc e_n_d	;проверка выдвинутого разряда - если бит равен 0, то сдвиг.
		add dx, B	;иначе сложение.
	e_n_d:	
		rcr dx, 1	;сдвиг сумматора
		loop b_2	;уменьшение cx на 1
		rcr bx, 1	;дополнительный сдвиги
		rcr dx, 1
		rcr bx, 1
	result:
		neg ax
		cmp bx, ax	;сравниваем младшую часть и C/8
		jge m_a_x	;Если C/8 больше чем младшая часть, то занимаем 1 из старшей части
		dec dx
	m_a_x:
		neg ax
		add bx, ax	;С/8 + B**2(т.к. мы делим на 8 логично складывать именно с младшей частью)	
		mov Y1, dx	;старшая часть
		mov Y2, bx	;младшая часть
		jmp STOP	
	STOP_A:
		mov F_STOP_A, 1
	STOP:
		mov F_STOP, 1            	    	
	quit:      
		mov ax, 4c00h		
		int 21 			
code ends
end start