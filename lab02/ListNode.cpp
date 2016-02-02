#include <iostream>
#include "List.h"
#include "ListItr.h"

using namespace std;

ListNode::ListNode() {
	value = 0; 
	next = NULL;
	previous  = NULL;
}