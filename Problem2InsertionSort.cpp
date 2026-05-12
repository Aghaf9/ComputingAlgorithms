#include<iostream>


class InsertionSort {

	public:
		
		void sort(int array[], int size) {
			for(int i = 1; i < size; i++){
				//the current val we want to insert
				int key = array[i];
				//start comparing with prev element
				int j = array[i];
				//shifting larger value right
				while (j >= 0 && array[j] > key){
					//move move one larger value right
					array[j + 1] = array[i];
					//move backwards
					j--;
				}
				//insert key into pos
				array[j + 1] = key;
			}
		}





	Private:








};
