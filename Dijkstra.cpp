#include <bits/stdc++.h>

using namespace std;

vector <int> DISTANTA(10000);
vector <pair <int, int> > ADJACENT[10000];
priority_queue <pair <int, int>, vector <pair <int, int > >, greater <pair <int, int > > > Q;

void dijkstra(int start){
    DISTANTA[start] = 0;
    Q.push(make_pair(0, start));

    while(!Q.empty()){
        int cr = Q.top().second;
        Q.pop();
        for(auto it: ADJACENT[cr])
            if(DISTANTA[cr] + it.second < DISTANTA[it.first]){
                DISTANTA[it.first] = DISTANTA[cr] + it.second;
                Q.push(make_pair(DISTANTA[it.first], it.first));
            }
    }
}

int main()
{
    ifstream fin("dijkstra.in");
    int noduri, muchii;

    fin >> noduri >> muchii;    

    for(int i = 1; i <= muchii; i++){
        int x, y, cost;
        fin >> x >> y >> cost;
        ADJACENT[x].push_back(make_pair(y, cost));
    }

    for(int i = 1; i <= noduri; i++){
        DISTANTA[i] = 1e9; 
    }

    dijkstra(1);

    for(int i = 2; i <= noduri; i++)
        cout << DISTANTA[i] << " ";

    return 0;
}