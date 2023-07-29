#include "Header.h"
//=====SELECTION-SORT=====

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;
	// One by one move boundary of unsorted subarray
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
int selectionSortWithComparisonCount(int* arr, int n) {
	int comparisons = 0;

	for (int i = 0; ++comparisons && i < n - 1; i++) {
		int min_index = i;

		// Find the minimum element in the unsorted part of the array
		for (int j = i + 1; ++comparisons && j < n; j++) {
			// Increment comparison count
			if (++comparisons && arr[j] < arr[min_index])
				min_index = j;
		}

		// Swap the found minimum element with the first element
		swap(arr[i], arr[min_index]);
	}

	return comparisons;
}
void time_of_selectionSort(int arr[], int n, double& time) {
	clock_t start, end;
	start = clock();
	// Call the flashSort function
	selectionSort(arr, n);

	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
}

//=====INSERTION-SORT=====

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
int insertionSortWithComparisonCount(int* arr, int n) {
	int comparisons = 0;

	for (int i = 1; ++comparisons && i < n; i++) {
		int key = arr[i];
		int j = i - 1;

		// Move elements of arr[0..i-1] that are greater than key one position ahead of their current position
		while (++comparisons && j >= 0 && arr[j] > key) {
			// Increment comparison count
			arr[j + 1] = arr[j];
			j = j - 1;
		}

		// Place the key element at its correct position in the sorted sequence
		arr[j + 1] = key;
	}

	return comparisons;
}
void time_of_insertionSort(int arr[], int n, double& time) {
	clock_t start, end;
	start = clock();
	// Call the flashSort function
	insertionSort(arr, n);

	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
}

