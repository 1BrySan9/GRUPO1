/*
 * algoritmos.c
 * IE-0117 - Tarea en clase: Ordenamiento y Búsqueda
 *
 * Implementar las funciones asignadas en este archivo.
 * No modificar algoritmos.h ni main.c.
 */

#include "algoritmos.h"

/* ── Ordenamiento ─────────────────────────────────────── */

void bubble_sort(int *arr, int n) {
    /* TODO: implementar */
    (void)arr;
    (void)n;
}

void selection_sort(int *arr, int n) {
    //se crean variables que guardan posicion y una temporal para el intercambio de variables
    int min_idx;
    int variable_temp; 

    //se realiza un primer ciclo hasta u numero menor del arreglo, pues el ultimo valor se acomoda por si solo
    for (int i = 0; i < n - 1; i++){

        //se guarda la posicion inicial en una variable i para luego ser utillizada en recorrer el puntero
        min_idx = i; 

        // j empieza una posicion mas a la de i, pues lo que se busca es compararlo con los valores siguientes
        for (int j = i +1; j < n; j++){
            
            //si el valor del puntero en j es menor que el valor del puntero en la inicial se intercambian POSICIONES
            if (*(arr + j) < *( arr + min_idx)){

                //esto permite que luego se compare sobre el menor del total de una lista desordenada
                min_idx = j;
            }
        }
        //por utimo se guarda el valor de la posicion inicialtemporalmente y luego se intercambian posiciones
        variable_temp = *(arr + i); 
        *(arr + i) = *(arr + min_idx);
        *(arr + min_idx) = variable_temp;
     }
}
void insertion_sort(int *arr, int n) {
    /* TODO: implementar */
    (void)arr;
    (void)n;
}

/* ── Búsqueda ─────────────────────────────────────────── */

int busqueda_lineal(int *arr, int n, int valor) {
    /* TODO: implementar */
    (void)arr;
    (void)n;
    (void)valor;
    return -1;
}

int busqueda_binaria(int *arr, int n, int valor) {
    /* TODO: implementar */
    (void)arr;
    (void)n;
    (void)valor;
    return -1;
}

int buscar_ocurrencias(int *arr, int n, int valor, int *posiciones) {
    /* TODO: implementar */
    (void)arr;
    (void)n;
    (void)valor;
    (void)posiciones;
    return 0;
}
