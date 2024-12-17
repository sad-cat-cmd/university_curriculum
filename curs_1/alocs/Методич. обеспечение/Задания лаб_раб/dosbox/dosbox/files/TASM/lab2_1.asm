data segment
a16 dw 5851h
a32 dd 5851EB85h
b16 dw 947Bh
b32 dd 947AE14Bh
data ends
code segment
assume cs:code, ds:data, ss:nothing; 
start: mov ax, data
       mov ds, ax 
quit: mov ax, 4c00h; cod to finish 0
	int 21; exit to does
code ends
end start