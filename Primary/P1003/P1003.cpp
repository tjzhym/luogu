#include <cstdio>
#include <vector>


int main() {
    int n;
    scanf("%d\n", &n);
    std::vector<std::vector<int> > carpets;
    for (int id = 0; id < n; ++id) {
        int a, b, g, k;
        scanf("%d %d %d %d\n", &a, &b, &g, &k);
        std::vector<int> carpet{ a, b, g, k };
        carpets.emplace_back(carpet);
    }
    int x, y;
    scanf("%d %d", &x, &y);

    for (int id = n - 1; id >= 0; --id) {
        int a = carpets[id][0];
        int b = carpets[id][1];
        int g = carpets[id][0] + carpets[id][2];
        int k = carpets[id][1] + carpets[id][3];
        if (a <= x && x <= g && b <= y && y <= k) {
            printf("%d\n", id + 1);
            break;
        }
        if (id == 0) {
            printf("-1\n");
        }
    }
    return 0;
}