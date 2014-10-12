#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stack>
#include <map>

using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
	public:
		UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
			if(node == NULL)
				return NULL;
			// Save the visited address.
			set<UndirectedGraphNode *> alreadyVisitedAddress;
			stack<UndirectedGraphNode *> waitForVisitedAddress;
			// Save the new node, and avoid to new another
			map<UndirectedGraphNode *, UndirectedGraphNode *> corrsponding_address;
			waitForVisitedAddress.push(node);		
			alreadyVisitedAddress.insert(node);
			corrsponding_address.insert(pair<UndirectedGraphNode *, UndirectedGraphNode *>(node, new UndirectedGraphNode(node->label)));
			UndirectedGraphNode *head = NULL;
			while(waitForVisitedAddress.size() != 0){
				UndirectedGraphNode *temp = waitForVisitedAddress.top();
				waitForVisitedAddress.pop();
				UndirectedGraphNode *new_node = corrsponding_address.at(temp);
				if(temp == node){
					head = new_node;
				}
				for(int i = 0; i < temp->neighbors.size(); ++i){
					// If have visited, then skip, else push in the stack
					if(alreadyVisitedAddress.find(temp->neighbors[i]) == alreadyVisitedAddress.end()){
						waitForVisitedAddress.push(temp->neighbors[i]);
						alreadyVisitedAddress.insert(temp->neighbors[i]);
					}
					// If the node has been created, then skip, else create.
					if(corrsponding_address.find(temp->neighbors[i]) == corrsponding_address.end()){
						corrsponding_address.insert(pair<UndirectedGraphNode *, UndirectedGraphNode *>(temp->neighbors[i], new UndirectedGraphNode(temp->neighbors[i]->label)));
					}
					// Set the new neighbor
					new_node->neighbors.push_back(corrsponding_address.at(temp->neighbors[i]));
				}
			}
			return head;
		}
};

int main()
{
	return 0;
}
