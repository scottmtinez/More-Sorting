#include <iostream>
#include <string>
#include "TrieNode.h"
using namespace std;

#ifndef TRIE_H_
#define TRIE_H_

class Trie {

	TrieNode *root;

public:

	Trie() {
		root = new TrieNode(0);
	}

private:
	TrieNode *locus(string &str) { // complete this method
    //Set a TrieNode temporary variable tmp to the root. (In C++, tmp is a pointer.)
      TrieNode *tmp = root;

    //for (i = 0 to i < str.length()), do the following:
      for(int i = 0; i < str.length(); i++)
        {
          //Let c be the character at position i of str.
            char c = str.at(i);  

          //Let child be the child of tmp such that the edge from tmp to the child is labeled by c; use the hashtable edges stored in tmp to get hold of child.
            TrieNode *child = tmp->edges[c];
            //Has something to do with the code below.
            //unordered_map<char, TrieNode *> edges;

          //If the child is null, 
            if(child == NULL)
              {
                //then tmp is the locus; so return tmp.
                  return tmp;
              }
            else
              {
                //Else, move tmp to child
                  tmp = child; 
              }
        }

        //The entire string is matched at this point; so, the locus is given by tmp; return it.
          return tmp;
	}

public:
	void insert(string &str) { // complete this method
    //Let parent be the locus of str; let depth be its depth.
      TrieNode *parent = locus(str);
      int depth = parent->depth;
    
    //Starting a for-loop from index depth until the end of the string, do the following:
      for(int i = depth; i < str.length(); i++)
        {
          //Let c be the character at the index of str given by the for-loop counter.
            char c = str.at(i);

          //Create a new TrieNode child whose depth is one more than the loop counter.
            TrieNode *child = new TrieNode(i+1);

          //Insert this newly created node as the child of parent by using the hashtable edges stored at parent. Specifically, insert the child as value into edges keyed by c.
            parent->edges[c] = child;

          //Move parent to child:
            parent = child;
        }
    
	}

	bool search(string &str) { // complete this method
    //If Else statment to see if the string is found
      if(str.length() == locus(str)->depth)
        {
          return true;
        }
      else
        {
          return false;
        }
	}
};

#endif /* TRIE_H_ */
