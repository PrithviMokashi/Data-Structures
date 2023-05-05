#include<stdio.h>
#include<iostream>
#include<string.h>

struct node
{
    int data;
    struct node *next;
};

struct node *push(struct node *, int);
struct node *pop(struct node *);
void display(struct node *);

struct node *top;

int main()
{
    struct node *top = NULL;
    char input;
    int value;
    std::cout << """Operation List:\nP/p - Push\nO/o - Pop\nD/d - Display\nE/e - Exit\n\n""";
    do
    {
        std::cout << "Enter your Choice: ";
        do 
        {
            input = getchar();
        }while(strchr("PpOoDdEe", input)==NULL);
        switch(input)
        {
            case 'P':
            case 'p':
                std::cout << "Enter a data: ";
                std::cin >> value;
                top=push(top, value);
                display(top);
                break;

            case 'O':
            case 'o':
                top=pop(top);
                display(top);
                break;
            
            case 'D':
            case 'd':
                display(top);
                break;

        }
    } while (input != 'E' && input != 'e');
    return 0;
}

struct node *push(struct node *top, int item)
{
    struct node *newNode;
    newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=item;
    newNode->next=top;
    top=newNode;
    return top;
}

struct node *pop(struct node *top)
{
    if(top != NULL)
    {
        struct node *temp = top;
        int tmp = top->data;
        top = top->next;
        free(temp);
        std::cout << "\nPopped " << tmp << '\n';
        return top;
    }
    return top;
}

void display(struct node *top)
{
    if(top!=NULL) 
    {
        std::cout << "\n   <= TOP\n";
    } else {
        std::cout << "\nStack is Empty!\n";
    }
    for(;top!=NULL;top=top->next)
    {
        std::cout << "| " << top->data << " |\n";
        std::cout << "|___|\n";
    }
    std::cout << "\n";
}