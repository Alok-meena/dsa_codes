Reverse Using Stack
Difficulty: EasyAccuracy: 76.17%Submissions: 101K+Points: 2
You are given a string S, the task is to reverse the string using stack.

Example 1:

Input: S="GeeksforGeeks"
Output: skeeGrofskeeG
Example 2:

Input: S="Geek"
Output: keeG
Your Task:
You don't need to read input or print anything. Your task is to complete the function reverse() which takes the string S as an input parameter and returns the reversed string.

Constraints:
1 ≤ length of the string ≤ 100


char* reverse(char *S, int len)
{
    //code here
    stack<char>ch;
    

    for(int i=0;i<len;i++){
        ch.push(S[i]);
    }
    
    char *s=new char[len];
    int i=0;
    
    while(!ch.empty()){
        s[i++]=ch.top();
        ch.pop();
    }
    
    return s;
}








so if we are given with char *s string then these are the ways to traverse them



#include <bits/stdc++.h>
using namespace std;

int main(){

    const char *s="hello world";
    
    for(const char *ptr=s;*ptr!='\0';ptr++){
        cout<<*ptr<<" ";
    }
}

const to notify that the string is immutable okk;


and if length is given then we can access the string in the above method


and to insert values use these method:-
  If you want to insert characters into a `char*` one by one, you need to ensure the memory is writable and large enough to accommodate the inserted characters. Here's how you can achieve this in different scenarios:

---

### **1. Using a Mutable Character Array**
You can use a pre-allocated character array and insert characters by directly assigning them to specific positions.

#### Example:
```cpp
#include <iostream>
using namespace std;

int main() {
    char s[20] = ""; // Mutable array with enough space, initialized to an empty string
    int index = 0;   // Tracks the current position

    // Push characters one by one
    s[index++] = 'h';
    s[index++] = 'e';
    s[index++] = 'l';
    s[index++] = 'l';
    s[index++] = 'o';
    s[index++] = ' ';
    s[index++] = 'w';
    s[index++] = 'o';
    s[index++] = 'r';
    s[index++] = 'l';
    s[index++] = 'd';
    s[index] = '\0'; // Null-terminate the string

    cout << s << endl; // Output: hello world
    return 0;
}
```

---

### **2. Using Dynamically Allocated Memory**
You can allocate memory dynamically and insert characters using a pointer.

#### Example:
```cpp
#include <iostream>
using namespace std;

int main() {
    int maxLen = 20;
    char* s = new char[maxLen]; // Dynamically allocate memory
    int index = 0;             // Tracks the current position

    // Push characters one by one
    s[index++] = 'h';
    s[index++] = 'e';
    s[index++] = 'l';
    s[index++] = 'l';
    s[index++] = 'o';
    s[index++] = ' ';
    s[index++] = 'w';
    s[index++] = 'o';
    s[index++] = 'r';
    s[index++] = 'l';
    s[index++] = 'd';
    s[index] = '\0'; // Null-terminate the string

    cout << s << endl; // Output: hello world

    delete[] s; // Free allocated memory
    return 0;
}
```

---

### **3. Using `std::string` (Preferred for Modern C++)**
If you're working in modern C++, use `std::string` to handle memory and push characters conveniently.

#### Example:
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;

    // Push characters one by one
    s.push_back('h');
    s.push_back('e');
    s.push_back('l');
    s.push_back('l');
    s.push_back('o');
    s.push_back(' ');
    s.push_back('w');
    s.push_back('o');
    s.push_back('r');
    s.push_back('l');
    s.push_back('d');

    cout << s << endl; // Output: hello world
    return 0;
}
```

---

### **Summary**
- **For Mutable Arrays:** Use indexing and ensure the array is null-terminated.
- **For Dynamically Allocated Memory:** Allocate sufficient space and manage memory manually.
- **For Modern C++:** Use `std::string` for simplicity and safety, as it automatically manages memory and provides methods like `push_back`.
