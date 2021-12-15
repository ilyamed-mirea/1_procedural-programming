// C++ implementation of Radix Sort
#include <iostream>
#include <vector>
using namespace std;

// A function to do counting sort of arr[] according to the digit represented by exp.
vector<int> countSortcom(vector<int> arr, int exp) {
	vector<int> output(arr.size()); // output array
	int i, count[10] = { 0 };
	cout << endl << "begin cycle" << endl;
	// Store count of occurrences in count[]
	cout << "ff" << endl;
	for (i = 0; i < arr.size(); i++) {
		cout << "filling count" << endl;
		count[(arr[i] / exp) % 10]++; // (arr[i] / exp) % 10 - current digit
		cout << "index: " << (arr[i] / exp) % 10 << ", val: " << count[(arr[i] / exp) % 10] << "; ";
	}
	cout << "ff end" << endl;
	// Change count[i] so that count[i] now contains actual
	// position of this digit in output[]
	cout << "sdvig start" << endl;
	for (i = 1; i < 10; i++) {
		cout << count[i] << " + " << count[i - 1] << " = " << count[i] + count[i - 1] << endl;
		count[i] += count[i - 1];
	}
	cout << "sdv end" << endl;

	// Build the output array
	for (i = arr.size() - 1; i >= 0; i--) {
		cout << "output[" << count[(arr[i] / exp) % 10] - 1 << "] = " << arr[i] << endl;
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	return output;
}


void radix_sort(int *a, int n) {
	int i = 0, b[100], m = 0, exp = 1;
	for (i = 0; i < n; i++)
		if (a[i] > m)
			m = a[i];
	for (exp; m / exp > 0; exp *= 10) {
		int box[10] = { 0 };
		i = 0;
		for (i = 0; i < n; i++) {
			box[(a[i] / exp) % 10]++;
		}
		for (i = 1; i < 10; i++) {
			box[i] += box[i - 1];
		}
		for (i = n - 1; i >= 0; i--) {
			b[--box[(a[i] / exp) % 10]] = a[i];
		}
		for (i = 0; i < n; i++) {
			a[i] = b[i];
		}
	}
}
// Driver Code
int mainn()
{
	cout << "radix sort" << endl << "write numbers" << endl;
	int arr[100] = {0};
	int n=0,x;
	while (cin>>x) {
		arr[n]=x;
		n++;
	}
	radix_sort(arr,n);
	cout << "output: " << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}
