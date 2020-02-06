#include <iostream>
#include <string>
#include <vector> 

using namespace std;

void input(); 

const int MAX_HP = 4;

class heap{		//牌堆
friend istream& operator >> (istream &, heap &);
public:
	char draw();
private:
	vector<char> card;
	vector<char>::iterator p;
	char end;
};

class pig{
friend istream& operator>> (istream &, pig &);
public:
	pig();
	void drawCard();
	char firstCard();
	void putCard();
	bool live();
	void turnDeath();
private:
	int identity;			//MP 0 ZP 1 FP 2
	int showedIdentity;	//未跳身份 0 主猪 -1 跳忠 1 跳反 2 类反 3 
	int hp;
	vector<char> card;
	bool isWeaponed;		//Z
	bool isLive;
};

class game{
	
public: 
	game();
private:
	int n;
	pig p[15];
protected:
	heap h;
}g;

istream& operator >> (istream &lhs, heap &rhs) {
	char tmp;
	while(lhs >> tmp) rhs.card.push_back(tmp);
	rhs.end = tmp;
	return lhs;
}
char heap::draw() { return p == card.end() ? *(p++) : end; }


istream& operator>> (istream &in, pig &p) {
	string iden; in >> iden; char ch;
	p.identity = iden == "MP" ? 0 : iden == "ZP" ? 1 : iden == "FP" ? 2 : -1;
	if(p.identity == -1) { cerr<<"error on read identity"<<endl; exit(-1); }	//check read identity
	for(int i = 0; i < 4; i++) { in >> ch; p.card.push_back(ch); }
	return in;
}
pig::pig() {
	hp = 4; identity = -1; showedIdentity = 0; isLive = true; isWeaponed = false;
}
void pig::drawCard() { card.push_back(g.h.draw()); card.push_back(h.draw()); }
char pig::firstCard() { return *card.begin(); }
void pig::putCard() { card.erase(card.begin()); }
bool pig::live() { return isLive; }
void pig::turnDeath() { isLive = false;	}


void input() {
	cin >> g.n;
	
}

int main() {
	input();
	return 0;
}
