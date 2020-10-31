#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>

//NUMBER 2018555064 NAME SURNAME:HUSEYIN UGURLU

void printArr(int array[], int n)
{
    int i;
    for (i = 0; i < n; i++){
        printf("%d", array[i]);
         
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

//Insertion Sort
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

//Selection Algorithm
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
// Bubble Sort Algorithm
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
// Merge sort algorithm
void merge(int array[], int l, int m, int r)
{
    int i, j, k, n1, n2;
    n1 = m - l + 1;
    n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        }
        else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
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

void merge_sort_char(char arr[], int x, int y)
{
    if (x < y) {
        int m = x + (y - x) / 2;

        merge_sort_char(arr, x, m);
        merge_sort_char(arr, m + 1, y);

        merge_char(arr, x, m, y);
    }
}

int main() {

    printf("Isim Soyisim = HUSEYIN UGURLU = 2018555064\n");
    clock_t zaman1;

    //insertion Sort
    int ogrenci_no[] = { 2, 0, 1, 8, 5, 5, 5, 0, 6, 4 };
    char name[] = "huseyin ugurlu";
    int n = sizeof(ogrenci_no) / sizeof(ogrenci_no[0]);
    int char_size = strlen(name);

    zaman1 = clock();
    insertion_sort(ogrenci_no, n);
    zaman1 = clock() - zaman1;
    printArr(ogrenci_no, n);
    printf("insertion sort time: %f\n", ((double)zaman1) / CLOCKS_PER_SEC);
     printf("\n");
    insertion_sort_char(name, char_size);
    zaman1 = clock() - zaman1;
    printf("%s\n", name);
    printf("insertion char sort time: %f\n", ((double)zaman1) / CLOCKS_PER_SEC);
 printf("\n");
 
    //Selection Sort

    selection_sort(ogrenci_no, n);
    zaman1 = clock() - zaman1;
    printArr(ogrenci_no, n);
    printf("selection sort time: %f\n", ((double)zaman1) / CLOCKS_PER_SEC);
 printf("\n");
    selection_sort_char(name, char_size);
    zaman1 = clock() - zaman1;
    printf("%s\n", name);
    printf("selection char sort time: %f\n", ((double)zaman1) / CLOCKS_PER_SEC);
 printf("\n");

    //Bubble Sort



    bubble_sort(ogrenci_no, n);
    zaman1 = clock() - zaman1;
    printArr(ogrenci_no, n);
    printf("bubble sort time: %f\n", ((double)zaman1) / CLOCKS_PER_SEC);
 printf("\n");
    bubble_sort_char(name, char_size);
    zaman1 = clock() - zaman1;
    printf("%s\n", name);
    printf("bubble char sort time: %f\n", ((double)zaman1) / CLOCKS_PER_SEC);
 printf("\n");

    //Merge Sort



    merge_sort(ogrenci_no, 0, n - 1);
    zaman1= clock() - zaman1;
    printArr(ogrenci_no, n);
    printf("merge sort time: %f\n", ((double)zaman1) / CLOCKS_PER_SEC);
     printf("\n");
    merge_sort_char(name, 0, char_size - 1);
    zaman1 = clock() - zaman1;
    printf("%s\n", name);
    printf("merge char sort time: %f\n", ((double)zaman1) / CLOCKS_PER_SEC);
 printf("\n");
    return 0;
}

