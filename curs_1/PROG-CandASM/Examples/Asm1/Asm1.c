
/*
    �������� ���������.
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
    // ��.
	//

	a = 0x10;
	b = 0x20;
	c = a + b;

	printf("a = %x\nb = %x\nc = %x\n", a, b, c);
	getch();


	//
	// ���������.
	//
	__asm
	{
		// ���������� � ����� ������� �������� ���������
		push eax;
		push ebx;

		// �������� �������� � ���������� a � b
		mov a, 0x10;
		mov b, 0x20;

		// ��������
		mov eax, a;		// EAX = a
		mov ebx, b;		// EBX = b
		add eax, ebx;	// EAX = EAX + EBX
		mov c, eax;		// c = EAX

		// �������������� �� ����� ����������� �������� ���������
        // (�������������� ����������� � �������� �������)
		pop ebx;
		pop eax;
	}

	printf("a = %x\nb = %x\nc = %x\n", a, b, c);
	getch();

}