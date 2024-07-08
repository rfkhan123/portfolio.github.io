#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
    TrieNode* children[ALPHABET_SIZE];
    TrieNode* fail;
    vector<int> output;

    TrieNode() {
        for (int i = 0; i < ALPHABET_SIZE; ++i)
            children[i] = nullptr;
        fail = nullptr;
    }
};

class AhoCorasick {
private:
    TrieNode* root;

public:
    AhoCorasick() {
        root = new TrieNode();
    }

    void insert(const string& pattern, int patternIndex) {
        TrieNode* current = root;

        for (char c : pattern) {
            int index = c - 'a';
            if (!current->children[index])
                current->children[index] = new TrieNode();
            current = current->children[index];
        }

        current->output.push_back(patternIndex);
    }

    void build() {
        queue<TrieNode*> q;
        root->fail = root;

        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            if (root->children[i]) {
                root->children[i]->fail = root;
                q.push(root->children[i]);
            } else {
                root->children[i] = root; 
            }
        }

        while (!q.empty()) {
            TrieNode* current = q.front();
            q.pop();

            for (int i = 0; i < ALPHABET_SIZE; ++i) {
                TrieNode* child = current->children[i];
                if (child) {
                    q.push(child);

                    TrieNode* fail = current->fail;
                    while (fail != root && !fail->children[i])
                        fail = fail->fail;

                    child->fail = fail->children[i] ? fail->children[i] : root;

                    for (int output : child->fail->output)
                        child->output.push_back(output);
                }
            }
        }
    }

    vector<pair<int, int>> search(const string& text, const vector<string>& patterns) {
        TrieNode* current = root;
        vector<pair<int, int>> matches;

        for (int i = 0; i < text.size(); ++i) {
            int index = text[i] - 'a';
            while (current != root && !current->children[index])
                current = current->fail;
            
            current = current->children[index] ? current->children[index] : root;

            for (int patternIndex : current->output) {
                int startPos = i - patterns[patternIndex].size() + 1;
                matches.emplace_back(startPos, patternIndex);
            }
        }

        return matches;
    }
};

int main() {
    AhoCorasick ac;

    vector<string> patterns = {"he", "she", "his", "hers"};
    string text = "ushers";

    for (int i = 0; i < patterns.size(); ++i)
        ac.insert(patterns[i], i);

    ac.build();

    vector<pair<int, int>> matches = ac.search(text, patterns);

    for (auto match : matches) {
        int startPos = match.first;
        int patternIndex = match.second;
        cout << "Pattern \"" << patterns[patternIndex] << "\" found at position " << startPos << endl;
    }

    return 0;
}
