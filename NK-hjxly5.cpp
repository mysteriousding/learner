#include<iostream>
#include<queue>
using namespace std;
const int mod_ = 1e9 + 7;
struct H {
    int sh, po;
    bool operator>(const H& k)const {
        if (po != k.po)return po > k.po;
        else return sh > k.sh;
    }
    H operator+(const H& k) {
        return { sh + k.sh,po + k.po };
    }
}h;
int main()
{
    int n, c, w;
    long long m = -1, num = 0;
    priority_queue<H, vector<H>, greater<H>>q;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c >> w;
        m += c;
        for (int j = 0; j < c; j++)
            q.push({ w % mod_,w / mod_ });
    }
    for (long long i = 0; i < m; i++)
    {
        h = q.top();
        q.pop();
        h = h + q.top();
        q.pop();
        q.push(h);
        num += h.sh, num %= mod_;
    }
    cout << num << endl;

    return 0;
}