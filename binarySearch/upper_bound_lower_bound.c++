terator lower_bound (Iterator first, Iterator last, const val)  
lower_bound returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘val’  and if the
value is not present in the vector then it returns the end iterator.

Iterator upper_bound (Iterator first, Iterator last, const val)
upper_bound returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘val’  and if the value is 
not present in the vector then it returns the end iterator.



WE CAN ALSO use stl functions

int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.
	return upper_bound(arr.begin(),arr.end(),x)-arr.begin();
}

	return lower_bound(arr.begin(),arr.end(),x)-arr.begin();//as these will return iterators so -.begin() to convert them to index


// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

int lower_bound(vector<int>&v,int value){
    
    int low=0;
    int high=v.size()-1;
    int ans=v.size();//if value doesnot exist then end() will be returned
    while(low<=high){
        int mid=low+(high-low)/2;
        if(v[mid]>=value){
            ans=mid;//as lower_bound always return the index
            high=mid-1;//this is done as ex 1 2 3 8 8 8 8 9 9 so in this mid is 4 but it is not the first occurence to get it we have to move towards left 
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}


int upper_bound(vector<int>&v,int value){
    int low=0;
    int high=v.size()-1;
    int ans=v.size();
    while(low<=high){
        int mid=low+(high-low)/2;
        if(v[mid]>value){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int main() {
    // Write C++ code here
    vector<int>v={1,2,3,4,5,6,7,8};
    cout<<lower_bound(v,4);

    return 0;
}
