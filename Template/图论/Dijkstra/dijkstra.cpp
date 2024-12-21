struct edge {
    int v, w;
};
vector<edge> adj[150005];
int dist[150005];
bool st[150005];

void dijstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.emplace(0, 1);

    while (!q.empty()) {
        auto [d, u] = q.top(); q.pop();
        if (st[u]) continue;
        st[u] = true;
        for (auto [v, w] : adj[u]) {
            if (d + w < dist[v]) {
                dist[v] = d + w;
                q.emplace(dist[v], v);
            }
        }
    }
}
// Judge：(dist[n] == 0x3f3f3f3f ? -1 : dist[n])
