class Solution {
	int sum = 0;
public:
	TreeNode* bstToGst(TreeNode* root) {
		if (root->right) bstToGst(root->right);

		root->val += sum;
		sum = root->val;

		if (root->left) bstToGst(root->left);
		return root;
	}
};