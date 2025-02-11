#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "incremental/incremental.h"
#include "lib/lib.h"
#include "sorting/sorting.h"




int main() {
    int value[] = {5,5,5,5,5,5,6,6};
    int time, element;
    moda(value, sizeof(value)/sizeof(int), &time, &element);

    printf("time: %d, element: %d", time, element);
}



