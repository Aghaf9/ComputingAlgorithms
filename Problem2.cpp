#include<iostream>
using namespace std;
//QuickSort
class QuickSort 
{



	public:
		void sort(int array[], int size) {
			quickSort(array, 0, size - 1);
		}
	private:
		//partition function

		//->pick a pivot
		//->Place it in the correct partition
		//->move smaller elemenets left and larger right
		int partition(int array[], int low, int high) {
			int pivot = array[high];
			int i = low -1;
			
			//loop from low to hight-1
			for (int j = low; j < high; j++) {
				//if current < pivot
				if(array[j] < pivot){
					i++;
					//swap current element with element at i
					swap(array[i], array[j]);
				}
			}
			//place 
		swap(array[i+1], array[high]);	
		//pivot index
			return i+1;	

		}
		void quickSort(int array[], int low, int high) {
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
