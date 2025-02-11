#include "lib.h"

#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "incremental/incremental.h"




/**
 *@brief calcolo distanza tra due punti
 *
 * @param x1 punto x1
 * @param y1 immagine x1 f(x1)
 * @param x2 punto x2
 * @param y2 immagine x2 f(x2)
 * @return distanza tra P1 e P2
 *
 */
float distanza_p1_p2(float x1, float y1, float x2, float y2) {
    return (float) sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

/***
 * @brief esegue la lettura da tastiera di elementi di un array
 * @param a
 * @param size
 *
 * @return valori inseriti in a;
 */
void leggi_a(int *a, int size) {
    int i;
    for (i = 0; i < size; i++) {
        scanf("%d", a + i);
    }
}


/**
 *@brief una funzione che si occupa di stampare i valori dell'array da start a end, se si vuole inizare dall'inizione non c'è bisogno di inserire il valore di start
 * @param a
 * @param start
 * @param end
 */
void visulaizza_a(int *a, int start, int end) {
    int i;
    for (i = start; i < end; i++) {
        printf("%d\n", *(a + i));
    }
}

/**
 * @brief Calcolo distanza dall'origine di un punto
 * @param x
 * @param y
 * @return distanza tra P da O
 */
float distanza_O(float x, float y) {
    return (float) sqrt(pow(x, 2) + pow(y, 2));
}


/**
 * @brief Risolutore Disequazione di secondo grado
 *
 * @param a valore tipo ax^2
 * @param b valore tipo bx
 * @param c valore tipo c
 * @param sign segno della disequazione > o <
 * @param result variabile dove verrà immagazzinato il risultato
 * @param disc variabile dove verra immagazinato il discriminante
 *
 *@returns result, disc
 */
void diseq2Grade(double a, double b, double c, char sign, char *result, double *disc) {
    double r, r1, r2;;
    char stringa[100];

    if (a < 0) {
        a = a * -1;
        b = b * -1;
        c = c * -1;
        sign = (sign == '<') ? '>' : (sign == '>') ? '<' : '>';
    }
    *disc = (b * b) - (4 * a * c);

    if (*disc < 0) {
        strcpy(result, "Insieme Vuoto");
    } else if (*disc == 0) {
        r = (-b) / (2 * a);
        sprintf(stringa, "%f", r);
        strcpy(result, "Tutto R tranne ");
        strcat(result, stringa);
    } else {
        // Quando il discriminante è positivo, puoi aggiungere il resto del codice
        r1 = (-b + sqrt(*disc)) / (2 * a);
        r2 = (-b - sqrt(*disc)) / (2 * a);
        snprintf(result, 100, "Intervalli soluzioni: (%.2f, %.2f)", r1, r2);
    }
}


/**
 * @brief  Calcola MCD di due numeri.
 *
 * prende due valori e calcola mcd
 *
 * @param a Il primo numero intero.
 * @param b Il secondo numero intero.
 * @return MCD.
 */
int mcd(int a, int b) {
    int r;
    if (a < b) {
        r = b % a;
        if (r == 0) {
            return a;
        } else {
            return mcd(a, r);
        }
    } else {
        r = a % b;
        if (r == 0) {
            return b;
        } else {
            return mcd(b, r);
        }
    }
}

/**
 * @brief Procedura per il quadrato di un numero
 * @param x valore da elevare al quadrato
 * @returns il quadrato di x
 */
void pow2(int *x) {
    *x = *x * *x;
}


double formula_x(double x) {
    return (x * x * x + 3 * x + 5) / (8 * x + 1);
}

double formula_y(double y) {
    return (y * y * y * y) / (1 + y);
}

void formula_xy(double x, double y, double *result_x, double *result_y) {
    *result_x = formula_x(x);
    *result_y = formula_y(y);
}

void real_formula_x(double x, double *result) {
    //int number = 0 + (1-0) * (float)rand()/(float)RAND_MAX;
    /* il codice scritto in successione serve per generare randomicamente reali [a;b] (a + (b-a) * (float)rand()/(float)Rand_max)*/
    *result = formula_x(x);
}


int *concArray(int a1[], int a2[], int n, int m) {
    int *result = (int *) malloc((n + m) * sizeof(int));
    int k = 0, a1c = 0, a2c = 0;
    for (k = 0; k < n + m; k++) {
        if (((k % 2) == 0) && (a2c < m)) {
            result[k] = a2[a2c];
            a2c++;
        } else if (a1c < n) {
            result[k] = a1[a1c];
            a1c++;
        } else {
            result[k] = a2[a2c];
            a2c++;
        }
    }

    return result;
}

/**
 *
 * @brief una funzione che trasposta la matrice alla j-esima colonna come la i-esima riga
 * @param matrice
 * @param row il numero di righe
 * @param col il numero di colonne
 * @return
 */
int *traspostaMatrice(int *matrice, int row, int col) {
    int *result = (int *) malloc(col * row * sizeof(int));
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            result[j * row + i] = matrice[i * col + j];
        }
    }

    return result;
}

int *sommaMatrici(int *matrice1, int *matrice2, int n, int m) {
    int *result = (int *) malloc(n * m * sizeof(int));
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            *(result + i * m + j) = *(matrice1 + i * m + j) + *(matrice2 + i * m + j);
        }
    }
    return result;
}

