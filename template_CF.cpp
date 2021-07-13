#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long int
#define lll long long
#define MOD (int)1e9 + 7

void getArr(lll n, vector<lll> &arr)
{
    lll x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr.pb(x);
    }
}

void solve(lll n, vector<lll> &arr)
{
}

int main()
{
    lll t, n;
    cin >> t;
    vector<lll> a;
    while (t--)
    {
        cin >> n;
        getArr(n, a);
        solve(n, a);
        a.clear();
    }
    return 0;
}