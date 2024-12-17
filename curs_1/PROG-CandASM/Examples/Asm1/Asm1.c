
/*
    Линейная программа.
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
	c = a + b;

	printf("a = %x\nb = %x\nc = %x\n", a, b, c);
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
		mov a, 0x10;
		mov b, 0x20;

		// Сложение
		mov eax, a;		// EAX = a
		mov ebx, b;		// EBX = b
		add eax, ebx;	// EAX = EAX + EBX
		mov c, eax;		// c = EAX

		// Восстановление из стека сохраненных значений регистров
        // (восстановление выполняется в обратном порядке)
		pop ebx;
		pop eax;
	}

	printf("a = %x\nb = %x\nc = %x\n", a, b, c);
	getch();

}