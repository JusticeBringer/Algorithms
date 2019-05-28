#include <bits/stdc++.h>

using namespace std;

vector <bool> ADAUGAT(10000);
vector <int> DISTANTA(10000);
vector <int> PARINTE(10000);
vector <pair <int, int > > ADJACENT[10000];
priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int > > > Q;

void algPrim(int start){
    DISTANTA[start] = 0;
    Q.push(make_pair(0, start));
    
    while(!Q.empty()){
        int cr = Q.top().second;
        Q.pop();
        ADAUGAT[cr]  = true;
        
        for(auto it: ADJACENT[cr])
            if(!ADAUGAT[it.first] && it.second < DISTANTA[it.first]){
                DISTANTA[it.first] = it.second;
                Q.push(make_pair(DISTANTA[it.first], it.first));
                PARINTE[it.first] = cr;
            }
    }
}

int main()
{
    ifstream fin("apm.in");
    int noduri, muchii;

    fin >> noduri >> muchii;

    for(int i = 1; i <= muchii; i++){
        int x, y, cost;
        fin >> x >> y >> cost;

        ADJACENT[x].push_back(make_pair(y, cost));
        ADJACENT[y].push_back(make_pair(x, cost));
    }

    for(int i = 1; i <= noduri; i++){
        ADAUGAT[i]  = false;
        DISTANTA[i] = 1e9;
        PARINTE[i]  = -1;
    }

    algPrim(1);
    for(int i = 2; i <= noduri; i++)
        cout << PARINTE[i] << " " << i << endl;

    return 0;
}