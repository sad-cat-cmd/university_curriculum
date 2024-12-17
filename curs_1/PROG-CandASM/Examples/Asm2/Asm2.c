
/*
    Разветвляющаяся программа.
*/

#define _CRT_NONSTDC_NO_WARNINGS

#include <stdio.h>
#include <conio.h>

void main(void)
{
	int a;
	int b;
	int c;


	//
    // Си.
	//

	a = 0x10;
	b = 0x20;
    
    if (a < b)
        c = a + b;
    else
        c = a * b;

	printf("c = %x\n", c);
	getch();


	//
	// Ассемблер.
	//
	__asm
	{
		// Сохранение в стеке текущих значений регистров
		push eax;
		push ebx;

		// Загрузка значений в переменные a и b
		mov a, 0x30;
		mov b, 0x20;

        // Сравнение переменных a и b
		mov eax, a;			// EAX = a
		mov ebx, b;			// EBX = b
        cmp eax, ebx;		// сравнение a и b
        jge LabelCmpFalse;	// переход, если a >= b
        // Если a < b
		add eax, ebx;		// EAX = EAX + EBX
		mov c, eax;			// c = EAX
        jmp CmpEnd;
	LabelCmpFalse:
        // Если a >= b
		imul eax, ebx;	    // EAX = EAX * EBX
		mov c, eax;		    // c = EAX
        // Конец условия
        CmpEnd:

		// Восстановление из стека сохраненных значений регистров
        // (восстановление выполняется в обратном порядке)
		pop ebx;
		pop eax;
	}

	printf("c = %x\n", c);
	getch();
}
