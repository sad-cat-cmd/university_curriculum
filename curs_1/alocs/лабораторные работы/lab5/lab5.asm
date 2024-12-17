data segment
am dw 502Ah
as dw 0h
bm dw 07F02h
bs dw 0FFFFh
ym dw ?
ys dw ?
data ends
code segment
assume cs:code, ds:data, ss:nothing; 
start: mov ax, data; load adress
       mov ds, ax; data segment; 
mov AX, am; 
mov BX, bm; 
add AX, BX; 
mov ym, AX;
mov AX, as;
mov BX, bs;
add AX, BX;
mov ys, AX;
 
quit: mov ax, 4c00h; cod to finish 0
	int 21; exit to does
code ends
end start