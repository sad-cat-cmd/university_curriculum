
/*
    Функции.
*/

#define _CRT_NONSTDC_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <memory.h>


/** Стандартная функция ANSY C.
  * Передача параметров - стек.
  * Возвращаемое значение - регистр EAX.
  */
int func1(int v, int d)
{
    return v + d;
}


/** Функция с передачей параметров через регистры.
  * int func2(int v, int d)
  * Передача параметров - регистры.
  *     регистр EBX - v
  *     регистр ECX - d
  * Возвращаемое значение - регистр.
  *     регистр EAX - возвращаемое значение
  */
__declspec(naked)
func2()
{
    __asm
    {
        mov eax, ebx;   // EAX = v
        add eax, ecx;   // EAX = EAX + d
        ret;            // результат в EAX
    }
}


/** Функция с передачей параметров через сегмент данных.
  * int func3(int v, int d)
  * Передача параметров - в регистре EBX передается адрес глобальной области
  * памяти (массив param3), в котором размещены параметры v и d.
  *     param3[0] - v
  *     param3[1] - d
  * Возвращаемое значение - сегмент данных.
  *     param3[2] - возвращаемое значение
  */

int param3[3];

__declspec(naked)
func3()
{
    __asm
    {
        mov eax, [ebx + 0];             // EAX = v
        add eax, [ebx + 4];             // EAX = EAX + d
        mov dword ptr [ebx + 8], eax;   // возвращаемое значение
        xor eax, eax;
        ret;
    }
}


void main(void)
{
    int value;


    //
	// value = func1(10, 2);
    //
	__asm
	{
		push 2;                 // параметр d
		push 10;                // параметр v
        call func1;
        add esp,8;              // восстановление ESP, sizeof(v) + sizeof(d) = 8
        mov value, eax;         // результат
	}

	printf("value = %d\n", value);


    //
	// value = func2(20, 3);
    //
    __asm
    {
        push ebx;
        push ecx;

        mov ebx, 20;            // параметр v
        mov ecx, 3;             // параметр d
        call func2;
        mov value, eax;         // результат

        pop ecx;
        pop ebx;
    }

	printf("value = %d\n", value);


    //
	// value = func3(30, 4);
    //
    __asm
    {
        push ebx;
        
        lea ebx, param3;
        mov dword ptr [ebx + 0], 30;    // параметр v
        mov dword ptr [ebx + 4], 4;     // параметр d
        call func3;
        mov eax, [ebx + 8];
        mov value, eax;                 // результат
        
        pop ebx;
    }

	printf("value = %d\n", value);
	getch();
}