int somma_elementi_array(int *a, int size) {
    int sum = 0, i = 0;
    for (i = 0; i < size; i++) {
        sum = sum + *(a + i);
    }
    return sum;
}

void procedura_somma_elementi_array(int *a, int size, int *result) {
    int i = 0;
    *result = 0;
    for (i = 0; i < size; i++) {
        *result = *result + (*a + i);
    }
}

int function(int *a, int size) {
    int max1 = a[0], max2 = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] > max1) {
            max2 = max1;
            max1 = a[i];
        } else if (max2 > a[i] && a[i] > max1) {
            max2 = a[i];
        }
    }
    return max2;
}

int max_sum_matrice_col(int *mat, int row, int col) {
    int i, j, max = 0, sum = 0;


    for (i = 0; i < col; i++) {
        // Itera sulle colonne
        sum = 0; // Inizializza la somma per la colonna corrente
        for (j = 0; j < row; j++) {
            sum += *(mat + j * col + i); // Accesso alla matrice per colonne
        }
        printf("sum = %d\n", sum);
        if (j == 0 || sum > max) {
            max = sum;
        }
    }
    return max;
}

int max_sum_matrice_row(int *mat, int row, int col) {
    int i, j, max = 0, sum = 0;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            sum = sum + *(mat + i * col + j);
        }
        if (i == 0 || sum > max) {
            max = sum;
        }
        sum = 0;
    }
    return max;
}

int count_3lettereword(char word1[]) {
    int i = 0;
    char separatori[] = {' ', '\0'};
    int count = 0;
    char *token = strtok(word1, separatori);
    while (token != NULL) {
        if (strlen(token) == 3) {
            count++;
        }
        token = strtok(NULL, separatori);
    }
    return count;
}

int count_parole_are(char s[]) {
    int count = 0, i;
    int size = strlen(s);
    char termination[3] = "are";
    for (i = 0; i < size; i++) {
        if (s[i + 1] == ' ' || i == size - 1) {
            if (s[i] == termination[2] && s[i - 1] == termination[1] && s[i - 2] == termination[0]) {
                count++;
            }
        }
    }
    return count;
}

int count_parole_are_tok(char s[]) {
    int count = 0;
    char separatori[] = {' ', '\0'};
    int i = 0;
    char *token = strtok(s, separatori);
    while (token != NULL) {
        while (token[i] != '\0') {
            if (token[i + 1] == '\0' && token[i] == 'e' && token[i - 1] == 'r' && token[i - 2] == 'a') {
                count++;
            }
            i++;
        }
        i = 0;
        token = strtok(NULL, separatori);
    }
    return count;
}

int count_word_start_terminate(char s[], char start, char end) {
    int count = 0;
    int size = strlen(s);
    int i;
    int start_a = 0;
    for (i = 0; i < size; i++) {
        if ((s[i] != ' ' && (s[i - 1] == ' ' || i == 0)) && s[i] == start) {
            start_a = 1;
        }
        if ((s[i] != ' ' && s[i - 1] != ' ' && (s[i + 1] == ' ' || i == size - 1)) && s[i] == end && start_a == 1) {
            count++;
            start_a = 0;
        }
    }
    return count;
}


int count_word_with_vocals(char s[]) {
    int count = 0, count_char = 0;
    size_t size = strlen(s);
    for (int i = 0; i < size; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            count_char++;
            if (count_char >= 5 && (s[i + 1] == ' ' || i == size - 1)) {
                count++;
                count_char = 0;
            }
        } else if (s[i] == ' ') {
            count_char = 0;
        }
    }
    return count;
}

int count_word_with_vocals_tok(char s[]) {
    int i = 0;
    int count_in_world = 0;
    int count = 0;
    char separatori[] = {' ', '\0'};
    char *token = strtok(s, separatori);
    while (token != NULL) {
        while (token[i] != '\0') {
            if (is_vocal(token[i])) {
                count_in_world++;
            }
            i++;
        }
        if (count_in_world >= 5) {
            count++;
        }
        i = 0;
        count_in_world = 0;
        token = strtok(NULL, separatori);
    }
    return count;
}

void media_elementi_array(float *arr, int size, float *result) {
    int i;
    float sum = 0;
    for (i = 0; i < size; i++) {
        sum += *(arr + i);
    }
    *result = sum / (float) size;
}

void somma_cumulativa(float arr[], int size, float result[]) {
    int i, j;
    float sum = 0;
    for (i = 0; i < size; i++) {
        for (j = 0; j <= i; j++) {
            sum = sum + arr[j];
        }
        result[i] = sum;
        sum = 0;
    }
}

void max_min_int_array(int *arr, int size, int *min, int *max) {
    int i;
    *min = *(arr);
    *max = *(arr);
    for (i = 1; i < size; i++) {
        if (*(arr + i) > *max) {
            *max = *(arr + i);
        } else if (*(arr + i) < *min) {
            *min = *(arr + i);
        }
    }
}

void varianza_array(float *arr, int size, float *result) {
    float media;
    int i;
    media_elementi_array(arr, size, &media);
    for (i = 0; i < size; i++) {
        *result = *result + ((*(arr + i) - media) * (*(arr + i) - media));
    }
    *result = *result / (float) (size - 1);
}

int ricerca_element(int *arr, int size, int key) {
    int i;
    for (i = 0; i < size; i++) {
        if (*(arr + i) == key) {
            return true;
        }
    }
    return false;
}

