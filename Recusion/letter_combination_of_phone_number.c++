17. Letter Combinations of a Phone Number
Solved
Medium
Topics
Companies
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
0







class Solution {
public:
    void solve(string digits,vector<string>&ans,string output,int idx,string mapping[]){
        if(idx>=digits.length()){
            ans.push_back(output);
            return;
        }

        int key=digits[idx]-'0';
        string value=mapping[key];

        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solve(digits,ans,output,idx+1,mapping);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.length()==0) return ans;
        string output;
        int idx=0;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,ans,output,idx,mapping);
        return ans;
    }
};


2nd time


class Solution {
public:
    void solve(int idx,string digits,vector<string>&store,vector<string>&ans,string output){
        if(idx>=digits.length()){
            ans.push_back(output);
            return;
        }

        int i=digits[idx]-'0';
        for(auto ch:store[i]){
            output.push_back(ch);
            solve(idx+1,digits,store,ans,output);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>store={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        vector<string>ans;

        if(digits.empty()) return ans;

        string output;

        solve(0,digits,store,ans,output);

        return ans;
    }
};

t.c:-O(4^n) in worst case and s.c:-O(n) due to ans and recursive stack

it is 4^n becasue in worst case 


Exactly! You're absolutely right. Let's break it down clearly:

---

### 🔍 Why is it exponential?

Each digit in the input string maps to **3 or 4 letters**:

* Most digits (`2–6`, `8`) → **3 letters**
* Digits `7` and `9` → **4 letters**

---

### 📌 Key Insight:

* You are **combining letters for each digit**.
* So for `n` digits, where each digit maps to up to `4` letters, the **total combinations** are:

$$
\text{Total combinations} = \text{(number of letters for digit 1)} \times \text{(number of letters for digit 2)} \times \dots \text{(digit n)}
$$

---

### 🔺 Worst Case:

If every digit maps to 4 letters (like all `7` or `9`), then:

$$
\text{Total combinations} = 4^n
$$

That’s **why the time complexity is exponential** in terms of `n` (number of digits).

---

### ✅ Summary:

* Yes, **each letter on the left combines with each letter on the right**, just like nested loops.
* And since the number of digits (`n`) is variable, the **branching factor** at each level causes the total to grow **exponentially** → `O(4^n)` in the worst case.

 
Let me know if you want help visualizing this as a tree!


3rd time


class Solution {
public:
    void solve(string digits,vector<string>&mapping,vector<string>&ans,string output,int idx){
        if(idx>=digits.length()){
            ans.push_back(output);
            return;
        }

        int digit=digits[idx]-'0';

        for(int i=0;i<mapping[digit].length();i++){
            output.push_back(mapping[digit][i]);
            solve(digits,mapping,ans,output,idx+1);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {

        if(digits.empty()) return {};
        vector<string>mapping={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        vector<string>ans;

        string output;

        solve(digits,mapping,ans,output,0);

        return ans;
    }
};

