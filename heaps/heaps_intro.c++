#include <iostream>
using namespace std;


//maxheap

class heap{
    public:
    int arr[100];
    int size;

    //constructor
    heap(){
        arr[0]=-1;//to ye 1 based indexing me krte hai to simplify calculations jo parent node left right child etc ke liye tha 0 based me nhi karna hai ye
        size=0;
    }

    //insertion for max heap

    void insert(int value){
        //size increased by 1
        size=size+1;

        int index=size;
        arr[index]=value;
        //jab tak root node tk nhi pahuchoge condition check krte krte tab tak swap krte jao if condition full fill hoti hai to
        while(index>1){
            //ye to heapify ka hi concept ho gya
            // pahle parent ka index le liya then usse compare kr liya
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void deletefromheap(){
        if(size==0){
            cout<<"nothing to delete as heap is empty..."<<endl;
            return;
        }

        //put last element to first index
        arr[1]=arr[size];

        //remove last element
        size--;

        //take root node to its correct position
        int i=1;
        while(i<size){
            int leftindex=2*i;
            int rightindex=2*i+1;

           if(leftindex<size && arr[leftindex]>arr[i] && arr[leftindex]>arr[rightindex]){
                swap(arr[i],arr[leftindex]);
                i=leftindex;
            }
            else if(rightindex<size && arr[rightindex]>arr[i]&& arr[rightindex]>arr[leftindex]){
                swap(arr[i],arr[rightindex]);
                i=rightindex;
            }
            else{
                return;
            }


        }
    }
};

void heapify(int arr[],int n,int i){ // this heapify function is for 1 based indexing..........
    int largest=i;
    int left=2*i;// for 0 based it is 2*i+1
    int right=2*i+1;// for 0 based it is 2*i+2

    if(left<=n && arr[largest]<arr[left]){// to yha pe aor niche left<=n hai equal to hai for 1 based indexing and < only for 0 based indexing
        largest=left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest=right;
    }

    if(largest!=i){// ager ye condition satisfy ho jayegi mtlb hme swap krna hai node apni shi position pe nhi hai 
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}


void heapsort(int arr[],int n){
    int size=n;
    while(size>1){
        swap(arr[size],arr[1]);
        size--;

        heapify(arr,size,1);//ham always 1st element ko hi heapify kr rhe hai
    }
}
int main(){

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deletefromheap();

    int arr[6]={-1,54,53,55,52,50};//to ye 1 based indexing me krte hai to simplify calculations jo parent node left
    // right child etc ke liye tha 0 based me nhi karna hai ye
    int n=5;
    for(int i=n/2;i>0;i--){// this is for 1 based indexing and for 0 based indexing it is from n/2-1 equal to 0
        heapify(arr,n,i);
    }
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    heapsort(arr,n);

    cout<<"printing sorted list..."<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }



     //priority queue works as max heap
    priority_queue<int>pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout<<"max element of heap:"<<pq.top()<<endl;
    pq.pop();
    cout<<"max element of heap:"<<pq.top()<<endl;

    cout<<"size of the max heap:"<<pq.size()<<endl;
    if(pq.empty()){
        cout<<"heap is empty..."<<endl;
    }
    else{
        cout<<"heap is not empty..."<<endl;
    }

    //min heap
    cout<<"implementing minheap using priority queue..."<<endl;
    priority_queue<int,vector<int>,greater<int>>minheap;
    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);
    cout<<"min element of heap:"<<minheap.top()<<endl;
    minheap.pop();
    cout<<"min element of heap:"<<minheap.top()<<endl;

    cout<<"size of the min heap:"<<minheap.size()<<endl;
    if(minheap.empty()){
        cout<<"heap is empty..."<<endl;
    }
    else{
        cout<<"heap is not empty..."<<endl;
    }

}
