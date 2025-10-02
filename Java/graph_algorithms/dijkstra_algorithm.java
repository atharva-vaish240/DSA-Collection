import java.util.*;

public class dijkstra_algorithm {
    static class Node implements Comparable<Node> {
        int vertex;
        int distance;
        
        Node(int vertex, int distance) {
            this.vertex = vertex;
            this.distance = distance;
        }
        
        public int compareTo(Node other) {
            return Integer.compare(this.distance, other.distance);
        }
    }
    
    public static void dijkstra(ArrayList<ArrayList<Node>> adj, int V, int source) {
        int[] distance = new int[V];
        Arrays.fill(distance, Integer.MAX_VALUE);
        distance[source] = 0;
        
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(source, 0));
        
        while (!pq.isEmpty()) {
            Node current = pq.poll();
            
            for (Node neighbor : adj.get(current.vertex)) {
                if (distance[current.vertex] + neighbor.distance < distance[neighbor.vertex]) {
                    distance[neighbor.vertex] = distance[current.vertex] + neighbor.distance;
                    pq.add(new Node(neighbor.vertex, distance[neighbor.vertex]));
                }
            }
        }
        
        for (int i = 0; i < V; i++) {
            System.out.println("Distance from source to " + i + " is " + distance[i]);
        }
    }
    
    public static void main(String[] args) {
        int V = 5;
        ArrayList<ArrayList<Node>> adj = new ArrayList<>();
        
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }
        
        adj.get(0).add(new Node(1, 4));
        adj.get(0).add(new Node(2, 1));
        adj.get(1).add(new Node(3, 1));
        adj.get(2).add(new Node(1, 2));
        adj.get(2).add(new Node(3, 5));
        adj.get(3).add(new Node(4, 3));
        
        dijkstra(adj, V, 0);
    }
}