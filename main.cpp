#include <iostream> 

using namespace std; 

template <typename T> class Node { 
	public: 
		T data; 
		Node* next; 
};

template <typename T> class Stack{
	private:
		Node<T> *head;
		unsigned int length;
	public:
		Stack(){
			head = NULL;
			length = 0;
		}
		bool isEmpty(){
			return head == NULL;
		}
		void push(T data){
			Node<T> *newnode = new Node<T>;
			newnode->data = data;
			newnode->next = head;
			head = newnode;
			this->length++;
		}
		T pop(){
			if(isEmpty()){
				cout<<"Can't pop element , stack is empty"<<endl;
				exit(0);
			}
			T returnData;
			returnData = head->data;
			Node<T> *deleteNode = head;
			head = head->next;
			delete deleteNode;
			this->length--;
			return returnData;
		}
		void print(){
			if(head == NULL){
				cout<<"Stack is empty\n";
			}
			Node<T> *iNode = head;
			for(int i=0;i<length;i++){
				cout<<iNode->data<<" ";
				iNode = iNode->next;
			}
		}
		T peek(){
			if(isEmpty()){
				cout<<"Can't peek element , stack is empty"<<endl;
				exit(0);
			}
			return head->data;
		}
		unsigned int getLength(){
			return this->length;
		}
};

template <typename T> class Queue{ 
	private: 
		Stack<T> inputStack;
		Stack<T> outputStack;
	public:
		void enQueue(T data){
			while(!inputStack.isEmpty()){
				outputStack.push(inputStack.pop());
			}
			inputStack.push(data);
			while(!outputStack.isEmpty()){
				inputStack.push(outputStack.pop());
			}
		}
		T deQueue(){
			if(inputStack.isEmpty()){
				cout<<"Queue is empty"<<endl;
				exit(0);
			}
			return inputStack.pop();
		}
		void print(){
			while(!inputStack.isEmpty()){
				outputStack.push(inputStack.pop());
			}
			while(!outputStack.isEmpty()){
				cout<<outputStack.peek()<<" ";
				inputStack.push(outputStack.pop());
			}
		}
		unsigned int getLength(){
			return inputStack.getLength();
		}
		bool isEmpty(){
			return inputStack.isEmpty();
		}
		T peek(){
			if(isEmpty()){
				cout<<"Can't peek element , queue is empty"<<endl;
				exit(0);
			}
			return inputStack.peek();
		}	
};

template <typename T> class List{
	private:
		Node<T> *head;
		Node<T> *tail;
	public:
		List(){
			head = NULL;
			tail = NULL;
		}
		void insertStart(T value){
			Node<T> *temp = new Node<T>;
			temp->data = value;
			temp->next = head;
			head = temp;
		}
		void insertEnd(T value){
			Node<T> *temp = new Node<T>;
			temp->data = value;
			temp->next = NULL;
			if(head == NULL){
				head = temp;
				tail = temp;
				temp = NULL;
			}else{
				tail->next = temp;
				tail = temp;
			}
		}
		void insertByPosition(unsigned int position,T value){
			Node<T> *previous = new Node<T>;
			Node<T> *current = new Node<T>;
			Node<T> *temp = new Node<T>;
			current = head;
			for(int i=1;i<position;i++){
				previous = current;
				current = current->next;
			}
			temp->data = value;
			previous->next = temp;
			temp->next = current;
		}
		T deleteFirst(){
			if(head == NULL){
				cout<<"Can't delete any value ,List is empty"<<endl;
				exit(0);
			}
			Node<T> *temp = new Node<T>;
			temp = head;
			T returnValue = head->data;
			head=head->next;
			delete temp;
			return returnValue;
		}
		T deleteLast(){
			if(head == NULL){
				cout<<"Can't delete any value ,List is empty"<<endl;
				exit(0);
			}
			Node<T> *current = new Node<T>;
			Node<T> *previous = new Node<T>;
			current = head;
			while(current->next != NULL){
				previous = current;
				current = current->next;
			}
			tail = previous;
			previous->next = NULL;
			T returnValue = current->data;
			delete current;
			return returnValue;
		}
		T deleteByPosition(unsigned int position){
			if(head == NULL){
				cout<<"Can't delete any value ,List is empty"<<endl;
				exit(0);
			}
			Node<T> *current = new Node<T>;
			Node<T> *previous = new Node<T>;
			current = head;
			for(int i=0;i<position;i++){
				previous = current;
				current = current->next;
			}
			previous->next = current->next;
			return previous->data;
		}
		void print(){
			if(head == NULL){
				cout<<"List is empty"<<endl;
				exit(0);
			}
			Node<T> *temp = new Node<T>;
			temp = head;
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp = temp->next;
			}
		}
		void reverse(){
			Node<T> *current = head;
			Node<T> *previous = NULL;
			Node<T> *next = NULL;
			while(current != NULL){
				next = current->next;
				current->next = previous;
				previous = current;
				current = next;
			}
			head = previous;
		}		
};

int main(int argc, char** argv) { 
	
	return 0; 
}