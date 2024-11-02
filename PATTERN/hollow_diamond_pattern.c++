Take N (number of rows), print the following pattern (for N = 5).

     * * * * *
     * *   * *
     *       *
     * *   * *
     * * * * *

Input Format

Constraints
0 < N < 10 (where N is an odd number)


Output Format

Sample Input
5
Sample Output
*	*	*       *      *		  
*	*	        *      *
* 	                       *
* 	*               *      *
* 	*	*       *      *	
Explanation
Each '*' is separated from other by a tab.











#include <iostream>
using namespace std;


int main(){
    

    int n;
    cin>>n;

    int rows=1;
    int m=(n+1)/2;
    while(rows<=m){
        if(rows==1){
            int col=1;
            while(col<=n){
                cout<<"*";
                col++;
            }
        }
        else{
            
            int star=m-rows+1;
            while(star>=1){
                cout<<"*";
                star--;
            }

            int spaces=(2*(rows-1)-1);
            while(spaces>=1){
                cout<<" ";
                spaces--;
            }

            star=m-rows+1;
            while(star>=1){
                cout<<"*";
                star--;
            }
        }

        cout<<endl;
        rows++;
    }

    rows=m-1;
    while(rows>=1){
        if(rows==1){
            int col=1;
            while(col<=n){
                cout<<"*";
                col++;
            }
        }
        else{
            
            int star=m-rows+1;
            while(star>=1){
                cout<<"*";
                star--;
            }

            int spaces=(2*(rows-1)-1);
            while(spaces>=1){
                cout<<" ";
                spaces--;
            }

            star=m-rows+1;
            while(star>=1){
                cout<<"*";
                star--;
            }
        }

        cout<<endl;
        rows--;
    }

}
