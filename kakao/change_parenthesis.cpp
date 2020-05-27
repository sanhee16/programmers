#include <string>
#include <vector>
#include <iostream>

using namespace std;
string reverse_str(string rev_s) {

    for (int i = 0; i < rev_s.length(); i++) {
        string temp = rev_s.substr(i, 1);
        if (temp.compare("(") == 0) {
            rev_s.replace(i, 1, ")");
        }
        else {
            rev_s.replace(i, 1, "(");
        }
    }
    return rev_s;
    
}
int right(string s) {
    int cnt1 = 0;
    int r = 1;
    for (int i = 0; i < s.length(); i++) {
        string temp = s.substr(i, 1);
        if (temp.compare("(") == 0) {
            cnt1++;
        }
        else {
            cnt1--;
            if (cnt1 < 0) {
                r = 0;
                break;
            }
        }
    }
    return r;
    // r==0 : no right
    // r==1 : right
}
string solution(string p) {
    string answer = "";
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;

    string u = "", v = "";

    int r = right(p);
    if (r == 1) {
        answer = p;
        return answer;
    }


    // case 1
    if (p == "") {
        return "";
    }

    // case 2
    int first = 1, second = 1;
    cout << "str : " << p << endl;
    for (int i = 0; i < p.length(); i++) {
        string temp = p.substr(i, 1);
        if (temp.compare("(") == 0) {
            cnt1++;
            cnt2++;
            if (cnt3 > 0 && second == 1 && cnt1 == 0) {
                u = p.substr(0,cnt2+cnt3);
                v = p.substr(cnt2+cnt3);
                cout << "u : " << u << endl << "v : " << v << endl;
                second = 0;
                first = 0;
            }
        }
        else {
            cnt1--;
            cnt3++;
            if (cnt2 > 0 && first == 1 && cnt1 == 0) {
                u = p.substr(0, cnt2 + cnt3);
                v = p.substr(cnt2 + cnt3);
                cout << "u : " << u << endl << "v : " << v << endl;
                first = 0;
                second = 0;
            }
        }
    }


    int res = right(u);
    if (res == 1) {
        // u is right
        // case 3
        string tmp = solution(v);
        u += tmp;
        answer = u;
        return answer;
    }
    else {
        cout << "case 4" << endl;
        // u is not right
        // case 4
        string tmp = "";
        tmp += "(";
        
        string res_v = solution(v);
        tmp += res_v;

        tmp += ")";
        cout << "tmp : " << tmp << endl;
        cout << "u : " << u << endl;
        u = u.substr(1, u.length() - 2);
        cout << "u : " << u << endl;

        u = reverse_str(u);
        cout << "u reverse : " << u << endl;

        tmp += u;
        cout << "tmp : " << tmp << endl;
        answer = tmp;
        return answer;

    }
    return answer;
}

int main() {
    string ans = "";
    
    //ans = solution("(()))(");
    //solution("(()())()"); //"(()())()"
     solution(")("); // "()"
     ans = solution("()))((()"); // 	"()(())()"

    cout << "answer : " << ans << endl;
    return 0;
}