/**
 * @brief una procedura che dati due array ordinati, li restituisce uniti in result
 * @param a
 * @param b
 * @param a_size
 * @param b_size
 * @param result
 */
void fusione_array(int *a, int *b, int a_size, int b_size, int *result) {
    int i, i_a = 0, i_b = 0;
    for (i = 0; i < a_size + b_size; i++) {
        if (i_a < a_size && i_b < b_size) {
            if (a[i_a] < b[i_b]) {
                result[i] = a[i_a];
                i_a++;
            } else {
                result[i] = b[i_b];
                i_b++;
            }
        } else if (i_a >= a_size) {
            result[i] = b[i_b];
            i_b++;
        } else {
            result[i] = a[i_a];
            i_a++;
        }
    }
}

int is_equal_arr(int a[], int b[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

void f(char *a, char *b, int *o, int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (*(a + j) == *(b + i * col + j)) {
                *(o + j) = *(o + j) + 1;
            }
        }
    }
}

void ordina_A(int *a, int size) {
    int i, j;
    int element;
    for (i = 0; i < size; i++) {
        j = i - 1;
        element = *(a + i);
        while (j >= 0 && element < *(a + j)) {
            *(a + j + 1) = *(a + j);
            j--;
        }
        *(a + j + 1) = element;
    }
}

float media_lunghezza_parole(char *s) {
    int i, count_char = 0, count_word = 0;
    for (i = 0; *(s + i) != '\0'; i++) {
        if (*(s + i) != ' ') {
            count_char++;
            if (*(s + i + 1) == ' ' || *(s + i + 1) == '\0') {
                count_word++;
            }
        }
    }

    return count_word > 0 ? (float) count_char / (float) count_word : 0.0F;
}

int is_vocal(char litteral) {
    if (litteral == 'a' || litteral == 'e' || litteral == 'i' || litteral == 'o' || litteral == 'u') {
        return 1;
    }
    return 0;
}

int max_vocal_in_word(char *s) {
    int count_vocal = 0, max_vocals = 0;
    int i = 0;
    while (*(s + i) != '\0') {
        if (*(s + i) != ' ' && is_vocal(*(s + i))) {
            count_vocal++;
        } else if (*(s + i) == ' ' || *(s + i + 1) == '\0') {
            if (count_vocal > max_vocals) {
                max_vocals = count_vocal;
            }
            count_vocal = 0;
        }
        i++;
    }
    return max_vocals;
}

float somma_array(float *a, int size) {
    int i;
    float somma = 0.0F;
    for (i = 0; i < size; i++) {
        somma = somma + *(a + i);
    }
    return somma;
}

void somma_max_soglia(float *a, int size, float soglia) {
    int i;
    while (somma_array(a, size) >= soglia) {
        for (i = 0; i < size; i++) {
            *(a + i) = *(a + i) / 2.0f;
        }
    }
}

double f_di_x(float x) {
    return (3.0f * sin((double) x)) / (pow(x, 2) + 10.0f);
}

void campionaF(double funzione(float), float partenza, float terminazione, int dimensione_griglia, float f_c[]) {
    float passo, punto_griglia;
    int i;
    passo = (terminazione - partenza) / (float) (dimensione_griglia);

    for (i = 0; i < dimensione_griglia; i++) {
        punto_griglia = partenza + (float) (i) * passo;
        f_c[i] = (float) funzione(punto_griglia);
    }
}

void array_casual(int *p, int size) {
    srand(time(0));
    int i;
    for (i = 0; i < size; i++) {
        *(p + i) = 0 + rand() % (99 + 1 - 0);
    }
}

void unione_insiemi(int *a, int *b, int size_a, int size_b, int **new_insieme, int *new_size) {
    int i;

    // Inizializza il nuovo array con gli elementi di `a`
    *new_size = size_a;
    *new_insieme = (int *) calloc(*new_size, sizeof(int));
    if (*new_insieme == NULL) {
        printf("Memoria non allocata: Errore\n");
        return;
    }

    // Copia gli elementi di `a`
    for (i = 0; i < *new_size; i++) {
        *(*new_insieme + i) = a[i];
    }

    // Aggiungi elementi di `b` che non sono già presenti
    for (i = 0; i < size_b; i++) {
        if (!ricerca_element(*new_insieme, *new_size, b[i])) {
            (*new_size)++;
            *new_insieme = (int *) realloc(*new_insieme, (*new_size) * sizeof(int));
            if (*new_insieme == NULL) {
                printf("Errore nella reallocazione\n");
                return;
            }
            *(*new_insieme + *new_size - 1) = b[i];
        }
    }
}

void intersezione(int *a, int *b, int size_a, int size_b, int **risultato, int *new_size) {
    int i;
    *new_size = 0;
    for (i = 0; i < size_a; i++) {
        if (ricerca_element(b, size_b, *(a + i))) {
            *risultato = realloc(*risultato, ++(*new_size) * sizeof(int));
            *(*risultato + *new_size - 1) = *(a + i);
        }
    }
}

/**
 * @brief Funzione che verifica se A ⊂ B
 * @param a insieme A
 * @param b insieme B
 * @param size_a Cardinalità A
 * @param size_b Cardinalità B
 * @return verifica booleana se A è incluso in B
 */
