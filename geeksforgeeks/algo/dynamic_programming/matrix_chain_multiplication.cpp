// http://www.geeksforgeeks.org/dynamic-programming-set-8-matrix-chain-multiplication/

#include<iostream>
using namespace std;

#define INF 999999999999

int no_matrices;
int * dimensions;
long long ** cost;

long long mult_matrix(int start, int end){
	if(start >= end)
		return 0;
	else if(start < 0 || end > no_matrices - 1)
		return 0;

	if(cost[start][end] != -1)
		return cost[start][end];
		
	long long min = INF;
	long long c;
	for(int i=start;i<end;i++){
		c = mult_matrix(start, i) + mult_matrix(i+1, end) + (dimensions[start] * dimensions[i+1] * dimensions[end+1]);
		if(c < min)
			min = c;
	}
		
	cost[start][end] = min;
	return min;
}


int main(){
	cout << "Enter the number of matrices\n";
	cin >> no_matrices;
	dimensions = new int[no_matrices + 1];
	for(int i=0;i<=no_matrices;i++)
		cin >> dimensions[i];
	cost = new long long * [no_matrices];
	for(int i=0;i<no_matrices;i++)
		cost[i] = new long long[no_matrices];
	for(int i=0;i<no_matrices;i++)
		for(int j=0;j<no_matrices;j++)
			cost[i][j] = -1;
	
	for(int i=0;i<no_matrices;i++)
		cost[i][i] = 0;	
	
	cout << "Min cost of multiplying the matrices is " << mult_matrix(0, no_matrices-1) << endl;
	
	return 0;
}