/* Simple implementation of the a linked list. 
// TODO ADD DELETE FRONT/BACK
Advantages over storing data in a singly linked list?
	- O(1) deletion of either end of the list. 
		- With this can implement a simple queue with O(1) enqueue and dequeue.

Written by Bryan Elcorrobarrutia.
11/7/2019
*/

#include <stdlib.h>
#include <stdio.h>

#define TEST // undefine this if u don't want to test it in main directly.


// Basic node and linked list structures. 
typedef struct node {
	int key;
	struct node *next;
} node_l;

typedef struct linked_list {
	node_l *head;
	node_l *tail;
} list_l;



void ll_init(list_l *list){
	list->head = NULL;
	list->tail = NULL;
}

int ll_insert_front(list_l *list, int value){
	// Allocate and initialize the new node.
	node_l * new = malloc(sizeof(node_l));
	if (new == NULL){
		perror("malloc");
		return 1; // fail
	}
	new->key = value;
	new->next = list->head;

	if (list->head == NULL){
		list->tail = new;
	}
	list->head = new;

	return 0; //success
}

int ll_insert_back(list_l *list, int value){
	// Allocate and initialize the new node.
	node_l * new = malloc(sizeof(node_l));
	if (new == NULL){
		perror("malloc");
		return 1; // fail
	}
	new->key = value;
	new->next = NULL;
	list->tail->next = new;

	if (list->tail == NULL){
		list->head = new;
	}
	list->tail = new;

	return 0; //success
}



void ll_destroy(list_l * list){
	/* frees all dynamically allocated nodes in linked list if any */
	node_l * curr = list->head;
	node_l * tmp;
	while (curr){
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
}

int ll_lookup(list_l *list, int value){
	/* return 0 if a node with key == value was found in the list, 1 otherwise */
	node_l * curr = list->head;
	while (curr){
		if (curr->key == value) 
			return 0; //success
		curr = curr->next;
	}
	return 1; // fail

}


void ll_print(list_l * list){
	node_l * curr = list->head;
	while (curr){
		printf("%d<->", curr->key);
		curr = curr->next;
	}
	printf("NULL\n");
}

int ll_delete(list_l * list, int value){
	/* O(n) time deletion of the FIRST occurrence of value in node */
	node_l * curr = list->head;

	// if node to be deleted at head of linked list.
	if (list->head && list->head->key == value){
		list->head = list->head->next;
		return 0; // success
	}

	node_l * prev = curr;
	curr = curr->next;

	while (curr){
		if (curr->key == value) {
			prev->next = curr->next;
			return 0; //success
		}
		prev = prev->next;
		curr = curr->next;
	}

	return 1; // fail
}





#ifdef TEST



int main(){
	struct linked_list list;

	ll_init(&list);

	int size = 6;
	for (int i = 0; i < size; i++){
		ll_insert_front(&list, i);
	}

	ll_print(&list);
	ll_insert_back(&list, 12);
	ll_print(&list);
	ll_insert_front(&list, 13);
	ll_print(&list);
	ll_insert_back(&list, 20);
	ll_print(&list);
}

#endif
