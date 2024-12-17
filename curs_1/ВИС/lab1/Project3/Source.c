#include <stdio.h>
#include <string.h>

int octalToDecimal(char* num) {
	int len = strlen(num);
	int whole = 0, fraction = 0, i;
    for (i = 0; i < len && num[i] != '.' && num[i] != ','; i++) {
        whole = whole * 8 + (num[i] - '0');
    }

    if (i < len) {
        i++;
        int divisor = 8;
        while (i < len) {
            fraction = fraction + (num[i] - '0') / (double)divisor;
            divisor *= 8;
            i++;
        }
    }

    return whole + fraction;
}

int main() {
    char num[20];
    printf("Enter an octal number: ");
    scanf_s("%s", num, sizeof(num));
    int decimal = octalToDecimal(num);

    printf("The decimal equivalent is: %d\n", decimal);

    return 0;
}