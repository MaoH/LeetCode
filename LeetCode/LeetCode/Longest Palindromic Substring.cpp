#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		const int size = s.size();
		const int Max = 1000;
		bool p[Max][Max] = {false};
		int maxLen = 1, start = 0;

		for (int i = 0; i < size; i++)
		{
			p[i][i] = true;
			if ((i < size - 1) && (s[i] == s[i + 1]))
			{
				p[i][i + 1] = true;
				if (maxLen < 2)
				{
					maxLen = 2;
					start = i;
				}
			}
		}

		for (int len = 3; len <= size; len++)
			for (int i = 0; i < size - len + 1; i++)
				if ((s[i] == s[i + len - 1]) && (p[i+1][i+len-2]))
				{
					p[i][i + len - 1] = true;
					if (maxLen < len)
					{
						maxLen = len;
						start = i;
					}
				}
		return s.substr(start, maxLen);
		
	}


};

/*
int main()
{
	Solution solu;
	std::cout << solu.longestPalindrome("ccc");
	return 0;
}

*/