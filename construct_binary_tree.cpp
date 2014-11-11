#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
			TreeNode *root = NULL;
			if(preorder.size() == 0)
				return root;
			root = buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
			return root;
		}
		TreeNode *buildTree(vector<int> &preorder, int pre_begin, int pre_end, vector<int> &inorder, int ino_begin, int ino_end) {
			TreeNode *root = NULL;
			if(pre_end <= pre_begin)
				return root;
			root = new TreeNode(preorder[pre_begin]); 
			if(pre_end - pre_begin == 1){
				root->right = NULL;
				root->left = NULL;
				return root;
			}
			int i = ino_begin;
			for(; i < ino_end; ++i)
			{
				if(inorder[i] == preorder[pre_begin])
					break;
			}

			if(i == ino_begin){
				root->left = NULL;
				root->right = buildTree(preorder, pre_begin + 1, pre_end, inorder, ino_begin + 1, ino_end);
			}else if(i == ino_end-1){
				root->right = NULL;
				root->left = buildTree(preorder, pre_begin + 1, pre_end, inorder, ino_begin, ino_end-1);
			}else{
				root->left = buildTree(preorder,pre_begin + 1, pre_begin + 1 + i - ino_begin, inorder, ino_begin, ino_begin + i);
				root->right = buildTree(preorder, pre_begin + 1 + i - ino_begin, pre_end, inorder, ino_begin + i + 1, ino_end);
			}
			return root;
		}

		// Memory Limit Exceeded
		/*
		TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
			TreeNode *root = NULL;
			if(preorder.size() == 0)
				return root;
			root = new TreeNode(preorder[0]); 
			if(preorder.size() == 1){
				root->right = NULL;
				root->left = NULL;
				return root;
			}
			int i = 0;
			for(; i < inorder.size(); ++i)
			{
				if(inorder[i] == preorder[0])
					break;
			}

			if(i == 0){
				root->left = NULL;
				vector<int> inorder_right(inorder.begin() + 1, inorder.end());
				vector<int> preorder_right(preorder.begin() + 1, preorder.end());
				root->right = buildTree(preorder_right, preorder_right);
			}else if(i == inorder.size()-1){
				root->right = NULL;
				vector<int> inorder_left(inorder.begin(), inorder.begin() + inorder.size()-1);
				vector<int> preorder_left(preorder.begin() + 1, preorder.end());
				root->left = buildTree(preorder_left, inorder_left);
			}else{
				vector<int> inorder_left(inorder.begin(), inorder.begin() + i);
				vector<int> inorder_right(inorder.begin() + i + 1, inorder.end());
				vector<int> preorder_left(preorder.begin() + 1, preorder.begin() + 1 + inorder_left.size());
				vector<int> preorder_right(preorder.begin() + 1 + inorder_left.size(), preorder.end());

				root->left = buildTree(preorder_left, inorder_left);
				root->right = buildTree(preorder_right, preorder_right);
			}
			return root;
		}
		*/
		void show(TreeNode *root){
			if(root == NULL)
				return;
			cout << root->val << endl;
			show(root->left);
			show(root->right);
		}

};

int main()
{
//	vector<int> temp_a = {1,2,3,4,5,6,7,8,9,10};
//	vector<int> temp_b(temp_a.begin(), temp_a.end() + 1);
/*	for(int i = 0; i < temp_b.size(); ++i)
	{
		cout << temp_b[i] << endl;	
	}
	*/

//	vector<int> preorder = {1,2,4,5,3,6,7};
//	vector<int> inorder = {4,2,5,1,6,3,7};
//	vector<int> preorder = {1,2,3,4,5,7,6};
//	vector<int> inorder = {7,6,5,4,3,2,1};
//	vector<int> preorder = {1,3,2,4,5,6};
//	vector<int> inorder = {1,2,3,4,5,6};
	vector<int> preorder = {-77,24,-74,84,93,28,83,6,95,58,59,66,22,-3,-66,-68,-22,3,-80,-79,-85,17,32,9,-88,-99,14,-60,13,-93,-63,91,82,21,26,-11,-32,-16,-100,-94,-31,-62,-89,49,-9,-8,87,-33,-81,80,0,69,-7,52,67,-5,-65,31,-30,37,-57,27,23,38,-28,7,-82,-42,11,-55,-36,-58,-24,89,56,73,41,18,-87,-70,4,-64,20,-52,-39,79,19,30,65,25,-71,-76,-1,62,-69,98,39,-25,-73,70,88,-17,-20,-75,55,34,57,81,-10,94,48,-35,5,-23,-44,40,-51,-61,-13,-86,63,71,-97,45,43,51,75,33,-34,92,47,-78,85,-26,97,-29,-92,-83,-59,74,96,68,77,16,-4,10,60,64,-21,-2,1,-91,86,46,76,-37,-19,-96,36,-98,29,-72,61,50,15,-95,-40,-43,-53,90,-15,-48,-27,-90,-54,72,-50,-49,-18,78,54,35,-38,99,44,-67,53,-12,-41,2,8,-14,-84,-56,-6,12,-45,42,-47,-46};
	vector<int> inorder = {93,28,84,83,-74,59,58,66,-66,-3,-79,-80,3,-22,-68,22,-85,-99,14,-88,9,32,17,-60,95,-93,82,21,91,-63,26,13,-16,-32,-11,-100,6,-62,49,-89,-31,87,-8,69,0,80,-7,-81,-65,-5,67,-30,31,52,-33,37,-57,-9,7,-28,-42,-82,38,-55,11,23,-36,27,56,89,73,-24,41,-58,-70,-87,20,-64,-52,4,18,-94,19,30,-76,-1,-71,62,-69,25,-73,-25,70,39,88,98,-20,-17,65,55,-75,79,34,-39,48,94,-23,5,-44,-35,40,-10,-61,-51,-13,81,63,-97,71,-86,57,45,24,-34,85,97,-26,-78,-83,-92,74,-59,96,-29,68,47,77,92,10,-4,16,60,33,-21,1,86,76,46,-37,-91,-2,64,75,51,-19,-96,43,-98,29,61,-72,50,36,-95,-40,-43,15,90,-15,-53,-77,-54,-90,-49,-50,72,-27,35,54,-38,78,-67,44,53,99,-41,-12,-18,8,2,-48,-56,-84,-14,-45,12,42,-6,-46,-47};
	Solution sol;
	TreeNode *root = sol.buildTree(preorder, inorder);
	sol.show(root);
	return 0;
}
