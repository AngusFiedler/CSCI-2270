#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////
void heapify(float arr[], int arraySize, int i) 
{ 
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (right < arraySize && arr[right] > arr[largest]){
        largest = right; 
    }
    if (left < arraySize && arr[left] > arr[largest]){
        largest = left; 
    } 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]);
        heapify(arr, arraySize, largest); 
    } 
}
////////////////////////////////////////////////////////////////////////
float * heapSort(float arr[], int arraySize) 
{
	/*
	float newArray[arraySize];
	float *ptr = newArray;
	for(int t = 0; t < arraySize; t++){
		newArray[t] = arr[t];
	}
	*/
    for (int i = arraySize / 2 - 1; i >= 0; i--) {
        heapify(arr, arraySize, i); 
    } 
    for (int i=arraySize-1; i>=0; i--) 
    { 
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0); 
    }
    return arr;
}

int main(){
	//should return 1.2,5,10.5,15,20.7
	cout << "----------------" << endl;
	cout << "TEST 1" << endl;
	cout << "----------------" << endl;
	int arrSize1 = 5;
	float arr1[] = {1.2,10.5,5,15,20.7};
	heapSort(arr1, arrSize1);
	for(int i =0; i< arrSize1; i++){
		cout << arr1[i];
		if(i+1 < arrSize1){
			cout << " - ";
		}
	}
	cout << endl;

	//should just return 5
	cout << "----------------" << endl;
	cout << "TEST 2" << endl;
	cout << "----------------" << endl;
	int arrSize2 = 1;
	float arr2[] = {5};
	heapSort(arr2,arrSize2);
	for(int i =0; i< arrSize2; i++){
		cout << arr2[i];
		if(i+1 < arrSize2){
			cout << " - ";
		}
	}
	cout << endl;


	//should return 8.2,30,34
	cout << "----------------" << endl;
	cout << "TEST 3" << endl;
	cout << "----------------" << endl;
	int arrSize3 = 3;
	float arr3[] = {30,8.2,34};
	heapSort(arr3,arrSize3);
	for(int i =0; i< arrSize3; i++){
		cout << arr3[i];
		if(i+1 < arrSize3){
			cout << " - ";
		}
	}
	cout << endl;

}