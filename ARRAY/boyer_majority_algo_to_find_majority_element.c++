#include <bits/stdc++.h>
#include <map>
using namespace std;

//here our definition of majority element is that the element's count should be greater than > N/2

int main(){
    int arr[13]={1,1,1,0,0,0,2,2,2,0,1,1,1};
    
    
    int element=-1;
    int count=0;
    for(int i=0;i<13;i++){
        //if count is 0 the set current value as majority value 
        if(count==0){
            element=arr[i];
            count++;
        }
        //if same then increase count o/w decrease count if some other element comes
        //here we use the concept that if a element is in majority then count of others 
        //will always be <N/2
        else if(element==arr[i]){
            count++;
        }
        else{
            count--;
        }
    }

    count=0;
    //element will contain the element which is in majority

    for(int i=0;i<13;i++){
        if(element==arr[i]) count++;
    }
    if(count>13/2){
        cout<<element;
        return 0;
    }
    cout<<"no one is majority element";
    
} 
