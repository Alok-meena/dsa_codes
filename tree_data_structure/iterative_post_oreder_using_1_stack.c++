

bat kya hai post order == left , right , root ( ok ) 

curr ko root pe kr diya aor stack le liya jb tk left null nhi hota jate jao ho gya to ek node ko s top ke right pe le jao ager vo null nhi hai to simply curr
ko us node pe dal do o/w us node me s.top ko lo pop kro ans print kro then until stack is not empty and s.top ka right == temp hai to nikalo pop kro print ans bs


void iterativepost(node *root){
    stack<node*>s;
    node *curr=root;
    
    while(curr!=NULL or !s.empty()){
        if(curr!=NULL){
            s.push(curr);
            curr=curr->left;
        }
        else{
            node *temp=s.top()->right;
            if(temp==NULL){
                temp=s.top();
                s.pop();
                cout<<temp->data<<" ";

                while(!s.empty() and s.top()->right==temp){
                    temp=s.top();
                    s.pop();
                    cout<<temp->data<<" ";
                }
            }
            else curr=temp;
        }
    }
}
