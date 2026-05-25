#include<iostream>
#include<chrono>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<string>

using namespace std;
using namespace chrono;
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
//time complexity sections
//fills array with random values
void makeRandomList(int array[], int size) {
    for(int i = 0; i < size; i++) {
        array[i] = rand() % 1000000;
    }
}

//fills array in reverse order
void makeReverseList(int array[], int size) {
    for(int i = 0; i < size; i++) {
        array[i] = size - i;
    }
}

//mostly small values with a few large outliers
void makeExtremeList(int array[], int size) {
    for(int i = 0; i < size; i++) {
        array[i] = 1;
    }

    for(int i = 0; i < size; i += 100) {
        array[i] = 1000000;
    }
}

//fills array with many duplicate values
void makeDuplicateList(int array[], int size) {
    for(int i = 0; i < size; i++) {
        array[i] = i % 5;
    }
}

//benchmark function using chrono
double testQuickSort(int array[], int size) {
    QuickSort sorter;

    auto start = high_resolution_clock::now();

    sorter.sort(array, size);

    auto stop = high_resolution_clock::now();

    duration<double, milli> timeTaken = stop - start;

    return timeTaken.count();
}



int main() {
    srand(time(0));

    int sizes[] = {1000, 5000, 10000, 20000, 30000, 40000, 50000, 100000, 500000};
    int numberOfSizes = 9;

    string dataTypes[] = {"Random", "Reverse", "Extreme", "Duplicates"};
    int numberOfDataTypes = 4;

    ofstream file("QuickSortResults.csv");

    file << "Algorithm,DataType,Size,TimeMilliseconds\n";

    for(int d = 0; d < numberOfDataTypes; d++) {
        for(int s = 0; s < numberOfSizes; s++) {

            int size = sizes[s];

                if(size > 50000 && dataTypes[d] != "Random") {
                file << "QuickSort," << dataTypes[d] << "," << size << ",SKIPPED\n";
                cout << "QuickSort " << dataTypes[d] << " " << size << " SKIPPED" << endl;
                continue;
            }

            int* array = new int[size];

            if(dataTypes[d] == "Random") {
                makeRandomList(array, size);
            }
            else if(dataTypes[d] == "Reverse") {
                makeReverseList(array, size);
            }
            else if(dataTypes[d] == "Extreme") {
                makeExtremeList(array, size);
            }
            else {
                makeDuplicateList(array, size);
            }

            double time = testQuickSort(array, size);

            file << "QuickSort," << dataTypes[d] << "," << size << "," << time << "\n";

            cout << "QuickSort " << dataTypes[d] << " " << size << " " << time << " ms" << endl;

            delete[] array;
        }
    }

    file.close();

    cout << "The QuickSort benchmark complete. Results saved to QuickSortResults.csv" << endl;

    return 0;
}
