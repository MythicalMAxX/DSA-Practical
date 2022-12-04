#include <stdio.h>

struct node
{
    int data;
    struct node *previous;
    struct node *next;
};


struct node *head, *tail = NULL;


void CreateAndInsert()
{
    int data,num;
    printf("Total Numbers of elements to be added:");
    scanf("%d",&num);
    while(num>1)
    {
        printf("Enter data:");
        scanf("%d",&data);
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = data;


        if(head == NULL)
        {

            head = tail = newNode;

            head->previous = NULL;

            tail->next = NULL;
        }
        else
        {

            tail->next = newNode;

            newNode->previous = tail;

            tail = newNode;

            tail->next = NULL;
            num= num-1;
        }
    }
}

void display()
{

    struct node *current = head;
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Nodes of doubly linked list: \n");
    while(current != NULL)
    {

        printf("%d ", current->data);
        current = current->next;
    }
}

void DeleteNode()
{
    struct node *ptr, *temp;
    int val;
    printf("Enter the index value");
    scanf("%d",&val);
    temp = head;
    while(temp -> data != val)
        temp = temp -> next;
    if(temp -> next == NULL)
    {
        printf("Failed to delete Node");
    }
    else if(temp -> next -> next == NULL)
    {
        temp ->next = NULL;
        printf("Node DeletedSuccessfully");
    }
    else
    {
        ptr = temp -> next;
        temp -> next = ptr -> next;
        ptr -> next -> previous = temp;
        free(ptr);
        printf("Node Deleted");
    }
}

int main()
{
    CreateAndInsert();
    display();
    DeleteNode();
    display();

    return 0;
}

