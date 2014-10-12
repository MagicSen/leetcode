#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>
#include <list>
#include <forward_list>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
using namespace std;

class LRUCache{
	public:
		// Save the iterator of the list, speed up visit list.
		unordered_map<int, list<pair<int, int>>::iterator> page_map;
		// Save the key and value
		list<pair<int, int>> virtual_page;
		int list_length;
		int capacity;
		LRUCache(int capacity) {
			this->capacity = capacity;
			this->list_length = 0;
		}

		int get(int key) {
			// update the priority.
			auto temp_iter = page_map.find(key);
			if(temp_iter != page_map.end()){
				pair<int, int> temp_p = *(temp_iter->second);
				virtual_page.erase(temp_iter->second);
				virtual_page.insert(virtual_page.begin(), temp_p);
				page_map[key] = virtual_page.begin();
				return temp_iter->second->second;
			}
			else
				return -1;
		}
		
		void set(int key, int value) {
			auto temp_iter = page_map.find(key);
			if(temp_iter != page_map.end()){
				virtual_page.erase(temp_iter->second);
				page_map.erase(key);
			}else if(list_length == capacity){
				page_map.erase(virtual_page.back().first);
				virtual_page.pop_back();
			}else{
				list_length++;
			}
			// update the list
			virtual_page.insert(virtual_page.begin(), pair<int, int>(key, value));
			page_map[key] = virtual_page.begin();
		} 
/*
		forward_list<pair<int, int>> virtual_page;
		int list_length;
		int capacity;
		LRUCache(int capacity) {
			this->capacity = capacity;
			this->list_length = 0;
		}

		int get(int key) {
			for(auto i : virtual_page)
				if(i.first == key)
					return i.second;
			return -1;
		}
		
		void set(int key, int value) {
			int test = get(key) ;
			if(test != -1){
				auto prev = virtual_page.before_begin();
				auto curr = virtual_page.begin();
				while( curr != virtual_page.end())
				{
					if(curr->first == key){
						break;
					}else{
						prev = curr;
						curr++;
					}
				}
				virtual_page.erase_after(prev);
				list_length--;
			}else if(list_length == capacity){
				auto prev_2 = virtual_page.before_begin();
				auto prev = virtual_page.before_begin();
				auto curr = virtual_page.begin();
				while( curr != virtual_page.end())
				{
					prev_2 = prev;
					prev = curr;
					curr++;
				}
				virtual_page.erase_after(prev_2);
				list_length--;
			}else{}
			virtual_page.insert_after(virtual_page.before_begin(), pair<int, int>(key, value));
			list_length++;
		} 
*/
	/*	unordered_map<int, int> virtual_page;
		int capacity;
		LRUCache(int capacity) {
			this->capacity = capacity;
		}

		int get(int key) {
			auto temp_iter = virtual_page.find(key);
			if(temp_iter == virtual_page.end())
				return -1;
			else
				return temp_iter->second;
		}

		void set(int key, int value) {
			int test = get(key) ;
			if(test != -1){
				auto temp_iter = virtual_page.find(key);
				virtual_page.erase(temp_iter);
			}else if(virtual_page.size() == capacity){
				auto temp_iter = virtual_page.begin();
				auto temp_pre = temp_iter;
				while(temp_iter != virtual_page.end())
				{
					temp_pre = temp_iter;
					temp_iter++;
				}
				virtual_page.erase(temp_pre->first);
			}else{}
			virtual_page.insert(virtual_page.begin(), pair<int, int>(key, value));
		} 
		*/

	/*	vector<pair<int, int>> virtual_page;
		int capacity;
		LRUCache(int capacity) {
			this->capacity = capacity;
		}

		int get(int key) {
			for(auto i : virtual_page)
			{
				if(i.first == key)
					return i.second;
			}
			return -1;
		}

		void set(int key, int value) {
			int test = get(key) ;
			if(test == -1 && virtual_page.size() < capacity){
				virtual_page.insert(virtual_page.begin(), pair<int, int>(key, value));
			}else{
				if(get(test) == -1 && virtual_page.size() == capacity){
					virtual_page.erase(virtual_page.begin() + virtual_page.size()-1);
					virtual_page.insert(virtual_page.begin(), pair<int, int>(key, value));
				}else{
					for(int i = 0; i < virtual_page.size()-1; ++i)
						if(virtual_page[i].first == key)
							swap(*(virtual_page.begin() + i), *(virtual_page.begin() + 0));
				}
			}
		} 
		*/
};

//void show(unordered_map<int, int> virtual_page)
//void show(forward_list<pair<int, int>> virtual_page)
void show(list<pair<int, int>> virtual_page)
{
	cout << "##########################################" << endl;
	for(auto i : virtual_page)
		cout << i.first << " " << i.second << endl;
}
int main()
{
	LRUCache lr(2);
/*	lr.set(10,11);	
	show(lr.virtual_page);
	cout << "find key " << lr.get(123) << endl;
	lr.set(11,111);
	show(lr.virtual_page);
	cout << "find key " << lr.get(11) << endl;
	lr.set(12,123);
	show(lr.virtual_page);
	cout << "find key " << lr.get(12) << endl;
	lr.set(13,22);
	show(lr.virtual_page);
	cout << "find key " << lr.get(13) << endl;
	lr.set(11,1444);
	show(lr.virtual_page);
	cout << "find key " << lr.get(11) << endl;
	*/
	lr.set(2,1);
	show(lr.virtual_page);
	lr.set(1,1);
	show(lr.virtual_page);
	cout << lr.get(2) << endl;
	lr.set(4,1);
	show(lr.virtual_page);
	cout << lr.get(1) << endl;
	cout << lr.get(2) << endl;
	return 0;
}
