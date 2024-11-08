#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int factorial(int num) {
    int fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

int nCr(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

void printPascalsTriangle(int n) {
//listen r<=n and both r and n starts from 0 so appply this formula for each row till 0 to n-1 and r fromm 0 to n
    for (int row = 0; row <n; row++) {
        
        for (int col = 0; col <=row; col++) {
            cout << nCr(row, col) <<"\t";
        }
        cout << endl;
    }
}

int main() {
	int n;
	cin>>n;
    printPascalsTriangle(n);
    return 0;
}
