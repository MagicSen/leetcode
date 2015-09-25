#include <iostream>
#include <vector>
#include <algorithM>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* rotateRight(ListNode* head, int k) {
			if(head == NULL){
				return NULL;
			}
			ListNode *p1 = head;
			int length = 0;
			while(p1 != NULL){
				length++;
				p1 = p1->next;
			}
			k = k % length;
			int i = 0;
			p1 = head;
			while(i < k){
				p1 = p1->next;
				i++;
			}
			if(k == 0){
				return head;
			}
			ListNode *p1_pre = p1;
			ListNode *p2 = head;
			ListNode *p2_pre = head;
			while(p1 != NULL){
				p1_pre = p1;
				p1 = p1->next;
				p2_pre = p2;
				p2 = p2->next;
			}
			p1_pre->next = head;
			p2_pre->next = NULL;
			head = p2;
			return head;
		}
};


int main()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	Solution sol;
	head = sol.rotateRight(head, 30000000);
	while(head != NULL){
		cout << head->val << endl;
		head = head->next;
	}
	return 0;
}
