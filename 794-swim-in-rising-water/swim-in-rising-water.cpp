class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        // Size of the square grid
        int n = grid.size();

        // Directions for moving Up, Right, Down, Left
        vector<pair<int,int>> dir = {
            {-1,0},
            {0,1},
            {1,0},
            {0,-1}
        };

        /*
            Priority Queue (Min Heap)

            Stores:
            {time required to reach this cell,
             {row, column}}

            We always process the cell having
            the minimum required time first.
        */
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        /*
            visited[r][c] tells whether we have already
            inserted this cell into the priority queue.

            Since the first time we push a cell into the
            min heap is with its minimum possible time,
            we don't need to process it again.
        */
        vector<vector<bool>> visited(n, vector<bool>(n,false));

        // Start from top-left corner.
        // Initial time equals its elevation.
        pq.push({grid[0][0], {0,0}});
        visited[0][0] = true;

        while(!pq.empty()){

            // Cell having minimum current required time
            auto current = pq.top();
            pq.pop();

            int time = current.first;
            int row = current.second.first;
            int col = current.second.second;

            // Destination reached
            // Since this is Dijkstra,
            // first time reaching destination is optimal.
            if(row == n-1 && col == n-1)
                return time;

            // Explore all 4 neighbours
            for(auto d : dir){

                int newRow = row + d.first;
                int newCol = col + d.second;

                // Skip if outside the grid
                if(newRow < 0 || newCol < 0 ||
                   newRow >= n || newCol >= n)
                    continue;

                // Skip already visited cells
                if(visited[newRow][newCol])
                    continue;

                /*
                    Time needed to enter neighbour

                    Current path already needs 'time'.

                    If neighbour's elevation is higher,
                    we must wait until that level.

                    Therefore

                    newTime =
                    max(current path time,
                        neighbour elevation)
                */
                int newTime = max(time, grid[newRow][newCol]);

                // Push neighbour into min heap
                pq.push({newTime, {newRow,newCol}});

                // Mark visited
                visited[newRow][newCol] = true;
            }
        }

        // Problem guarantees an answer,
        // so this line is never reached.
        return -1;
    }
};