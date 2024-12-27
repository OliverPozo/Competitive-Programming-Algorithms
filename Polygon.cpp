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


double dist(point a, point b)
{
	return hypot(a.x-b.x, a.y-b.y);
}
point tovec(point a, point b)
{
	return point(b.x-a.x,b.y-a.y);
}
double norm(point a)
{
	return hypot(a.x,a.y);
}
double dot(point a, point b)
{
	return a.x*b.x + a.y*b.y;
}
double cross(point a, point b)
{
	return a.x*b.y - a.y*b.x;
}
bool ccw(point a, point b, point c)
{
	return cross(tovec(a,b),tovec(a,c)) >= 0; //depende si se acepta colinear o no
}
double an(point a, point b, point c)
{
	a = tovec(b,a), b = tovec(b,c);
	return acos(dot(a,b)/(norm(a)*norm(b)));
}
double perimeter(const vector<point> &p)
{
	double result = 0.0;
	for(int i = 0; i<p.size()-1; i++)
	{
		result += dist(p[i],p[i+1]);
	}
	return result;
}

//Tienes que darle el vector de punto donde el vec[n-1] = vec[0],
//es decir al final de todos los puntos vuelves a añadir el primer punto
//si la respuesta es ll cambias todo a ll incluido el double del struct del 
//punto. Recuerda el problema de CSES de area de poligono que era entero. 
double area(const vector<point> &p)
{
	double result = 0.0;
	for(int i=0;i<p.size()-1;i++)
	{
		result += p[i].x*p[i+1].y - p[i].y*p[i+1].x;;
	}
	return fabs(result)/2.0;
}
point lineIntersectSeg(point p, point q, point A, point B) 
{
	double a = B.y - A.y;
	double b = A.x - B.x;
	double c = B.x * A.y - A.x * B.y;
	double u = fabs(a * p.x + b * p.y + c);
	double v = fabs(a * q.x + b * q.y + c);
	return point((p.x * v + q.x * u) / (u+v), (p.y * v + q.y * u) / (u+v)); 
}
vector<point> cutPolygon(point a, point b, const vector<point> &Q) 
{
	vector<point> P;
	for (int i = 0; i < (int)Q.size(); i++) {
		double left1 = cross(tovec(a, b), tovec(a, Q[i])), left2 = 0;
		if (i != (int)Q.size()-1) left2 = cross(tovec(a, b), tovec(a, Q[i+1]));
		if (left1 > -EPS) P.push_back(Q[i]); // Q[i] is on the left of ab ; left1 < EPS para la derecha
		if (left1 * left2 < -EPS) // edge (Q[i], Q[i+1]) crosses line ab
			P.push_back(lineIntersectSeg(Q[i], Q[i+1], a, b));
	}
	if (!P.empty() && (P.back().x != P.front().x || P.back().y != P.front().y))
		P.push_back(P.front()); // make P’s first point = P’s last point
	return P;
}
bool isConvex(const vector<point> &p)
{
	int sz = p.size();
	if(sz<=3) return false;
	bool left = ccw(p[0],p[1],p[2]);
	cout<<left<<endl;
	for(int i = 1; i < sz - 1; i++)
	{
		cout<<i<<' '<<ccw(p[i],p[i+1],p[((i+2)==sz)? 1:i+2])<<endl;
		if(ccw(p[i],p[i+1],p[((i+2)==sz)? 1:i+2])!=left)
			return false;
	}
	return true;
}
bool isIn(const vector<point> &p, point a)
{
	double ang = 0;
	int sz = p.size();
	if(sz == 0) return false;
	for(int i = 0; i<sz-1;i++)
	{
		if(ccw(a,p[i],p[i+1]))
			ang += an(p[i],a,p[i+1]);
		else
			ang -= an(p[i],a,p[i+1]);
	}
	cout<<ang<<endl;
	return fabs(ang - 2.0*PI) < EPS;
}

/*Lattice Points in Polygon
The problems says count the integer coordinates inside a polygon and in the 
boundaries.
Area you have it above, points in boundary you have it below. 
*/

//The formula is:
//A = i +b/2 - 1 where A is the area of the polygon, i the number of integer points
//inside and b the number of points in the boundary. 

//i = A-b/2+1

ll pointsInBoundary(const vector<point> &p){
    ll points = 0;
    for(int i = 0; i < sz(p)-1; i++){
        ll cant = __gcd(abs(p[i].x-p[i+1].x), abs(p[i].y-p[i+1].y));
        points += cant;
    }
    return points;
}


//point in polygon(inside, outside, boundary)}
//the polygon has n+1 points because you have tu put de beginning point at the end
//return -1 outside, 0 boundary, 1 inside
ll pointInPoly(const vector<point> &polygon, point act){
    bool bo = 0;
    ll cont = 0;
    forn(i,sz(polygon)-1){
        if(act.on_seg(polygon[i], polygon[i+1])){
            bo = 1;
            break;
        }
        if(polygon[i].y<=act.y && act.y<polygon[i+1].y && 
        act.dir(polygon[i], polygon[i+1])>0){
            cont++;
        }
        if(polygon[i+1].y<=act.y && act.y<polygon[i].y && 
        act.dir(polygon[i+1], polygon[i])>0){
            cont++;
        }
    }
    if(bo) return 0;
    else{
        if(cont & 1) return 1;
        return -1;
    }
}
