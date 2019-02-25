#include <bits/stdc++.h>
using namespace std;
#define N 100001
int n;
char s[2];
typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
}node;
node* new_node1; 
node* node12 ;
int x, k, len;
node* t;
node* temp;
node* head = NULL;
void print(node *hd)
{  
    int i = 0;
    node* te;
    te = hd;
    //printf("\n");
    while(te != NULL && i <= len)
    {
        printf("%d ", te->data);
        te = te->next;
        i++;
    }
    printf("\n");
}

void doubly()
{
    printf("Enter numbers. Alphabet to stop.\n");
    while(1)
    {
        scanf("%d", &x);
        if(x == -1)
            break;
        t = (node*) malloc(sizeof(node));
        len++;
        if(head == NULL)
        {
            head = t;
            head->data = x;
            head->next = NULL;
            head->prev = NULL;
        }
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = t;
        t->prev = temp;
        t->next = NULL;
        t->data = x;
    }
    print(head);
}
node* create_node()
{
    node * node1 = (node*) malloc(sizeof(node));
    return node1;
}
void insert(int j)
{
    node * node = head;
    
    while(node !=NULL)
    {
        if(j < node->data )
        {
            new_node1 = create_node();
            if(node == head)
            {
                new_node1->prev=NULL;
                new_node1->next=head;
                head->prev=new_node1;
                new_node1->data=j;
                head = new_node1;
                len++;
                break;
            }
            else
            {
                new_node1->next=node;
                new_node1->prev=node->prev;
                (node->prev)->next = new_node1;
                node->prev= new_node1;
                new_node1->data = j;
                len++;
                break;
            }
        }
        else
            node=node->next;
    }
    if(node == NULL)
    {
        new_node1= create_node();
        new_node1->data=j;
        t->next=new_node1;
        new_node1->next=NULL;
        new_node1->prev=t;
        t=new_node1;
        len++;  
    }
    //print(head);
}
void del(int j)
{
    node* current;
    node * node = head;
    while(node !=NULL)
    {
        if(j == node->data )
        {  
            if(node == head)
            {
                current = node->next;
                current->prev=NULL;
                head= current;
                len--;
                break;
            }
            else
            {
                if(node->next != NULL)
                {
                    current = node->prev;
                    current->next=node->next;
                    (node->next)->prev= current;
                    len--;
                    break;
                }
                else if(node->next == NULL)
                {
                    current = node->prev;
                    current->next = NULL;
                    len--;
                    t=current;
                    break;
                }
            }
        }
        else
            node=node->next;
    }
    
    //print(head);

}
void swap(int j , int k)
{
    node* current = head;
    while(current != NULL)
    {
        if(current->data == j)
        {
            current->data=k;
            break;
        }
        else
            current=current->next;
    }
    current= t;
    while(current!=NULL)
    {
        if(current->data == k)
        {
            current->data = j;
            break;
        }
        else
            current=current->prev;
    } 
    //print(head);  
}
void bubbleSort(node *start) 
{ 
    int swapped, i; 
    node *ptr1; 
    node *lptr = NULL; 
    if (start == NULL) 
        return; 
    do
    { 
        swapped = 0; 
        ptr1 = start; 
        while (ptr1->next != lptr) 
        { 
            if (ptr1->data > ptr1->next->data) 
            {  
                swap(ptr1->data, (ptr1->next)->data); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
}
int main()
{
    doubly();
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int j,k;
        scanf("%s",s);
        if(s[0]=='I')
        {
            scanf("%d",&j);
            insert(j);
            print(head);
        }
        else if((s[0]=='D'))
        {
            scanf("%d",&j);
            del(j);
            print(head);
        }
        else if(s[0]=='S' && s[1]=='W')
        {
            scanf("%d %d",&j,&k);
            swap(j,k);
            print(head);
        }
        else if(s[0]=='S' && s[1]=='O')
        {
            bubbleSort(head);
            print(head);
        }
    }
}