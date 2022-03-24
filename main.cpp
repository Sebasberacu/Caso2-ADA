#include "libs.h"

//Ascendente
#define ascendentArr1000 int arrA1K[1000]
#define ascendentArr10000 int arrA10K[10000]
#define ascendentArr100000 int arrA100K[100000]
//Descendiente
#define descendentArr1000 int arrD1K[1000]
#define descendentArr10000 int arrD10K[10000]
#define descendentArr50000 int arrD50K[50000]

//Fill
void fillArrayAscendent(int a[], int n){
    for(int i=0 ; i<n ; i++)
        a[i]=i+1;
}
void fillArrayDescendent(int a[], int n){
    int counter = n;
    for(int i=0; i<n; i++){
        a[i]=counter;
        counter--;
    }
}
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << to_string(a[i]) << ", ";
    cout << endl;
}

int main(){

    ascendentArr1000;
    ascendentArr10000;
    ascendentArr100000;

    descendentArr1000;
    descendentArr10000;
    descendentArr50000;

    fillArrayAscendent(arrA1K,1000);
    fillArrayAscendent(arrA10K,10000);
    fillArrayAscendent(arrA100K,100000);

    fillArrayDescendent(arrD1K,1000);
    fillArrayDescendent(arrD10K,10000);
    fillArrayDescendent(arrD50K,50000);

    cout << "Llena los arreglos." << endl;

    auto start = std::chrono::high_resolution_clock::now();

    //Quicksort logarítmico
        //pivote random
    //quickSort(arrD1K,0,1000-1,3);//297171, 305964, 338996, 287008
    //quickSort(arrD10K,0,10000-1,3); //3032570, 3380094, 3010376, 3871718
    //quickSort(arrD50K,0,50000-1,3); //15888730, 15484628, 18082261, 19687641

    //Quicksort cuadrático
        //pivote fijo alto
    //quickSort(arrD1K,0,1000-1,1); //4140974, 4721882, 5120247, 3243315
    //quickSort(arrD10K,0,10000-1,1); //450746692, 378953600, 400745171, 324446466
    //quickSort(arrD50K,0,50000-1,1); //8437645160

    //Insertion Sort Lineal
        //Todos los elementos ya están ordenados
    // insertionSort(arrA1K,1000); //10926, 10739, 9896, 13467, 7506
    // insertionSort(arrA10K,10000); //59760, 70823, 68120, 69934, 71260
    // insertionSort(arrA100K,100000); //662836, 558040, 764155

    //Insertion Sort Cuadrático
        //Todos los elementos están en orden descendente
    //insertionSort(arrD1K, 1000); //2720374, 1641043, 1967609, 1680672
    //insertionSort(arrD10K, 10000);//153888495, 163618815
    //insertionSort(arrD50K, 50000);//3984653696


    //Freetext search
        //Z algorithm (Linear time pattern searching Algorithm)
    //sendSearch("t"); //1627793411
    //sendSearch("s"); //2168293870
    //sendSearch("amor");//961363020
    //sendSearch("cielo");//906628479
    //sendSearch("obstáculo");//946759242
    //sendSearch("educación");//949881274
    //sendSearch("desilusionarían");//972980324

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::nanoseconds>(stop - start);
    cout << "Tiempo de ejecución: " << duration.count() << " nanoseconds" << endl;
}