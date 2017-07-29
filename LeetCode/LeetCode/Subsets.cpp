#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		len = nums.size();
		N = nums;
		vector<int> vi;
		vvi.push_back(vi);
		DFS(vi, 0);
		return vvi;
	}

	void DFS(vector<int>& vi, int k)
	{
		if (k >= len)
			return;
		vi.push_back(N[k]);
		vvi.push_back(vi);
		DFS(vi, k + 1);
		vi.pop_back();
		//vvi.push_back(vi);
		DFS(vi, k + 1);
	}

private:
	int len;
	vector<vector<int>> vvi;
	vector<int> N;
};