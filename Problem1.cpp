#include<iostream>
using namespace std;


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

		int DeQueue;



		int peek;
}



//FIFO Queue
//n = 0
//Head[n], Tail = [length(n)/(n)]
//Head[0+1], Tail[n+1] shift to the right


//EnQueue


//DeQueue


//ViewNextOrder








int main() {

int FIFOarray[10] = {}







}
