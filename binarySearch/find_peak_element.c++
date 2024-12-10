








this is correct but gives runtime error

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;  // Correct the initialization of high

        while (low <= high) {
            int mid = low + (high - low) / 2;  // Safe way to calculate mid

            // Check if mid is the peak
            if ((mid == 0 || nums[mid] > nums[mid - 1]) && 
                (mid == n - 1 || nums[mid] > nums[mid + 1])) {
                return mid;
            }

            // Move to the part of the array that is more likely to have a peak
            if (nums[mid] > nums[mid - 1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;  // Return -1 if no peak is found, though this shouldn't happen
    }
};



this runs correctly 

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        
        // Binary search approach
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] > nums[mid + 1]) {
                // Peak lies in the left half
                high = mid;
            } else {
                // Peak lies in the right half
                low = mid + 1;
            }
        }
        
        return low;  // The peak element is at index `low`
    }
};
