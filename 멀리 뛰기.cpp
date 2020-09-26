#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<int> d(2001,0);
    d[0] = 0;
    d[1] = 1;
    d[2] = 2;
    for(int i=3; i<=n; i++){
        d[i] = (d[i-1] + d[i-2])%1234567;
    }
    answer = d[n]%1234567;
    return answer;
}
