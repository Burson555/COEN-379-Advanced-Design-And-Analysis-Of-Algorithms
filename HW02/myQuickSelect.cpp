#include <iostream>
#include <ctime>
using namespace std;

int myRandomQuickSelect(int arr[], int low, int high, int k);
int partition(int arr[], int low, int high);
void swap(int arr[], int a, int b);

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int arr[] = {1,3,2,4,7,6,9,5,8,0,10};
	myRandomQuickSelect(arr, 0, 10, 5);
	for (int i = 0; i < 10; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}

int myRandomQuickSelect(int arr[], int low, int high, int k) {
	if (k < low || k > high){
		return -1;
	} else if (low == high) {
		return k;
	}

	int ppos = partition(arr, low, high);
	int prank = ppos - low + 1;
	if (k == prank) {
		return k;
	} else if (k < prank) {
		myRandomQuickSelect(arr, low, ppos-1, k);
	} else {
		myRandomQuickSelect(arr, ppos+1, high, k-(ppos-low+1));
	}

	return k;
}

int partition(int arr[], int low, int high) {
	int i = low;
	int pivot = rand() % (high-low+1);
	swap(arr, high, pivot);
	for (int j = low; j < high; j++) {
		if (arr[j] < arr[high])
			swap(arr, j, i++);
	}
	swap(arr, i, high);
	return i;
}

void swap(int arr[], int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
