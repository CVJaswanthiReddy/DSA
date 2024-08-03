Minimum Number of Flips to Make Binary Grid Palindromic I

contest problem 2

class Solution {
public:
    int countFlipsForRow(vector<int>& row) {
        int n = row.size();
        int flips = 0;
        for (int i = 0; i < n / 2; i++) {
            if (row[i] != row[n - i - 1]) {
                flips++;
            }
        }
        return flips;
    }

    int countFlipsForColumn(vector<vector<int>>& grid, int col) {
        int m = grid.size();
        int flips = 0;
        if (col >= grid[0].size()) return flips; 
        for (int i = 0; i < m / 2; i++) {
            if (grid[i][col] != grid[m - i - 1][col]) {
                flips++;
            }
        }
        return flips;
    }

    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int rowFlips = 0;
        for (int i = 0; i < m; i++) {
            rowFlips += countFlipsForRow(grid[i]);
        }

        int colFlips = 0;
        for (int j = 0; j < n; j++) {
            colFlips += countFlipsForColumn(grid, j);
        }

        return min(rowFlips, colFlips);
    }
};