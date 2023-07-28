#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <time.h>
#include <chrono>
#include <cstring>

#define MAX_SIZE 500001

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

using namespace std;

struct inputData {
	string mode;
	string algorithm_name;
	int size;
	string output_para;
};

template <class T>
void HoanVi(T& a, T& b)
{
	T x = a;
	a = b;
	b = x;
}

//-------------------------------------------------

// Hàm phát sinh m?ng d? li?u ng?u nhiên
void GenerateRandomData(int*& a, int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}

// Hàm phát sinh m?ng d? li?u có th? t? tang d?n
void GenerateSortedData(int*& a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// Hàm phát sinh m?ng d? li?u có th? t? ngu?c (gi?m d?n)
void GenerateReverseData(int*& a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh m?ng d? li?u g?n nhu có th? t?
void GenerateNearlySortedData(int*& a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		HoanVi(a[r1], a[r2]);
	}
}

void GenerateData(int*& a, int n, int dataType)
{
	switch (dataType)
	{
	case 0:	// ng?u nhiên
		GenerateRandomData(a, n);
		break;
	case 1:	// có th? t?
		GenerateSortedData(a, n);
		break;
	case 2:	// có th? t? ngu?c
		GenerateReverseData(a, n);
		break;
	case 3:	// g?n nhu có th? t?
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}

//=====SELECTION-SORT=====
//=====Time complexity: O(n^2)=====
//=====Comparisons: =====

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	// One by one move boundary of
	// unsorted subarray
	for (i = 0; i < n - 1; i++) {

		// Find the minimum element in
		// unsorted array
		min_idx = i;
		for (j = i + 1; j < n; j++) {
			if (arr[j] < arr[min_idx])
				min_idx = j;
		}

		// Swap the found minimum element
		// with the first element
		if (min_idx != i)
			swap(arr[min_idx], arr[i]);
	}
}

//=====INSERTION-SORT=====
//=====Time complexity: O(n^2)=====
//=====Comparisons: =====

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		// Move elements of arr[0..i-1],
		// that are greater than key,
		// to one position ahead of their
		// current position
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

//=====BUBBLE-SORT=====
//=====Time complexity: =====
//=====Comparisons: =====

void bubbleSort(int arr[], int n)
{
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++) {
		swapped = false;
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}

		// If no two elements were swapped
		// by inner loop, then break
		if (swapped == false)
			break;
	}
}

//=====SHAKER-SORT=====
//=====Time complexity: =====
//=====Comparisons: =====

void shakerSort(int arr[], int n)
{
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	while (Left < Right)
	{
		for (int i = Left; i < Right; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; i > Left; i--)
		{
			if (arr[i] < arr[i - 1])
			{
				swap(arr[i], arr[i - 1]);
				k = i;
			}
		}
		Left = k;
	}
}

//=====SHELL-SORT=====
//=====Time complexity: =====
//=====Comparisons: =====



//=====HEAP-SORT=====
//=====Time complexity: =====
//=====Comparisons: =====

//=====MERGE-SORT=====
//=====Time complexity: =====
//=====Comparisons: =====

//=====QUICK-SORT=====
//=====Time complexity: =====
//=====Comparisons: =====
void quickSort(int*& arr, int first, int last) {
	int pivot = arr[(first + last) / 2];
	int i = first, j = last;
	do {
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++; j--;
		}
	} while (i <= j);
	if (first < j) quickSort(arr, first, j);
	if (i < last) quickSort(arr, i, last);
}
void time_of_quickSort(int*& arr, int n, double& time) {
	clock_t start, end;
	start = clock();
	// Call the flashSort function
	quickSort(arr, 0, n - 1);

	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
}
void comp_of_quickSort(int*& arr, int first, int last, long long& comp) {
	int pivot = arr[(first + last) / 2];
	int i = first, j = last;
	do {
		while (++comp && arr[i] < pivot) i++;
		while (++comp && arr[j] > pivot) j--;
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++; j--;
		}
	} while (++comp && i <= j);
	if (++comp && first < j) quickSort(arr, first, j);
	if (++comp && i < last) quickSort(arr, i, last);
}

//=====COUNTING-SORT=====
//=====Time complexity: =====
//=====Comparisons: =====

