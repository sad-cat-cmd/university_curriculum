data segment
a8 db 45h
a16 dw 45h
ma8 db 0BBh
ma16 dw 0FFBBh
b8 db 0ACh
b16 dw 0FFACh
mb8 db 54h
mb16 dw 54h
bm dw 07F02h
bs dw 0FFFFh
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