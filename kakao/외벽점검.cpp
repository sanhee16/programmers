#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 0;
    sort(dist.begin(), dist.end());
    int num = weak.size();
    vector<int> tmp_weak = weak;
    answer = 1e9;
    
    for (int i = 0; i < num; i++) {
        tmp_weak.push_back(tmp_weak[i] + n);
        int ans = 0;
        while (true) {
            ans = 0;
            int weak_num = 0;
            int idx = i;
            for (int j = 0; j <= dist.size(); j++) {
                if (idx >= i + num)
                    break;
                if (j == dist.size()) {
                    ans = 1e9;
                    break;
                }
                ans++;
                weak_num = tmp_weak[idx] + dist[j];
                while (true) {
                    if (idx == num + i)
                        break;
                    if (tmp_weak[idx] <= weak_num)
                        idx++;
                    else
                        break;
                }
            }
            if (answer > ans)
                answer = ans;
            if (next_permutation(dist.begin(), dist.end()) == false)
                break;
        }
    }
    if (answer == 1e9)
        answer = -1; 
    return answer;
} 


int main() {
    solution(12, { 1,4,5,7 }, { 1, 2, 3});
    return 0;
}
