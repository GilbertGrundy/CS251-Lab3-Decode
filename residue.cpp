#include <iostream>
#include <cstring>

long long residue(int num, int mod, long long exponent);
void find_residue(int &count, long long &a, long long k, long long n, long long &residue, long long &total);
long long next_res(long long residue, long long mod);

using namespace std;


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
