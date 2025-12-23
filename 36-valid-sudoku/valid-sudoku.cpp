class Solution {
int SudokuRank = 9;
    int SudokuRoot = 3;

public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::unordered_map<int, std::unordered_set<char>> rows;
        std::unordered_map<int, std::unordered_set<char>> columns;
        std::unordered_map<int, std::unordered_set<char>> clusters;

        for (int i = 0; i < SudokuRank; ++i) {
            for (int j = 0; j < SudokuRank; ++j) {
                char c = board[i][j];
                if (c == '.') {
                    continue;
                }

                // Create the cluster key by converting integer divisions to string
                int clusterKey = (i / SudokuRoot) * 10 + (j / SudokuRoot);

                // Insert into clusters
                if (clusters.find(clusterKey) == clusters.end()) {
                    clusters[clusterKey] = std::unordered_set<char>();
                }
                if (!clusters[clusterKey].insert(c).second) {
                    return false;
                }

                // Insert into columns
                if (columns.find(j) == columns.end()) {
                    columns[j] = std::unordered_set<char>();
                }
                if (!columns[j].insert(c).second) {
                    return false;
                }

                // Insert into rows
                if (rows.find(i) == rows.end()) {
                    rows[i] = std::unordered_set<char>();
                }
                if (!rows[i].insert(c).second) {
                    return false;
                }
            }
        }

        return true;
    }
};