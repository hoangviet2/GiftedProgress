// C++ program for the above approach
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// Function that finds maximum number
// of triplets with different elements
void findTriplets(int ar[], int n)
{

    // Map M will store the frequency
    // of each element in the array
    unordered_map<int, int> mp;

    for (int x = 0; x < n; x++)
        mp[ar[x]]++;

    // Priority queue of pairs
    // {frequency, value}
    priority_queue<pair<int, int> > pq;

    for (auto& pa : mp)
        pq.push({ pa.second, pa.first });

    // ans will store possible triplets
    vector<array<int, 3> > ans;

    while (pq.size() >= 3) {

        // Extract top 3 elements
        pair<int, int> ar[3];
        for (int x = 0; x < 3; x++) {
            ar[x] = pq.top();
            pq.pop();
        }

        // Make a triplet
        ans.push_back({ ar[0].second,
                        ar[1].second,
                        ar[2].second });

        // Decrease frequency and push
        // back into priority queue if
        // non-zero frequency
        for (int x = 0; x < 3; x++) {
            ar[x].first--;
            if (ar[x].first)
                pq.push(ar[x]);
        }
    }

    // Print the triplets
    cout << "Maximum number of "
        << "possible triples: ";
    cout << ans.size() << endl;

    for (auto& pa : ans) {

        // Print the triplets
        for (int v : pa)
            cout << v << " ";
        cout << endl;
    }
}

// Driver Code
int main()
{
    // Given array arr[]
    int arr[] = { 2, 2, 3, 3, 4, 4, 4, 4, 5 };

    int n = sizeof(arr) / sizeof(arr[0]);

    // Function Call
    findTriplets(arr, n);
    return 0;
}
