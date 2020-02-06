#include <cstdio>

using namespace std;

struct node{
    int a, b, c;
    node(int A, int B, int C) : a(A), b(B), c(C) {}
    void swap(int &a, int &b) {
        int t = a; a = b; b = t;	
    }
    void arr() {
        if(a > b) swap(a, b); if(a > c) swap(a, c); if(b > c) swap(b, c);	
    }
    bool operator == (const node &o) {
        return a == o.a && b == o.b && c == o.c;	
    }
};

int step;
inline node find_anc(node cur) {
    int a = cur.a, b = cur.b, c = cur.c; step = 0;
    int d1 = b - a, d2 = c - b;
    if(d2 == d1) return node(a, b, c);
    while(d1 != d2) {
        if(d1 < d2) {
            int stp = d2 / d1;
            if(!(d2 % d1)) stp--;
            a += stp * d1; b += stp * d1;
            step += stp;
            d2 = c - b;
        } else {
            int stp = d1 / d2;
            if(!(d1 % d2)) stp--;
            c -= stp * d2; b -= stp * d2;
            step += stp;
            d1 = b - a;
        }
    }
    return node(a, b, c);
}

inline node up(node cur, int step) {
    int a = cur.a, b = cur.b, c = cur.c;
    int d1 = b - a, d2 = c - b;
    while(step > 0) {
        if(d2 > d1) {
            int stp = d2 / d1;
            if(!(d2 % d1)) stp--;
            step -= stp;
            if(step < 0) stp = step + stp;
            a += stp * d1; b += stp * d1;
            d2 = c - b;
        }
        else if(d1 > d2) {
            int stp = d1 / d2;
            if(!(d1 % d2)) stp--;
            step -= stp;
            if(step < 0) stp = step + stp;
            c -= d2 * stp; b -= d2 * stp;
            d1 = b - a;
        }
    }
    return node(a, b, c);
}

int main() {
    int t1, t2, t3, t4, t5, t6;
    scanf("%d %d %d %d %d %d", &t1, &t2, &t3, &t4, &t5, &t6);
    node a(t1, t2, t3), b(t4, t5, t6);
    a.arr(); b.arr();
    node ana = find_anc(a);
    int da = step;
    node anb = find_anc(b);
    int db = step;
    if(ana == anb) printf("YES\n");
    else {
        printf("NO\n");
        return 0;	
    }
    int tot;
    if(da < db)
        b = up(b, db - da), tot = db - da;
    else if(da > db)
        a = up(a, da - db), tot = da - db, da = db;
    int l = 0, r = da;
    while(l < r) {
        int mid = (l + r) >> 1;
        node t1 = up(a, mid), t2 = up(b, mid);
        if(up(a, mid) == up(b, mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", tot + l * 2);
    return 0;
} 
