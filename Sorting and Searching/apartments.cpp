#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------
CSES Problem: Apartments
--------------------------------------------

🧩 Problem Summary:
We have 'n' applicants looking for apartments and 'm' available apartments.
Each applicant has a desired apartment size, and they are willing to accept
an apartment if its size differs from their desired size by at most 'k'.

Goal: Find the maximum number of applicants who can be assigned an apartment.

--------------------------------------------
💡 Approach:
We use a **two-pointer technique** after sorting both lists
of desired apartment sizes and available apartment sizes.

1. Read input values:
   - n → number of applicants
   - m → number of apartments
   - k → maximum allowed difference in apartment size

2. Store the desired sizes of applicants in vector 'apartments'.
   Store the available apartment sizes in vector 'available'.

3. Sort both vectors in ascending order so we can efficiently compare them
   using two pointers.

4. Initialize:
   - i = 0 → pointer for applicants
   - j = 0 → pointer for available apartments
   - ans = 0 → count of successful matches

5. Use a while loop while both lists have unprocessed elements:
   - If abs(apartments[i] - available[j]) <= k:
        → Applicant can accept this apartment.
        → Increment both i and j (move to next applicant and apartment)
        → Increment ans (found one match)
   - Else if (available[j] < apartments[i] - k):
        → Apartment is too small for this applicant.
        → Move j to the next (larger) apartment.
   - Else:
        → Apartment is too large for this applicant.
        → Move i to the next applicant.

6. After the loop ends, print ans — the total number of successful matches.

--------------------------------------------
🕒 Time Complexity:
O(n log n + m log m)  → due to sorting
+ O(n + m)  → for the two-pointer traversal
Total: Efficient for input sizes up to 2×10⁵.

--------------------------------------------
✅ Example:
Input:
  n = 3, m = 3, k = 5
  Applicants: 60 45 80
  Apartments: 30 60 75

Sorted:
  Applicants: 45 60 80
  Apartments: 30 60 75

Matching:
  - 45 → (no match, 30 too small)
  - 60 ↔ 60 (match)
  - 80 ↔ 75 (match)

Output: 2

--------------------------------------------
*/


int main(){
    int n , m , k;
    cin >> n >> m >> k;
    vector<int> apartments;
    for(int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        apartments.push_back(x);
    }
    sort(apartments.begin(),apartments.end());
    vector<int> available;
    for(int i = 0 ; i < m ; i++){
        int x;
        cin >> x;
        available.push_back(x);
    }
    sort(available.begin(),available.end());
    int i = 0, j = 0 ,ans = 0;
    while(i<n && j<m){
        if(abs(apartments[i]-available[j])<=k){
            i++;
            ans++;
            j++;
        }else if(available[j]<apartments[i]-k){
            j++;
        }else{
            i++;
        }
        
    }
    cout << ans << endl;
}