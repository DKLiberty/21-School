#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Функция для кодирования символов
void encode(char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        printf("%02X ",
               (unsigned char)
                   input[i]);  // Преобразуем символ в ASCII код и выводим его в шестнадцатеричном формате
    }
    printf("\n");
}

// Функция для декодирования шестнадцатеричных значений
void decode(char *input) {
    char *token = strtok(input, " ");
    while (token != NULL) {
        char *endptr;
        long int value = strtol(token, &endptr, 16);  // Преобразуем шестнадцатеричное значение в число
        if (*endptr != '\0' || value < 0 ||
            value > 255) {  // Проверяем, что значение корректное (от 0 до 255)
            printf("n/a\n");
            return;
        }
        printf("%c ", (char)value);  // Выводим символ, соответствующий ASCII коду
        token = strtok(NULL, " ");
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <mode>\n", argv[0]);
        return 1;
    }

    int mode = atoi(argv[1]);  // Получаем режим работы (0 — кодирование, 1 — декодирование)

    if (mode == 0) {
        char input[100];
        if (scanf("%[^\n]%*c", input) != 1) {  // Считываем строку с пробелами до символа новой строки
            printf("n/a\n");
            return 1;
        }
        encode(input);
    } else if (mode == 1) {
        char input[100];
        if (scanf("%[^\n]%*c", input) != 1) {  // Считываем строку с пробелами до символа новой строки
            printf("n/a\n");
            return 1;
        }
        decode(input);
    } else {
        printf("n/a\n");
        return 1;
    }

    return 0;
}
