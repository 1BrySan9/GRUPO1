/*
 * main.c
 * IE-0117 - Tarea en clase: Ordenamiento y Búsqueda
 *
 * No modificar este archivo.
 * Implementar las funciones en algoritmos.c.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algoritmos.h"

/* Imprime un arreglo en una línea */
static void imprimir(const char *etiqueta, int *arr, int n) {
    int i;
    printf("%-20s [ ", etiqueta);
    for (i = 0; i < n; i++)
        printf("%3d%s", arr[i], i < n - 1 ? "," : "");
    printf(" ]\n");
}

/* Copia src en dst (mismo tamaño n) */
static void copiar(int *dst, int *src, int n) {
    memcpy(dst, src, (size_t)n * sizeof(int));
}

/* Imprime los índices donde se encontraron ocurrencias */
static void imprimir_ocurrencias(int *pos, int k) {
    int i;
    if (k == 0) {
        printf("(no encontrado)\n");
        return;
    }
    printf("indices [ ");
    for (i = 0; i < k; i++)
        printf("%d%s", pos[i], i < k - 1 ? ", " : "");
    printf(" ]\n");
}

int main(void) {
    /* ── Datos originales ───────────────────────────────── */
    int datos_originales[] = {42, 17, 8, 55, 23, 8, 91, 4, 8, 36};
    int n = 10;
    int valor_busqueda = 8;

    /* ── Reservar arreglo dinámico ──────────────────────── */
    int *arr = malloc((size_t)n * sizeof(int));
    int *copia = malloc((size_t)n * sizeof(int));
    int *posiciones = malloc((size_t)n * sizeof(int));

    if (!arr || !copia || !posiciones) {
        fprintf(stderr, "Error: malloc fallo.\n");
        return 1;
    }

    printf("=== Tarea en clase: Ordenamiento y Búsqueda ===\n\n");
    imprimir("Arreglo original:", datos_originales, n);
    printf("\n");

    /* ── Bubble sort ────────────────────────────────────── */
    copiar(arr, datos_originales, n);
    bubble_sort(arr, n);
    imprimir("Bubble sort:", arr, n);

    /* ── Selection sort ─────────────────────────────────── */
    copiar(arr, datos_originales, n);
    selection_sort(arr, n);
    imprimir("Selection sort:", arr, n);

    /* ── Insertion sort ─────────────────────────────────── */
    copiar(arr, datos_originales, n);
    insertion_sort(arr, n);
    imprimir("Insertion sort:", arr, n);

    printf("\n");

    /* ── Búsqueda lineal (sobre datos originales) ───────── */
    copiar(arr, datos_originales, n);
    int idx_lineal = busqueda_lineal(arr, n, valor_busqueda);
    printf("Busqueda lineal  (valor=%d): ", valor_busqueda);
    if (idx_lineal >= 0)
        printf("primer indice = %d\n", idx_lineal);
    else
        printf("no encontrado\n");

    /* ── Búsqueda binaria (sobre arreglo ordenado) ──────── */
    copiar(arr, datos_originales, n);
    insertion_sort(arr, n);          /* ordenar primero */
    imprimir("Ordenado p/binaria:", arr, n);
    int idx_binaria = busqueda_binaria(arr, n, valor_busqueda);
    printf("Busqueda binaria (valor=%d): ", valor_busqueda);
    if (idx_binaria >= 0)
        printf("indice = %d\n", idx_binaria);
    else
        printf("no encontrado\n");

    /* ── Todas las ocurrencias ──────────────────────────── */
    copiar(arr, datos_originales, n);
    int k = buscar_ocurrencias(arr, n, valor_busqueda, posiciones);
    printf("Ocurrencias      (valor=%d): %d ocurrencia(s) en ", valor_busqueda, k);
    imprimir_ocurrencias(posiciones, k);

    /* ── Liberar memoria ────────────────────────────────── */
    free(arr);
    free(copia);
    free(posiciones);

    return 0;
}