void countingSort(int*& arr, int n) { // u is the maximum value
	// perform distribution counting
	int u = arr[0]; // get the maximum value in the array
	for (int i = 1; i < n; ++i)
		if (arr[i] > u) u = arr[i];
	int* f = new int[u + 1] {};
	for (int i = 0; i < n; i++)
		f[arr[i]]++;
	// accumulate the sum of frequencies
	for (int i = 1; i <= u; i++)
		f[i] = f[i] + f[i - 1];
	// distribute valueto their final positions
	int* b = new int[n] {};
	for (int i = n - 1; i >= 0; i--) {
		b[f[arr[i]] - 1] = arr[i];
		f[arr[i]]--;
	}
	for (int i = 0; i < n; i++)
		arr[i] = b[i];

	delete[] f;
	delete[] b;
}
void time_of_countingSort(int*& arr, int n, double& time) {
	clock_t start, end;
	start = clock();
	// Call the flashSort function
	countingSort(arr, n);
	
	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
}
void comp_of_countingSort(int*& arr, int n, long long& comp) {
	int u = arr[0]; // get the maximum value in the array
	for (int i = 1; ++comp && i < n; ++i)
		if (++comp && arr[i] > u) u = arr[i];
	int* f = new int[u + 1] {};
	for (int i = 0; ++comp && i < n; i++)
		f[arr[i]]++;
	// accumulate the sum of frequencies
	for (int i = 1; ++comp && i <= u; i++)
		f[i] = f[i] + f[i - 1];
	// distribute values to their final positions
	int* b = new int[n] {};
	for (int i = n - 1; ++comp && i >= 0; i--) {
		b[f[arr[i]] - 1] = arr[i];
		f[arr[i]]--;
	}
	for (int i = 0; ++comp && i < n; i++)
		arr[i] = b[i];

	delete[] f;
	delete[] b;
}
//=====RADIX-SORT=====
//=====Time complexity: =====
//=====Comparisons: =====
void radixSort(int*& arr, int n) {
	int max_val = arr[0]; // get maximum value in the array
	for (int i = 1; i < n; ++i)
		if (arr[i] > max_val) max_val = arr[i];
	int digits = 0;
	double div = 0.0; // find the maximum number of digits
	do {
		digits++;
		div = max_val / pow(10, digits);
	} while (div > 0);

	int** tempArr = new int* [10]; // declare variables for temp store
	for (int i = 0; i < 10; ++i)
		tempArr[i] = new int[n];

	int tempCount[10]{};
	for (int i = 0; i < digits; ++i) {
		int exp = pow(10, i);
		for (int j = 0; j < 10; ++j) // reset the counting
			tempCount[j] = 0;
		for (int j = 0; j < n; ++j) { // form groups
			int idx = (arr[j] / exp) % 10;
			tempArr[idx][tempCount[idx]++] = arr[j];
		}
		int idx = 0; // combine groups
		for (int j = 0; j < 10; ++j)
			for (int k = 0; k < tempCount[j]; ++k)
				arr[idx++] = tempArr[j][k];

	}
}
void time_of_radixSort(int*& arr, int n, double& time) {
	clock_t start, end;
	start = clock();
	// Call the flashSort function
	radixSort(arr, n);

	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
}
void comp_of_radixSort(int*& arr, int n, long long& comp) {
	int max_val = arr[0]; // get maximum value in the array
	for (int i = 1; i < n; ++i)
		if (arr[i] > max_val) max_val = arr[i];
	int digits = 0;
	double div = 0.0; // find the maximum number of digits
	do {
		digits++;
		div = max_val / pow(10, digits);
	} while (div > 0);

	int** tempArr = new int* [10]; // declare variables for temp store
	for (int i = 0; i < 10; ++i)
		tempArr[i] = new int[n];

	int tempCount[10]{};
	for (int i = 0; ++comp && i < digits; ++i) {
		int exp = pow(10, i);
		for (int j = 0; ++comp && j < 10; ++j) // reset the counting
			tempCount[j] = 0;
		for (int j = 0; ++comp && j < n; ++j) { // form groups
			int idx = (arr[j] / exp) % 10;
			tempArr[idx][tempCount[idx]++] = arr[j];
		}
		int idx = 0; // combine groups
		for (int j = 0; ++comp && j < 10; ++j)
			for (int k = 0; ++comp && k < tempCount[j]; ++k)
				arr[idx++] = tempArr[j][k];

	}
}

