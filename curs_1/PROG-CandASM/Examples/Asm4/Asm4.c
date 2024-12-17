
/*
    Циклическая программа.
*/

#define _CRT_NONSTDC_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <memory.h>

void main(void)
{
    char src[] = "56";
    char res[50];
    int num;
    char* pstr;
    char digit;


	//
    // Си.
	//

    // Перевод строки в число
    // (в строке записано число в 10-ом формате)
    num = 0;
    pstr = src;
    while (*pstr != 0) {
        digit = *pstr;          // символ цифры
        digit -= 0x30;          // перевод символа цифры в 10-ю цифру
        num = (num * 10) + digit;
        pstr++;
    }

    printf("num = %d\n", num);

    // Перевод числа в строку
    // (в строку запишется число в 2-ом формате)
    pstr = &res[49];
    *pstr = 0;                  // символ конца строки
    while (num > 0) {
        digit = num % 2;        // младшая цифра 2-го числа
        digit += 0x30;          // перевод 2-ой цифры в символ цифры
        pstr--;
        *pstr = digit;          // копирование символа цифры в строку
        num /= 2;
    }

	printf("res = %s\n", pstr);
	getch();


	//
	// Ассемблер.
	//

    memset(res, "0", sizeof(res));

	__asm
	{
		// Сохранение в стеке текущих значений регистров
		push eax;
		push ebx;
		push ecx;
		push edx;

        // Перевод строки в число
        // (в строке записано число в 10-ом формате)
        mov num, 0;         
        lea eax, src;               // EAX = адрес src
        mov pstr, eax;              // pstr = EAX
    LabelStart1:
        // Проверка условия окончания цикла
        // while (*pstr != 0)
        mov eax, pstr;              // EAX = pstr
        xor ecx, ecx;               // ECX = 0;
        mov cl, byte ptr [eax];     // CL = *pstr, в CL символ цифры
        test cl, cl;              // проверка ECX
        je LabelEnd1;               // если ECX == 0, то переход на LabelEnd1
        // Перевод символа цифры в 10-ю цифру
        sub ecx, 0x30;              // ECX = ECX - 0x30
        mov digit, cl;              // digit = CL
        // Формирование числа num
        mov eax, num;
        xor ebx, ebx;
        mov bx, 10;
        mul bx;                     // EAX = EAX * BX (EAX = num * 10)
        xor ebx, ebx;
        mov bl, digit;
        add eax, ebx;               // EAX = EAX + EBX (EAX = num + digit)
        mov num, eax;
        // Смещение к следующему символу строки
        inc pstr;                   // pstr++;
        jmp LabelStart1;
    LabelEnd1:

        // Перевод числа в строку
        // (в строку запишется число в 2-ом формате)
        lea eax, res;
        add eax, 49;
        mov pstr, eax;
        mov byte ptr [eax], 0;     // *pstr = 0
    LabelStart2:
        // Проверка условия окончания цикла
        // while (num > 0)
        cmp num, 0;
        jle LabelEnd2;
        // Получение младшей цифры 2-го числа
        mov eax, num;
        xor edx, edx;               // делимое в EDX:EAX
        mov ebx, 2;                 // делитель в EBX
        div ebx;                    // (EDX:EAX) / EBX, частное в EAX, остаток в EDX
        // Сохранение результата деления
        mov num, eax;
        // Перевод цифры в символ 2-ой цифры
        add edx, 0x30;
        mov digit, dl;
        // Копирование символа цифры в строку
        dec pstr;
        mov eax, pstr;
        mov byte ptr [eax], dl;     // *pstr = digit
        // Следующая цифра
        jmp LabelStart2;
    LabelEnd2:

        // Восстановление из стека сохраненных значений регистров
        // (восстановление выполняется в обратном порядке)
        pop edx;
        pop ecx;
		pop ebx;
		pop eax;
	}

	printf("res = %s\n", pstr);
	getch();
}
