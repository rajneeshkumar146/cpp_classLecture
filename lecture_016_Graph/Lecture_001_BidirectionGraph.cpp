#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Edge
{
public:
    int u = 0;
    int v = 0;
    int wt = 0;

    Edge(int u, int v, int wt)
    {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }

    friend ostream &operator<<(ostream &out, const Edge &c);
};

ostream &operator<<(ostream &out, const Edge &c)
{
    .
    
}

vector<vector<Edge *>> graph;

//Vertex.===========================================

void addVtx(int vtx)
{
    vector<Edge *> ve;
    graph.push_back(ve);
}

void removeVtx(int vtx)
{

    vector<Edge *> ve = graph[vtx];
    for (int i = 0; i < ve.size(); i++)
    {
        int vt = ve[i]->v;

        for (int j = 0; j < graph[vt].size(); j++)
        {
            if (graph[vt][j]->v == vtx)
            {
                graph[vt].erase(graph[vt].begin() + j);
                j--;
            }
        }
    }
    graph.erase(graph.begin() + vtx);
}

//Edges.========================================

int findEdgeIdx(int u, int v)
{
    int idx = -1;
    for (int i = 0; i < graph[u].size(); i++)
    {
        if (graph[u][i]->v == v)
        {
            idx = i;
            break;
        }
    }
    return idx;
}

void addEdge(int u, int v, int wt)
{
    graph[u].push_back(new Edge(u, v, wt));
    graph[v].push_back(new Edge(v, u, wt));
}

void removeEdge(int u, int v)
{
    int idx = findEdgeIdx(u, v);
    if (idx != -1)
        graph[u].erase(graph[u].begin() + idx);

    idx = findEdgeIdx(v, u);
    if (idx != -1)
        graph[v].erase(graph[v].begin() + idx);
}

// TraversingFunction.==============================================

void display()
{
    for (vector<Edge *> ve : graph)
    {
        cout << "[ ";
        for (Edge *e : ve)
            cout << *e << " ";
        cout << "]" << endl;
    }
}

bool hasPath(int u, int v, vector<bool> &isVisited)
{
    if (isVisited[u]) //IndetifyCyclePointInGraph.
        return false;
    if (u == v)
        return true;

    isVisited[u] = true;
    for (Edge *e : graph[u])
    {
        if (isVisited[e->v])
            continue;
        bool res = hasPath(e->v, v, isVisited);
        if (res)
            return res;
    }
    return false;
}

int printAllPath(int u, int v, vector<bool> isVisited, string psf)
{
    if (isVisited[u]) //IndetifyCyclePointInGraph.
        return 0;

    if (u == v)
    {
        cout << psf + to_string(u) << endl;
        return 1;
    }

    isVisited[u] = true;
    int res = 0;
    for (Edge *e : graph[u])
    {
        if (isVisited[e->v])
            continue;
        res += printAllPath(e->v, v, isVisited, psf + to_string(u) + " ");
    }

    isVisited[u] = false;
    return res;
}

//DFS_BFS.===========================================================

void BFS()
{
    struct pair
    {
        int vtx = 0;
        string psf = "";

        pair(int vtx, string psf)
        {
            this->vtx = vtx;
            this->psf = psf;
        }
    };

    string findString;
    int v = 6; //destination.

    queue<pair> que;
    vector<bool> isVisited(graph.size(), false);

    for (int i = 0; i < graph.size(); i++)
    {
        pair p(i, to_string(i) + " ");
        que.push(p);
        while (que.size() > 0)
        {
            pair proc = que.front();
            que.pop();

            if (isVisited[proc.vtx]) //IndetifyCyclePointInGraph.
                continue;

            isVisited[proc.vtx] = true;

            cout << proc.vtx << " via " << proc.psf << endl;
            if (proc.vtx == v)
                findString = proc.psf;

            for (Edge *e : graph[proc.vtx])
            {
                if (isVisited[e->v])
                    continue;

                pair np(e->v, proc.psf + to_string(e->v) + " ");
                que.push(np);
            }
        }
    }

    cout << "Ans: " << findString << endl;
}

void DFS()
{
    struct pair
    {
        int vtx = 0;
        string psf = "";

        pair(int vtx, string psf)
        {
            this->vtx = vtx;
            this->psf = psf;
        }
    };

    string findString;
    int v = 6; //destination.

    stack<pair> st;
    vector<bool> isVisited(graph.size(), false);

    for (int i = 0; i < graph.size(); i++)
    {
        pair p(i, to_string(i) + " ");
        st.push(p);
        while (st.size() > 0)
        {
        }
    }
}

void DFS_BFS()
{
    BFS();
}

void TraversingFunction()
{
    // display();

    vector<bool> isvisted(graph.size(), false);
    // cout << (boolalpha) << hasPath(2, 6, isvisted) << endl;
    cout << printAllPath(0, 6, isvisted, "") << endl;
}

//======================================================================

void construction()
{
    for (int i = 0; i < 7; i++)
        addVtx(i);

    addEdge(0, 1, 10);
    addEdge(1, 2, 10);
    addEdge(2, 3, 10);
    addEdge(3, 0, 40);
    addEdge(3, 4, 2);
    addEdge(4, 5, 3);
    addEdge(5, 6, 3);
    addEdge(6, 4, 8);
    addEdge(2, 5, 2);
}

void solve()
{
    construction();
    // TraversingFunction();
    DFS_BFS();
}

int main(int args, char **argc)
{
    solve();
    return 1;
}
