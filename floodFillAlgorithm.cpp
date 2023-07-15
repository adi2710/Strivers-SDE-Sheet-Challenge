void floodf(int r, int c, vector<vector<int>> &image, int color, int prev){
    if(r < 0 || r >= image.size() || c < 0 || c >= image[0].size() || image[r][c] != prev)
        return;
    prev = image[r][c];
    image[r][c] = color;
    floodf(r - 1, c, image, color, prev);
    floodf(r + 1, c, image, color, prev);
    floodf(r, c - 1, image, color, prev);
    floodf(r, c + 1, image, color, prev);
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    if(image[sr][sc] == color)
        return image;
    floodf(sr, sc, image, color, image[sr][sc]);
    return image;
}