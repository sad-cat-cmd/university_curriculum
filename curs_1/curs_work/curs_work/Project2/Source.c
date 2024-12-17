#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#define size 20
int main() {
	char str[] = "+21112";
	char A[20];
	int num;
	__asm {
		push eax;
		push ebx;
		push ecx;
		push edx;
		push edi;

		mov num, 0;
		lea edi, str;
		mov ax, [edi];
		cmp ax, '+';
		jne check_negative;
		lea edi, A;
		mov[edi], '+';
		jmp next;
	check_negative:
		cmp ax, '-';
		jne next;
		mov[edi], '-';
	next:
		lea edi, str;
		inc edi;
	}
}