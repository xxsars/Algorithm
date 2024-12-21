void floyd() {
    for (int k = 1; k <= n; k ++ )
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
// Init:
for (int i = 1; i <= n; i ++ ) for (int j = 1; j <= n; j ++ )
    if (i == j) d[i][j] = 0;
	else d[i][j] = INF;
// Judge:
d[a][b] if d[a][b] <= INF / 2 else "possbile"
