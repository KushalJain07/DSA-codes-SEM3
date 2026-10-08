#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    char data;
    struct Node* next;  
};

struct Node* createNode(char data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void push(struct Node** top,char data){
    if(*top==NULL){
        struct Node* newNode=createNode(data);
        *top=newNode;
        return;
    }
    struct Node* newNode=createNode(data);
    newNode->next=*top;
    
    *top=newNode;
    return;
}

char pop(struct Node** top){
    if(*top==NULL){
        printf("Stack empty. UNDERFLOW\n");
        return '\0';
    }
    struct Node* temp = *top;
    char x=temp->data;
    *top=(*top)->next;
    free(temp);
    printf("Popped: %c\n",x);
    return x;
}

void peek(struct Node** top){
    if(*top != NULL) {
        printf("%c\n", (*top)->data);
    }
}

bool isEmpty(struct Node** top){
    if(*top==NULL){
        return true;
    }
    return false;
}

void display(struct Node** top){
    if(isEmpty(top)){
        return;
    }
    struct Node* temp= *top;
    while(temp!=NULL){
        printf("%c -> ",temp->data);
        
        temp=temp->next;
    }
    printf("NULL");
    printf("\n");
}

int main(){
    struct Node* top=NULL;
    push(&top, '1');
    push(&top, '2');
    push(&top, '3');
    display(&top);
    peek(&top);
    pop(&top);
    pop(&top);
    peek(&top);
    return 0;
}