int inclusione(int *a, int *b, int size_a, int size_b) {
    int i;
    for (i = 0; i < size_a; i++) {
        if (!ricerca_element(b, size_b, *(a + i))) {
            return 0;
        }
    }
    return 1;
}

void sottrazione_insiemistica(int *a, int *b, int size_a, int size_b, int **result, int *size_r) {
    int i;
    *size_r = 0;
    for (i = 0; i < size_a; i++) {
        if (!ricerca_element(b, size_b, *(a + i))) {
            *result = realloc(*result, ++(*size_r));
            *(*result + *size_r - 1) = *(a + i);
        }
    }
}

int uguaglianza_insiemistica(int *a, int *b, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (!ricerca_element(b, size, *(a + i))) {
            return 0;
        }
    }
    return 1;
}

void leggi_m(double *mat, int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%lf", mat + i * col + j);
        }
        printf("\n");
    }
}

void ese18118024(double *mat, int n_colonne, int row, int col) {
    leggi_m(mat, row, col);
    int i, j;
    double somma_quad = 0, somma = 0;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            somma_quad = somma_quad + pow(*(mat + i * n_colonne + j), 2);
            somma = somma + *(mat + i * n_colonne + j);
        }
        printf("la media della riga %d e\': %lf\n", i, somma / col);
        somma = 0;
    }
    for (j = 0; j < col; j++) {
        for (i = 0; i < row; i++) {
            somma_quad = somma_quad + pow(*(mat + i * n_colonne + j), 2);
            somma = somma + *(mat + i * n_colonne + j);
        }
        printf("la media della colonna %d e\': %lf\n", j, somma / row);
        somma = 0;
    }
    printf("la somma del quadrato di ogni elemento %lf", somma_quad);
}

int equal_string(const char *string1, const char *string2) {
    int i = 0;
    while (string2[i] != '\0' && string1[i] != '\0') {
        if (string2[i] != string1[i]) {
            return 0;
        }
        i++;
    }
    return 1;
}

int equal_array_char(const char *string1, const char *string2, int len) {
    int i;
    for (i = 0; i < len; i++) {
        if (*(string1 + i) != *(string2 + i)) {
            return 0;
        }
    }
    return 1;
}

int pattern_matching(const char *text, const char *pattern) {
    int i = 0;
    int text_size = strlen(text), pattern_size = strlen(pattern);

    while (i <= text_size - pattern_size) {
        if (equal_string(text + i, pattern)) {
            return 1;
        }
        i++;
    }
    return 0;
}

int best_matching(const char *text, const char *pattern) {
    int size_text = strlen(text), size_pattern = strlen(pattern);
    int matching_count = 0, max_matching_value = 0, i = 0, j = 0;
    while (i <= size_text - size_pattern) {
        while (pattern[j] != '\0') {
            if (text[i + j] == pattern[j]) {
                matching_count++;
            }
            j++;
        }
        if (max_matching_value < matching_count) {
            max_matching_value = matching_count;
        } else if (max_matching_value == size_pattern) {
            return max_matching_value;
        }
        matching_count = 0;
        j = 0;
        i++;
    }
    return max_matching_value;
}


int somma_righe_dispari(const int *mat, int row, int col) {
    int i, j, somma = 0;
    for (i = 1; i < row; i = i + 2) {
        for (j = 0; j < col; j++) {
            somma = somma + *(mat + i * col + j);
        }
    }
    return somma;
}

float media_righe_dispari(const int *mat, int row, int col) {
    int i, j, elements = 0;
    float somma = 0;

    for (i = 1; i < row; i = i + 2) {
        for (j = 0; j < col; j++) {
            somma = somma + (float) *(mat + i * col + j);
            elements++;
        }
    }
    return somma / (float) elements;
}


float somma_elementi_matrice(const float *mat, int row, int col, int colonne_effettive) {
    int i, j;
    float somma = 0;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            somma = somma + *(mat + i * colonne_effettive + j);
        }
    }
    return somma;
}


void media_righe_colonne(float *mat, float *avg_c, float *avg_r, int col, int row) {
    int i, j;
    for (i = 0; i < row; i++) {
        *(avg_r + i) = 0.0f;
        for (j = 0; j < col; j++) {
            if (i == 0) {
                *(avg_c + j) = 0.0f; // Reset della colonna j durante il primo passaggio
            }
            *(avg_r + i) = *(mat + i * col + j) + *(avg_r + i);
            *(avg_c + j) = (*(mat + i * col + j) / (float) row) + *(avg_c + j);
        }
        *(avg_r + i) = *(avg_r + i) / (float) col;
    }
}


void search(char *mat, const int row, const int col, char *password) {
    int i;
    int flag = 1;
    for (i = 0; i < row; i++) {
        if (equal_array_char(mat + i * col + 0, password, col)) {
            printf("la password e\' salvata nella riga %d", i);
            return;
        }
    }
    printf("la pssword non e\' presente da nessuan parte");
}

void swap_in_arr(int *arr, int n) {
    int i;
    for (i = 0; i < n / 2; i++) {
        swap(arr + i, arr + (n - 1) - i);
    }
}

void swap_beetwen_arr(int *arr1, int *arr2, int size) {
    int i = 0;
    int temp;
    for (i = 0; i < size; i++) {
        temp = *(arr1 + i);
        *(arr1 + i) = *(arr2 + i);
        *(arr2 + i) = temp;
    }
}

