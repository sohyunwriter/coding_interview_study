import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    static class Point implements Comparable<Point>{
        int x, y;

        Point(int x, int y) {
            this.x = x;     // 도착점
            this.y = y;     // 비용       
        }

        @Override
        public int compareTo(Point o) {     
            // TODO Auto-generated method stub
            return this.y - o.y;
        }
    }

    static boolean[] visited;   
    static List<Point> list[];
    static int[] value;
    static PriorityQueue<Point> pq = new PriorityQueue<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int V = sc.nextInt();  
        int E = sc.nextInt();   
        int K = sc.nextInt();   

        list = new ArrayList[V+1];

        value = new int[V+1];
        visited = new boolean[V+1];
        Arrays.fill(value, Integer.MAX_VALUE); 
        value[K]=0;

        for(int i=0;i<=V;i++) {
            list[i] = new ArrayList<>();
        }

        // 인접 리스트
        for(int i=0;i<E;i++) {
            int a = sc.nextInt();  
            int b = sc.nextInt();  
            int c = sc.nextInt();  
            list[a].add(new Point(b,c));
        }
        pq.add(new Point(K,0));    
        solve(K);
        for(int i=1;i<=V;i++) {
            System.out.println(value[i]==Integer.MAX_VALUE?"INF":value[i]);    
        }
    }

    static void solve(int k) {
        while(!pq.isEmpty()) {
            int now = pq.poll().x;     
            if(visited[now]) continue;  
            visited[now]=true;         

            for(Point i:list[now]) {  
                if(value[i.x] > value[now]+i.y) {              
                    value[i.x] = value[now]+i.y;
                    pq.add(new Point(i.x,value[i.x]));
                }
            }

        }

    }
}
