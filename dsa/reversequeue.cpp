class Solution
{
    private:
    void reverse(queue<int>&q){
        if(q.empty()){
            
            return;
        }
        int d=q.front();
        q.pop();
        reverse(q);
        q.push(d);
    }
    
    public:
    queue<int> rev(queue<int> q)
    {
    reverse(q);
    return q;
    }
};
