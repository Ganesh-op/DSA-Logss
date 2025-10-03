// Time Complexity : O(n)_Loop 
// Space Complexity : O(n) Space
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int>Seen; // Space O(n)
        for(int num:nums){
            if(Seen.find(num)!=Seen.end()) return num; // Found The Element in Set
            Seen.insert(num); // Upadate a Set
        }
        return -1;
    }
};