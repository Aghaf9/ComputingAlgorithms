#include<iostream>
using namespace std;



class SelectionSort {

public:
	void sort(int array[], int size){
		selectSort(array, size);
	}
private:
	void selectSort(int array[], int size){
		for(int i = 0; i < size; i++){
			//current index has the smallest vlue
			int minIndex = i;
			//searching the rest of the array for something smaller
			for (int j = i + 1; j < size; j++){
				if (array[j] < array[minIndex]) {
					minIndex = j;
			}
		}
		//swap the smallest val into the current pos
		
		swap(array[i], array[minIndex]);
			}
		}
};





int main(){
	int array[10] = {10, 7, 8, 9, 1, 5, 3, 2, 4, 6};
	int size = sizeof(array) / sizeof(array[0]);
	SelectionSort select;	
	//print unsorted array
	cout << "Unsorted array: ";
	for (int i = 0; i < size; i++) cout << array[i] << " ";
	cout << endl;

	//call insertionsort
	select.sort(array, size);

	//print sorted array
	cout << "Sorted array: ";
	for (int i = 0; i < size; i++) cout << array[i] << " ";
	cout << endl;


	return 0;
};