void swap_matrice(int *mat, int row, int col) {
    int i;
    for (i = 0; i < row; i++) {
        swap_in_arr(mat + i * col, col);
    }
    for (i = 0; i < row / 2; i++) {
        swap_beetwen_arr(mat + i * col, mat + (row - 1 - i) * col, col);
    }
}

/*data una matrice definire una funzione che restituisce in output due array che hanno il count delle vocali*/
void vocal_row_col(const char *mat, int row, int col, int *vocal_row, int *vocal_col) {
    int i, j;
    for (i = 0; i < row; i++) {
        *(vocal_row + i) = 0;
        for (j = 0; j < col; j++) {
            if (i == 0) {
                *(vocal_col + j) = 0;
            }
            if (is_vocal(*(mat + i * col + j))) {
                (*(vocal_row + i))++;
                (*(vocal_col + j))++;
            }
        }
    }
}


void cons_row_col(const char *mat, int row, int col, int *vocal_row, int *vocal_col) {
    int i, j;
    for (i = 0; i < row; i++) {
        *(vocal_row + i) = 0;
        for (j = 0; j < col; j++) {
            if (i == 0) {
                *(vocal_col + j) = 0;
            }
            if (!is_vocal(*(mat + i * col + j))) {
                (*(vocal_row + i))++;
                (*(vocal_col + j))++;
            }
        }
    }
}

void max_in_col_row(const int *mat, int row, int col, int *maxs_row, int *maxs_col) {
    int i, j;
    for (i = 0; i < row; i++) {
        *(maxs_row + i) = *(mat + i * col + 0);
        for (j = 0; j < col; j++) {
            if (i == 0) {
                *(maxs_col + j) = *(mat + i * col + j);
            }
            *(maxs_row + i) = *(maxs_row + i) < *(mat + i * col + j) ? *(mat + i * col + j) : *(maxs_row + i);
            *(maxs_col + j) = *(maxs_col + j) < *(mat + i * col + j) ? *(mat + i * col + j) : *(maxs_col + j);
        }
    }
}

void index_min(const int *mat, int row, int col, int *index_row, int *index_col) {
    int i, j;
    int min = *(mat + 0 * col + 0);
    *index_col = 0;
    *index_row = 0;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (min > *(mat + i * col + j)) {
                min = *(mat + i * col + j);
                *index_col = j;
                *index_row = i;
            }
        }
    }
}

void index_max(const int *mat, int row, int col, int *index_row, int *index_col) {
    int i, j;
    int max = *(mat + 0 * col + 0);
    *index_col = 0;
    *index_row = 0;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (max < *(mat + i * col + j)) {
                max = *(mat + i * col + j);
                *index_col = j;
                *index_row = i;
            }
        }
    }
}


void my_strcat(char **str1, char *str2) {
    int i, j = 0;
    int len1 = strlen(*str1); // Lunghezza attuale di str1
    int len2 = strlen(str2); // Lunghezza di str2
    int new_dimension = len1 + len2 + 1; // Nuova dimensione totale

    // Ridimensiona la memoria puntata da *str1
    *str1 = realloc(*str1, new_dimension);
    if (*str1 == NULL) {
        // Controlla se realloc ha fallito
        fprintf(stderr, "Errore di allocazione della memoria\n");
        return;
    }

    // Copia i caratteri di str2 in *str1
    for (i = len1; i < new_dimension - 1; i++) {
        (*str1)[i] = str2[j++];
    }

    (*str1)[new_dimension - 1] = '\0'; // Aggiungi il terminatore nullo
}

void count_vowels(char *arr[], int rows, int cols, int *voc_row, int *voc_col) {
    int i, j;

    // Contiamo le vocali per riga e per colonna
    for (i = 0; i < rows; i++) {
        voc_row[i] = 0;
        for (j = 0; j < cols; j++) {
            if (i == 0) {
                voc_col[j] = 0;
            }
            if (is_vocal(arr[i][j])) {
                voc_row[i]++; // Conta le vocali per riga
                voc_col[j]++; // Conta le vocali per colonna
            }
        }
    }
}

int count_word_in_text(char *testo) {
    int i = 0;
    int count = 0;
    while (*(testo + i) != '\0') {
        if (testo[i] != ' ' && (testo[i + 1] == ' ' || testo[i + 1] == '\0')) {
            count++;
        }
        i++;
    }
    return count;
}

char *my_tokenizer(char *text, char delimitatore) {
    static char *current_position = NULL; // Tiene traccia della posizione corrente
    if (text != NULL) {
        current_position = text; // Inizializza per la prima chiamata
    }
    if (current_position == NULL || *current_position == '\0') {
        return NULL; // Fine della stringa o chiamata invalida
    }

    // Salta i delimitatori iniziali
    while (*current_position == delimitatore) {
        current_position++;
    }

    if (*current_position == '\0') {
        return NULL; // Fine della stringa
    }

    // Inizia il token
    char *token_start = current_position;

    // Cerca il prossimo delimitatore
    while (*current_position != '\0' && *current_position != delimitatore) {
        current_position++;
    }

    // Termina il token se non è la fine della stringa
    if (*current_position == delimitatore) {
        *current_position = '\0';
        current_position++; // Avanza oltre il delimitatore
    }

    return token_start;
}

