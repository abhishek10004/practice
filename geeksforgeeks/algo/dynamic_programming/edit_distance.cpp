#include<iostream>
#include<string>
using namespace std;

const int c = 1;		// cost of the operations
const int inf = 1000000;

int min(int a, int b, int c){
	if(a <=b && a <= c) return a;
	else if(b<=a && b<=c ) return b;
	return c;
}

int edit_distance(string & str1, string & str2, int ** table, int i, int j){
	if(i>str1.size() || j>str2.size())
		return inf;
	
	if(table[i][j] != -1)
		return table[i][j];
	
	if(str1[i] == str2[j])
		table[i][j] = edit_distance(str1, str2, table, i+1, j+1);
	else
		table[i][j] = c + min(edit_distance(str1, str2, table, i, j+1), edit_distance(str1, str2, table, i+1, j), edit_distance(str1, str2, table, i+1, j+1));
	
	return table[i][j];
}

int main(){
	string str1, str2;
	int ** table;
	cout << "Enter the two strings\n";
	cin >> str1 >> str2;
	table = new int * [str1.size()+1];
	for(int i=0;i<=str1.size();i++)
		table[i] = new int[str2.size()+1];
	for(int i=0;i<=str1.size();i++)
		for(int j=0;j<=str2.size();j++)
			table[i][j] = -1;
	for(int i=0;i<str1.size();i++)
		table[i][str2.size()] = str1.size() - i - 1;
	for(int j=0;j<str2.size();j++)
		table[str1.size()][j] = str2.size() - j - 1;
	table[str1.size()][str2.size()] = 0;
	cout << "The edit distance between " << str1 << " and " << str2 << " is " << edit_distance(str1, str2, table, 0, 0) << endl;
	return 0;
}