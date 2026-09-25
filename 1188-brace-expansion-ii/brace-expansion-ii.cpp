#include <vector>
#include <string>
#include <set>
#include <stack>
#include <utility>

using namespace std;

class Solution {
private:
    // Helper function to perform Cartesian Product of two string sets
    set<string> multiply(const set<string>& set1, const set<string>& set2) {
        set<string> result;
        for (const string& s1 : set1) {
            for (const string& s2 : set2) {
                result.insert(s1 + s2);
            }
        }
        return result;
    }

public:
    vector<string> braceExpansionII(string expression) {
      
        stack<pair<set<string>, set<string>>> st;
        
        set<string> res_sum;
        set<string> res_prod = {""};

        for (char c : expression) {
            if (isalpha(c)) {
              
                string s(1, c);
                res_prod = multiply(res_prod, {s});
            } 
            else if (c == '{') {
               
                st.push({res_sum, res_prod});
                res_sum.clear();
                res_prod = {""};
            } 
            else if (c == ',') {
              
                res_sum.insert(res_prod.begin(), res_prod.end());
                res_prod = {""};
            } 
            else if (c == '}') {
               
                set<string> inner_total = res_sum;
                inner_total.insert(res_prod.begin(), res_prod.end());

                auto [prev_sum, prev_prod] = st.top();
                st.pop();

                res_sum = prev_sum;
                res_prod = multiply(prev_prod, inner_total);
            }
        }

       
        set<string> final_set = res_sum;
        final_set.insert(res_prod.begin(), res_prod.end());

 
        return vector<string>(final_set.begin(), final_set.end());
    }
};