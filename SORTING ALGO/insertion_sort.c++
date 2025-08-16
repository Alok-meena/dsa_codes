#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {5, 4, 3, 2, 1};
    int n = v.size();

    for (int i = 1; i < n; i++) { // Start from the second element
        int key = v[i];          // The current element to be inserted
        int j = i - 1;

        // Move elements of v[0..i-1], that are greater than key, one position ahead
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j]; //are bhai ager picla element chota hai to shift bhi to kroge elements ko alright very imp
            j--;
        }

        v[j + 1] = key; // Insert the key at the correct position
    }

    // Print the sorted array
    for (auto i : v) {
        cout << i << " ";
    }

    return 0;
}

isme ham mante hai ki left part sorted hai aor pure array se compare krke us part ko sort krte hai okk


int main() {
    vector<int> v = {5, 4, 3, 2, 1};
    int n = v.size();

    for (int i = 1; i < n; i++) { // Start from the second element
        int j = i;

        // Move elements of v[0..i-1], that are greater than key, one position ahead
        while (j >0 && v[j] > v[j-1]) {
            swap(v[j],v[j-1])
            j--;
        }

    }


but the above one is more efficient 


#include <bits/stdc++.h>
using namespace std;

recursive one

void insertionsort(int i,int n,vector<int>&arr){
    if(i==n) return;

    int j=i;
    while(j>0 and arr[j-1]>arr[j]){
        swap(arr[j],arr[j-1]);
        j--;
    }

    insertionsort(i+1,n,arr);
}

int main(){
    vector<int>v={5,4,3,2,1};

    for(int i=1;i<5;i++){
        int j=i;
        while(j>0 and v[j]<v[j-1]){
            swap(v[j],v[j-1]);
            j--;
        }
    }

    for(auto i:v) cout<<i<<" "; 
    
}
