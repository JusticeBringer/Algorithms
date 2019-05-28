#include <bits/stdc++.h>

using namespace std;

struct kruskal{
    int from;
    int to;
    int cost;
};

vector <int> PARINTE(10000);
vector <kruskal> ADJACENT(10000);

bool cmp(const kruskal &a, const kruskal &b){
    return a.cost < b.cost;
}

int reprezentare(int nod){
    if(nod == PARINTE[nod])
        return nod;
    else
        reprezentare(PARINTE[nod]);
}

void unire(int a, int b){
    int A = reprezentare(a);
    int B = reprezentare(b);
    PARINTE[B] = A;
}

int main()
{   
    ifstream fin("apm.in");
    int noduri, muchii;

    fin >> noduri >> muchii;

    for(int i = 1; i <= muchii; i++){
        kruskal muchie;
        fin >> muchie.from >> muchie.to >> muchie.cost;
        ADJACENT.push_back(muchie);
    }

    sort(ADJACENT.begin(), ADJACENT.end(), cmp);
    for(int i = 1; i <= noduri; i++)
        PARINTE[i] = i;

    vector <kruskal> nouGraf;

    for(auto it: ADJACENT)
        if(reprezentare(it.from) != reprezentare(it.to)){
            unire(it.from, it.to);
            nouGraf.push_back(it);
        }

    for(auto it: nouGraf)
        cout << it.from << " " << it.to << endl;

    return 0;
}