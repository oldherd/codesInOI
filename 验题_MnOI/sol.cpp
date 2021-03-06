#include <bits/stdc++.h>
using namespace std;

const int maxn = 100, maxm = 100, maxk = 100;
int n, m, k;
bool flagGame = true, noZumbles;

struct shooter{		//attack = 1, bspeed = 1, fz = 2
	int x, y;	//place
	int frz;	//froze
	int hp;
	bool isLive;
}st[maxn];
int su = 0;
struct thrower{		//attack = 3, bspeed = 2, fz = 
	int x, y;	//place
	int frz, gld;
	int hp;
	bool isLive;
}th[maxn];
int tu = 0;
struct zumbles{
	int x, y;
	int spd;	//speed move
	int hp;
	int agg;	//attack
	int abtAtk;
	bool isLive;
}zbs[maxm];
int zu = 0;
struct bullet{
	int xi, yi;
	bool isLive;	
}blt[maxn];
int bu = 0;

pair<int, int> mmap[10][15];		//1...5 1...9
int zd[10][15];

struct setPlant{
	int time, kind, x, y;	
	bool operator < (const setPlant& o) const {
		return time < o.time;	
	}
}sp[maxn];
struct setZumbles{
	int time, kind, x, y;
	bool operator < (const setZumbles& o) const {
		return time < o.time;	
	}
}sz[maxm];
struct setBossAttack{
	int time, y;
	bool operator < (const setBossAttack& o) const {
		return time < o.time;	
	}
}sb[maxk];

void init() {
	string s;
	for(int i = 1; i <= 9; i++) mmap[0][i] = make_pair(-1, 0);		//car
	for(int i = 1; i <= 5; i++)
		for(int j = 1; j <= 9; j++)
			mmap[i][j] = make_pair(0, 0);
	for(int i = 0; i < n; i++) {
		cin >> s >> sp[i].time >> sp[i].y >> sp[i].x;
		sp[i].kind = s[0]=='W'?1:2;
	}
	for(int i = 0; i < m; i++) {
		cin >> s >> sz[i].time >> sz[i].y >> sz[i].x;
		switch(s[0]) {
			case 'P': sz[i].kind = 1; break;
			case 'L': sz[i].kind = 2; break;
			case 'T': sz[i].kind = 3; break;
			case 'G': sz[i].kind = 4;	
		}
	}
	for(int i = 0; i < k; i++)
		cin >> sb[i].time >> sb[i].y;
	sort(sp, sp+n); sort(sz, sz+m); sort(sb, sb+k);
}

queue<int> shq, thq, zbq, blq;
void addShooter(int xi, int yi){
	int id;
	if(!shq.empty()) {
		id = shq.front(); shq.pop();	
	} else id = su++;
	shooter &it = st[id];
	it.x = xi; it.y = yi; it.hp = 7;
	it.frz = 0; it.isLive = true;
	mmap[xi][yi] = make_pair(1, id);
}
void addThrower(int xi, int yi) {
	int id;
	if(!thq.empty()) {
		id = thq.front(); thq.pop();	
	} else id = tu++;
	thrower &it = th[id];
	it.x = xi; it.y = yi; it.frz = it.gld = 0;
	it.hp = 9; it.isLive = true;
	mmap[xi][yi] = make_pair(2, id);
}
void addZumbles(int xi, int yi, int spd, int agg, int hp) {
	int id;
	if(!zbq.empty()) {
		id = zbq.front(); zbq.pop();	
	} else id = zu++;
	zumbles &it = zbs[id];
	it.x = xi; it.y = yi; it.spd = spd; it.hp = hp;
	it.agg = agg; it.abtAtk = -1; it.isLive = true;
	mmap[xi][yi] = make_pair(3, id);
}
void addBullet(int xi, int yi) {
	int id;
	if(!blq.empty()) {
		id = blq.front(); blq.pop();
	} else id = bu++;
	bullet &it = blt[id];
	it.xi = xi; it.yi = yi; it.isLive = true;
	zd[xi][yi] = id;
}
void setItems(int t) {
	static int pp = 0, pz = 0;
	while(pp < n && sp[pp].time == t) {
		setPlant &s = sp[pp];
		if(s.kind == 1) addShooter(s.x, s.y);
		else if(s.kind == 2) addThrower(s.x, s.y);
		pp++;
	}
	while(pz < m && sz[pz].time == t) {
		setZumbles &s = sz[pz];
		switch(s.kind) {
			case 1: addZumbles(s.x, s.y, 1, 1, 5); break;
			case 2: addZumbles(s.x, s.y, 1, 1, 7); break;
			case 3: addZumbles(s.x, s.y, 1, 1, 9); break;
			case 4: addZumbles(s.x, s.y, 2, 1, 9);
		}
		pz++;
	}
}

int getLine() {
	int x = 0, wx = 0;
	for(int i = 1; i <= 5; i++) {
		int t = 0;
		for(int j = 1; j <= 9; j++) {
			if(mmap[i][j].first == 1) t += 7;
			else if(mmap[i][j].first == 2) t += 9;
		}
		if(t > wx) { x = i; wx = t;	}
	}
	return x;
}

void killer(int xi, int yi) {
	if(mmap[xi][yi].first == 2) th[mmap[xi][yi].second].hp = 0;
	else st[mmap[xi][yi].second].hp = 0;
}

void bossAttack(int t) {
	static int pb = 0;
	while(pb < n && sb[pb].time == t) {
		setBossAttack &s = sb[pb];
		int x = getLine();
		killer(x, s.y-1);
		killer(x, s.y);
		killer(x, s.y+1);
		pb++;
	}
}

