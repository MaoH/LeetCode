#include <iostream>

class Solution {
public:
	int uniquePaths(int m, int n) {                    //直接计算应为要计算n！，会溢出。
		const int MAX = 102;
		int p[MAX][MAX];

		for (int i = 0; i < MAX; i++)
			p[1][i] = 1;
		for (int i = 0; i < MAX; i++)
			p[i][1] = 1;

		for(int i=2;i<=m;i++)
			for (int j = 2; j <= n; j++)
			{
				p[i][j] = p[i][j - 1] + p[i - 1][j];
			}

		return p[m][n];

	}

};

/*
int main()
{
	Solution solu;
	std::cout << solu.uniquePaths(2, 7) << std::endl;;
}


*/