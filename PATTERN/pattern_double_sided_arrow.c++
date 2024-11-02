Take N as input. For a value of N=7, we wish to draw the following pattern :

                            1 
                        2 1   1 2 
                    3 2 1       1 2 3 
                4 3 2 1           1 2 3 4 
                    3 2 1       1 2 3 
                        2 1   1 2 
                            1 

Input Format
Take N as input.


Constraints
N is odd number.


Output Format
Pattern should be printed with a space between every two values.


Sample Input
7
Sample Output
            1 
        2 1   1 2 
    3 2 1       1 2 3 
4 3 2 1           1 2 3 4 
    3 2 1       1 2 3 
        2 1   1 2 
            1 
Explanation
Catch the pattern and print it accordingly.





#include <iostream>
using namespace std;


int main(){
    

    int n;
    cin>>n;

    int rows=1;
    int m=(n+1)/2;
    while(rows<=m){
        //and here instead of this formula we can change this formula to n-1 then decrement each time by 2 and before 2nd half of mirroring do z=z+4 then continue
        int spaces=(2*m)-2*rows;
        while(spaces){
            cout<<"  ";//here we printed 2 spaces instead of a single space
            spaces--;
        }

        int no=rows;
        while(no>=1){
            cout<<no<<" ";
            no--;
        }

        spaces=(2*(rows-1)-1);
        while(spaces>=1){
            cout<<"  ";
            spaces--;
        }

        no=1;
        if(rows!=1){
            while(no<=rows){
                cout<<no<<" ";
                no++;
            }
        }

        cout<<endl;
        rows++;
    }

    rows=m-1;
    while(rows>=1){
        
        int spaces=2*m-2*rows;
        while(spaces){
            cout<<"  ";
            spaces--;
        }

        int no=rows;
        while(no>=1){
            cout<<no<<" ";
            no--;
        }

        spaces=(2*(rows-1)-1);
        while(spaces>=1){
            cout<<"  ";
            spaces--;
        }

        no=1;
        if(rows!=1){
            while(no<=rows){
                cout<<no<<" ";
                no++;
            }
        }

        cout<<endl;
        rows--;
    }

}
