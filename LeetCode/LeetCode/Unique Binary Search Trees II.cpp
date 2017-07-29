#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) 
	{
	}
	
};

class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0)
		{
			vector<TreeNode*> v(0);
			return v;
		}
		return BST(1, n);
	}

	vector<TreeNode*> BST(int first, int end)
	{
		vector<TreeNode*> v;
		int len = end - first + 1;
		if (len == 0)
		{
			v.push_back(NULL);
			return std::move(v);
		}
		if (len == 1)
		{
			TreeNode* p = new TreeNode(first);
			v.push_back(p);
			return std::move(v);
		}
		for (int x = first; x <= end; x++)
		{
			vector<TreeNode*> vl = BST(first, x - 1);
			vector<TreeNode*> vr = BST(x + 1, end);
			for(int i=0;i<vl.size();i++)
				for (int j = 0; j < vr.size(); j++)
				{
					TreeNode* p = new TreeNode(x);
					p->left = vl[i];
					p->right = vr[j];
					v.push_back(p);
				}
		}

		return std::move(v);
	}
};

/*
int main()
{
	Solution solu;
	auto vt=solu.generateTrees(3);
	cout << vt.size();
}


*/