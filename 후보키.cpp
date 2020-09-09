#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    vector<int> ans;
    int n = relation.size();
    int m = relation[0].size();
    //bit mask
    int a = 1 << m;
    
    for (int i = 1; i < (1 << m); i++) {
        // 모든 경우의 수 검토하기 (bit mask)
        map<string,int> mm;
        for (int j = 0; j < n; j++) {
            // 모든 tuple에 대해서 유일성을 만족하는지?
            string str = "";
            for (int k = 0; k < m; k++) {
                // 속성 중에서 bitmask에서 1인 부분의 속성
                if ((i & (1 << k)) >= 1) {
                    str += relation[j][k];
                }
            }
            mm[str]++;
        }
        if (mm.size() == n) {
            // 유일성 만족

            // 최소성 체크
            int no = 0;
            for (int j = 0; j < ans.size(); j++) {
                for (int k = 0; k < m; k++) {
                    if ((ans[j] & i) == ans[j]) {
                        no = 1;
                        break;
                    }
                }
            }
            if(no==0)
                ans.push_back(i);
               
        }
    }
    answer = ans.size();
    return answer;
}

int main() {

    solution({  {"100","ryan","music","2"},
                {"200","apeach","math","2"},
                {"300","tube","computer","3"},
                {"400","con","computer","4"},
                {"500","muzi","music","3"},
                {"600","apeach","music","2"} });


    return 0;
}
