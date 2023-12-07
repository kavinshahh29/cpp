#include<bits/stdc++.h>
using namespace std;
 vector<vector<int>> floodFill(vector<vector<int>>& im, int sr, int sc, int newColor) {
        
        vector<vector<bool>>visit(im.size(),vector<bool>(im[0].size(),false));
        vector<vector<int>>image=im;
        dfs(sr,sc,image,newColor,visit,image[sr][sc]);
        return image;
    }
    void dfs(int row,int col,vector<vector<int>>&image,int newcolor,vector<vector<bool>>&visit,int color)
    {
        visit[row][col]=true;
        image[row][col]=newcolor;
        int rowmatrix[]={0,-1,0,1};
        int colmatrix[]={-1,0,1,0};
        for(int i=0;i<4;i++)
        {
            int rowin=row+rowmatrix[i];
            int colin=col+colmatrix[i];
            if(rowin>=0 and rowin<image.size() and colin>=0 and colin<image[0].size() and visit[rowin][colin]==false and image[rowin][colin]==color)
            {
                dfs(rowin,colin,image,newcolor,visit,color);
            }
        }
    }

    