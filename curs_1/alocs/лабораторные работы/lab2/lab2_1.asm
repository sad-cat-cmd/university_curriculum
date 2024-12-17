data segment
c16 dw 0B0B4h
c32 dd 0B0A3B71EAh
d16 dw 0D6F6h
d32 dd 0D70A3D5Ch
data ends
code segment
assume cs:code, ds:data, ss:nothing; 
start: mov ax, data
       mov ds, ax 
quit: mov ax, 4c00h; cod to finish 0
	int 21; exit to does
code ends
end start
