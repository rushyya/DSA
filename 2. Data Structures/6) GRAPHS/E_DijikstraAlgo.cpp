#include <iostream>
#include <climits>
#include <set>
#include <vector>

using namespace std;

vector<int> shortest_path(int n, vector<pair<int, int>> adj[], int src)
{ // src is the starting/source node
    vector<int> dist(n + 1, INT_MAX);
    set<pair<int, int>> st;

    dist[src] = 0;

    st.insert({dist[src], src});

    while (!st.empty())
    {//set stores value in sorted order(very imp point so that we are just using begin operator in each iteration)
        pair<int, int> node = *st.begin();
        st.erase(st.begin());

        for (auto it : adj[node.second])
        {
            if (node.first + it.second < dist[it.first])
            {
                dist[it.first] = node.first + it.second;
                st.insert({dist[it.first], it.first});
            }
        }
    }

    return dist;
}

int main()
{
    int n, m, src;
    cin >> n >> m >> src;

    vector<pair<int, int>> adj[n + 1];

    while (m--)
    {
        int x, y, w;
        cin >> x >> y >> w;

        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    vector<int> ans = shortest_path(n, adj, src);

    for (int i = 1; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}