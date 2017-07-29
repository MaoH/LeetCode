#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;


class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<string> board;
		for (int i = 0; i < n; i++)
		{
			string str;
			for (int j = 0; j < n; j++)
			{
				str = str + ".";
			}
			board.push_back(str);
		}
		DFS(board, 0);
		return vvs;

	}

	void DFS(vector<string>& board, int n)
	{
		int N = board.size();
		if (N == n)
		{
			vvs.push_back(board);
			return;
		}
		for (int i = 0; i < N; i++)
		{
			board[n][i] = 'Q';
			if(check(board,n))
				DFS(board, n + 1);
			board[n][i] = '.';
		}
	}


	bool check(vector<string>& board, int n)
	{
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				int count = 0;
				if (board[i][j] == 'Q')
					count++;
				if (count > 1)
					return false;
			}
			for (int j = 0; j <= n; j++)
			{
				int count = 0;
				if (board[j][i] == 'Q')
					count++;
				if (count > 1)
					return false;
			}                                                
		}                                                      ////////
		for (int sum = 0; sum <= n; sum++)
		{
			int count = 0;
			for (int i = 0; i <= sum; i++)
			{
				if (board[i][sum - i] == 'Q')
					count++;
				if (count > 1)
					return false;
			}
		}
		for (int sum = 0; sum <= n; sum++)
		{
			int count = 0;
			for (int i = 0; i <= sum; i++)
			{
				if (board[i][sum - i] == 'Q')
					count++;
				if (count > 1)
					return false;
			}
		}
		

	}

private:
	vector<vector<string>> vvs;
};