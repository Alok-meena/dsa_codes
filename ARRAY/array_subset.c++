Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m, where both arrays may contain duplicate elements. The task is to determine whether array a2 is a subset of array a1. It's important to note that both arrays can be sorted or unsorted. Additionally, each occurrence of a duplicate element within an array is considered as a separate element of the set.

Example 1:

Input:
a1[] = {11, 7, 1, 13, 21, 3, 7, 3}
a2[] = {11, 3, 7, 1, 7}
Output:
Yes
Explanation:
a2[] is a subset of a1[]

Example 2:

Input:
a1[] = {1, 2, 3, 4, 4, 5, 6}
a2[] = {1, 2, 4}
Output:
Yes
Explanation:
a2[] is a subset of a1[]




string isSubset(int a1[], int a2[], int n, int m) {
    
    sort(a1,a1+n);
    sort(a2,a2+m);
    
    for(int i=0;i<m;i++){
        int flag=0;
        int value=a2[i];
        for(int j=i;j<n;j++){
            if(value==a1[j]){
                flag=1;
            break;
            }
        }
        if(flag==0){
            return "No";
        }
        
    }
    
    return "Yes";
    
    
}



2nd// Function to check if a2 is a subset of a1
string isSubset(int a1[], int a2[], int n, int m) {
    
    // Create a unordered map to store the frequency of elements in a1
    unordered_map<int, int> um, um2;

    // Count the frequency of elements in a1
    for (int i = 0; i < n; i++) {
        um[a1[i]]++;
    }
    
    // Count the frequency of elements in a2
    for (int i = 0; i < m; i++) {
        um2[a2[i]]++;
    }

    int count = 0;
    
    // Iterate through the elements in a2
    for (auto it = um2.begin(); it != um2.end(); it++) {
        // If the frequency in a1 is greater than or equal to the frequency in a2,
        // increment the count
        if (um[it->first] >= it->second) {
            count+=it->second;
        }
    }
    
    // If the count is equal to the size of a2, a2 is a subset of a1
    if (count == m)
        return "Yes";
    // Otherwise, a2 is not a subset of a1
    else
        return "No";
}


Time Complexity: O(n + m) for counting frequencies in a1 and a2 and O(m) for comparing frequencies.
Space Complexity: O(n + m) for storing frequencies of elements in um and um2.


3:
  string isSubset(int a1[], int a2[], int n, int m) {
    std::sort(a1,a1+n);
    std::sort(a2,a2+m);

    int i = 0, j = 0;

    while (i < n && j < m) {
        if (a1[i] < a2[j]) {
            ++i;
        } else if (a1[i] == a2[j]) {
            ++i;
            ++j;
        } else {
            return "No";
        }
    }

    return (j == m) ? "Yes" : "No";
}

Time Complexity: O(n log n + m log m) due to the sorting operations.
Space Complexity: O(1) - no extra space used apart from the input arrays and a few variables.
