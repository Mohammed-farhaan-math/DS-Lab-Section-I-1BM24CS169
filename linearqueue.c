#include <stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int front=-1;
int rear=-1;
void insert(int ele)
{
if(rear==MAX-1){printf("Overflow\n");}
else
    {
        if (front==-1)
            {
                front=0;
            }
        rear++;
        queue[rear]=ele;
        printf("Inserted %d\n",ele);
    }
}
void delete()
{
    if(front==-1||front >rear)
    {
     printf("Underflow\n"); front=-1; rear=-1;
    }
    else
        {
            printf("Deleted %d\n",queue[front]);
            front++;
            if(front>rear)
                {
                    front=-1;
                    rear=-1;

                }
        }


}

void display()
{
    if(front==-1)
        {
            printf("Empty Queue\n");

        }
    else
        {
            printf("Queue elemenets:\n");
            for(int i =front;i<=rear;i++)
                {
                    printf("%d \n",queue[i]);
                }
        }

}
int main()
{
    int choice,val;
    do
        {
            printf("Enter your choice\n");
            scanf("%d",&choice);
            switch(choice)

            {
            case 1:
                printf("Enter digit to insert\n");
                scanf("%d",&val);
                insert(val);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exit Program\n");
                break;
            default:
                printf("Invalid\n");


            }
        }
    while(choice!=4);
    return 0;

}

