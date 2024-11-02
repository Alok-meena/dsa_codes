Take N (number of rows), print the following pattern (for N = 3).

                         1
                       2 3 2
                     3 4 5 4 3
                       2 3 2
                         1

Input Format

Constraints
0 < N < 10


Output Format

Sample Input
3
Sample Output
    1
	2	3	2
3	4	5	4	3
	2	3	2
		1
Explanation
Each number is separated from other by a tab.










#include <iostream>
using namespace std;


int main(){
    

    int n;
    cin>>n;

    int rows=1;
    while(rows<=n){
        int spaces=n-rows;
        while(spaces){
            cout<<"	";
            spaces--;
        }

        int number=rows;
        int col=1;
        while(col<=rows){
            cout<<number<<"	";
            number++;
            col++;
        }

        number=number-2;
        col=1;
        while(col<=rows-1){
            cout<<number<<"	";
            number--;
            col++;
        }

        cout<<endl;
        rows++;
    }

    //now mirroring concept is applied and it can only be applied upside down so just copy paste that code and do required changes as per the given question

    rows=n-1;
    while(rows>=1){
        int spaces=n-rows;
        while(spaces){
            cout<<"	";
            spaces--;
        }

        int number=rows;
        int col=1;
        while(col<=rows){
            cout<<number<<"	";
            number++;
            col++;
        }

        number=number-2;
        col=1;
        while(col<=rows-1){
            cout<<number<<"	";
            number--;
            col++;
        }

        cout<<endl;
        rows--;
    }

}
