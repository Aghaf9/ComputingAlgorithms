#include<iostream>
using namespace std;
//MergeSort is a divide and conquer algorithm that divides the input array 
//into two halves, calls itself for the two halves, and then merges the two 
//sorted halves. The merge() function is used for merging two halves. The merge(arr, l, m, r) 
//is a key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two 
//sorted sub-arrays into one.
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
		void merge(int array[], int low, int mid, int high) {
			int leftTree = mid - low + 1;
			int rightTree = high - mid;
			
			int left[leftTree];
			int right[rightTree];

			for (int i = 0; i < leftTree; i++){
				left[i] = array[low + i]}

			for (int j = 0; i < rightTree; i++){
				right[j] = array[mid + 1 + j]}

			int i = 0, j = 0, k = low;
			

			while (i < leftTree && j < rightTree){
				if (left[i] <= right[j]){
					array[k] = left[i];
					i++
				}
				k++;
			}




		void mergeSort(int array[], int low, int high) {
			//only sort if if there are more than 1 element
			if (low < high) {
				int pivotIndex = merge(array, low, high);
				MergeSort(array, low, pivotIndex - 1);
				MergeSort(array, pivotIndex + 1, high);
			}
		}
};




int main(){
	int array[10] = {10, 7, 8, 9, 1, 5, 3, 2, 4, 6};
	int size = sizeof(array) / sizeof(array[0]);
	MergeSort qs;	
	//print unsorted array
	cout << "Unsorted array: ";
	for (int i = 0; i < size; i++) cout << array[i] << " ";
	cout << endl;

	//call mergesort
	qs.sort(array, size);

	//print sorted array
	cout << "Sorted array: ";
	for (int i = 0; i < size; i++) cout << array[i] << " ";
	cout << endl;


	return 0;
}
