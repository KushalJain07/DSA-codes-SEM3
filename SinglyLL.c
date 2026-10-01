/*contains insertion, deletion (start, mid, end), inversion ,and concat*/

#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node* next;
    
};


struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->next=NULL;
    newNode->data=data;
    
    return newNode;
}


void insertStart(struct Node** head,int data){
    struct Node* newNode = createNode(data);
    newNode->next=*head;
    *head=newNode;
    
}

void insertEnd(struct Node** head, int data ){
    
    
    struct Node* newNode = createNode(data);
    
    if(*head==NULL){
        *head=newNode;
        return;
    }
    struct Node* temp = *head;
    while(temp->next!=NULL){
        temp=temp->next;
        
    }
    newNode->next=NULL;
    temp->next=newNode;
    
}



void insMiddle(int data, int pos, struct Node** head){
    
    
    struct Node* newNode = createNode(data);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    struct Node* temp = *head;
    int i;
    for(i=1;i<pos;i++){
        temp=temp->next;
        
    }
    newNode->next=temp->next;
    temp->next=newNode;
    
}





void delStart(struct Node** head){
    if((*head)->next==NULL){
        free(head);
        return;
    }
    struct Node* temp= *head;
    *head=(*head)->next;
    temp->next=NULL;
    free(temp);
}


void delEnd(struct Node** head){
    if((*head)->next==NULL){
        free(head);
        return;
    }
    struct Node* temp= *head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}



void delMiddle(struct Node** head, int pos){
    if((*head)->next==NULL){
        free(head);
        return;
    }
    struct Node* temp= *head;
    int i;
    for(i=1; i<pos-1;i++){
        temp=temp->next;
    }
    struct Node* temp2=temp->next;
    
    temp->next=temp2->next;
    
    free(temp2);
    
    
}

void inverse(struct Node** head){
    struct Node* prev = NULL;
    struct Node* next = NULL;
    struct Node* current = *head;
    
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        
    }
    *head = prev;
    
}


/*
Think of reversing a linked list like flipping a chain of directional arrows one by one.
The Problem

In a normal list:
A -> B -> C -> NULL

To reverse it, every node needs to point backwards:
NULL <- A <- B <- C
The 4 Steps inside the Loop

You need 3 pointers to keep track of where you are:

    prev: The node behind current (starts as NULL).

    current: The node you are reversing right now (starts at head).

    next: Keeps track of the rest of the list so you don't lose it.

Inside while(current != NULL):

    next = current->next

    Save the rest of the list. (If you change current->next without saving this first, you lose access to B and C).

    current->next = prev

    Flip the arrow! Point current backwards to prev.

    prev = current

    Move prev one step forward (it takes current's spot).

    current = next

    Move current one step forward to process the next node.

Step-by-Step Visualization

Starting List: 10 -> 20 -> 30 -> NULL
prev = NULL, current = 10
Pass 1 (At Node 10):

    next = 20

    10->next = NULL (flipped arrow: NULL <- 10)

    prev = 10

    current = 20

Pass 2 (At Node 20):

    next = 30

    20->next = 10 (flipped arrow: NULL <- 10 <- 20)

    prev = 20

    current = 30

Pass 3 (At Node 30):

    next = NULL

    30->next = 20 (flipped arrow: NULL <- 10 <- 20 <- 30)

    prev = 30

    current = NULL

Loop ends!

current is now NULL.
prev is pointing at 30 (the new first node).

That's why at the very end you set *head = prev so head points to 30.
*/



struct Node* concatLL(struct Node** head1, struct Node** head2)
{
    if(*head1==NULL){
        *head1=*head2;
        return *head1;
        
    }
    struct Node* temp = *head1;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=*head2;
    return *head1;
    
}

int main(){
    
    struct Node* temp1;
    
    struct Node* head1 = createNode(10);
    



    insertStart(&head1, 20);
    insertStart(&head1, 30);
    insertStart(&head1, 40);
    insertEnd(&head1, 100);
    insMiddle(35, 3, &head1);
    delStart(&head1);
    delEnd(&head1);
    delMiddle(&head1, 3);
    insertStart(&head1, 210);
    insertStart(&head1, 220);
    insertStart(&head1, 230);
    inverse(&head1);
    temp1=head1;
    while(temp1!=NULL){
        
        printf(" -> %d -> ",temp1->data);
        temp1=temp1->next;
    }
    
    printf("\n\n");
    /*LL2*/
    struct Node* head2 = createNode(300);
    struct Node* temp2;
    
    insertStart(&head2,301);
    insertStart(&head2,302);
    insertStart(&head2,303);
    
    temp2 = head2;
    while(temp2!=NULL){
        printf(" -> %d -> ",temp2->data);
        temp2=temp2->next;
        
    }
    
    
    printf("\n\n");
    
    struct Node* temp3=concatLL(&head1, &head2);
    while(temp3!=NULL){
        printf(" -> %d -> ",temp3->data);
        temp3=temp3->next;
        
    }
    
    printf("\n\n");
}
