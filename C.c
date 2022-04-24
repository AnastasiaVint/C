#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <malloc.h>



void sheik(int* mas, int years) {
    int l = 0, r = years - 1, kr = 1;
    while ((l < r) && kr > 0) {
        kr = 0;
        for (int i = l; i < r; i++) {
            if (mas[i] > mas[i + 1]) {
                int t = mas[i];
                mas[i] = mas[i + 1];
                mas[i + 1] = t;
                kr = 1;
            }
        }
        r--;
        for (int i = r; i > l; i--) {
            if (mas[i - 1] > mas[i]) {
                int t = mas[i];
                mas[i] = mas[i - 1];
                mas[i - 1] = t;
                kr = 1;
            }
        }
        l++;
    }
}

float* salary(int** Array, int ps, int years)
{
    float* mass_average = (float*)malloc(sizeof(float) * ps);
    float sum = 0;
    for (int p = 0; p < ps; p++) {
        for (int year = 0; year < years; year++) {
            sum += Array[p][year];
        }
        mass_average[p] = sum / (float)years;
        sum = 0;
    }
    return mass_average;
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int** f_group, ** s_group;
    float* aver_values_f, * aver_values_s;
    int num_f, num_s, years;



    printf("-------------------Program-------------------\n\n");
    printf("Ввeдіть кількість людей у 1 підрозділі: ");
    scanf("%d", &num_f);
    printf("\nВвeдіть кількість людей у 2 підрозділі: ");
    scanf("%d", &num_s);
    printf("\nВвeдіть кількість років для аналізу: ");
    scanf("%d", &years);



    f_group = (int**)malloc(sizeof(int*) * num_f);
    for (int i = 0; i < num_f; i++) {
        f_group[i] = (int*)malloc(sizeof(int) * years);
    }
    s_group = (int**)malloc(sizeof(int*) * num_s);
    for (int i = 0; i < num_s; i++) {
        s_group[i] = (int*)malloc(sizeof(int) * years);
    }
    aver_values_f = (float*)malloc(sizeof(float) * num_f);
    aver_values_s = (float*)malloc(sizeof(float) * num_s);


    printf("\nВвeдіть данні про заробіток для 1 групи за кількість років (%d): \n", years);
    for (int p = 0; p < num_f; p++) {
        printf("%d Людина: ", p + 1);
        for (int year = 0; year < years; year++) {
            scanf("%d", &f_group[p][year]);
        }
    }
    printf("\nВвeдіть данні про заробіток для 2 групи за кількість років (%d): \n", years);
    for (int p = 0; p < num_s; p++) {
        printf("%d людина: ", p + 1);
        for (int year = 0; year < years; year++) {
            scanf("%d", &s_group[p][year]);
        }
    }
    printf("\n");

    aver_values_f = salary(f_group, num_f, years);
    aver_values_s = salary(s_group, num_s, years);
    printf("Середні значення для 1 групи\n");
    for (int i = 0; i < num_f; i++) {
        printf("Людина №%d = %10.2f \n", i + 1, aver_values_f[i]);
    }
    printf("\n");
    printf("Середні значення для 2 групи\n");
    for (int i = 0; i < num_s; i++) {
        printf("Людина №%d = %10.2f \n", i + 1, aver_values_s[i]);
    }


    for (int p = 0; p < num_s; p++) {
        sheik(s_group[p], years);
    }


    for (int p = 0; p < num_s; p++) {
        printf("\nЛюдина №%d : ", p + 1);
        for (int year = 0; year < years; year++) {
            printf("%d ", s_group[p][year]);
        }
    }
}