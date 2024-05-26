#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        long long res = 0;
        int maxdiff = 0; // 最大差距
        int maxnum = nums[0];
        int minnum = INT32_MAX;
        int possiblemax = maxnum;
        // 可能的最大值 12...5...20.15 18.. 雖然20>12 但是我不能直接把12用20代替 而是先記下來但是不動
        // 因為20後面可能沒有比20小很多的數字
        for (int i = 1; i < nums.size(); i++)
        {
            //
            res = max(res, (long long)maxdiff * (long long)nums[i]);
            if (possiblemax - nums[i] > maxdiff)
            { // 沿用上面的例子的話 就是20後面現了小於13的數字 於是更改當前最大和最小
                minnum = nums[i];
                maxnum = possiblemax;
            }
            if (nums[i] > maxnum)
            {
                // 我一開始沒有加上max函數possiblemax =nums[i]
                // 導致比較大的poss會被比較小的數字覆蓋掉
                // ex 12.....5...14...13......略 14因為後面沒有發現小於7的數字  所以一直是poss
                // 當遇到13的時候nums[i] > maxnum為true 導致14被覆蓋
                possiblemax = max(possiblemax, nums[i]);
                // maxnum = nums[i];
                // minnum = INT32_MAX;
            }

            maxdiff = maxnum - minnum;
        }
        return res;
    }
};