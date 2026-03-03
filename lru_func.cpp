#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

// LRU: Evict the item whose most recent access time is the oldest.
int lru(int k, const vector<int>& requests) 
{
    unordered_map<int, list<int>::iterator> cache; 
    
    // Front items = most used, back items = least used
    list<int> order;                                
    int number_of_misses = 0;

    for (int req : requests) 
    {
        if (cache.count(req)) 
        {
            // If there is a hit, we move item to front (most recently used)
            order.erase(cache[req]);
            order.push_front(req);
            cache[req] = order.begin();
            continue;
        }

        // Otherwise, this is a miss. (increment miss count)
        number_of_misses++;

        // Check if cache is full
        if ((int)cache.size() == k) 
        {
            // If the cache is full, evict least recently used.
            int evict_item = order.back();
            order.pop_back();
            cache.erase(evict_item);
        }

        // // If the cache is not full, simply insert it to front (most recently used)
        order.push_front(req);
        cache[req] = order.begin();
    }

    return number_of_misses;
}