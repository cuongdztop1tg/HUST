#include <bits/stdc++.h>
using namespace std;

// Constants
const int MAXN = 100; // maximum number of nodes
const int INF = 1e9;  // infinity

// Variables
int n, K, Q; // number of destinations, maximum routes, capacity
int f = 0, fStar = INF; // current and best cost
int Cmin = INF; // minimum cost
int d[MAXN]; // demand array
int c[MAXN][MAXN]; // cost array
int y[MAXN], x[MAXN]; // y[k] is the route, x[s] is the assignment
bool visited[MAXN]; // visited array
int load[MAXN]; // load array
int segments = 0; // number of segments
int nbR; // number of routes

// Function to check if we can assign v to x[s]
bool checkX(int v, int k) {
    if (v > 0 && visited[v]) return false;
    if (load[k] + d[v] > Q) return false;
    return true;
}

// Function to check if we can assign v to y[k]
bool checkY(int v, int k) {
    if (v == 0) return true;
    if (load[k] + d[v] > Q) return false;
    if (visited[v]) return false;
    return true;
}

// Function TRY_X(s, k) to try assigning values to x[s]
void TRY_X(int s, int k) {
    if (s == 0) {
        if (k < K) {
            TRY_X(y[k + 1], k + 1);
        }
        return;
    }

    for (int v = 0; v <= n; v++) {
        if (checkX(v, k)) {
            x[s] = v;
            visited[v] = true;
            f = f + c[s][v];
            load[k] += d[v];
            segments++;

            if (v > 0) {
                if (f + (n + nbR - segments) * Cmin < fStar) {
                    TRY_X(v, k);
                }
            } else {
                if (k == K) {
                    if (segments == n + nbR) {
                        fStar = min(fStar, f); // update the best cost
                    }
                } else {
                    if (f + (n + nbR - segments) * Cmin < fStar) {
                        TRY_X(y[k + 1], k + 1);
                    }
                }
            }

            visited[v] = false;
            f = f - c[s][v];
            load[k] -= d[v];
            segments--;
        }
    }
}

// Function TRY_Y(k) to try assigning values to y[k]
void TRY_Y(int k) {
    int s = 0;
    if (y[k - 1] > 0) s = y[k - 1] + 1;
    for (int v = s; v <= n; v++) {
        if (checkY(v, k)) {
            y[k] = v;
            if (v > 0) segments++;
            visited[v] = true;
            f += c[0][v];
            load[k] += d[v];
            
            if (k < K) {
                TRY_Y(k + 1);
            } else {
                nbR = segments;
                TRY_X(y[1], 1);
            }

            load[k] -= d[v];
            visited[v] = false;
            f -= c[0][v];
            if (v > 0) segments--;
        }
    }
}

// Solve function to initialize and start the search
void solve() {
    f = 0;
    fStar = INF;
    y[0] = 0;
    for (int i = 1; i <= n; i++) visited[i] = false;
    TRY_Y(1);
    cout << fStar << endl;
}

// Main function
int main() {
    // Input number of destinations, maximum routes, and capacity
    cin >> n >> K >> Q;

    // Input demands for each destination
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }

    // Input cost matrix
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> c[i][j];
            if (i != j) Cmin = min(Cmin, c[i][j]);
        }
    }

    // Solve the problem
    solve();

    return 0;
}
