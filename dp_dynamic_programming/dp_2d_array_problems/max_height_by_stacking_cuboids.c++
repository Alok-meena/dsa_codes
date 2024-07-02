Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed).
Choose a subset of cuboids and place them on each other.

You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj.
You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.

Return the maximum height of the stacked cuboids.

 

Example 1:



Input: cuboids = [[50,45,20],[95,37,53],[45,23,12]]
Output: 190
Explanation:
Cuboid 1 is placed on the bottom with the 53x37 side facing down with height 95.
Cuboid 0 is placed next with the 45x20 side facing down with height 50.
Cuboid 2 is placed next with the 23x12 side facing down with height 45.
The total height is 95 + 50 + 45 = 190.



class Solution {
public:


    //to hamne a[curr] aor a[prev] bheja yani curr to base vala cuboid hai aor prev new box
    //to l w h newbox ki kam honi chahie
    bool check(vector<int>base,vector<int>newbox){
        //0 1 2 pe w l h mojud hai
        if(newbox[0]<=base[0] && newbox[1]<=base[1] && newbox[2]<=base[2]){
            return true;
        }
        else{
            return false;
        }
    }
    int solve(int n,vector<vector<int>>&a){
        
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);
        
        //CURRINDEX+1 MEANS NEXT ROW AND CURINDEX MEANS CURR ROW
        
        //to 2 row se kam chal jayega
        
        for(int currindex=n-1;currindex>=0;currindex--){
            for(int previndex=currindex-1;previndex>=-1;previndex--){
                int include=0;
                //include case
                if(previndex==-1 || check(a[currindex],a[previndex])){//last se start kiya to curr vala base hai aor prev vala uspe jo cuboid aaya vo hai
                  //to yha pe hmari condition
                //alag hogi w1<w2 l1<l2 h1<h2 to iske liye function call kr do
                    
                    
                    //2 condn ek ki pahla element hai and 2nd uske bad vala

                    include=a[currindex][2]+next[currindex+1];//yha pe hme height add krni hai
                    //to current row ka 2nd column and outer loop row ka hai so use currindex
                    
                    
                    //aor vhi dp hai to previndex me curr ko +1 krna hi hoga
                    //curr ko aage bda do and prev 
                    //ab curr ke equal ho jayega
                }
                
                //exclude case
                int exclude=0+next[previndex+1];//+1 kiya prev me so that -1 na ho invalid index
                //curr to aage bd gya but not prev vo vhi rhega
                
                curr[previndex+1]=max(include,exclude);
            }
            
            next=curr;//har iteration ke bad aage vali row piche ke equal ho jayegi
        }
        return next[0];// pev -1 tk jayga to -1+1=0
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        //step1: sort all dimensions of the cuboid (l,b,h)
        //so that max value at end and we can assume it as height
        //values ko access kiya then sort
        for(auto&a:cuboids){
            sort(a.begin(),a.end());
        }

        //can use this also
        // for(int i=0;i<cuboids.size();i++){
        //     sort(cuboids[i].begin(),cuboids[i].end());
        // }

        //now sort all cuboids basis on w or l
        sort(cuboids.begin(),cuboids.end());//ye first parameter ke basis pe sort kr dega

        //now just apply LIS concept
        return solve(cuboids.size(),cuboids);
    }
};

t.c:-O(N^2)
s.c:-O(N^2)
