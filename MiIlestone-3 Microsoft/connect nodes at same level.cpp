void connect(Node *root){
       // Your Code Here
       queue<Node *>Q;
       
       Q.push(root);
       Node * temp=newNode(-1);
       
       while(!Q.empty()){
           int n=Q.size();
           Q.push(temp);
           
           for(int i=0;i<n;i++){
               Node * start=Q.front();
               Q.pop();
               if(Q.front()!=temp){
                   start->nextRight=Q.front();
               }else{
                   start->nextRight=NULL;
                   Q.pop();
               }
               
               if(start->left)Q.push(start->left);
                if(start->right)Q.push(start->right);
           }
           
       }
       
       
       
    }   