//=====FLASH-SORT=====
//=====Time complexity: =====
//=====Comparisons: =====
void flashSort(int*& a, int n) {
	if (n <= 1)
		return;

	int MAXid = 0, MIN = a[0];
	for (int i = 1; i < n; i++) {
		if (a[MAXid] < a[i])
			MAXid = i;
		MIN = min(MIN, a[i]);
	}
	if (a[MAXid] == MIN)
		return;

	int m = 0.43 * n;
	int* bucket = new int[m] {};
	int* temp = new int[n] {};
	double coef = (m - 1.0) / (a[MAXid] - MIN);

	// count the number of elements in each bucket
	for (int i = 0; i < n; i++) {
		int j = coef * (a[i] - MIN);
		bucket[j]++;
	}

	for (int i = 1; i < m; i++)
		bucket[i] += bucket[i - 1];

	// put elements in their rightful buckets
	for (int i = n - 1; i >= 0; i--) {
		int j = coef * (a[i] - MIN);
		temp[--bucket[j]] = a[i];
	}

	// copy the elements back to the original array
	for (int i = 0; i < n; i++)
		a[i] = temp[i];

	// perform insertion sort for each bucket
	for (int i = 0; i < m; i++) {
		int start = (i == 0) ? 0 : bucket[i - 1];
		int end = bucket[i] - 1;
		for (int j = start + 1; j <= end; j++) {
			int key = a[j];
			int k = j - 1;
			while (k >= start && a[k] > key) {
				a[k + 1] = a[k];
				k--;
			}
			a[k + 1] = key;
		}
	}

	delete[] bucket;
	delete[] temp;
}
void time_of_flashSort(int*& a, int n, double& time) {
	clock_t start, end;
	start = clock();

	// Call the flashSort function
	flashSort(a, n);
	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
}
void comp_of_flashSort(int*& a, int n, long long& comp) {
	if (++comp && n <= 1) {
		return;
	}

	int MAXid = 0, MIN = a[0];
	for (int i = 1; ++comp && i < n; i++) {
		if (++comp && a[MAXid] < a[i]) {
			MAXid = i;
		}

		MIN = min(MIN, a[i]);
	}
	if (++comp && a[MAXid] == MIN)
		return;

	int m = 0.43 * n;
	int* bucket = new int[m] {};
	int* temp = new int[n]();
	double coef = (m - 1.0) / (a[MAXid] - MIN);

	// count the number of elements in each bucket
	for (int i = 0; ++comp && i < n; i++) {
		int j = coef * (a[i] - MIN);
		bucket[j]++;
	}
	for (int i = 1; ++comp && i < m; i++) {
		bucket[i] += bucket[i - 1];
	}
	// put elements in their rightful buckets
	for (int i = n - 1; ++comp && i >= 0; i--) {
		int j = coef * (a[i] - MIN);
		temp[--bucket[j]] = a[i];
	}

	// copy the elements back to the original array

	for (int i = 0; ++comp && i < n; i++) {
		a[i] = temp[i];
	}
	// perform insertion sort for each bucket
	for (int i = 0; ++comp && i < m; i++) {
		int start = (i == 0) ? 0 : bucket[i - 1];
		int end = bucket[i] - 1;
		for (int j = start + 1; ++comp && j <= end; j++) {
			int key = a[j];
			int k = j - 1;
			while ((++comp && k >= start) && (++comp && a[k] > key)) {
				a[k + 1] = a[k];
				k--;
			}
			a[k + 1] = key;
		}
	}
	
	delete[] bucket;
	delete[] temp;
}

int max_value(int a[], int n) {
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (max < a[i])
			max = a[i];
	}
	return max;
}




/*void sorting_by_time(char* argv[], int a[], int n, int& time) {
	switch(argv[2]){
		case
	}
}*/

