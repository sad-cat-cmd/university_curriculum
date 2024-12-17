data segment
a16 dw 0B0A4h
a32 dd 0B0A4h
b16 dw 0D70Ah
b32 dd 0FFFFD70Ah
data ends
code segment
assume cs:code, ds:data, ss:nothing; 
start: mov ax, data
       mov ds, ax 
quit mov ax, 4c00h; cod to finish 0
	int 21; exit to does
code ends	
end start