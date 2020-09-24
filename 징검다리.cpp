#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int r = distance, l = 0, mid = distance / 2;
    vector<int> dist;
    int rock_num = rocks.size();
    sort(rocks.begin(), rocks.end());
    int t = 0;
    for (int i = 0; i < rock_num; i++) {
        dist.push_back(rocks[i] - t);
        t = rocks[i];
    }
    dist.push_back(distance - t);

    while (true) {
        if (l > r)
            break;
        mid = (l+r) / 2;
        int tmp = 0, cnt = 0, idx = 0;
        while (true) {
            if (idx == dist.size())
                break;
            tmp += dist[idx];
            if (tmp < mid) {
                cnt++;
            }
            else {
                tmp = 0;
            }
            idx++;
        }
        if (cnt <= n) {
            answer = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }

    }
    cout << answer << endl;
    return answer;
}

int main() {
    solution(25, { 2, 14, 11, 21, 17 }, 2);
    return 0;
}
