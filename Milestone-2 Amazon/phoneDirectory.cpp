class Solution{
public:
    
    class Node {
    public:
        vector<Node*> child;
        vector<int> indexes;
        
        Node() {
            child = vector<Node*>(26);
        }
        
        void addIndex(int i)  {
            indexes.push_back(i);
        }
        bool hasChild(char c) {
            return child[c-'a'];
        }
        Node* getChild(char c) {
            return child[c-'a'];
        }
        void putChild(char c) {
            child[c-'a'] = new Node();
        }
    };
    
    class Trie {
    public:
        Node* root = new Node();
        
        void insert(string &s, int ind) {
            Node* cur = root;
            for(char &c: s) {
                if(!(cur->hasChild(c))) {
                    cur->putChild(c);
                }
                cur = cur->getChild(c);
                cur->addIndex(ind);
            }
        }
        
    };

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Trie trie;
        for(int i = 0; i < n; i++) {
            trie.insert(contact[i], i);
        }
        vector<vector<string>> res;
        Node* cur = trie.root;
        bool exists = true;
        for(char c: s) {
            if(exists && cur->hasChild(c)) {
                cur = cur->getChild(c);
                set<string> curRes;
                for(int i: cur->indexes) {
                    curRes.insert(contact[i]);
                }
                res.push_back(vector<string>(curRes.begin(), curRes.end()));
            }
            else {
                exists = false;
                res.push_back({"0"});
            }
        }
        return res;
    }
};