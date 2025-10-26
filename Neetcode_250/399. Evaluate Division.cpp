class Solution {
public:
    unordered_map<string,string > parent;
    unordered_map<string,double> weight;

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int NumEquations = equations.size();

        for(const auto& equation : equations){
            parent[equation[0]] = equation[0];
            parent[equation[1]] = equation[1];
            weight[equation[0]] = 1.0;
            weight[equation[1]] = 1.0;
        }

        for(int i = 0; i < NumEquations; i++){
            vector<string> equation = equations[i];
            string numerator = equation[0]; 
            string denominator = equation[1];

            string parentNumerator = find(numerator);
            string parentDenominator = find(denominator);

            if(parentNumerator == parentDenominator) continue;

            parent[parentNumerator] = parentDenominator;

            weight[parentNumerator] = weight[denominator] * values[i] / weight[numerator];
        }
        int numQueries = queries.size();
        vector<double> results(numQueries);

        for(int i = 0; i < numQueries; i++){
            string dividend = queries[i][0];    
            string divisor = queries[i][1];

            if (parent.find(dividend) == parent.end() || 
                parent.find(divisor) == parent.end() || 
                find(dividend) != find(divisor)) {
                results[i] = -1.0;
            } else {
                results[i] = weight[dividend] / weight[divisor];
            }
        }
        return results;
    }
    string find(string vairable){
        if(parent[vairable] != vairable){
            string originalParent = parent[vairable];
            parent[vairable] = find(parent[vairable]);
            weight[vairable] *= weight[originalParent];
        }
        return parent[vairable];
    }
};