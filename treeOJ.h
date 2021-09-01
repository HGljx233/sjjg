#pragma once
#include"Common.h"
struct TreeNode {
    int val;
	struct TreeNode* left;
	struct TreeNode* right;
	
};
//求左叶子之和
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
//合并二叉树
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
//二叉树的镜像输出
struct TreeNode* mirrorTree(struct TreeNode* root) {
	if (root == NULL)
		return NULL;
	struct TreeNode* left = mirrorTree(root->left);
	struct TreeNode* right = mirrorTree(root->right);
	root->left = right;
	root->right = left;
	return root;

}
//从根到叶的二进制数之和
int dfs(struct TreeNode* root, int sub) {
	if (!root)
		return 0;
	// 每增加一个节点，上一个节点就外前移一位。
	// 而当前的值只可能是0 1 与十进制的0 1 是一个意思就直接累加
	sub = (sub << 1) + root->val;
	return root->left == root->right ? sub :
		dfs(root->left, sub) + dfs(root->right, sub);
}

int sumRootToLeaf(struct TreeNode* root) {
	return dfs(root, 0);
}