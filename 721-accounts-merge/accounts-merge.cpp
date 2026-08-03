class DisjointSet{
    vector<int> rank,size,parent;
    public : 
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        // Create DSU for all account indices
        DisjointSet ds(n);

        // Maps an email to the first account index where it appeared
        unordered_map<string, int> mailToNode;

        // Traverse every account
        for (int i = 0; i < n; i++) {

            // Skip account name (starts from index 1)
            for (int j = 1; j < accounts[i].size(); j++) {

                string mail = accounts[i][j];

                // First time seeing this email
                if (mailToNode.find(mail) == mailToNode.end()) {
                    mailToNode[mail] = i;
                }
                else {
                    // Same email already exists
                    // Merge both account indices
                    ds.unionBySize(i, mailToNode[mail]);
                }
            }
        }

        // Stores emails grouped by their ultimate parent
        vector<vector<string>> mergedMail(n);

        for (auto it : mailToNode) {

            string mail = it.first;
            int node = it.second;

            // Find representative account
            int parent = ds.findUPar(node);

            mergedMail[parent].push_back(mail);
        }

        vector<vector<string>> ans;

        // Build final answer
        for (int i = 0; i < n; i++) {

            if (mergedMail[i].empty())
                continue;

            // Emails must be sorted
            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;

            // Account name
            temp.push_back(accounts[i][0]);

            // Add all emails
            for (string &mail : mergedMail[i])
                temp.push_back(mail);

            ans.push_back(temp);
        }

        return ans;
    }
};