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

}










int main(){







	return 0;
}
