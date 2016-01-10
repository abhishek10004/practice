// http://www.geeksforgeeks.org/dynamic-programming-set-3-longest-increasing-subsequence/

#include<iostream>
using namespace std;

int main(){
	int n, *arr, *res;
	cout << "Enter the size of the array\n";
	cin >> n;
	arr = new int[n];
	res = new int[n];
	cout << "Enter the elements\n";
	for(int i=0;i<n;i++)
		cin >> arr[i];
	for(int i=0;i<n;i++)
		res[i] = -1;
	res[0] = 1;
	for(int i = 1;i<n;i++){
		int max = 1;
		for(int j=i-1;j>=0;j--){
			if(arr[i] > arr[j]){
				if(res[j] >= max)
					max = res[j] + 1;
			}
		}
		res[i] = max;
	}
	
	int lis = res[0];
	for(int i=1;i<n;i++){
		if(lis < res[i])
			lis = res[i];
	}
	cout << "The length of the longest increasing subsequence is " << lis << endl;
	return 0;
}
