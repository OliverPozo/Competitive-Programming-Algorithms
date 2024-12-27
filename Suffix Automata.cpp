/*El código implementa una automaton de sufijos (Suffix Automaton),
 una estructura de datos eficiente para manejar cadenas y sus sufijos. 
 Permite realizar operaciones como encontrar subcadenas, comprobar si
  una subcadena está contenida en la cadena original, entre otras, 
  de forma eficiente.*/

struct state {int len,link;map<char,int> next;}; //clear next!!
state st[100005];
int sz,last;
void sa_init(){
	last=st[0].len=0;sz=1;
	st[0].link=-1;
}
void sa_extend(char c){
	int k=sz++,p;
	st[k].len=st[last].len+1;
	for(p=last;p!=-1&&!st[p].next.count(c);p=st[p].link)st[p].next[c]=k;
	if(p==-1)st[k].link=0;
	else {
		int q=st[p].next[c];
		if(st[p].len+1==st[q].len)st[k].link=q;
		else {
			int w=sz++;
			st[w].len=st[p].len+1;
			st[w].next=st[q].next;st[w].link=st[q].link;
			for(;p!=-1&&st[p].next[c]==q;p=st[p].link)st[p].next[c]=w;
			st[q].link=st[k].link=w;
		}
	}
	last=k;
}
//  input: abcbcbc
//  i,link,len,next
//  0 -1 0 (a,1) (b,5) (c,7)
//  1 0 1 (b,2)
//  2 5 2 (c,3)
//  3 7 3 (b,4)
//  4 9 4 (c,6)
//  5 0 1 (c,7)
//  6 11 5 (b,8)
//  7 0 2 (b,9)
//  8 9 6 (c,10)
//  9 5 3 (c,11)
//  10 11 7
//  11 7 4 (b,8)


// Estructura que representa un estado en el autómata de sufijos
struct state {
    int len, link;               // 'len' es la longitud del sufijo representado por el estado, 
                                 // 'link' es el enlace al estado de sufijo más largo.
    map<char, int> next;         // 'next' es un mapa que relaciona caracteres con transiciones a otros estados.
};

// Arreglo de estados del autómata de sufijos
state st[100005];
int sz, last;  // 'sz' es el número de estados, 'last' es el último estado añadido.

// Inicializa el autómata de sufijos
void sa_init() {
    last = st[0].len = 0;   // El primer estado representa el sufijo vacío, su longitud es 0.
    sz = 1;                  // El número de estados comienza en 1.
    st[0].link = -1;         // No hay enlace para el primer estado (el sufijo vacío).
}

// Extiende el autómata con un nuevo carácter 'c'
void sa_extend(char c) {
    int k = sz++, p;  // 'k' es el índice del nuevo estado, 'p' es el estado donde vamos a buscar transiciones.

    st[k].len = st[last].len + 1;   // La longitud del nuevo estado es 1 más que la longitud del estado 'last'.
    
    // Busca el primer estado 'p' tal que no tenga una transición para 'c'.
    for (p = last; p != -1 && !st[p].next.count(c); p = st[p].link) {
        st[p].next[c] = k;  // Si 'p' no tiene transición para 'c', la creamos.
    }

    // Si no encontramos un estado con transición para 'c', enlazamos el nuevo estado al estado 0 (el sufijo vacío).
    if (p == -1) {
        st[k].link = 0;
    } else {
        // Si encontramos un estado 'p' con la transición para 'c', verificamos si es necesario crear un nuevo estado.
        int q = st[p].next[c];  // 'q' es el estado al que llegamos por la transición 'c' desde 'p'.

        // Si las longitudes de los sufijos de 'p' y 'q' son iguales, el enlace del nuevo estado es 'q'.
        if (st[p].len + 1 == st[q].len) {
            st[k].link = q;
        } else {
            // Si no, necesitamos crear un nuevo estado 'w' que representa un sufijo común.
            int w = sz++;  
            st[w].len = st[p].len + 1;  // El nuevo estado tiene longitud 1 más que el de 'p'.
            st[w].next = st[q].next;    // Las transiciones de 'w' son las mismas que las de 'q'.
            st[w].link = st[q].link;    // El enlace de 'w' es el mismo que el de 'q'.
            
            // Recorremos todos los estados que tengan la misma transición 'c' y los redirigimos a 'w'.
            for (; p != -1 && st[p].next[c] == q; p = st[p].link) {
                st[p].next[c] = w;
            }
            
            // El enlace de 'q' y el de 'k' deben apuntar a 'w'.
            st[q].link = st[k].link = w;
        }
    }
    
    // Actualizamos el estado 'last' al nuevo estado 'k'.
    last = k;
}

// Ejemplo de entrada: abcbcbc
// Descripción del autómata después de cada extensión:
//  i, link, len, next (transiciones)
//  0 -1 0 (a, 1) (b, 5) (c, 7)
//  1 0 1 (b, 2)
//  2 5 2 (c, 3)
//  3 7 3 (b, 4)
//  4 9 4 (c, 6)
//  5 0 1 (c, 7)
//  6 11 5 (b, 8)
//  7 0 2 (b, 9)
//  8 9 6 (c, 10)
//  9 5 3 (c, 11)
//  10 11 7
//  11 7 4 (b, 8)
