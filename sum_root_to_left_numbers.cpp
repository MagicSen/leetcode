#include <iostream>
#include <vector>
#include <algorithm>
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
	int sumNumbers(TreeNode *root) {
		stack<pair<TreeNode *, int>> address;
		TreeNode *temp = root;
		int sum = 0;
		int flag = 0;
		int single_num = 0;
		while(address.size() != 0 | temp != NULL){
			while(temp != NULL){
				single_num = single_num*10 + temp->val;
				address.push(pair<TreeNode *, int>(temp, 1));
				temp = temp->left;
			}
			temp = address.top().first;	
			flag = address.top().second;
			if(flag == 1){
				address.pop();
				address.push(pair<TreeNode *, int>(temp, 0));
				temp = temp->right;
			}else{
				if(temp->right == NULL && temp->left == NULL){
					sum += single_num;
				}
				single_num /= 10;	
				address.pop();
				temp = NULL;
			}
		}
		return sum;
	}
};
int main()
{
	Solution sol;
//	TreeNode *head = NULL;
	TreeNode *head = new TreeNode(1);
	head->left = new TreeNode(2);
	head->left->left = new TreeNode(4);
	head->left->right = new TreeNode(5);
//	head->right = new TreeNode(3);
	cout << sol.sumNumbers(head) << endl;
	return 0;
}
