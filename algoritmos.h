#ifndef ALGORITMOS_H
#define ALGORITMOS_H

/*
 * algoritmos.h
 * IE-0117 - Tarea en clase: Ordenamiento y Búsqueda
 *
 * Cada función recibe un arreglo dinámico y su tamaño.
 * Las funciones de ordenamiento modifican el arreglo original.
 * Las funciones de búsqueda retornan índices o conteos.
 */

/* ── Ordenamiento ─────────────────────────────────────── */

/* Ordena arr de menor a mayor usando bubble sort. */
void bubble_sort(int *arr, int n);

/* Ordena arr de menor a mayor usando selection sort. */
void selection_sort(int *arr, int n);

/* Ordena arr de menor a mayor usando insertion sort. */
void insertion_sort(int *arr, int n);

/* ── Búsqueda ─────────────────────────────────────────── */

/* Retorna el índice de la primera aparición de valor en arr,
 * o -1 si no se encuentra. No requiere que arr esté ordenado. */
int busqueda_lineal(int *arr, int n, int valor);

/* Retorna el índice de valor en arr usando búsqueda binaria.
 * Requiere que arr esté ordenado. Retorna -1 si no se encuentra. */
int busqueda_binaria(int *arr, int n, int valor);

/* Busca todas las posiciones donde aparece valor en arr.
 * Almacena los índices en el arreglo posiciones[] y retorna
 * cuántas ocurrencias encontró.
 * El llamador debe asegurarse de que posiciones tenga espacio
 * para al menos n elementos. */
int buscar_ocurrencias(int *arr, int n, int valor, int *posiciones);

#endif /* ALGORITMOS_H */
