#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



//Bubble sort
void bubbleSort(int arr[], int size){
     int temp;
     int a, b;
     int c;
     
     
     for (a=1; a<size; a++)
     {
        c = size-a;
        
        for (b=0; b<c; b++)
         {
            if(arr[b] > arr[b+1])
             {
                temp = arr[b];
                arr[b] = arr[b+1];
                arr[b+1] = temp;
             }
         }
    }
}

void bubblechar(char arr[], int size){
     char temp;
     int a, b;
     int c;
     
     
     for (a=1; a<size; a++)
     {
       c=size-a;
       for (b=0; b<c; b++)
       {
          if(arr[b] > arr[b+1])
           {
            temp = arr[b];
            arr[b] = arr[b+1];
             arr[b+1] = temp;
             }
         }
    }
}



//Insertion Sort
void InsertionSort(int arr[], int number)
{
	int x, key, y;
	for (x = 1; x < number; x++) {
		key = arr[x];
		y = x - 1;
		
		while (y >= 0 && arr[y] > key) {
		    
			arr[y + 1] = arr[y];
			y = y - 1;
		}
		arr[y + 1] = key;
	}
}

void Insertionchar(char arr[], int number){
	int a,b;
	char key;
	for (a=1; a<number; a++){
		key = arr[a];
		b = a-1;
		while(b >= 0 && arr[b] > key){
			arr[b+1] = arr[b];
			b = b-1;
		}
		arr[b+1] = key;
	}
}

//Selection Sort
void SelectionSort(int *p, int size)
{
   int   x, y, temp, min;

   for (x = 0; x < size - 1; x++) {
      min = x;
      for (y = x + 1; y < size; y++)
         if (p[min] > p[y])
            min = y;
      temp = p[min];
      p[min] = p[x];
      p[x] = temp;
   }
}

void Selectionchar(char arr[], int number)
{
      int  x, y, min;
      char temp;


   for (x = 0; x < number - 1; x++) {
      min = x;
      for (y = x+ 1; y < number; y++)
         if (arr[min] > arr[y])
            min = y;
      temp = arr[min];
      arr[min] = arr[x];
      arr[x] = temp;
}
}



//Merge Sort
void merge(int *Arr, int start, int mid, int end) {

	int temp[end - start + 1];
	int x = start ;
	int y = mid+1 ;
	int k = 0;

	while(x <= mid && y <= end) {
		if(Arr[x] <= Arr[y]) {
			temp[k] = Arr[x];
			k += 1; 
			x += 1;
		}
		else {
			temp[k] = Arr[y];
			k += 1;
			y += 1;
		}
	}
	while(x <= mid) {
		temp[k] = Arr[x];
		k += 1; 
		x += 1;
	}

	while(y <= end) {
		temp[k] = Arr[y];
		k += 1; 
		y += 1;
	}

	for(x = start; x <= end; x += 1) {
		Arr[x] = temp[x - start];
	}
}
void mergeSort(int *Arr, int start, int end) {

	if(start < end) {
		int mid = ((start + end) / 2);
		mergeSort(Arr, start, mid);
		mergeSort(Arr, mid+1, end);
		merge(Arr, start, mid, end);
	}
}

 void mergesort(char *Arr, int start, int mid, int end) {

	int temp[end - start + 1];
	int x = start, y = mid+1, k = 0;

	while(x <= mid && y <= end) {
		if(Arr[x] <= Arr[y]) {
			temp[k] = Arr[x];
			k += 1; x+= 1;
		}
		else {
			temp[k] = Arr[y];
			k += 1; y += 1;
		}
	}
	while(x <= mid) {
		temp[k] = Arr[x];
		k += 1; x += 1;
	}

	while(y <= end) {
		temp[k] = Arr[y];
		k += 1; y += 1;
	}

	for(x = start; x <= end; x += 1) {
		Arr[x] = temp[x - start];
	}
}
void mergesortchar(char *Arr, int start, int end) {

	if(start < end) {
		int mid = (start + end) / 2;
		mergesortchar(Arr, start, mid);
		mergesortchar(Arr, mid+1, end);
		mergesort(Arr, start, mid, end);
	}
}


 void prints(int arr[], int size){
      int a;
      for(a = 0; a < size ; a++){
          
          printf("%d ",arr[a]);
          
      }
}




 int main(){
     
     
     clock_t t;
     
     //BubbleSort
      int arr[] ={2,0,1,8,5,5,5,4,5,3} ;
      int x = sizeof(arr)/sizeof(arr[0]);
      char name[] = "murat ozcan";
      int char0 = strlen(name);

      t = (double)clock();
      bubbleSort(arr, x);
      printf("\nSorted numbers in Bubble Sort:");
      prints(arr,x);
      bubblechar(name,char0);
      t = clock()-t;
      printf("\nSorted name in Bubble Sort : %s\n",name);
      printf("Running time of Bubble Sort: %f\n",((double)t) / CLOCKS_PER_SEC);



      //SelectionSort
 	  int ar1[] = {2,0,1,8,5,5,5,4,5,3};
      int y = sizeof(arr)/sizeof(ar1[0]);
      char name1[] = "murat ozcan";
      int char1 = strlen(name1);

      t = (double)clock();

      SelectionSort(ar1, y);
      printf("\nSorted numbers in Selection Sort:");
      prints(ar1,y);
      Selectionchar(name1,char1);
      t =(double)clock()-t;
      printf("\nSorted name in Selection Sort : %s\n",name1);
      printf("Running time of Selection Sort : %f\n",((double)t) / CLOCKS_PER_SEC);

      //MergeSort
      int ar2[] ={2,0,1,8,5,5,5,4,5,3} ;
      int z = sizeof(arr)/sizeof(ar2[0]);
      char name2[] = "murat ozcan";
      int char2 = strlen(name2);

      t = (double)clock();
      mergeSort(ar2,0, z-1);
      printf("\nSorted numbers in Merge Sort:");
      prints(ar2,z);
      mergesortchar(name2,0,char2-1);
      t = (double)clock()-t;
      printf("\nSorted name in Merge Sort : %s\n",name2);
      printf("Running time of Merge Sort: %f\n",((double)t) / CLOCKS_PER_SEC);
      
       	  //InsertionSort
 	  int ar3[] = {2,0,1,8,5,5,5,4,5,3};
      int f = sizeof(arr)/sizeof(ar3[0]);
      char name3[] = "murat ozcan";
      int char3 = strlen(name3);

      t = (double)clock();
      InsertionSort(ar3, f);
      printf("\nSorted numbers in InsertionSort:");
      prints(ar3,f);
      Insertionchar(name3,char3);
      t = (double)clock()-t;
      printf("\nSorted name in Insertion Sort : %s\n",name3);
      printf("Running time of Insertion Sort: %f\n",((double)t) / CLOCKS_PER_SEC);


      return 0;
 }