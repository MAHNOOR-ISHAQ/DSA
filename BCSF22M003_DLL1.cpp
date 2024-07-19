#include <iostream>
using namespace std;
class Node {
private:
	int data;
	Node* next;
	Node* prev;
	friend class DLL;
public:
	Node() {
		data = 0;
		next = NULL;
		prev = NULL;
	}
	Node(int x) {
		data = x;
		next = NULL;
		prev = NULL;
	}
};
class DLL {
private:
	Node* head;
public:
	DLL() {
		head = NULL;
	}
	DLL(int x) {
		head = new Node(x);
	}
	// Insert at start function
	void insertAtStart(int x) {
		if (head == NULL) {
			Node* n1 = new Node(x);
			head = n1;
			return;
		}
		else {
			Node* temp = new Node(x);
			temp->next = head;
			temp->prev = NULL;
			head->prev = temp;
			head = temp;
		}
	}
	//Insert at end (Append) function
	void insertAtEnd(int x) {
		if (head == NULL) {
			Node* n1 = new Node(x);
			head = n1;
			return;
		}
		else {
			Node* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			Node* n1 = new Node(x);
			n1->next = NULL;
			n1->prev = temp;
			temp->next = n1;
		}
	}
	//inser in Middle
	//Insert before function
	void insertBefore(int value, int x) {
		if (head == NULL) {
			cout << "List is Empty" << endl;
			return;
		}
		else if (head->data == value) {
			insertAtStart(x);
			return;
		}
		else{
			Node* temp = head;
			while (temp != NULL) {
				if (temp->data == value) {
					Node* n1 = new Node(x);
					n1->next = temp;
					n1->prev = temp->prev;
					temp->prev->next = n1;
					temp->prev = n1;
					return;
				}
				temp = temp ->next;
			}
			cout << "Data not Found!" << endl;
		}
	}
	//insert After
	void insertAfter(int value, int x) {
		if (head == NULL) {
			cout << "List is Empty" << endl;
			return;
		}
		else {
			Node* temp = head;
			while (temp != NULL) {
				if (temp->data == value) {
					if (temp->next == NULL) {
						insertAtEnd(x);
						return;
					}
					Node* n1 = new Node(x);
					n1->next= temp->next;
					n1->prev = temp;
					temp->next->prev = n1;
					temp->next = n1;
					return;
				}
				
				temp = temp->next;
			}
			cout << "Data not Found" << endl;
		}
	}
	//delete the first occurrence
	void deleteFirstOccurrence(int value) {
		if (head == NULL) {
			cout << "List is Empty" << endl;
			return;
		}
		else if (head->data == value) {
			Node* temp = head;
			head = head->next;
			head->prev = NULL;
			delete temp;
			return;
		}
		else {
			Node* temp = head;
			while (temp != NULL) {
				if (temp->data == value) {
					if (temp->next == NULL) {
						temp->prev->next = NULL;
						delete temp;
						return;
					}
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
					return;
				}
				temp = temp->next;
			}
			cout << "Data not Found" << endl;
		}
	}
	//deleting kth occurrence
	void kthOccurrence(int value, int k) {
		if (head == NULL) {
			cout << "List is Empty" << endl;
			return;

		}
		else {
			int count = 0;
			Node* temp = head;
			while (temp!= NULL) {
				if (temp->data == value) {
					count++;

				}
				if (count == k) {
					break;
				}
				temp = temp->next;
			}
			if (temp->next == NULL) {
				temp ->prev->next = NULL;
			}
			else if (temp == NULL) {
				cout << "Occurence not FounD!" << endl;
				return;
			}
			else if (temp->prev == NULL) {
				head = head->next;
				head->prev = NULL;
			}
			else{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
			}
			delete temp;
		}
	}
	//delete all occurrences
	void deleteAllOccurrences(int value) {
		if (head == NULL) {
			cout << "List is Empty" << endl;
			return;
		}

		Node* temp = head;

		while (temp != NULL) {
			if (temp->data == value) {
				Node* toDelete = temp;

				if (temp == head) {
				
					head = head->next;
					if (head != NULL) {
						head->prev = NULL;
					}
					temp = head;
				}
				else if (temp->next == NULL) {
					
					temp->prev->next = NULL;
					temp = NULL;
				}
				else {
				
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
					temp = temp->next;
				}

				delete toDelete;
			}
			else {
				temp = temp->next;
			}
		}
		
	}
	void printReverse() {
		if (head == NULL) {
			cout << "List is Empty" << endl;
			return;
		}
		else {
			Node* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			while (temp != NULL) {
				cout << temp->data << " ";
				temp = temp->prev;
			}
			cout << endl;
		}
	}
	//reversing list
	DLL* reverseList() {
		if (head == NULL) {
			cout << "List is Empty" << endl;
			return new DLL();
		}
		else {
			DLL* list1 = new DLL();
			Node* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			while (temp != NULL) {
				list1->insertAtEnd(temp->data);
				temp = temp->prev;

			}
			return list1;
		}
	}


	//Display function
		void display() {
			if (head == NULL) {
				cout << "list is empty" << endl;
				return;
			}
			else {
				Node* temp = head;
				while (temp != NULL) {
					cout << temp->data << " ";
					temp = temp->next;
				}
				cout << endl;
			}
		}
	//destructor
		~DLL() {
			Node* temp = head;
			while (temp != NULL) {
				Node* nextNode = temp->next;
				delete temp;
				temp = nextNode;
			}
			head = NULL;
		
		}

};
int main() {
	cout << "-----------DOUBLE LINKED LIST(1 POINTER)----------" << endl;
	DLL* list = new DLL(78);
	cout << "Adding nodes at end" << endl;
	list->insertAtEnd(56);
	list->insertAtEnd(41);
	list->insertAtEnd(41);
	list->insertAtEnd(41);
	list->insertAtEnd(56);
	list->insertAtEnd(56);
	list->insertAtEnd(90);
	cout << "Displaying List" << endl;
	list->display();
	cout << endl;

	cout << "adding nodes at start" << endl;
	list->insertAtStart(23);
	cout << "Displaying List" << endl;
	list->display();
	cout << endl;
	cout << "Inserting after (41)" << endl;
	list->insertAfter(41, 90);
	cout << "Displaying List" << endl;
	list->display();
	cout << endl;
	cout << "Inserting before (41)" << endl;
	list->insertBefore(41, 99);
	cout << "Displaying List" << endl;
	list->display();
	cout << endl;
	cout << "Printing the reverse" << endl;
	list->printReverse();
	cout << endl;
	cout << "reversing the actual list" << endl;
	DLL* list1 = new DLL();
	list1 = list->reverseList();
	list1->display();
	cout << endl;
	cout << "Deleting the first occurence of 41" << endl;
	list->deleteFirstOccurrence(41);
	list->display();
	cout << endl;
	cout << "Deleting 2nd occurrence of 41" << endl;
	list->kthOccurrence(41, 2);
	list->display();
	cout << endl;
	cout << "Deleting all occurrences of 56" << endl;
	list->deleteAllOccurrences(56);
	list->display();
	cout << endl;
	

	delete list;
	return 0;
}