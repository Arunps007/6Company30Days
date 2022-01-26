class Solution {
public:
void helper(int node,vector<vector>connected,vector&visited)
{
visited[node]=true;
for(int i=0;i<connected.size();i++)
{
if(connected[node][i]==1 && visited[i]==false)
{
helper(i,connected,visited);
}
}
}
int findCircleNum(vector<vector>& connected) {
vectorvisited(connected.size(),0);
int count=0;
for(int i=0;i<connected.size();i++)
{
if(visited[i]==false)
{
helper(i,connected,visited);
count++;
}
}

    return count;
}
};