void print_arr(int*& a, int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void readDataFromFile(const string& filename, int arr[], int& n) {
	ifstream ifs(filename);
	ifs >> n;
	for (int i = 0; i < n; i++) {
		ifs >> arr[i];
	}
	ifs.close();
}

int* readData(const string& filename, int& n)
{
	ifstream ifs(filename);
	ifs >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		ifs >> arr[i];
	}
	ifs.close();
	return arr;
}
///////////CMD1--------------------------
void runAlgorithmOnGivenInput(int argc, char* argv[]) {
	// Code th?c hi?n tác v?
	string algorithm = argv[2];
    string inputFilename = argv[3];

    // Read data from the input file
    ifstream inputFile(inputFilename);
    if (!inputFile) {
        cerr << "Error: Unable to open input file: " << inputFilename << endl;
        return;
    }
	
    int n;
    inputFile >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
    	inputFile >> arr[i];
	}
    inputFile.close();

    // Measure execution time and comparisons
    clock_t start, end;
    int comp = 0;
	start = clock();
    // Sorting algorithm
    switch (algorithm)
    {
    	case ("selection-sort"):
    		selectionSort(arr, n);
    		break;
    	case ("insertion-sort"):
    		insertionSort(arr, n);\
    		break;
	}
	// bo sung thuat toan sau
    end = clock();
    double duration = double(end-start) / CLOCKS_PER_SEC;

    // Output to the "output.txt" file
    ofstream outputFile("output.txt");
    if (!outputFile) {
        cerr << "Error: Unable to create output file.\n";
        return;
    }

    outputFile.close();

    // Handle output parameters
    for (int i = 4; i < argc; i++) {
        string outputParam = argv[i];

        if (outputParam == "-time") {
            cout << "Running time (if required): " << duration << " miliseconds \n";
        } else if (outputParam == "-comp") {
            cout << "Comparisons (if required): " << comp << "\n";
        } else if (outputParam == "-both") {
            cout << "Running time (if required): " << duration << " miliseconds \n";
            cout << "Comparisons (if required): " << comp << "\n";
        } else {
            cout << "Warning: Unrecognized output parameter: " << outputParam << "\n";
        }
    }
	
	
}

///////////CMD2--------------------------
void runAlgorithmOnGeneratedData(int argc, char* argv[]) {
	// Code th?c hi?n tác v?
	string algorithm = argv[2];
    int size = stoi(argv[3]);
    string order = argv[4];
	
    int* arr = new int[size];
	
    if (order == "-rand") {
        GenerateRandomData(arr, size);
    } else if (order == "-nsorted") {
        GenerateNearlySortedData(arr, size);
    } else if (order == "-sorted") {
        GenerateSortedData(arr, size);
    } else if (order == "-rev") {
        GenerateReverseData(arr, size);
    } else {
        cout << "Error: Invalid input order." << endl;
        return;
    }

    int comparisons = 0;

    if (algorithm == "selection-sort") {
        clock_t start, end;
        start = clock();
        selectionSort(arr, size);
        end = clock();
        if (argc == 6) {
            string output_param = argv[5];
            if (output_param == "-time") {
                double time_action = double(end - start) / CLOCKS_PER_SEC; 
                cout << "Running Time (if required): " << time_action << " microseconds" << endl;
            } else if (output_param == "-comp") {
                cout << "Comparison (if required): " << comparisons << endl;
            } else if (output_param == "-both") {
               	double time_action = double(end - start) / CLOCKS_PER_SEC;
                cout << "Running Time (if required): " << time_action << " microseconds" << endl;
                cout << "Comparison (if required): " << comparisons << endl;
            }
        }
    } else {
        cout << "Error: Invalid algorithm specified." << endl;
        return;
    }
	
    // Write sorted array to "output.txt"
  	
}


