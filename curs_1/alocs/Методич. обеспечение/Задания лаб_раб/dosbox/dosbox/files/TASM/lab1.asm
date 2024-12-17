data segment
a dw? ; 
b dw? ; 
y dw? ; 
data ends
code segment
assume cs:code, ds:data, ss:nothing; 
start: mov ax, data; load adress
       mov ds, ax; data segment; 

mov AX, a ; 
mov BX, b ; 
add AX, BX; 
mov y, AX ; 
quit mov ax, 4c00h; cod to finish 0
	int 21; exit to does
code ends
end start