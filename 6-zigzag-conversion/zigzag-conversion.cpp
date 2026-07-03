class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || s.length() <= numRows) {
            return s;
        }
        
        vector<string> rows(min(numRows, (int)s.length()));
        int currRow = 0;
        bool goingDown = false;
        
        for (char c : s) {
            rows[currRow] += c;
            if (currRow == 0 || currRow == numRows - 1) {
                goingDown = !goingDown;
            }
            currRow += goingDown ? 1 : -1;
        }
        
        string res = "";
        for (string row : rows) {
            res += row;
        }
        
        return res;
    }
};

/* ================================================================================
SHORT GITHUB SOLUTION SUMMARY:
================================================================================
- An array of strings handles sorting characters into their respective horizontal rows.
- A directional tracker flag ('goingDown') flips whenever the index hits the topmost or bottommost row.
- The pointer steps down or bounces back up sequentially, adding characters dynamically where they land.
- All distinct row strings are concatenated linearly at the end to assemble the final zigzag sequence.
*/