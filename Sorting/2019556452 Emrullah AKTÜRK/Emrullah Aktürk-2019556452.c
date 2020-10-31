#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>






void merge(int arr[], int l, int m, int r)
{
	int lside = m - l+1;
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

void mergesort(int arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;

		mergesort(arr, l, m);
		mergesort(arr, m + 1, r);

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

void mergesortchar(char arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;

		mergesortchar(arr, l, m);
		mergesortchar(arr, m + 1, r);

		mergeChar(arr, l, m, r);
	}
}
void selectionsort(int array[], int n) {

	int minimum, temp;
	int i, j;
	for (i = 0; i < n; i++) {
		minimum = i;

		for (j = i; j < n; j++) {

			if (array[j] < array[minimum]) {
				minimum = j;

			}

		}
		temp = array[i];
		array[i] = array[minimum];
		array[minimum] = temp;

	}
}
void selectionsortchar(char array[], int n) {

	int minimum, temp;
	int i, j;
	for (i = 0; i < n; i++) {
		minimum = i;

		for (j = i; j < n; j++) {

			if (array[j] < array[minimum]) {
				minimum = j;

			}


		}
		temp = array[i];
		array[i] = array[minimum];
		array[minimum] = temp;

	}

}
void insertionsort(int array[], int n) {
	int i, j;
	int element;

	for (i = 1; i < n; ++i) {
		element = array[i];

		for (j = i - 1; array[j] > element && j >= 0; --j) {
			array[j + 1] = array[j];
		}
		array[j + 1] = element;
	}

}
void insertionsortchar(char array[], int n) {
	int i, j;
	int constant;

	for (i = 1; i < n; ++i) {
		constant = array[i];

		for (j = i - 1; array[j] > constant && j >= 0; --j) {
			array[j + 1] = array[j];
		}
		array[j + 1] = constant;
	}

}
void bubblesort(int array[], int size) {
	int i, j, temp;

	for (i = 0; i < size; i++) {
		for (j = 1; j < size - i; j++) {
			if (array[j - 1] > array[j]) {
				temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;

			}

		}
	}
}
void bubblesortchar(char array[], int size) {
	int i, j, temp;

	for (i = 0; i < size; i++) {
		for (j = 1; j < size - i; j++) {
			if (array[j - 1] > array[j]) {
				temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;

			}

		}
	}
}
void printarrayint(int arr[], int count) {
	int i;
	for (i = 0; i < count; ++i) {

		printf("%d", arr[i]);

	}

}
void printarraychar(char arr[], int count) {
	int i;
	for (i = 0; i < count; ++i) {

		printf("%c", arr[i]);

	}

}

int main() {

	clock_t x;
	x = clock();

	char name[] = "emrullah akturk";
	int number[] = { 2,0,1,9,5,5,6,4,5,2 };
	int numbersize = sizeof(number) / sizeof(number[1]);
	int namesize = strlen(name);
	printf("Selection Sort:\n");
    x = clock() - x;
	selectionsort(number, numbersize);
	printf("\nNumber Selection Sort:");
	printarrayint(number, numbersize);
    printf("\nNumber Selection Sort Time : %f", ((double)x) / CLOCKS_PER_SEC);

	x = clock() - x;
	selectionsortchar(name, namesize);
	printf("\nName Selection Sort:");
	printarraychar(name, namesize);
	printf("\nName Selection Sort Time : %f ", ((double)x) / CLOCKS_PER_SEC);
 
 
	printf("\n\nInsertion Sort:\n");
	x = clock() - x;
	insertionsort(number, numbersize);
	printf("\nNumber Insertion Sort:");
	printarrayint(number, numbersize);
	printf("\nNumber Insertion Sort Time  %f\n", ((double)x) / CLOCKS_PER_SEC);
	

    x = clock() - x;
	insertionsortchar(name, namesize);
	printf("Name Insertion Sort :");
	printarraychar(name, namesize);
	printf("\nName Insertion Sort Time : %f\n", ((double)x) / CLOCKS_PER_SEC);



	printf("\n\nBubble Sort:\n");
    x = clock() - x;
	bubblesort(number, numbersize);
	printf("\nNumber Bubble Sorting:");
	printarrayint(number, numbersize);
	printf("\nNumber Bubble Sorting Time : %f ", ((double)x) / CLOCKS_PER_SEC);
	

	x = clock() - x;
	bubblesortchar(name, namesize);
	printf("\nName Bubble Sorting:");	
	printarraychar(name, namesize);
	printf("\nName Bubble Sorting Time : %f \n ", ((double)x) / CLOCKS_PER_SEC);
	
	
	
	printf("\nMerge Sort:\n ");
	mergesort(number, 0, numbersize - 1);
	x = clock() - x;
	printf("\nNumber Merge Sorting:");	
	printarrayint(number, numbersize);
	printf("\nNumber Merge Sort Time: %f", ((double)x) / CLOCKS_PER_SEC);
	
	
	mergesortchar(name, 0, namesize - 1);
	x = clock() - x;
	printf("\nName Merge Sorting:");	
	printarraychar(name,namesize );
	printf("\nName Merge Sort Time: %f\n", ((double)x) / CLOCKS_PER_SEC);
	
	


	return 0;
}
