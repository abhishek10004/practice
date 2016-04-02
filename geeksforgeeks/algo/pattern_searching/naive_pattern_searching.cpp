// http://www.geeksforgeeks.org/searching-for-patterns-set-1-naive-pattern-searching/

#include <iostream>
#include <string>
using namespace std;

// will return the index of the pattern if found, otherwise will return -1
int search(string & text, string & pattern, int index)
{
	for(int i=index;i<text.size();i++)
	{
		if(text[i] == pattern[0])
		{
			int match = true;
			for(int j=0;j<pattern.size();j++)
			{
				if(text[i+j] != pattern[j])
				{
					match = false;
					break;
				}
			}
			if(match)
				return i;
		}
	}
	return -1;
}

int main()
{
	string text, pattern;
	cout << "Enter the text\n";
	getline(cin, text);
	cout << "Enter the pattern\n";
	getline(cin, pattern);
	int res = -1;
	bool atleast_once = false;
	while(true)
	{
		res = search(text, pattern, res + 1);
		if(res == -1)
			break;
		else{
			atleast_once = true;
			cout << "The pattern was found at index " << res << endl;
		}
	}
	if(!atleast_once)
		cout << "The pattern was not found inside the text\n";
	return 0;
}
