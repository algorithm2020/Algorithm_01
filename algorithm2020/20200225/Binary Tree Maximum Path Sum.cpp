/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int max_num;
class Solution {
public:
	int maxPathSum(TreeNode* root) {
		max_num = root->val;
		dfs(root);

		return max_num;
	}
	//���� �׵����� ��
	int dfs(TreeNode* root) {
		int left_sum = 0, right_sum = 0;
		if (root->left != NULL) {
			left_sum += dfs(root->left);
		}
		if (root->right != NULL) {
			right_sum += dfs(root->right);
		}

		int num = std::max(root->val, std::max(left_sum, right_sum) + root->val); //��尡 ���� ���϶�
		int num2 = std::max(num, left_sum + right_sum + root->val); //��尡 �Ϻ��϶�
		max_num = std::max(max_num, num2);
		if (root->val == 2 || root->val == -3 || root->val == 9) {
			cout << num << "\n";
			cout << "left and right is :" << left_sum << " " << right_sum << "\n";
		}

		return num;
	}
};