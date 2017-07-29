#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int count;
		for (int i = 0; i < N; i++)                      //row
		{
			sc.clear();
			count = 0;
			for (int j = 0; j < N; j++)
			{
				if (board[i][j] != '.')
				{
					count++;
					sc.insert(board[i][j]);
				}
			}
			if (count != sc.size())
				return false;
		}

		for (int i = 0; i < N; i++)                     //column
		{
			sc.clear();
			count = 0;
			for (int j = 0; j < N; j++)
			{
				if (board[j][i] != '.')
				{
					count++;
					sc.insert(board[j][i]);
				}
			}
			if (count != sc.size())
				return false;
		}

		for (int k = 0; k < N; k++)                   //subboard
		{
			int x = (k / 3) * 3;
			int y = (k % 3) * 3;
			count = 0;
			sc.clear();
			for(int i = 0;i < 3; i++)
				for (int j = 0; j < 3; j++)
				{
					if (board[x + i][y + j] != '.')
					{
						count++;
						sc.insert(board[x + i][y + j]);
					}
				}
			if (count != sc.size())
				return false;
		}
		return true;
	}
private:
	const int N = 9;
	set<char> sc;
};

