#include<iostream>
using namespace std;

//array FIFO queue
class FIFOArray 
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

class FIFOLinkedList {
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
	Node* StartOfLinkedList;
	Node* EndOfLinkedList;
	int size;
public:
	FIFOLinkedList(){
		StartOfLinkedList=NULL;
		EndOfLinkedList = NULL;
		size=0;
	}

//Queue Linked List

	int EnqueueLinkedList(int x){
		Node* n = new Node(x);
		if (EndOfLinkedList == NULL) {
			StartOfLinkedList = n;
			EndOfLinkedList = n;
		} else {
			EndOfLinkedList -> next = n;
			EndOfLinkedList = n;
		}
			size++;
			return 1;
	}
	
//Dequeue Linked list

	int DeQueue(){
		if(StartOfLinkedList == NULL){
			cout<<"Linked List is empty\n" << endl;
			return 0;
		}
		int FirstValue = StartOfLinkedList -> data;
		Node* ThisDeletesPTR = StartOfLinkedList;
		StartOfLinkedList = StartOfLinkedList -> next;
		delete ThisDeletesPTR; 
		size--;

		if (StartOfLinkedList == NULL) {
			EndOfLinkedList = NULL;
		}
		return FirstValue;
}

// Peek at the first number in Linked list

	int PeekLinkedList(){
		if (StartOfLinkedList == NULL){
			cout<<"Linked list is empty\n" << endl;
			return -1;
		}
		return StartOfLinkedList->data;
	}


	int CancelOrderLinkedList(int target){
		if (StartOfLinkedList ==NULL){
			cout<<"Linked List is empty\n" << endl;
			return 0;
		}
		
		if (StartOfLinkedList-> data == target) {
			Node* temp = StartOfLinkedList;
			StartOfLinkedList = StartOfLinkedList->next;
			delete temp;
			size--;

			if (StartOfLinkedList == NULL){
				EndOfLinkedList = NULL;
			}
			return 1;
			}
			

			Node* select = StartOfLinkedList;
			while (select-> next != NULL){
				if(select->next->data == target){
					Node* temp = select->next;
					select->next = temp->next;


					if (temp == EndOfLinkedList) {
						EndOfLinkedList = select;
					}
					delete temp;
					size--;
					return 1;
				}
				select = select->next;
			}
			return 0;
	}
		bool IsEmpty() {
			return StartOfLinkedList == NULL;
		}
		int Size() {
			return size;
		}
};

int main() {

//__________________________________________________________________

	//FIFO with array;
	FIFOArray array1;

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
	cout << "Cancelling 90: " << array1.CancelOrder(90) << endl;
	
	//dequeue rest
	cout << "Dequeue: " << array1.DeQueue() << endl;
	cout << "DeQueue: " << array1.DeQueue() << endl;

	//See what happens when DeQueue() is called when empopty
	cout << "Dequeue: " << array1.DeQueue() << endl;
//___________________________________________________________________

	//FIFO Linked list
	FIFOLinkedList LinkedList1;
	//Enqueue values
	cout<<"80 is enqueued: " << LinkedList1.EnqueueLinkedList(80) << endl;
        cout<<"90 is enqueued: " << LinkedList1.EnqueueLinkedList(90) << endl;
        cout<<"100 is enqueued: " << LinkedList1.EnqueueLinkedList(100) << endl;

	//Peek at front value
	cout << "Peek: " << LinkedList1.PeekLinkedList() << endl;


	//Dequeue 
	cout << "Dequeue: " << LinkedList1.DeQueue() << endl;

	//Peek and check again
	cout << "Peek again is: " << LinkedList1.PeekLinkedList() << endl;


	//cancel order
	cout << "Cancelling 90: " << LinkedList1.CancelOrderLinkedList(90) << endl;
	
	//dequeue rest
	cout << "Dequeue: " << LinkedList1.DeQueue() << endl;
	cout << "DeQueue: " << LinkedList1.DeQueue() << endl;

	//See what happens when DeQueue() is called when empopty
	cout << "Dequeue: " << LinkedList1.DeQueue() << endl;
	
	return 0;

}
