#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<cstdio>
#include<map>
#include<cassert>
using namespace std;
 
typedef long long Int;
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define sz(s) (int)(s).size()
#define pb push_back
#define mp make_pair
const int inf = 1000000000;
const int MOD = 1000000007;
 
int a[1111];
 
int main()
{
	//freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	int tests;
	cin>>tests;
	while(tests--){
		int n;cin>>n;
		FOR(i,1,n)cin>>a[i];
		sort(a+1,a+n+1);
		int ans=0;
		FOR(i,1,n)ans+=a[i]-a[1];
		cout<<ans<<endl;
	}
} 
