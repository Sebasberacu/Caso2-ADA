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

void printArray(int a[], int n);

//Quicksort
void simpleSort(int arr[], int size);
int particionar(int arr[], int imin, int imax);
int particionarRandom(int arr[], int imin, int imax);
int particionarAlto(int arr[], int imin, int imax);
int particionarMediana(int arr[], int imin, int imax);
void quickSort(int arr[], int imin, int imax, int pivot);

//Insertion Sort
void insertionSort(int arr[], int n);

//Free text search
string importText();
void getZarr(string str, int Z[]);
vector<int> search(string text, string pattern);
void sendSearch(string pattern);
