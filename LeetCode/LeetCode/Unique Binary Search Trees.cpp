#include <iostream>
using namespace std;

class Solution {
public:
	int numTrees(int n) {
		int f[1000] = { 0 };
		f[0] = 1;
		f[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				f[i] += f[j - 1] * f[i - j];
			}
		}
		return f[n];

	}
};


/*


int main()
{
	Solution solu;
	cout << solu.numTrees(3);
}


*/