int somma_elementi_prima_area(const int *mat, int n) {
    int i, j;
    int somma = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            somma = somma + *(mat + i * n + j);
        }
    }
    return somma;
}

int somma_elementi_seconda_area(const int *mat, int n) {
    int i, j;
    int somma = 0;
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            somma = somma + mat[i * n + j];
        }
    }
    return somma;
}

int somma_elementi_prima_area_seconda_diagonale(const int *mat, int n) {
    int i, j;
    int somma = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            printf("%d\n", mat[i * n + j]);
            somma = somma + mat[i * n + j];
        }
    }
    return somma;
}

int somma_elementi_seconda_area_seconda_diagonale(const int *mat, int n) {
    int i, j;
    int somma = 0;
    for (i = 0; i < n; i++) {
        for (j = n - 1; j >= n - i - 1; j--) {
            printf("%d\n", mat[i * n + j]);
            somma = somma + mat[i * n + j];
        }
    }
    return somma;
}

int occorrenza_carattere(const char *s, char carattere) {
    int count = 0, i = 0;
    while (s[i] != '\0') {
        if (s[i] == carattere) {
            count++;
        }
        i++;
    }
    return count;
}

void all_occorenze(const char *s, int *result) {
    char *alfabeto = "abcdefghilmnopqrstuvzjxywz\0";
    int i = 0;
    while (alfabeto[i] != '\0') {
        *(result + i) = 0;
        *(result + i) = occorrenza_carattere(s, alfabeto[i]);
        i++;
    }
}

void to_upper_case(char *s) {
    int i = 0;

    while (s[i] != '\0') {
        if ('a' <= s[i] && s[i] <= 'z') {
            s[i] = (char) s[i] - ('a' - 'A');
        }
        i++;
    }
}

void char_swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse_string(char string[]) {
    int size = strlen(string);
    int i;
    for (i = 0; i < size / 2; i++) {
        char_swap(&string[i], &string[size - 1 - i]);
    }
}

void cript_in_ascii(char *string, int n) {
    int i = 0;
    while (*(string + i) != '\0') {
        *(string + i) = (string[i] + n) % 127;
        i++;
    }
}

int index_in_alph(char *alphabet, char value) {
    int i = 0;
    while (alphabet[i] != '\0') {
        if (alphabet[i] == value) {
            return i;
        }
        i++;
    }
    return 0;
}

void cript_cesar(char *string, int n) {
    char alfabeto[] = "abcdefghijklmnopqrstuvwxyz";
    int i = 0;
    while (string[i] != '\0') {
        string[i] = alfabeto[(index_in_alph(alfabeto, string[i]) + n) % strlen(alfabeto)];
        i++;
    }
}

void upper_first_world(char *string) {
    int i = 0;
    while (string[i] != '\0') {
        if ((string[i] >= 'a' && string[i] <= 'z') && string[i - 1] == ' ' || i == 0) {
            string[i] = string[i] - ('a' - 'A');
        }

        i++;
    }
}

void cesar_soft(char *string) {
    int i = 0;
    const int offset = 1;
    while (string[i] != '\0') {
        if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] = 'a' + (string[i] - 'a' + offset) % 26;
        }
        i++;
    }
}

void decript_cesar_soft(char *string) {
    int i = 0;
    const int offset = -1;
    while (string[i] != '\0') {
        if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] = 'z' + (string[i] - 'z' + offset) % 26;
        }
        i++;
    }
}

int my_strcmp(const char *s1, const char *s2) {
    int i = 0;
    while ((s1[i] != '\0' && s2[i] != '\0') || s1[i] != s2[i]) {
        if (s1[i] < s2[i]) {
            return -1;
        } else if (s1[i] > s2[i]) {
            return 1;
        }
        i++;
    }

    return 0;
}

unsigned int my_strlen(const char *s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

char *my_strlowe(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = (char) (str[i] + 32);
        }

        i++;
    }
    return str;
}

char *my_strstr(char *s1, char *s2) {
    int i;
    int s1_size = (int) my_strlen(s1);
    int s2_size = (int) my_strlen(s2);
    if (s2_size > s1_size) {
        return NULL;
    }
    for (i = 0; i <= s1_size - s2_size; i++) {
        if (equal_string(s1 + i, s2)) {
            return s1 + i;
        }
    }
    return NULL;
}

void fusione_alfabeti_ordinati(char *alpha1, char *alpha2, char *result) {
    int size1 = (int) my_strlen(alpha1), size2 = (int) my_strlen(alpha2);

    int i = 0, j = 0, r;
    for (r = 0; r < size1 + size2; r++) {
        if (i < size1 && j < size2) {
            if (alpha1[i] < alpha2[j]) {
                result[r] = alpha1[i];
                i++;
            } else {
                result[r] = alpha2[j];
                j++;
            }
        } else if (i >= size1) {
            result[r] = alpha2[j];
            j++;
        } else {
            result[r] = alpha1[i];
            i++;
        }
    }
    result[size1 + size2] = '\0';
}

void delete_occorenze_vicini(char *s, char litteral) {
    int i = 0;
    while (s[i] != '\0') {
        while (s[i] == litteral && s[i + 1] == litteral) {
            strcpy(s + i, s + i + 1);
        }
        i++;
    }
}

