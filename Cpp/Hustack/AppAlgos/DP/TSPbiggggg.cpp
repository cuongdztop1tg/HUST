#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
int n, c[1001][1001];
int mem[1001][1 << 20]; // Memoization array for minimum distance
int path[1001][1 << 20]; // Array to store paths for reconstruction

// Remove city i from the set S
unsigned int removeItem(unsigned int S, int i) {
    return S & ~(1 << i); // Clear bit i
}

// Add city i to the set S
unsigned int addItem(unsigned int S, int i) {
    return S | (1 << i); // Set bit i
}

// Check if city i is in the set S
bool containItem(unsigned int S, int i) {
    return S & (1 << i);
}

// Recursive function for TSP using DP with bitmask
int TSP(int i, unsigned int S) {
    // Base case: If all cities have been visited, return cost to return to the start city
    if (S == 0) return c[i][0];

    // If this state has been computed, return the stored result
    if (mem[i][S] != -1) return mem[i][S];

    int minDis = INF;
    int minJ = -1;

    // Iterate over all possible next cities
    for (int j = 1; j < n; j++) {
        if (containItem(S, j)) {
            // Calculate the distance if we visit city j next
            int dis = c[i][j] + TSP(j, removeItem(S, j));
            if (dis < minDis) {
                minDis = dis;
                minJ = j;
            }
        }
    }

    // Store the result in memoization and path arrays
    mem[i][S] = minDis;
    path[i][S] = minJ;
    return minDis;
}

// Trace function to reconstruct the path
void trace(int i, unsigned int S) {
    cout << i + 1 << " "; // Convert to 1-based index for display
    if (S == 0) return;
    int j = path[i][S];
    trace(j, removeItem(S, j));
}

int main() {
    // Read number of cities
    cin >> n;

    // Read cost matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }

    // Initialize the memoization array with -1 to signify uncomputed states
    memset(mem, -1, sizeof(mem));

    // Start with all cities in the set, excluding the starting city (0)
    unsigned int S = (1 << n) - 1;
    S = removeItem(S, 0); // Remove city 0 from the initial set

    // Calculate the minimum cost to visit all cities and return to the start
    int result = TSP(0, S);

    cout << "Minimum cost: " << result << endl;
    cout << "Path: ";
    trace(0, S);
    cout << "1" << endl; // Return to the start city

    return 0;
}
