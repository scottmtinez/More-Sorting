#include <iostream>
#include <unordered_map>
using namespace std;

#ifndef TRIENODE_H_
#define TRIENODE_H_

class TrieNode {

public:

	unordered_map<char, TrieNode *> edges;
	int depth;

	TrieNode(int depth) {
		this->depth = depth;
	}
};



#endif /* TRIENODE_H_ */
