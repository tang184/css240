
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"

//
// Initialize a linked list
//
void llist_init(LinkedList * list)
{
	list->head = NULL;
}

//
// It prints the elements in the list in the form:
// 4, 6, 2, 3, 8,7
//
void llist_print(LinkedList * list) {
	
	ListNode * e;

	if (list->head == NULL) {
		printf("{EMPTY}\n");
		return;
	}

	printf("{");

	e = list->head;
	while (e != NULL) {
		printf("%d", e->value);
		e = e->next;
		if (e!=NULL) {
			printf(", ");
		}
	}
	printf("}\n");
}

//
// Appends a new node with this value at the beginning of the list
//
void llist_add(LinkedList * list, int value) {
	// Create new node
	ListNode * n = (ListNode *) malloc(sizeof(ListNode));
	n->value = value;
	
	// Add at the beginning of the list
	n->next = list->head;
	list->head = n;
}

//
// Returns true if the value exists in the list.
//
int llist_exists(LinkedList * list, int value) {
	ListNode * e = list->head;
	while (e != NULL) {
		if (e->value == value) {
			return 1;
		}
		e = e->next;
	}
	return 0;
}

//
// It removes the entry with that value in the list.
//
int llist_remove(LinkedList * list, int value) {
	ListNode *e = list->head;
	while (e->next != NULL) {
		if (e->next->value == value) {
			e->next = e->next->next;
			return 1;
		}

		e = e->next;
	}
	return 0;

}

//
// It stores in *value the value that correspond to the ith entry.
// It returns 1 if success or 0 if there is no ith entry.
//
int llist_get_ith(LinkedList * list, int ith, int * value) {
	ListNode *e = list->head;
	int i = 0;
	for (i = 0; e != NULL && i < ith; i++) {
		e = e->next;
	}

	if (e == NULL) {
		return 0;
	} else {
		*value = e->value;
		return 1;
	}

}

//
// It removes the ith entry from the list.
// It returns 1 if success or 0 if there is no ith entry.
//
int llist_remove_ith(LinkedList * list, int ith) {
	ListNode * e;
		e = list->head;
		int i = 0;
		int j = 0;
		while (e != NULL) {
			if (i == ith - 1) {
				e->next = e->next->next;
				e = e->next;
				j = 1;
			} else {
				e = e->next;
			}
			i++;
		}
		return j;
}

//
// It returns the number of elements in the list.
//
int llist_number_elements(LinkedList * list) {
	ListNode *e = list->head;
	int i = 0;
	while (e != NULL) {
		e = e->next;
		i++;
	}
	return i;
}


//
// It saves the list in a file called file_name. The format of the
// file is as follows:
//
// value1\n
// value2\n
// ...
//
int llist_save(LinkedList * list, char * file_name) {
	ListNode *e = list->head;
	FILE *fp = fopen(file_name, "a+");
	if (fp == NULL) {
		return 0;
	}

	if (list->head == NULL) {
		return 0;
	}

	while (e != NULL) {
		fprintf(fp, "%d\n", e->value);
		e = e->next;
	}

	fclose(fp);
	return 0;
}

//
// It reads the list from the file_name indicated. If the list already has entries, 
// it will clear the entries.
//
int llist_read(LinkedList * list, char * file_name) {
	FILE * fp = fopen(file_name, "r+");
	if (fp == NULL) {
		return 0;
	}

	int n = 0;
	fscanf(fp, "%d", &n);

	while (!feof(fp)) {
		llist_add(list, n);
		fscanf(fp, "%d", &n);
	}
	return 1;
}


//
// It sorts the list. The parameter ascending determines if the
// order si ascending (1) or descending(0).
//
void llist_sort(LinkedList * list, int ascending) {
	ListNode *e = list->head;
	while (e->next != NULL) {
		ListNode *f = e->next;
		while (f != NULL) {
			if (ascending) {
				if (e->value > f->value) {
					int p = e->value;
					e->value = f->value;
					f->value = p;
				}
			} else {
				if (e->value < f->value) {
					int p = e->value;
					e->value = f->value;
					f->value = p;
				}
			}
			f = f->next;
		}
		e = e->next;
	}
}

//
// It removes the first entry in the list and puts value in *value.
// It also frees memory allocated for the node
//
int llist_remove_first(LinkedList * list, int * value) {
	if (list->head == NULL) {
		return 0;
	}
	*value = list->head->value;
	list->head = list->head->next;
	return 1;

}

//
// It removes the last entry in the list and puts value in *value/
// It also frees memory allocated for node.
//
int llist_remove_last(LinkedList * list, int *value) {
	if (list->head == NULL) {
		return 0;
	}
	ListNode *e = list -> head;
	while (e->next->next != NULL) {
		e = e -> next;
	}

	*value = e->next->value;
	e->next = NULL;
	return 1;
}

//
// Insert a value at the beginning of the list.
// There is no check if the value exists. The entry is added
// at the beginning of the list.
//
void llist_insert_first(LinkedList * list, int value) {
	llist_add(list, value);
}

//
// Insert a value at the end of the list.
// There is no check if the name already exists. The entry is added
// at the end of the list.
//
void llist_insert_last(LinkedList * list, int value) {
	if (list->head == NULL) {
		llist_add(list, value);
	} else {
		ListNode *n = malloc (sizeof(ListNode));
		n->value = value;
		ListNode *e = list->head;
		while (e->next != NULL) {
			e = e->next;
		}
		e->next = n;
		n->next = NULL;
	}


}

//
// Clear all elements in the list and free the nodes
//
void llist_clear(LinkedList *list)
{
	list->head = NULL;
}
