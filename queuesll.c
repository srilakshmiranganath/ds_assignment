#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
} *front = NULL, *rear = NULL;

void enqueue(int element){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = element;
    newNode -> next = NULL;
    if(front == NULL){
        front = newNode;
        rear = newNode;
    }

    else{
        rear -> next = newNode;
        rear = newNode;
    }
}

int dequeue(){
    struct node *ptr = front;
    while(ptr -> next != NULL)
        ptr = ptr -> next;
    int del = rear -> data;
    rear = ptr;
    return del;
}

void display(){
    struct node *ptr = front;
    printf("The queue is : ");
    while(ptr != NULL){
        printf(" %d ", ptr -> data);
        ptr = ptr -> next;
    }
}

void main(){
    int choice;
    while (1){    
        printf("Choode from the following : \n");
        printf("1. Enqueue \n 2. Dequeue \n 3. Display queue \n 4. Exit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch ((choice))
        {
        case 1:{
            int element;
            printf("Enter element to add : ");
            scanf("%d", &element);
            enqueue(element);
            break;
            }
        case 2:{
            int del = dequeue();
            printf("Deleted element is : %d\n", del);
            break;
        }
        case 3: {
            display();
            break;
        }
        case 4: {
            exit(0);
        }
        
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}