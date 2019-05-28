#include <bits/stdc++.h>

using namespace std;

vector <int> ADJACENT[10000];
vector <bool> VIZITAT(10000);
stack  <int> STIVA;

void DFS(int start){
    VIZITAT[start] = true;
    for(auto it: ADJACENT[start])
        if(!VIZITAT[it])
            DFS(it);
    STIVA.push(start);
}

int main()
{
    ifstream fin("sortaret.in");
    int noduri, muchii;

    fin >> noduri >> muchii;

    for(int i = 1; i <= muchii; i++){
        int x, y;
        fin >> x >> y;

        ADJACENT[x].push_back(y);
    }

    for(int i = 1; i <= noduri; i++)
        VIZITAT[i] = false;

    for(int i = 1; i <= noduri; i++)
        if(!VIZITAT[i])
            DFS(i);

    while(!STIVA.empty()){
        cout << STIVA.top() << " ";
        STIVA.pop();
    }

    return 0;
}