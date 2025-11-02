class Solution {
public:
    bool isPerfectSquare(int x) {
        int r = (int) sqrt(x);
        return r * r == x;
    }
    
    int numSquares(int n) {
        // Case 1: 1 square
        if (isPerfectSquare(n)) return 1;
        
        // Case 2: sum of 2 squares
        for (int i = 1; i * i <= n; i++) {
            int j = n - i * i;
            if (isPerfectSquare(j)) return 2;
        }
        
        // Case 3 or 4: use Legendre’s theorem which is if n= 4^k(8m+7) then it cant be represented as sum of square of 3 integres
        int tmp = n;
        while (tmp % 4 == 0) tmp /= 4; 
        if (tmp % 8 == 7) return 4; 
        
        return 3; // if legendre holds true
    }
};