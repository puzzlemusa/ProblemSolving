package LeetCode;


public class FloodFill {

    public static void main(String[] args) {

        System.out.println(floodFill(new int[][]{{1,1,1},{1,1,0},{1,0,1}}, 1, 1, 2));
        System.out.println(floodFill(new int[][]{{0,0,0},{0,0,0}}, 0, 0, 0));
    }

    public static int[][] floodFill(int[][] image, int sr, int sc, int color) {
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }

    public static void dfs(int[][] image, int sr, int sc, int color, int sourceColor){
        image[sr][sc] = color;
        if(sc>0 && sourceColor == image[sr][sc-1] && color != image[sr][sc-1])
            floodFill(image, sr, sc-1, color);
        if(sc<image[sr].length-1 && sourceColor == image[sr][sc+1] && color != image[sr][sc+1])
            floodFill(image, sr, sc+1, color);
        if(sr>0 && sourceColor == image[sr-1][sc] && color != image[sr-1][sc])
            floodFill(image, sr-1, sc, color);
        if(sr<image.length-1 && sourceColor == image[sr+1][sc] && color != image[sr+1][sc])
            floodFill(image, sr+1, sc, color);
    }
}
