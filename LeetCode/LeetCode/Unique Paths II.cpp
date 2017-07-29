#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {            
		const int MAX = 102;
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		int p[MAX][MAX] = { 0 };

		for (int i = 1; i <= n; i++)
			if (obstacleGrid[0][i-1] == 0)
				p[1][i] = 1;
			else
				break;

		for (int i = 1; i <= m; i++)
			if (obstacleGrid[i-1][0] == 0)
				p[i][1] = 1;
			else
				break;

		for (int i = 2; i <= m; i++)
			for (int j = 2; j <= n; j++)
				if (obstacleGrid[i - 1][j - 1] == 0)
					p[i][j] = p[i][j - 1] + p[i - 1][j];
				else
					p[i][j] = 0;

		
		return p[m][n];

	}

};

/*
int main()
{
	Solution solu;
	vector<vector<int>> v = { {0,0,0},{0,1,0},{0,0,0} };
	solu.uniquePathsWithObstacles(v);
}

*/