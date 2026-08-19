#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reservedMap;
        
        // Define masks for seats 2..9 mapped to bits 0..7
        int leftMask = 0b00001111;   // seats 2, 3, 4, 5
        int middleMask = 0b00111100; // seats 4, 5, 6, 7
        int rightMask = 0b11110000;  // seats 6, 7, 8, 9

        // Populating the bitmask for rows with active reservations
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (col >= 2 && col <= 9) {
                reservedMap[row] |= (1 << (col - 2));
            }
        }

        int maxGroups = 0;

        // Process only rows containing reservations in seats 2..9
        for (const auto& [row, reserved] : reservedMap) {
            bool canLeft = (reserved & leftMask) == 0;
            bool canRight = (reserved & rightMask) == 0;
            bool canMiddle = (reserved & middleMask) == 0;

            if (canLeft && canRight) {
                maxGroups += 2;
            } else if (canLeft || canRight || canMiddle) {
                maxGroups += 1;
            }
        }

        // Add 2 groups for each completely unreserved row
        int unreservedRows = n - reservedMap.size();
        maxGroups += unreservedRows * 2;

        return maxGroups;
    }
};