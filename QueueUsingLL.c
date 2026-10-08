#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    char data;
    struct Node* next;  
};

bool isEmpty(struct Node** front, struct Node** rear){
    if(*front==NULL && *rear==NULL){
        return true;
    }
    return false;
}

struct Node* createNode(char data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void enqueue(struct Node** front, struct Node** rear,char data){
    if(isEmpty(front,rear)){
        struct Node* newNode=createNode(data);
        *front=*rear=newNode;
        return;
    }
    struct Node* newNode=createNode(data);
    ((*rear)->next)=newNode;
    *rear=newNode;
    return;
}

char dequeue(struct Node** front, struct Node** rear){
    if(isEmpty(front,rear)){
        printf("Queue empty. UNDERFLOW\n");
        return '\0';
    }
    struct Node* temp = *front;
    char x=temp->data;
    *front=(*front)->next;
    if(*front == NULL){
        *rear = NULL;
    }
    free(temp);
    printf("Dequeued: %c\n",x);
    return x;
}

void peek(struct Node** front){
    if(*front != NULL){
        printf("Front: %c\n", (*front)->data);
    }
}

void display(struct Node** front, struct Node** rear){
    if(isEmpty(front,rear)){
        return;
    }
    struct Node* temp= *front;
    while(temp!=NULL){
        printf("%c -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node* front=NULL;
    struct Node* rear=NULL;
    enqueue(&front, &rear, '1');
    enqueue(&front, &rear, '2');
    enqueue(&front, &rear, '3');
    enqueue(&front, &rear, '4');
    enqueue(&front, &rear, '5');
    enqueue(&front, &rear, '6');
    enqueue(&front, &rear, '7');
    enqueue(&front, &rear, '8');
    display(&front, &rear);
    peek(&front);
    dequeue(&front, &rear);
    dequeue(&front, &rear);
    peek(&front);
    return 0;
}
