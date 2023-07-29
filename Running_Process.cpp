#include "Header.h"
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
	// Sorting algorithm
	if (algorithm == "selection-sort")
	{
		start = clock();
		selectionSort(arr, n);
		end = clock();
		comp = selectionSortWithComparisonCount(arr, n);
	}
	else if (algorithm == "insertion-sort")
	{
		start = clock();
		insertionSort(arr, n);
		end = clock();
		comp = insertionSortWithComparisonCount(arr, n);
	}
	else if (algorithm == "bubble-sort")
	{
		start = clock();
		bubbleSort(arr, n);
		end = clock();
		comp = bubbleSortWithComparisonCount(arr, n);
	}
	else if (algorithm == "shaker-sort")
	{
		start = clock();
		shakerSort(arr, n);
		end = clock();
		comp = shakerSortWithComparisonCount(arr, n);
	}
	else if (algorithm == "shell-sort")
	{
		start = clock();
		shellSort(arr, n);
		end = clock();
		comp = shellSortWithComparisonCount(arr, n);
	}

	else if (algorithm == "heap-sort")
	{
		start = clock();
		heapSort(arr, n, comp);
		end = clock();
	}
	else if (algorithm == "merge-sort")
	{
		start = clock();
		mergeSort(arr, 0, n-1, comp);
		end = clock();
	}

	else if (algorithm == "quick-sort")
	{
		start = clock();
		quickSort(arr, 0, n - 1);
		end = clock();
		comp_of_quickSort(arr, 0, n - 1, comp);
	}
	else if (algorithm == "counting-sort")
	{
		start = clock();
		countingSort(arr, n);
		end = clock();
		comp_of_countingSort(arr, n, comp);
	}
	else if (algorithm == "radix-sort")
	{
		start = clock();
		radixSort(arr, n);
		end = clock();
		comp_of_radixSort(arr, n, comp);
	}
	else if (algorithm == "flash-sort")
	{
		start = clock();
		flashSort(arr, n);
		end = clock();
		comp_of_flashSort(arr, n, comp);
	}
	
	double duration = double(end - start) / CLOCKS_PER_SEC;

	// Output to the "output.txt" file
	ofstream outputFile("output.txt");
	if (!outputFile) {
		cerr << "Error: Unable to create output file.\n";
		return;
	}

	outputFile.close();

	cout << "ALGORITHM MODE" << "\n";
	cout << "Algorithm: " << algorithm << "\n";
	cout << "Input file: " << inputFilename << "\n";
	cout << "Input size: " << n << "\n";
	cout << "--------------------------" << "\n";
	// Handle output parameters
	for (int i = 4; i < argc; i++) {
		string outputParam = argv[i];

		if (outputParam == "-time") {
			cout << "Running time (if required): " << duration << " miliseconds \n";
		}
		else if (outputParam == "-comp") {
			cout << "Comparisons (if required): " << comp << "\n";
		}
		else if (outputParam == "-both") {
			cout << "Running time (if required): " << duration << " miliseconds \n";
			cout << "Comparisons (if required): " << comp << "\n";
		}
		else {
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
	}
	else if (order == "-nsorted") {
		GenerateNearlySortedData(arr, size);
	}
	else if (order == "-sorted") {
		GenerateSortedData(arr, size);
	}
	else if (order == "-rev") {
		GenerateReverseData(arr, size);
	}
	else {
		cout << "Error: Invalid input order." << endl;
		return;
	}
	clock_t start, end;
	int comp = 0;
	int n = size;
	// Sorting algorithm
	if (algorithm == "selection-sort")
	{
		start = clock();
		selectionSort(arr, n);
		end = clock();
		comp = selectionSortWithComparisonCount(arr, n);
	}
	else if (algorithm == "insertion-sort")
	{
		start = clock();
		insertionSort(arr, n);
		end = clock();
		comp = insertionSortWithComparisonCount(arr, n);
	}
	else if (algorithm == "bubble-sort")
	{
		start = clock();
		bubbleSort(arr, n);
		end = clock();
		comp = bubbleSortWithComparisonCount(arr, n);
	}
	else if (algorithm == "shaker-sort")
	{
		start = clock();
		shakerSort(arr, n);
		end = clock();
		comp = shakerSortWithComparisonCount(arr, n);
	}
	else if (algorithm == "shell-sort")
	{
		start = clock();
		shellSort(arr, n);
		end = clock();
		comp = shellSortWithComparisonCount(arr, n);
	}

	else if (algorithm == "heap-sort")
	{
		start = clock();
		heapSort(arr, n, comp);
		end = clock();
	}
	else if (algorithm == "merge-sort")
	{
		start = clock();
		mergeSort(arr, 0, n - 1, comp);
		end = clock();
	}

	else if (algorithm == "quick-sort")
	{
		start = clock();
		quickSort(arr, 0, n - 1);
		end = clock();
		comp_of_quickSort(arr, 0, n - 1, comp);
	}
	else if (algorithm == "counting-sort")
	{
		start = clock();
		countingSort(arr, n);
		end = clock();
		comp_of_countingSort(arr, n, comp);
	}
	else if (algorithm == "radix-sort")
	{
		start = clock();
		radixSort(arr, n);
		end = clock();
		comp_of_radixSort(arr, n, comp);
	}
	else if (algorithm == "flash-sort")
	{
		start = clock();
		flashSort(arr, n);
		end = clock();
		comp_of_flashSort(arr, n, comp);
	}

	double duration = double(end - start) / CLOCKS_PER_SEC;

	// Output to the "output.txt" file
	ofstream outputFile("output.txt");
	if (!outputFile) {
		cerr << "Error: Unable to create output file.\n";
		return;
	}

	outputFile.close();

	cout << "ALGORITHM MODE" << "\n";
	cout << "Algorithm: " << algorithm << "\n";
	cout << "Input size: " << n << "\n";
	cout << "Input order: " << order << "\n";
	cout << "--------------------------" << "\n";
	// Handle output parameters
	for (int i = 4; i < argc; i++) {
		string outputParam = argv[i];

		if (outputParam == "-time") {
			cout << "Running time (if required): " << duration << " miliseconds \n";
		}
		else if (outputParam == "-comp") {
			cout << "Comparisons (if required): " << comp << "\n";
		}
		else if (outputParam == "-both") {
			cout << "Running time (if required): " << duration << " miliseconds \n";
			cout << "Comparisons (if required): " << comp << "\n";
		}
		else {
			cout << "Warning: Unrecognized output parameter: " << outputParam << "\n";
		}
	}
}
	// Write sorted array to "output.txt"



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

			if (strcmp(argv[2], "selection-sort") == 0) {
				time_of_selectionSort(randArr, input_size, time_rand);
				time_of_selectionSort(nearArr, input_size, time_near);
				time_of_selectionSort(sortedArr, input_size, time_sorted);
				time_of_selectionSort(revArr, input_size, time_rev);
			}
			else if (strcmp(argv[2], "bubble-sort") == 0) {
				time_of_bubbleSort(randArr, input_size, time_rand);
				time_of_bubbleSort(nearArr, input_size, time_near);
				time_of_bubbleSort(sortedArr, input_size, time_sorted);
				time_of_bubbleSort(revArr, input_size, time_rev);
			}
			else if (strcmp(argv[2], "insertion-sort") == 0) {
				time_of_insertionSort(randArr, input_size, time_rand);
				time_of_insertionSort(nearArr, input_size, time_near);
				time_of_insertionSort(sortedArr, input_size, time_sorted);
				time_of_insertionSort(revArr, input_size, time_rev);
			}
			else if (strcmp(argv[2], "merge-sort") == 0) {
				time_of_mergeSort(randArr, 0, input_size - 1, time_rand);
				time_of_mergeSort(nearArr, 0, input_size - 1, time_near);
				time_of_mergeSort(sortedArr, 0, input_size - 1, time_sorted);
				time_of_mergeSort(revArr, 0, input_size - 1, time_rev);
			}
			else if (strcmp(argv[2], "heap-sort") == 0) {
				time_of_heapSort(randArr, input_size, time_rand);
				time_of_heapSort(nearArr, input_size, time_near);
				time_of_heapSort(sortedArr, input_size, time_sorted);
				time_of_heapSort(revArr, input_size, time_rev);
			}
			else if (strcmp(argv[2], "shaker-sort") == 0) {
				time_of_shakerSort(randArr, input_size, time_rand);
				time_of_shakerSort(nearArr, input_size, time_near);
				time_of_shakerSort(sortedArr, input_size, time_sorted);
				time_of_shakerSort(revArr, input_size, time_rev);
			}
			else if (strcmp(argv[2], "shell-sort") == 0) {
				time_of_shellSort(randArr, input_size, time_rand);
				time_of_shellSort(nearArr, input_size, time_near);
				time_of_shellSort(sortedArr, input_size, time_sorted);
				time_of_shellSort(revArr, input_size, time_rev);
			}
			else if (strcmp(argv[2], "flash-sort") == 0) {
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
			int comp_rand = 0, comp_near = 0, comp_sorted = 0, comp_rev = 0;
			if (strcmp(argv[2], "selection-sort") == 0) {
				comp_rand = selectionSortWithComparisonCount(randArr, input_size);
				comp_near = selectionSortWithComparisonCount(nearArr, input_size);
				comp_sorted = selectionSortWithComparisonCount(sortedArr, input_size);
				comp_rev = selectionSortWithComparisonCount(revArr, input_size);
			}
			else if (strcmp(argv[2], "bubble-sort") == 0) {
				comp_rand = bubbleSortWithComparisonCount(randArr, input_size);
				comp_near = bubbleSortWithComparisonCount(nearArr, input_size);
				comp_sorted = bubbleSortWithComparisonCount(sortedArr, input_size);
				comp_rev = bubbleSortWithComparisonCount(revArr, input_size);
			}
			else if (strcmp(argv[2], "insertion-sort") == 0) {
				comp_rand = insertionSortWithComparisonCount(randArr, input_size);
				comp_near = insertionSortWithComparisonCount(nearArr, input_size);
				comp_sorted = insertionSortWithComparisonCount(sortedArr, input_size);
				comp_rev = insertionSortWithComparisonCount(revArr, input_size);
			}
			else if (strcmp(argv[2], "merge-sort") == 0) { //
				mergeSort(randArr, 0, input_size - 1, comp_rand);
				mergeSort(nearArr, 0, input_size - 1, comp_near);
				mergeSort(sortedArr, 0, input_size - 1, comp_sorted);
				mergeSort(revArr, 0, input_size - 1, comp_rev);
			}
			else if (strcmp(argv[2], "heap-sort") == 0) { //
				heapSort(randArr, input_size, comp_rand);
				heapSort(nearArr, input_size, comp_near);
				heapSort(sortedArr, input_size, comp_sorted);
				heapSort(revArr, input_size, comp_rev);
			}
			else if (strcmp(argv[2], "shaker-sort") == 0) {
				comp_rand = shakerSortWithComparisonCount(randArr, input_size);
				comp_near = shakerSortWithComparisonCount(nearArr, input_size);
				comp_sorted = shakerSortWithComparisonCount(sortedArr, input_size);
				comp_rev = shakerSortWithComparisonCount(revArr, input_size);
			}
			else if (strcmp(argv[2], "shell-sort") == 0) {
				comp_rand = shellSortWithComparisonCount(randArr, input_size);
				comp_near = shellSortWithComparisonCount(nearArr, input_size);
				comp_sorted = shellSortWithComparisonCount(sortedArr, input_size);
				comp_rev = shellSortWithComparisonCount(revArr, input_size);
			}
			else if (strcmp(argv[2], "flash-sort") == 0) {
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
		if (strcmp(argv[2], "selection-sort") == 0) {
			time_of_selectionSort(randArr_t, input_size, time_rand);
			time_of_selectionSort(nearArr_t, input_size, time_near);
			time_of_selectionSort(sortedArr_t, input_size, time_sorted);
			time_of_selectionSort(revArr_t, input_size, time_rev);
		}
		else if (strcmp(argv[2], "bubble-sort") == 0) {
			time_of_bubbleSort(randArr_t, input_size, time_rand);
			time_of_bubbleSort(nearArr_t, input_size, time_near);
			time_of_bubbleSort(sortedArr_t, input_size, time_sorted);
			time_of_bubbleSort(revArr_t, input_size, time_rev);
		}
		else if (strcmp(argv[2], "insertion-sort") == 0) {
			time_of_insertionSort(randArr_t, input_size, time_rand);
			time_of_insertionSort(nearArr_t, input_size, time_near);
			time_of_insertionSort(sortedArr_t, input_size, time_sorted);
			time_of_insertionSort(revArr_t, input_size, time_rev);
		}
		else if (strcmp(argv[2], "merge-sort") == 0) {
			time_of_mergeSort(randArr_t, 0, input_size - 1, time_rand);
			time_of_mergeSort(nearArr_t, 0, input_size - 1, time_near);
			time_of_mergeSort(sortedArr_t, 0, input_size - 1, time_sorted);
			time_of_mergeSort(revArr_t, 0, input_size - 1, time_rev);
		}
		else if (strcmp(argv[2], "heap-sort") == 0) {
			time_of_heapSort(randArr_t, input_size, time_rand);
			time_of_heapSort(nearArr_t, input_size, time_near);
			time_of_heapSort(sortedArr_t, input_size, time_sorted);
			time_of_heapSort(revArr_t, input_size, time_rev);
		}
		else if (strcmp(argv[2], "shaker-sort") == 0) {
			time_of_shakerSort(randArr_t, input_size, time_rand);
			time_of_shakerSort(nearArr_t, input_size, time_near);
			time_of_shakerSort(sortedArr_t, input_size, time_sorted);
			time_of_shakerSort(revArr_t, input_size, time_rev);
		}
		else if (strcmp(argv[2], "shell-sort") == 0) {
			time_of_shellSort(randArr_t, input_size, time_rand);
			time_of_shellSort(nearArr_t, input_size, time_near);
			time_of_shellSort(sortedArr_t, input_size, time_sorted);
			time_of_shellSort(revArr_t, input_size, time_rev);
		}
		else if (strcmp(argv[2], "flash-sort") == 0) {
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
		int comp_rand = 0, comp_near = 0, comp_sorted = 0, comp_rev = 0;
		if (strcmp(argv[2], "selection-sort") == 0) {
			comp_rand = selectionSortWithComparisonCount(randArr_c, input_size);
			comp_near = selectionSortWithComparisonCount(nearArr_c, input_size);
			comp_sorted = selectionSortWithComparisonCount(sortedArr_c, input_size);
			comp_rev = selectionSortWithComparisonCount(revArr_c, input_size);
		}
		else if (strcmp(argv[2], "bubble-sort") == 0) {
			comp_rand = bubbleSortWithComparisonCount(randArr_c, input_size);
			comp_near = bubbleSortWithComparisonCount(nearArr_c, input_size);
			comp_sorted = bubbleSortWithComparisonCount(sortedArr_c, input_size);
			comp_rev = bubbleSortWithComparisonCount(revArr_c, input_size);
		}
		else if (strcmp(argv[2], "insertion-sort") == 0) {
			comp_rand = insertionSortWithComparisonCount(randArr_c, input_size);
			comp_near = insertionSortWithComparisonCount(nearArr_c, input_size);
			comp_sorted = insertionSortWithComparisonCount(sortedArr_c, input_size);
			comp_rev = insertionSortWithComparisonCount(revArr_c, input_size);
		}
		else if (strcmp(argv[2], "merge-sort") == 0) { //
			mergeSort(randArr_c, 0, input_size - 1, comp_rand);
			mergeSort(nearArr_c, 0, input_size - 1, comp_near);
			mergeSort(sortedArr_c, 0, input_size - 1, comp_sorted);
			mergeSort(revArr_c, 0, input_size - 1, comp_rev);
		}
		else if (strcmp(argv[2], "heap-sort") == 0) { //
			heapSort(randArr_c, input_size, comp_rand);
			heapSort(nearArr_c, input_size, comp_near);
			heapSort(sortedArr_c, input_size, comp_sorted);
			heapSort(revArr_c, input_size, comp_rev);
		}
		else if (strcmp(argv[2], "shaker-sort") == 0) {
			comp_rand = shakerSortWithComparisonCount(randArr_c, input_size);
			comp_near = shakerSortWithComparisonCount(nearArr_c, input_size);
			comp_sorted = shakerSortWithComparisonCount(sortedArr_c, input_size);
			comp_rev = shakerSortWithComparisonCount(revArr_c, input_size);
		}
		else if (strcmp(argv[2], "shell-sort") == 0) {
			comp_rand = shellSortWithComparisonCount(randArr_c, input_size);
			comp_near = shellSortWithComparisonCount(nearArr_c, input_size);
			comp_sorted = shellSortWithComparisonCount(sortedArr_c, input_size);
			comp_rev = shellSortWithComparisonCount(revArr_c, input_size);
		}
		else if (strcmp(argv[2], "flash-sort") == 0) {
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
	double time_count_1 = 0.0, time_count_2 = 0.0;
	int comp_count_1 = 0, comp_count_2 = 0;

	// Measure running time and comparisons for algorithm1
	if (algorithm1 == "selection-sort")
	{
		start = clock();
		selectionSort(arr_a1, n);
		end = clock();
		comp_count_1 = selectionSortWithComparisonCount(arr_a1, n);
	}
	else if (algorithm1 == "insertion-sort")
	{
		start = clock();
		insertionSort(arr_a1, n);
		end = clock();
		comp_count_1 = insertionSortWithComparisonCount(arr_a1, n);
	}
	else if (algorithm1 == "bubble-sort")
	{
		start = clock();
		bubbleSort(arr_a1, n);
		end = clock();
		comp_count_1 = bubbleSortWithComparisonCount(arr_a1, n);
	}
	else if (algorithm1 == "shaker-sort")
	{
		start = clock();
		shakerSort(arr_a1, n);
		end = clock();
		comp_count_1 = shakerSortWithComparisonCount(arr_a1, n);
	}
	else if (algorithm1 == "shell-sort")
	{
		start = clock();
		shellSort(arr_a1, n);
		end = clock();
		comp_count_1 = shellSortWithComparisonCount(arr_a1, n);
	}

	else if (algorithm1 == "heap-sort")
	{
		start = clock();
		heapSort(arr_a1, n, comp_count_1);
		end = clock();
	}
	else if (algorithm1 == "merge-sort")
	{
		start = clock();
		mergeSort(arr_a1, 0, n - 1, comp_count_1);
		end = clock();
	}

	else if (algorithm1 == "quick-sort")
	{
		start = clock();
		quickSort(arr_a1, 0, n - 1);
		end = clock();
		comp_of_quickSort(arr_a1, 0, n - 1, comp_count_1);
	}
	else if (algorithm1 == "counting-sort")
	{
		start = clock();
		countingSort(arr_a1, n);
		end = clock();
		comp_of_countingSort(arr_a1, n, comp_count_1);
	}
	else if (algorithm1 == "radix-sort")
	{
		start = clock();
		radixSort(arr_a1, n);
		end = clock();
		comp_of_radixSort(arr_a1, n, comp_count_1);
	}
	else if (algorithm1 == "flash-sort")
	{
		start = clock();
		flashSort(arr_a1, n);
		end = clock();
		comp_of_flashSort(arr_a1, n, comp_count_1);
	}

	if (algorithm2 == "selection-sort")
	{
		start = clock();
		selectionSort(arr_a2, n);
		end = clock();
		comp_count_2 = selectionSortWithComparisonCount(arr_a2, n);
	}
	else if (algorithm2 == "insertion-sort")
	{
		start = clock();
		insertionSort(arr_a2, n);
		end = clock();
		comp_count_2 = insertionSortWithComparisonCount(arr_a2, n);
	}
	else if (algorithm2 == "bubble-sort")
	{
		start = clock();
		bubbleSort(arr_a2, n);
		end = clock();
		comp_count_2 = bubbleSortWithComparisonCount(arr_a2, n);
	}
	else if (algorithm2 == "shaker-sort")
	{
		start = clock();
		shakerSort(arr_a2, n);
		end = clock();
		comp_count_2 = shakerSortWithComparisonCount(arr_a2, n);
	}
	else if (algorithm2 == "shell-sort")
	{
		start = clock();
		shellSort(arr_a2, n);
		end = clock();
		comp_count_2 = shellSortWithComparisonCount(arr_a2, n);
	}

	else if (algorithm2 == "heap-sort")
	{
		start = clock();
		heapSort(arr_a2, n, comp_count_2);
		end = clock();
	}
	else if (algorithm2 == "merge-sort")
	{
		start = clock();
		mergeSort(arr_a2, 0, n - 1, comp_count_2);
		end = clock();
	}

	else if (algorithm2 == "quick-sort")
	{
		start = clock();
		quickSort(arr_a2, 0, n - 1);
		end = clock();
		comp_of_quickSort(arr_a2, 0, n - 1, comp_count_2);
	}
	else if (algorithm2 == "counting-sort")
	{
		start = clock();
		countingSort(arr_a2, n);
		end = clock();
		comp_of_countingSort(arr_a2, n, comp_count_2);
	}
	else if (algorithm2 == "radix-sort")
	{
		start = clock();
		radixSort(arr_a2, n);
		end = clock();
		comp_of_radixSort(arr_a2, n, comp_count_2);
	}
	else if (algorithm2 == "flash-sort")
	{
		start = clock();
		flashSort(arr_a2, n);
		end = clock();
		comp_of_flashSort(arr_a2, n, comp_count_2);
	}

	cout << "COMPARE MODE" << "\n";
	cout << "Algorithm: " << algorithm1 << " | " << algorithm2 << "\n";
	cout << "Input file: " << inputFileName << "\n";
	cout << "Input size: " << n  << "\n";
	cout << "-----------------------------------" << "\n";
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
	int* subArray = new int[input_size];
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
	for (int i = 0; i < input_size; i++)
	{
		subArray[i] = Array[i];
	}
	ofstream ofs("input.txt");
	ofs << input_size << endl;

	for (int i = 0; i < input_size; i++) {
		ofs << Array[i] << " ";
	}

	int* al_1t = new int[input_size], * al_1c = new int[input_size], * al_2t = new int[input_size], * al_2c = new int[input_size];


	int comp1 = 0, comp2 = 0;
	double time1 = 0.0, time2 = 0.0;

	///////////A2
	if (strcmp(argv[2], "selection-sort") == 0) {
		time_of_selectionSort(Array, input_size, time1);
		comp1 = selectionSortWithComparisonCount(Array, input_size);
	}
	else if (strcmp(argv[2], "bubble-sort") == 0) {
		time_of_bubbleSort(Array, input_size, time1);
		comp1 = bubbleSortWithComparisonCount(Array, input_size);
	}
	else if (strcmp(argv[2], "insertion-sort") == 0) {
		time_of_insertionSort(Array, input_size, time1);
		comp1 = insertionSortWithComparisonCount(Array, input_size);
	}
	else if (strcmp(argv[2], "merge-sort") == 0) { //
		time_of_mergeSort(Array, 0, input_size-1, time1);
		mergeSort(Array, 0, input_size - 1, comp1);
	}
	else if (strcmp(argv[2], "heap-sort") == 0) { //
		time_of_heapSort(Array, input_size, time1);
		mergeSort(Array, 0, input_size - 1, comp1);
	}
	else if (strcmp(argv[2], "shaker-sort") == 0) {
		time_of_shakerSort(Array, input_size, time1);
		comp1 = shakerSortWithComparisonCount(Array, input_size);
	}
	else if (strcmp(argv[2], "shell-sort") == 0) {
		time_of_shellSort(Array, input_size, time1);
		comp1 = shellSortWithComparisonCount(Array, input_size);
	}
	else if (strcmp(argv[2], "flash-sort")) {
		time_of_flashSort(subArray, input_size, time1);
		comp_of_flashSort(subArray, input_size, comp1);
	}
	else if (strcmp(argv[2], "radix-sort")) {
		time_of_radixSort(subArray, input_size, time1);
		comp_of_radixSort(subArray, input_size, comp1);
	}
	else if (strcmp(argv[2], "couting-sort")) {
		time_of_countingSort(subArray, input_size, time1);
		comp_of_countingSort(subArray, input_size, comp1);
	}
	else if (strcmp(argv[2], "quick-sort")) {
		time_of_quickSort(subArray, input_size, time1);
		comp_of_quickSort(subArray, 0, input_size - 1, comp1);
	}
	else {
		cout << "Invalid order data name\n";
		return;
	}

	///////A3
	if (strcmp(argv[3], "selection-sort") == 0) {
		time_of_selectionSort(Array, input_size, time2);
		comp2 = selectionSortWithComparisonCount(Array, input_size);
	}
	else if (strcmp(argv[3], "bubble-sort") == 0) {
		time_of_bubbleSort(Array, input_size, time2);
		comp2 = bubbleSortWithComparisonCount(Array, input_size);
	}
	else if (strcmp(argv[3], "insertion-sort") == 0) {
		time_of_insertionSort(Array, input_size, time2);
		comp2 = insertionSortWithComparisonCount(Array, input_size);
	}
	else if (strcmp(argv[3], "merge-sort") == 0) { //
		time_of_mergeSort(Array, 0, input_size - 1, time2);
		mergeSort(Array, 0, input_size - 1, comp2);
	}
	else if (strcmp(argv[3], "heap-sort") == 0) { //
		time_of_heapSort(Array, input_size, time2);
		mergeSort(Array, 0, input_size - 1, comp2);
	}
	else if (strcmp(argv[3], "shaker-sort") == 0) {
		time_of_shakerSort(Array, input_size, time2);
		comp2 = shakerSortWithComparisonCount(Array, input_size);
	}
	else if (strcmp(argv[3], "shell-sort") == 0) {
		time_of_shellSort(Array, input_size, time2);
		comp2 = shellSortWithComparisonCount(Array, input_size);
	}
	else if (strcmp(argv[3], "flash-sort")) {
		time_of_flashSort(subArray, input_size, time2);
		comp_of_flashSort(subArray, input_size, comp2);
	}
	else if (strcmp(argv[3], "radix-sort")) {
		time_of_radixSort(subArray, input_size, time2);
		comp_of_radixSort(subArray, input_size, comp2);
	}
	else if (strcmp(argv[3], "couting-sort")) {
		time_of_countingSort(subArray, input_size, time2);
		comp_of_countingSort(subArray, input_size, comp2);
	}
	else if (strcmp(argv[3], "quick-sort")) {
		time_of_quickSort(subArray, input_size, time2);
		comp_of_quickSort(subArray, 0, input_size - 1, comp2);
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

	delete[] Array, subArray, al_1t, al_1c, al_2t, al_2c;
}

