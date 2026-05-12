#include<iostream>

using namespace std;


class HeapSort 
{
public:
	void sort(int array[], int size) {
		heapSort(array, size);
	}

private:
	void Heapify(int array[], int parent, int size) {
		int leftChild = 2 * parent + 1;
	
		int rightChild = 2 * parent + 2;
		
		if (leftChild < size && array[leftChild] > array[largest]) {
			largest = leftChild;
		}

		if (rightChild < size && array[rightChild] > array[largest]) {
			largest = rightChild;
		}
			

		if (larget != parent) {
			swap(array[parent], array[largest]);
			Heapify(array, size, largest);

		}
	}
		
	void heapSort(int array[], int size) {
		for (int i = size / 2 - 1; i >= 0; i--){
			Heapify(array, size, i);
		}
	
		for (int i = sise - 1; i > 0; i--){
		swap(array[0], array[i]);
		Heapify(array, i, 0);
		}
	}
};




int main(){







	return 0;
}
