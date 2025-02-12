class Trienode {
public:
    char data;
    unordered_map<char, Trienode*> children;
    bool isEndNode;
    Trienode(char ch) { data = ch; 
        isEndNode=false;
    }
};

class Trie {
public:
    Trienode* root;
    Trie() { 
        root = new Trienode('\0');
         }

    void insertIntoTries(Trienode* root, string& word, int i = 0) {

        if (i == word.size()) {
            root->isEndNode = true;
            return;
        }
        Trienode* child;
        char ch = word[i];
        if (root->children.count(ch) == 1) {
            child = root->children[ch];
        } else { // absent case
            child = new Trienode(ch);
            root->children[ch] = child;
        }
        insertIntoTries(child, word, i + 1);
    }

    bool searchIntoTries(Trienode* root, string& word, int i = 0) {
        if (i == word.size() && root->isEndNode == true) {
            return true;
        }
        char ch = word[i];
        bool matched = false;
        if (ch == '.') {

            for (auto it : root->children) {
                matched = searchIntoTries(it.second, word, i + 1);
                if (matched) {
                    return true;
                }
            }

        } else {
            
            if (root->children.find(ch) == 0) {
                return false;
            }
            Trienode* child = root->children[ch];
            matched = searchIntoTries(child, word, i + 1);
        }
        return matched;
    }

    void insert(string& word) { return insertIntoTries(root, word); }

    bool search(string& word) { return searchIntoTries(root, word); }
};

class WordDictionary {
public:
    Trie trie;
    WordDictionary() {}

    void addWord(string word) { trie.insert(word); }

    bool search(string word) { return trie.search(word); }
};
