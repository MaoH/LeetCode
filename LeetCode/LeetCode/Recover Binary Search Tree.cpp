#include <iostream>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	void recoverTree(TreeNode* root) {
		pre = NULL;
		p1 = NULL;
		p2 = NULL;
		inOrder(root);
		int temp = p1->val;
		p1->val = p2->val;
		p2->val = temp;
	}

	void inOrder(TreeNode* root)
	{
		if (root)
		{

			inOrder(root->left);
			if (pre && pre->val > root->val)
			{
				if (!p1)
				{
					p1 = pre;
				}
				p2 = root;

			}
			pre = root;
			inOrder(root->right);
		}
	}

private:
	TreeNode *pre;
	TreeNode *p1, *p2;
};