int all_diversi(int *arr, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n - 1; j++) {
            if (arr[i] == arr[j]) {
                return 0;
            }
        }
    }
    return 1;
}

void count_char_in_string(char *s, int *vocali, int *consonati) {
    int i = 0;
    *vocali = 0;
    *consonati = 0;
    while (s[i] != '\0') {
        if (is_vocal(s[i])) {
            *vocali = *vocali + 1;
        } else {
            *consonati = *consonati + 1;
        }
        i++;
    }
}

char *invert_upper_lower(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = (char) (s[i] - 32);
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = (char) (s[i] + 32);
        }
        i++;
    }
    return s;
}

int check_revers(char *s, char *s2) {
    int size1 = (int) my_strlen(s), size2 = (int) my_strlen(s2);
    int i = 0;
    if (size1 != size2) {
        return 0;
    }
    while (s2[i] != '\0') {
        if (s2[i] != s[size2 - i - 1]) {
            return 0;
        }
        i++;
    }
    return 1;
}

void scomposizione_email(char *email, char *utente, char *dominio, char *root) {
    int i = 0, j = 0, k = 0;
    while (email[i] != '@') {
        utente[i] = *(email + i);
        i++;
    }
    utente[i] = '\0';
    i++;
    while (email[i] != '.') {
        dominio[j] = email[i];
        i++;
        j++;
    }

    dominio[j] = '\0';
    i++;
    while (email[i] != '\0') {
        root[k] = email[i];
        k++;
        i++;
    }

    root[k] = '\0';
}

int second_max_matrice(const int *mat, int row, int col) {
    int max = *(mat + 0 * col + 0), max2 = *(mat + 0 * col + 0);
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (*(mat + i * col + j) > max) {
                max2 = max;
                max = *(mat + i * col + j);
            } else if (*(mat + i * col + j) > max2 && *(mat + i * col + j) < max) {
                max2 = *(mat + i * col + j);
            } else if (max2 == max && *(mat + i * col + j) < max2) {
                max2 = *(mat + i * col + j);
            }
        }
    }
    return max2;
}

int max_tra_somma_colonne(int *mat, int row, int col) {
    int somma = 0;
    int max_somma = 0;
    int i, j;
    for (j = 0; j < col; j++) {
        for (i = 0; i < row; i++) {
            somma = somma + *(mat + i * col + j);
        }
        if (j == 0) {
            max_somma = somma;
        } else if (somma > max_somma) {
            max_somma = somma;
        }
        somma = 0;
    }
    return max_somma;
}

void parola_minima_testo(char testo[], int *dimension, char parola[], int *position) {
    char separatore[] = {' ', '\0'};
    char *token = strtok(testo, separatore);
    int token_dimension;
    *dimension = (int) strlen(token);
    while (token != NULL) {
        token_dimension = (int) strlen(token);
        if (token_dimension < *dimension) {
            *dimension = token_dimension;
            strcpy(parola, token);
        }
        token = strtok(NULL, separatore);
    }
}

void all_occorrenze_26(char *s, int *occorenze) {
    int i = 0;
    for (i = 0; i < 26; i++) {
        occorenze[i] = 0;
    }
    i = 0;
    while (s[i] != '\0') {
        (*(occorenze + s[i] - 'a'))++;
        i++;
    }
}

int index_alfabeto_21(char litteral) {
    char *alfabeto = "abcdefghilmnopqrstuvz";
    int i;
    for (i = 0; i < strlen(alfabeto); i++) {
        if (litteral == alfabeto[i]) {
            return i;
        }
    }
    return -1;
}

int is_all_true(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == 0) {
            return 0;
        }
    }
    return 1;
}

int is_pangramma(char arr[], int size) {
    int result[21] = {0};
    int i;
    int index;
    for (i = 0; i < size; i++) {
        index = index_alfabeto_21(arr[i]);
        if (index >= 0) {
            result[index] = 1;
        }
    }
    return is_all_true(result, 21);
}

void es04122024(char s[], int arr[], int *dimension) {
    int i = 0;
    char separatori[] = {' ', '\t', '\n', '\0'};
    int count = 0;
    char *token = strtok(s, separatori);
    while (token != NULL) {
        arr[count] = 0;
        while (token[i] != '\0') {
            if (is_vocal(token[i])) {
                arr[count]++;
            }
            i++;
        }
        i = 0;
        count++;
        token = strtok(NULL, separatori);
    }
    *dimension = count;
}

int somma_k_riga(const int *arr, int row, int col, int k) {
    int somma = 0;
    int j;
    if (k > row - 1) {
        return NAN;
    }
    for (j = 0; j < col; j++) {
        somma = somma + *(arr + k * col + j);
    }
    return somma;
}

void sign_diagonale_prima(int *mat, int row_col) {
    int i, j;
    for (i = 0; i < row_col; i++) {
        for (j = 0; j < row_col; j++) {
            *(mat + i * row_col + j) = 0;
            if (i == j) {
                *(mat + i * row_col + j) = 1;
            }
        }
    }
}

int is_scacchiera(int *mat, int row, int col) {
    int i, j;
    int now = 1;
    int expected;
    if (!(row == 8 && col == 8)) {
        return 0;
    }
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            expected = (i + j) % 2;
            if (mat[i * col + j] != !expected) {
                return 0;
            }
        }
    }
    return 1;
}

