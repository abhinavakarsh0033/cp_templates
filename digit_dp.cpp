#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

// dp[idx][cnt_nonZeroDigit][isMoreThanL][isLessThanR]
lli dp[19][4][2][2];
vector<int> L, R;

// X = x0 x1 ... x18
vector<int> numToArr(lli x) {
    vector<int> v(19,0);
    for(int i=18;i>=0;i--) {
        v[i] = x%10;
        x /= 10;
    }
    return v;
}

lli help(int idx, int cnt, int isMore, int isLess) {
    if(idx == 19) return 1;
    lli &ans = dp[idx][cnt][isMore][isLess];
    if(ans != -1) return ans;

    ans = 0;
    int a = isMore ? 0 : L[idx];
    int b = isLess ? 9 : R[idx];
    for(int i=a;i<=b;i++) {
        if(cnt>=3 && i) continue;
        ans += help(idx+1, cnt+(i!=0), isMore || (i>L[idx]), isLess || (i<R[idx]));
    }
    return ans;
}

void solve() {
    lli l, r;
    cin>>l>>r;
    L = numToArr(l);
    R = numToArr(r);
    memset(dp, -1, sizeof(dp));
    cout<<help(0,0,0,0)<<'\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}