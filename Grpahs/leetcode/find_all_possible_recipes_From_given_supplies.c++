2115. Find All Possible Recipes from Given Supplies
Solved
Medium
Topics
Companies
Hint
You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. A recipe can also be an ingredient for other recipes, i.e., ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the answer in any order.

Note that two recipes may contain each other in their ingredients.

 

Example 1:

Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
Output: ["bread"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
Example 2:

Input: recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
Example 3:

Input: recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich","burger"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
We can create "burger" since we have the ingredient "meat" and can create the ingredients "bread" and "sandwich".
 

Constraints:

n == recipes.length == ingredients.length
1 <= n <= 100
1 <= ingredients[i].length, supplies.length <= 100
1 <= recipes[i].length, ingredients[i][j].length, supplies[k].length <= 10
recipes[i], ingredients[i][j], and supplies[k] consist only of lowercase English letters.
All the values of recipes and supplies combined are unique.
Each ingredients[i] does not contain any duplicate values.



as each recipe is dependent on ingridients and next recipes are dependent on previous ingridients and recipes too so there is a dependency and have to apply 
kahn's algo for topo sort alright 

so we created an edge from ingridients --- > recipes alright and similarly did for indgree and in queue we added inital available ingreidients alright
then just apply topo like if the indegree of any recipe becomes 0 then add it to the queue as we got sufficient amount of ingridients to make that recipe alright

sort and if by chance the ingridient from the recipie is a recipie from recipes which is required by further so add it to our ans


class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        map<string,vector<string>>adj; //adj[ingridient]=recipe so edge from ingridient --> recipe alright
        map<string,int>indegree;

        for(int i=0;i<recipes.size();i++){
            for(int j=0;j<ingredients[i].size();j++){
                adj[ingredients[i][j]].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }

        queue<string>q;
        for(auto supply:supplies){
            q.push(supply);
        }

        vector<string>ans;

        while(!q.empty()){
            string current=q.front();
            q.pop();

            if(std::find(recipes.begin(),recipes.end(),current)!=recipes.end()){
                ans.push_back(current);
            }

            for(auto neigh:adj[current]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }

        return ans;
    }
};
