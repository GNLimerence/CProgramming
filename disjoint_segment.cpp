/*
Given a set of segments X = {(a1, b1), . . . , (an, bn)} 
in which ai < bi are coordinates of the segment i on a line, i = 1, …, n.  
Find a subset of X having largest cardinality in which no two segments of the 
subset intersect
Input
Line 1: contains a positive integer n (1 <= n <= 100000)
Line i+1 (i= 1,...,n): contains ai and bi (0 <= ai <= bi <= 1000000)
Output
Number of segments in the solution found.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 100000;
int n;
int ans = 1;
struct Segment {
    int start, end;
    //sort the vector by their end point
    bool operator < (const Segment& other) const {
        return end < other.end;
    }
};
void solve(){
    //Input:
    cin >> n;
    vector<Segment> segment(n);
    for(int i = 0; i < n; i++){
        cin >> segment[i].start >> segment[i].end;
    }
    //Sort the segment by its end point 
    sort(segment.begin(),segment.end());
    /*for(int i = 0; i < n; i++){
        cout << segment[i].start << " " << segment[i].end << endl;
    } */   
    //update the current end point to the end point of the first segment
    int current_end = segment[0].end;
    for(int i = 0; i < n; i++){
        if(segment[i].start > current_end){
            current_end = segment[i].end;
            ans++;
        }
    }
    cout << ans << endl;
}
int main(){
    solve();
    return 0;
}