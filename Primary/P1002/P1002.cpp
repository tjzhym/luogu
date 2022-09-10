#include <cstdio>
#include <vector>


// step(): row, col
const std::vector<std::vector<int> > STEPS = { {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1} };

void HorseBlock(std::vector<std::vector<long long> > &map, const int horse_row, const int horse_col) {
    map[horse_row][horse_col] = 0;
	for (const auto step : STEPS) {
        int new_row = horse_row + step[0];
        int new_col = horse_col + step[1];
        if (new_row < 0 || new_row >= map.size() || new_col < 0 || new_col >= map[0].size()) {
	        continue;
        }
        map[new_row][new_col] = 0;
	}
}

void PrintPathsCount(std::vector<std::vector<long long> >& map, const int end_row, const int end_col) {
    int count = 0;
	for (size_t row = 0; row <= end_row; ++row) {
		for (size_t col = 0; col <= end_col; ++col) {
			if (map[row][col] == 0) {
				continue;
			}
            if (row == 0 && col == 0) {
                map[0][0] = 1;
            } else if (row == 0) {
                map[0][col] = map[0][col - 1];
            } else if (col == 0) {
                map[row][0] = map[row - 1][0];
            } else {
                map[row][col] = map[row - 1][col] + map[row][col - 1];
            }
		}
	}
    printf("%lld\n", map[end_row][end_col]);
}

int main() {
    int end_row;
    int end_col;
    int horse_row;
    int horse_col;
    scanf("%d %d %d %d", &end_row, &end_col, &horse_row, &horse_col);
    std::vector<std::vector<long long> > map(21, std::vector<long long>(21,1));
    HorseBlock(map, horse_row, horse_col);
    PrintPathsCount(map, end_row, end_col);
    return 0;
}