#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

void dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Kuyruk bos.\n");
        return;
    }
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL)
        queue->rear = NULL;
    free(temp);
}

void display(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Kuyruk bos.\n");
        return;
    }
    struct Node* temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;

    int choice, data;

    while (1) {
        printf("1. Ekleme\n");
        printf("2. Silme\n");
        printf("3. Goruntuleme\n");
        printf("4. Cikis\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Eklenecek elemani girin: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                exit(0);
            default:
                printf("Gecersiz secim. Tekrar deneyin.\n");
        }
    }

    return 0;
}

