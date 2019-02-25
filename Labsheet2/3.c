#include<stdio.h>
struct Node 
{ 
  int data; 
  struct Node *next; 
}; 

int main(){
    struct Node *head = NULL;
    struct Node *temp = NULL;
    struct Node *first = NULL; 
    int count =0;
    int choice = 1;
    first = 0;
    int k;
    printf("Enter k: ");
    scanf("%d",&k);
    
    while(choice!=-1){
        head = (struct Node*)malloc(sizeof(struct Node*));
        printf("Enter Data: ");
        scanf("%d",&choice);
        head->data = choice;
        if(first!=0){
            temp->next = head;
            temp = head;
        }else
        {
            first = temp = head;
        }
        count++;
    }
    
    temp->next = 0;
    temp = first;
    int i=1;
    count = 1;
    int store[1000];
    int j =0;
    struct Node *head_new = NULL;
    struct Node *temp_new = NULL;
    struct Node *first_new = NULL;
    while (temp != 0)
    {
        if(count == k*i){
            // printf("=>%d", temp->data);
            head_new = (struct Node*)malloc(sizeof(struct Node*));
            head_new->data = temp->data;
            if(i == 1){
                // printf("=>%d", temp->data);
                first_new = temp_new = head_new;
            }else
            {
                // printf("=>%d", temp->data);
                temp_new->next = head_new;
                temp_new = head_new;
            }
                // printf("=>%d", temp->data);
                i++;
        }else
        {
            store[j++] = temp->data;
        }
        
        count++;
        temp = temp -> next;
    }
    j = j-2;
    while(j>=0){
        head_new = (struct Node*)malloc(sizeof(struct Node*));
        head_new->data = store[j--];
        temp_new->next = head_new;
        temp_new = head_new;
        // printf("=>%d",store[j--]);
    }
    temp_new->next = 0;
    temp_new = first_new;
    i=1;
    count = 1;
    while (temp_new!= 0)
    {
        printf("%d ", temp_new->data);
        temp_new = temp_new-> next;
    }
    
    


    free(head);
    free(first);
    free(temp);
    free(head_new);
    free(first_new);
    free(temp_new);
    
    return 0;
}