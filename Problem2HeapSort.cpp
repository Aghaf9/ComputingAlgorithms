#include<iostream>

using namespace std;


class HeapSort 
{
public:
	void sort(int array[], int size) {
		heapSort(array, size);
	}

private:
	void Heapify(int array[], int size, int parent) {
		//parent is initially the largest
		int largest = parent;
		//calculating chilldren	

		int leftChild = 2 * parent + 1;
		int rightChild = 2 * parent + 2;

		//comparing left child
		if (leftChild < size && array[leftChild] > array[largest]) {
			largest = leftChild;
		}
		//comparing right child
		if (rightChild < size && array[rightChild] > array[largest]) {
			largest = rightChild;
		}
			
		//if the parent is not the target
		if (largest != parent) {
			swap(array[parent], array[largest]);
			Heapify(array, size, largest);

		}
	}
		
	void heapSort(int array[], int size) {
		//move largest element left 
		//shriniking each head after iterations
		for (int i = size / 2 - 1; i >= 0; i--){
			Heapify(array, size, i);
		}
		//move current largest to the end
		for (int i = size - 1; i > 0; i--){
		swap(array[0], array[i]);
		Heapify(array, i, 0);
		}
	}
};




int main(){
	int array[10] = {10, 7, 8, 9, 1, 5, 3, 2, 4, 6};
	int size = sizeof(array) / sizeof(array[0]);
	HeapSort qs;	
	//print unsorted array
	cout << "Unsorted array: ";
	for (int i = 0; i < size; i++) cout << array[i] << " ";
	cout << endl;

	//call quicksort
	qs.sort(array, size);

	//print sorted array
	cout << "Sorted array: ";
	for (int i = 0; i < size; i++) cout << array[i] << " ";
	cout << endl;


	return 0;
}



