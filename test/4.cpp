#include <bits/stdc++.h>
#define MX (int)1e6
using namespace std;

typedef pair<int, int> ii;

int partition(ii* arr, int l, int r) {
    int pivot = rand()%(r-l+1) + l;
    swap(arr[pivot], arr[r]);
    int j = l-1;
    for(int i = l; i < r; i++) {
        if(arr[i].first > arr[r].first) {
            swap(arr[++j], arr[i]);
        }
    }
    swap(arr[++j], arr[r]);
    return j;
}

void subseqK(ii* arr, int n, int k) {
    int* tmp = new int[n];
    for(int i = 0; i < n; i++)
        tmp[i] = arr[i].first;
    k--;
    int l = 0;
    int r = n-1;
    int pi = partition(arr, l, r);
    bool* take = new bool[n];
    memset(take, false, n);
    
    while(true) {
        if(pi == k) {
            for(int i = 0; i <= k; i++)
                take[arr[i].second] = true;
            break;
        }
        else if(pi < k)
            l = pi + 1;
        else
            r = pi - 1;
        
        pi = partition(arr, l, r);
    }

    for(int i = 0; i < n; i++) {
        if(take[i])
            cout << tmp[i] << " ";
    }
}

int main() {
    fstream fin("input.txt", ios::in);
    int n, k;
    fin >> n >> k;
    ii* arr = new ii[n];
    for(int i = 0; i < n; i++) {
        fin >> arr[i].first;
        arr[i].second = i;
    }
    subseqK(arr, n, k);
}