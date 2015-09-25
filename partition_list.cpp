#include<iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* partition(ListNode* head, int x) {
			if(head == NULL){
				return NULL;
			}
			ListNode *t1 = new ListNode(0);
			ListNode *t2 = new ListNode(0);
			ListNode *p = t1;
			ListNode *q = t2;
			while(head){
				if(head->val < x){
					p->next = head;
					p = p->next;
				}else{
					q->next = head;
					q = q->next;
				}
				head = head->next;
			}
			q->next = NULL;
			p->next = t2->next;
			return t1->next;
		}
};

int main()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(4);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(2);
	ListNode *temp = head;
	while(temp != NULL){
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
	Solution sol;
	temp = sol.partition(head, 3);
	while(temp != NULL){
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
	return 0;
}
