#include <bits/stdc++.h>
using namespace std;

// tìm bit cao nhất (most significant bit)
int msb(int a) {
    if(a == 0)
        return 0;
    
    // giảm a cho tới khi chỉ còn lại bit cao nhất
    while(a - (a&-a))
        a -= a&-a;
    
    // tìm vị trí của bit cao nhất
    int i = 0;
    while((a & (1<<i)) == 0)
        i++;
    return i+1;
}

int Multiplication(int x, int y) {
    int n = max(msb(x), msb(y));        // tìm bit cao nhất
    if (x == 0 || y == 0)
        return 0;
    if (n <= 4)                         // nếu bit cao nhất <= 4 thì dùng built-in operator
        return x*y;
    
    n += n&1;                           // nếu n lẻ thì cho n += 1, nếu không thì n += 0
    int m = n/2;

    int xl = x >> m;
    int xr = x & ((1<<m) - 1);
    int yl = y >> m;
    int yr = y & ((1<<m) - 1);

    int ll = Multiplication(xl, yl);    // tính xl*yl
    int rr = Multiplication(xr, yr);    // tính xr*yr
    int lr = Multiplication(xl + xr, yl + yr) - (ll + rr);  // tính xl*yr + xr*yl

    int ans = (ll << n) + (lr << m) + rr;
    return ans;
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << Multiplication(a, b);
}