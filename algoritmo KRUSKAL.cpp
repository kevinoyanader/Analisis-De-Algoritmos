#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
const int MAX = 1e4 + 5;
int id[MAX], nodos, bordes;
par <long long, par<int, int> > p[MAX];

void inicializar()
{
    for(int i = 0;i < MAX;++i)
        id[i] = i;
}

int raiz(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p = raiz(x);
    int q = raiz(y);
    id[p] = id[q];
}

long long kruskal(par<long long, par<int, int> > p[])
{
    int x, y;
    long long costo, costoMinimo = 0;
    for(int i = 0;i < bordes;++i)
    {
        // Selecciona bordes uno a uno en orden creciente desde el principio
        x = p[i].segundo.primero;
        y = p[i].segundo.segundo;
        costo = p[i].first;
        // Comprueba si el borde seleccionado está creando un ciclo o no
        if(raiz(x) != raiz(y))
        {
            costoMinimo += costo;
            union1(x, y);
        }    
    }
    return costoMinimo;
}

int main()
{
    int x, y;
    long long peso, costo, costoMinimo;
    inicializar();
    cin >> nodos >> bordes;
    for(int i = 0;i < bordes;++i)
    {
        cin >> x >> y >> peso;
        p[i] = hacer_par(peso, hacer_par(x, y));
    }
    // Ordenar los bordes en orden ascendente
    sort(p, p + bordes);
    costoMinimo = kruskal(p);
    cout << costoMinimo << endl;
    return 0;
}