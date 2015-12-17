#include "DLList.h"
#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

DLList::DLList()
{
	head = new DLNode();
	head->next = head;
	head->prev = head;

}

DLList::~DLList()
{
	head->next = head;
	head->prev = head;
}

void DLList::print()
{
	DLNode * e = head -> next;
	while (e != head) {
		std::cout<< e->data <<std::endl;
		e = e->next;
	}

}

void DLList::printSorted()
{
	DLList li;
	DLNode * m = head->next;
	while (m != head) {
		li << m->data;
		m = m->next;
	}

	int k;
	DLNode *e = li.head->next;
	while (e->next != li.head) {
		DLNode *f = e->next;
		while (f != li.head) {
			if (e->data > f->data) {
				k = e->data;
				e->data = f->data;
				f->data = k;
			}
			f = f->next;
		}
		e = e->next;
	}

	li.print();

}

void DLList::insertFront(int data)
{
	DLNode *e = new DLNode();
	e ->data = data;
	e ->next = head->next;
	e ->prev = head;
	e ->next->prev = e;
	e ->prev->next = e;

}

bool DLList::removeLast(int & data)
{
	data = head->prev->data;
	head->prev = head->prev->prev;
	head->prev->next = head;
	return true;
}

DLList * DLList::difference(DLList & list)
{
	DLNode *e = head->prev;
	DLList *diff = new DLList();
	int p;
	while (e != head) {
		p = 1;
		DLNode *f = list.head->prev;
		while (f != list.head) {
			if (e->data == f->data) {
				p = 0;
				break;
			}
			f = f->prev;
		}
		if (p) {
			diff->insertFront(e->data);
		}
		e = e->prev;
	}

	return diff;


}

DLList * DLList::getRange(int start, int end)
{
	return this;
}

DLList * DLList::intersection(DLList & list)
{
	DLNode *e = head->prev;
	DLList *diff = new DLList();
	int p;
	while (e != head) {
		p = 0;
		DLNode *f = list.head->prev;
		while (f != list.head) {
			if (e->data == f->data) {
				p = 1;
				break;
			}
			f = f->prev;
		}
		if (p) {
			diff->insertFront(e->data);
		}
		e = e->prev;
	}

	return diff;
}

void DLList::removeRange(int start, int end)
{

}
