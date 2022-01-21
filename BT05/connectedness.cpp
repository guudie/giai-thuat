#include <bits/stdc++.h>
using namespace std;

bool connected(bool** const& g, int n) {
    if(n==1)
        return true;
    else if(!connected(g, n-1))
        return false;
    else {
        for(int i = 0; i < n-1; i++)
            if(g[n-1][i])
                return true;
        return false;
    }
}

int main() {
    fstream fin("conn.txt", ios::in);
    int n;
    fin >> n;
    bool** g = new bool*[n];
    for(int i = 0; i < n; i++) {
        g[i] = new bool[n];
        for(int j = 0; j < n; j++)
            fin >> g[i][j];
    }

    cout << connected(g, n);
}