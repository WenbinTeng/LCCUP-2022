#include <vector>

class Solution {
public:
    int getMinimumTime(std::vector<int>& time, std::vector<std::vector<int>>& fruits, int limit) {
        int res = 0;

        for (int i = 0; i < fruits.size(); ++i)
        {
            int type = fruits[i][0];
            int num = fruits[i][1];

            res += time[type] * (num / limit);

            if (num % limit != 0) res += time[type];
        }

        return res;
    }
};