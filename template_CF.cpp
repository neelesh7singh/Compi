#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long int
#define lll long long
#define MOD (int)1e9 + 7

//-------------------dsu---------------------
//nodes.resize(1001, -1);
//rank.resize(1001,0);

//  find
int find(lll a, vector<lll> &nodes, vector<lll> &rank)
{
    if (nodes[a] == -1)
        return a;
    else
        return nodes[a] = find(nodes[a], nodes, rank);
}
//  union
void uni(lll a, int b, vector<lll> &nodes, vector<lll> &rank)
{
    int fa = find(a, nodes, rank), fb = find(b, nodes, rank);
    if (fa == fb)
        return;
    if (rank[fa] > rank[fb])
        nodes[fb] = fa;
    else if (rank[fa] < rank[fb])
        nodes[fa] = fb;
    else
    {
        nodes[fb] = fa;
        rank[fa]++;
    }
}

//--------------Combination--------------
lll C(int n, int r)
{
    if (r > n - r)
        r = n - r; // because C(n, r) == C(n, n - r)
    lll ans = 1;
    int i;

    for (i = 1; i <= r; i++)
    {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

void getArr(lll n, vector<lll> &arr)
{
    lll x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr.pb(x);
    }
}

void getArr2(lll n, lll l, vector<vector<lll>> &arr)
{
    vector<lll> temp(l);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < l; j++)
            cin >> temp[j];
        arr.pb(temp);
    }
}

void solve(int n, vector<vector<lll>> &arr)
{
    return;
}

int main()
{
    lll n, t, n1, n2;
    cin >> t;
    vector<vector<lll>> arr;
    for (int tc = 1; tc <= t; tc++)
    {
        cin >> n >> n1 >> n2;
        getArr2(n1, n2, arr);
        solve(n, arr);
    }

    return 0;
}
