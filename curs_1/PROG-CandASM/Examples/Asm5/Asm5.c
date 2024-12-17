
/*
    �������.
*/

#define _CRT_NONSTDC_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <memory.h>


/** ����������� ������� ANSY C.
  * �������� ���������� - ����.
  * ������������ �������� - ������� EAX.
  */
int func1(int v, int d)
{
    return v + d;
}


/** ������� � ��������� ���������� ����� ��������.
  * int func2(int v, int d)
  * �������� ���������� - ��������.
  *     ������� EBX - v
  *     ������� ECX - d
  * ������������ �������� - �������.
  *     ������� EAX - ������������ ��������
  */
__declspec(naked)
func2()
{
    __asm
    {
        mov eax, ebx;   // EAX = v
        add eax, ecx;   // EAX = EAX + d
        ret;            // ��������� � EAX
    }
}


/** ������� � ��������� ���������� ����� ������� ������.
  * int func3(int v, int d)
  * �������� ���������� - � �������� EBX ���������� ����� ���������� �������
  * ������ (������ param3), � ������� ��������� ��������� v � d.
  *     param3[0] - v
  *     param3[1] - d
  * ������������ �������� - ������� ������.
  *     param3[2] - ������������ ��������
  */

int param3[3];

__declspec(naked)
func3()
{
    __asm
    {
        mov eax, [ebx + 0];             // EAX = v
        add eax, [ebx + 4];             // EAX = EAX + d
        mov dword ptr [ebx + 8], eax;   // ������������ ��������
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
		push 2;                 // �������� d
		push 10;                // �������� v
        call func1;
        add esp,8;              // �������������� ESP, sizeof(v) + sizeof(d) = 8
        mov value, eax;         // ���������
	}

	printf("value = %d\n", value);


    //
	// value = func2(20, 3);
    //
    __asm
    {
        push ebx;
        push ecx;

        mov ebx, 20;            // �������� v
        mov ecx, 3;             // �������� d
        call func2;
        mov value, eax;         // ���������

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
        mov dword ptr [ebx + 0], 30;    // �������� v
        mov dword ptr [ebx + 4], 4;     // �������� d
        call func3;
        mov eax, [ebx + 8];
        mov value, eax;                 // ���������
        
        pop ebx;
    }

	printf("value = %d\n", value);
	getch();
}
