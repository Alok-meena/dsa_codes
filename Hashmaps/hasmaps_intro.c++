#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main(){

    //creation
    unordered_map<string,int>m;

    //it sotre values in <key,value> format and each key will
    //have a unique value

    //insertion

    //method 1
    pair<string,int>p=make_pair("alok",3);
    m.insert(p);

    //method 2
    pair<string,int>pair2("love",2);
    m.insert(pair2);

    //method 3
    m["kumar"]=1;
    m["nasha"]=2;//so it will just update the old entry value of 1 to 2
    // to koi bhi key me pahli bar creation hota hai and 2nd time updation hota hai all of
    //the entries will be for the unique entries koi bhi duplicate entries nhi hogi

    //method 4
    m.insert({"meena",5});   

    //search
    cout<<m["alok"]<<endl;
    cout<<m.at("love")<<endl;

    //now searching a key value which is not defined
    // cout<<m.at("unknown")<<endl;
    cout<<m["unknown"]<<endl;// to is method ko use krke ager unknown key access kroge to uski entry bn jayegi corresponding to 0
    cout<<m.at("unknown")<<endl;//aor ab ye bhi 0 de dega

    //size
    cout<<m.size()<<endl;

    //to check presence of a key in the map
    cout<<m.count("bro")<<endl; //if key is not present -->0
    cout<<m.count("alok")<<endl; // if key is present -->1

    //erase function
    m.erase("unknown");
    cout<<m.size()<<endl;

    //how to traverse

    //1st method
    for(auto i:m){//auto function automatically assigns the type of value of m to i
        cout<<i.first<<" "<<i.second<<endl;
    }
    

    //2nd method using iterator
    unordered_map<string,int> :: iterator it=m.begin();
    while(it!=m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }

    //in unordered map the elements cannot be in sequence ----> O(1)  complexity for all insertion , deletion... operations
    //but using map(which is ordered map) elements will be displayed in sequence ---> O(logn)  complexity for all insertion , deletion... operations
    
    

    


}
