#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <string>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
	public:
	/*	ListNode *sortList(ListNode *head) {
		 	if(head == NULL || head->next == NULL)
		        	return head;
			ListNode *p = head->next;
			head->next = NULL;
			while(p != NULL)
			{
				ListNode *q = p->next;	
				if(head->val >= p-> val){
					p->next = head;
					head = p;
				}else{
					ListNode *temp = head;
					while(temp->next != NULL)
					{
						if(temp->next->val >= p->val){
							break;
						}else{
							temp = temp->next;
						}
					}
					p->next = temp->next;
					temp->next = p;
				}
				p = q;
			}
			return head;
		}
		*/
		ListNode *sortList(ListNode *head) {
			if(head == NULL || head->next == NULL)
		        	return head;
			int len = 0;
			ListNode *temp = head;
			while(temp != NULL)
			{
				len++;
				temp = temp->next;
			}
			temp = head;
			ListNode *q = temp;
			for(int i = 0; i < len/2; i++)
			{
				q = temp;
				temp = temp->next;
			}
			ListNode *firstHead = head;
			ListNode *secondHead = temp;
			q->next = NULL;	
			firstHead = sortList(firstHead);
			secondHead = sortList(secondHead);
			head = merge(firstHead, secondHead);
			return head;
		}
	// Because two subsequence has been sorted, so don't need to traversal the subsequence	
		ListNode *merge(ListNode *firstHead, ListNode *secondHead)
		{
			ListNode *temp_head = NULL;
			ListNode *temp_tail = NULL;
			while(secondHead != NULL && firstHead != NULL)	
			{
				if(temp_head == NULL){
					if(firstHead->val <= secondHead->val){
						temp_head = firstHead;
						firstHead = firstHead->next;
					}else{
						temp_head = secondHead;
						secondHead = secondHead->next;
					}
					temp_tail = temp_head;
				}else{
					if(firstHead->val <= secondHead->val){
						temp_tail->next = firstHead;
						firstHead = firstHead->next;	
					}else{
						temp_tail->next = secondHead;
						secondHead = secondHead->next;	
					}
					temp_tail = temp_tail->next;
				}
			}
			if(firstHead == NULL){
				temp_tail->next = secondHead;
			}else{
				temp_tail->next = firstHead;
			}
			return temp_head;
		} 
};


void show(ListNode *head)
{
	while(head != NULL)
	{
		cout << head->val << " " << endl;	
		head = head->next;
	}
}
int main()
{
	int temp;
	ListNode *head = new ListNode(3);
	ListNode *p = head;
	while(cin >> temp)	
	{
		p->next = new ListNode(temp);	
		p = p->next;
	}
	Solution sol;
	show(sol.sortList(head));
	return 0;
}
