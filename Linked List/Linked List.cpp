#include <iostream>
using namespace std;

class Node{
	public:
		char id;
		Node *next;
		
		Node(){
			next = NULL;	
		}
};

class LinkedList{
	public:
		Node *head;
		Node *tail;
		
		LinkedList(){
			head = tail = NULL;
		}
		void insertToHead(char data){
			
			Node *node = new Node ();
			node->id = data;
			
			Node *tmp = head;
			head = node;
			node->next = tmp;
		}
		
		void insertToTail(char data){
			
			Node *node = new Node();
			node->id = data;
			
			tail->next = node;
			tail = node;
		}
		
		void printAll(){
			if (head!=NULL){
				Node *tmp = head;
				do {
					cout << tmp->id << "->";
					tmp = tmp->next;
				} while(tmp!=NULL);
			}
		}
};


int main(int argc, char** argv) {
	
	LinkedList *link1 = new LinkedList();
	
	Node *node1 = new Node();
	node1->id = 'A';
	
	link1->head = node1;
	link1->tail = node1;
	
	cout << link1->head->id << endl;
	
	Node *nodeX = new Node();
	nodeX->id ='X';
	
	Node *tmp = link1->head;
	link1->head = nodeX;
	nodeX->next = tmp;
	
	cout << link1->head->id << endl;
	cout << link1->tail->id << endl;
	
	link1->insertToHead('Y');
	link1->insertToTail('C');
	
	cout << link1->head->id << endl;
	cout << link1->tail->id << endl;
	
	link1->printAll();
	return 0;
}
	
//insert to the tail
//insert to the head
	
	
	
	