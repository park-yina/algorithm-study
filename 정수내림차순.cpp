#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string temp=to_string(n);
    sort(temp.rbegin(),temp.rend());
    return stoll(temp);
}