void plantAttack() {
	int isZum[10];//, lstZum[10][2];
	for(int i = 1; i <= 5; i++) {
		for(int j = 9; j > -1 && !isZum[i]; --j)
			if(mmap[i][j].first == 3)
				isZum[i] = j;
//		for(int j = 1; !lstZum[i][0] && j <= 9; j++)
//			if(mmap[i][j].first == 3)
//				lstZum[i][0] = j, lstZum[i][1] = zbs[mmap[i][j].second].spd;
	}
	for(int i = 0; i < su; i++)
		if(st[i].isLive) {
			if(st[i].frz > 0) st[i].frz--;
			if(st[i].frz <= 0 && isZum[st[i].x] >= st[i].y) {
				addBullet(st[i].x, st[i].y);
				st[i].frz = 2;
			}
		}
	for(int i = 0; i < su; i++)
		if(th[i].isLive) {
			if(th[i].frz > 0) th[i].frz--;
			if(th[i].gld > -100) th[i].gld--;
			if(th[i].frz <= 0 && isZum[th[i].x] >= th[i].y) {
				int id;
				for(int j = 1; j <= 9; j++)
					if(mmap[i][j].first == 3) {
						id = mmap[i][j].second;
						break;
					}
				th[i].frz = 2;
				zbs[id].abtAtk = th[i].gld = (zbs[id].y-th[i].y)/(2+zbs[id].spd);
			}
		}
} 

void bulletFly() {
	for(int i = 0; i < bu; i++)
		if(blt[i].isLive) {
			bullet& it = blt[i];
			zd[it.xi][it.yi] = 0;
			it.yi += 1;
			if(mmap[it.xi][it.yi].first == 3) {
				it.isLive = false;
				blq.push(i);
				zd[it.xi][it.yi] = 0;
				zbs[mmap[it.xi][it.yi].second].hp -= 1;
			} else zd[it.xi][it.yi] = i;
		}
}

void zumblesGo() {
	for(int i = 0; i <= n; i++)
		if(zbs[i].isLive) {
			zumbles& it = zbs[i];
			if(!(it.abtAtk--)) it.hp -= 3;
			if(mmap[it.x][it.y+1].first == 1)
				st[mmap[it.x][it.y+1].second].hp -= it.agg;
			else if(mmap[it.x][it.y+1].first == 2)
				th[mmap[it.x][it.y].second].hp -= it.agg;
			else {
				mmap[it.x][it.y] = make_pair(0, 0);
				if(it.spd == 2) {
					if(mmap[it.x][it.y+1].first == 1 || mmap[it.x][it.y+1].first == 2) {
						if(zd[it.x][it.y-1]) {
							it.hp--;
							blt[zd[it.x][it.y-1]].isLive = false;
							blq.push(zd[it.x][it.y-1]);
						}
						it.y--;
					} else {
						if(zd[it.x][it.y-1]) {
							it.hp--;
							blt[zd[it.x][it.y-1]].isLive = false;
							blq.push(zd[it.x][it.y-1]);
						}
						if(zd[it.x][it.y-2]) {
							it.hp--;
							blt[zd[it.x][it.y-2]].isLive = false;
							blq.push(zd[it.x][it.y-2]);
						}
						it.y -= 2;
					}
				}
				else it.y -= it.spd;
			}
			if(it.y <= 0) flagGame = false;
		}
}

void checkDeath() {
	for(int i = 0; i < su; i++)
		if(st[i].hp <= 0){
			st[i].isLive = false;
			shq.push(i);
		}
	for(int i = 0; i < tu; i++)
		if(th[i].hp <= 0) {
			th[i].isLive = false;
			thq.push(i);	
		}
	for(int i = 0; i < zu; i++)
		if(zbs[i].hp <= 0) {
			zbs[i].isLive = false;
			zbq.push(i);	
		}
}

void drawMap() {
	noZumbles = true;
	for(int i = 1; i <= 5; i++)
		for(int j = 1; j <= 9; j++)
			mmap[i][j] = make_pair(0, 0), zd[i][j] = 0;
	for(int i = 0; i < su; i++)
		if(st[i].isLive)
			mmap[st[i].x][st[i].y] = make_pair(1, i);
	for(int i = 0; i < tu; i++)
		if(th[i].isLive)
			mmap[th[i].x][th[i].y] = make_pair(2, i);
	for(int i = 0; i < zu; i++)
		if(zbs[i].isLive) {
			mmap[zbs[i].x][zbs[i].y] = make_pair(3, i);
			noZumbles = false;
		}
	for(int i = 0; i < bu; i++)
		if(blt[i].isLive)
			zd[blt[i].xi][blt[i].yi] = i;
}

bool gameWin(int t) {
	if(t > sz[m-1].time && noZumbles) return true;
	return false;
}

void printMap() {
	cout << "#######################" << endl;
	for(int i = 1; i <= 5; i++) {
		for(int j = 1; j <= 9; j++) {
			pair<int, int>& it = mmap[i][j];
			if(it.first == 1)
				cout << "P";
			else if(it.first == 2)
				cout << "T";
			else if(it.first == 3)
				cout << "J";
			else if(zd[i][j])
				cout << "Z";
			else cout << " ";
		}
		cout << endl;
	}
	cout << "#######################" << endl;
}

int main() {
	int t = 0;
	cin >> n >> m >> k;
	init();
	while(++t) {
		setItems(t);
		drawMap();
		cout << t-1 << endl;
		printMap();
		bossAttack(t);
		if(gameWin(t)) {
			printf("-1\n");
			return 0;
		}
		plantAttack();
		bulletFly();
		zumblesGo();
		if(!flagGame) {
			printf("%d\n", t);
			break;
		}
		checkDeath();
	}
	return 0;
}
