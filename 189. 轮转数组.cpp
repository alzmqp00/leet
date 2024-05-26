#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size(); // 3%7=2

        // 嚴格來說不能分成左右
        int rindex = 0;
        int leftindex = 0;
        // 這個i不是index 只是記數i < nums.size()可以改成 i < nums.size()-1
        // 因為只剩下一個數還沒排過的話 他一定是正確的

        /*原本的想法是說
        每過一次迴圈
        利用保存的上一次迴圈保存到nums[0]的元素 和tempindex(紀錄nums[0]的元素原本在哪個位置)的資訊
        計算出nums[0]元素要放到哪一個位置 放過去之後 將該位置的元素保存到nums[0] 同時保存索引
        但是忽略了當tempindex就是0的情況 自己和自己換 沒辦法取得一個新的數字 只能來回轉圈

        如此確定一個數字在正確的位置上 重複n次就好

        */
        for (int i = 0; i < nums.size(); i++)
        {

            rindex = (rindex + k) % nums.size();
            if (leftindex == rindex)
            {
                leftindex = (leftindex + 1) % nums.size();
                rindex = (rindex + 1) % nums.size();
            }

            swap(nums[leftindex], nums[rindex]);
        }
    }
};