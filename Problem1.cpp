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
		bool isEmpty() {
			return CountSize == 0;
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

class FIFODoublyLinkedList {
private:
    class Node {
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int data) {
            this->data = data;
            next = NULL;
            prev = NULL;
        }
    };

    Node* front;
    Node* back;
    int size;

public:
    FIFODoublyLinkedList() {
        front = NULL;
        back = NULL;
        size = 0;
    }

    Node* EnqueueDoubly(int x) {
        Node* n = new Node(x);
        if (back == NULL) {
            front = n;
            back = n;
        } else {
            back->next = n;
            n->prev = back;
            back = n;
        }
        size++;
        return n;
    }

    int DeQueueDoubly() {
        if (front == NULL) {
            cout << "Doubly linked list is empty\n" << endl;
            return 0;
        }

        int value = front->data;
        Node* temp = front;
        front = front->next;

        if (front != NULL) {
            front->prev = NULL;
        } else {
            back = NULL;
        }

        delete temp;
        size--;
        return value;
    }

    int PeekDoubly() {
        if (front == NULL) {
            return -1;
        }
        return front->data;
    }

    int CancelByReference(Node* orderNode) {
           if (orderNode == NULL) {
            return 0;
        }

        if (orderNode->prev != NULL) {
            orderNode->prev->next = orderNode->next;
        } else {
            front = orderNode->next;
        }

        if (orderNode->next != NULL) {
            orderNode->next->prev = orderNode->prev;
        } else {
            back = orderNode->prev;
        }

        delete orderNode;
        size--;
        return 1;
    }

    bool IsEmpty() {
        return front == NULL;
    }

    int Size() {
        return size;
    }

};



int main() {
    cout << "Problem 1 Queue Tests\n\n";

    FIFOArray array1;
    cout << "Array queue:\n";
    cout << "10 is Enqueued: " << array1.Enqueue(10) << endl;
    cout << "20 is Enqueued: " << array1.Enqueue(20) << endl;
    cout << "30 is Enqueued: " << array1.Enqueue(30) << endl;
    cout << "Peek: " << array1.Peek() << endl;
    cout << "Dequeue: " << array1.DeQueue() << endl;
    cout << "Cancel 20: " << array1.CancelOrder(20) << endl;
    cout << "Peek again: " << array1.Peek() << endl;

    FIFOLinkedList LinkedList1;
    cout << "\nSingly linked list queue:\n";
    cout << "80 is enqueued: " << LinkedList1.EnqueueLinkedList(80) << endl;
    cout << "90 is enqueued: " << LinkedList1.EnqueueLinkedList(90) << endl;
    cout << "100 is enqueued: " << LinkedList1.EnqueueLinkedList(100) << endl;
    cout << "Peek: " << LinkedList1.PeekLinkedList() << endl;
    cout << "Cancel 90: " << LinkedList1.CancelOrderLinkedList(90) << endl;
    cout << "Dequeue: " << LinkedList1.DeQueue() << endl;

    FIFODoublyLinkedList DoublyList1;
    cout << "\nDoubly linked list queue:\n";
    auto orderA = DoublyList1.EnqueueDoubly(500);
    auto orderB = DoublyList1.EnqueueDoubly(600);
    auto orderC = DoublyList1.EnqueueDoubly(700);
    cout << "Peek: " << DoublyList1.PeekDoubly() << endl;
    cout << "Cancel 600 by direct reference: " << DoublyList1.CancelByReference(orderB) << endl;
    cout << "Dequeue: " << DoublyList1.DeQueueDoubly() << endl;
    cout << "Dequeue: " << DoublyList1.DeQueueDoubly() << endl;

    // Prevent unused variable warnings in some compilers.
    (void)orderA;
    (void)orderC;

    return 0;
}
