#include <iostream>
#include <fstream>
#include <random>
#include <string>

using namespace std;


int main(int argc, char* argv[])
{

	//usage: ./generate k m max seed test.out
	//k->Cache Capacity
	//m->number of requests
	//max->largest possible item number
	//seed->seed number for random number generator
	//test.out->output file name

	int k = stoi(argv[1]);
	int m = stoi(argv[2]);
	int max = stoi(argv[3]);
	int seed = stoi(argv[4]);
	string filename = argv[5];//store command line arguments as variables
	
	ofstream output(filename);//start output file stream and configure random number generation
	mt19937 rng(seed);
	uniform_int_distribution<int> distrib(1, max);

	output << k <<  " " << m << "\n";

	for (int i=0; i<m; i++)//populate output file
	{
		output << distrib(rng);
		if (i < m - 1)//ensures proper formatting at end of list
		{
			output << " ";
		}
	}

	return 0;


}
