#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

lli rnd(lli a, lli b) {
    return a + rand() % (b-a+1);
}

void solve() {
    int n = rnd(1,10);
    cout<<n<<'\n';
    for(int i=0;i<n;i++) cout << rnd(1,100) << ' ';
    cout<<'\n';
    return;
}

int main(int argc, char **argv) {
    int seed = argc>1 ? atoi(argv[1]) : rand();
    srand(seed);
    int t = 1;
    t = rnd(1,10); cout<<t<<'\n';
    while(t--) solve();
    return 0;
}