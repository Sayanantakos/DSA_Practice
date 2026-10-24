#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    const vector<int> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int dateToDayOfYear(const string& date) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        int dayOfYear = day;
        for (int i = 0; i < month - 1; ++i) {
            dayOfYear += daysInMonths[i];
        }

        return dayOfYear;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int startAlice = dateToDayOfYear(arriveAlice);
        int endAlice = dateToDayOfYear(leaveAlice);
        int startBob = dateToDayOfYear(arriveBob);
        int endBob = dateToDayOfYear(leaveBob);

        int startTogether = max(startAlice, startBob);
        int endTogether = min(endAlice, endBob);

        return max(0, endTogether - startTogether + 1);
    }
};