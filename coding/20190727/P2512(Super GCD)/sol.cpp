#include <cstdio>
#include <cstring>

using namespace std;

const char ct[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', };
const int size = 10010; 

struct bignum{
	int data[size], end;
	bignum() { memset(data, 0, sizeof(data)); end = -1; }
	void reverse() { int t; for(int i = 0; i <= end-i; i++) { t = data[i]; data[i] = data[end-i]; data[end-i] = t; } }
	void input() {
		char ch = getchar(); end = -1;
		while(ch < '0' || ch > '9') ch = getchar();
		while(ch >= '0' && ch <= '9') { data[++end] = ch&15; ch = getchar(); }
		this -> reverse();
	}
	void output() { for(int i = end; i > -1; --i) putchar(ct[data[i]]);	}
	bignum operator = (const bignum &o) { end = o.end; for(int i = 0; i <= end; i++) data[i] = o.data[i]; return *this; }
	bool operator == (const bignum &o) {
		if(end != o.end) return false;
		for(int i = end; i > -1; --i) if(data[i] != o.data[i]) return false;
		return true;	
	}
	bool operator != (const bignum &o) { return !(*this == o); }
	bool operator < (const bignum &o) {
		if(end != o.end) return end < o.end;
		for(int i = end; i > -1; --i) if(data[i] != o.data[i]) return data[i] < o.data[i];
		return false;
	}
	bignum operator - (const bignum &o) const {
		bignum res;
		res.end = end;
		for(int i = 0; i <= o.end; i++) {
			res.data[i] += data[i] - o.data[i];
			if(res.data[i] < 0) { res.data[i] += 10; --res.data[i+1]; }
		}
		for(int i = o.end+1; i <= end; ++i) {
			res.data[i] += data[i];
			if(res.data[i] < 0) { res.data[i] += 10; --res.data[i+1]; }
		}
		while(!res.data[res.end]) --res.end;
		return res;
	}
	bignum operator * (const int &o) const {
		bignum res; int t = 0;
		res.end = end;
		for(int i = 0; i <= end; i++) {
			res.data[i] = data[i] * o + t;
			t = res.data[i] / 10;
			res.data[i] %= 10;	
		}
		while(t) { res.data[++res.end] = t % 10; t /= 10; }
		return res;
	}
	bignum operator / (const int &o) const {
		bignum res;
		res.end = end;
		for(int i = end; i > 0; --i) {
			res.data[i] += data[i];
			res.data[i-1] += res.data[i] % o * 10;
			res.data[i] /= o;
		}
		res.data[0] += data[0]; res.data[0] /= o;
		while(!res.data[res.end]) --res.end;
		return res;
	}
	bignum operator *= (const int &o) { return *this = *this * o; }
	bignum operator /= (const int &o) { return *this = *this / o; }
	bool m2() { return !(data[0] % 2); }
}a, b;

int main() {
	a.input(); b.input();
	int cnt = 0;
	while(a != b) {
		if(a.m2() && b.m2()) { 
			cnt++; 
			a /= 2; 
			b /= 2; 
		}else if(a.m2()) a /= 2;
		else if(b.m2()) b /= 2;
		else if(a < b) b = b - a;
		else a = a - b;
	}
	while(cnt--) a *= 2;
	a.output(); putchar('\n');
	return 0;
}
