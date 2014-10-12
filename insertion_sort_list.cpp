#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
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
		ListNode *insertionSortList(ListNode *head) {
			if(head == NULL || head->next == NULL)
				return head;

			ListNode *second_head = head->next;
			head->next = NULL;
			while(second_head != NULL)
			{
				ListNode *q = second_head->next;	
				if(second_head->val <= head->val){
					second_head->next = head;
					head = second_head;
				}else{
					ListNode *temp_head = head;        
					while(temp_head->next != NULL && temp_head->next->val <= second_head->val)
					{
						temp_head = temp_head->next;		
					}
					second_head->next = temp_head->next;
					temp_head->next = second_head;
				}
				second_head = q;
			}
			return head;
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
	show(sol.insertionSortList(head));
	return 0;
}
