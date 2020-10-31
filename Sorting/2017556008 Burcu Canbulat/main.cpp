#include <stdio.h>
#include <string.h>
#include <time.h>

//NUMBER 2017556008 NAME SURNAME:BURCU CANBULAT

void printArray(int array[], int n)
{
    int i;
    for (i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
     printf("\n");
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_char(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}


void insertion_sort(int array[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}
void insertion_sort_char(char array[], int n)
{
    int i, j;
    char key;
    for(i = 1; i < n; i++) {
        key = array[i];
        j = i - 1;
        while(j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}


void selection_sort(int arr[], int n)
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

void selection_sort_char(char array[], int n)
{
    int i, j;
    char min;
    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i+1; j < n; j++)
          if (array[j] < array[min])
            min = j;
        swap_char(&array[min], &array[i]);
    }
}

void bubble_sort(int array[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
           if (array[j] > array[j+1])
              swap(&array[j], &array[j+1]);
}

void bubble_sort_char(char array[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
           if (array[j] > array[j+1])
               swap_char(&array[j], &array[j+1]);
}

void merge(int array[], int l, int m, int r)
{
    int i, j, k, r1, r2;
    r1 = m - l + 1;
    r2 = r - m;

    int X[r1], Y[r2];

    for (i = 0; i < r1; i++)
        Y[i] = array[l + i];
    for (j = 0; j < r2; j++)
        X[j] = array[m + 1 + j];
 
    i = 0;
    j = 0;
    k = l;

    while (i < r1 && j < r2) {
        if (Y[i] <= X[j]) {
            array[k] = Y[i];
            i++;
        }
        else {
            array[k] = X[j];
            j++;
        }
        k++;
    }
 
    while (i < r1) {
        array[k] = Y[i];
        i++;
        k++;
    }
 
    while (j < r2) {
        array[k] = X[j];
        j++;
        k++;
    }
}

void merge_sort(int array[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
 
        merge_sort(array, l, m);
        merge_sort(array, m + 1, r);
 
        merge(array, l, m, r);
    }
}
 
void merge_char(char arr[], int x, int y, int z)
{
    int i, j, k, n1, n2;
    n1 = y - x + 1;
    n2 = z - y;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[x + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[y + 1 + j];
 
    i = 0;
    j = 0;
    k = x;

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

void merge_sort_char(char arr[], int z, int y)
{
    if (z < y) {
        int m = z + (y - z) / 2;
 
        merge_sort_char(arr, z, m);
        merge_sort_char(arr, m + 1, y);
 
        merge_char(arr, z, m, y);
    }
}

int main() {
 
    printf("NAME AND SURNAME = BURCU CANBULAT NUMBER =  2017556008\n\n");
    clock_t time_t;


    int ogrenci_no[] = { 2, 0, 1, 7, 5, 5, 6, 0, 0, 8 };
    char name[] = "burcu canbulat";
    int n = sizeof(ogrenci_no) / sizeof(ogrenci_no[0]);
    int char_size = strlen(name);
    

   
    time_t = clock();
    insertion_sort(ogrenci_no, n);
    time_t = clock() - time_t;
    printf("INSERTION SORT\n");
    printArray(ogrenci_no, n);
    printf("The total time for insertion sort id: %f\n", ((double)time_t) / CLOCKS_PER_SEC);
    insertion_sort_char(name, char_size);
    time_t = clock() - time_t;
    printf("%s\n",name);
    printf("The total time for insertion sort name: %f\n\n", ((double)time_t) / CLOCKS_PER_SEC);

   
    printf("SELECTION SORT\n");
    selection_sort(ogrenci_no, n);
    time_t = clock() - time_t;
    printArray(ogrenci_no, n);
    printf("The total time for selection sort id: %f\n", ((double)time_t) / CLOCKS_PER_SEC);
    
    selection_sort_char(name, char_size);
    time_t = clock() - time_t;
    printf("%s\n",name);
    printf(" The total time for selection sort name: %f\n\n", ((double)time_t) / CLOCKS_PER_SEC);


    printf("BUBBLE SORT\n");
    bubble_sort(ogrenci_no, n);
    time_t = clock() - time_t;
    printArray(ogrenci_no, n);
    printf("The total time for bubble sort id: %f\n", ((double)time_t) / CLOCKS_PER_SEC);

    bubble_sort_char(name, char_size);
    time_t = clock() - time_t;
    printf("%s\n",name);
    printf("The total time for bubble sort name: %f\n\n", ((double)time_t) / CLOCKS_PER_SEC);


    printf("MERGE SORT\n");
    merge_sort(ogrenci_no, 0, n - 1);
    time_t= clock() - time_t;
    printArray(ogrenci_no, n);
    printf("The total time for merge sort id: %f\n", ((double)time_t) / CLOCKS_PER_SEC);
    merge_sort_char(name, 0, char_size - 1);
    time_t = clock() - time_t;
    printf("%s\n",name);
    printf("The total time for merge sort name: %f\n", ((double)time_t) / CLOCKS_PER_SEC);

    return 0;
}
