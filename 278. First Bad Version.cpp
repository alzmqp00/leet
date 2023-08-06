// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int mid;
        int bot=1;
        while(n>=bot){
            mid=(n+bot)/2;
            if(isBadVersion(bot)==0 && isBadVersion(n)==1){
                return n;
            }
            if(isBadVersion(mid)){
                n=mid-1;
            }
            else bot=mid+1;
        }
        return -1;
    }
        

        
    
};