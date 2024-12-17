data segment 
	A dw -80
        B dw -40
	C dw 8
 	Y1 dw ? 
 	Y2 dw ?  
 	Chast dw ?  	
	Ost dw ? 
 	F_STOP db ?  
	F_STOP_A db ?  	
	del dw ?  	
	del_neg dw ? 
data ends
code segment 
assume cs: code, ds:data, ss: nothing 
start: mov ax, data; load adress    
     mov ds,ax; data segment 
 	 	mov F_STOP, 0  	; Флаг нормального завершения 
 	 	mov F_STOP_A, 0 ; Флаг аварийного завершения(выставляется с F_STOP) 
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
		xor si, si
		add si ,1
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
		neg ax
		cmp bx, ax	;сравниваем младшую часть и C/8
		jge m_a_x	;Если C/8 больше чем младшая часть, то занимаем 1 из старшей части
		dec dx
	m_a_x:
		neg ax
		add bx, ax	;С/8 + B**2(т.к. мы делим на 8 логично складывать именно с младшей частью)	
		mov Y1, dx	;старшая часть
		mov Y2, bx	;младшая часть
		mov ax, dx      ;
		xor dx, dx	;сбрасываем знак
		xor bx, bx	;сбрасываем знак
Start_div: 
	cmp si,1
	jne metka
	neg B
	metka:
	mov dx, A
	mov bx, dx
	sal dx, 1		;A*2
	jo div_4_1		;Если переполнение, то сначала делим
	add dx, bx		;A*2 + A = A*3
	jo div_4_1		;Если переполнение, то сначала делим
	sar dx, 1		;A*3/2
	sar dx, 1		;A*3/2
	jmp div_4		;Если всё хорошо, то (3/4*А+В)/4
	div_4_1:
		
		mov dx, bx
		sar dx, 1	;A/2
		sar dx, 1	;A/2
		mov bx,dx
		sal dx, 1	;A/4 * 2
		add dx, bx	;A/4 * (2 + 1) = A/4 * 3
	div_4:
		mov bx, B	;
		add dx, bx	;3/4 * A + B
		jo STOP_A_kt	;Если переполнение, то аварийное завершение
		cmp dx, 0 ;
		
		je STOP_A_kt ;
 	 	xor si, si  	; Сбрасываем знак, если он был в предыдущем вычислении. 
 	 	test dx, 8000h 	; Проверка на знак 
 	 	jz predDIV  	; Если положительное то прыжок 
 	 	neg dx  	 	; В дополнительный код 
 	 	add si, 1 	 	; Сохраняем знак 
predDIV:    
 	 	mov cx, 16  	; Цикл 
 	 	mov del, dx  	; Делитель 
		mov bx , Y2	;
 	 	neg dx  	 	; Инверсия делителя 
 	 	mov del_neg, dx 	; Отрицательный делитель 
 	 	add ax, del_neg 	; Пробное деление 
 	 	jc STOP_A_kt  	; Аварийное завершение 
 	 	neg dx  	 	;  
 	 	jmp DELENIE  
STOP_A_kt:  	
  jmp STOP_A     	; 
  vost: 
 	 	popf  	 ;
DELENIE:     	
		
 	 	rcl bx,1 	 	;  
 	 	rcl ax,1 	 	; 
 	 	jc plus 	
 	 	add ax,del_neg 	;
		jmp cycle 
 	 plus:  	
		add ax, del	 	; 
 	 cycle: 	
 	 	pushf; 	
		loop vost
 	 over: 		 	; 
 	 	popf  	 	; 
 	 	rcl bx, 1 	 	; 
 	 	test ax, 8000h 	; Проверяем остаток на знак 
 	 	jz over2 	 	; если положительное, то прыжок 
		add ax, del
 	 over2: 	
 	 	test si, 1  	; Восстанавливаем знак делителя 
 	 	jz result 	 ; Если положительный, то прыжок, иначе инверсия  частного 
		neg bx  	 ;  
 	 result:  
 	 	mov Chast, bx  	;загрузка частного в память 
 	 	mov Ost, ax  	;загрузка остатка в память 
		jmp STOP	;
 	 
STOP_A:  	
	mov F_STOP_A, 1 	 ;переход на нормальное завершение 
 	 
STOP:  
	mov F_STOP, 1 	; Аварийное завершение(выставляется с F_STOP) 
 	 quit:   	
		mov F_STOP, 1  	; Нормальное завершение 
 	 	mov ax,4c00h 	; 
 	int 21  	; 	 
code ends ;
end start 	
