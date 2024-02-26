#include <stdio.h>
#include <stdlib.h>
//Hector Moreno
//Chapter 4 PA

// struct to hold the data and pointer of a node
struct node {
	int data;
	struct node *next;
} 	node;

// pointers to the head node
struct node *head = NULL;

// Function to perform the same list operation as the pseudocode found in section 4.2.5
void listPrepend(int data){

	//create a link
	struct node *lk = (struct node*) malloc(sizeof(struct node));
	lk->data = data;

	// point it to old first node
	lk->next = head;

	//point first to new first node
	head = lk;
}

// Function to perform the same list operation as the pseudocode found in section 4.2.3
void listAppend(int data){
	if (head == NULL) { // list is empty
		listPrepend(data);
	} else {
		//create a link
		struct node *lk = (struct node*) malloc(sizeof(struct node));
		lk->data = data;
		struct node *linkedlist = head;

		// point it to old first node
		while(linkedlist->next != NULL) {
			linkedlist = linkedlist->next;
		}
   
		//point first to new first node
		linkedlist->next = lk;
	}
}

// Function to perform the same list operation as the pseudocode found in section 4.3.1
void listInsertAfter(struct node *list, int data){
	struct node *lk = (struct node*) malloc(sizeof(struct node));
	lk->data = data;
	lk->next = list->next;
	list->next = lk;
}

// Function to perform the same list operation as the pseudocode found in section 4.4.1
// Function removes the node that is passed in, not the next node
void listRemoveNode(int key){
	struct node *temp = head, *prev;
	if (temp != NULL && temp->data == key) {
		head = temp->next;
		return;
	}

	// Find the key to be deleted
	while (temp != NULL && temp->data != key) {
		prev = temp;
		temp = temp->next;
	}

	// If the key is not present
	if (temp == NULL) return;

	// Remove the node
	prev->next = temp->next;
}

// Function to perform the same list operation as the pseudocode found in section 4.5.1
// Function will return a 1 if found or 0 if not found
int listSearch(int key){
	struct node *temp = head;
	while(temp != NULL) {
		if (temp->data == key) {
			return 1;
		}
		temp=temp->next;
	}
	return 0;
}

//Function to perform the same list operation as the  pseudocode found in section 4.9.1
void listTraverse(){
	struct node *p = head;
	printf("\nThe list order is: ");

	//start from the beginning
	while(p != NULL) {
		printf("%d ",p->data);
		p = p->next;
	}
}

// Implement sumDataValues method
int sumDataValues(struct node* head) {
    int sum = 0;
    struct node* current = head;

    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }
    
    return sum;
}

int main(){
	listAppend(1);//Append 1
	listAppend(2);//Append 2
	listPrepend(3);//Prepend 3
	listInsertAfter(head, 4);//Insert 4 after the head
	listAppend(5); //insert 5 at end of list
	listInsertAfter(head->next, 6); //insert 6 after 4
	listInsertAfter(head->next->next->next->next, 7); //insert 7 after 2
	listTraverse();//print list
	
	listRemoveNode(3); //remove head
	listRemoveNode(5); //remove 5
	
	listTraverse();//print list
	
	printf("\nNode with data 5 was %s", listSearch(5) ? "found." : "not found.");//Search for 5 and display if found or not
    	printf("\nNode with data 2 was %s", listSearch(2) ? "found." : "not found.");//Search for 2 and display if found or not
    	
    	int result = sumDataValues(head);
    	printf("\nThe sum of the linked list data values is %d\n", result);//Print sum of list
	
	return 0;
}
