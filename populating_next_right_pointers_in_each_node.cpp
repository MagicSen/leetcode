#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	// Brilliant method
	
	void connect(TreeLinkNode *root) {
		if(root == NULL) return;
		TreeLinkNode *pre = root;
		TreeLinkNode *cur = NULL;
		while(pre->left){
			cur = pre;
			while(cur){
				cur->left->next = cur->right;
				if(cur->next) cur->right->next = cur->next->left;
				cur = cur->next;
			}
			pre = pre->left;
		}
	}
	// BFS
/*	void connect(TreeLinkNode *root) {
		if(root == NULL)
			return;
		queue<TreeLinkNode *> address;
		TreeLinkNode *temp = NULL;
		address.push(root);
		int i = 1;
		int uplimit = 1;
		while(address.size() != 0){
			temp = address.front();	
			address.pop();
			if(temp->left != NULL){
				address.push(temp->left);

			}
			if(temp->right != NULL){
				address.push(temp->right);
			}
			if(i == uplimit){
				temp->next = NULL;
				i = 1;
				uplimit *= 2;
			}else{
				temp->next = address.front();
				++i;
			}
		}
	}
	*/
};

int main()
{

}
