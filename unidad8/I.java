import java.util.*;
//NOT MY CODE
public class I {

    static final double INF = 1e18;

    static class Edge {
        int to;
        double w;

        Edge(int to, double w) {
            this.to = to;
            this.w = w;
        }
    }

    public static double[] dijkstra(ArrayList<ArrayList<Edge>> grafo, int start) {

        int n = grafo.size();
        double[] dist = new double[n];
        Arrays.fill(dist, INF);
        PriorityQueue<double[]> pq = new PriorityQueue<>(
            (a, b) -> Double.compare(a[1], b[1])
        );
        dist[start] = 0;
        pq.add(new double[]{start, 0});

        while (!pq.isEmpty()) {

            double[] current = pq.poll();
            int nodo = (int) current[0];
            double d = current[1];

            if (d != dist[nodo]) continue;

            for (Edge e : grafo.get(nodo)) {

                double nd = d + e.w;

                if (nd < dist[e.to]) {
                    dist[e.to] = nd;
                    pq.add(new double[]{e.to, nd});
                }
            }
        }

        return dist;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        sc.useLocale(Locale.US);

        int nodos = sc.nextInt();
        int aristas = sc.nextInt();
        double d = sc.nextDouble();

        String inicioTomas = sc.next();
        String inicioDani = sc.next();

        String[] nombres = new String[nodos];
        HashMap<String, Integer> map = new HashMap<>();

        for (int i = 0; i < nodos; i++) {
            nombres[i] = sc.next();
            map.put(nombres[i], i);
        }

        ArrayList<ArrayList<Edge>> grafo = new ArrayList<>();
        for (int i = 0; i < nodos; i++) {
            grafo.add(new ArrayList<>());
        }

        for (int i = 0; i < aristas; i++) {
            String u = sc.next();
            String v = sc.next();
            double w = sc.nextDouble();

            int a = map.get(u);
            int b = map.get(v);

            grafo.get(a).add(new Edge(b, w));
            grafo.get(b).add(new Edge(a, w));
        }

        int tomas = map.get(inicioTomas);
        int dani = map.get(inicioDani);

        double[] distT = dijkstra(grafo, tomas);
        double[] distD = dijkstra(grafo, dani);

        ArrayList<String> resultado = new ArrayList<>();

        for (int i = 0; i < nodos; i++) {
            if (distT[i] <= distD[i] + d + 1e-9 &&
                distD[i] <= distT[i] + d + 1e-9) {

                resultado.add(nombres[i]);
            }
        }

        Collections.sort(resultado);

        System.out.println(resultado.size());
        for (String s : resultado) {
            System.out.println(s);
        }

        sc.close();
    }
}