#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	int numDecodings(string s) {
		int len = s.length();

		if (len == 0)
			return 0;

		if (s[0] == '0')
			return 0;

		if (len == 1)
			return 1;

		vector<int> vi;
		int code = std::atoi(s.substr(0, 2).c_str());
		
		if (code > 20 && code % 10 == 0)
			return 0;
		if (code > 10 && code <= 26 && code != 20)
		{
			vi.push_back(1);
			vi.push_back(2);
		}
		else
		{
			vi.push_back(1);
			vi.push_back(1);
		}


		for (int i = 2; i < len; i++)
		{
			int code = std::atoi(s.substr(i - 1, 2).c_str());
			if (code == 0)
				return 0;
			if (code > 20 && code % 10 == 0)
				return 0;
			if (code == 10 || code == 20)
				vi.push_back(vi[i - 2]);
			else if (code>10 && code <= 26)
				vi.push_back(vi[i - 1] + vi[i - 2]);
			else
				vi.push_back(vi[i - 1]);
		}
		return vi[len - 1];
	}
};


/*
int main()
{
	Solution solu;
	cout<<solu.numDecodings("20")<<endl;
	
}

*/

/*
f(n) =
		0						  code = 0;
		f(n - 1)			      1 <= code <= 9;
		f(n - 2)                  code = 10 or code = 20;
		f(n - 1) + f(n - 2)       11 <= code <= 26 and code != 20;
		f(n - 1)                  code > 26 and code % 10 != 0;
		0                         code = 30, 40, 50...90;



*/
