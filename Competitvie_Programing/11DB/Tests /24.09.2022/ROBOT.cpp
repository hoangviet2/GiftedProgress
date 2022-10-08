#include <bits/stdc++.h>
#define between(l,x,r) ((l) <= (x) && (x) <= (r))
#define MP(a,b) make_pair((a),(b))
using namespace std;
using t3 = tuple<int,int,int>;

int rows, cols, K;
vector<string> grid;
string moves = "";
vector<vector<vector<t3>>> nextCell;

inline t3 getNextCell(const int& sR, const int& sC, const int& sDir) {
    // (0, up), (1, right), (2, down), (3, left)
    int curDir = sDir;
    int curR = sR, curC = sC;
    for (int i = 0; i < K; i++) {
        if (grid[curR][curC] == 'E') break;
        int nR = curR, nC = curC, nDir = curDir;
        if (moves[i] == 'F') {
            if (curDir == 0) nR--;
            else if (curDir == 1) nC++;
            else if (curDir == 2) nR++;
            else if (curDir == 3) nC--;

            if (between(0, nR, rows-1) && between(0, nC, cols-1)) {
                if (grid[nR][nC] != '#') curR = nR, curC = nC;
            }
        }
        else {
            if (moves[i] == 'R') nDir = (curDir + 1) % 4;
            else if (moves[i] == 'L') nDir = (curDir + 3) % 4;
            curDir = nDir;
        }
    }

    return t3(curR, curC, curDir);
}

vector<vector<vector<int>>> dp;
vector<vector<vector<int>>> seen;
inline bool endReachable(const int& sR, const int& sC, const int& sDir, const int& time) {
    if (grid[sR][sC] == 'E') return true;
    if (grid[sR][sC] == '#') return false;
    if (dp[sR][sC][sDir] != -1) return dp[sR][sC][sDir];

    vector<t3> path; path.push_back(t3(sR, sC, sDir));
    int curR = sR, curC = sC, curDir = sDir;
    while (true) {
        if (grid[curR][curC] == 'E' || dp[curR][curC][curDir] == 1) {
            dp[curR][curC][curDir] = true;
            break;
        }
        if (seen[curR][curC][curDir] == time) {
            dp[curR][curC][curDir] = false;
            break;
        }
        if (dp[curR][curC][curDir] == 0) {
            dp[curR][curC][curDir] = false;
            break;
        }

        seen[curR][curC][curDir] = time;
        int nR = get<0>(nextCell[curR][curC][curDir]);
        int nC = get<1>(nextCell[curR][curC][curDir]);
        int nDir = get<2>(nextCell[curR][curC][curDir]);

        curR = nR, curC = nC, curDir = nDir;
        path.push_back(t3(curR, curC, curDir));
    }

    int rR = curR, rC = curC, rDir = curDir;
    for (int i = 0; i < path.size(); i++) {
        int thisR = get<0>(path[i]);
        int thisC = get<1>(path[i]);
        int thisDir = get<2>(path[i]);
        dp[thisR][thisC][thisDir] = dp[curR][curC][curDir];
        cout << "";
    }

    return dp[sR][sC][sDir];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("ROBOT.INP", "r", stdin);
    freopen("ROBOT.OUT", "w", stdout);
    cin >> rows >> cols >> K;
    grid = vector<string>(rows);
    for (string& i : grid) cin >> i;
    cin >> moves;
    dp = seen = vector<vector<vector<int>>>(rows+5, vector<vector<int>>(cols+5, vector<int>(7, -1)));
    nextCell = vector<vector<vector<t3>>>(rows+5, vector<vector<t3>>(cols+5, vector<t3>(7)));
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            for (int dir = 0; dir < 4; dir++) {
                nextCell[r][c][dir] = getNextCell(r, c, dir);
            }
        }
    }

    bool reachableFromAll = true;
    int countReachable = 0;
    int time = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == '#') continue;
            reachableFromAll = reachableFromAll && endReachable(r,c,0,time);
            countReachable += endReachable(r,c,0,time);
            time++;
        }
    }

    if (reachableFromAll) cout << "YES";
    else cout << countReachable;
}
