using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class Interval {
public:
    int start = 0;
    int end = 0;

    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class MergeIntervals {
public:
    static vector<Interval> merge(vector<Interval> &intervals) {
        /*
         * sort the intervals into two vectors; starting and ending.
         * sort the two vectors
         * let i, j = 0, where i is the index of the first array and j is the index of the second array
         * let k, l = 0, be the starting and ending values of an interval
         * while i != start.size()
         *  take start[i], compare it to end[j];
         *      if start[i] < end[j]
         *          i++;
     *          else
         *          save start[k], end[j] as a new interval (add to a vector of intervals)
         *          i++
         *          set k = i,
         */
        // TODO: Write your code here
        vector<Interval> mergedIntervals;

        vector<int> start = vector<int>(intervals.size());
        vector<int> end = vector<int>(intervals.size());
        for(int i = 0; i < intervals.size(); i++) {
            start[i] = intervals[i].start;
            end[i] = intervals[i].end;
        }
        std::sort(start.begin(),start.end());
        std::sort(end.begin(),end.end());

        int i = 0;
        int j = 0;
        int k = 0;
        while(i < start.size()) {
            if (start[i] > end[j]){
                while(start[i] > end[j]) {
                    j++;
                }

                cout << "adding " << start[k] << " " << end[j-1] << endl;
                mergedIntervals.push_back(Interval{start[k],end[j-1]});
                k = i;
                j++;
            }
            i++;
        }
        mergedIntervals.push_back(Interval{start[k],end[j-1]});

        return mergedIntervals;
    }
};

int main(int argc, char *argv[]) {
    vector<Interval> input = {{1, 3}, {2, 5}, {7, 9}};
    cout << "Merged intervals: ";
    for (auto interval : MergeIntervals::merge(input)) {
        cout << "[" << interval.start << "," << interval.end << "] ";
    }
    cout << endl;

    input = {{6, 7}, {2, 4}, {5, 9}};
    cout << "Merged intervals: ";
    for (auto interval : MergeIntervals::merge(input)) {
        cout << "[" << interval.start << "," << interval.end << "] ";
    }
    cout << endl;

    input = {{1, 4}, {2, 6}, {3, 5}};
    cout << "Merged intervals: ";
    for (auto interval : MergeIntervals::merge(input)) {
        cout << "[" << interval.start << "," << interval.end << "] ";
    }
    cout << endl;
}