int is_compreso(int *mat, int row_col, int n, int m) {
    int i, j;
    for (i = 0; i < row_col; i++) {
        for (j = 0; j < row_col; j++) {
            if (!(mat[i * row_col + j] >= n && mat[i * row_col + j] <= m)) {
                return 0;
            }
        }
    }
    return 1;
}

int index_min_arr(int *arr, int size) {
    int i;
    int min = arr[0], index = 0;
    for (i = 1; i < size; i++) {
        if (min > arr[i]) {
            min = arr[i];
            index = i;
        }
    }
    return index;
}

void ordinamento_minimo(int a[], int size) {
    int i, j;
    int min, index;
    for (i = 0; i < size - 1; i++) {
        index = index_min_arr(a + i, size - i);
        swap(a + i, a + i + index);
    }
}


long long int fibonacci(long long int n) {
    int i;
    long long int prec = 1;
    long long int prec_2 = 0;
    long long int value = 0;
    for (i = 2; i <= n; i++) {
        value = prec + prec_2;
        prec_2 = prec;
        prec = value;
    }
    return value;
}

int ricerca_binaria(int *a, int size, int key) {
    if (size <= 0) {
        return 0;
    }
    int mediano = size / 2;
    if (a[mediano] == key) {
        return 1;
    } else if (key > a[mediano]) {
        return ricerca_binaria(a + mediano + 1, size - mediano - 1, key);
    } else {
        return ricerca_binaria(a, mediano, key);
    }
}

int ricerca_binaria_2(int *a, int size, int key) {
    int ultimo = size - 1;
    int mediano = ultimo / 2;
    if (key == *(a + mediano)) {
        return 1;
    }
    if (key > *(a + mediano) && size > 0) {
        return ricerca_binaria(a + mediano + 1, size - mediano - 1, key);
    }
    if (key < *(a + mediano) && size > 0) {
        return ricerca_binaria(a, mediano, key);
    }

    return 0;
}

int somma_doppia(int *a, int size) {
    if (size <= 0) {
        return 0;
    }
    if (size == 1) {
        return *a;
    } else {
        return somma_doppia(a, size - 2) + a[size - 1] + a[size - 2];
    }
}

int max_doppia(int *a, int size) {
    if (size == 1) {
        return a[0]; // Se c'è un solo elemento, è il massimo.
    } else if (size == 2) {
        // Se ci sono due elementi, restituisci il massimo tra loro.
        return (a[0] > a[1]) ? a[0] : a[1];
    } else {
        // Calcola il massimo tra gli ultimi due e il massimo calcolato finora.
        int max_corrente = (a[size - 1] > a[size - 2]) ? a[size - 1] : a[size - 2];
        int max_precedente = max_doppia(a, size - 2);
        return (max_corrente > max_precedente) ? max_corrente : max_precedente;
    }
}

int sum_natural(int n) {
    if(n == 1) {
        return n;
    } else {
        return n + sum_natural(n - 1);
    }
}

int fattorial_r(int n) {
    if(n == 1) {
        return 1;
    } else {
        return n * fattorial_r(n - 1);
    }
}
void min_distance_index(punto p, int size) {
    int i, j;
    int index_p1 = 0;
    int index_p2 = 1;
    double min_distance = distanza_p1_p2(p[0].x,p[0].y,p[1].x,p[1].y);
    double actual_distance;
    for(i = 0; i < size; i++) {
        for(j = i + 1; j < size; j++) {
            actual_distance = distanza_p1_p2(p[i].x,p[i].y,p[j].x,p[j].y);
            if(actual_distance < min_distance) {
                min_distance = actual_distance;
                index_p1 = i;
                index_p2 = j;
            }
        }
    }
    printf("%d %d", index_p1, index_p2);
}

double max_distance(punto p, int size) {
    double max_distance = distanza_p1_p2(p[0].x, p[0].y, p[1].x, p[1].y);
    double actual_distance;
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            actual_distance = distanza_p1_p2(p[i].x, p[i].y, p[j].x, p[j].y);
            if (max_distance < actual_distance) {
                max_distance = actual_distance;
            }
        }
    }
    return max_distance;
}


int max_lenght_in_text(char s[]) {
    char delim [] = {' ', '\0',};
    char * token = strtok(s, delim);
    int max = 0;
    int actual_max;
    while (token != NULL) {
        actual_max = (int)my_strlen(token);
        if(actual_max > max) {
            max = actual_max;
        }
        token = strtok(NULL, delim);
    }
    return max;
}


/*Sviluppare una function C (moda) che, dati come parametri di input un array di int  e il
suo size, determina e restituisce come parametro di output il valore più frequente (che in
statistica prende il nome di moda) */

int moda(int *a, int size, int *time, int *element) {
    int i, j;
    int actual_time = 0;
    int actual_element = *(a + 0);
    *element = *(a + 0);
    *time = 0;
    for (i = 0; i < size; i++) {
        actual_element = *(a + i);
        for (j = i; j < size; j++) {
            if(actual_element == *(a + j)) {
                actual_time++;
            }
        }
        if(actual_time > *time) {
            *time = actual_time;
            *element = actual_element;
        }
        actual_time = 0;
    }
}

/**
  0 1 2 3 4
0[][][][][]
1[][][][][]
2[][][][][]
3[][][][][]
4[][][][][]
**/
