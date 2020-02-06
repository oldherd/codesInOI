//outputDebug
//tree without change data
#include <queue>
#define pii pair<int, int>
ostream& operator << (ostream &os, Splay &s) {
	queue<pii> q;
	int cur = s.root;
	q.push(make_pair(cur, 1));
	int la = 1;
	while(!q.empty()) {
		cur = q.front().first; int dep = q.front().second; q.pop();
		if(la != dep) os << endl; la = dep;
		os<<"("<<cur<<": <"<<s.val[cur]<<", " << s.cnt[cur]<<"> "<<"son:("<<s.ch[cur][0]<<", "<<s.ch[cur][1]<<") ) size:"<<s.size[cur]<<"   ";
		if(s.ch[cur][0]) q.push(make_pair(s.ch[cur][0], dep+1));
		if(s.ch[cur][1]) q.push(make_pair(s.ch[cur][1], dep+1));
	}
	return os;
}

//all number change data
ostream& operator << (ostream &os, Splay &s) {
	int cur = s.root, tm, la = 0;
	while(s.ch[cur][0]) cur = s.ch[cur][0];
	while(la != inf) {
		if(s.val[cur] == la) break;
		la = s.val[cur];
		tm = s.cnt[cur];
		while(tm--) os << la << " ";
		cur = s.prePost(s.val[cur], 1);
	}
	return os;
}

//testData
//2 12 324 777(del) 50000
