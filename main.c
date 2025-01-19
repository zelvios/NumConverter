#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Decimal Calulations
void DecimalToBinary(int num) {
    int binary[32];
    int i = 0;

    while (num > 0) {
        binary[i] = num % 2;
        num = num / 2;
        i++;
    }

    printf("Binary: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

void DecimalToHexadecimal(int num) {
    char hex[32];
    int i = 0;
    char hexDigits[] = "0123456789ABCDEF";

    if (num == 0) {
        printf("Hexadecimal: 0x0\n");
        return;
    }

    while (num > 0) {
        hex[i] = hexDigits[num % 16];
        num = num / 16;
        i++;
    }

    printf("Hexadecimal: 0x");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    printf("\n");
}

// Binary Calulations
int binaryToDecimal(const char *str) {
    int result = 0;
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        if (str[i] == '1') {
            result += (1 << (length - i - 1));
        } else if (str[i] != '0') {
            return -1;
        }
    }

    return result;
}

void BinaryToDecimal(const char *str) {
    int decimal = binaryToDecimal(str);
    if (decimal == -1) {
        printf("Invalid binary number!\n");
    } else {
        printf("Decimal: %d\n", decimal);
    }
}

void BinaryToHexadecimal(const char *str) {
    int decimal = binaryToDecimal(str);
    if (decimal == -1) {
        printf("Invalid binary number!\n");
        return;
    }

    char hex[32];
    int i = 0;
    char hexDigits[] = "0123456789ABCDEF";

    if (decimal == 0) {
        printf("Hexadecimal: 0x0\n");
        return;
    }

    while (decimal > 0) {
        hex[i] = hexDigits[decimal % 16];
        decimal = decimal / 16;
        i++;
    }

    printf("Hexadecimal: 0x");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    printf("\n");
}

// Hexadecimal Calculations
int hexToDecimal(const char *str) {
    int result = 0;
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        char c = toupper(str[i]);
        int value = 0;

        if (c >= '0' && c <= '9') {
            value = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            value = c - 'A' + 10;
        } else {
            return -1;
        }

        result += value * (1 << (4 * (length - i - 1)));
    }
    return result;
}

void HexadecimalToDecimal(const char *str) {
    int decimal = hexToDecimal(str);
    if (decimal == -1) {
        printf("Invalid hexadecimal number!\n");
    } else {
        printf("Decimal: %d\n", decimal);
    }
}

void HexadecimalToBinary(const char *str) {
    int decimal = hexToDecimal(str);
    if (decimal == -1) {
        printf("Invalid hexadecimal number!\n");
        return;
    }

    int binary[32];
    int i = 0;

    if (decimal == 0) {
        printf("Binary: 0\n");
        return;
    }

    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }

    printf("Binary: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

// Checkers
int isBinary(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '0' && str[i] != '1') {
            return 0;
        }
    }
    return 1;
}

int isHexadecimal(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isxdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int isWholeNumber(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') { //checks if it's not a digit ( ASCII values )
            return 0;
        }
    }
    return 1;
}

// Main
int main() {
    char input[100];
    int number;
    char choice;

    while (1) {
        printf("[======================================]\n");
        printf("\nWhat type is your number?: \n");
        printf("1. Binary\n");
        printf("2. Hexadecimal (without 0x)\n");
        printf("3. Decimal (only whole numbers)\n");
        printf("4. Exit\n");
        printf("Enter choice:");
        scanf("%c", &choice);
        getchar();

        if (choice == '4') {
            printf("Exiting...\n");
            break;
        }

        printf("Enter a number: ");
        scanf("%99[^\n]", input);
        getchar();

        if (choice == '1') {
            if (isBinary(input)) {
                BinaryToDecimal(input);
                BinaryToHexadecimal(input);
            } else {
                printf("Invalid binary number!\n");
            }
        } else if (choice == '2') {
            if (isHexadecimal(input)) {
                HexadecimalToDecimal(input);
                HexadecimalToBinary(input);
            } else {
                printf("Invalid hexadecimal number!\n");
            }
        } else if (choice == '3') {
            if (isWholeNumber(input)) {
                number = atoi(input);
                DecimalToBinary(number);
                DecimalToHexadecimal(number);
            } else {
                printf("Invalid number! Please enter a whole number.\n");
            }
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
