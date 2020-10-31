#include <stdio.h>
#include<time.h>
#include<conio.h>

/*Amine Ceyda Tandoðan
  2018555061*/
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap2(char *a, char *b)
{
   char temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)

       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);

              printf("Bubble Sort: \n");
}

void bubbleSort2(char arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)

       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap2(&arr[j], &arr[j+1]);


}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int s1 = m - l + 1;
    int s2 = r - m;


    int left[s1], right[s2];


    for (i = 0; i < s1; i++)
        left[i] = arr[l + i];
    for (j = 0; j < s2; j++)
        right[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < s1 && j < s2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }


    while (i < s1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < s2) {
        arr[k] = right[j];
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

void merge2(char arr[], int l, int m, int r)
{
    int i, j, k;
    int s1 = m - l + 1;
    int s2 = r - m;


    int left[s1], right[s2];


    for (i = 0; i < s1; i++)
        left[i] = arr[l + i];
    for (j = 0; j < s2; j++)
        right[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < s1 && j < s2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }


    while (i < s1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < s2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort2(char arr[], int l, int r)
{
    if (l < r) {

    int m = l + (r - l) / 2;

        mergeSort2(arr, l, m);
        mergeSort2(arr, m + 1, r);

        merge2(arr, l, m, r);
    }

}

void insertionSort(int arr[], int n)
{
    int i, temvalue, j;
    for (i = 1; i < n; i++) {
        temvalue = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > temvalue) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temvalue;
    }
}

void insertionSort2(char arr[], int n)
{
    int i, temvalue, j;
    for (i = 1; i < n; i++) {
        temvalue = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > temvalue) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temvalue;
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, minindex;

    for (i = 0; i < n-1; i++)
    {
        minindex = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[minindex])
            minindex = j;
        swap(&arr[minindex], &arr[i]);
    }
}
void selectionSort2(char arr[], int n)
{
    int i, j, minindex;

    for (i = 0; i < n-1; i++)
    {
        minindex = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[minindex])
           minindex = j;
        swap(&arr[minindex], &arr[i]);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void printArray2(char arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf(" %c ", arr[i]);
    printf("\n");
}


int main()
{
    int arr[] = {2,0,1,8,5,5,5,0,6,1};
    int size1 = sizeof(arr)/sizeof(arr[0]);
    char name[]="Amine TANDOGAN";
    int size2=sizeof(name)/sizeof(name[0]);
     clock_t start = clock();

    bubbleSort(arr, size1);
    printArray(arr, size1);
    bubbleSort2(name, size2);
    printArray2(name, size2);

       clock_t stop = clock();
    double elapsed = (double)(stop - start)  / CLOCKS_PER_SEC;
    printf("\nexecution time: %f\n", elapsed);

         clock_t begin= clock();
    mergeSort(arr,0,size1-1);
    printf("\nMerge Sort\n");
    printArray(arr, size1);
    mergeSort2(name,0,size2-1);
    printArray2(name, size2);

 clock_t end = clock();
    double elapsed2 = (double)(end - begin)  / CLOCKS_PER_SEC;
    printf("\nexecution time: %f\n", elapsed2);

    clock_t start2 = clock();
    insertionSort(arr,size1);
    printf("\n Insertion Sort\n");
    printArray(arr, size1);
    insertionSort2(name,size2);
    printArray2(name, size2);

     clock_t stop2 = clock();
    double elapsed3 = (double)(stop2 - start2)  / CLOCKS_PER_SEC;
    printf("\nexecution time: %f\n", elapsed3);

     clock_t start3 = clock();
    selectionSort(arr,size1);
    printf("\n Selection Sort\n");
    printArray(arr, size1);
    selectionSort2(name,size2);
    printArray2(name, size2);

 clock_t stop3 = clock();
    double elapsed4 = (double)(stop3 - start3)  / CLOCKS_PER_SEC;
    printf("\nexecution time: %f\n", elapsed4);

    return 0;
}
