#include <vector>
#include <string>
#include <deque>

class Solution {
public:
    int conveyorBelt(std::vector<std::string>& matrix, std::vector<int>& start, std::vector<int>& end) {
        int m = matrix.size();
        int n = matrix[0].size();
        std::vector<std::vector<int>> op(101, std::vector<int>(101, -1));
        std::vector<std::vector<bool>> visit(101, std::vector<bool>(101, false));
        const std::vector<int> dx = {-1, 0, 1, 0};
        const std::vector<int> dy = {0, 1, 0, -1};
        const std::vector<char> dict = {'^', '>', 'v', '<'};
        std::deque<std::pair<int, int>> dq;

        dq.push_back({start[0], start[1]});

        op[start[0]][start[1]] = 0;

        while (!dq.empty())
        {
            auto [x, y] = dq.front();
            dq.pop_front();

            if (x == end[0] && y == end[1]) return op[x][y];

            if (visit[x][y]) continue;
            visit[x][y] = true;

            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visit[nx][ny]) continue;

                if (dict[i] == matrix[x][y])
                {
                    dq.push_front({nx, ny});
                    op[nx][ny] = op[x][y];
                }
                else
                {
                    dq.push_back({nx, ny});
                    op[nx][ny] = op[nx][ny] != -1 ? std::min(op[nx][ny], op[x][y] + 1) : op[x][y] + 1;
                }
            }
        }

        return -1;
    }
};