///////////CMD3--------------------------
void runAlgorithmOnAllDataArrangements(int argc, char* argv[]) {

	stringstream ss1(argv[3]);
	int input_size;
	ss1 >> input_size;
	int* rand = new int[input_size], * near = new int[input_size], * rev = new int[input_size], * sorted = new int[input_size];

	GenerateRandomData(rand, input_size);
	GenerateNearlySortedData(near, input_size);
	GenerateSortedData(sorted, input_size);
	GenerateReverseData(rev, input_size);
	ofstream ofs1("input_1.txt");
	ofstream ofs2("input_2.txt");
	ofstream ofs3("input_3.txt");
	ofstream ofs4("input_4.txt");
	ofs1 << input_size << endl;
	ofs2 << input_size << endl;
	ofs3 << input_size << endl;
	ofs4 << input_size << endl;

	for (int i = 0; i < input_size; i++) {
		ofs1 << rand[i] << " ";
	}
	for (int i = 0; i < input_size; i++) {
		ofs2 << near[i] << " ";
	}
	for (int i = 0; i < input_size; i++) {
		ofs3 << sorted[i] << " ";
	}
	for (int i = 0; i < input_size; i++) {
		ofs4 << rev[i] << " ";
	}
	ofs1.close();
	ofs2.close();
	ofs3.close();
	ofs4.close();
	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm: " << argv[2] << endl;
	cout << "Input size: " << input_size << endl << endl;
	if (strcmp(argv[4], "-time") == 0 || strcmp(argv[4], "-comp") == 0) {
		int* randArr = new int[input_size], * nearArr = new int[input_size], * revArr = new int[input_size], * sortedArr = new int[input_size];

		readDataFromFile("input_1.txt", randArr, input_size);
		readDataFromFile("input_2.txt", nearArr, input_size);
		readDataFromFile("input_3.txt", sortedArr, input_size);
		readDataFromFile("input_4.txt", revArr, input_size);

		if (strcmp(argv[4], "-time") == 0) {
			double time_rand = 0.0, time_near = 0.0, time_rev = 0.0, time_sorted = 0.0;
			if (strcmp(argv[2], "flash-sort") == 0) {
				time_of_flashSort(randArr, input_size, time_rand);
				time_of_flashSort(nearArr, input_size, time_near);
				time_of_flashSort(sortedArr, input_size, time_sorted);
				time_of_flashSort(revArr, input_size, time_rev);
			}
			else if (strcmp(argv[2], "quick-sort") == 0) {
				time_of_quickSort(randArr, input_size, time_rand);
				time_of_quickSort(nearArr, input_size, time_near);
				time_of_quickSort(sortedArr, input_size, time_sorted);
				time_of_quickSort(revArr, input_size, time_rev);
			}
			else if (strcmp(argv[2], "radix-sort") == 0) {
				time_of_radixSort(randArr, input_size, time_rand);
				time_of_radixSort(nearArr, input_size, time_near);
				time_of_radixSort(sortedArr, input_size, time_sorted);
				time_of_radixSort(revArr, input_size, time_rev);
			}
			else if (strcmp(argv[2], "counting-sort") == 0) {
				time_of_countingSort(randArr, input_size, time_rand);
				time_of_countingSort(nearArr, input_size, time_near);
				time_of_countingSort(sortedArr, input_size, time_sorted);
				time_of_countingSort(revArr, input_size, time_rev);
			}
			else {
				cout << "Invalid algorithm name\n";
				return;
			}
			cout << "Input order: Randomize" << endl;
			cout << "-------------------------" << endl;
			cout << "Running time: " << time_rand << endl << endl;
			cout << "Input order: Nearly Sorted" << endl;
			cout << "-------------------------" << endl;
			cout << "Running time: " << time_near << endl << endl;
			cout << "Input order: Sorted" << endl;
			cout << "-------------------------" << endl;
			cout << "Running time: " << time_sorted << endl << endl;
			cout << "Input order: Reversed" << endl;
			cout << "-------------------------" << endl;
			cout << "Running time: " << time_rev << endl << endl;
		}
		else if (strcmp(argv[4], "-comp") == 0) {
			long long comp_rand = 0, comp_near = 0, comp_sorted = 0, comp_rev = 0;
			if (strcmp(argv[2], "flash-sort") == 0) {
				comp_of_flashSort(randArr, input_size, comp_rand);
				comp_of_flashSort(nearArr, input_size, comp_near);
				comp_of_flashSort(sortedArr, input_size, comp_sorted);
				comp_of_flashSort(revArr, input_size, comp_rev);
			}
			else if (strcmp(argv[2], "quick-sort") == 0) {
				comp_of_quickSort(randArr, 0, input_size - 1, comp_rand);
				comp_of_quickSort(nearArr, 0, input_size - 1, comp_near);
				comp_of_quickSort(sortedArr, 0, input_size - 1, comp_sorted);
				comp_of_quickSort(revArr, 0, input_size - 1, comp_rev);
			}
			else if (strcmp(argv[2], "radix-sort") == 0) {
				comp_of_radixSort(randArr, input_size, comp_rand);
				comp_of_radixSort(nearArr, input_size, comp_near);
				comp_of_radixSort(sortedArr, input_size, comp_sorted);
				comp_of_radixSort(revArr, input_size, comp_rev);
			}
			else if (strcmp(argv[2], "counting-sort") == 0) {
				comp_of_countingSort(randArr, input_size, comp_rand);
				comp_of_countingSort(nearArr, input_size, comp_near);
				comp_of_countingSort(sortedArr, input_size, comp_sorted);
				comp_of_countingSort(revArr, input_size, comp_rev);
			}
			else {
				cout << "Invalid algorithm name\n";
				return;
			}
			cout << "Input order: Randomize" << endl;
			cout << "-------------------------" << endl;
			cout << "Comparisons: " << comp_rand << endl << endl;
			cout << "Input order: Nearly Sorted" << endl;
			cout << "-------------------------" << endl;
			cout << "Comparisons: " << comp_near << endl << endl;
			cout << "Input order: Sorted" << endl;
			cout << "-------------------------" << endl;
			cout << "Comparisons: " << comp_sorted << endl << endl;
			cout << "Input order: Reversed" << endl;
			cout << "-------------------------" << endl;
			cout << "Comparisons: " << comp_rev << endl << endl;
		}
	}
	else {
		int* randArr_t = new int[MAX_SIZE], * nearArr_t = new int[MAX_SIZE], * revArr_t = new int[MAX_SIZE], * sortedArr_t = new int[MAX_SIZE],
			* randArr_c = new int[MAX_SIZE], * nearArr_c = new int[MAX_SIZE], * sortedArr_c = new int[MAX_SIZE], * revArr_c = new int[MAX_SIZE];

		readDataFromFile("input_1.txt", randArr_t, input_size);
		readDataFromFile("input_2.txt", nearArr_t, input_size);
		readDataFromFile("input_3.txt", sortedArr_t, input_size);
		readDataFromFile("input_4.txt", revArr_t, input_size);

		readDataFromFile("input_1.txt", randArr_c, input_size);
		readDataFromFile("input_2.txt", nearArr_c, input_size);
		readDataFromFile("input_3.txt", sortedArr_c, input_size);
		readDataFromFile("input_4.txt", revArr_c, input_size);

		double time_rand = 0.0, time_near = 0.0, time_rev = 0.0, time_sorted = 0.0;
		if (strcmp(argv[2], "flash-sort") == 0) {
			time_of_flashSort(randArr_t, input_size, time_rand);
			time_of_flashSort(nearArr_t, input_size, time_near);
			time_of_flashSort(sortedArr_t, input_size, time_sorted);
			time_of_flashSort(revArr_t, input_size, time_rev);
		}
		else if (strcmp(argv[2], "quick-sort") == 0) {
			time_of_quickSort(randArr_t, input_size, time_rand);
			time_of_quickSort(nearArr_t, input_size, time_near);
			time_of_quickSort(sortedArr_t, input_size, time_sorted);
			time_of_quickSort(revArr_t, input_size, time_rev);
		}
		else if (strcmp(argv[2], "radix-sort") == 0) {
			time_of_radixSort(randArr_t, input_size, time_rand);
			time_of_radixSort(nearArr_t, input_size, time_near);
			time_of_radixSort(sortedArr_t, input_size, time_sorted);
			time_of_radixSort(revArr_t, input_size, time_rev);
		}
		else if (strcmp(argv[2], "counting-sort") == 0) {
			time_of_countingSort(randArr_t, input_size, time_rand);
			time_of_countingSort(nearArr_t, input_size, time_near);
			time_of_countingSort(sortedArr_t, input_size, time_sorted);
			time_of_countingSort(revArr_t, input_size, time_rev);
		}
		else {
			cout << "Invalid algorithm name\n";
			return;
		}
		long long comp_rand = 0, comp_near = 0, comp_sorted = 0, comp_rev = 0;
		if (strcmp(argv[2], "flash-sort") == 0) {
			comp_of_flashSort(randArr_c, input_size, comp_rand);
			comp_of_flashSort(nearArr_c, input_size, comp_near);
			comp_of_flashSort(sortedArr_c, input_size, comp_sorted);
			comp_of_flashSort(revArr_c, input_size, comp_rev);
		}
		else if (strcmp(argv[2], "quick-sort") == 0) {
			comp_of_quickSort(randArr_c, 0, input_size - 1, comp_rand);
			comp_of_quickSort(nearArr_c, 0, input_size - 1, comp_near);
			comp_of_quickSort(sortedArr_c, 0, input_size - 1, comp_sorted);
			comp_of_quickSort(revArr_c, 0, input_size - 1, comp_rev);
		}
		else if (strcmp(argv[2], "radix-sort") == 0) {
			comp_of_radixSort(randArr_c, input_size, comp_rand);
			comp_of_radixSort(nearArr_c, input_size, comp_near);
			comp_of_radixSort(sortedArr_c, input_size, comp_sorted);
			comp_of_radixSort(revArr_c, input_size, comp_rev);
		}
		else if (strcmp(argv[2], "counting-sort") == 0) {
			comp_of_countingSort(randArr_c, input_size, comp_rand);
			comp_of_countingSort(nearArr_c, input_size, comp_near);
			comp_of_countingSort(sortedArr_c, input_size, comp_sorted);
			comp_of_countingSort(revArr_c, input_size, comp_rev);
		}
		else {
			cout << "Invalid algorithm name\n";
			return;
		}
		cout << "Input order: Randomize" << endl;
		cout << "-------------------------" << endl;
		cout << "Running time: " << time_rand << endl;
		cout << "Comparisons: " << comp_rand << endl << endl;
		cout << "Input order: Nearly Sorted" << endl;
		cout << "-------------------------" << endl;
		cout << "Running time: " << time_near << endl;
		cout << "Comparisons: " << comp_near << endl << endl;
		cout << "Input order: Sorted" << endl;
		cout << "-------------------------" << endl;
		cout << "Running time: " << time_sorted << endl;
		cout << "Comparisons: " << comp_sorted << endl << endl;
		cout << "Input order: Reversed" << endl;
		cout << "-------------------------" << endl;
		cout << "Running time: " << time_rev << endl;
		cout << "Comparisons: " << comp_rev << endl << endl;
	}

	cout << "input_1.txt: Random order data";
	cout << endl;
	cout << "input_2.txt: Nearly sorted data";
	cout << endl;
	cout << "input_3.txt: Sorted data";
	cout << endl;
	cout << "input_4.txt: Reverse data";

	delete[] rand, near, sorted, rev;


}

