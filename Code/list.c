#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "list.h"

//struct node defition
struct node {
   char *data;
   int key;
   struct node *next;
   
};
struct node* head;

//display the list
void printList() {
   struct node *ptr = head;        		//ptr pointer, starting from head to end
   printf("\n[ ");
   
   //start from the beginning
   while(ptr != NULL) {
      if(ptr->key<32){
      printf("(%d) %s\n",ptr->key,ptr->data);}
      ptr = ptr->next;
}
   
   printf(" ]");
}

//insert link at the first location
void insertFirst(int key, char data[]) {
   struct node *link = (struct node*) malloc(sizeof(struct node));
   int i = 0;
   while(data[i] != 'd'){
      printf("%c",data[i]);
      i++;
   }
   link->key = key;
  // link->data = data;
  // printf("%c",link->data);
   
   //point it to old first node
   if(head==NULL){
      head = link;  
   }
   else{
         link->next = head;
         head=link;
   }
   
   //point first to new first node
}


//delete first item
struct node* deleteFirst() {

   //save reference to first link
   struct node *tempLink = head;
   
   //mark next to first link as first 
   head = head->next;
   
   //return the deleted link
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
struct node* find(int key) {

   //start from the first link
   struct node* current = head;

   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->key != key) {
	
      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //go to next link
         current = current->next;
      }
   }      
	
   //if data found, return the current Link
   printf("%d - %s\n",current->key, current->data );
   return current;
      
   
}


struct node* deleteNode(int key){

   //start from the first link
   struct node* previous = NULL;
   struct node* current = NULL;
   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   current = head;
   while(current->key != key) {

      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //store reference to current link
         previous = current;
         //move to next link
         current = current->next;
      }
   }

   //found a match, update the link
   if(current == head) {
      //change first to point to next link
      head = head->next;
   } else {
      //bypass the current link
      previous->next = current->next;
   }    
   return current;
}
//create function, creating head equals to NULL
void create(){
   head = NULL;
}

//add function, adding food list to linked list
void add(char *food){
   struct node *temp = (struct node*) malloc(sizeof(struct node));   //creating a node to insert
   temp->data = NULL;
   temp->key = 0;
   temp->next = NULL;
   if(head == NULL){                                    // if list is empty, then make the node first element, head
      temp->key = 1;
      temp->data = strdup(food);			//for taking string correctly
      head = temp;
   }
   else{// if list's node > 1, then go to end of the list and add the upcoming node
      struct node *traverse;  //traverse node for moving around in linked list
      traverse = head;	
      int i=0;
      while(traverse != NULL){			//getting list length for clarification of key
         traverse = traverse->next;
         i++;
      }
      temp->key = i+1;
      temp->data = strdup(food);
      temp->next = NULL;
      traverse = head;
      while(traverse->next != NULL){              // go to end of the list and add the day
         traverse = traverse->next;
      }
      traverse->next = temp;
   }
}
