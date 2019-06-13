#include <iostream>
#include <vector>
#include <queue>

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
    out << "(" + to_string(c.u) + ", " + to_string(c.v) + ", " + to_string(c.wt) + "), ";
    return out;
}

vector<vector<Edge *>> graph;

//Vertex.===========================================

void addVertexCollection(int totalVertex)
{
    for (int i = 0; i <= totalVertex; i++)
    {
        vector<Edge *> vec;
        graph.push_back(vec);
    }
}

void addVertex(int u)
{
    if (graph.size() >= u)
    {
        vector<Edge *> vec;
        graph.push_back(vec);
    }
}

void removeVertex(int u)
{
    if (u >= graph.size())
        return;

    for (int i = 0; i < graph[u].size(); i++)
    {
        int vt = graph[u][i]->v;

        for (int j = 0; j < graph[vt].size(); j++)
        {
            if (graph[vt][j]->v == u)
            {
                graph[vt].erase(graph[vt].begin() + j);
                j--;
            }
        }
    }
    graph.erase(graph.begin() + u);
}

//Edge.===========================================

void addEdge(int u, int v, int wtx)
{
    if (u >= graph.size() || v >= graph.size())
        return;

    graph[u].push_back(new Edge(u, v, wtx));
    graph[v].push_back(new Edge(v, u, wtx));
}

int findEdgeIndex(int u, int v)
{
    for (int i = 0; i < graph[u].size(); i++)
    {
        if (graph[u][i]->v == v)
        {
            return i;
        }
    }
    return -1;
}

void removeEdge(int u, int v)
{

    if (u >= graph.size() || v >= graph.size())
        return;

    int index = findEdgeIndex(u, v);
    if (index == -1)
        return;
    graph[u].erase(graph[u].begin() + index);

    index = findEdgeIndex(v, u);
    graph[v].erase(graph[v].begin() + index);
}

// TraversingFunction.==============================================

void display()
{

    for (vector<Edge *> keys : graph)
    {
        cout << "[";
        for (Edge *e : keys)
        {
            cout << *e;
        }
        cout << "]" << endl;
    }
}

bool hasPath(int u, int v, vector<bool> &isVisited)
{
    if (isVisited[u])
        return false;
    if (u == v)
        return true;

    isVisited[u] = true;
    for (Edge *e : graph[u])
    {
        if (!isVisited[e->v] && hasPath(e->v, v, isVisited))
            return true;
    }

    return false;
}

int printAllPath(int u, int v, vector<bool> isVisited, string psf)
{
    if (isVisited[u])
        return 0;
    if (u == v)
    {
        cout << psf << endl;
        return 1;
    }
  
    isVisited[u] = true;
    int res = 0;

    for (Edge *e : graph[u])
    {
        if (isVisited[e->v])
            continue;

        res += printAllPath(e->v, v, isVisited, psf + "->" + to_string(e->v));
    }

    isVisited[u] = false;
    return res;
}

//BFS_DFS

void BFS()
{
    struct pair
    {
        int v;
        string psf;
        pair(int v, string psf)
        {
            this->v = v;
            this->psf = psf;
        }
    };

    vector<bool> isVisited(graph.size(), false);
    queue<pair> q;

    int v = 6;
    string findString;

    for (int i = 0; i < graph.size(); i++)
    {
        if (isVisited[i])
            continue;

        pair p(i, to_string(i) + "->");
        q.push(p);

        while (q.size() != 0)
        {
            pair curr = q.front();
            q.pop();

            if (isVisited[curr.v]) //IndetifyCyclePointInGraph.
                continue;
            isVisited[curr.v] = true;
            cout << to_string(curr.v) + " via " + curr.psf << endl;

            if (curr.v == v)
            {
            }
        }
    }
}

void TraversingFunction()
{
    // display();

    vector<bool> isvisted(graph.size(), false);
    // cout << (boolalpha) << hasPath(2, 6, isvisted) << endl;
    cout << printAllPath(0, 6, isvisted, to_string(0)) << endl;
}

void construction()
{
    addVertexCollection(6);

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
    TraversingFunction();
}

int main(int args, char **argc)
{
    solve();
    return 1;
}