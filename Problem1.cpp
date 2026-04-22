#include<iostream>
using namespace std;

//array FIFO queue
class FIFO 
{
	private:
		int array[10] = {};
		int start = 0;
		int end = -1;
		int CountSize = 0;
		
	public:
		int Enqueue(int newValue) {
			if (CountSize == sizeof(array) / sizeof(array[0])) {
				return 0;
			}
			end++;
			array[end] = newValue;
			CountSize++;
			return 1;
		
		}

		int DeQueue(void) {
			if (CountSize == 0){
				return 0;
			}
			int FirstValue = array[start];
			start++;		
			CountSize--;
			return FirstValue;
		}

		int Peek(void){
			if (CountSize == 0) {
				return 0;
			}
			return array[start];
			
		}

		int CancelOrder(int target) {
			for (int i = start; i <= end; i++){
				if (array[i] == target) {
					for (int j = i; j < end; j++) {
						array[j] = array[j + 1];
					}
					end--;
					CountSize--;
					return 1;
				}
			}
			return 0;
			}
};

//___________________________________________________________________
//Linked list FIFO queue

class stack {
private:
	class Node {
	public:
		int data;
		Node* next;
	
		Node(int data){
			this->data=data;
			next = NULL;
		}
	};
	Node * TopOfNode;
	int size;
public:
	stack(){
		TopOfNode=NULL;
		size=0;
	}
	void push(int x){
		Node* n = new Node(x);
		n->next=TopOfNode;
		TopOfNode=n; 
		size++;
	}
	void pop(){
		if(TopOfNode == NULL){
			cout<<"Stack is empty\n";
			return;
		}
		Node* ThisDeletesPTR = TopOfNode;
		TopOfNode = TopOfNode -> next;
		delete ThisDeletesPTR; 
		size--;
	}
	int Top(){
		if (TopOfNode == NULL){
			cout<<"stack is empty\n";
			return -1;
		}
		return TopOfNode->data;
	}
	bool empty(){
		return TopOfNode ==NULL;
		}
	int Size(){
		return size;
	}
};

int main() {

//__________________________________________________________________

	FIFO array1;
	
	//Enqueue values
	cout<<"10 is Enqueued: " << array1.Enqueue(10) << endl;
	cout<<"20 is Enqueued: " << array1.Enqueue(20) << endl;
	cout<<"30 is Enqueued: " << array1.Enqueue(30) << endl;
	
	//Peek at front value
	cout << "Peek: " << array1.Peek() << endl;


	//Dequeue 
	cout << "Dequeue: " << array1.DeQueue() << endl;

	//Peek and check again
	cout << "Peek again is: " << array1.Peek() << endl;


	//cancel order
	cout << "Cancelling 90" << array1.CancelOrder(90) << endl;
	
	//dequeue rest
	cout << "Dequeue: " << array1.DeQueue() << endl;
	cout << "DeQueue: " << array1.DeQueue() << endl;

	//See what happens when DeQueue() is called when empopty
	cout << "Dequeue: " << array1.DeQueue() << endl;
//___________________________________________________________________













	return 0;

}
