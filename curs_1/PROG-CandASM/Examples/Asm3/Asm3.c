
/*
    Циклическая программа.
*/

#define _CRT_NONSTDC_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <memory.h>

void main(void)
{
	int mass[10];
	int i;
	int sum;


	//
    // Си.
	//

    // Заполнение массива
    for (i = 0; i < 10; i++) {
        mass[i] = i + 2;
    }

    // Подсчет суммы элементов массива
    sum = 0;
    i = 0;
    while (i < 10) {
        sum = sum + mass[i];
        i++;
    }
    
	printf("sum = %d\n", sum);
	getch();


	//
	// Ассемблер.
	//

    memset(mass, 0, sizeof(mass));

	__asm
	{
		// Сохранение в стеке текущих значений регистров
		push eax;
		push ebx;
		push ecx;
		push edi;
        push esi;

		// Цикл заполнения массива (с использованием loop)
        mov eax, 2;         // в EAX начальное значение для заполнения
		mov ecx, 10;	    // счетчик цикла, 10 элементов массива
        lea edi, mass;      // в EDI адрес начала массива mass
	LabelLoop:
        mov [edi], eax;     // по адресу EDI копируется значение EAX
        inc eax;            // следующее значение элемента массива
        add edi, 4;         // смещение указателя массива (sizeof(int) = 4)
        loop LabelLoop;

        // Цикл подсчета суммы элементов массива (с использование условия)
        mov sum, 0;
        mov ecx, 0;         // в ECX индекс элемента массива
    LabelWileStart:
        cmp ecx, 10;        // проверка условия окончания цикла
        jge LabelWileEnd;   // если ECX >= 10, то переход на LabelWileEnd
        mov ebx, dword ptr mass[ecx*4];
        add sum, ebx;
        inc ecx;
        jmp LabelWileStart;
    LabelWileEnd:

        // Восстановление из стека сохраненных значений регистров
        // (восстановление выполняется в обратном порядке)
        pop esi;
        pop edi;
        pop ecx;
		pop ebx;
		pop eax;
	}

	printf("sum = %d\n", sum);
	getch();
}
