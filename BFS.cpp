#include <bits/stdc++.h>

using namespace std;

vector <bool> VIZITAT(10000);
vector <int> ADJACENT[10000];

void BFS(int start){
    VIZITAT[start] = true;

    queue <int> coada;
    coada.push(start);
    while (!coada.empty()){
        int cr = coada.front();
        cout << cr << " ";
        coada.pop();

        for(auto it: ADJACENT[cr])
            if(!VIZITAT[it]){
                coada.push(it);
                VIZITAT[it] = true;
            }
    }
}

int main()
{
    ifstream fin("graf.in");
    int noduri, muchii;

    fin >> noduri >> muchii;

    for(int i = 1; i<= muchii; i++){
        int x, y;
        fin >> x >> y;

        ADJACENT[x].push_back(y);
        ADJACENT[y].push_back(x);
    }

    for(int i = 1; i <= noduri; i++)
        VIZITAT[i] = false;

    BFS(1);








    return 0;
}