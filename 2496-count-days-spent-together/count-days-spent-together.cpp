

class Solution {
private:
    int dateToDay(const string& date) {
        vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        
        int totalDays = day;
        for (int i = 0; i < month - 1; ++i) {
            totalDays += daysInMonth[i];
        }
        return totalDays;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int startAlice = dateToDay(arriveAlice);
        int endAlice = dateToDay(leaveAlice);
        int startBob = dateToDay(arriveBob);
        int endBob = dateToDay(leaveBob);

        int overlapStart = max(startAlice, startBob);
        int overlapEnd = min(endAlice, endBob);

        if (overlapStart <= overlapEnd) {
            return overlapEnd - overlapStart + 1;
        }
        return 0;
    }
};