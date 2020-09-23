#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    int answer = 0;
    answer = -1;
    vector<long long> v[9];
    unordered_map<int, long long> m;
    unordered_set<int> s[9];
    int i = 1;
    for (; i < 9; i++) {
        int  a = N;
        for (int j = 1; j < i; j++)
            a = a * 10 + N;

        //v[i].push_back(a);
        //m.insert({i, a});
        s[i].insert(a);
        /*
        for (int j = 0; j < v[i - 1].size(); j++) {
            v[i].push_back(v[i - 1][j] + N);
            v[i].push_back(v[i - 1][j] - N);
            v[i].push_back(v[i - 1][j] / N);
            v[i].push_back(v[i - 1][j] * N);
        }
        */
        /*
        
        for (int k = 1; k <= i/2 ; k++) {
            for (int j = 0; j < v[i - k].size(); j++) {
                for (int l = 0; l < v[k].size(); l++) {
                    v[i].push_back(v[i - k][j] + v[k][l]);
                    v[i].push_back(v[i - k][j] - v[k][l]);
                    v[i].push_back(v[k][l] - v[i - k][j]);
                    v[i].push_back(v[i - k][j] * v[k][l]);
                    if (v[i - k][j] > v[k][l]) 
                        v[i].push_back(v[i - k][j] / v[k][l]);
                    else
                        v[i].push_back(v[k][l] / v[i - k][j]);
                }
            }
        }
        */
        for (int k = 1; k <= i ; k++) {
            for (const auto& s1 : s[i-k]) {
                for (const auto& s2 : s[k]) {
                    s[i].insert(s1 + s2);
                    s[i].insert(s1 - s2);
                    if(s2!=0)
                        s[i].insert(s1 / s2);
                    s[i].insert(s1 * s2);
                }
            }
        }

        for (const auto& it : s[i]) {
            if (it == number) {
                answer = i;
                cout << answer << endl;
                return answer;
            }
        }
        /*
        for (int j = 0; j < v[i].size(); j++) {
            if (v[i][j] == number) {
                answer = i;
                cout << answer << endl;
                return answer;
            }
        }
        */
    }
    cout << answer << endl;
    return answer;
}

int main() {
    solution(3, 3300);
    solution(5, 110);
    return 0;
}
