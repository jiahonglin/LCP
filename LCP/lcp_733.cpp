class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> visited(image.size(),vector<int> (image[0].size(), 0));
        int startVal = image[sr][sc];
        doflood(image, sr, sc, newColor, startVal, visited);
        return image;
    }

    void doflood(vector<vector<int>>& image, int sr, int sc, int newColor, int startVal,vector<vector<int>>& visited){
        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size() || visited[sr][sc]==1) return;
        if(image[sr][sc] == startVal){
            visited[sr][sc]=1;
            doflood(image,sr-1,sc,newColor,startVal,visited);
            doflood(image,sr+1,sc,newColor,startVal, visited);
            doflood(image,sr,sc-1,newColor,startVal, visited);
            doflood(image,sr,sc+1,newColor,startVal, visited);
            image[sr][sc] = newColor;
        }
        return;
    }
};
