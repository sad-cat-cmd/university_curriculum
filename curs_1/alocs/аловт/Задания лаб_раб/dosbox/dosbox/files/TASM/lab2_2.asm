data segment
f16 dw 456Dh
f32 dd 00456D9Eh
g16 dw 0ACA5h
g32 dd 0FFACA5AFh
data ends
code segment
assume cs:code, ds:data, ss:nothing; 
start: mov ax, data
       mov ds, ax 
quit: mov ax, 4c00h; cod to finish 0
	int 21; exit to does
code ends
end start