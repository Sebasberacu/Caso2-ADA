#include "libs.h"

/*
*   QUICKSORT
*   es un algoritmo de tipo "divide y vencerás"
*   se basa en escoger un elemento llamado "pivote" que se usa para dividir la colección
*   los elementos menores al pivote se ordenarán a la izquierda, los mayores a la derecha
*   aplicar quicksort a las "sublistas" generadas por la partición del pivote
*   Hay 4 diferentes patrones para escoger el pivote:
        1. Escoger el primer elemento -> si primer elemento NO es un límite
        2. Escoger el último elemento -> si último elemento NO es un límite
        3. Escoger "la media" -> datos "medianamente" ordenados
        4. Escoger un elemento aleatorio -> si se desconoce el orden de la colección
*   Si los datos son aleatorios o desconocidos, realmente no importa qué elemento se selecciona como pivote
*/

void simpleSort(int arr[], int size) {
    int temp;
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int particionar(int arr[], int imin, int imax) {

    int pivot = imin;

    /*INTERCAMBIAR LOS ELEMENTOS DE ACUERDO CON SU VALOR VS PIVOTE*/
    int i = imin;   // i es el índice de inicio que retorna para luego "dividir" la colección en mitades
    int j = i+1;    // indice de fin
    // loop hace comparaciones hasta que salga del ciclo
    while (j <= imax) {
        if (arr[j] < arr[pivot]) {  // si el siguiente elemento es menor al pivote (inicia como el anterior)
            i++;    // aumente el indice de retorno
            swap(arr[i], arr[j]);
        }
        j++;    // aumente el indice final
    }
    swap(arr[i], arr[pivot]);   // pivote ordenado en su posicion final
    /*INTERCAMBIAR LOS ELEMENTOS DE ACUERDO CON SU VALOR VS PIVOTE*/
    return i;   // devuelve el índice de la partición
}

int particionarRandom(int arr[], int imin, int imax) {
    srand(time(NULL));
    int random = imin + rand() % (imax - imin);
    swap(arr[random], arr[imin]);
    return particionar(arr, imin, imax);
}

int particionarAlto(int arr[], int imin, int imax) {
    int pivot = imax;
    int i = imin;
    int j = imin;
    while (i <= imax) {
        if (arr[i] > arr[pivot]) {
            i++;
        }
        else {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
    }
    return (j-1);
}

int particionarMediana(int arr[], int imin, int imax) {
    int tab[] = {imin, (imax - imin) / 2, imax};
    simpleSort(tab, 3);
    int ind = 3 / 2;
    int mediana = tab[ind];
    swap(arr[mediana], arr[imin]);
    return particionar(arr, imin, imax);

}

void quickSort(int arr[], int imin, int imax, int pivot) {
    int k;
    if (imin >= imax) { return; } // condicion de parada
    int pivotType = pivot;
    switch (pivotType) {
    case 0:
        k = particionar(arr, imin, imax);
        break;
    case 1:
        k = particionarAlto(arr, imin, imax);
        break;
    case 2:
        k = particionarMediana(arr, imin, imax);
        break;
    case 3:
        k = particionarRandom(arr, imin, imax);
        break;
    default:
        k = particionar(arr, imin, imax);
        break;
    }    
    quickSort(arr, imin, k-1, pivot); // mitad izquierda
    quickSort(arr, k+1, imax, pivot); // mitad derecha
}
