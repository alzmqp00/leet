#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
// n*lon(n) 有待優化
using namespace std;
class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        vector<int> dp(nums.size(), 0); // 到i點的最大值
        dp[0] = nums[0];
        multimap<int, int> maxHeap; // 為了拿到的索引
        maxHeap.insert({dp[0], 0});
        int index = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            // auto maxElement = *(maxHeap.rbegin());
            /*maxElement = *(maxHeap.rbegin());
        這個錯誤訊息表示你試圖賦值給一個 std::pair 的 first 成員，
        而該成員是 const 的。
            */
            // 如果最大值的索引值太小 就移除直到發現第一個可以用的數字
            while (i > (maxHeap.rbegin())->second + k)
            {
                maxHeap.erase((maxHeap.rbegin())->first);
            }

            dp[i] = nums[i] + (maxHeap.rbegin())->first;
            maxHeap.insert({dp[i], i});

            /*  for (int j = 1; j <= k; j++)
              {
                  if (i - j >= 0)
                      dp[i] = max(dp[i - j], dp[i]);
              }
            對於每一個i都往回k步找最大值
              dp[i] += nums[i];*/
        }
        /*   for (int i = 0; i < nums.size(); i++)
           {
               cout << dp[i] << endl;
           }*/
        return dp.back();
    }
};

/*class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        deque<int> queue;
        queue.push_back(0);
        for (int i = 1; i < n; i++) {
            while (!queue.empty() && queue.front() < i - k) {
                queue.pop_front();
            }
            dp[i] = dp[queue.front()] + nums[i];
            while (!queue.empty() && dp[queue.back()] <= dp[i]) {
                queue.pop_back();
            }
            queue.push_back(i);
        }
        return dp[n - 1];
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/jump-game-vi/solutions/2627601/tiao-yue-you-xi-vi-by-leetcode-solution-fdpb/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/