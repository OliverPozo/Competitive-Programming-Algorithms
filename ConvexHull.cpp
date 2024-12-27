//Complejidad: nlogn

//usar este, es mejor
//si es double cambiar el type
//el vector que le das al convex hull solo tiene que estar los n puntos
//no es necesario añadir extras
//ahora esta con colineares incluido, si no quieres incluir en la funcion de 
//convexHull setteas bool include_collinear = false

using type = long long;

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

int orientation(point a, point b, point c) {
    type v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cw(point a, point b, point c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool collinear(point a, point b, point c) { return orientation(a, b, c) == 0; }

void convex_hull(vector<point>& a, bool include_collinear = true) {
    point p0 = *min_element(a.begin(), a.end(), [](point a, point b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });
    sort(a.begin(), a.end(), [&p0](const point& a, const point& b) {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return o < 0;
    });
    if (include_collinear) {
        int i = (int)a.size()-1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }

    vector<point> st;
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }

    a = st;
}

ll area(const vector<point> &p)
{
	ll result = 0;
	for(int i=0;i<p.size()-1;i++)
	{
		result += p[i].x*p[i+1].y - p[i].y*p[i+1].x;;
	}
	return labs(result)/2;
}

int main(){
    fast_cin();
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    return 0;
}