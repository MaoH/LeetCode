#include <iostream>
#include <vector>
#include <map>
using namespace std;


struct TreeNode {
    int val;
	TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> findMode(TreeNode* root) {
		vector<int> vi;
		inOrder(root);
		int max = 0;
		for (auto it = mii.begin(); it != mii.end(); it++)
		{
			if (it->second == max)
				vi.push_back(it->first);
			if (it->second > max)
			{
				max = it->second;
				vi.clear();
				vi.push_back(it->first);
			}

		}
		return vi;
	}

	void inOrder(TreeNode* root)
	{
		if (root)
		{
			inOrder(root->left);
			map<int, int>::iterator it = mii.find(root->val);
			if (it == mii.end())
				mii.insert(pair<int, int>(root->val, 1));
			else
				it->second++;
			inOrder(root->right);
		}
	}
	map<int, int> mii;
};