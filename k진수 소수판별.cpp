#include<iostream>
#include<algorithm>
#include<cmath>
void change(int n,int k){
    while(n>0){
        num+=to_string(n%k);
        n/=k;
    }
    reverse(num.begin(),num.end());
}
bool check(long long n){
    if(n==0||n==1)return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
