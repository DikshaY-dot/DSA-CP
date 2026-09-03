class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target,
                    vector<vector<int>>& specialRoads) {

        int n = specialRoads.size();

        /*
            dist[i] = minimum cost required to reach
                      the starting point of special road i.

            We use Dijkstra's algorithm because the graph
            has only non-negative edge weights.
        */
        vector<int> dist(n, INT_MAX);

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        /*
            Direct Manhattan distance from start to target.
            This is our initial answer because we can completely
            ignore all special roads.
        */
        int ans = abs(start[0] - target[0]) +
                  abs(start[1] - target[1]);

        /*
            Initially, we can reach the starting point of every
            special road directly from the starting position.
        */
        for (int i = 0; i < n; i++) {

            int x1 = specialRoads[i][0];
            int y1 = specialRoads[i][1];

            int d = abs(start[0] - x1) +
                    abs(start[1] - y1);

            dist[i] = d;
            pq.push({d, i});
        }

        /*
            Apply Dijkstra's algorithm.

            Each special road represents a state.
            From the end of one special road, we can:
              1. Go to the target directly.
              2. Go to the starting point of another special road.
        */
        while (!pq.empty()) {

            auto [cost, i] = pq.top();
            pq.pop();

            // Ignore outdated priority queue entries.
            if (cost != dist[i])
                continue;

            int x1 = specialRoads[i][0];
            int y1 = specialRoads[i][1];
            int x2 = specialRoads[i][2];
            int y2 = specialRoads[i][3];
            int roadCost = specialRoads[i][4];

            /*
                Taking the special road is useful only if its
                given cost is cheaper than simply walking between
                its endpoints using Manhattan distance.
            */
            int currentCost = cost + min(
                roadCost,
                abs(x1 - x2) + abs(y1 - y2)
            );

            /*
                Option 1:
                After using this special road, directly travel
                from its endpoint to the target.
            */
            ans = min(
                ans,
                currentCost +
                abs(x2 - target[0]) +
                abs(y2 - target[1])
            );

            /*
                Option 2:
                Travel from the current road's endpoint to the
                starting point of every other special road.
            */
            for (int j = 0; j < n; j++) {

                int nx = specialRoads[j][0];
                int ny = specialRoads[j][1];

                int newCost =
                    currentCost +
                    abs(x2 - nx) +
                    abs(y2 - ny);

                if (newCost < dist[j]) {

                    dist[j] = newCost;
                    pq.push({newCost, j});
                }
            }
        }

        return ans;
    }
};
