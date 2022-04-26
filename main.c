#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
   int data;
   int key;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

//display the list
void printList() {
   struct node *ptr = head;
   printf("\n[ ");
	
   //start from the beginning
   while(ptr != NULL) {
      printf("(%d,%d) ",ptr->key,ptr->data);
      ptr = ptr->next;
   }
	
   printf(" ]");
}

//insert link at the first location
void insertFirst(int key, int data) {
   struct node *link = (struct node*) malloc(sizeof(struct node));
	
   link->key = key;
   link->data = data;

   link->next = head;

   head = link;
}

//delete first item
struct node* deleteFirst() {

   struct node *tempLink = head;

   head = head->next;

   return tempLink;
}

//is list empty
bool isEmpty() {
   return head == NULL;
}

int length() {
   int length = 0;
   struct node *current;
	
   for(current = head; current != NULL; current = current->next) {
      length++;
   }
	
   return length;
}

//find a link with given key
struct node* find(int number) {
   struct node* current = head;
   while (current != NULL) {
       if (current->key == number)
           return current;
       current = current->next;
   }
   return NULL;
}

//delete a link with given key
struct node* delete(int index){
    struct node* current  = head;
    struct node* next = head->next;
    for (int i = 0; i < index-1; i++)
    {
        current = current->next;
        next = next->next;
    }
    current->next = next->next;
    free(next);
    return head;
}

void sort() {
    int i, j, k, tempKey, tempData;
    struct node *current;
    struct node *next;
    int size = length();
    k = size;
    for ( i = 0 ; i < size - 1 ; i++, k-- ) {
        current = head;
        next = head->next;
        for ( j = 1 ; j < k ; j++ ) {
            if ( current->data > next->data ) {
                tempData = current->data;
                current->data = next->data;
                next->data = tempData;

                tempKey = current->key;
                current->key = next->key;
                next->key = tempKey;
            }
            current = current->next;
            next = next->next;
        }
    }
}

void reverse() {
    struct node* previous = NULL;
    struct node* current = head;
    while (current != NULL)
    {
        struct node* next = current->next;
        current->next = previous;

        previous = current;
        current = next;
    }

    head = previous;
}

int main() {
   insertFirst(1,10);
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,1);
   insertFirst(5,40);
   insertFirst(6,56); 

   printf("Original List: "); 
	
   //print list
   printList();

   while(!isEmpty()) {            
      struct node *temp = deleteFirst();
      printf("\nDeleted value:");
      printf("(%d,%d) ",temp->key,temp->data);
   }  
	
   printf("\nList after deleting all items: ");
   printList();
   insertFirst(1,10);
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,1);
   insertFirst(5,40);
   insertFirst(6,56);
   
   printf("\nRestored List: ");
   printList();
   printf("\n");  

   struct node *foundLink = find(4);
	
   if(foundLink != NULL) {
      printf("Element found: ");
      printf("(%d,%d) ",foundLink->key,foundLink->data);
      printf("\n");  
   } else {
      printf("Element not found.");
   }

   delete(4);
   printf("List after deleting an item: ");
   printList();
   printf("\n");
   foundLink = find(4);
	
   if(foundLink != NULL) {
      printf("Element found: ");
      printf("(%d,%d) ",foundLink->key,foundLink->data);
      printf("\n");
   } else {
      printf("Element not found.");
   }
	
   printf("\n");
   sort();
	
   printf("List after sorting the data: ");
   printList();
	
   reverse();
   printf("\nList after reversing the data: ");
   printList();
   return 0;
}