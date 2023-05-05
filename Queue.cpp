#include <string.h>
#include <stdio.h>
#include <iostream>

struct node
{
    int data;
    struct node *next;
};

struct node *push(struct node *, int);
struct node *pop(struct node *);
void display(struct node *);

struct node *front;

int main()
{
    struct node *front = NULL;
    char input;
    int value;
    std::cout << """Operation List:\nP/p - Queue\nO/o - Dequeue\nD/d - Display\nE/e - Exit\n\n""";
    do
    {
        std::cout << "Enter your Choice: ";
        do{
            input=getchar();
        }while(strchr("PpOoEeDd", input)==NULL);
        switch(input)
        {
            case 'P':
            case 'p':
                std::cout << "Enter a data: ";
                std::cin >> value;
                front=push(front, value);
                display(front);
                break;

            case 'O':
            case 'o':
                front=pop(front);
                display(front);
                break;

            case 'D':
            case 'd':
                display(front);
                break;
        }
    } while (input != 'E' && input != 'e');
    return 0;
}

struct node *push(struct node *front, int value)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=front;
    front=newnode;
    return front;
}

struct node *pop(struct node *front)
{
    if(front!=NULL)
    {
        struct node *temp = front;
        int tmp=front->data;
        front = front->next;
        free(temp);
        std::cout << "\nPopped " << tmp << '\n';
        return front;
    }
    return front;
}

void display(struct node *fornt)
{
    if(fornt==NULL) 
    {
        std::cout << "\nQueue is Empty!\n";
    } else {
        std::cout << "\n";
        for(;fornt!=NULL;fornt=fornt->next)
        {
            std::cout << " " << fornt->data << " |";
        }
        std::cout << " <= FRONT\n\n";
    }
}