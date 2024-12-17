
/*
    ����������� ���������.
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
    // ��.
	//

    // ���������� �������
    for (i = 0; i < 10; i++) {
        mass[i] = i + 2;
    }

    // ������� ����� ��������� �������
    sum = 0;
    i = 0;
    while (i < 10) {
        sum = sum + mass[i];
        i++;
    }
    
	printf("sum = %d\n", sum);
	getch();


	//
	// ���������.
	//

    memset(mass, 0, sizeof(mass));

	__asm
	{
		// ���������� � ����� ������� �������� ���������
		push eax;
		push ebx;
		push ecx;
		push edi;
        push esi;

		// ���� ���������� ������� (� �������������� loop)
        mov eax, 2;         // � EAX ��������� �������� ��� ����������
		mov ecx, 10;	    // ������� �����, 10 ��������� �������
        lea edi, mass;      // � EDI ����� ������ ������� mass
	LabelLoop:
        mov [edi], eax;     // �� ������ EDI ���������� �������� EAX
        inc eax;            // ��������� �������� �������� �������
        add edi, 4;         // �������� ��������� ������� (sizeof(int) = 4)
        loop LabelLoop;

        // ���� �������� ����� ��������� ������� (� ������������� �������)
        mov sum, 0;
        mov ecx, 0;         // � ECX ������ �������� �������
    LabelWileStart:
        cmp ecx, 10;        // �������� ������� ��������� �����
        jge LabelWileEnd;   // ���� ECX >= 10, �� ������� �� LabelWileEnd
        mov ebx, dword ptr mass[ecx*4];
        add sum, ebx;
        inc ecx;
        jmp LabelWileStart;
    LabelWileEnd:

        // �������������� �� ����� ����������� �������� ���������
        // (�������������� ����������� � �������� �������)
        pop esi;
        pop edi;
        pop ecx;
		pop ebx;
		pop eax;
	}

	printf("sum = %d\n", sum);
	getch();
}
