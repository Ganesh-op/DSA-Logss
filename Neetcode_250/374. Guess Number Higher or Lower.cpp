
class Solution {
public:
    int guessNumber(int n) 
    {
      int low = 1, high = n ;
      while(low <= high)
      {
        int mid = low +( high - low)/2;

        int mid1 = guess(mid);

        if(mid1 == 0)
        {
          return mid;
        }
        else if(mid1 > 0) {
            low = mid + 1;
        }
        else{
            high = mid - 1;
        } 
      }
        return -1;
    }
};