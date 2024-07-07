#include <iostream>
#include <unordered_map>
using namespace std;

// TrieNode class definition
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

// Trie class definition
class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the trie
    void insert(string word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

    // Search for a word in the trie
    bool search(string word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return current != nullptr && current->isEndOfWord;
    }

    // Check if any word starts with the given prefix
    bool startsWith(string prefix) {
        TrieNode* current = root;
        for (char ch : prefix) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return current != nullptr;
    }
};

// Main function to test the Trie implementation
int main() {
    Trie trie;

    // Insert some words into the trie
    trie.insert("apple");
    trie.insert("application");
    trie.insert("apply");
    trie.insert("banana");

    // Search for words in the trie
    cout << "Searching for 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'app': " << (trie.search("app") ? "Found" : "Not Found") << endl;

    // Check if words start with a prefix
    cout << "Words starting with 'app': " << (trie.startsWith("app") ? "Exist" : "Do not exist") << endl;
    cout << "Words starting with 'xyz': " << (trie.startsWith("xyz") ? "Exist" : "Do not exist") << endl;

    return 0;
}
