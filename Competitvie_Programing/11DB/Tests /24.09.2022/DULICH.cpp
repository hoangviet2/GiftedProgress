#include <bits/stdc++.h>
using namespace std;
#define MP(a,b) make_pair((a),(b))
using i64 = long long;
// (-curTime, curNode, NOTvisited (cares about cities [0..P-1] only))
using t3 = tuple<i64,int,int>;

inline bool isBitOff(const int& x, const int& p) {
    return (x & (1 << p)) == 0;
}

inline int turnBitOff(const int& x, const int& p) {
    return isBitOff(x,p) ? x : x ^ (1 << p);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("DULICH.INP", "r", stdin);
    freopen("DULICH.OUT", "w", stdout);
    int N, M, P; cin >> N >> M >> P;
    vector<vector<pair<int,i64>>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v; i64 t; cin >> u >> v >> t; u--, v--;
        G[u].push_back(MP(v, t));
    }
    priority_queue<t3> pq; pq.push(t3(0, N-1, (1 << P) - 1));
    vector<vector<char>> seen(N+5, vector<char>((1 << P)+5, false));
    while (!pq.empty()) {
        i64 curTime = -get<0>(pq.top());
        int curNode = get<1>(pq.top());
        int NOTvisited = get<2>(pq.top());
        pq.pop();
        if (seen[curNode][NOTvisited] == true) continue;
        seen[curNode][NOTvisited] = true;

        if (curNode == N-1 && NOTvisited == 0) {
            cout << curTime;
            return 0;
        }

        for (const pair<int,i64>& E : G[curNode]) {
            int neibor = E.first;
            i64 t = E.second;
            int next_NOTvisited = NOTvisited;
            if (0 <= neibor && neibor <= P-1) {
                next_NOTvisited = turnBitOff(NOTvisited, neibor);
            }
            pq.push(t3(-curTime-t, neibor, next_NOTvisited));
        }
    }

    cout << -1;
}
