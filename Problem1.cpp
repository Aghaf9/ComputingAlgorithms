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

		int CanacelOrder(int target) {
			for (int i = start; i <= end; i++){
				if (array[i] == target)
					for (int j = i; j < end; j++){
						array[j] = array[j + 1];
					}
					end--;
					CountSize--;
					return 1;
			}
		}
		return 0;
}};



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
