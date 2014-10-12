#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <unordered_map>
using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
	private:
		// speed up 336ms
		unordered_map<int, RandomListNode *> node_map;
	public:
		// 364ms
		RandomListNode *copyRandomList(RandomListNode *head) {
			if(head == NULL)	
				return NULL;
			RandomListNode *temp_head = head;
			while(temp_head != NULL)
			{
				RandomListNode *current_node = NULL;
				RandomListNode *next_node = NULL;
				RandomListNode *random_node = NULL;
				if(node_map.find(temp_head->label) == node_map.end()){
					current_node = new RandomListNode(temp_head->label);
					node_map[current_node->label] = current_node;
				}else{
					current_node = node_map.find(temp_head->label)->second;
				}
				if(temp_head->next != NULL){
					auto temp_iter = node_map.find(temp_head->next->label);
					if(temp_iter == node_map.end()){
						next_node = new RandomListNode(temp_head->next->label);
						node_map[next_node->label] = next_node;
					}else{
						next_node = temp_iter->second;
					}
				}
				if(temp_head->random != NULL){
					auto temp_iter = node_map.find(temp_head->random->label);
					if( temp_iter == node_map.end()){
						random_node = new RandomListNode(temp_head->random->label);
						node_map[random_node->label] = random_node;
					}else{
						random_node = node_map.find(temp_head->random->label)->second;
					}
				}
				current_node->next = next_node;
				current_node->random = random_node;
				temp_head = temp_head->next;
			}
			return node_map.find(head->label)->second;
		}

		/*		RandomListNode *copyRandomList(RandomListNode *head) {
				if(head == NULL)	
				return NULL;
				RandomListNode *test_head = new RandomListNode(head->label);
				node_map.insert(pair<int, RandomListNode *>(test_head->label, test_head));
				RandomListNode *temp_head = head;
				while(temp_head != NULL)
				{
				RandomListNode *current_node = NULL;
				RandomListNode *next_node = NULL;
				RandomListNode *random_node = NULL;
				if(node_map.find(temp_head->label) == node_map.end()){
				current_node = new RandomListNode(temp_head->label);
				node_map.insert(pair<int, RandomListNode *>(current_node->label, current_node));
				}else{
				current_node = node_map.find(temp_head->label)->second;
				}
				if(temp_head->next != NULL && node_map.find(temp_head->next->label) == node_map.end()){
				next_node = new RandomListNode(temp_head->next->label);
				node_map.insert(pair<int, RandomListNode *>(next_node->label, next_node));
				}else{
				if(temp_head->next != NULL)
				next_node = node_map.find(temp_head->next->label)->second;
				}
				if(temp_head->random != NULL && node_map.find(temp_head->random->label) == node_map.end()){
				random_node = new RandomListNode(temp_head->random->label);
				node_map.insert(pair<int, RandomListNode *>(random_node->label, random_node));
				}else{
				if(temp_head->random != NULL)
				random_node = node_map.find(temp_head->random->label)->second;
				}
				current_node->next = next_node;
				current_node->random = random_node;
				temp_head = temp_head->next;
				}
				return test_head;
				}
				*/
};


int main()
{
	Solution sol;

	return 0;
}
