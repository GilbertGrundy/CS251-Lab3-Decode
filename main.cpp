/*
Name: Gilbert Grundy
Assignment: Lab #3
*/

#include <iostream>
#include <fstream>
#include <cstring>

long long residue(long long num, long long mod, long long exponent);
void find_residue(int &count, long long &a, long long k, long long n, long long &residue, long long &total);
long long next_res(long long residue, long long mod);

using namespace std;

int main(int argc, char ** argv)
{
	long long num;
	long long mod;
	long long exponent;
	long long code;
	ifstream read;

	cout << "Gilbert Grundy CS251 Lab #3.\n";
    	
	//checks if there is the correct amount of arguments
    	//there should just be one file passed in.
    	if(argc != 2)
    	{
        	fprintf(stderr, "Codebreaker: Invalid amount of arguments.\n");
        	return -1;
    	}

	read.open(argv[1]);

	if(!read.is_open())
	{
        	fprintf(stderr, "Codebreaker: File failed to open.\n");
        	return -1;

	}

	read.ignore(5);

	read >> mod;

	read.ignore(7);

	read >> exponent;	

	while(!read.eof())
	{
		read >> num;
		//cout << "read in num " << num << endl;

		code = residue(num, mod, exponent);
		//cout << "residue: " << code <<endl;

		if(code == 27) cout << " ";
		else if(code < 27) printf("%c", (char)(code + 96));
		else cout << "#";

	}
	cout << "\n";
	
	return 0;
}


long long residue(long long num, long long mod, long long exponent)
{
	long long residue = 0;	//residue of a^k mod n
	long long total = 1;	//sum of a^(2^a1, a2, ... an) mod n
	int count = 0;	// count the exponent k of a^(2^k)


	//captures the residue of a^1 mod n
	residue = (num % mod);
	
	//solve the residue	
	find_residue(count, num, exponent, mod, residue, total);

	return (total%mod);
}



//function to find final residue of a^k mod n
void find_residue(int &count, long long &a, long long k, long long n, long long &residue, long long &total)
{
	if(k < 1) return; //leaves if can't be divided anymore.

	//if k%2 = 1, then a^(2^k) mod n is relevant
	if(k % 2) total = (total * (residue%n));

	//get the value of a^(2^(k+1)) mod n
	residue = next_res(residue, n);

	//halve the exponent, count the exponent, call the function recursively
	find_residue(++count, a, (k/2), n, residue, total);

	return;
}

/*This function takes two arguments, the residue which is the
*value of a^(2^k) mod n, and the other argument is n.
*The function then returns the value of a^(2^(k+1)) mod n
* by multiplying a^(2^k) mod n by itself, then getting the
* modulus by n.
*/ 
long long next_res(long long residue, long long mod)
{
	return ((residue*residue)%(mod));
}
