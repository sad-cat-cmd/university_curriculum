data segment
A dw 5f5ah
C dw 693Ch
Y dw ?
GOOD db ?
AVARIA db ?
data ends

code segment
assume cs: code, ds:data, ss: nothing

start:
	mov ax, data
	mov ds, ax
	mov GOOD, 0

	mov ax, A
	sal ax, 1
jo izmen
	add ax, A
jo izmen
	mov bx, C
	sar bx, 1
	sub ax, bx
	mov cx, 250
	sub cx, ax
jo FAVARIA
	mov y, cx
jmp FGOOD

izmen:
	mov ax, A
	sal ax, 1
jo FAVARIA
	mov bx, C
	sar bx, 1
	sub ax, bx
	add ax, A
jo FAVARIA
	mov cx, 250
	sub cx, ax
jo FAVARIA
	mov y, cx

FGOOD:
	inc GOOD
jmp quit

FAVARIA:
	inc AVARIA

quit:
	mov ax, 4c00h
	int 21
code ends
end start