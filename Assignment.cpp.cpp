
#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
	int data;
	node *next;
} Node;

class List {
	private:
		node *head;
		node *tail;

	public:

		List(){
			head = NULL;
			tail = NULL;
		}
		
		//This is the function to insert node at the beginning
		void insertNodeBeginning (int num) {
			node *temp = new node;
			temp->data = num;
			temp->next = head;
			head = temp;
		}
			//This is the function to insert node at the end
		void insertNodeAtEnd (int num) {
			node *temp = new node;
			temp->data = num;
			temp->next = NULL;
			
			if (head == NULL) {
				head = temp;
				tail = temp;
				temp = NULL;
			}else {
				tail->next = temp;
				tail = temp;
			}
		}
		List(const List& l2) {
			head = l2.head;
			tail = l2.tail;
		}
		//this is function to overload assigning operator 
		void operator= (const List & l){
		        head=l.head;
			tail=l.tail;
		}
//		Function to dislplay the list
		void displayList(){
		    node *temp=new node;
		    temp = head;
		    if (head == NULL) { 
		       cout<<" linked list is empty"<<endl;       
		       return;  
		    }else {
			    while(temp!=NULL){
			      cout<<temp->data<<"\t";
			      temp=temp->next;
			    }		    	
			}

	  	}
	  	
		  //parametarized constructor to insert node at the end
		List(int size) {
			int k=0;
			while (k < size) {
				insertNodeAtEnd(rand());
				k++;
			}
			displayList();
		}
		//Function to delete node
		void deleteNode(int num){
		  struct node *prv, *curr;
		  while(head != NULL && head ->data == num){
            prv = head;
            head = head ->next;
            delete(prv);
            cout<<"The number deleted"<<endl;
            return;
		  }
		  prv = NULL;
		  curr = head;
		  while(curr != NULL){
            if(curr ->data == num){
                if(prv !=NULL)
                    prv ->next = curr ->next;
                delete(curr);
                cout<<"The number deleted"<<endl;
                return;
            }
            prv = curr;
            curr = curr->next;
		  }

		}
		//Function to reverse the list
		void reverse() {
			if (head == NULL) return;
			
		    node *temp = new node;
		    node *prev = new node;
		    node *curr = new node;
		    
			temp = NULL;
		    prev = NULL;
		    curr = head;
		    while(curr != NULL) {
		        temp = curr->next;
		        curr->next = prev;
		        prev = curr;
		        curr = temp;
		    }
		    head = prev;
		}
		//function to remove duplicate elements
		void remove_duplicate() {  
		    node *curr = new node;
		    node *ptr = new node;
		    node *temp = new node;
			curr = head,  ptr = NULL, temp = NULL;  
		      
		    if(head == NULL) {  
		        return;  
		    }  
		    else {  
		        while(curr != NULL){    
		            temp = curr;   
		            ptr = curr->next;  
		              
		            while(ptr != NULL) {    
		                if(curr->data == ptr->data) {   
		                    temp->next = ptr->next;  
		                }  
		                else {  
		                    temp = ptr;  
		                }  
		                ptr = ptr->next;  
		            }  
		            curr = curr->next;  
		        } 
				displayList();         
		    }  
		}  
		//searching function
		void search(){  
		    node *ptr = new node;  
		    int item,i=0,flag;  
		    ptr = head;   
		    if(ptr == NULL){  
		    	cout<<"List is empty"; 
		    } else {   
		    	cout<<"Enter item to search?\n";
		        cin>>item;   
		          
		        while (ptr!=NULL){  
		            if(ptr->data == item){  
		            	cout<<"Item found at position "<<(i+1)<<endl;
		                  
		                flag=0;
						break;  
		            }else {  
		                flag=1;  
		            }  
		            i++;  
		            ptr = ptr -> next;  
		        }  
		        if(flag==1){  
		        	cout<<"Item not found!\n";
		              
		        }  
		    }     
		          
		}
		
		
	//end of class defition
};
//Main function
int main() {
	int size; 
	int num_of_operation; 
	int val;
	//Request user to enter random size of numbers to be generated
	cout<<"Enter the number of random integers to be generated.\n";
	cin>>size;

	List l(size);
        //Select option to be perfomed
        cout<<endl<<"Choose an operations "<<endl;
        cout<<"1.Display Linked List"<<endl;
        cout<<"2.Insert Node at the front."<<endl;
		cout<<"3.Delete a node with a given number"<<endl;        
        cout<<"4.Insert node at the end."<<endl;
        cout<<"5.Reverse Linked List "<<endl;
        cout<<"6.Search Element"<<endl;
		cout<<"7.Remove duplicates from the list."<<endl;
        cout<<"8.Exit "<<endl;
		
		//Responding to the user option if 1-> displayList will be called	
    while (1){
        cout<<"Enter operation number: ";
        cin>>num_of_operation;
        if (num_of_operation == 1) {
        	l.displayList();
            cout<<endl;

		} else if(num_of_operation == 2){
			cout<<"Enter the number to insert at the front:"<<endl;
			cin>>val;
            l.insertNodeBeginning(val);
            cout<<endl;

		}else if (num_of_operation == 3) {
			cout<<"\nEnter a number you want to delete: "<<endl;
            cin>>val;
			l.deleteNode(val);

		} else if (num_of_operation == 4) {
			cout<<"Enter the number to insert at the end"<<endl;
            cin>>val;
            l.insertNodeAtEnd(val);
            cout<<endl;

		} else if (num_of_operation == 5) {
			l.reverse();
            cout<<endl;
		} else if (num_of_operation == 6) {
			l.search();
            cout<<endl;
		}else if (num_of_operation == 7) {
			l.remove_duplicate();
            cout<<endl;
            //if we want to exit our otption is 8
		}else if (num_of_operation == 8) {
			cout<<"Exiting..."<<endl;
            exit(1);
		} else {
			//Option entered does not have its correspondence.
			cout<<"Operation number entered doesn't exist.'"<<endl;
		}
        
    }
	
}
