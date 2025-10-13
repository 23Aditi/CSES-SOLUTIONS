#include <bits/stdc++.h>
using namespace std;

/*
This program solves the "Traffic Lights" problem from CSES, where we want to find the length
of the longest segment of a street without traffic lights after each new light is added.

Explanation:

1. Inputs:
   - x: Length of the street.
   - n: Number of traffic lights to be added.
   - y (loop input): Position of each new traffic light.

2. Data Structures:
   - `multiset<int> lights`: Stores all traffic light positions in sorted order.
     Initially contains {0, x} representing the ends of the street.
     - **Why `multiset`?**
       Because we need to efficiently find the nearest lights on either side of a new light.
       `multiset` keeps elements sorted and allows O(log n) lookup for `upper_bound`.
   - `map<int, int> segs`: Stores the segment lengths between lights as keys
     and their counts as values. Initially, one segment of length x exists.
     - **Why `map` and not `unordered_map`?**
       Because we need to efficiently find the maximum segment length after each insertion.
       `map` keeps keys in sorted order, so the largest key can be accessed in O(1) using `rbegin()`.
       `unordered_map` does not maintain order, so finding the max key would take O(n), which is too slow.

3. Algorithm for each new traffic light y:
   a. Find the neighboring traffic lights around y:
      - `right` = first light strictly greater than y (`upper_bound` in multiset).
        - **Why `upper_bound`?**
          It directly gives the light to the right of y in O(log n), so we can find the segment being split.
      - `left` = light immediately before `right` (`prev(right)`).
   b. Calculate the old segment length being split: `old_len = *right - *left`.
   c. Update `segs` map:
      - Decrease count of `old_len` by 1 because it's split.
      - Remove `old_len` from the map if its count reaches 0.
      - Insert the two new segments created:
        - Left segment: `y - *left`
        - Right segment: `*right - y`
      - Increment counts of these new segments in `segs`.
   d. Insert the new light `y` into the `lights` set.

4. Output:
   - After each insertion, the longest segment is the largest key in `segs` map.
     Accessed using `segs.rbegin()->first`.

5. Complexity:
   - Each insertion and map/set operation is O(log n), giving overall O(n log n) time,
     efficient enough for n up to 2e5.
*/

int main(){
    int x;
    int n;
    cin >> x >> n;
    multiset<int> lights = {0,x};
    map<int,int> segs;
    segs[x]=1;
    for(int i =0 ; i < n ; i++){
        int y;
        cin >> y;
        auto right = lights.upper_bound(y);
        auto left = prev(right);
        int old_len = *right-*left;
        segs[old_len]--;
        if(segs[old_len]<=0) segs.erase(old_len);
        segs[*right-y]++;
        segs[y-*left]++;
        lights.insert(y);
        cout << segs.rbegin()->first << " ";
    }
}