///////////CMD4--------------------------
void runTwoAlgorithmsOnGivenInput(int argc, char* argv[]) 
{
	string algorithm1 = argv[2];
    string algorithm2 = argv[3];
    string inputFileName = argv[4];
    
    ifstream inputFile(inputFileName);
    if (!inputFile) {
        cout << "Error: Could not open input file." << endl;
        return;
    }
    int n;
	inputFile >> n;
	int* arr_a1 = new int[n];
    int* arr_a2 = new int[n];
	for (int i = 0; i < n; i++)
	{
		inputFile >> arr_a1[i];
	}
	for (int i = 0; i < n; i++)
	{
		arr_a2[i] = arr_a1[i];
	}
	clock_t start, end;
	double time_count_1, time_count_2;
	int comp_count_1 = 0, comp_count_2 = 0;
	
    // Measure running time and comparisons for algorithm1
	// do cai cho nay bi loi nhma t chua fix duoc nen
	// t dang chia case tren file khac, tutu t add cai nay vao :(
	
    // Output results
    cout << "Algorithm: " << algorithm1 << " | " << algorithm2 << endl;
    cout << "Input File: " << inputFileName << endl;
    cout << "Running Time: " << time_count_1 << " microseconds | " << time_count_2 << " microseconds" << endl;
    cout << "Comparisons: " << comp_count_1 << " | " << comp_count_2 << endl;

}

