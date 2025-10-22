/*
    AUTHOR     - Prince Sharma
    DATE       - 22/7/2025 14:50
    PROBLEM    - Find the Town Judge
    NOTATION   - O -> worst case complexcity, S -> for space complexity, T -> for time complexity
    COMPLEXITY - TO(trust.size()+n), SO(n)
*/

class Solution
{
public:
    int findJudge(int n, vector<vector<int>>& trust)
    {
        vector<pair<bool, int>> people(n, {false, 0});
        for(auto& t:trust) {people[t[0]-1].first=true; people[t[1]-1].second++;}
        for(int i=1; i<=n; i++)
            if(people[i-1].first==false and people[i-1].second==n-1)
                return i;
        return -1;
    }
};