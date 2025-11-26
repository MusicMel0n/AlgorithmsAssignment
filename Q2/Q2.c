#include <stdio.h>

int binarySearch(int[], int);
void merge(int[], int[], int[], int, int);
void mergeSort(int[], int);

#define SIZE1 7
#define SIZE2 6
int main(){
    int arr1[SIZE1] = {5, 4, 8, 12, 3, 0, 9};
    int arr2[SIZE2] = {5, 4, 3, 2, 9, 10};
    int intersection[SIZE2] = {0};
    int size;
    int count = 0;

    mergeSort(arr1, SIZE1);
    mergeSort(arr2, SIZE2);
  
    if(SIZE2 > SIZE1){
        size = SIZE2 - 1;
    }
    else{
        size = SIZE1 - 1;
    }

    for(int i = 0; i < size; i++){
        if(binarySearch(arr2, arr1[i]) != -1){
            intersection[count] = arr1[i];
            count++;
        }
    }

    for(int i = 0; i < count; i++){
        printf("\n%d", intersection[i]);
    }
}

int binarySearch(int arr[], int key){ //Input array has to be sorted
    int low = 0; //Lowest index of array (always 0 at start)
    int high; //highest index of array (size of array - 1)

    if(SIZE2 > SIZE1){
        high = SIZE2 - 1; //Checks which array is bigger and sets highest index to the largest array
    }
    else{
        high = SIZE1 - 1;
    }

    while(low <= high){ //When false we have search through the whole array and we did not find the key
        int middle = (low + high) / 2; //Gets the middle index of the portion of the array we are looking at 
        if(key == arr[middle]){
            return middle; //If they key is in the middle index we return the middle index
        }
        else if(key < arr[middle]){
            high = middle - 1; //If the key is less than the element in the middle index we set high to the middle index - 1 (Look at elements to the left of the previous middle index)
        }
        else if(key > arr[middle]){
            low = middle + 1; //If the key is greater than the element in the middle index we set low to middle index + 1 (Look at elements to the right of the previous middle index)
        }
    }

    return -1; //Return a -1 if the key was NOT found in the input array
}

void mergeSort(int arr[], int size){
    int length = size;

    //Base case: arrays with 0 or 1 elements are already sorted
    if(length < 2){ 
        return;
    }

    //Gets the middle index of the array
    int middle = size / 2; 

    //Splits the array into two halves into two temporary arrays
    int leftHalf[middle]; 
    int rightHalf[size - middle]; 

    //Copies the first half of the elements into the leftHalf array
    for(int i = 0; i < middle; i++){
        leftHalf[i] = arr[i]; 
    }

    //Copies the second half of the elements into the rightHalf array
    for(int i = middle; i < length; i++){
        rightHalf[i - middle] = arr[i]; 
    } 

    mergeSort(leftHalf, middle); //Divide: Splits the left half and recursively sorts it
    mergeSort(rightHalf, size - middle); //Divide: Splits the right half and recursively sorts it
    merge(arr, leftHalf, rightHalf, middle, size - middle); //Conquer: Merges the two sorted halves back into the original array
}

void merge(int arr[], int leftHalf[], int rightHalf[], int leftSize, int rightSize){
    //i tracks position in left array, j tracks position in right array and k tracks position in the final merged array
    int i = 0, j = 0, k = 0; 

    //While we have elements left in the left half and the right half
    while(i < leftSize && j < rightSize){ 
        //Iterates through the left and right half and takes the smaller element from either the left half or the right half and places it in the final merged array
        if(leftHalf[i] <= rightHalf[j]){
            arr[k] = leftHalf[i];
            i++;
        }
        else{
            arr[k] = rightHalf[j];
            j++;
        }
        k++;
    }

    //Copy any remaining elements left over in the left half (if any)
    while(i < leftSize){
        arr[k] = leftHalf[i];
        i++;
        k++;
    }

    //Copy any remaining elements left over in the right half (if any)
    while(j < rightSize){
        arr[k] = rightHalf[j];
        j++;
        k++;
    }
}