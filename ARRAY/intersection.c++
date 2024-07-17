
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //to is tarike se kisi me bhi sari values dali ja skti hai vector ki


        
        set<int>set1(nums1.begin(),nums1.end());//by this set gets elements which are unique
        set<int>set2(nums2.begin(),nums2.end());
        
        vector<int>ans;
        for(auto value:set1){
            if(set2.find(value)!=set2.end()){//we know that set2.find() operator if found returns and iterator to the element if not found then it return set2.end()
                ans.push_back(value);
            }
        }
        return ans;
        
    }
};
