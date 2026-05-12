#include<iostream>
using namespace std;

class InsertionSort {

public:		
	void sort(int array[], int size) {
		for(int i = 1; i < size; i++){
			//the current val we want to insert
			int key = array[i];
			//start comparing with prev element
			int j = i - 1;
			//shifting larger value right
			while (j >= 0 && array[j] > key){
				//move move one larger value right
				array[j + 1] = array[j];
				//move backwards
				j--;
			}
			//insert key into pos
			array[j + 1] = key;
		}
	}
};



int main(){
	int array[10] = {10, 7, 8, 9, 1, 5, 3, 2, 4, 6};
	int size = sizeof(array) / sizeof(array[0]);
	InsertionSort is;	
	//print unsorted array
	cout << "Unsorted array: ";
	for (int i = 0; i < size; i++) cout << array[i] << " ";
	cout << endl;

	//call insertionsort
	is.sort(array, size);

	//print sorted array
	cout << "Sorted array: ";
	for (int i = 0; i < size; i++) cout << array[i] << " ";
	cout << endl;


	return 0;
};
