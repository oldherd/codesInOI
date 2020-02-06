#include <cstdio>

using namespace std;

inline int getdi() {
    char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    return ch - '0';
}

const int N = 234567;
int v[N], yl[N];

void build(int f, int k, int t) {
    for(int i = f; i <= t; ++i) {
        v[i] = v[i - k];
    }
}

bool greater(int n) {
    for(int i = 1; i <= n; ++i) {
        if(v[i] > yl[i]) return true;
        if(v[i] < yl[i]) return false;
    }
    return true;
}

void output(int n) {
    printf("%d\n", n);
    for(int i = 1; i <= n; ++i) putchar('0' + v[i]);
    printf("\n");
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++i) {
        yl[i] = getdi();
    }
    for(int i = 1; i <= k; ++i) {
        v[i] = yl[i];
    }
    build(k + 1, k, n);
    if(greater(n)) {
        output(n);
    } else {
        ++v[k];
        for(int i = k; i; --i) {
            if(v[i] > 9) {
                v[i] %= 10; ++v[i-1];
            }else {
                break;
            }
        }
        if(v[0] == 1) {
            ++k; n += 2; v[1] = 1;
            for(int i = 2; i <= k; ++i) v[i] = 0;
        }
        build(k + 1, k, n);
        output(n);
    }
    return 0;
}
