data segment
a8 db 4Eh
a16 dw 4Eh
a32 dd 4Eh

b8 db 0B5h
b16 dw 0FFB5h
b32 dd 0FFFFFFB5h
data ends
code segment
assume cs:code, ds:data, ss:nothing 
start: mov ax, data
       mov ds, ax 
quit: mov ax, 4c00h
	int 21
code ends
end start