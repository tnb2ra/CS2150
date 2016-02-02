#include <iostream>
#include "ListNode.h"
#include "List.h"

using namespace std;

// ------------------------------------------------  default constructor
ListItr::ListItr() {
	//initialize all private data members
	current = NULL;
}

// ------------------------------------------------  one parameter constructor
ListItr::ListItr(ListNode* theNode) {
	//initialize all private data members
	current = theNode;
}
 
bool ListItr::isPastEnd() const{ //Returns true if past end position in list, else false
	return (current->next==NULL);
}	

bool ListItr::isPastBeginning() const{ //Returns true if past first position in list, else false
	return (current->previous==NULL);
}	

void ListItr::moveForward(){ //Advances current to next position in list 
	//(unless already past end of list)
	if(!current->isPastEnd()){
		current = current->next;
	}
}

void ListItr::moveBackward(){ //Moves current back to previous position
    // in list (unless already past beginning of list)
	if(!current->isPastBeginning()){
		current = current->previous;
	}
}

int ListItr::retrieve() const{ //Returns item in current position
	return current->value;
}