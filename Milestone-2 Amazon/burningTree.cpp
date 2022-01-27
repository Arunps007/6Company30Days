class Solution {
  public:
  
    int getHeight(Node* root, map<Node*, int> &height) {
        if(root == NULL)
            return 0;
        return height[root] = 1 + 
        max(getHeight(root->left, height), getHeight(root->right, height));
    }
  
    int solve(Node* root, int target, int parentHeight, map<Node*, int> &height) {
        if(root == NULL)
            return -1;
        else if(root->data == target) {
            return max({parentHeight, height[root->left], height[root->right]});
        }
        else {
            // for left
            int myHeightLeft = max(parentHeight, height[root->right]) + 1;
            int myHeightRight = max(parentHeight, height[root->left]) + 1;
            return max(
                solve(root->left, target, myHeightLeft, height), 
                solve(root->right, target, myHeightRight, height)
            );
        }
    }
  
    int minTime(Node* root, int target) 
    {
        map<Node*, int> height;
        height[NULL] = 0;
        getHeight(root, height);
        return solve(root, target, 0, height);
    }
};