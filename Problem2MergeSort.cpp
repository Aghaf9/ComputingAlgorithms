#include<iostream>
using namespace std;
//QuickSort
class MergeSort 
{



	public:
		void sort(int array[], int size) {
			mergeSort(array, 0, size - 1);
		}
	private:

		//->pick a middle
		//->Place it in the correct partition
		//->move smaller elemenets left and larger right
		int merge(int array[], int low, int high) {
			int middle = low + (high - low) / 2
		//loop from low to hight-1
			for (int j = low; j < high; j++) {
				//if current < middle
				if(array[j] < middle){
					i++;
					//swap current element with element at i
				}
			}


		}


		void mergeSort(int array[], int low, int high) {
			//only sort if if there are more than 1 element
			if (low < high) {
				int pivotIndex = partition(array, low, high);
				quickSort(array, low, pivotIndex - 1);
				quickSort(array, pivotIndex + 1, high);
			}
		}
};




int main(){
	int array[10] = {10, 7, 8, 9, 1, 5, 3, 2, 4, 6};
	int size = sizeof(array) / sizeof(array[0]);
	QuickSort qs;	
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
