#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
int main() {
	int a = 10; // ��������� ������� ���������, �� ������� ����������� �������
	int b = 2; // ��������� ������� ������� ���������
	int c = 6 ;// ����������� � �������� ������� ���������
	int g = a / c;
	int q;
	int r = 0;
	printf("������� ����� � ������� ��������� %d: \n", a);
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