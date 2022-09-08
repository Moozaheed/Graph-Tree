bool vis[maxx][maxx];
int dist[maxx][maxx];
int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
int diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };

bool isValid(int row, int col)
{
    if (row < 0 || col < 0 || row >= ROW || col >= COL)
        return false;
    if (vis[row][col])
        return false;
    return true;
}
void bfs(int srcX, int srcY)
{
    queue<pair<int, int> > q;
    q.push(make_pair(srcX, srcY));
    dist[srcX][srcY]=0;
    vis[srcX][srcY]=1;
    
    //if(srcX==tarX && srcY==tarY)return;

    while (!q.empty()) 
    {
        pair<int, int> curr = q.front();
        q.pop();

        int row = curr.first;
        int col = curr.second;

       for (int i = 0; i < 8; i++)
        if(isValid(row+dirx[i],col+diry[i]))
        {
            int adjx = row + dirx[i];
            int adjy = col + diry[i];

            dist[adjx][adjy]=dist[row][col]+1;
            vis[adjx][adjy]=1;

            q.push({ adjx, adjy });
        }
    }
}
