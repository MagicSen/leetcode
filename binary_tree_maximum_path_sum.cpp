#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *createTree(vector<int> value){
		TreeNode *root = new TreeNode(value[0]);
		root->left = new TreeNode(value[1]);
		root->right = new TreeNode(value[2]);
		root->left->left = new TreeNode(value[3]);
		root->left->right = new TreeNode(value[4]);
		root->right->left = new TreeNode(value[5]);
		root->right->right = new TreeNode(value[6]);
		return root;
	}
	// recursion
	void DLR(TreeNode *root){
		if(root != NULL){
			cout << root->val << " ";
			DLR(root->left);
			DLR(root->right);
		}
	}
	void LDR(TreeNode *root){
		if(root != NULL){
			LDR(root->left);
			cout << root->val << " ";
			LDR(root->right);
		}
	}
	void LRD(TreeNode *root){
		if(root != NULL){
			LRD(root->left);
			LRD(root->right);
			cout << root->val << " ";
		}
	}

	// non-recursion
	void non_DLR(TreeNode *root){
		stack<TreeNode *> address;
		TreeNode *temp = root;
		while(address.size() != 0 || temp != NULL){
			while(temp != NULL){
				cout << temp->val << " ";
				address.push(temp);
				temp = temp->left;
			}
			temp = address.top();
			address.pop();
			temp = temp->right;
		}
		cout << endl;
	}
	void non_LDR(TreeNode *root){
		stack<TreeNode *> address;
		TreeNode *temp = root;
		while(address.size() != 0 || temp != NULL){
			while(temp != NULL){
				address.push(temp);
				temp = temp->left;
			}
			temp = address.top();
			address.pop();
			cout << temp->val << " ";
			temp = temp->right;
		}
		cout << endl;
	}
	void non_LRD(TreeNode *root){
		stack<pair<TreeNode *, int>> address;
		TreeNode *temp = root;
		while(address.size() != 0 || temp != NULL){
			while(temp != NULL){
				address.push(pair<TreeNode *, int>(temp, 1));
				temp = temp->left;
			}
			temp = address.top().first;
			int flag = address.top().second;
			if(flag){
				address.pop();
				address.push(pair<TreeNode *, int>(temp, 0));
				temp = temp->right;
			}else{
				cout << temp->val << " ";
				address.pop();
				temp = NULL;
			}
		}
		cout << endl;
	}

	void DFS(TreeNode *root){
		stack<TreeNode *> address;
		address.push(root);
		TreeNode *temp = NULL;
		while(address.size() != 0){
			temp = address.top();
			address.pop();
			cout << temp->val << " ";
			if(temp->right != NULL){
				address.push(temp->right);
			}
			if(temp->left != NULL){
				address.push(temp->left);
			}
		}
		cout << endl;
	}
	void BFS(TreeNode *root){
		queue<TreeNode *> address;
		address.push(root);
		TreeNode *temp = NULL;
		while(address.size() != 0){
			temp = address.front();
			address.pop();
			cout << temp->val << " ";
			if(temp->left != NULL){
				address.push(temp->left);
			}
			if(temp->right != NULL){
				address.push(temp->right);
			}
		}
		cout << endl;
	}
	
	int max(int a, int b){
		return a > b ? a : b;
	}

	int maxPathSum(TreeNode *root) {
		if(root->right == NULL && root->left == NULL)
			return root->val;
		else if(root->right == NULL){
			int temp_left = maxPathSum(root->left);
			return max(max(root->val, root->val+temp_left), temp_left);
		}else if(root->left == NULL){
			int temp_right = maxPathSum(root->right);
			return max(max(root->val, root->val+temp_right), temp_right);
		}else{
			int temp_left = maxPathSum(root->left);
			int temp_right = maxPathSum(root->right);
	
			int single_side = max(root->val, root->val + max(temp_left, temp_right));	
			int double_side = max(single_side, root->val + temp_left + temp_right);
			single_side = max(single_side, max(temp_left, temp_right));
			return max(single_side, double_side);		
		}
	}
};

int main()
{
	Solution sol;
//	vector<int> value={-1,-2,-3,-4,-5,-6,-7};
	vector<int> value={1,-2,-3,1,3,-2,-1};
	for(int i = 0; i < value.size(); ++i)
		cout << value[i];
	cout << endl;
	TreeNode *root = sol.createTree(value);
	cout << "******************" << endl;
	sol.DLR(root);
	cout << endl;
	sol.LDR(root);
	cout << endl;
	sol.LRD(root);
	cout << endl;
	cout << "******************" << endl;
	sol.non_DLR(root);
	sol.non_LDR(root);
	sol.non_LRD(root);
	cout << "******************" << endl;
	sol.DFS(root);
	sol.BFS(root);
	cout << sol.maxPathSum(root) << endl;
	TreeNode *temp_root = new TreeNode(-2);
	temp_root->left = new TreeNode(-1);
	cout << sol.maxPathSum(temp_root) << endl;

	return 0;
}
