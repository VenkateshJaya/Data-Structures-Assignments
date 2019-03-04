#include<stdio.h>
#include<stdlib.h>

typedef struct nodeType
{
    int data;
    struct nodeType* next;
} Node;

void insertBeg(Node** head, int elem)
{
    Node* temp = malloc(sizeof(Node));
    temp->data = elem;
    temp->next = *head;
    *head = temp;
}

void traverse(Node* head)
{
    if(head == NULL)
    {
        return;
    }
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

Node* merge(Node* l1, Node* l2)
{
    Node* head = NULL;
    Node* temp;
    while((l1) != NULL && (l2) != NULL)
    {
        if((l1)->data > (l2)->data)
        {
            temp = l1;
            l1 = (l1)->next;
        }
        else
        {
             temp = l2;
            l2 = (l2)->next;
        }   
        temp->next = head;
        head = temp;
    }

    while((l1) != NULL)
    {   
        temp = l1;
        l1 = (l1)->next;
        temp->next = head;
        head = temp; 
    }
    while((l2) != NULL)
    {   
        temp = l2;
        l2 = (l2)->next;
        temp->next = head;
        head = temp; 
    }
    return head;
}

int main()
{
    int n, m;
    Node* l1 = NULL, *l2 = NULL;

    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        int temp;
        scanf("%d", &temp);
        insertBeg(&l1, temp);
    }
    scanf("%d", &m);
    for(int i=0;i<m;i++)
    {
        int temp;
        scanf("%d", &temp);
        insertBeg(&l2, temp);
    }

    Node* head = merge(l1, l2);
    traverse(head);
    return 0;
}