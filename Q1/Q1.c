#include <stdio.h>

void intersectionBruteForce(int[], int[], int[]);

#define SIZE1 6
#define SIZE2 7
int main(){
    int arr1[SIZE1] = {5, 4, 8, 9, 3, 0};
    int arr2[SIZE2] = {5, 4, 3, 2, 142, 10, 9};
    int intersection[SIZE2] = {0};

    intersectionBruteForce(arr1, arr2, intersection);

    return 0;
}

void intersectionBruteForce(int arr1[], int arr2[], int intersection[]){
    int count = 0;

    //Checks every element in arr1 against arr2 and adds it to the intersection array when they are equal to eachother
    for(int i = 0; i < SIZE1; i++){
        for(int j = 0; j < SIZE2; j++){
            if(arr1[i] == arr2[j]){
                intersection[count] = arr1[i];
                count++;
            }
        }
    }

    //Displays the intersection array
    for(int i = 0; i < count; i++){
        printf("\n%d", intersection[i]);
    }
}