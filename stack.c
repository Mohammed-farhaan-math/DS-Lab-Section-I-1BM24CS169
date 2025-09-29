#include <stdio.h>
#define size 5
int stack[size];
int top = -1;

void push(int element)
{
    if( top==size-1)
        {
        printf(" STACK OVERFLOW\n");
        }
    else
        {
            top=top+1;
            stack[top]=element;
        }
}
void pop()
{
    if(top==-1)
        {
            printf(" STACK UNDERFLOW\n");
        }
    else
    {
    top=top-1;
    }
}

void display()
{
if (top==-1) {printf("stack is empty");}
else
{
 printf("stack is:\n");
 for(int i=top;i>=0;i--)
 {
    printf("%d \n",stack[i]);
 }
}

}
int main()
{
    int choice,element;
    while(1)
    {
        printf("Stack operations \n 1.push \n 2.pop \n 3.display");
        scanf("%d",choice);
    switch(choice)
    {
case 1:
    printf("Enter element to push");
    scanf("%d",&element);
    push(element);
    break;
case 2:
    pop();
    break;
case 3:
    display();
    break;
case 4:
    exit(0);
default:
    printf("select a valid operation");
    }
}

}

mohammedfarhaan.cs24@bmsce.ac.in
