#include<stdio.h>
#include<stdlib.h>

struct linked_list
{
    int number;
    struct linked_list *next;
    struct linked_list *previous;
};

typedef struct linked_list node;
node *head = NULL, *tail = NULL;

void CreateNode(int number)
{
    node *newNode = (node *) malloc(sizeof(node));

    newNode->number = number;
    newNode->next = newNode;
    newNode->previous = newNode;

    if(head==NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->next = head;
        newNode->previous = tail;
        tail = newNode;
        head->previous = tail;
    }
}

void print_forward_order()
{
    if(head==NULL)  return;

    node *current = head;

    do
    {
        printf("%d ", current->number);
        current = current->next;
    }
    while(current != head);

}

void print_reverse_order()
{
    if(head==NULL)  return;

    node *current = tail;

    do
    {
        printf("%d ", current->number);
        current = current->previous;
    }
    while(current != tail);

}

void InsertNode(int number, int position)
{
    if(position==1)
    {
        insert_at_head(number);
        return;
    }
    else if(position>1 && head!=NULL)
    {
        node *current = head;
        node *temp = (node *) malloc(sizeof(node));
        int count = 0;

        do
        {
            count++;
            temp = current;
            current = current->next;
        }
        while(current->next != head && count<position-1);

        if(count==position-1)
        {
            if(temp==tail)
                insert_at_tail(number);
            else
            {
                node *newNode = (node *) malloc(sizeof(node));
                newNode->number = number;

                temp->next = newNode;
                newNode->next = current;
                newNode->previous = temp;
                current->previous = newNode;

            }
            return;
        }

    }

    printf("Position does not exist!\n");
}

void delete_head()
{
    if(head==NULL)  return;

    node *temp = head;

    tail->next = head->next;
    head = head->next;
    head->previous = tail;

    free(temp);
}

void delete_tail()
{
    if(head==NULL)  return;

    node *temp = head;
    node *current = head;

    while(current->next != head)
    {
        temp = current;
        current = current->next;
    }

    temp->next = head;
    tail = temp;
    head->previous = tail;
    free(current);
}

void insert_at_head(int number)
{
    node *newNode = (node *) malloc(sizeof(node));

    newNode->number = number;
    newNode->next = newNode;
    newNode->previous = newNode;

    if(head==NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        newNode->previous = tail;
        head->previous = newNode;
        tail->next = newNode;
        head = newNode;
    }

}

void insert_at_tail(int number)
{
    node *newNode = (node *) malloc(sizeof(node));

    newNode->number = number;
    newNode->next = newNode;
    newNode->previous = newNode;

    if(head==NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->next = head;
        newNode->previous = tail;
        tail = newNode;
        head->previous = tail;
    }
}


void DeleteNode(int position)
{
    if(head==NULL)  return;

    if(position==1)
    {
        delete_head();
        return;
    }

    node *current = head;
    node *temp;
    int count = 0;

    do
    {
        count++;
        temp = current;
        current = current->next;
    }
    while(current->next != head && count<position-1);

    if(count==position-1)
    {
        if(current==tail)
        {
            delete_tail();
            return;
        }

        temp->next = current->next;
        current->next->previous = temp;
        free(current);
        return;
    }

    printf("Position (%d) does not exist!", position);
}

void PrintList()
{
    printf("\nFORWARD order print:");
    print_forward_order();

    printf("\nREVERSE order print:");
    print_reverse_order();
}

int main()
{
    int i,num,data,position;

    printf("Enter total number of nodes to be created:");
    scanf("%d",&num);
    for(i=0; i<num; i++)
    {
        printf("\nEnter element to be added:");
        scanf("%d",&data);
        CreateNode(data);
    }
    PrintList();

    printf("\nEnter position of element of insertion");
    scanf("%d",&position);
    printf("Enter data");
    scanf("%d",&data);
    InsertNode(data, position);
    PrintList();

    printf("\nEnter position of element of deletion");
    scanf("%d",&position);
    DeleteNode(position);
    PrintList();

    return 0;
}
