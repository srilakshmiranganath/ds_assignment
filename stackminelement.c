#include<stdio.h>
#define size 10

int stack[size], aux_stack[size];
int top = -1, aux_top = -1;

void stackPush(int element){
    if(top == size){
        printf("Stack full\n");
    }
    else{
        top++;
        stack[top] = element;
    }
}

int main(){
    int choice=1, element;
    while(choice == 1){
    printf("Enter element to push : ");
    scanf("%d", &element);
    stackPush(element);
    if(aux_top == -1){
        aux_top++;
        aux_stack[aux_top] = element;
    }
    else if(aux_stack[aux_top] >= element){
        aux_stack[aux_top] = element;
    }
    
    printf("Push one more element ? (1->yes, 0->no)");
    scanf("%d", &choice);
    }
    printf("%d", aux_stack[aux_top]);
    printf("Minimum element is : %d\n", aux_stack[aux_top]);
}