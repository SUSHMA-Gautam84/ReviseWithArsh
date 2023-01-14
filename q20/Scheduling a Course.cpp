class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //create an adjacency list
        unordered_map<int,list<int>> adj;
        for(int i = 0 ; i < prerequisites.size() ; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].push_back(v);
        }

        //step 1 : find indegree for each node
        vector<int> indegree(numCourses);
        
        for(auto i : adj){
            for(auto j : i.second){
                indegree[j]++;
            }
        }

        //step 2 : add elements with indegree = 0 to a queue
        queue<int> q;
        for(int i = 0 ; i < numCourses ; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;
        //step 3 : apply BFS
        while(!q.empty()){
            int front = q.front();
            q.pop();

            ans.push_back(front);

            //update indegree of the neighbours
            for(auto i : adj[front]){
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
        }

        //step 4 : Finally if indegree all the nodes = 0, then return true.
        if(ans.size() == numCourses)
            return true;
        else
            return false;
    }
};
