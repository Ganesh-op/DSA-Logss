class Solution {
public:
    vector<int> arr;
    vector<vector<string>> ans;
    int cnt = 0;
    void helper(int row, int n) {
        if (row == n) cnt++;
        for (int col = 0; col < n; col++) {
            if (issafe(row, col, n)) {
                arr[row] = col;
                helper(row + 1, n);
            }
        }
    }

    bool issafe(int row, int col, int n) {
        for (int i = 0; i < row; i++) {
            if (arr[i] == col || abs(row - i) == abs(col - arr[i]))
                return false;
        }
        return true;
    }
    int totalNQueens(int n) {
        arr = vector<int>(n, -1);
        helper(0, n);
        return cnt;
    }
};


    