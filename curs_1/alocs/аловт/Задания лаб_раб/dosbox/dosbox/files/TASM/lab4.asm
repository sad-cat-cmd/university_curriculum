data segment
a16 dw 456Bh
ma16 dw 0BB95h
b16 dw 0ACA8h
mb16 dw 5358h
y16 dw ?
data ends
code segment
assume cs:code, ds:data, ss:nothing; 
start: mov ax, data; load adress
       mov ds, ax; data segment; 
mov AX, a16;
mov BX, b16;
add AX, BX;
mov y16, AX;

mov AX, a16;
mov BX, mb16;
add AX, BX;
mov y16, AX;

mov AX, ma16;
mov BX, b16;
add AX, BX;
mov y16, AX;

mov AX, ma16;
mov BX, mb16;
add AX, BX;
mov y16, AX;   
 
quit: mov ax, 4c00h; cod to finish 0
	int 21; exit to does
code ends
end start