#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


//FONKSİYONLAR

void printfunction(int* arr, int size) {
	for (int k = 0; k < size; k++) {
		printf("%d\t", arr[k]);

	}
	printf("\n");
}

// INSERTION SORT FONKSİYONU

void Insertionsort(int num[], int size) {
	int element, j, i;
	for (i = 1; i < size; i++) {
		element = num[i];
		for (j = i - 1; j >= 0 && num[j] > element; j--) {
			num[j + 1] = num[j];
		}
		num[j + 1] = element;
	}
	printfunction(num, size);

}
void InsertionsortChar(char name[], int size) {
	int element, j, i;
	for (i = 1; i < size; i++) {
		element = name[i];
		for (j = i - 1; j >= 0 && name[j] > element; j--) {
			name[j + 1] = name[j];
		}
		name[j + 1] = element;
	}
	printf("%s\n", name);
	int t = clock() - t;
	printf("InsertionChar sort  time: %f\n", ((double)t) / CLOCKS_PER_SEC);
	printf("\n");
}



//SELECTİON SORT FONKSİYONU

void SelectionSort(int* num, int size) {
	int i, j, min, temp;
	for (i = 0; i < size; i++) {
		min = num[i];
		for (j = i + 1; j < size; j++) {
			if (num[j] < num[i]) {
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}

		}
	}
	printfunction(num, size);

}
void SelectionSortChar(char* name, int size) {
	int i, j, min, temp;
	for (i = 0; i < size; i++) {
		min = name[i];
		for (j = i + 1; j < size; j++) {
			if (name[j] < name[i]) {
				temp = name[i];
				name[i] = name[j];
				name[j] = temp;
			}

		}
	}
	printf("%s\n", name);
	int t = clock() - t;
	printf("SelectionChar sort  time: %f\n", ((double)t) / CLOCKS_PER_SEC);
	printf("\n");
}

// BUBBLE SORT

void BubbleSort(int* num, int size) {
	int i, j, temp;
	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i - 1; j++)
			if (num[j] > num[j + 1]) {
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
	printfunction(num, size);
}
void BubbleSortChar(char* name, int size) {
	int i, j, temp;
	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i - 1; j++)
			if (name[j] > name[j + 1]) {
				temp = name[i];
				name[i] = name[j];
				name[j] = temp;
			}
	printf("%s\n", name);
	int t = clock() - t;
	printf("BubbleChar sort  time: %f\n", ((double)t) / CLOCKS_PER_SEC);
	printf("\n");
}
//Merge Sort
void merge(int arr[], int l, int m, int r)
{
	int lside = m - l + 1;
	int rside = r - m;
	int Left[lside];
	int Right[rside];
	int i, j, k;
	for (i = 0; i < lside; i++)
		Left[i] = arr[l + i];
	for (j = 0; j < rside; j++)
		Right[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;

	while (i < lside && j < rside) {
		if (Left[i] <= Right[j]) {
			arr[k] = Left[i];
			i++;
		}
		else {
			arr[k] = Right[j];
			j++;
		}
		k++;
	}

	while (i < lside) {
		arr[k] = Left[i];
		i++;
		k++;
	}

	while (j < rside) {
		arr[k] = Right[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

void mergeChar(char arr[], int l, int m, int r)
{
	int i, j, k, n1, n2;
	n1 = m - l + 1;
	n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSortChar(char arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSortChar(arr, l, m);
		mergeSortChar(arr, m + 1, r);

		mergeChar(arr, l, m, r);
	}
}
int main() {
	clock_t t;

	//NUMARA
	int num[] = { 2,0,1,8,5,5,6,0,3,6 };
	//AD SOYAD
	char name[] = "HAKAN KABAYEL";
	int size = sizeof(num) / sizeof(num[0]);
	int sizechar = strlen(name);

	t = clock();
	Insertionsort(num, size);
	InsertionsortChar(name, sizechar);
	t = clock() - t;
	printf("insertion sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);

	t = clock();
	SelectionSort(num, size);
	SelectionSortChar(name, size);
	t = clock() -t;
	printf("Selection sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);

	t = clock();
	BubbleSort(num, size);
	BubbleSortChar(name, size);
	t = clock() - t;
	printf("Bubble sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);

	//Merge Sort
	t = clock();
	printf("Merge Sort:\n");
	mergeSort(num, 0, size - 1);
	printfunction(num, size);
	t = clock() - t;
	printf("merge sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);
	mergeSortChar(name, 0, sizechar - 1);
	
	t = clock();
	printf("%s\n", name);
	printf("merge char sort time: %f\n", ((double)t) / CLOCKS_PER_SEC);
	t = clock() - t;

	return 0;
}