//http://www.geeksforgeeks.org/dynamic-programming-set-4-longest-common-subsequence/


#include<iostream>
using namespace std;

int max(int a, int b){
	return (a>b) ? a : b;
}

int lcs(char *a, char *b, int **table, int i, int j, int n, int m){
	if(i>=n || j>=m)
		return 0;
	if(table[i][j] != -1)
		return table[i][j];
	if(a[i] == b[j])
		table[i][j] = 1 + lcs(a, b, table, i+1, j+1, n, m);
	else
		table[i][j] = max( lcs(a, b, table, i, j+1, n, m), lcs(a, b, table, i+1, j, n, m) );
	return table[i][j];
}

int main(){
	int n,m;
	char *a, *b;
	cout << "Enter the size of the 2 arrays\n";
	cin >> n >> m;
	a = new char[n];
	b = new char[m];
	cout << "Enter the first sequence (Enter space between each characters)\n";
	for(int i=0;i<n;i++)
		cin >> a[i];
	cout << "Enter the second sequence (Enter space between each characters)\n";
	for(int i=0;i<m;i++)
		cin >> b[i];
	int ** table;
	table = new int *[n];
	for(int i=0;i<n;i++)
		table[i] = new int[m];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			table[i][j] = -1;
	if(a[n-1] == b[m-1])
		table[n-1][m-1] = 1;
	else
		table[n-1][m-1] = 0;
	cout << "The length of the longest common subsequence is " << lcs(a, b, table, 0, 0, n, m) << endl;
	return 0;
}
