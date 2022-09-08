bool vis[maxx][maxx];
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


void dfs(int srcX, int srcY)
{
    stack<pair<int, int> > st;
    st.push(make_pair(srcX, srcY));
    while (!st.empty()) 
    {
        pair<int, int> curr = st.top();
        st.pop();
        int row = curr.first;
        int col = curr.second;
        if (!isValid(row, col))
            continue;

        vis[row][col] = true;
       // cnt++;

       for (int i = 0; i < 4; i++)
        {
            int adjx = row + dirx[i];
            int adjy = col + diry[i];
            st.push({ adjx, adjy });
        }
    }
}


