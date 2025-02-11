//
// Created by vince on 18/10/2024.
//

#include <stdio.h>

int sommatoria_naturale(unsigned int n) {
    int i, sum = 0;
    for (i = 1; i <= n; i++) {
        sum += i;
    }

    return sum;
}

float serie_armonica(unsigned int n) {
    int i;
    float sum = 0;
    for (i = 1; i <= n; i++) {
        sum += 1.0F / (float) i;
    }
    return sum;
}

int sommatoria_naturale_O(unsigned int n) {
    return n * (n + 1) / 2;
}


int fattoriale(unsigned int n) {
    int fatt = 1;
    int i;
    for (i = 2; i <= n; i++) {
        fatt *= i;
    }
    return fatt;
}

int max(unsigned int n) {
    int i, max, num;
    printf("insrisci il numero (1): ");
    scanf("%d", &num);
    max = num;
    for (i = 2; i <= n; i++) {
        printf("insrisci il numero (%d): ", i);
        scanf("%d", &num);
        if (num > max) {
            max = num;
        }
    }

    return max;
}


void max_min(unsigned int n, int *max, int *min) {
    int i, num;
    printf("insrisci il numero (1): ");
    scanf("%d", &num);
    *max = num;
    *min = num;
    for (i = 2; i <= n; i++) {
        printf("insrisci il numero (%d): ", i);
        scanf("%d", &num);
        if (num > *max) {
            *max = num;
        } else if (num < *min) {
            *min = num;
        }
    }
}

/**
 * @brief esegue lo swap dei valori di due variabili
 * @param a variabile a
 * @param b variabile b
 * @returns VALORE DI a in b e  VALORE DI b in a
 */
void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void max_2max(int n, int *max, int *max2) {
    int num, i;

    if (n >= 2) {
        printf("insrisci il numero (1): ");
        scanf("%d", &num);
        *max = num;
        *max2 = num;
        for (i = 2; i <= n; i++) {
            printf("insrisci il numero (%d): ", i);
            scanf("%d", &num);
            if (num > *max) {
                *max2 = *max;
                *max = num;
            } else if (num > *max2 && num < *max) {
                *max2 = num;
            }
        }
    }
}

double sommatoria_reciproco_sq(unsigned int n) {
    int i;
    double sum = 0;
    for (i = 1; i <= n; i++) {
        sum = sum + 1.0F / (double) i * (double) i;
    }
    return sum;
}


int search_key(char key, unsigned int n) {
    int i = 1;
    int exit = 0;
    char value;
    do {
        printf("inserisci il carattere (%d): ", i);
        value = getchar();
        fflush(stdin);
        exit = (value == key);
        i++;
    } while (!exit && i <= n);

    return exit;
}
