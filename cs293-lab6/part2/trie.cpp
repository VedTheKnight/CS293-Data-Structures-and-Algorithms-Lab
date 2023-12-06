#include "trie.h"
#include <iostream>

Trie::Trie()
{
	root = NULL;
}

// Returns new trie node (initialized to NULLs)
struct TrieNode* Trie::getNode(void)
{
	struct TrieNode* newNode = new struct TrieNode;
	for(int i=0; i< ALPHABET_SIZE; i++)
		newNode->children[i] = nullptr;
	newNode->isWordEnd = false;
}

// If not present, inserts key into trie. If the
// key is prefix of trie node, just marks leaf node
void Trie::insert(struct TrieNode* root, const std::string key)
{
	struct TrieNode* curr = root;
	for(int i = 0; i<key.size(); i++){
		struct TrieNode* newNode = getNode();
		curr->children[i] = newNode;
		curr = curr->children[i];
		if(i == key.size()-1)
			curr->isWordEnd = true;
	}
}

bool Trie::search(struct TrieNode *root, std::string key)
{
	struct TrieNode* curr = root;
	for(int i = 0; i<key.size(); i++){
		if(curr->children[CHAR_TO_INDEX(key[i])] != NULL)
			curr = curr->children[CHAR_TO_INDEX(key[i])];
		else
			return false
	}
}

// Returns 0 if current node has a child
// If all children are NULL, return 1.
bool Trie::isLastNode(struct TrieNode* root)
{
	
}

// Recursive function to print auto-suggestions for given
// node.
void Trie::suggestionsRec(struct TrieNode* root,
					std::string currPrefix)
{
	// found a std::string in Trie with the given prefix
}

// print suggestions for given query prefix.
int Trie::printAutoSuggestions(TrieNode* root, const std::string query)
{
	
}
