class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
          int ans = 0, n = points.size();
        unordered_map <long long int, int> numOfPointsAtDist; 
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i == j) continue;
                
                long long int dist = pow((points[i][0] - points[j][0]),2) + pow((points[i][1] - points[j][1]),2);
                numOfPointsAtDist[dist]++;
            }
            unordered_map <long long int, int>::iterator it;
            for(it = numOfPointsAtDist.begin(); it != numOfPointsAtDist.end(); ++it)
            {
                int k = it->second;
                if(k < 2) continue;
                else ans += (k * (k-1)); 
            }
            
            numOfPointsAtDist.clear();
        }
        
        return ans;
    }
};
