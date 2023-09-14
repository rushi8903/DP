#include <iostream>
#include <vector>
using namespace std;

// basic recursive way to find fibonacci number 
// time complixity O(n^2)
// space complixity O(1)
// top-down approch 
int fibonacci01(int n){
    if(n==0||n==1){
    return n;
    }

    return fibonacci01(n-1)+fibonacci01(n-2);
}

// memorization technique 
// time complixity O(n)
// space complixity O(n) also consumming the space in function stack
// top-down approch 
int fibo2(int n,vector<int> &arr){
    if(n==0||n==1){
        return n;
    }

    if(arr[n]!=0){
        return arr[n];
    }

    arr[n]=fibo2(n-1,arr)+fibo2(n-2,arr);
    return arr[n];
}

int fibonacci02(int n){
    vector<int> arr(n+1,0);
    int ans=fibo2(n,arr);
    return ans;
}

// tabulation technique
// time conplixity O(n)
// space complixity O(n)
// bottom-up approch 
int fibo3(int n,vector<int> arr){
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<n+1;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    return arr[n];
}
int fibonacci03(int n){
    vector<int> arr(n+1,0);
    int ans=fibo3(n,arr);
    return ans;
}

// best technique among all
// time complixity O(n)
// space complixity O(1)
int fibonacci04(int n){
    if(n==0||n==1){
        return n;
    }

    int prev2=0,prev1=1,current;

    for(int i=2;i<=n;i++){
        current=prev2+prev1;
        prev2=prev1;
        prev1=current;
    }
    return current;
}

int main(){
    int n = 20;
    // int ans = fibonacci01(n);
    // int ans = fibonacci02(n);
    // int ans = fibonacci03(n);
    int ans = fibonacci04(n);
    cout<<ans;
    return 0;
}