#include <cstdio>
#include <cstring>

using namespace std;

const int N = 15, M = 5;

int m[N][N], f[N][N][M], row[N][N], colu[N][N], blk[N][N];

inline void input();
inline bool check(int,int,int,int);
inline int getone(void);
inline void getnxt(int,int,int&,int&);
inline void output(void);
void sch(int,int);
inline int getblk(int x, int y) { return (y-1)/3+1+(x-1)/3*3; }

int main() {
	memset(f, -1, sizeof(f));
	input();
	sch(1, 1);
	return 0;
}

void sch(int x, int y) {
	if(x == 10) {
		output();
		return;
	}
	int block = getblk(x, y), tx, ty;
	getnxt(x, y, tx, ty);
	for(int i = 1; i <= 9; ++i) {
		if(check(x,y,i, block)) {
			row[x][i] = colu[y][i] = blk[block][i] = 1;
			m[x][y] = i;
			sch(tx, ty);
			m[x][y] = 0;
			row[x][i] = colu[y][i] = blk[block][i] = 0;
		}
	}
}

inline bool check(int x, int y, int i, int block) {
	if(row[x][i] || colu[y][i] || blk[block][i]) return false;
	if(~f[x][y][0] && m[x][y-1] && ((int)(i>m[x][y-1])^(f[x][y][0]))) return false;
	if(~f[x][y][1] && m[x][y+1] && ((int)(i>m[x][y+1])^(f[x][y][1]))) return false;
	if(~f[x][y][2] && m[x-1][y] && ((int)(i>m[x-1][y])^(f[x][y][2]))) return false;
	if(~f[x][y][3] && m[x+1][y] && ((int)(i>m[x+1][y])^(f[x][y][3]))) return false;
	return true; 
}

inline void getnxt(int x, int y, int &tx, int &ty) {
	if(y == 9) {
		tx = x + 1; ty = 1;
	}else {
		tx = x; ty = y + 1;
	}
}
// -> 1 	<- 0	^ 2		v 3
inline void input() {
	int tmp;
	for(int i = 1; i <= 9; ++i) {
		for(int j = 1; j <= 9; ++j) 
			if(j % 3) {
			tmp = getone();
			f[i][j][1] = tmp;
			f[i][j+1][0] = tmp^1;
			}
		if(i%3) for(int j = 1; j <= 9; ++j) {
			tmp = getone();
			f[i][j][3] = tmp;
			f[i+1][j][2] = tmp^1;
		}
	}
}

inline int getone() {
	char ch = getchar();
	while(ch != '<' && ch != '>' && ch != '^' && ch != 'v') ch = getchar();
	if(ch == '<') return 0;
	if(ch == '>') return 1;
	if(ch == '^') return 0;
	return 1;
}

inline void output() {
	for(int i = 1; i <= 9; ++i) {
		for(int j = 1; j <= 9; ++j) {
			printf("%d ", m[i][j]); 
		}
		printf("\n");
	} 
}
