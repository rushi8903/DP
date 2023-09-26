// 
#include <bits/stdc++.h>

using namespace std;
int giveAns(vector<int> &arr,int n,int k,vector<int> &val){
    if(n==0 || n==1){
        return arr[n];
    }
    for(int i=2;i<n;i++){
    int val = INT_MAX;

    }
}

int frogJumpK(vector<int> &arr,int n,int k){
    vector<int> val(k,0);
    int giveAns(arr,n,k,val);
    return n;
}

int main(){
    int n = 6;
    int k = 3;
    vector <int> arr= {30,10,60,10,60,50};
    int ans = frogJumpK(arr,n-1,k);
    return 0;
}
