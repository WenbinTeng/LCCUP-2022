#include <vector>
#include <algorithm>

class Solution {
public:
    int getMaximumNumber(std::vector<std::vector<int>>& moles) {
        std::vector<std::vector<int>> dp(moles.size() + 1, std::vector<int>(2, 0));

        moles.push_back({0, 1, 1});

        std::sort(moles.begin(), moles.end());

        for (int i = 1; i < moles.size(); ++i)
        {
            int t = moles[i][0];
            int x = moles[i][1];
            int y = moles[i][2];

            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);

            for (int j = i - 1; j >= 0; --j)
            {
                int pt = moles[j][0];
                int px = moles[j][1];
                int py = moles[j][2];

                if (std::abs(x - px) + std::abs(y - py) <= t - pt)
                {
                    dp[i][1] = std::max(dp[i][1], dp[j][1] + 1);
                }

                if (t - pt >= 4)
                {
                    dp[i][1] = std::max(dp[i][1], dp[j][0] + 1);
                    break;
                }
            }
        }

        return std::max(dp.back()[0], dp.back()[1]);
    }
};