///////////CMD5--------------------------
void runTwoAlgorithmsOnGeneratedData(int argc, char* argv[]) {
	int input_size;
	stringstream ss1(argv[4]);
	ss1 >> input_size;
	
	int* Array = new int[input_size];
	if (strcmp(argv[5], "-rand") == 0)
		GenerateRandomData(Array, input_size);
	else if (strcmp(argv[5], "-nsorted") == 0)
		GenerateNearlySortedData(Array, input_size);
	else if (strcmp(argv[5], "-sorted") == 0)
		GenerateSortedData(Array, input_size);
	else if (strcmp(argv[5], "-rev") == 0)
		GenerateReverseData(Array, input_size);
	else {
		cout << "Invalid order data name\n";
		return;
	}

	ofstream ofs("input.txt");
	ofs << input_size << endl;
	
	for (int i = 0; i < input_size; i++) {
		ofs << Array[i] << " ";
	}

	int* al_1t = new int[input_size], * al_1c = new int[input_size], *al_2t = new int[input_size], *al_2c = new int[input_size];


	long long comp1 = 0, comp2 = 0;
	double time1 = 0.0, time2 = 0.0;

	///////////A2
	if (strcmp(argv[2], "flash-sort")) {
		time_of_flashSort(Array, input_size, time1);
		comp_of_flashSort(Array, input_size, comp1);
	}
	else if (strcmp(argv[2], "radix-sort")) {
		time_of_radixSort(Array, input_size, time1);
		comp_of_radixSort(Array, input_size, comp1);
	}
	else if (strcmp(argv[2], "couting-sort")) {
		time_of_countingSort(Array, input_size, time1);
		comp_of_countingSort(Array, input_size, comp1);
	}
	else if (strcmp(argv[2], "quick-sort")) {
		time_of_quickSort(Array, input_size , time1);
		comp_of_quickSort(Array,0, input_size -1, comp1);
	}
	else {
		cout << "Invalid order data name\n";
		return;
	}

	///////A3
	if (strcmp(argv[3], "flash-sort")) {
		time_of_flashSort(Array, input_size, time2);
		comp_of_flashSort(Array, input_size, comp2);
	}
	else if (strcmp(argv[3], "radix-sort")) {
		time_of_radixSort(Array, input_size, time2);
		comp_of_radixSort(Array, input_size, comp2);
	}
	else if (strcmp(argv[3], "couting-sort")) {
		time_of_countingSort(Array, input_size, time2);
		comp_of_countingSort(Array, input_size, comp2);
	}
	else if (strcmp(argv[3], "quick-sort")) {
		time_of_quickSort(Array, input_size, time2);
		comp_of_quickSort(Array, 0, input_size - 1, comp2);
	}
	else {
		cout << "Invalid order data name\n";
		return;
	}

	cout << "COMPARE MODE" << endl;
	cout << "Algorithm: " << argv[2] << " | " << argv[3] << endl;
	cout << "Input size: " << argv[4] << endl;
	cout << "Input order: " << argv[5] << endl;
	cout << "----------------------------" << endl;
	cout << "Running time: " << time1 << " | " << time2 << endl;
	cout << "Comparisons: " << comp1 << " | " << comp2;

	delete[] Array, al_1t, al_1c, al_2t, al_2c;
}


int main(int argc, char* argv[]) {
	if (argc < 2) {
		cout << "Missing command";
		return 1;
	}
	
	string command = argv[1];
	if (command == "-a" && argc == 5 && !isdigit(*argv[3])) {
		runAlgorithmOnGivenInput(argc, argv);

	}
	else if (command == "-a" && argc == 6) {
		runAlgorithmOnGeneratedData(argc, argv);

	}
	else if (command == "-a" && argc == 5 && isdigit(*argv[3])) {
		runAlgorithmOnAllDataArrangements(argc, argv);

	}
	else if (command == "-c" && argc == 5) {
		runTwoAlgorithmsOnGivenInput(argc, argv);
	}
	else if (command == "-c" && argc == 6) {
		runTwoAlgorithmsOnGeneratedData(argc, argv);

	}
	else {
		cout << "Invalid command";
		return 1;
	}

	return 0;
}

