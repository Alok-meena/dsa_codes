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
void QueueStack ::push(int x) {
    // code here
    q2.push(x);
    
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    
    while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();
    }
}

int QueueStack ::pop() {

    
    // code here
    if(q1.empty()) return -1;
    int val=q1.front();
    q1.pop();
    return val;
    
}

pahle q2 me dal diya alright
then q1 ke sare ele q2 me dal do
then q2 ke sare ele q1 me dal do alright


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

pahle value insert ki phir starting ki sari values curr se pahle ki (size-1) se pahle ki insert kr di queue me alright
