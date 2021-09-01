#pragma once
#include"Common.h"
struct TreeNode {
    int val;
	struct TreeNode* left;
	struct TreeNode* right;
	
};
//����Ҷ��֮��
int sumOfLeftLeaves(struct TreeNode* root) {
	if (root == NULL)
		return 0;
	int mid = 0;
	int result = 0;
	if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) {
		mid = root->left->val;
		int left = sumOfLeftLeaves(root->left);
		int right = sumOfLeftLeaves(root->right);
		result = mid + left + right;
		return result;
	}
}
//�ϲ�������
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2) {
	if (root1 == NULL)
		return root2;
	if (root2 == NULL)
		return root1;
	root1->val += root2->val;
	root1->left = mergeTrees(root1->left, root2->left);
	root1->right = mergeTrees(root1->right, root2->right);
	return root1;
}
//�������ľ������
struct TreeNode* mirrorTree(struct TreeNode* root) {
	if (root == NULL)
		return NULL;
	struct TreeNode* left = mirrorTree(root->left);
	struct TreeNode* right = mirrorTree(root->right);
	root->left = right;
	root->right = left;
	return root;

}
//�Ӹ���Ҷ�Ķ�������֮��
int dfs(struct TreeNode* root, int sub) {
	if (!root)
		return 0;
	// ÿ����һ���ڵ㣬��һ���ڵ����ǰ��һλ��
	// ����ǰ��ֵֻ������0 1 ��ʮ���Ƶ�0 1 ��һ����˼��ֱ���ۼ�
	sub = (sub << 1) + root->val;
	return root->left == root->right ? sub :
		dfs(root->left, sub) + dfs(root->right, sub);
}

int sumRootToLeaf(struct TreeNode* root) {
	return dfs(root, 0);
}