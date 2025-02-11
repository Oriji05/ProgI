//
// Created by vince on 30/10/2024.
//

#include <stdio.h>
#include "lib.h"
#include "incremental/incremental.h"

#include "sorting.h"

/**
 * @brief Una funzione che si occupa di ordinare un array di interi
 * @param array l'array che vuoi ordinare
 * @param dimension la dimensione dell'array
 */
void AOIS(int * array, int dimension) {

    int i, j;
    int  el_da_ins;
    for (i = 1; i < dimension; i++) {
        el_da_ins = array[i];
        j = i - 1;
        while (j >= 0 && el_da_ins < array[j]) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = el_da_ins;
    }
}