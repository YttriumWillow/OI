// Classification Activate !!


#include <iostream>
#include <vector>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

int n, m;
int mainPig = 0;
int traitorCnt = 0;
int heapTop = 0;

bool pWin;
bool GameOver;

char cardHeap[2010];

struct Card
{
	// Property
	char fce;

	// Feature
	bool ava;

	Card() {}
	Card(char a, bool b) { fce = a; ava = b; }
};
struct Pig
{
	// Property
	int idx;
	int hel;
	char idt;

	vector<Card> hnd;

	// Feature T/F
	bool dead;
	bool useKill;
	bool likeTraitor;
	bool jumped;
	bool equipped;

	// Behavior
	bool canUse(char p);

	int canKill();

	void generalAct 	();
	void getCard 		() 			{ hnd.push_back(Card(cardHeap[++heapTop], true)); }
	void getCard 		(int cnt) 	{ while (cnt--) getCard(); }
	void initIdt 		(char p) 	{ idt = p; }
	void jump 			() 			{ jumped = 1; }
	void startTurn 		();
	void use 			();

	Pig()
	{
		hel = 4;
		dead = 0;
		useKill = 0;
		likeTraitor = 0;
		jumped = 0;
		equipped = 0;
	}
};
Pig pig[15];


void remappingIdx() { rep (i, 1, n) { pig[i].idx = i; } }
void endgame() { return; }
void generalInitalize()
{
	cin >> n >> m;

	rep (i, 1, n)
	{
		string s; cin >> s;

		if (s[0] == 'M') { mainPig = i; }
		else if (s[0] == 'F') { ++traitorCnt; }

		pig[i].initIdt(s[0]);

		char ch;
		while ((ch = getchar()) != endl)
			if (isalpha(ch))
				pig[i].hnd.push_back(Card(ch, true));
	}

	rep (i, 1, m)
	{
		char ch;
		while (not isdigit(ch = getchar())) continue;
		cardHeap[i] = ch;
	}

	remappingIdx();

	rep (i, m + 1, 2000) { cardHeap[i] = cardHeap[m]; } //

	pig[mainPig].jump();

	if (traitorCnt == 0) { GameOver = 1; }

	int cur = 0;

	while (true)
	{
		if (GameOver) { endgame(); break; }

		cur = cur % n + 1;
		if (pig[cur].dead) continue;

		pig[cur].startTurn();
	}
}

int main()
{
	generalInitalize();
	return 0;
}

inline bool Pig::canUse(char p)
{
	if (p == 'P' and hel < 4)
		return true;
	if (
	    (p == 'K' and canKill())
	    or 	(p == 'F' and canFight())
	    or 	(p == 'N')
	    or 	(p == 'W')
	    or 	(p == 'Z')
	)
		return true;

	return false;
}
inline void Pig::generalAct()
{
	bool canPerform = 1;
	while (canPerform)
	{
		canPerform = 0;
		// for (auto& C : hnd)
		for (auto i = hnd.begin(); i != hnd.end(); ++i)
		{
			auto C = *i;
			if (C.ava and canUse(C.fce))
			{
				use(C.fce);
				if (dead or GameOver) return;
				i = prev(hnd.begin());
				canPerform = 1;
			}
		}
	}
}
inline void Pig::startTurn()
{
	getCard(2);
	generalAct();
	useKill = 0;
}
inline void Pig::use()
{
	return;
}
inline int Pig::canKill()
{
	if (useKill and not equipped) return false;
	if (idt == 'M')
	{
		for (int i = idx % n + 1; i != idx; i = i % n + 1)
		{
			if (pig[i].dead) continue;
			if (pig[i].likeTraitor or (pig[i].idt == 'F' and pig[i].jumped))
				return i;
			else
				return 0;
		}
	}
	else if (idt == 'Z')
	{
		for (int i = idx % n + 1; i != idx; i = i % n + 1)
		{
			if (pig[i].dead) continue;
			if (pig[i].idt == 'F' and pig[i].jumped)
				return i;
			else
				return 0;
		}
	}
	else
	{
		for (int i = idx % n + 1; i != idx; i = i % n + 1)
		{
			if (pig[i].dead) continue;
			if (pig[i].idt != 'F' and pig[i].jumped)
				return i;
			else
				return 0;
		}
	}
	return 0;
}