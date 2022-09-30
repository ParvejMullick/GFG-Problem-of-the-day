class Solution {
  public:
    void bfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& visited,vector<pair<int,int>>& ans)
   {
       visited[i][j]=true;
       int n=grid.size();
       int m=grid[0].size();
       vector<vector<int>> direction={{0,1},{1,0},{0,-1},{-1,0}};
       queue<pair<int,int>> q;
       q.push({i,j});
       while(q.empty()==false)
       {
           auto temp=q.front();
           q.pop();
           int r=temp.first;
           int c=temp.second;
           ans.push_back({i-r,j-c}); // store distance between two cells
           for(int i=0;i<direction.size();i++)
           {
               int nr=direction[i][0]+r;
               int nc=direction[i][1]+c;
               if(nr>=0 && nr<n && nc>=0 &&  nc<m && grid[nr][nc]==1 && visited[nr][nc]==false)
               {
                   visited[nr][nc]=true;
                   q.push({nr,nc});
               }
           }
       }
   }
   int countDistinctIslands(vector<vector<int>>& grid) {
       // code here
       int n=grid.size();
       int m=grid[0].size();
       set<vector<pair<int,int>>> s; // because set store unique value
       vector<vector<bool>> visited(n,vector<bool>(m,false)); // mark all false in matrix
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(grid[i][j]==1 && visited[i][j]==false)
               {
                   vector<pair<int,int>> ans;
                   bfs(i,j,grid,visited,ans);
                   s.insert(ans);// store only unique values provided by ans 
                   ans.clear();
               }
           }
       }
       return s.size();
       
   }
};