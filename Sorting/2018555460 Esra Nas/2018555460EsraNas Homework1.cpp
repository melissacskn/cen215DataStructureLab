#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void bubbleSort(int arr[], int size){
	int i,j;
	
	for( i=0;i<size; i++){
		for(j=1;j<size-i;j++){
			if(arr[j-1]>arr[j]){
				int temp =arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=temp;
			}
		}
	}
	for(i=0;i<size;i++)
	printf(" %d ",arr[i]);
}
void bubbleSortName(char arr[], int size) 
{ 
   int i, j; 
   for (i = 0; i < size-1; i++)          
       for (j = 0; j < size-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swapChar(arr[j], arr[j+1]); 
              for(i=0;i<size;i++){
              	 printf("%c ",arr[i]);
			  }
             
} 

void selectionSort(int arr[],int size){
	int i,j;
	int minimumindex;
	for(i=0;i<size;i++){
		minimumindex=i;
		for(j=i+1;j<size;j++){
			if(arr[j]<arr[minimumindex]){
				minimumindex=j;
				
			}
			int temp=arr[i];
			arr[i]=arr[minimumindex];
			arr[minimumindex]=temp;	
		}
	}
	for(i=0;i<size;i++)
	printf(" %d ",arr[i]);
}
void selectionSortName(char arr[], int size) 
{ 
    int i, j;
    char min;  
    for (i = 0; i < size-1; i++) 
    { 
        min = i; 
        for (j = i+1; j < size; j++) 
          if (arr[j] < arr[min]) 
            min = j; 
        swapChar(&arr[min], &arr[i]); 
    } 
    	for(i=0;i<size;i++)
	printf("%c ",arr[i]);
} 

void insertionSort(int arr[],int size){
	int i,j;
	int element;
	for(i=1;i<size;i++){
		element=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>element){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=element;
	}
	for(i=0;i<size;i++)
	printf(" %d ",arr[i]);
}
void insertionSortName(char arr[], int size) 
{
    int i, j;
    char element;
    for(i = 1; i <size; i++) {
        element = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > element) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = element;
    }
    	for(i=0;i<size;i++)
	printf("%c ",arr[i]);
}
void swapChar(char *xp, char *yp) 
{ 
    char temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
 
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
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
 
void mergeSort(int arr[], int l, int r) 
{ 
   
   
    if (l < r) { 
       
        int m = l + (r - l) / 2; 
 

        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
 
        merge(arr, l, m, r); 
    } 
    
} 

void mergeChar(char arr[], int left, int middle, int right) 
{ 
    int i, j, k, n1, n2; 
    n1 = middle - left + 1; 
    n2 = right - middle; 

    int L[n1], R[n2]; 

    for (i = 0; i < n1; i++) 
        L[i] = arr[left + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[middle + 1 + j]; 
 
    i = 0; 
    j = 0; 
    k = left; 

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

void mergeSortName(char arr[], int left, int right) 
{ 
    if (left < right) { 
        int middle = left + (right - left) / 2; 
 
        mergeSortName(arr, left, middle); 
        mergeSortName(arr, middle + 1, right); 
 
        mergeChar(arr, left, middle, right); 
    } 
}

 

int main(int argc, char *argv[]) {
	
	int i;
	int scNo[]={2,0,1,8,5,5,5,4,6,0};
	int scNo_size = sizeof(scNo) / sizeof(scNo[0]); 
	char name[]="esra nas";
 	
 	clock_t begin,end;
 	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	
	begin=clock();
	printf("This is bubble sort\n");
	bubbleSort(scNo,10);
	printf("\n");
	bubbleSortName(name,8);
	end=clock();
	printf("\n Time taken for sorting %lf \n",time_spent);
	
	begin=clock();
	printf("\n This is selection sort\n");
	selectionSort(scNo,10);
	printf("\n");
	selectionSortName(name,8);
	end=clock();
	printf("\n Time taken for sorting %lf \n",time_spent);

	begin=clock();
	printf("\n This is insertion sort\n");
	insertionSort(scNo,10);
	printf("\n");
	insertionSortName(name,8);
	end=clock();
	printf("\n Time taken for sorting %lf \n",time_spent);
		
	
	begin=clock();	
	printf("\n This is merge sort\n");
    mergeSort(scNo, 0, scNo_size - 1);
    for(  i=0;i<10;i++)
	printf(" %d ",scNo[i]);
	printf("\n");
	 mergeSortName(name, 0,7);
	 for(  i=0;i<10;i++)
	printf("%c ",name[i]);
	end=clock();
	printf("\n Time taken for sorting %lf \n",time_spent);
	

	   
				
	return 0;
}
