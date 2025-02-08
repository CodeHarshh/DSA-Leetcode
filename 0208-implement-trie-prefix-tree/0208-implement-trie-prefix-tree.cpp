// mine created class
class Trienode {
public:
    char value;
    unordered_map<char, Trienode*> children;
    bool isEndnode;

    Trienode(char data) {
        value = data;
        isEndnode = false;
    }

    void insertintoTries(Trienode* root, string word) {
        if (word.size() == 0) {
            root->isEndnode = true;
            return;
        }
        Trienode* child;
        char ch = word[0];
        if (root->children.count(ch) == 1) { //  if present then  case
            child = root->children[ch];
        } else { // absent case
            child = new Trienode(ch);
            root->children[ch] = child;
        }
        insertintoTries(child, word.substr(1)); // reccursion
    }

    bool searchTries(Trienode* root, string word) {
        if (word.size() == 0 && root->isEndnode == true) {
            return true;
        }
        char ch = word[0];
        if (root->children.find(ch) == 0) {
            return false;
        }

        Trienode* child = root->children[ch];
        bool reccAns = searchTries(child, word.substr(1));
        return reccAns;
    }

    bool searchPrefix(Trienode* root, string word) {
        if (word.size() == 0) {
            return true;
        }
        char ch = word[0];

        if (root->children.find(ch) == 0) {
            return false;
        }

        Trienode* child = root->children[ch];
        bool reccAns = searchPrefix(child, word.substr(1));
        return reccAns;
    }
};

class Trie {
public:
    Trienode* root;

    Trie() { root = new Trienode('-'); }

    void insert(string word) { root->insertintoTries(root, word); }

    bool search(string word) { return root->searchTries(root, word); }

    bool startsWith(string prefix) { return root->searchPrefix(root, prefix); }
};
