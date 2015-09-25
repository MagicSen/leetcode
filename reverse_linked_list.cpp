#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* reverseBetween(ListNode* head, int m, int n) {
			ListNode *p=head;
			ListNode *p_pre = NULL;
			ListNode *q = new ListNode(-1);
			ListNode *end = NULL;
			int i = 1;
			while(i <= n){
				if(i >= m){
					if(q->next == NULL){
						end = p;
					}
					ListNode *tmp = p->next;	
					p->next = q->next;
					q->next = p;
					p = tmp;
				}else{
					p_pre = p;
					p = p->next;
				}
				i++;
			}
			if(p_pre == NULL){
				head = q->next;
			}else{
				p_pre->next = q->next;
			}
			end->next = p;
			return head;
		}
		ListNode* reverseBetween2(ListNode* head, int m, int n) {
			ListNode *a=head;
			ListNode *b=head;
			ListNode *a_pre = head;
			ListNode *b_pre = head;
			int i = 1;
			while(i < n){
				b_pre = b;
				b = b->next;
				if(i == m-1){
					a_pre = b_pre;	
					a = b;
				}
				i++;
			}
			if(m == n){
				return head;
			}else if(n - m == 1){
				if(head == a){
					head = b;
					a->next = b->next;
					b->next = a;
				}else{
					a_pre->next = b;
					a->next = b->next;
					b->next = a;
				}
				return head;
			}else{
				if(head == a){
					head = b;
					ListNode *tmp = a->next;
					b_pre->next = a;
					a->next = b->next;
					b->next = tmp;
				}else{
					ListNode *tmp = a->next;
					a->next = b->next;
					b->next = tmp;
					a_pre->next = b;
					b_pre->next = a;
				}
				return head;
			}
		}
};

int main()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	/*
	head->next->next->next = new ListNode(4);
	   head->next->next->next->next = new ListNode(5);
	   */
	Solution sol;
	ListNode *tmp = head;
	while(tmp != NULL){
		cout << tmp->val << " ";
		tmp = tmp->next;
	}
	cout << endl;
	head = sol.reverseBetween(head, 1,2);
	tmp = head;
	while(tmp != NULL){
		cout << tmp->val << " ";
		tmp = tmp->next;
	}
	return 0;
}
