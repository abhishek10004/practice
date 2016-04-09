// http://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/

#include <iostream>
#include <string>
using namespace std;

void compute_lps(int* lps, string& pattern)
{
	int len = 0;	// this will be used to determine the value for lps[i], this will be the index of the prefix 
	int i=1;
	lps[0] = 0;
	
	while(i < pattern.size())
	{
		if(pattern[i] == pattern[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if(len !=  0)
				len = lps[len-1];
			else
				lps[i++] = 0;
		}
	} 
}

void kmp(string& text, string& pattern, int* lps)
{
	int i=0,j=0, len;
	while(i<text.size())
	{
		if(text[i] == pattern[j])
		{
			i++;
			j++;
			if(j == pattern.size())
			{
				cout << "Pattern found at index " << i - j << endl;
				j = lps[j-1];
			}
		}
		else
		{
			if(j!=0)
				j = lps[j-1];
			else
				i++;
		}
	}
}

int main()
{
	string text, pattern;
	cout << "Enter the text & the pattern\n";
	getline(cin, text);
	getline(cin, pattern);
	int *lps = new int[pattern.size()];
	compute_lps(lps, pattern);
	kmp(text, pattern, lps);
	return 0;
}
