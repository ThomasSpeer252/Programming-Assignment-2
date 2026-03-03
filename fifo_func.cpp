#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
using namespace std;

// FIFO: Evict the item that has been in the cache the longest.

/* 
You are given:

A cache of capacity ( k )

A sequence of ( m ) requests ( r_1, r_2,.., r_m )

For each request:

If the item is already in the cache, this is a hit.

Otherwise, this is a miss. Insert the item:

If the cache is not full, simply insert it.

If the cache is full, evict one item according to the policy.
*/

int fifo(int k, const vector<int>& number_of_requests) 
{
    // Track items in cache and order of items for eviction
    unordered_set<int> cache;      
    queue<int> order;              
    int number_of_misses = 0;

    for (int req : number_of_requests) 
    {
        // If the item is already in the cache, this is a hit.
        if (cache.count(req)) 
            continue;
        
        // Otherwise, this is a miss. (increment miss count)
        number_of_misses++;

        // Check if cache is full
        if ((int)cache.size() == k) 
        {
            // If the cache is full, evict one item according to the policy.
            int evict_item = order.front();
            order.pop();
            cache.erase(evict_item);
        }

        // If the cache is not full, simply insert it.
        cache.insert(req);
        order.push(req);
    }

    return number_of_misses;
}