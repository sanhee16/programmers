#include <string>
#include <vector>
#include <iostream>

using namespace std;

string final_str = "";

int solution(string s) {
    int answer = 2000;
    if (s.length() == 1) {
        answer = 1;
        return answer;
    }
    for (int i = 1; i < s.length()/2 + 1; i++) {
        int cnt=1;
        int left = s.length();
        string a="", b="", str="";
        int idx = 0;
        while (true) {
            a = s.substr(idx, i);
            b = s.substr(idx+i, i);
            //cout << i << " : "<< a << " " << b << endl;
            if (a.compare(b) == 0) {
                cnt++;
            }
            else {
                if (cnt == 1) {
                    
                }
                else {
                    str += to_string(cnt);
                    cnt = 1;
                }
                str += a;
            }
            
            idx += i;
            left -= i;
            if (idx + i >= s.length() && left < i) {
                if (cnt == 1) {

                }
                else {
                    str += to_string(cnt);
                    cnt = 1;
                    str += a;
                }
                str += s.substr(idx);
                break;
            }
        }
        int t = str.length();
        //cout << i << " : " << str << endl;
        if (answer > t) {
            answer = t;
            final_str = str;
        }
    }

    return answer;
}

int main() {

    int ans = solution("a");
    //ans = solution("acacdfdfdfdfaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    //ans = solution("acacdfdfdfdf aaaaaaaaaaaa aaaaaaaaaaaa aaaaaaaaaaaa aaaaaaaaaaaa");
    cout << ans << endl;
    //cout << ans << "," << final_str << endl;
    return 0;
}
