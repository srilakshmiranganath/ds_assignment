#include<stdio.h>
#include<stdlib.h>
# define max_size 10
int stack[max_size];
int top = -1;

int stackfull(){
    if(top>=max_size){
        return 1;
    }
    else{
        return 0;
    }
}

int stackempty(){
    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void stackPush(int element){
    if(stackfull()){
        printf("Stack full\n");
    }
    else{
        top++;
        stack[top] = element;
    }
}

int stackPop(){
    int element;
    if(stackempty()){
        printf("Stack empty\n");
    }
    else{
        element = stack[top];
        top--;
        printf("Popped element : %d\n",element);
    }
}

int stackPeek(){
    if(stackempty()){
        printf("Stack empty\n");
    }
    else{
        printf("Top element is %d\n", stack[top]);
    }
}

void stackDisplay(){
    if(stackempty()){
        printf("Stack empty\n");
    }
    else{
        for(int i=top;i>=0;i--){
            printf(" %d \n",stack[i]);
        }
    }
}

int main(){
    int choice, element;

    while(1){
        printf("1. push\n 2. pop\n 3. peek\n 4.display\n");
        printf("Enter choice : ");
        scanf("%d", &choice);

        if(choice==1){
            printf("Enter element to push : ");
            scanf("%d",&element);
            stackPush(element);
        }

        else if(choice==2){
            stackPop();
        }

        else if(choice==3){
            stackPeek();
        }

        else if(choice==4){
            stackDisplay();
        }

        else{
            printf("Invalid choice\n");
            break;
        }
    }
}