
#include<stdio.h>

#define SIZE 5
int stack[SIZE];
int top=-1;


void push(int value){
    if (top==SIZE-1){
        printf("stack overflow!%d\n",value); }
        else{
            top=top+1;
            stack[top]=value;
            printf("%d pushed into the stack.\n",value); }
        }

void pop(){
    if(top==-1){
        printf("stack underflow!\n");}
    else{
        printf("%d poped from the stack.\n",stack[top]);
        top=top-1;
    }
}


void display(){
    if(top==-1){
        printf("stack is empty"); }
    else{
        printf("stack elements are: \n");
        for(int i=top;i>=0;i--){
            printf("%d \n",stack[i]);
        }
    }
}

int main(){
    int choice,value;
    while(1){
        printf("\n____stack operations____\n");
        printf("1.push \n 2.pop \n 3.display \n 4.exit\n\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        printf("Enter element to push: ");
        scanf("%d",&value);
        push(value);
        break;

        case 2:
        pop();
        break;

        case 3:
        display();
        break;

        case 4:
        printf("Exiting program...");
        exit(0);

        default:
        printf("Choose something from the list dude! :o");
            break;
        }
    }
}
