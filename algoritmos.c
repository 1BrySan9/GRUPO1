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
    int i, j, tmp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                tmp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = tmp;
            }
        }
    }
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
void insertion_sort(int *arr, int n) { //se asume un arreglo con punteros
	int key;
	int j;
	for(int i = 1; i<n; i++) {
		key = arr[i]; //direccionar el arrey
		j = i - 1; //asignar un valor cambiante en j para el siguiente ciclo
		while(j >= 0 && arr[j] > key) { //esto debe dezplazar los elementos hasta que la key sea mayor al elemento analizado
			arr[j + 1] = arr[j]; //esto debe mover un elemento  la derecha por ciclo superado
			j--;
		}
		arr[j + 1] = key; //esto es para cuando termine el ciclo, el valor de la key termine en el espacio "libre" disponible
	}
}
/* ── Búsqueda ─────────────────────────────────────────── */

int busqueda_lineal(int *arr, int n, int valor) {
    /* TODO: implementar */
    int i;

    for (i = 0; i < n; i++) {
        if (*(arr + i) == valor) {
            return i;
        }
    }

    return -1;
}

int busqueda_binaria(int *arr, int n, int valor) {
    //OJO se asume que el arreglo ya esta ordenado. Segun el main.c se ordena con insertion. 
    //variables utilizadas para la funcion de busqueda
    int izq = 0; 
    int der = n -1; 
    int mid; 
     //ciclo utilizado oara la busqueda
    while (izq <= der){

        //esta ecuacion permite recorrer el arreglo desde el centro hacia los lados
        mid = izq + (der - izq) / 2;

        //y segun el resultado de cada condicion cambia el valor de alguna variable
        if (*(arr + mid) == valor){
            return mid; 
        }
        if (*(arr + mid) < valor){
            izq = mid + 1;
        }
        else{
            der = mid - 1; 
        }
    }
    return -1;
}
int buscar_ocurrencias(int *arr, int n, int valor, int *posiciones) { //se presupone un arreglo con punteros
	int k = 0; //esto es para dar un valor inicial 
	for(int i = 0; i < n; i++) { //el ciclo busca que el valor de la posicion es decir k, sea el mismo que el valor de estudio i para que se denote dicha posicion 
		if(arr[i] == valor) {
			posiciones[k] = i; //la comparacion y asignacion, se realiza aca
			k++; //mientras que esto solo aumenta el conteo 
		}
	}
	return k;
}


