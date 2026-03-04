#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
#include <list>
#include <unordered_map>
#include <iostream>
#include <fstream>

using namespace std;



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


int optff(int k, const vector<int>& number_of_requests)
{
	return 0;
	//TO-DO: Implement OPTFF
}



int main(int argc, char* argv[])
{
        //usage: ./cache_sim <INPUT FILE>
        //Ex: ./cache_sim test.in

        //Example Output:
        //FIFO  : <number_of_misses>
        //LRU   : <number_of_misses>
        //OPTFF : <number_of_misses>


        string inputfile = argv[1];

        vector<int> requests;
        int k;
        int m;
        int lruMisses;
        int fifoMisses;
        int optffMisses;


        ifstream input(inputfile);
        input >> k >> m; //populate k and m variables with proper value

        requests.resize(m);//size the vector according to the value of m

        //populate vector with values from input file
        for (int i=0; i<m; i++)
        {
                input >> requests[i];
        }


        lruMisses = lru(k, requests);//get our number of cache misses
        fifoMisses = fifo(k, requests);
        optffMisses = optff(k, requests);

        cout << "FIFO : " << fifoMisses << endl;
        cout << "LRU : " << lruMisses << endl;
        cout << "OPTFF : " << optffMisses << endl;

        return 0;


}
