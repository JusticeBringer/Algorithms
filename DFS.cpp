#include <bits/stdc++.h>

using namespace std;

vector <bool> VIZITAT(10000);
vector <int> ADJACENT[10000];

void DFS(int start){
    VIZITAT[start] = true;
    cout << start << " ";
    for(auto it: ADJACENT[start])
        if(!(VIZITAT[it]))
            DFS(it);
}

int main()
{
    ifstream fin("graf.in");
    int noduri, muchii;

    fin >> noduri >> muchii;

    for(int i = 1; i <= muchii; i++){
        int x, y;
        fin >> x >> y;

        ADJACENT[x].push_back(y);
        ADJACENT[y].push_back(x);
    }

    for(int i = 1; i <= noduri; i++)
        VIZITAT[i] = false;

    DFS(1);











    return 0;
}