/*DLL with ins, del, concat, and inverse*/

#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
    
};


struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->next=NULL;
    newNode->prev=NULL;
    newNode->data=data;
    
    return newNode;
}


void insertStart(struct Node** head,int data){
    struct Node* newNode = createNode(data);
    
    if(*head==NULL){
        *head=newNode;
        return;
    }
    newNode->next=*head;
    (*head)->prev=newNode;
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
    
    newNode->prev=temp;
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
    for(i=1;i<pos-1;i++){
        temp=temp->next;
        
    }
    newNode->next=temp->next;
    temp->next->prev=newNode;
    temp->next=newNode;
    newNode->prev=temp;
}





void delStart(struct Node** head){
    if((*head)->next==NULL){
        free(head);
        return;
    }
    
    *head=(*head)->next;
    free((*head)->prev);
    (*head)->prev=NULL;
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
    temp->next->prev=temp;
    free(temp2);
    
    
}

void inverse(struct Node** head){
    struct Node* prev = NULL;
    struct Node* next = NULL;
    struct Node* current = *head;
    struct Node* temp = NULL;
    
    while(current!=NULL){
        
        next=current->next;
        
        /*swapping*/
        temp=current->next;
        current->next=current->prev;
        current->prev=temp;
        
        prev=current;
        current=next;
    }
    if (prev != NULL) {
        *head = prev;    // Set new head to the last non-NULL node processed
    }
    
    
    
}



    


struct Node* concatLL(struct Node** head1, struct Node** head2)
{
    if(*head1==NULL){
        
        return *head2;
        
    }
    if(*head2==NULL){
        
        return *head1;
        
    }
    struct Node* temp = *head1;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=*head2;
    (*head2)->prev=temp;
    
    
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