//=====BUBBLE-SORT=====

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
int bubbleSortWithComparisonCount(int* arr, int n) {
	int comparisons = 0;
	bool swapped;

	for (int i = 0; ++comparisons && i < n - 1; i++) {
		swapped = false;
		for (int j = 0; ++comparisons && j < n - i - 1; j++) {
			// Increment comparison count
			if (++comparisons && arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}

		// If no two elements were swapped in the inner loop, the array is already sorted
		if (++comparisons && !swapped)
			break;
	}

	return comparisons;
}
void time_of_bubbleSort(int arr[], int n, double& time) {
	clock_t start, end;
	start = clock();
	// Call the flashSort function
	bubbleSort(arr, n);

	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
}

//=====SHAKER-SORT=====

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
int shakerSortWithComparisonCount(int arr[], int size) {
	int comparisons = 0;
	int left = 0;
	int right = size - 1;
	bool swapped;

	while (++comparisons && left < right) {
		swapped = false;

		// Move the largest element to the right
		for (int i = left; ++comparisons && i < right; i++) {
			// Increment comparison count
			if (++comparisons && arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}

		// If no swap occurred, the array is already sorted
		if (++comparisons && !swapped)
			break;

		right--;

		// Move the smallest element to the left
		for (int i = right; ++comparisons && i > left; i--) {
			// Increment comparison count
			if (++comparisons && arr[i] < arr[i - 1]) {
				swap(arr[i], arr[i - 1]);
				swapped = true;
			}
		}

		// If no swap occurred, the array is already sorted
		if (++comparisons && !swapped)
			break;

		left++;
	}

	return comparisons;
}
void time_of_shakerSort(int arr[], int n, double& time) {
	clock_t start, end;
	start = clock();
	// Call the flashSort function
	shakerSort(arr, n);

	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
}

//=====SHELL-SORT=====

void shellSort(int arr[], int n)
{
	// Start with a big gap, then reduce the gap
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		// Do a gapped insertion sort for this gap size.
		// The first gap elements a[0..gap-1] are already in gapped order
		// keep adding one more element until the entire array is
		// gap sorted 
		for (int i = gap; i < n; i += 1)
		{
			// add a[i] to the elements that have been gap sorted
			// save a[i] in temp and make a hole at position i
			int temp = arr[i];

			// shift earlier gap-sorted elements up until the correct 
			// location for a[i] is found
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];

			//  put temp (the original a[i]) in its correct location
			arr[j] = temp;
		}
	}
}
int shellSortWithComparisonCount(int arr[], int size) {
	int comparisons = 0;

	// Start with a large gap and reduce it in each iteration
	for (int gap = size / 2; ++comparisons && gap > 0; gap /= 2) {
		for (int i = gap; ++comparisons && i < size; i++) {
			int temp = arr[i];
			int j;
			for (j = i; ++comparisons && j >= gap && arr[j - gap] > temp; j -= gap) {
				// Increment comparison count
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}

	return comparisons;
}
void time_of_shellSort(int arr[], int n, double& time) {
	clock_t start, end;
	start = clock();
	// Call the flashSort function
	shellSort(arr, n);
	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
}

//=====HEAP-SORT=====

void heapify(int arr[], int N, int i, int& comp)
{
	// Initialize largest as root
	int largest = i;

	// left = 2*i + 1
	int l = 2 * i + 1;

	// right = 2*i + 2
	int r = 2 * i + 2;

	// If left child is larger than root
	if (++comp && l < N && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest
	// so far
	if (++comp && r < N && arr[r] > arr[largest])
		largest = r;

	// If largest is not root

	if (++comp && largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected
		// sub-tree
		heapify(arr, N, largest, comp);
	}
}
void heapSort(int arr[], int N, int& comp)
{
	// Build heap (rearrange array)
	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i, comp);

	// One by one extract an element
	// from heap
	for (int i = N - 1; i > 0; i--) {

		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0, comp);
	}
}
void time_of_heapSort(int arr[], int n, double& time) {
	int dummy;
	clock_t start, end;
	start = clock();
	// Call the flashSort function
	heapSort(arr, n, dummy);
	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
}

//=====MERGE-SORT=====

void merge(int arr[], int left, int mid, int right, int& comparisons) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	// Create temporary arrays
	int* L = new int[n1];
	int* R = new int[n2];

	// Copy data to temporary arrays
	for (int i = 0; ++comparisons && i < n1; i++)
		L[i] = arr[left + i];
	for (int j = 0; ++comparisons && j < n2; j++)
		R[j] = arr[mid + 1 + j];

	// Merge the two temporary arrays back into arr[left..right]
	int i = 0, j = 0, k = left;
	while (++comparisons && i < n1 && j < n2) {
		// Increment comparison count
		if (++comparisons && L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of L[] and R[] (if any)
	while (++comparisons && i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (++comparisons && j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}

	// Free temporary arrays
	delete[] L;
	delete[] R;
}
void mergeSort(int array[], int const begin, int const end, int& comparisons)
{
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid, comparisons);
	mergeSort(array, mid + 1, end, comparisons);
	merge(array, begin, mid, end, comparisons);
}
void time_of_mergeSort(int array[], int const begin, int const m_end, double& time) {
	int dummy;
	clock_t start, end;
	start = clock();
	// Call the mergeSort function
	mergeSort(array, 0, m_end, dummy);
	end = clock(); // Initialize 'end' with current clock value
	time = (double)(end - start) / CLOCKS_PER_SEC;
}

//=====QUICK-SORT=====

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
void comp_of_quickSort(int*& arr, int first, int last, int& comp) {
	int pivot = arr[(first + last) / 2];
	int i = first, j = last;
	do {
		while (++comp && arr[i] < pivot) i++;
		while (++comp && arr[j] > pivot) j--;
		if (++comp && i <= j) {
			swap(arr[i], arr[j]);
			i++; j--;
		}
	} while (++comp && i <= j);
	if (++comp && first < j) quickSort(arr, first, j);
	if (++comp && i < last) quickSort(arr, i, last);
}

//=====COUNTING-SORT=====

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
void comp_of_countingSort(int*& arr, int n, int& comp) {
	int u = arr[0]; // get the maximum value in the array
	for (int i = 1; ++comp && i < n; ++i)
		if (++comp && arr[i] > u)
			u = arr[i];
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
void comp_of_radixSort(int*& arr, int n, int& comp) {
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
void comp_of_flashSort(int*& a, int n, int& comp) {
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


