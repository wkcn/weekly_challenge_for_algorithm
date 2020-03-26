class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        const int rows = image.size();
        if (rows == 0) return image;
        const int cols = image[0].size();
        if (cols == 0) return image;
        if (image[sr][sc] == newColor) return image;
        int oldColor = image[sr][sc];
        queue<pair<int, int> > q;
        q.push({sr, sc});
        image[sr][sc] = newColor;
        
        auto go = [&](unsigned int r, unsigned int c) {
          if (r < rows && c < cols) {
              if (image[r][c] == oldColor) {
                  image[r][c] = newColor;
                  q.push({r, c});
              }
          }  
        };
        
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            go(p.first+1, p.second);
            go(p.first-1, p.second);
            go(p.first, p.second+1);
            go(p.first, p.second-1);
        }
        return image;
    }
};
