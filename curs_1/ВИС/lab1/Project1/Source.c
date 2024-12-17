#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
int main() {
	int a = 10; // основание системы счисления, из которой выполняется перевод
	int b = 2; // основание целевой системы счисления
	int c = 6 ;// разрядность в исходной системе счисления
	int g = a / c;
	int q;
	int r = 0;
	printf("Введите число в сестеме счисление %d: \n", a);
	scanf_s("%d",&q);
	int A[20];
	int B[7];
	while (q > b ) {
		B[r] = q % b;
		r++;
		q =q / b;
	}
	for (int i = 0; i < 20; i++) {
		printf("%d", B[r]);
	}
}