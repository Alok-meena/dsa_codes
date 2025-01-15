/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
        // Your Code
        q1.push(x);
        
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        // Your Code  
        if(q2.empty()) return -1;
        int val=q2.front();
        q2.pop();
        return val;
}


using single queue

void QueueStack :: push(int x)
{
        // Your Code
        q1.push(x);
        int size=q1.size()-1;
        
        while(size--){
            q1.push(q1.front());
            q1.pop();
        }
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        // Your Code  
        if(q1.empty()) return -1;
        int val=q1.front();
        q1.pop();
        return val;
}

okkkk

isme bs khuch nhi values ko last me inert krte hao size-1 times okk
