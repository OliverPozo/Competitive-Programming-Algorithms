#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define int ll
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(int)a.size()
//#define eq(a, b)     	(fabs(a - b) < EPS)
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define DBG(x) cerr<<#x<<" = "<<(x)<<endl
#define RAYA cerr<<"=============================="<<endl
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 

struct point
{
	double x, y;
	point() {}
	point(double x, double y) : x(x), y(y){}
};
double dist(point a, point b)
{
	return hypot(a.x - b.x, a.y - b.y);
}
double cross2(point a, point b)
{
	return a.x*b.y - a.y*b.x;
}
point tovec(point a, point b)
{
	return point(b.x - a.x, b.y - a.y);
}
double cross(point a, point b, point c)
{
	return cross2(tovec(a, b), tovec(a, c));
}
bool eq(double a, double b)
{
	return fabs(a-b) < EPS;
}
point mini;
bool comp(point a, point b)
{
	point ta = tovec(mini, a);
	point tb = tovec(mini, b);
	double ana = atan2(ta.y, ta.x), anb = atan2(tb.y, tb.x);
	if(eq(ana, anb))
		return dist(a, mini) < dist(b, mini);
	return ana < anb - EPS;
}
//no hay 3 puntos colineales
vector<point> hull(vector<point> p)
{
	for(int i = 1; i < p.size(); i++)
	{
		if(eq(p[i].y, p[0].y) )
		{
			if(p[i].x < p[0].x - EPS)
				swap(p[i], p[0]);
		}
		else
		{
			if(p[i].y < p[0].y - EPS)
				swap(p[i], p[0]);
		}
	}
	mini = p[0];
	sort(++p.begin(), p.end(), comp);
	p.pb(p[0]);
	vector<point> res;
	res.pb(p[0]);
	res.pb(p[1]);
	for(int i = 2; i < p.size(); i++)
	{
		while(cross(res[res.size()-2], res.back(), p[i]) < EPS)
		{	
			res.pop_back();
		}
		res.pb(p[i]);
	}
	return res;
}

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	
	return 0;
}