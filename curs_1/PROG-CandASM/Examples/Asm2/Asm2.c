
/*
    ��������������� ���������.
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
    
    if (a < b)
        c = a + b;
    else
        c = a * b;

	printf("c = %x\n", c);
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
		mov a, 0x30;
		mov b, 0x20;

        // ��������� ���������� a � b
		mov eax, a;			// EAX = a
		mov ebx, b;			// EBX = b
        cmp eax, ebx;		// ��������� a � b
        jge LabelCmpFalse;	// �������, ���� a >= b
        // ���� a < b
		add eax, ebx;		// EAX = EAX + EBX
		mov c, eax;			// c = EAX
        jmp CmpEnd;
	LabelCmpFalse:
        // ���� a >= b
		imul eax, ebx;	    // EAX = EAX * EBX
		mov c, eax;		    // c = EAX
        // ����� �������
        CmpEnd:

		// �������������� �� ����� ����������� �������� ���������
        // (�������������� ����������� � �������� �������)
		pop ebx;
		pop eax;
	}

	printf("c = %x\n", c);
	getch();
}
