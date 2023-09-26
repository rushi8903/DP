// Maximum sum of non-adjacent elements
#include <bits/stdc++.h>
using namespace std;

// bottom-up approach 
int maxSum1(vector<int> &arr,int n,vector<int> &val){
    for(int i=3;i<=n;i++){
        val[i]=arr[i]+max(val[i-2],val[i-3]);
    }
    return val[n];
}
int maxSumOfNonAdjacent1(vector<int> &arr,int n){
    if(n==0){
        return arr[0]; 
    }
    if(n==1){
        return max(arr[0],arr[1]);
    }
    if(n==2){
        return max((arr[0]+arr[2]),arr[1]);
    }
    vector<int> val(n,0);
    val[0]=arr[0];
    val[1]=arr[1];
    val[2]=arr[0]+arr[2];
    int ans = maxSum1(arr,n,val);
    return ans;
}
// ++++++++++++++++++++++++++++++++++++++++++++>>>>>>>>>>>>>>>>>>>>>>>>
// space optimized approach 
int maxSumOfNonAdjacent2(vector<int> &arr,int n){
    if(n==0) return arr[0]; 
    int prev1,prev2,current;
    prev2 = 0;
    prev1 = arr[0];

    for(int i=1;i<=n;i++){
        current=max(prev1,arr[i]+prev2);
        prev2 = prev1;
        prev1 = current;
    }
    return current; 
}

//++++++++++++++++++++++++++++++++++++++++++++++++++>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int main(){
    int n = 6;
    vector<int> arr={4,6,2,7,3,1};
    // int ans = maxSumOfNonAdjacent1(arr,n-1);
    int ans = maxSumOfNonAdjacent2(arr,n-1);
    cout<<ans;
    return 0;
}