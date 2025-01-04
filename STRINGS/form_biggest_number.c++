Form Biggest Number
Medium
Difficulty
7
Submissions
100
Max Points
Status: Contest Over

0/100 Points
Problem
Submissions
Leaderboard
Discuss
You are provided an array of numbers. You need to arrange them in a way that yields the largest value.


Input Format
First line contains integer t which is number of test case.
For each test case, you are given a single integer n in the first line which is the size of array A[] and next line contains n space separated integers denoting the elements of the array A .


Constraints
1<=t<=100

1<=m<=100

1<=A[i]<=10^5


Output Format
Print the largest value.


Sample Input
1
4
54 546 548 60
Sample Output
6054854654
Explanation
Upon rearranging the elements of the array , 6054854654 is the largest possible number that can be generated.



first of all sorting will work if we are concatenating two strings then we have to take such a way that the string should be bigger okk





#include<bits/stdc++.h>
using namespace std;

bool cmp(string &a,string &b){
	return a+b>b+a;
}
int main() {
	int t;
	cin>>t;

	while(t--){
		int m;
		cin>>m;
		vector<string>v(m);
		for(int i=0;i<m;i++){
			cin>>v[i];
		}

		sort(v.begin(),v.end(),cmp);
		if(v[0]=="0"){
			cout<<"0"<<endl;
		}
		else{
			for(int i=0;i<m;i++){
				cout<<v[i];
			}
		}
		cout<<endl;

		
	}
	return 0;
}


if integers are given then convert them to strings okk then same approach


#include <bits/stdc++.h>
using namespace std;

// Custom comparator to compare two numbers as strings
bool cmp(int a, int b) {
    string sa = to_string(a);
    string sb = to_string(b);
    return sa + sb > sb + sa;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int m;
        cin >> m;

        vector<int> v(m);
        for (int i = 0; i < m; i++) {
            cin >> v[i];
        }

        // Sort using the custom comparator
        sort(v.begin(), v.end(), cmp);

        // Check for the all-zero case
        if (v[0] == 0) {
            cout << "0" << endl;
        } else {
            // Print the largest number by concatenating sorted integers
            for (int num : v) {
                cout << num;
            }
            cout << endl;
        }
    }

    return 0;
}


Sure! Let’s break this problem and its solution into simple steps so you can understand **why it works** and **how the logic is applied**.

---

### **Problem Goal**
You have an array of numbers, and you need to rearrange them to form the **largest possible number**. For example:
- Given numbers: `54, 546, 548, 60`
- Rearranging them as `6054854654` yields the largest number.

The trick is to **find the right order of concatenation** for these numbers.

---

### **Why Sorting Works**
The key insight is:
1. **Order matters when concatenating numbers**.
   - Example: For numbers `54` and `546`, there are two ways to concatenate:
     - `54546`
     - `54654`
   - Clearly, `54654` is larger, so `546` should come before `54`.

2. **Custom Comparator**:
   - The comparator checks two numbers, `a` and `b`, and decides their order based on which concatenation (`a+b` or `b+a`) is larger.
   - For example:
     - If `a = "54"` and `b = "546"`, we compare:
       - `"54546"` (a+b)
       - `"54654"` (b+a)
     - Since `"54654"` is larger, we say `b` (`546`) should come before `a` (`54`).

---

### **How the Solution Works**
#### 1. **Treat Numbers as Strings**
   - Numbers are converted to strings so they can be concatenated and compared.
   - This is because `+` for strings means concatenation, while for integers it means addition.

#### 2. **Sort Using Custom Comparator**
   - The `sort` function in C++ allows you to provide a custom comparison function.
   - In this problem, the comparator:
     ```cpp
     bool cmp(string &a, string &b) {
         return a + b > b + a;
     }
     ```
     - It ensures that if `a + b` (concatenating `a` first) is larger, `a` is placed before `b` in the sorted array.
     - This guarantees that the resulting concatenated string is as large as possible.

#### 3. **Concatenate Sorted Strings**
   - After sorting, you simply concatenate the numbers in order. The result is the largest number.

#### 4. **Handle Edge Case for All Zeros**
   - If the largest number in the sorted array is `"0"`, it means all numbers are zeros. The result should just be `"0"`.

---

### **Why This Approach Works**
Sorting ensures that each pair of numbers is placed in the order that maximizes the final concatenated result. Since sorting considers all pairs, the final arrangement is optimal.

#### **Proof with an Example**
Consider the array: `[54, 546, 548, 60]`.

1. **Sorting Step**:
   - Compare `546` and `54`:
     - `"54654"` (546 + 54) > `"54546"` (54 + 546), so `546` comes before `54`.
   - Compare `548` and `546`:
     - `"548546"` (548 + 546) > `"546548"` (546 + 548), so `548` comes before `546`.
   - Compare `60` and `548`:
     - `"60548"` (60 + 548) > `"54860"` (548 + 60), so `60` comes before `548`.

   After sorting: `[60, 548, 546, 54]`.

2. **Concatenation**:
   - Combine the sorted numbers: `6054854654`.

3. **Output**:
   - The result is the largest number that can be formed.

---

### **Complexity Analysis**
1. **Sorting**:
   - Sorting `m` numbers takes \(O(m \log m)\), where `m` is the number of numbers in the array.
   - Each comparison in sorting involves concatenating two strings, which takes \(O(k)\), where `k` is the average length of the numbers.
   - Total sorting complexity: \(O(m \cdot k \cdot \log m)\).

2. **Concatenation**:
   - Concatenating all numbers takes \(O(m \cdot k)\).

   **Overall Complexity**: \(O(m \cdot k \cdot \log m)\).

---

### **Summary**
- **Why It Works**: The custom comparator ensures the numbers are arranged in an order that maximizes the concatenated result.
- **Key Insight**: Comparing `a+b` and `b+a` gives the correct relative order for each pair of numbers.
- **Edge Cases**: Handles all zeros correctly by checking if the largest number is `"0"`.

If anything is still unclear, feel free to ask!
