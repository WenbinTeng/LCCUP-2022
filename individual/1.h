#include <vector>

class Solution {
public:
    int giveGem(std::vector<int>& gem, std::vector<std::vector<int>>& operations) {
        for (const auto& operation : operations)
        {
            int x = operation[0];
            int y = operation[1];

            int g = gem[x] / 2;
            gem[x] -= g;
            gem[y] += g;
        }


        int minGem = gem[0];
        int maxGem = gem[0];

        for (const auto g : gem)
        {
            minGem = std::min(minGem, g);
            maxGem = std::max(maxGem, g);
        }

        return maxGem - minGem;
    }
};