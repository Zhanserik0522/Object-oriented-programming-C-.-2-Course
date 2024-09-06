#include <iostream>
using namespace std;

int binary_search(int* arr, int start, int end, int target) {
	while (start <= end) {
		int mid = start + (end - start) / 2;

		if (arr[mid] == target) {
			return mid;  
		}
		if (arr[mid] < target) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return -1;
}



int main() {
	int n;
	cout << "Size of array equal = ";
	cin >> n;

	int* arr = new int[n];

	cout << "Write your array ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int num;
	cout << "Target equal = ";
	cin >> num;


	

	
	int result = binary_search(arr, 0, n - 1 , num);

	cout << "Your target is or could be under the index = " << result << endl;

	delete[] arr;

	return 0;
}


