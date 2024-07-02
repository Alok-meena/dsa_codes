// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//to bat ye hai ki 2 d me ya vector<pair<int,int>> me only sort vala 1st para ke basis pe sort karta hai if we have to consider other also use comparator

bool comparator(vector<int>&a,vector<int>&b){
    return a[0]>b[0];
}
int main(){
    
    vector<vector<int>>a={{3,50,2},{5,0,6}};
    for(int i=0;i<2;i++){
        sort(a[i].begin(),a[i].end());
    }
    sort(a.begin(),a.end());
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

o/p:--0 5 6 
      2 3 50 





  another method to sort normally and if any condition satisfies


static bool comparator(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];//to isse jab dono width equal hui to height ko descending order me 
            //sort kr diya jayega
        }

        return a[0]<b[0];//means by this we will sort according to width
    }
