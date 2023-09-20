#include <iostream>
#include <vector>
using namespace std;

int diff(int a,int b){
    return ((a-b)>0)?a-b:b-a;
}

// bottom-up approach 
int countValue1(vector<int> &arr,int n,vector<int> &val){
    if(n==0 || n==1){
        return val[n];
    }
    for(int i=2;i<=n;i++){
        if(val[i]==0){
            int val1=val[i-2]+diff(arr[i-2],arr[i]);
            int val2=val[i-1]+diff(arr[i-1],arr[i]);
            val[i]=min(val1,val2);
        }
    }
    return val[n];
}

// top-down approach
int countValue2(vector<int> &arr,int n,vector<int> &val){
    if(n==0 || n==1){
        return val[n];
    }
    if(val[n]!=0){
        return val[n];
    }
    int val1 = diff(arr[n],arr[n-1])+countValue2(arr,n-1,val);
    int val2 = diff(arr[n],arr[n-2])+countValue2(arr,n-2,val);
    val[n]=min(val1,val2);
    return val[n];
}

//space optimization 
int countValue3(vector<int> &arr,int n){
    if(n==0 || n==1){
        return diff(arr[0],arr[n]);
    }
    int prev1=diff(arr[0],arr[1]);
    int prev2=0,ans=0;
    for(int i=2;i<=n;i++){
        int val1=prev2+diff(arr[i-2],arr[i]);
        int val2=prev1+diff(arr[i-1],arr[i]);
        ans=min(val1,val2);
        prev2=prev1;
        prev1=ans;
    }
    return ans;
}

int frogJump(vector<int> &arr, int n ){
    // vector<int> val(n,0);
    // val[1]=diff(arr[0],arr[1]);
    // int ans = countValue1(arr,n-1,val);
    // int ans = countValue2(arr,n-1,val);
    int ans = countValue3(arr,n-1);
    return ans;
}

int main(){
    int n = 6;
    vector<int> arr={30,10,60,10,60,50};
    int ans = frogJump(arr,n);
    cout<<ans;
    return 0;
}