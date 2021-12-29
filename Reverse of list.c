#include<stdio.h>

#include<stdlib.h>



struct node{

int data;

struct node *link;

};

struct node* reverse(struct node* head, struct node* prev)

{



if (head == NULL)

return NULL;



struct node* temp;

struct node* c;

c = head;

// Reversing nodes until c node's value

// turn odd or Linked list is fully traversed

while (c != NULL && c->data % 2 == 0) {

temp = c->link;

c->link = prev;

prev = c;

c = temp;

}
// If elements were reversed then head

// pointer needs to be changed

if (c != head) {
head->link = c;

// Recur for the remaining linked list

c = reverse(c, NULL);

return prev;

}

// Simply iterate over the odd value nodes

else {

head->link = reverse(head->link, head);

return head;

}

}

int main(){

int n,Data;


printf("Enter number of nodes  ");

scanf("%d",&n);

struct node *head = malloc(sizeof(struct node));

printf("Enter the data of node %d :",1);

scanf("%d",&Data);

head->data = Data;

head->link = NULL;

struct node *tmp;

tmp = head;

struct node *current;

for(int i=1;i<n;i++){

printf("Enter the data of node %d :",i+1);

scanf("%d",&Data);

current = malloc(sizeof(struct node));

current->data = Data;

current->link = NULL;


tmp->link = current;

tmp = tmp->link;

}

head = reverse(head,NULL);


// Traversing

printf("....Display..... \n");

struct node *ptr;

ptr = head;

while(ptr != NULL){

printf("Value: %d\n",ptr->data);

ptr = ptr->link;

}

return 0;

}
