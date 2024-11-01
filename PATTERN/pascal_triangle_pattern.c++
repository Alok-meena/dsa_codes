#include <iostream>
using namespace std;

// Function to calculate factorial
int factorial(int num) {
    int fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

// Function to calculate nCr
int nCr(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

// Function to print Pascal's Triangle
void printPascalsTriangle(int n) {
    for (int line = 0; line < n; line++) {
        // Print leading spaces for alignment
        
        // Print the values in the current line
        for (int i = 0; i <= line; i++) {
            cout << nCr(line, i) << " "; // Calculate and print nCr
        }
        cout << endl; // Move to the next line
    }
}

int main() {
	int n;
	cin>>n;
    printPascalsTriangle(n);
    return 0;
}
