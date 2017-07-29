#include <iostream>
#include <vector>
#include <set>
using namespace std;


class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		DFS(0,board);
	}
private:
	bool DFS(int n, vector<vector<char>>& board)
	{
		if (n == N*N)
			return true;
		int x = n / N;
		int y = n%N;
		if (board[x][y] == '.')
		{
			for (int i = 1; i <= 9; i++)
			{
				board[x][y] = i + '0';
				if (IsValid(x, y,board))
					if (DFS(n + 1,board))
						return true;
				board[x][y] = '.';
			}
		}
		else
		{
			if (DFS(n + 1,board))
				return true;
		}
		return false;
	}

	bool IsValid(int x, int y, vector<vector<char>>& board)
	{
		sc.clear();
		int count = 0;
		for (int i = 0; i < N; i++)
		{
			if (board[x][i] != '.')
			{
				count++;
				sc.insert(board[x][i]);
			}
		}
		if (count != sc.size())
			return false;

		count = 0;
		sc.clear();
		for (int i = 0; i < N; i++)
		{
			if (board[i][y] != '.')
			{
				count++;
				sc.insert(board[i][y]);
			}
		}
		if (count != sc.size())
			return false;

		count = 0;
		sc.clear();
		int x0 = (x / 3) * 3;
		int y0 = (y / 3) * 3;
		for (int i = 0; i<3; i++)
			for (int j = 0; j < 3; j++)
			{
				if (board[x0 + i][y0 + j] != '.')
				{
					sc.insert(board[x0 + i][y0 + j]);
					count++;
				}
			}
		if (count != sc.size())
			return false;
		return true;
	}


private:
	const int N = 9;
	set<char> sc;
};


