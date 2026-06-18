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
