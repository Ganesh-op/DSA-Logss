class Solution {
public:
    void reverseString(vector<char>& a) {
    int left = 0, right = a.size() - 1;
    while (left < right) {
        swap(a[left], a[right]);
        left++;
        right--;
    }
}

    
};