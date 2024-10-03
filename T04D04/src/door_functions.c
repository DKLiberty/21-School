#include <math.h>
#include <stdio.h>

#define PI 3.14159265358979323846

// Функция для расчета значения Верзьера Аньези с единичным диаметром
double anziera_verzier(double x) {
    double y = sqrt(1 - pow(x, 4));
    return y;
}

// Функция для расчета значения Лемниската Бернулли с единичным интервалом в положительной полуплоскости
double bernoulli_lemniscate(double x) {
    double y = sqrt(x * x - 1);
    return y;
}

// Функция для расчета значения квадратичной гиперболы
double hyperbola(double x) {
    double y = 1 / x;
    return y;
}

int main() {
    FILE *fp = fopen("data/door_data.txt", "w");
    if (fp == NULL) {
        printf("Ошибка при открытии файла.\n");
        return 1;
    }

    for (int i = -20; i <= 20; i++) {
        double x = i * PI / 20.0;  // Рассчитываем значение абсциссы
        double y1 = anziera_verzier(x);
        double y2 = bernoulli_lemniscate(x);
        double y3 = hyperbola(x);

        fprintf(fp, "%.7f | %.7f | %.7f | %.7f\n", x, y1, y2, y3);
    }

    fclose(fp);
    printf("Таблица функций успешно записана в файл.\n");
    return 0;
}
