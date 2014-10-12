#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <string>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
	public:
		// unrecursive solution
		vector<int> postorderTraversal(TreeNode *root) {
			vector<int> total_num;
			if(root == NULL)
				return total_num;
			stack<TreeNode*> temp_address;
			temp_address.push(root);
			while(temp_address.size() != 0)
			{
				root = temp_address.top();
				temp_address.pop();
				total_num.insert(total_num.begin(),root->val);
				if(root->left != NULL)
					temp_address.push(root->left);
				if(root->right != NULL)
					temp_address.push(root->right);
			}
			return total_num;
		} 

		// recursive solution
	/*	vector<int> postorderTraversal(TreeNode *root) {
			vector<int> total_num;
			if(root == NULL)
				return total_num;
			vector<int> left_array = postorderTraversal(root->left);
			vector<int> right_array = postorderTraversal(root->right);
			if(left_array.size() != 0 )	
				total_num.insert(total_num.end(), left_array.begin(), left_array.end());
			if(right_array.size() != 0)
				total_num.insert(total_num.end(), right_array.begin(), right_array.end());
			total_num.insert(total_num.end(), root->val);
			return total_num;
		} 
		*/
};

int main()
{
	Solution sol;
	
	return 0;
}
