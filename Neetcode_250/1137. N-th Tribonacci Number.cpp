class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        int t1 = 0, t2 = 1, t3 = 1;
        int next = 0;

        for (int i = 3; i <= n; i++) {
            next = t1 + t2 + t3;
            t1 = t2;
            t2 = t3;
            t3 = next;
        }
        return next;
    }
};