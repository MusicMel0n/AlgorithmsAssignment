#include <stdio.h>
#include <stdbool.h>

void deleteElement(int[], int[], int, int*);
bool arrayContains(int[], int, int*);

#define SIZE 5
int main(){
    int arr[SIZE] = {1, 2, 3, 4, 5};
    int deletedIndices[SIZE];
    int pos = 0;

    deleteElement(arr, deletedIndices, 3, &pos);
    for(int i = 0; i < SIZE; i++){
        if(arrayContains(deletedIndices, i, &pos) == false){
            printf("\n%d", arr[i]);
        }
    }

    printf("\n\nDeleted indices");
    for(int i = 0; i < pos; i++){
        printf("\n%d", deletedIndices[i]);
    }

    return 0;
}

void deleteElement(int arr[], int deletedIndices[], int index, int *pos){ //Deletes an element by marking it with 0 and adding the deleted index to the deletedIndices array
    arr[index] = 0;
    deletedIndices[*pos] = index;
    (*pos)++;
}

bool arrayContains(int arr[], int key, int *size){ //Checks if a number (key) appears in the passed in array
    for(int i = 0; i < *size; i++){
        if(arr[i] == key){
            return true;
        }
    }
    return false;
}