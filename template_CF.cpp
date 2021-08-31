#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long int
#define lll long long
#define MOD (int)1e9+7

//-------------------dsu---------------------
//nodes.resize(1001, -1);
//rank.resize(1001,0);

//  find
int find(lll a, vector<lll> &nodes, vector<lll> &rank)
{
    if(nodes[a] == -1) return a;
    else return nodes[a] = find(nodes[a], nodes, rank);
}
//  union
void uni(lll a, int b, vector<lll> &nodes, vector<lll> &rank)
{
    int fa = find(a, nodes, rank), fb = find(b, nodes, rank);
    if(fa == fb) return;
    if(rank[fa] > rank[fb])
        nodes[fb] = fa;
    else if(rank[fa] < rank[fb])
        nodes[fa] = fb;
    else
    {
        nodes[fb] = fa;
        rank[fa]++;
    }
}

//--------------Combination--------------
lll C(int n, int r) {
    if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
    lll ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

void getArr(lll n, vector<lll>& arr)
{
    lll x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        arr.pb(x);
    }
}

void getArr2(lll n, lll l, vector<vector<lll>>& arr)
{
    vector<lll> temp(l);
    for (int i = 0; i < n; i++) {
        for(int j=0; j<l; j++) cin >> temp[j];
        arr.pb(temp);
    }
}

vector<lll> conv(vector<lll> &arr)
{
    int maxi=INT_MIN, idx=-1;
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] > maxi)
        {
            maxi = arr[i];
            idx = i;
        }
    }

    return {maxi, idx, (lll)arr.size()-idx-1};
}

void solve(string &s, int tc)
{
    lll vowC, mv, mc, consC;
    vowC = mv = mc = consC = 0;

    vector<lll> count(26,0);
    for(int i=0; i<s.length(); i++)
    {
        count[s[i]-'A']++;
        if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
        {
            vowC++;
            mv = max(mv, count[s[i]-'A']);
        }
        else
        {
            consC++;
            mc = max(mc, count[s[i]-'A']);
        }
    }

    lll ans1, ans2;
    ans1 = consC + (vowC-mv)*2;
    ans2 = vowC + (consC-mc)*2;

    cout << "Case #" << tc << ": " << min(ans1, ans2) << endl;
}

int main()
{
    lll n, t, n1, n2;
    cin >> t;
    string s;
    for(int tc=1; tc<=t; tc++)
    {
        cin >> s;
        solve(s, tc);
    }

    return 0;
}
