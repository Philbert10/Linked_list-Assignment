#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

// Making a node struct containing a data int and a pointer
// to another node
struct Node {
  int data;
  Node * next;
};

class LinkedList {
  // Head pointer
  Node * h;
  // TAIL pointer
  Node * t;
  void updateTail() {
    // if head is null set the tail to null also
    if (h == NULL) {
      t = NULL;
      return;
    }
    Node * temp = h;

    //  Else traverse till the last node
    while (temp -> next != NULL) {
      temp = temp -> next;
    }

    //  Assign the last node to tail
    t = temp;
    return;
  }

  void printTail() {
    if (t == NULL) cout << t;
    cout << t -> data;
  }

  public:
    // default constructor. Initializing head pointer
    LinkedList() {
      h = NULL;
      t = NULL;
    }
  LinkedList(int size) {
    // Seed srand with random numbers
    srand(time(0));
    for (int i = 0; i < size; i++)
      // Add random numbers into our linked list
      insertAtBeginning(rand());
  }
  // Copy constructor
  LinkedList(const LinkedList & l1) {
    h = l1.h;
    t = l1.t;
  }
  // Desctructor
  ~LinkedList() {
    Node * current = h;
    while (current != 0) {
      Node * next = current -> next;
      delete current;
      current = next;
    }
    h = NULL;
  } 
  void operator = (const LinkedList & l) {
    h = l.h;
    t = l.t;
  }
  Node * getHead() {
    return h;
  }
  // inserting elements (At start of the list)
  void insertAtBeginning(int val) {
    // make a new node
    Node * new_node = new Node;
    new_node -> data = val;
    new_node -> next = NULL;

    // If list is empty, make the new node, the head
    if (h == NULL) h = new_node;

    // else, make the new_node the head and its next, the previous
    // head
    else {
      new_node -> next = h;
      h = new_node;
    }
    this -> updateTail();
    //    this->printTail();
  }

  // inserting elements (At the end of the list)
  void insertAtEnd(int val) {
    // make a new node
    Node * new_node = new Node;
    new_node -> data = val;
    new_node -> next = NULL;

    // If list is empty, make the new node, the head
    if (h == NULL) h = new_node;

    // else, make the new_node the head and its next, the previous
    // head
    else {
      t -> next = new_node;
      t = new_node;
    }
    //      this->printTail();
  }
  // loop over the list. return true if element found
  bool search(int val) {
    Node * temp = h;
    while (temp != NULL) {
      if (temp -> data == val) return true;
      temp = temp -> next;
    }
    return false;
  }

  void remove(int val) {
    // If the head is to be deleted
    if (h -> data == val) {
      delete h;
      h = h -> next;
      return;
    }

    // If there is only one element in the list
    if (h -> next == NULL) {
      // If the head is to be deleted. Assign null to the head
      if (h -> data == val) {
        delete h;
        h = NULL;
        return;
      }
      // else print, value not found
      cout << "Value not found!" << endl;
      return;
    }

    // Else loop over the list and search for the node to delete
    Node * temp = h;
    while (temp -> next != NULL) {
      // When node is found, delete the node and modify the pointers
      if (temp -> next -> data == val) {
        Node * temp_ptr = temp -> next -> next;
        delete temp -> next;
        temp -> next = temp_ptr;
        return;
      }
      temp = temp -> next;
    }
    // Else, the value was neve in the list
    cout << "Value not found" << endl;
  }

  void display() {
    Node * temp = h;
    while (temp != NULL) {
      cout << temp -> data << " ";
      temp = temp -> next;
    }
    cout << endl;
  }

  /* Function to reverse the nodes in a linked list. */
  void reverse() {
    if (h == NULL) return;

    Node * prev = NULL, * current = NULL, * next = NULL;
    current = h;
    while (current != NULL) {
      next = current -> next;
      current -> next = prev;
      prev = current;
      current = next;
    }
    // now let the head point at the last node (prev)
    h = prev;
  }
  // Function
  void removeDuplicate() {
    this -> selectionSort();
    // temp pointing to head
    Node * temp = h;
    while (temp -> next != NULL && temp != NULL) {
      // Duplicate Found
      if (temp -> data == temp -> next -> data) {
        // DUplicate Removed
        temp -> next = temp -> next -> next;
      } else {
        // No Duplicate Present
        temp = temp -> next;
      }
    }
  }

  void selectionSort() {
    Node * temp = h;

    // Traverse the List
    while (temp) {
      Node * min = temp;
      Node * r = temp -> next;

      // Traverse the unsorted sublist
      while (r) {
        if (min -> data > r -> data) min = r;
        r = r -> next;
      }

      // Swap Data
      int x = temp -> data;
      temp -> data = min -> data;
      min -> data = x;
      temp = temp -> next;
    }
  }
};

int main() {
  LinkedList l(4);
  LinkedList l2 = l;
  cout << "Displaying l2:";

  l2.display();
  cout << l2.getHead() -> data;
  // inserting elements
  l.insertAtBeginning(3);
  l.insertAtBeginning(2);
  l.insertAtBeginning(1);
  l.insertAtEnd(24);
  l.insertAtBeginning(8);
  l.insertAtBeginning(4);
  l.insertAtEnd(22);
  cout << "Current Linked List: ";
  l2.display();

  cout << "Deleting 1: ";
  l.remove(1);
  l.display();
  cout << "Reversed linked list \t";
  l.reverse();
  l.display();
  cout << "Deleting 24: ";
  l.remove(24);

  cout << "Searching for 8: ";
  cout << l.search(8) << endl;
  //  l.selectionSort();
  //  l.removeDuplicate();
  cout << "Displaying l:";
  l.display();
  l2 = l;
  cout << "Displaying l2:";
  l2.display();
  cout << l.getHead() -> data << endl;
  cout << "Searching for 22: ";
  cout << l.search(22) << endl;

}
