// www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/

#include<iostream>
using namespace std;

int n;
int no_coins;
int * coins;
int ** ways;

int coin_change(int cents, int coin_index){
	if(cents < 0 || coin_index > no_coins)
		return 0;
	if(ways[cents][coin_index] != -1)
		return ways[cents][coin_index];
	ways[cents][coin_index] = coin_change(cents, coin_index + 1) + coin_change(cents - coins[coin_index], coin_index);
	return ways[cents][coin_index];
}

int main(){
	cout << "Enter the no. of coins\n";
	cin >> no_coins;
	coins = new int[no_coins];
	cout << "Enter the denomination of the coins\n";
	for(int i=0;i<no_coins;i++)
		cin >> coins[i];
	cout << "Enter the value of n\n";
	cin >> n;
	ways = new int*[n+1];
	for(int i=0;i<=n;i++)
		ways[i] = new int[no_coins];
	for(int i=0;i<=n;i++)
		for(int j=0;j<no_coins;j++)
			ways[i][j] = -1;
	// Base case
	for(int i=0;i<no_coins;i++)
		ways[0][i] = 1;			// for o cents, no of ways is exactly 1
	for(int i=1;i<=n;i++){
		if(i % coins[no_coins-1] == 0)
			ways[i][no_coins-1] = 1;
		else
			ways[i][no_coins-1] = 0;
	}
	
	cout << "We can make the change for " << n << " cents in " << coin_change(n, 0) << " ways\n";
	return 0;
}
