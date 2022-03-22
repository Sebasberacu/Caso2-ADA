#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

void printArray(int a[], int n);

//Quicksort
void simpleSort(int arr[], int size);
int particionar(int arr[], int imin, int imax);
int particionarRandom(int arr[], int imin, int imax);
int particionarAlto(int arr[], int imin, int imax);
int particionarMediana(int arr[], int imin, int imax);
void quickSort(int arr[], int imin, int imax, int pivot);

//Insertion Sort



//Free text search
string importText();
void preprocess_strong_suffix(int *shift, int *bpos, string pat, int m);
void preprocess_case2(int *shift, int *bpos, string pat, int m);
vector <int> search(string text, string pat);
void sendSearch(string pattern);

