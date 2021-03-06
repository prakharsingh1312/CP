// let there be a subset X = {}
// sum of all elements of the subset X = S1
// let the sum of the entire array = R
// the question is to find the count of such subsets where |S1 - (R-S1)| = C, where C is a given constant
// therefore R-2*S1 = C (assuming S1 to be the smaller subset of the partition)
// S1 = (R-C)/2
// therefore primary check = (R-C)%2 == 0
// Using the concept of subset sum
#include "bits/stdc++.h"
using namespace std;
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define MP make_pair
#define PB push_back
#define endl "\n"
#define yes cout<<"yes"<<endl;
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define UM unordered_map
#define CHECK(a) cout<<"a :"<<a<<endl
#define mem(a,v) memset(a,v,sizeof(a))
#define S second
#define F first
typedef vector<unsigned long long int> VI;
typedef vector<string> VS;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;

int dp[100][100]={0};
int countSubsets(int arr[], int c, int n){
  int r = 0;
  FOR(i,0,n,1)  r+=arr[i];
  if((r-c)%2!=0)  return 0;
  else{
    int x = (r-c)/2;
    FOR(i,0,x+1,1)  dp[0][i]=0;
    FOR(i,0,n+1,1)  dp[i][0]=1;
    FOR(i,1,n+1,1){
      FOR(j,1,x+1,1){
        if(arr[i-1]<=j)
          dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
        else
          dp[i][j]=dp[i-1][j];
      }
    }
    return dp[n][x];
  }
}

int main()
{
  int arr[]={1,1,3,5,2,4};
  int n = 6;
  int c = 2;
  cout<<"ans :"<<countSubsets(arr,c,n)<<endl;
  return 0;
}
