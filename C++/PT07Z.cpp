// Solution of PT07Z - Longest path in a tree from SPOJ

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"
 
vector<int> ar[100001];
int vis[100001],maxd,mn;
 
void dfs(int i,int d){
	vis[i]=1;
	if(d > maxd)maxd=d , mn=i;
	for(int x : ar[i]){
		if(vis[x] == 0)
			dfs(x,d+1);
	}
}
 
void solve() {
	int n,a,b,i;
	cin >> n ;
	for(i=1;i<n;i++){
		cin >> a >> b;
		ar[a].pb(b);
		ar[b].pb(a);
	}
	maxd=-1;
	dfs(1,0);
	for(i=0;i<n;i++) vis[i]=0;
	maxd=-1;
	dfs(mn,0);

	cout << maxd << endl;
}
 
int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	for(int i=1;i<=t;i++){	solve();}
	return 0;
} 
