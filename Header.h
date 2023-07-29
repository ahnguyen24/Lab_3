#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <time.h>
#include <cstring>

#define MAX_SIZE 500001
/*
#define selection-sort 1
#define insertion-sort 2
#define bubble-sort 3
#define shaker-sort 4
#define shell-sort 5
#define heap-sort 6
#define merge-sort 7
#define quick-sort 8
#define counting-sort 9
#define radix-sort 10
#define flash-sort 11
*/

using namespace std;

struct inputData {
	string mode;
	string algorithm_name;
	int size;
	string output_para;
};

template <class T>
void HoanVi(T& a, T& b);
//=====SELECTION-SORT=====

void selectionSort(int arr[], int n);
int selectionSortWithComparisonCount(int* arr, int n);
void time_of_selectionSort(int arr[], int n, double& time);
//=====INSERTION-SORT=====

void insertionSort(int arr[], int n);
int insertionSortWithComparisonCount(int* arr, int n);
void time_of_insertionSort(int arr[], int n, double& time);
//=====BUBBLE-SORT=====

void bubbleSort(int arr[], int n);
int bubbleSortWithComparisonCount(int* arr, int n);
void time_of_bubbleSort(int arr[], int n, double& time);

//=====SHAKER-SORT=====

void shakerSort(int arr[], int n);
int shakerSortWithComparisonCount(int arr[], int size);
void time_of_shakerSort(int arr[], int n, double& time);

//=====SHELL-SORT=====

void shellSort(int arr[], int n);
int shellSortWithComparisonCount(int arr[], int size);
void time_of_shellSort(int arr[], int n, double& time);

//=====HEAP-SORT=====

void heapify(int arr[], int N, int i, int& comp);
void heapSort(int arr[], int N, int& comp);
void time_of_heapSort(int arr[], int n, double& time);

//=====MERGE-SORT=====

void merge(int arr[], int left, int mid, int right, int& comparisons);
void mergeSort(int array[], int const begin, int const end, int& comparisons);
void time_of_mergeSort(int array[], int const begin, int const m_end, double& time);

//=====QUICK-SORT=====

void quickSort(int*& arr, int first, int last);
void time_of_quickSort(int*& arr, int n, double& time);
void comp_of_quickSort(int*& arr, int first, int last, int& comp);

//=====COUNTING-SORT=====

void countingSort(int*& arr, int n);
void time_of_countingSort(int*& arr, int n, double& time);
void comp_of_countingSort(int*& arr, int n, int& comp);

//=====RADIX-SORT=====

void radixSort(int*& arr, int n);
void time_of_radixSort(int*& arr, int n, double& time);
void comp_of_radixSort(int*& arr, int n, int& comp);

//=====FLASH-SORT=====

void flashSort(int*& a, int n);
void time_of_flashSort(int*& a, int n, double& time);
void comp_of_flashSort(int*& a, int n, int& comp);
//-------------------------------------------------

// Hàm phát sinh m?ng d? li?u ng?u nhiên
void GenerateRandomData(int*& a, int n);

// Hàm phát sinh m?ng d? li?u có th? t? tang d?n
void GenerateSortedData(int*& a, int n);

// Hàm phát sinh m?ng d? li?u có th? t? ngu?c (gi?m d?n)
void GenerateReverseData(int*& a, int n);

// Hàm phát sinh m?ng d? li?u g?n nhu có th? t?
void GenerateNearlySortedData(int*& a, int n);

void GenerateData(int*& a, int n, int dataType);

int max_value(int a[], int n);

/*void sorting_by_time(char* argv[], int a[], int n, int& time) {
	switch(argv[2]){
		case
	}
}*/

void print_arr(int*& a, int n);
void readDataFromFile(const string& filename, int arr[], int& n);

int* readData(const string& filename, int& n);
///////////CMD1--------------------------
void runAlgorithmOnGivenInput(int argc, char* argv[]);
///////////CMD2--------------------------
void runAlgorithmOnGeneratedData(int argc, char* argv[]);


///////////CMD3--------------------------
void runAlgorithmOnAllDataArrangements(int argc, char* argv[]);

///////////CMD4--------------------------
void runTwoAlgorithmsOnGivenInput(int argc, char* argv[]);

///////////CMD5--------------------------
void runTwoAlgorithmsOnGeneratedData(int argc, char* argv[]);