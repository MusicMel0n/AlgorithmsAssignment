#include <stdio.h>
#include <stdbool.h>

#define MAX 10
struct queue{
    int data[MAX];
    int front;
    int back;
    int size;
};

//Queue Functions
void initializeQueue(struct queue *q);
bool isFull(struct queue *q);
bool isEmpty(struct queue *q);
void enqueue(struct queue *q, int);
void dequeue(struct queue *q);
void peek(struct queue *q);
void printQueue(struct queue *q);

//Stack Functions
void push(struct queue *q, int);
void pop(struct queue *q);

int main(){
    struct queue q;

    initializeQueue(&q);
    push(&q, 1);
    push(&q, 2);
    push(&q, 3);
    push(&q, 4);
    push(&q, 5);
    printQueue(&q);
    pop(&q);
    printf("\n");
    printQueue(&q);

    return 0;
}

//Queue Functions
void initializeQueue(struct queue *q){
    q -> front = 0;
    q -> back = 0;
    q -> size = 0;
}

void enqueue(struct queue *q, int value){
    if(!isFull(q)){
        q -> data[q -> back] = value;
        q -> back = (q -> back + 1) % MAX;
        q -> size++;
    }
    else{
        printf("\nQueue is full! Cannot enqueue %d!", value);
    }
}

void dequeue(struct queue *q){
    if(!isEmpty(q)){
        q -> front = (q -> front + 1) % MAX;
        q -> size--;
    }
    else{
        printf("\nQueue is empty! Cannot dequeue!");
    }
}

void peek(struct queue *q){
    if(!isEmpty(q)){
        printf("\n%d", q -> data[q -> front]);
    }
    else{
        printf("Queue is empty cannot peek!");
    }
}

void printQueue(struct queue *q){
    for(int i = q -> front; i < q -> back; i++){
        printf("%d ", q -> data[i]);
    }
}

bool isFull(struct queue *q){
    if((q -> size) == MAX){
        return true;
    }
    else{
        return false;
    }
}

bool isEmpty(struct queue *q){
    if((q -> size) == 0){
        return true;
    }
    else{
        return false;
    }
}

//Stack Functions
void push(struct queue *q, int value){
    enqueue(q, value);
}

void pop(struct queue *q){
    for(int i = 0; i < q -> size - 1; i++){ //Loop runs until we have moved everything in front of the last item in the queue behind it
        enqueue(q, q -> data[q -> front]); //Queues the element in the front of the queue to the back
        dequeue(q); //Dequeues the element at the front which is now a duplicate
    }

    dequeue(q); //Dequeues the element now at the front (started as the element in the back)
}