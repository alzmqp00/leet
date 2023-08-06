#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        int res;
        res=arrivalTime+delayedTime;
        if(res>=24){
            res-=24;
        }
        return res;
    }
};