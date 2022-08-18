#define infinity 9999
#define MAX 20

#include <iostream>
#include <stdlib.h>

using namespace std;
class Q
{
    int data[30];
    int R, F;

public:
    Q()
    {
        R = F = -1;
    }
    void init()
    {
        R = F = -1;
    }
    int empty()
    {
        if (R == -1)
            return 1;
        return 0;
    }
    void insert(int x)
    {
        if (empty())
            R = F = 0;
        else
            R = R + 1;     // R will increase while inserting F remain same
        data[R] = x;
    }
    int Delete()
    {
        int x = data[F];
        if (R == F)
            R = F = -1;
        else
            F = F + 1;     // F will increase while deleting node
        return (x);
    }
};

struct node
{
    node *next;
    int vertex;    // data of node
};

class graph
{
    node *G[20];
    int n;
    int visited[MAX];
    void insert(int vi, int vj);
    void DFS1(int);  // int will take user input(from which node you have to start)

public:
    graph() { n = 0; }
    void readgraph();
    void BFS(int);
    void DFS(int p)  // sourse node
    {
        for(int i = 0 ; i<n ; i++)
        {
            visited[i] =0;
        }
        DFS1(p);
    }
   
};

void graph::readgraph()
{
    int i, vi, vj, no_of_edges;
    cout << "\nEnter no. of vertices";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        G[i] = NULL;
    }
    cout << "\nEnter no. of edges:";
    cin >> no_of_edges;
    for (i = 0; i < no_of_edges; i++)
    {
        cout << "\nEnter an edge (u,v) : ";
        cin >> vi >> vj;
        insert(vi, vj);
        insert(vj, vi);
    }
}

void graph::insert(int vi, int vj)
{
    node *p, *q;
    q = new node;
    q->vertex = vj;
    q->next = NULL;
    if (G[vi] == NULL)
        G[vi] = q;
    else
    {
        p = G[vi];
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = q;
    }
}


void graph::DFS1(int i) // i is the sourse node
{
    node *p;
    cout << "\n"<< i << " ";
    p = G[i];             // storing sourse node in P
    visited[i] = 1;       // just mark it visited
    while (p != NULL)   // 
    {
        i = p->vertex;  //storing data of p into i
        if (!visited[i])
            DFS1(i);
        p = p->next;
    }
}

void graph::BFS(int v)
{
    int i, w;
    Q q;
    node *p;
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    q.insert(v);
    cout << "\n Visit "<< v;
    visited[v] = 1;
    while (!q.empty())
    {
        v = q.Delete();
        for (p = G[v]; p != NULL; p = p->next)
        {
            w = p->vertex;
            if (visited[w] == 0)
            {
                q.insert(w);
                visited[w] = 1;
                cout << "\n visit " << w;
            }
        }
    }
}

int main()
{
    int op, start, n;
    graph g1;
    do
    {
        cout << "\n\n1) Create a graph \n2) BFS \n3) DFS \n4) Quit";
        cout << "\nEnter Your Choice: ";
        cin >> op;
        switch (op)
        {
        case 1:
            g1.readgraph();
            break;
        case 2:
            cout << "\nEnter Starting Node: ";
            cin >> start;
            g1.BFS(start);
            break;
        case 3:
            cout << "\nEnter Starting Node: ";
            cin >> start;
            g1.DFS(start);
            break;
        }
    } while (op != 4);
    return 0;
}