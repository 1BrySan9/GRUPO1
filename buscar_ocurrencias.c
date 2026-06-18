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

