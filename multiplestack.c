#include<stdio.h>
#define size 10

int stack[size];
int top1 = -1, top2 = size;

void stackPush(int stacknum, int element){
    if(stacknum == 1){
        if(top1 == top2-1){
            printf("Stack full\n");
        }
        else{
            top1++;
            stack[top1] = element;
        }
    }

    else if(stacknum == 2){
        if(top2 == top1+1){
            printf("Stack full\n");
        }
        else{
            top2--;
            stack[top2] = element;
        }
    }
}

void stackPop(int stacknum){
    int popEl;
    if(stacknum == 1){
        if(top1 == -1){
            printf("Stack empty\n");
        }
        else{
            popEl = stack[top1];
            printf("Popped element : %d\n", popEl);
            top1--;
        }
    }

    else if(stacknum == 2){
        if(top2 == size){
            printf("Stack empty\n");
        }
        else{
            popEl = stack[top2];
            printf("Popped element : %d\n", popEl);
            top2++;
        }
    }
}

void stackPeek(int stacknum){
    if(stacknum == 1){
        if(top1 == -1){
            printf("Stack empty\n");
        }
        else{
            printf("Stack 1 top element : %d\n", stack[top1]);
        }
    }

    else if(stacknum == 2){
        if(top2 == size){
            printf("Stack empty\n");
        }
        else{
            printf("Stack 2 top element : %d\n", stack[top2]);
        }
    }
}

void stackDisplay(int stacknum){
        if(stacknum == 1){
        if(top1 == -1){
            printf("Stack empty\n");
        }
        else{
            printf("Stack 1 elements : \n");
            for(int i=top1;i>=0;i--){
                printf(" %d ", stack[i]);
            }
            printf("\n");
        }
    }

    else if(stacknum == 2){
        if(top2 == size){
            printf("Stack empty\n");
        }
        else{
            printf("Stack 2 elements : \n");
            for(int i=size-1;i>=top2;i--){
                printf(" %d ",stack[i]);
            }
            printf("\n");
        }
    }
}

int main(){
    int choice, element, stacknum;

    while(1){
        printf("1. push\n 2. pop\n 3. peek\n 4.display\n");
        printf("Enter choice : ");
        scanf("%d", &choice);

        if(choice==1){
            printf("Enter which stack to push to : ");
            scanf("%d", &stacknum);
            if(stacknum==1 || stacknum==2){
                printf("Enter element to push : ");
                scanf("%d",&element);
                stackPush(stacknum, element);
                
            }
            else{
                printf("No such stack\n");
            }
        }

        else if(choice==2){
            printf("Enter which stack to pop from : ");
            scanf("%d", &stacknum);
            if(stacknum==1 || stacknum==2){
                stackPop(stacknum); 
            }
            else{
                printf("No such stack\n");
            }
        }

        else if(choice==3){
            printf("Enter which stack to peek : ");
            scanf("%d", &stacknum);
            if(stacknum==1 || stacknum==2){
                stackPeek(stacknum);
            }
            else{
                printf("No such stack\n");
            }
        }

        else if(choice==4){
            printf("Enter which stack to display : ");
            scanf("%d", &stacknum);
            if(stacknum==1 || stacknum==2){
                stackDisplay(stacknum);
            }
            else{
                printf("No such stack\n");
            }
        }

        else{
            printf("Invalid choice\n");
            break;
        }
    }
}

