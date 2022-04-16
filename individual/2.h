#include <vector>

class Solution {
public:
    int perfectMenu(std::vector<int>& materials, std::vector<std::vector<int>>& cookbooks, std::vector<std::vector<int>>& attribute, int limit) {
        dfs(materials, cookbooks, attribute, limit, 0, 0, 0);
        return res;
    }

private:
    int res = -1;

    void dfs(std::vector<int>& materials, std::vector<std::vector<int>>& cookbooks, std::vector<std::vector<int>>& attribute, int limit, int index, int x, int y)
    {
        if (index == cookbooks.size())
        {
            if (y >= limit)
            {
                res = std::max(res, x);
            }
            return;
        }
        
        bool enough = true;
        auto _materials = materials;
        for (int i = 0; i < _materials.size(); ++i)
        {
            if (_materials[i] < cookbooks[index][i])
            {
                enough = false;
                break;
            }
            _materials[i] -= cookbooks[index][i];
        }
        if (enough)
        {
            dfs(_materials, cookbooks, attribute, limit, index + 1, x + attribute[index][0], y + attribute[index][1]);
        }
        dfs(materials, cookbooks, attribute, limit, index + 1, x, y);
    }
};