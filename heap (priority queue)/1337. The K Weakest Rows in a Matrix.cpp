// maxheap
// O(n^2) + O(2n)
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>> maxh;
        vector<int> res;
        
        for(int i = 0; i < mat.size(); i++) {
            int counts = 0;
            for(int j = 0; j < mat[i].size(); j++) {
                if(mat[i][j] == 1) counts++;
            }
            maxh.push({counts, i});
            if(maxh.size() > k) maxh.pop();
        }
        
        while(!maxh.empty()) {
            int row = maxh.top().second;
            maxh.pop();
            res.push_back(row);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// minheap
// O(n^2) + O(n)
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> maxh;
        vector<int> res;
        
        for(int i = 0; i < mat.size(); i++) {
            int counts = 0;
            for(int j = 0; j < mat[i].size(); j++) {
                if(mat[i][j] == 1) counts++;
            }
            maxh.push({counts, i});
        }
        
        while(k--) {
            int row = maxh.top().second;
            maxh.pop();
            res.push_back(row);
        }
        return res;
    }
};

// efficient - count using binary search
// O(nlogn) + O(n)
class Solution {
public:
    int calculateSoldiers(vector<int>& v) {
        int l = 0, h = v.size()-1;
        while(l <= h) {
            int mid = l + (h-l)/2;
            if(v[mid] == 0) h = mid-1;
            else l = mid+1;
        }
        return l;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> maxh;
        vector<int> res;
        
        for(int i = 0; i < mat.size(); i++) {
            maxh.push({calculateSoldiers(mat[i]), i});
        }
        
        while(k--) {
            int row = maxh.top().second;
            maxh.pop();
            res.push_back(row);
        }
        return res;
    }
};