#include <string>
#include <vector>
#include <algorithm>
#define MUL 65536
using namespace std;

int solution(string str1, string str2) {
    int answer;
    vector<string>v1;
    vector<string>v2;
    double temp;
    string tmp;
    for(int i=0;i<str1.size()-1;i++){
        if(isalpha(str1[i])&&isalpha(str1[i+1])){
            tmp="";
            tmp=tmp+str1[i]+str1[i+1];
            transform(tmp.begin(),tmp.end(),tmp.begin(),::tolower);
            v1.push_back(tmp);
        }
    }
    for(int j=0;j<str2.size()-1;j++){
        if(isalpha(str2[j])&&isalpha(str2[j+1])){
            tmp="";
            tmp=tmp+str2[j]+str2[j+1];
            transform(tmp.begin(),tmp.end(),tmp.begin(),::tolower);
            v2.push_back(tmp);
        }
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    vector<string>i(v1.size()+v2.size());
    vector<string>u(v1.size()+v2.size());
    auto iter1=set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),i.begin());
    i.erase(iter1,i.end());
    auto iter2=set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),u.begin());
    u.erase(iter2,u.end());
    if(i.size()==0)
        answer=MUL;
    else{
        temp=((double)u.size()/(double)i.size())*MUL;
        answer=temp;
        
    }
    return answer;
}
