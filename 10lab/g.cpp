#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> g[505];
int used[505];
stack<int> st;
vector<int> cyclePath;

bool dfs(int v, int a, int b) {
    used[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (v == a && b == to) continue;
        if (!used[to]) {
            if (dfs(to, a, b)) return true;
        } else if (used[to] == 1) {
            return true;
        }
    }
    used[v] = 2;
    return false;
}

bool dfs2(int v) {
    used[v] = 1;
    st.push(v);
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (!used[to]) {
            if (dfs2(to)) return true;
        } else if (used[to] == 1) {
            while (st.top() != to) {
                cyclePath.push_back(st.top());
                st.pop();
            }
            cyclePath.push_back(to);
            cyclePath.push_back(v);
            reverse(cyclePath.begin(), cyclePath.end());
            return true;
        }
    }
    used[v] = 2;
    if (!st.empty()) st.pop();
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }

    bool cycle = false;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            cycle = dfs2(i);
            if (cycle) break;
        }
    }
    
    if (!cycle) {
        cout << "YES" << endl;
        return 0;
    }

    for (int i = 0; i < cyclePath.size() - 1; i++) {
        int u = cyclePath[i];
        int v = cyclePath[i + 1];
        for (int j = 1; j <= n; j++) {
            used[j] = 0;
        }
        cycle = 0;
        for (int j = 1; j <= n; j++) {
            if (!used[j]) {
                cycle |= dfs(j, u, v);
            }
        }
        if (!cycle) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
}