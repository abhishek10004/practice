// http://www.geeksforgeeks.org/square-root-of-an-integer/

#include<iostream>
using namespace std;

// I think we can use binary search here to do this

bool check_square_root(int n, int var)
{
	if( (var-1) * (var-1) < n && (var+1) * (var+1) > n)
		return true;
	return false;
}

int square_root(int n, int low, int high)
{
	int mid = low + (high - low)/2;
	if(check_square_root(n, low))
		return low;
	else if(check_square_root(n, high))
		return high;
	else if (check_square_root(n, mid))
		return mid;
	if (mid * mid > n)
		return square_root(n, low, mid);
	else if(mid * mid < n)
		return square_root(n, mid, high);
}

int main()
{
	int n;
	cout << "Enter the number\n";
	cin >> n;
	if(n == 1 || n == 2 || n == 3)
		return 1;
	cout << square_root(n, 1, n) << endl;
	return 0;
}