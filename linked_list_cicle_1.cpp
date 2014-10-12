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
		bool hasCycle(ListNode *head) {
			if(head == NULL || head->next == NULL)	
				return false;
			ListNode *fast_head = head;
			ListNode *slow_head = head;
			while(slow_head != NULL && fast_head != NULL)
			{
				slow_head = slow_head->next;
				fast_head = fast_head->next;
				if(fast_head->next != NULL)
					fast_head = fast_head->next;
				else
					break;
				if(slow_head == fast_head)
					return true;
			}
			return false;
		}
};

int main()
{
	
	return 0;
}
