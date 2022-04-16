#include <vector>
#include <map>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int getNumber(TreeNode* root, std::vector<std::vector<int>>& ops) {
        redInterval = std::map<int, int>();

        for (const auto& op : ops)
        {
            int type = op[0];
            int x = op[1];
            int y = op[2];

            if (type)
            {
                auto iter = redInterval.lower_bound(x);

                while (true)
                {
                    if (iter == redInterval.end() || iter->second > y)
                    {
                        redInterval.insert({y, x});
                        break;
                    }
                    else
                    {
                        int _x = iter->second;
                        int _y = iter->first;
                        redInterval.erase(iter);
                        redInterval.insert({_y, std::min(_x, x)});
                        if (y > _y)
                        {
                            x = _y + 1;
                        }
                        else
                        {
                            break;
                        }
                    }

                    iter = redInterval.lower_bound(x);
                }
            }
            else
            {
                auto iter = redInterval.lower_bound(x);

                while (true)
                {
                    if (iter == redInterval.end() || iter->second > y)
                    {
                        break;
                    }
                    else
                    {
                        int _x = iter->second;
                        int _y = iter->first;
                        redInterval.erase(iter);
                        if (x > _x)
                        {
                            redInterval.insert({x - 1, _x});
                        }
                        if (y < _y)
                        {
                            redInterval.insert({_y, y + 1});
                            break;
                        }
                        else
                        {
                            x = _y + 1;
                        }
                    }

                    iter = redInterval.lower_bound(x);
                }
            }
        }

        inorder(root);

        return res;
    }

private:
    int res = 0;
    std::map<int, int> redInterval;

    void inorder(TreeNode* node)
    {
        if (node == nullptr) return;

        auto iter = redInterval.lower_bound(node->val);

        if (iter != redInterval.end() && node->val >= iter->second) ++res;
        inorder(node->left);
        inorder(node->right);
    }
};