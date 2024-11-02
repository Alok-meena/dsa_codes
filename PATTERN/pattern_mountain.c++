Problem
Submissions
Leaderboard
Discuss
Take N (number of rows), print the following pattern (for N = 4).

                       1           1
                       1 2       2 1  
                       1 2 3   3 2 1
                       1 2 3 4 3 2 1   

Input Format

Constraints
0 < N < 10


Output Format

Sample Input
4
Sample Output
1						1
1	2				2	1
1	2	3		3	2	1
1	2	3	4	3	2	1


#include <iostream>
using namespace std;


int main(){
    

    int n;
    cin>>n;

    int rows=1;
    int z=(2*n)-3;
    while(rows<=n){
        int no=1;
        while(no<=rows){
            cout<<no<<"	";
            no++;
        }

        int spaces=z;
        while(spaces>=1){
            cout<<"	";
            spaces--;
        }

        no=rows;
        if(no==n){
            no--;
        }
        while(no>=1){
            cout<<no<<"	";
            no--;
        }



        cout<<endl;
        z=z-2;
        rows++;
    }

}
