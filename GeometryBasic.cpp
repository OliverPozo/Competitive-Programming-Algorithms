#include <bits/stdc++.h>  
 
#define ll                    long long
#define ld                    long double
#define mp                    make_pair
#define pb                    push_back
#define fi                    first
#define se                    second
#define INF                   2e18
#define all(x)                (x).begin(), (x).end()
#define sz(x)                 ((int)(x).size())
#define forn(i,n)             for(int i = 0; i < n; i++)
#define fore(i,b,e)           for(int i = b; i < e; i++)
#define forg(i,b,e,m)         for(int i = b; i < e; i+=m)
#define rforn(i,n)            for(int i = n; i >= 0; i--)
#define rfore(i,b,e)          for(int i = b; i >= e; i--)
#define rforg(i,b,e,m)        for(int i = s; i >= e; i-=m)
#define endl                  "\n"
#define MOD                   1000000007
#define fast_cin()            ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;


//SI VAS A USAR LONG LONG QUE TU INF SEA LLONG_MAX, CUIDADO!!!


using type = double;


const double EPS = 1e-9;
const double PI = acos((double)-1.0);

bool ge(type x, type y) { return x + EPS > y; }
bool le(type x, type y) { return x - EPS < y; }

struct point{
    type x,y; 
    point(){ x = 0, y = 0;}
    point(type x, type y): x(x), y(y){}

    point operator -() { return point(-x, -y); }
    point operator +(point p) { return point(x + p.x, y + p.y); }
    point operator -(point p) { return point(x - p.x, y - p.y); }

    point operator *(type k) { return point(k*x, k*y); }
    point operator /(type k) { return point(x/k, y/k); }

    //producto punto product
    type operator *(point p) { return x*p.x + y*p.y; }
    //cross product
    type operator %(point p) { return x*p.y - y*p.x; }

    bool operator ==(const point &p) const{ return x == p.x and y == p.y; }
    bool operator !=(const point &p) const{ return x != p.x  or y != p.y; }
    bool operator <(const point &p) const { return (x < p.x) or (x == p.x and y < p.y); }


    //para saber si el punto actual esta a la izquierda o derecha en relacion
    //a la linea generada por los puntos o y p. 
    // 0 => same direction
    // 1 => this is on the left 
    //-1 => this is on the right    
    int dir(point o, point p) {
        type x = (p - o) % (*this - o);
        return ge(x,0) - le(x,0);
    }

    //si el punto actual esta en el segmento generado por p y q. 
    bool on_seg(point p, point q) {
        if (this->dir(p, q)) return 0;
        return ge(x, min(p.x, q.x)) and le(x, max(p.x, q.x)) and ge(y, min(p.y, q.y)) and le(y, max(p.y, q.y));
    }

    type abs() { return sqrt(x*x + y*y); }
    type abs2() { return x*x + y*y; }
    //retorna la distancia entre el punto actual y q
    type dist(point q) { return (*this - q).abs(); }
    type dist2(point q) { return (*this - q).abs2(); }
};

//te da la direccion relativa del punto p en relacion a la linea generada
//por los puntos o y q. 
int direction(point p, point o, point q) { return p.dir(o, q); }

//for reading purposes avoid using * and % operators, use the functions below:
type dot(point p, point q)     { return p.x*q.x + p.y*q.y; }
type cross(point p, point q)   { return p.x*q.y - p.y*q.x; }

//double area
//el area es 1/2 la suma del producto cruzado entre los tres puntos
//esto te da el doble del area para no tener division
type area_2(point a, point b, point c) { return cross(a,b) + cross(b,c) + cross(c,a); }


//YouKnowWho
bool is_point_on_seg(point p, point a, point b) {
    if (fabs(cross(p - b, a - b)) < EPS) {
        if (p.x < min(a.x, b.x) - EPS || p.x > max(a.x, b.x) + EPS) return false;
        if (p.y < min(a.y, b.y) - EPS || p.y > max(a.y, b.y) + EPS) return false;
        return true;
    }
    return false;
}

//Se usa para line segment intersection(abajo)
bool quick_check(point p1, point p2, point p3, point p4) {
	type x1, x2, x3, x4, y1, y2, y3, y4;
	x1 = min(p1.x, p2.x), x2 = max(p1.x, p2.x);
	y1 = min(p1.y, p2.y), y2 = max(p1.y, p2.y);
	x3 = min(p3.x, p4.x), x4 = max(p3.x, p4.x);
	y3 = min(p3.y, p4.y), y4 = max(p3.y, p4.y);
	return x2 < x3 || x4 < x1 || y2 < y3 || y4 < y1;
}

//Line segment intersection
//Te dan los segmentos: El primero conformado por p1 y p2, el segundo por p3 y p4
//Te dice si hay interseccion entre los segmentos(si chocan en un punto).

bool lineSegmentIntersection(point p1, point p2, point p3, point p4){
    if(quick_check(p1, p2, p3, p4)) return 0;
    if(direction(p1, p3, p4)*direction(p2, p3, p4)<=0 &&
        (direction(p3, p1, p2)*direction(p4, p1, p2))<=0) return 1;
    return 0;
}


/*
Dado un conjunto de punto te retorna la distancia minima entre dos puntos distintos. 
*/
ll minimumEuclideanDistance(vector<point>& vec){
    //ordenar por x
    sort(all(vec));
    //set para mantener los puntos activos que me serviran para revisar despues
    set<point> st;
    st.insert({vec[0].y, vec[0].x});
    ll disMi = LLONG_MAX;
    ll j = 0, n = sz(vec);
    for(int i = 1; i < n; i++){
        ll dis = ceil(sqrt(disMi));
        while(j < i && vec[i].x-dis>vec[j].x){
            st.erase({vec[j].y, vec[j].x});
            j++;
        }
        auto itLo = st.lower_bound({vec[i].y-dis, 0ll});
        auto itHi = st.upper_bound({vec[i].y+dis, 0ll});
        for(auto it = itLo; it != itHi; it++){
            disMi = min(disMi, vec[i].dist2({it->y, it->x}));
        }
        st.insert({vec[i].y, vec[i].x});
    }
    return disMi;
}



int main(){
    fast_cin();
    
    return 0;
}


