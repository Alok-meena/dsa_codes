#include <iostream>
#include <math.h>
using namespace std;

#define MOD 1000000007


//log base 2 n complexity
long long solve(long long x,long long n){
    long long ans=1;

    while(n>0){
        cout<<ans<<" ";
        if(n%2==1){
            ans=ans*x;
            n=n-1;//reducing the no. to reach even power
        }
        else{
            x=x*x;
            n=n>>1;
        }
    }
    return ans;
}
long long power(int n){
    long long x=(long long)(n*(n-1))/2;
    cout<<x<<" "<<endl;
    return solve(2,x);
}
int main(){
    int n;
    cout<<"enter the value of n:";
    cin>>n;
    cout<<power(n);
}



#include <iostream>
using namespace std;

const int MOD = 1000000007; // Define the modulus

// Function to compute (x^y) % MOD in O(log y) time
long long power(long long x, long long y, int MOD) {
    long long result = 1;
    x = x % MOD; // Take modulo of x initially to handle large base

    while (y > 0) {
        if (y % 2 == 1) { // If y is odd
            result = (result * x) % MOD;
        }
        y = y >> 1; // y = y / 2
        x = (x * x) % MOD; // Square the base
    }

    return result;
}

// Function to compute the number of distinct graphs with n vertices
long long countGraphs(int n) {
    // Maximum number of edges in a simple graph with n vertices
    long long maxEdges = (long long)n * (n - 1) / 2;

    // Number of distinct graphs is 2^maxEdges
    return power(2, maxEdges, MOD);
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    
    cout << "Number of distinct graphs with " << n << " vertices is: " << countGraphs(n) << endl;
    
    return 0;
}
in the 2nd code we didnt use else case so no require to decrease the power
