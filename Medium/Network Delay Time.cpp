
// You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

// We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 

// Example 1:


// Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
// Output: 2
// Example 2:

// Input: times = [[1,2,1]], n = 2, k = 1
// Output: 1
// Example 3:

// Input: times = [[1,2,1]], n = 2, k = 2
// Output: -1
 

// Constraints:

// 1 <= k <= n <= 100
// 1 <= times.length <= 6000
// times[i].length == 3
// 1 <= ui, vi <= n
// ui != vi
// 0 <= wi <= 100
// All the pairs (ui, vi) are unique. (i.e., no multiple edges.)

class Solution {
public:
vector<pair<int,int>> adj[101];
    void dijkstra(vector<int>& signalReceivedAt, int source, int n){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
        pq.push({0,source});

        signalReceivedAt[source] = 0;

        while(!pq.empty()){
            int currNodeTime = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            if(currNodeTime>signalReceivedAt[currNode]){
                continue;
            }

            for(pair<int,int> edge: adj[currNode]){
                int time = edge.first;
                int neighborNode = edge.second;

                if(signalReceivedAt[neighborNode]>currNodeTime+time){
                    signalReceivedAt[neighborNode] = currNodeTime+time;
                    pq.push({signalReceivedAt[neighborNode], neighborNode});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        for(vector<int> time: times){
            int source = time[0];
            int dest = time[1];
            int travelTime = time[2];

            adj[source].push_back({travelTime, dest});
        }

        vector<int> signalReceivedAt(n+1, INT_MAX);
        dijkstra(signalReceivedAt, k, n);
        int answer = INT_MIN;

        for(int i =1; i<=n; i++){
            answer = max(answer, signalReceivedAt[i]);
        }

        return answer == INT_MAX? -1: answer; 

       


        
    }
};