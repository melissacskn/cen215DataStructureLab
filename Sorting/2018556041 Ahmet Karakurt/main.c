#include <time.h>
#include <stdio.h>
#include <string.h>

//swap things
void swapChar(char* a, char* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

//insertion sort part
void insertionSort(int arr[], int n){
	
	int i, j;
	int temp;
	for(i=0;i < n; i++){
		j= i-1;
		temp = arr[i];
		while(j >= 0 && arr[j] > temp){
			arr[j+1] = arr[j];
			j = j -1;
		}
		arr[j+1] = temp;	
	}
	
}
void insertionSortChar(char arr[], int size){
	int i, j;
	char temp;
	for(i=1;i<size;i++){
		j = i-1;
		temp = arr[i];
		while(j>=0&&arr[j]>temp){
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = temp;
	}
}

//merge sort parts
void merge(int d[], int left, int k, int right) {
	int i, j, l = 0;
	int m[10];
	for (i = left, j = k + 1; (i <= k) && (j <= right);) {
		if (d[i] < d[j]) {
			m[l] = d[i];
			i++;
			l++;
		}
		else {
			m[l] = d[j];
			j++;
			l++;
		}
	}
	while (i <= k) {
		m[l] = d[i];
		i++;
		l++;
	}
	while (j <= right) {
		m[l] = d[j];
		j++;
		l++;
	}
	for (i = left, l = 0; i <= right; i++, l++) {
		d[i] = m[l];
	}
}

void mergeSort(int arr[], int left, int right){
	int m;
	if (left < right) {
		m = (left+right)/2;
		mergeSort(arr, left, m);
		mergeSort(arr, m+1, right);
		merge(arr, left, m, right);
		
	}
}



//merge sort for characters
void mergechar(char d[], int left, int k, int right) {
	int i, j, l = 0;
	int m[16];
	for (i = left, j = k + 1; (i <= k) && (j <= right);) {
		if (d[i] < d[j]) {
			m[l] = d[i];
			i++;
			l++;
		}
		else {
			m[l] = d[j];
			j++;
			l++;
		}
	}
	while (i <= k) {
		m[l] = d[i];
		i++;
		l++;
	}
	while (j <= right) {
		m[l] = d[j];
		j++;
		l++;
	}
	for (i = left, l = 0; i <= right; i++, l++) {
		d[i] = m[l];
	}
}


void mergesortchar(char d[], int left, int right) {
	int k;
	if (left < right) {
		k = (left + right) / 2;
		mergesortchar(d, left, k);
		mergesortchar(d, k + 1, right);
		mergechar(d, left, k, right);
	}
}

//bubble sort parts

void bubbleSort(int arr[], int size) {
	int i, j;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}

		}
	}
}

//bubble sort for characters
void bubbleSortChar(char arr[], int size) {
	int i, j;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swapChar(&arr[j], &arr[j + 1]);
			}

		}
	}
}
//selection sort part 
void selectionSort(int arr[], int n) 
{ 
    int i, j, min;  
    for (i = 0; i < n-1; i++) 
    { 
        min = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min]) 
            min = j; 
        swap(&arr[min], &arr[i]); 
    } 
} 
//selection sort for characters
void selectionSortChar(char arr[], int n) 
{ 
    int i, j;
    char min;  
    for (i = 0; i < n-1; i++) 
    { 
        min = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min]) 
            min = j; 
        swapChar(&arr[min], &arr[i]); 
    } 
} 

void printArray(int arr[], int n){
	 int i; 
    for (i = 0; i < n; i++){
		printf("%d ", arr[i]); 
	}
    printf("\n");
}

int main() {
    clock_t t;
	//okul numarasý
    int scno[] = {2,0,1,8,5,5,6,0,4,1}; 
    //Ad soyad
    char name[] = "ahmet karakurt"; 
	int n = sizeof(scno) / sizeof(scno[0]); 
	int charSize = strlen(name);
	
	//insertion sort
    t = clock();
    insertionSort(scno, n);
    t = clock() - t;
    printArray(scno, n); 
    printf("insertion sort time: %f\n\n\n", ((double)t) / CLOCKS_PER_SEC);
    
    insertionSortChar(name, charSize);
    
    t = clock() - t;
    printf("%s\n", name);
    
    printf("insertion char sort time: %f\n\n\n", ((double)t) / CLOCKS_PER_SEC);

    //Selection Sort

    selectionSort(scno, n);
    t = clock() - t;
    printArray(scno, n); 
    printf("selection sort time: %f\n\n\n", ((double)t) / CLOCKS_PER_SEC);

    selectionSortChar(name, charSize);
    t = clock() - t;
    printf("%s\n", name);
    printf("selection char sort time: %f\n\n\n", ((double)t) / CLOCKS_PER_SEC);


    //Bubble Sort

    bubbleSort(scno, n);
    t = clock() - t;
    printArray(scno, n); 
    printf("bubble sort time: %f\n\n\n", ((double)t) / CLOCKS_PER_SEC);

    bubbleSortChar(name, charSize);
    t = clock() - t;
    printf("%s\n", name);
    printf("bubble char sort time: %f\n\n\n", ((double)t) / CLOCKS_PER_SEC);


    //Merge Sort

    mergeSort(scno, 0, n - 1);
    t = clock() - t;
    printArray(scno, n); 
    printf("merge sort time: %f\n\n\n", ((double)t) / CLOCKS_PER_SEC);
    mergesortchar(name, 0, charSize - 1);
    t = clock() - t;
    printf("%s\n", name);
    printf("merge char sort time: %f\n\n\n", ((double)t) / CLOCKS_PER_SEC);
    
    printf("Ahmet Karakurt 2018556041");

    return 0;
}










