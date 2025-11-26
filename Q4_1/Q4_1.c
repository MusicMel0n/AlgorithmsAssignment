#include <stdio.h>

#define LENGTH 5

void deleteElement(int[], int, int*);
int main(){
    int array[LENGTH] = {5, 4, 3, 2, 1};
    int size = LENGTH;

    deleteElement(array, 1, &size);
    printf("\n\nPrinting Array:\n");
    for(int i = 0; i < size; i++){
        printf("\n%d", array[i]);
    }

    deleteElement(array, 0, &size);
    printf("\n\nPrinting Array:\n");
    for(int i = 0; i < size; i++){
        printf("\n%d", array[i]);
    }

    deleteElement(array, 0, &size);
    printf("\n\nPrinting Array:\n");
    for(int i = 0; i < size; i++){
        printf("\n%d", array[i]);
    }
}

void deleteElement(int array[], int index, int *size){ //Deletes an element by swapping the element you want to delete with the last element in the array and reduces the logical size by 1
    if(*size == 0){
        printf("Cannot delete array is empty!");
    }
    else{
        array[index] = array[(*size) - 1];
        (*size)--;
    }
}

