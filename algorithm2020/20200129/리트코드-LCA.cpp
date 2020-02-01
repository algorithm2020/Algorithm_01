class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode* ancestor;
		if (root->val == p->val) ancestor = p;
		if (root->val == q->val) ancestor = q;

		if ((root->val > p->val) && (root->val > q->val)) {
			ancestor = lowestCommonAncestor(root->left, p, q);
		}

		else if ((root->val < p->val) && (root->val < q->val)) {
			ancestor = lowestCommonAncestor(root->right, p, q);
		}

		else if ((root->val > p->val) && (root->val < q->val)) {
			ancestor = root;
		}

		else if ((root->val < p->val) && (root->val > q->val)) {
			ancestor = root;
		}
		return ancestor;
	}
};