#include<string>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
/*
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int maxLen= 0;
		for (int i = 0; i < s.size(); i++)
		{
			int len = 0;
			for (int j = i; j < s.size(); j++)
			{
				if (hasChar(s, i, j, s[j]))
					break;
				len++;
				if (len > maxLen)
					maxLen = len;
				
			}
		}
		return maxLen;
	}

	inline bool hasChar(string s ,int i , int j , char ch)
	{
		while (i < j)
		{
			if (s[i++] == ch)
				return true;
		}
		return false;
	}
};

*/

/*
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		set<char> cSet;
		int maxlength=0;
		int i = 0, j = 0;
		while (j<s.size())
		{
			if (cSet.find(s[j]) != cSet.end())
			{
				cSet.erase(s[i++]);
			}
			else
			{
				cSet.insert(s[j++]);
				maxlength = max(maxlength, j - i);
			}
		}
		return maxlength;

	}

};


*/

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int> myMap;
		
		int maxLength = 0;
		for (int j = 0,i = 0; j < s.size();j++)
		{
			if (myMap.find(s[j]) != myMap.end())
			{
				i = max(myMap[s[j]]+1, i);
			}
			maxLength = max(maxLength, j - i+1);
			myMap.erase(s[j]);
			myMap.insert(pair<char, int>(s[j], j));
			
		}
		return maxLength;
	}

};

