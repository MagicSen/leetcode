#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>
#include <stack>
#include <list>
#include <string>
#include <unordered_map>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
void show(ListNode *head)
{
	cout << "#################################" << endl;
	while(head != NULL)
	{
		cout << head->val << " " << endl;	
		head = head->next;
	}
}

class Solution {
	public:
		// Use half sequence reverse to speed up.
		ListNode *reverse(ListNode *head)
		{
			if(head == NULL || head->next == NULL)
				return head;
			ListNode *head_pre = head->next;
			head->next = NULL;
			while(head_pre != NULL)		
			{
				ListNode *temp_pre_next = head_pre->next;
				head_pre->next = head;
				head = head_pre;
				head_pre = temp_pre_next;
			}
			return head;
		}
		void insert_after(ListNode *p1, ListNode *p2)
		{
			if(p1 != NULL && p2 != NULL){
				p2->next = p1->next;
				p1->next = p2;	
			}
		}
		void reorderList(ListNode *head) {
			if(head == NULL || head->next == NULL)
				return;
			int list_length = 0;
			ListNode *second_head = head;
			while(second_head != NULL)
			{
				list_length++;
				second_head = second_head->next;	
			}
			if(list_length <= 2)
				return;
			ListNode *first_head = head;
			second_head = head;
			ListNode *second_pre = head;
			int i = 0;
			while( i <= list_length/2)
			{
				second_pre = second_head;	
				second_head = second_head->next;
				i++;
			}
			second_pre->next = NULL;
			second_head = reverse(second_head);
			while(first_head != NULL && second_head != NULL)
			{
				ListNode *temp_first = first_head->next;
				ListNode *temp_second = second_head->next;
				insert_after(first_head, second_head);
				first_head = temp_first;	
				second_head = temp_second;
			}

		}

		// Use extra space
	/*	void insert_after(ListNode *p1, ListNode *p2)
		{
			if(p1 != NULL && p2 != NULL){
				p2->next = p1->next;
				p1->next = p2;	
			}
		}
		void reorderList(ListNode *head) {
			if(head == NULL || head->next == NULL)
				return;
			vector<ListNode*> temp_address;
			ListNode *temp = head;
			while(temp != NULL)
			{
				temp_address.push_back(temp);	
				temp = temp->next;
			}
			int i = temp_address.size()-1;
			while(i > temp_address.size()/2)
			{
				insert_after(temp_address[temp_address.size()-1-i], temp_address[i]);	
				i--;	
			}
			temp_address[i]->next = NULL;
		}
		*/
		/*
		void reorderList(ListNode *head) {
			if(head == NULL)
				return;
			int list_length = 0;
			ListNode *second_head = head;
			while(second_head != NULL)
			{
				list_length++;
				second_head = second_head->next;	
			}
			if(list_length <= 2)
				return;
			ListNode *first_head = head;
			second_head = head;
			ListNode *second_pre = head;
			int i = 0;
			while( i <= list_length/2)
			{
				second_pre = second_head;	
				second_head = second_head->next;
				i++;
			}
			second_pre->next = NULL;
			// second list length;
			i = list_length - i;
			ListNode *first_pre = first_head->next;	
			while(first_pre != NULL && i != 0)
			{
				first_pre = first_head->next;
				ListNode *temp = second_head;
				ListNode *temp_pre = second_head;
				int j = 1;
				while(j < i)		
				{
					temp_pre = temp;	
					temp = temp->next;
					j++;
				}
				i--;
				temp_pre->next = NULL;
				temp->next = first_head->next;
				first_head->next = temp;
				first_head = first_pre;
			}
		}
		*/
};

int main()
{
	int temp;
	ListNode *head = new ListNode(1);
	ListNode *p = head;
	while(cin >> temp)	
	{
		p->next = new ListNode(temp);	
		p = p->next;
	}
	Solution sol;
	show(head);
	sol.reorderList(head);
	show(head);
	return 0;
}
