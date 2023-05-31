# include<iostream>
#include <bits/stdc++.h>
#include <cstdlib> 
#include <ctime> 
#include <climits>
#include<stdio.h>
#include<conio.h>
#include<iomanip>
#include<string>


int printArray(int array[], int size);
void insertionSort(int array[], int size);

void mergeSort(int arr[], int n) ;
int min(int x, int y) { return (x<y)? x :y; }
void merge(int arr[], int l, int m, int r) ;


void quickSortIterative(int arr[], int low, int high);
int partition (int arr[], int low, int high);
void swap(int* a, int* b) ;

 void countSort(int array[], int size) ;


using namespace std;
int main()
{
	 
	int n, i;
 
	for(int j=1; j<6; j++)
{       
		cout << "\nstep #"<<j<< "\n ";
		cout <<"enter the size of array =   ";
	
	
	cin >> n; 
	  // 4 array 
	   int arrayinser[n]; 
	      int arraymarg[n];
	      int arrayquick[n];
	      int arraycount[n];
	        
	        
	        // stor data random in array 
	for( i=0; i<n ; i++ )
     	{
	     	arrayinser[i]= rand();
//	cout<<"arr["<<i<<"]="<< arrayinser[i] << "\n ";
	
		
     }

    // copy arrayinser to 3 array 
for(int d=0; d<n ; d++)
 { 
   
  arraymarg[d]=arrayinser[d];
 }
 
 
     
for(int d=0; d<n ; d++)
 { 
   
  arraycount[d]=arrayinser[d];
 }
 
 
 
     
for(int d=0; d<n ; d++)
 { 
   
  arrayquick[d]=arraymarg[d];
 }
 
 ////////////////////////////////////////////////////////////////////////////////////
 
 //Inseartion time    


					float start_s1=clock();
				 insertionSort( arrayinser, n);
             		float stop_s1=clock();
					cout << "time1 insertionSort : " << (stop_s1-start_s1)/double(CLOCKS_PER_SEC)*1000 << endl;

 
// insertionSort( arrayinser, n);
////cout << " \n  \n ##########################################################################################\n merge sort  \n";

//mergtime     

					 start_s1=clock();
                   	mergeSort(arraymarg, n);
             		  stop_s1=clock();
					  cout << "time1 mergeSort: " << (stop_s1-start_s1)/double(CLOCKS_PER_SEC)*1000 << endl;
			
            	

 //   merge_sort(arraymarg, n);
 //  printArray(arraymarg, n);
 

 //cout << " \n  \n ##########################################################################################\n quick sort  \n";
 //quicktime

					 start_s1=clock() ;
		       	quickSortIterative(arrayquick, 0, n - 1);
     				 stop_s1=clock();
					cout << "time1 quickSort: " << (stop_s1-start_s1)/double(CLOCKS_PER_SEC)*1000 << endl;

//  quickSortIterative(arrayquick, 0, n - 1);
  
  
// printArray(arrayquick, n);
 // cout << " \n  \n ##########################################################################################\n counting sort  \n";
    
  
	 //countingtime

					 start_s1=clock() ;
					  
  countSort( arraycount, n);
             		 stop_s1=clock();
					 cout << "time1 countingSort: " << (stop_s1-start_s1)/double(CLOCKS_PER_SEC)*1000 << endl;
		

 
 // countSort( arraycount, n);
   
}
return 0;
}


	

 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 // print fun
 // insertion sort code 
int printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
  
}


void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
  
  
}

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  // margsort code 
  
void mergeSort(int arr[], int n)
{
int curr_size; // For current size of subarrays to be merged
				// curr_size varies from 1 to n/2
int left_start; // For picking starting index of left subarray
				// to be merged

// Merge subarrays in bottom up manner. First merge subarrays of
// size 1 to create sorted subarrays of size 2, then merge subarrays
// of size 2 to create sorted subarrays of size 4, and so on.
for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size)
{
	// Pick starting point of different subarrays of current size
	for (left_start=0; left_start<n-1; left_start += 2*curr_size)
	{
		// Find ending point of left subarray. mid+1 is starting
		// point of right
		int mid = min(left_start + curr_size - 1, n-1);

		int right_end = min(left_start + 2*curr_size - 1, n-1);

		// Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
		merge(arr, left_start, mid, right_end);
	}
}
}

/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

 
  
  
  
  
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
// An iterative implementation of quick sort

 

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 

int partition(int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
 
    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}
 

void quickSortIterative(int arr[], int l, int h)
{
  
    int stack[h - l + 1];
 
   
    int top = -1;
 
  
    stack[++top] = l;
    stack[++top] = h;
 
    while (top >= 0) {
        
        h = stack[top--];
        l = stack[top--];
 
      
        int p = partition(arr, l, h);
 
        
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
 
        
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}
 

printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        cout << arr[i] << " ";
}


  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void countSort(int arr[], int n){
 
    // Step 1: Finding the maximum element
    int maximum = -1;
 
    for(int i=0;i<n;i++){
        maximum = max(arr[i], maximum);
    }
 
    // Step 2: Initialize a count array of length = (max + 1) 
 
    int count[maximum+1];
    memset(count, 0, sizeof(count));
 
    // Step 3: Fill the count array accordingly
 
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
 
    // Step 4: Calculate cumulative frequency in Count Array
 
    for(int i=1;i<=maximum;i++){
        count[i] += count[i-1];
    }
 
    // Step 5: Fix the values in the sorted array
 
    int sorted_arr[n];
 
    for(int i=0;i<n;i++){
        sorted_arr[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
 
    // Printing the sorted array
 
  // for(int i=0;i<n;i++){
  //      cout<<sorted_arr[i]<<" ";
  //  }
   // cout<<endl;
}






