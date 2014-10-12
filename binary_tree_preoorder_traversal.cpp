#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>
#include <list>
#include <map>
#include <set>
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
		vector<int> preorderTraversal(TreeNode *root) {
			vector<int> total_num;
			if(root == NULL)
				return total_num;
			stack<TreeNode*> temp_address;
			temp_address.push(root);
			while(temp_address.size() != 0)
			{
				root = temp_address.top();
				temp_address.pop();
				total_num.push_back(root->val);	
				if(root->right != NULL)
					temp_address.push(root->right);
				if(root->left != NULL)
					temp_address.push(root->left);
			}
			return total_num;
		} 
		// recursive solution
	/*	vector<int> preorderTraversal(TreeNode *root) {
			vector<int> total_num;
			if(root == NULL)
				return total_num;
			vector<int> left_num = preorderTraversal(root->left);
			vector<int> right_num = preorderTraversal(root->right);
			total_num.push_back(root->val);
			if(left_num.size() != 0)
				total_num.insert(total_num.end(), left_num.begin(), left_num.end());
			if(right_num.size() != 0)
				total_num.insert(total_num.end(), right_num.begin(), right_num.end());
			return total_num;
		}
		*/
};
int main()
{
	return 0;
}
