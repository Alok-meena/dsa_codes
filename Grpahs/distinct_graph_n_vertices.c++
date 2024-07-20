Input: N = 3 
Output: 8
Input: N = 4 
Output: 64 


The maximum number of edges a graph with N vertices can contain is X = N * (N – 1) / 2.
The total number of graphs containing 0 edge and N vertices will be XC0
The total number of graphs containing 1 edge and N vertices will be XC1
And so on from a number of edges 1 to X with N vertices
Hence, the total number of graphs that can be formed with n vertices will be:
XC0 + XC1 + XC2 + … + XCX = 2X.


  Given an integer N which is the number of vertices. The task is to find the number of distinct graphs that can be formed. Since the answer can be very large, print the answer % 1000000007.
Examples: 
 

Input: N = 3 
Output: 8
Input: N = 4 
Output: 64 
 


 


Approach: 
 

The maximum number of edges a graph with N vertices can contain is X = N * (N – 1) / 2.
The total number of graphs containing 0 edge and N vertices will be XC0
The total number of graphs containing 1 edge and N vertices will be XC1
And so on from a number of edges 1 to X with N vertices
Hence, the total number of graphs that can be formed with n vertices will be:
XC0 + XC1 + XC2 + … + XCX = 2X.

Below is the implementation of the above approach: 
 


<script>

// Javascript implementation of the approach

const MOD = 1000000000 + 7;

// Function to return (x^y) % MOD
// in O(log(y))
function power(x, y, MOD)
{
    let res = 1;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
        x = (x * x) % MOD;
        y = parseInt(y / 2);
    }
    return res;
}

// Function to return the count of distinct
// graphs possible with n vertices
function countGraphs(n)
{

    // Maximum number of edges for a
    // graph with n vertices
    let x = parseInt(n * (n - 1) / 2);

    // Function to calculate
    // (2^x) % mod
    return power(2, x, MOD);
}


THIS IS THE CODE WHICH I THOUGHT
