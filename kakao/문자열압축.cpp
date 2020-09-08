#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

int solution(string s){
    int str_size = s.length();
    int answer = str_size;
    string res = "", left = "";
    string ans_str = "";
    for (int i = str_size / 2; i > 0; i--) {
        int idx = 0, cnt = 1;
        res = "";
        while (true){
            if (idx > str_size - i) {
                if (cnt > 1)
                    res += to_string(cnt);
                res = res + s.substr(idx);
                break;
            }
            string tmp = s.substr(idx, i);
            int idx_tmp = idx + i;
            if (idx_tmp > str_size - i) {
                if (cnt > 1) 
                    res += to_string(cnt);
                
                res += s.substr(idx);
                break;
            }
            idx += i;
            string next_tmp = s.substr(idx, i);
            if (tmp.compare(next_tmp) == 0) {
                cnt++;
            }
            else {
                if (cnt == 1) {
                    res += tmp;
                }
                else {
                    res += to_string(cnt) + tmp;
                    cnt = 1;
                }
            }
        }
        if (answer > res.length()) {
            ans_str = res;
            answer = res.length();
        }
    }
    return answer;
}
int main() {
    solution("aabbaccc");
    solution("ababcdcdababcdcd");
    solution("abcabcdede");
    solution("abcabcabcabcdededededede");
    solution("xababcdcdababcdcd");
                    


    return 0;
}
