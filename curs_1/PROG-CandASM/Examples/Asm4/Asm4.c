
/*
    ����������� ���������.
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
    // ��.
	//

    // ������� ������ � �����
    // (� ������ �������� ����� � 10-�� �������)
    num = 0;
    pstr = src;
    while (*pstr != 0) {
        digit = *pstr;          // ������ �����
        digit -= 0x30;          // ������� ������� ����� � 10-� �����
        num = (num * 10) + digit;
        pstr++;
    }

    printf("num = %d\n", num);

    // ������� ����� � ������
    // (� ������ ��������� ����� � 2-�� �������)
    pstr = &res[49];
    *pstr = 0;                  // ������ ����� ������
    while (num > 0) {
        digit = num % 2;        // ������� ����� 2-�� �����
        digit += 0x30;          // ������� 2-�� ����� � ������ �����
        pstr--;
        *pstr = digit;          // ����������� ������� ����� � ������
        num /= 2;
    }

	printf("res = %s\n", pstr);
	getch();


	//
	// ���������.
	//

    memset(res, "0", sizeof(res));

	__asm
	{
		// ���������� � ����� ������� �������� ���������
		push eax;
		push ebx;
		push ecx;
		push edx;

        // ������� ������ � �����
        // (� ������ �������� ����� � 10-�� �������)
        mov num, 0;         
        lea eax, src;               // EAX = ����� src
        mov pstr, eax;              // pstr = EAX
    LabelStart1:
        // �������� ������� ��������� �����
        // while (*pstr != 0)
        mov eax, pstr;              // EAX = pstr
        xor ecx, ecx;               // ECX = 0;
        mov cl, byte ptr [eax];     // CL = *pstr, � CL ������ �����
        test cl, cl;              // �������� ECX
        je LabelEnd1;               // ���� ECX == 0, �� ������� �� LabelEnd1
        // ������� ������� ����� � 10-� �����
        sub ecx, 0x30;              // ECX = ECX - 0x30
        mov digit, cl;              // digit = CL
        // ������������ ����� num
        mov eax, num;
        xor ebx, ebx;
        mov bx, 10;
        mul bx;                     // EAX = EAX * BX (EAX = num * 10)
        xor ebx, ebx;
        mov bl, digit;
        add eax, ebx;               // EAX = EAX + EBX (EAX = num + digit)
        mov num, eax;
        // �������� � ���������� ������� ������
        inc pstr;                   // pstr++;
        jmp LabelStart1;
    LabelEnd1:

        // ������� ����� � ������
        // (� ������ ��������� ����� � 2-�� �������)
        lea eax, res;
        add eax, 49;
        mov pstr, eax;
        mov byte ptr [eax], 0;     // *pstr = 0
    LabelStart2:
        // �������� ������� ��������� �����
        // while (num > 0)
        cmp num, 0;
        jle LabelEnd2;
        // ��������� ������� ����� 2-�� �����
        mov eax, num;
        xor edx, edx;               // ������� � EDX:EAX
        mov ebx, 2;                 // �������� � EBX
        div ebx;                    // (EDX:EAX) / EBX, ������� � EAX, ������� � EDX
        // ���������� ���������� �������
        mov num, eax;
        // ������� ����� � ������ 2-�� �����
        add edx, 0x30;
        mov digit, dl;
        // ����������� ������� ����� � ������
        dec pstr;
        mov eax, pstr;
        mov byte ptr [eax], dl;     // *pstr = digit
        // ��������� �����
        jmp LabelStart2;
    LabelEnd2:

        // �������������� �� ����� ����������� �������� ���������
        // (�������������� ����������� � �������� �������)
        pop edx;
        pop ecx;
		pop ebx;
		pop eax;
	}

	printf("res = %s\n", pstr);
	getch();
}
