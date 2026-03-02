#Problem Statement
Implement and compare three cache eviction policies on the same request sequence:

FIFO (First-In, First-Out)

LRU (Least Recently Used)

OPTFF (Belady’s Farthest-in-Future, optimal offline)

You will also complete a short written component, including a proof that OPTFF is optimal.

You are given:

A cache of capacity ( k )

A sequence of ( m ) requests ( r_1, r_2,.., r_m )

For each request:

If the item is already in the cache, this is a hit.

Otherwise, this is a miss. Insert the item:

If the cache is not full, simply insert it.

If the cache is full, evict one item according to the policy.

Eviction Policies
FIFO: Evict the item that has been in the cache the longest.

LRU: Evict the item whose most recent access time is the oldest.

OPTFF: Among items currently in the cache, evict the one whose next request occurs farthest in the future (or never occurs again).

Input Format
Your program must read input from a file with the following format:

k m
r1 r2 r3 ... rm
Where:

( k ) = cache capacity ( ( k >= 1 ) )

( m ) = number of requests

( r_1, .., r_m ) = sequence of integer IDs

Output Format
Your program must output:

FIFO  : <number_of_misses>
LRU   : <number_of_misses>
OPTFF : <number_of_misses>
