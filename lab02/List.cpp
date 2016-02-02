#include <iostream>
#include "ListNode.h"
#include "ListItr.h"

using namespace std;

// ------------------------------------------------  default constructor
List::List() {
	//initialize all private data members
	head = new ListNode;
	tail = new ListNode;
	count = 0;
}

// ---------------------------------------------------  copy constructor
List::List(const List& source) {   
    head=new ListNode;
    tail=new ListNode;
    head->next=tail;
    tail->previous=head;
    count=0;
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {       // deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

// --------------------------------------------------------  destructor
List::~List() {
	 //make list empty
	 makeEmpty();

	 //reclaim memory allocated for head and tail
	 delete head;
	 delete tail;
}
// --------------------------------------------------------  equals operator

List& List::operator=(const List& source) { //Equals operator
    if (this == &source)
        return *this;
    else {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

bool List::isEmpty() const {
	//return true if list is empty, else return false
	return(head==NULL);
}

void List::makeEmpty(){ //removes/reclaims all items from a list, except the dummy head and tail nodes.
	while(head != NULL){
		ListNode *next = head->next;
		delete head;
		head = next;
	}
}

ListItr List::first(){ //Returns an iterator that points to
    //the ListNode in the first position
	ListItr* x = new ListItr(head->next);
	return *x;
}

ListItr List::last(){			//Returns an iterator that points to
    //the ListNode in the last position
    ListItr* x = new ListItr(tail->previous);
	return *x;
}

void List::insertAfter(int x, ListItr position){//Inserts x after current iterator position p
    ListNode* temp = new ListNode();
    temp->value = x;
    ListNode* temp2 = new ListNode();
    temp2->value = position.current->next->value;

    position.current->next = temp;
    temp->previous = position.current;
    temp->next = temp2;
    temp2->previous = temp;

}

void List::insertBefore(int x, ListItr position){  //Inserts x before current iterator position p
   	ListNode* temp = new ListNode();
   	temp->value = x;
    ListNode* temp2 = new ListNode();
    temp2->value = position.current->previous->value;

    position.current->previous = temp;
    temp->next = position.current;
    temp->previous = temp2;
    temp2->next = temp;

}

void List::insertAtTail(int x){ //Insert x at tail of list
	ListItr* iter = new ListItr(tail);
	this->insertBefore(x,*iter);

}

void List::remove(int x){ //Removes the first occurrence of x
	ListItr* iter = new ListItr(head);
	while(!(iter->current->value==x)){
	}
}

ListItr List::find(int x){ //Returns an iterator that points to
    // the first occurrence of x, else return an iterator to the dummy tail node
	return NULL;

}

int List::size() const{ //Returns the number of elements in the list
	return 0;
}

void printList(List& source, bool direction){ ////prints list forwards when direction is true
//or backwards when direction is false

}
