#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int priority;
    struct node *next;
};

typedef struct node pq;

pq *front = NULL, *rear = NULL;

void enqueue(int data, int priority) {
    pq *t, *temp;
    t = (pq *)malloc(sizeof(pq));
    t->data = data;
    t->priority = priority;
    t->next = NULL;

    if (front == NULL || priority < front->priority) {
        t->next = front;
        front = t;
    } else {
        temp = front;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        t->next = temp->next;
        temp->next = t;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } 
    else {
        pq *temp = front;
        printf("Dequeued: %d (Priority: %d)\n", front->data, front->priority);
        front = front->next;
        free(temp);
    }
}

int main() {
    enqueue(10, 2);
    enqueue(20, 1);
    enqueue(30, 3);
    enqueue(220,2);
    enqueue(40, 1);

    dequeue(); // Dequeues 20 with priority 1
    dequeue(); // Dequeues 40 with priority 1
    dequeue(); // Dequeues 10 with priority 2
    dequeue(); // Dequeues 30 with priority 3

    return 0;
}
