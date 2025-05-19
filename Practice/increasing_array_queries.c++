#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct obj
{
    ll l, r, i;
    bool operator<(const obj &o) const
    { // 定義查詢排序的規則
        return l > o.l;
    }
};
struct BIT
{
#define lowbit(i) (i & -i)
    int len;
    vector<ll> arr;
    BIT(ll n) : len(n), arr(n, 0) {}
    void update(int idx, ll val)
    {
        for (int i = idx; i < len; i += lowbit(i))
            arr[i] += val;
    }
    ll query(int idx)
    {
        ll result = 0;
        for (int i = idx; i > 0; i -= lowbit(i))
            result += arr[i];
        return result;
    }
};
struct RSQ
{
    BIT a, b;
    RSQ(ll n) : a(n + 1), b(n + 1) {}
    void add(ll i, ll v)
    {
        a.update(i, v);
        b.update(i, v * (i - 1));
    }
    ll get(ll i)
    {
        return a.query(i) * i - b.query(i);
    }
    void add(ll l, ll r, ll v)
    {
        add(l, v);
        add(r + 1, -v);
    }
    ll get(ll l, ll r)
    {
        return get(r) - get(l - 1);
    }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll &i : a)
        cin >> i;
    vector<obj> v(q);
    for (ll i = 0; i < q; i++)
        cin >> v[i].l >> v[i].r, v[i].i = i;
    sort(v.begin(), v.end());            // 排序查詢
    vector<pair<ll, ll>> d;              // 單調stack，因為std::stack很爛所以用vector
    d.push_back(make_pair(1e18, n + 1)); // 在結尾插入一個超大的值方便處理邊界
    ll cur = n;
    vector<ll> ans(q);
    RSQ t(n);
    for (ll i = 0; i < n; i++)
    {
        t.add(i + 1, i + 1, -a[i]); // 把"扣掉初始值"放在一起方便查詢
    }
    for (obj o : v)
    {
        while (cur >= o.l)
        {
            cur--;
            ll h = a[cur];
            t.add(cur + 1, cur + 1, h);
            while (h >= d.back().first)
            {
                ll L = d.back().second;
                ll D = h - d.back().first;
                d.pop_back();
                t.add(L, d.back().second - 1, D);
            }
            d.push_back(make_pair(h, cur + 1));
        }
        ans[o.i] = t.get(o.l, o.r);
    }
    for (ll i : ans)
        cout << i << "\n";
}
