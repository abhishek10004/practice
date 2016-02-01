// http://www.geeksforgeeks.org/dynamic-programming-set-9-binomial-coefficient/

// instead of using dp, could have also done this by simplifying the formula & then calculating the value (would have been faster & space efficient)

#include <iostream>
using namespace std;

int n;
int k;
int ** c;


int binomial_coefficient(int n, int k){
	if(n<k || n == 0)
		return 0;
	if(c[n][k] != -1)
		return c[n][k];
	c[n][k] = binomial_coefficient(n-1, k-1) + binomial_coefficient(n-1, k);
	return c[n][k];
}

int main(){
	cout << "Enter the value of n & k\n";
	cin >> n >> k;
	
	c = new int * [n+1];
	for(int i=0;i<=n;i++)
		c[i] = new int[k+1];
	
	for(int i=0;i<=n;i++)
		for(int j=0;j<=k;j++)
			c[i][j] = -1;
	
	for(int i=0;i<=n;i++)
		c[i][0] = c[i][i] = 1;
	
	cout << "C(" << n << "," << k << ") is " << binomial_coefficient(n, k) << endl;
	
	return 0;
	
}