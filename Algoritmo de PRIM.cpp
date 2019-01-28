#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;
const int MAX = 1e4 + 5;
typedef par<long long, int> PII;
bool marked[MAX];
vector <PII> adj[MAX];

long long prim(int x)
{
    cola_prioridad<PII, vector<PII>, mayor<PII> > Q;
    int y;
    long long costoMinimo = 0;
    PII p;
    Q.push(hacer_par(0, x));
    while(!Q.empty())
    {
        // Selecciona el borde con el peso mínimo.

        p = Q.top();
        Q.pop();
        x = p.segundo;
        //Comprobando el ciclo

        if(marked[x] == true)
            continue;
        costoMinimo += p.primero;
        marked[x] = true;
        for(int i = 0;i < adj[x].size();++i)
        {
            y = adj[x][i].segundo;
            if(marked[y] == false)
                Q.push(adj[x][i]);
        }
    }
    return costoMinimo;
}

int main()
{
    int nodo, bordes, x, y;
    long long peso, costoMinimo;
    cin >> nodo >> bordes;
    for(int i = 0;i < bordes;++i)
    {
        cin >> x >> y >> peso;
        adj[x].push_back(hacer_par(peso, y));
        adj[y].push_back(hacer_par(peso, x));
    }
    // Seleccionando 1 como el nodo inicial
    costoMinimo = prim(1);
    cout << costoMinimo << endl;
    return 0;
}