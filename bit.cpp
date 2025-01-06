#include <bits/stdc++.h> 
using namespace std; 

int getSum(int BITree[], int index) 
{ 
	int sum = 0;
	index = index + 1; 

	cout << "\nget sum of " << index << "\n";
	while (index>0) 
	{ 
		cout << index << " - ";
		sum += BITree[index]; 
		index -= index & (-index); 

	}
	cout << "\nsum: " << sum << endl;
	return sum; 
} 

void updateBIT(int BITree[], int n, int index, int val) 
{ 
	index = index + 1; 
	while (index <= n) 
	{ 
		BITree[index] += val; 
		index += index & (-index); 
	} 
} 

int* constructBITree(int arr[], int n) 
{ 
	int *BITree = new int[n+1]; 
	for (int i=1; i<=n; i++) 
		BITree[i] = 0; 

	for (int i=0; i<n; i++) 
		updateBIT(BITree, n, i, arr[i]); 

	for (int i=1; i<=n; i++) 
		 cout << BITree[i] << " "; 

	return BITree; 
}

int getRangeSum(int BITree[], int from, int to) {
	return getSum(BITree, to) - getSum(BITree, from);
}


int main() 
{ 
	int freq[] = {5,2,9,-3,5,20,10,-7,2,3,-4,0,-2,15,5}; 
	int n = sizeof(freq)/sizeof(freq[0]); 
	int *BITree = constructBITree(freq, n); 
	cout << "\nSum of elements in arr[2..5] is "
		<< getRangeSum(BITree, 2, 5); 

	// Add 6 to 3rd
	updateBIT(BITree, n, 3, 6); 

	cout << "\nSum of elements in arr[2..5] after update is "
		<< getRangeSum(BITree, 2, 5); 

	return 0; 
} 
