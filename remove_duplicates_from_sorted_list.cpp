#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if(head == NULL)
			return NULL;

		ListNode *flag = NULL;
		ListNode *temp_head = head;

		while(temp_head->next){
			if(temp_head->val == temp_head->next->val){
				// First time repeat.
				if(flag == NULL){
					flag = temp_head;
				}
			}else{
				// Delete the repeated node.
				if(flag != NULL){
					flag->next = temp_head->next;
					flag = NULL;
				}
			}
			temp_head = temp_head->next;
		}

		if(flag != NULL){
			flag->next = NULL;
		}
		return head;
	}
};

int main()
{
	Solution sol;
	ListNode *head;
	head = new ListNode(1);
	head->next = new ListNode(1);
/*	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(3);
	*/
	ListNode *temp = sol.deleteDuplicates(head);
	while(temp){
		cout << temp->val << endl;
		temp = temp->next;
	}
	return 0;
}
