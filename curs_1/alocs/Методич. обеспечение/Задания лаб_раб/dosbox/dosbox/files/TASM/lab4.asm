data segment
a8 db 58h
a16 dw 58h
ma8 db 0A8h
ma16 dw 0A7AFh
b8 db 94h
b16 dw 947Bh
mb8 db 6Bh
mb16 dw 6B85h
y8 db ?
y16 dw ?
data ends
code segment
assume cs:code, ds:data, ss:nothing; 
start: mov ax, data; load adress
       mov ds, ax; data segment; 
mov AH, a8; 
mov AL, b8; 
add AH, AL; 
mov y8, AH;

mov AX, a16;
mov BX, b16;
add AX, BX;
mov y16, AX;

mov AH, a8;
mov AL, mb8;
add AH, AL;
mov y8, AH;

mov AX, a16;
mov BX, mb16;
add AX, BX;
mov y16, AX;

mov AH, ma8;
mov AL, b8;
add AH, AL;
mov y8, AH;

mov AX, ma16;
mov BX, b16;
add AX, BX;
mov y16, AX;

mov AH, ma8;
mov AL, mb8;
add AH, AL;
mov y8, AH;

mov AX, ma16;
mov BX, mb16;
add AX, BX;
mov y16, AX;   
 
quit: mov ax, 4c00h; cod to finish 0
	int 21; exit to does
code ends
end start