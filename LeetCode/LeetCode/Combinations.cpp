#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;


class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		K = k;
		N = n;
		vector<int> vi;
		vvi.clear();
		DFS(vi, 1);
		return vvi;
	}

	void DFS(vector<int>& vi, int k)
	{
		if (vi.size() == K)
		{
			vvi.push_back(vi);
			return;
		}
		if (k>N)                 //or            if(K - vi.size() > N - k + 1)
			return;
		vi.push_back(k);
		DFS(vi, k + 1);
		vi.pop_back();
		DFS(vi, k + 1);

	}
private:
	vector<vector<int>> vvi;
	int K;
	int N;
};


int main()
{
	Solution solu;
	auto vvi=solu.combine(3, 2);
	for (int i = 0; i < vvi.size(); i++)
	{
		for (int j = 0; j < vvi[0].size(); j++)
			cout << vvi[i][j] << ends;;
		cout << endl;
	}
}