class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        vector<int> res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node* cur = q.front(); q.pop();
            res.push_back(cur == NULL ? -1 : cur->data);
            if(cur) {
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return res;
    }
    
    //Function to deserialize a list and construct the tree.
    
    Node* newNode(int val) {
        Node* cur = NULL;
        if(val != -1) {
            cur = (Node*)malloc(sizeof(Node));
            cur->data = val;
            cur->left = NULL;
            cur->right = NULL;
        }
        return cur;
    }
    
    Node * deSerialize(vector<int> &A)
    {
        int n = A.size();
        Node* root = newNode(A[0]);
        vector<Node*> prev = {root};
        int i = 1;
        while(i < n) {
            vector<Node*> cur;
            for(Node* node: prev) {
                if(node) {
                    cur.push_back(node->left = newNode(A[i++]));
                    cur.push_back(node->right = newNode(A[i++]));
                }
            }
            prev = cur;
        }
        return root;
    }

};