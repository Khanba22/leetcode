#include <bits/stdc++.h>
using namespace std;
#define mod
1000000007 #define endl "\n" #define test ll t;
cin >> t;
while (t--)
    typedef long long int ll;
int main()
{
    test
    {
        ll n, q;
        cin >> n >> q;
        vector<ll> x(n), r(n);
        for (auto &it : x)
            cin >> it;
        for (auto &it : r)
            cin >> it;
        vector<ll> ans(4 * n + 5, 0);
        for (int i = 0; i < n; i++)
        {
            ll left = x[i] - r[i] + 2 * n;
            ll right = x[i] + r[i] + 2 * n + 1;
            if (x[i] > 0)
            {
                left = max(left, 2 * n);
            }
            else
            {
                right = min(right, 2 * n);
            }
            ans[left]++;
            ans[right]--;
        }
        for (int i = 1; i < 4 * n + 5; i++)
        {
            ans[i] += ans[i - 1];
        }
        while (q--)
        {
            int inp;
            cin >> inp;
            inp += 2 * n;
            cout << ans[inp] << endl;
        }
    }
    return 0;
}