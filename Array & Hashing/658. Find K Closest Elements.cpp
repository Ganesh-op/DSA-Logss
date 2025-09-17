class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int idx = -1;
        bool found = false;
        for(int i = 0; i<arr.size()-1; i++){
            if(arr[i]<=x && x<arr[i+1]){
                found = true;
                idx = i;
                break;
            }
        }
        vector<int> ans;
        if(!found){
            if(arr[0]>=x) idx = 0;
            else if(arr[arr.size()-1] <= x) idx = arr.size() - 1; 
        }
        int left = idx, right = idx + 1;
        for(int i = 0; i<k; i++){
            if(left>=0 && right<arr.size()){
                if(abs(arr[left] - x) <= abs(arr[right] - x)){
                    ans.push_back(arr[left]);
                    left--;
                }
                else{
                    ans.push_back(arr[right]);
                    right++;
                }
            }
            else if(left>=0){
                ans.push_back(arr[left]);
                left--;
            }
            else{
                ans.push_back(arr[right]);
                right++;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};