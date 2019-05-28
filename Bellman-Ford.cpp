#include <bits/stdc++.h>

using namespace std;

vector <int> DISTANTA(10000);
vector <pair <int, int> > ADJACENT[10000];
queue <int> Q;

int main()
{
    ifstream fin("bellmanford.in");
    int noduri, muchii;

    fin >> noduri >> muchii;

    for(int i = 1; i <= muchii; i++){
        int x, y, cost;
        fin >> x >> y >> cost;

        ADJACENT[x].push_back(make_pair(y, cost));
    }

    for(int i = 1; i <= noduri; i++)
        DISTANTA[i] = 1e9;

    int start = 1;
    Q.push(start);
    DISTANTA[start] = 0;

    vector <int> NUMAR(10000);

    while (!Q.empty()){
        int cr = Q.front();
        Q.pop();
        NUMAR[cr] ++;
        if(NUMAR[cr] > noduri - 1){
            cout << "Ciclu negativ!";
            return 0;
        }
        for(auto it: ADJACENT[cr])
            if(DISTANTA[cr] + it.second < DISTANTA[it.first]){
                DISTANTA[it.first] = DISTANTA[cr] + it.second;
                Q.push(it.first);
            }
    }
    
    for(int i = 2; i <= noduri; i++)
        cout << DISTANTA[i] << " ";

    return 0;
}