#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <numeric>
#include <list>
#include <stack>
#include <string>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		// Better solution
		ListNode *detectCycle(ListNode *head) {
			if(head == NULL || head->next == NULL)	
				return NULL;
			ListNode *fast = head;
			ListNode *slow = head;
			while(fast != NULL && slow != NULL)
			{
				slow = slow->next;
				if(fast->next != NULL)
					fast = fast->next->next;
				else
					return NULL;
				if(fast == slow)
					break;
			}
			if(fast == NULL)
				return NULL; 
			slow = head;
			while(slow != fast)
			{
				slow = slow->next;	
				fast = fast->next;
			}
			return slow;
		}
		/*
		ListNode *detectCycle(ListNode *head) {
			if(head == NULL || head->next == NULL)	
				return NULL;
			while(head != NULL)
			{
				if(head->val == -1)
					break;
				head->val = -1;	
				head = head->next;
			}
			return head;
		}
		*/
};

int main()
{
	
	return 0;
}
