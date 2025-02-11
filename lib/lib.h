typedef struct {
    double x;
    double y;
} punto[];

float distanza_p1_p2(float,float,float,float);

float distanza_O(float,float);

void diseq2Grade(double a, double b, double c, char sign, char * result, double * discriminante);

int mcd(int a, int b);

void pow2(int* x);

double formula_x(double);
double formula_y(double);
void formula_xy(double, double, double *, double *);
void real_formula_x(double x, double* result);

int* concArray(int a1[], int a2[], int n, int m );

int *traspostaMatrice(int *matrice, int row, int col);
int* sommaMatrici(int *matrice1, int *matrice2, int n, int m);

int somma_elementi_array(int* a, int size);
void procedura_somma_elementi_array(int *a, int size, int* result);
int max_sum_matrice_col(int *mat, int row, int col);
int max_sum_matrice_row(int *mat, int row, int col);

int count_3lettereword(char word1[]);
int count_parole_are(char s[]);
int count_word_start_terminate(char s[], char start, char end);

int count_word_with_vocals(char s[]);
void media_elementi_array(float *arr, int size, float *result);

void somma_cumulativa(float arr [], int size, float result[]);

void f(char *a, char *b, int *o, int row, int col);
void leggi_a(int *a, int size);
void visulaizza_a(int *a, int start,int size);

void ordina_A(int *a, int size);

float media_lunghezza_parole(char *s);
int is_vocal(char litteral);
int max_vocal_in_word(char *s);

void array_casual(int *p, int size);
void unione_insiemi(int *a, int *b, int size_a, int size_b, int **new_insieme, int *new_size);
void intersezione(int *a, int *b, int size_a, int size_b, int **risultato, int *new_size);
int inclusione(int *a, int *b, int size_a, int size_b);
void sottrazione_insiemistica(int *a, int *b, int size_a, int size_b, int **result, int *size_r );
int uguaglianza_insiemistica(int *a, int *b, int size);
void ese18118024(double *mat, int n_colonne, int row, int col);

int equal_string(const char * string1, const char * string2);
int pattern_matching(const char * text, const char * pattern);
int best_matching(const char * text, const char * pattern);


int somma_righe_dispari(const int * mat, int row, int col);
float media_righe_dispari(const int * mat, int row, int col);
void media_righe_colonne(float *mat, float *avg_c, float *avg_r, int col, int row);
void search(char *mat, const int row, const int col, char *password);
void swap_matrice(int *mat, int row, int col);
void vocal_row_col(const char * mat, int row, int col, int * vocal_row, int * vocal_col);
void cons_row_col(const char * mat, int row, int col, int * vocal_row, int * vocal_col);
void max_in_col_row(const int * mat, int row, int col, int * maxs_row, int * maxs_col);
void index_min(const int * mat,int row, int col, int * index_row, int * index_col);

void count_vowels(char *arr[], int rows, int cols, int *voc_row, int *voc_col);
int count_word_in_text(char * testo);
char * my_tokenizer(char * text, char delimitatore);
int somma_elementi_prima_area(const int *mat, int n);
int somma_elementi_seconda_area(const int * mat, int n);
int somma_elementi_prima_area_seconda_diagonale(const int * mat, int n);
int occorrenza_carattere(const char * s, char carattere);
void all_occorenze(const char * s, int * result);
void to_upper_case(char * s);
void reverse_string(char *string);
void cript_in_ascii(char *string, int n);
void cript_cesar(char *string, int n);
void upper_first_world(char * string);
void cesar_soft(char * string);
void decript_cesar_soft(char * string);
int my_strcmp(const char *s1, const char *s2);
char * my_strlowe(char * str);
char * my_strstr(char * s1, char * s2);
void fusione_alfabeti_ordinati(char *alpha1, char *alpha2, char * result);
void delete_occorenze_vicini(char * s, char litteral);
int all_diversi(int * arr, int n);
void count_char_in_string(char * s, int * vocali, int * consonati);
char * invert_upper_lower(char * s);
int check_revers(char *s, char *s2);
void scomposizione_email(char *email, char * utente, char * dominio, char * root);
int second_max_matrice(const int *mat, int row, int col);
int count_parole_are_tok(char s[]);
void parola_minima_testo(char testo[], int *dimension, char parola[], int *position);
void all_occorrenze_26(char *s, int *occorenze);
int is_pangramma(char arr[], int size);
void es04122024(char s[], int arr[], int * dimension);
int somma_k_riga(const int *arr, int row, int col, int k);
void sign_diagonale_prima(int *mat, int row_col);
int is_scacchiera(int *mat, int row, int col);
int is_compreso(int * mat, int row_col, int n, int m);
void ordinamento_minimo(int * a, int size);
long long int fibonacci(long long int n);
int ricerca_binaria(int *a, int size, int key);
int ricerca_binaria_2(int *a, int size, int key);
int somma_doppia(int *a, int size);
int max_doppia(int *a, int size);
void min_distance_index(punto, int);
int moda(int *a, int size, int *time, int *element);