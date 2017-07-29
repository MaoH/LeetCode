#include <iostream>
#include <vector>

using namespace std;


 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if (root == NULL)
			return true;
		if (root->left == NULL && root->right == NULL)
			return true;
		if (root->left == NULL)
		{
			if (!isValidBST(root->right))
				return false;
			TreeNode *Rmin = root->right;
			while (Rmin->left)
				Rmin = Rmin->left;
			if (root->val < Rmin->val)
				return true;
			else
				return false;

		}
		else if (root->right == NULL)
		{
			if (!isValidBST(root->left))
				return false;
			TreeNode* Lmax = root->left;
			while (Lmax->right)
				Lmax = Lmax->right;
			if (root->val > Lmax->val)
				return true;
			else
				return false;
		}
		else
		{
			if (!isValidBST(root->left) || !isValidBST(root->right))
				return false;

			TreeNode *Rmin = root->right;
			while (Rmin->left)
				Rmin = Rmin->left;

			TreeNode* Lmax = root->left;
			while (Lmax->right)
				Lmax = Lmax->right;
			
			if (root->val > Lmax->val && root->val < Rmin->val)
				return true;
			else
				return false;
		}

	}
};