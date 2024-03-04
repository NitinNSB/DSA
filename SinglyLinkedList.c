#include<stdio.h>
#include<stdlib.h>
struct node{
    int content;
    struct node* next;
};

struct node* addDataToList(struct node* head,int data);

struct node* insertBegnning(struct node* head,int data);

void printReverse(struct node* head);

void main(){
    struct node *head;
    head=NULL;
    head=insertBegnning(head,5);
    head=insertBegnning(head,6);
    head=insertBegnning(head,7);
    printReverse(head);
    
}
//function to insert data into the list at the begnning.
struct node* insertBegnning(struct node* head,int data){
    struct node* temp=head;
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->content=data;
    newNode->next=temp;
    return newNode;
}

//function to insert data into the list at the Last.

struct node* addDataToList(struct node* head,int data){
    struct node* jump;
    if(head==NULL){
        head=(struct node*)malloc(sizeof(struct node));
        head->content=data;
        head->next=NULL;
        return head;
    }
    else{
        jump=head;
        while(jump->next!=NULL){
            jump=jump->next;
        }
        jump->next=(struct node*)malloc(sizeof(struct node));
        jump->next->content=data;
        jump->next->next=NULL;
        return head;
    }
}
//Function to print linked list data in reverse order

void printReverse(struct node* head){
    struct node* temp=head;
    struct node* temp2=head;
    int count=0;
    if(head==NULL){
        printf("No node\n");
    }
    else{
        printf("Before reversing\n");
        for(int i=0;temp!=NULL;i++){
            printf("%d\n",temp->content);
            temp=temp->next;
            count++;
        }

        int *arr;
        arr=(int*)malloc(sizeof(int)*count);
        
        for(int i=0;temp2!=NULL;i++){
            arr[i]=temp2->content;
            temp2=temp2->next;
        }

        printf("After reversing\n");

        for(int i=count-1;i>=0;i--){
            printf("%d\n",arr[i]);
        }
        free(arr);
    }
    
}