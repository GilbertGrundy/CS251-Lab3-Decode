/*
Name: Gilbert Grundy
Assignment: Lab #2
*/

#include <iostream>
#include <cstring>

int get_values(long long &a, long long &k, long long &n);
void find_residue(int &count, long long &a, long long k, long long n, long long &residue, long long &total);
long long next_res(long long residue, long long mod);
bool repeat();

using namespace std;

int main()
{
	long long integer = 0;	//integer to mod
	long long exponent = 0;	//number to be exponent to a - a^k 
	long long mod = 0;	//number to modulus
	long long residue = 0;	//residue of a^k mod n
	long long total = 1;	//sum of a^(2^a1, a2, ... an) mod n
	int count = 0;	// count the exponent k of a^(2^k)

	cout << "Gilbert Grundy CS251 Lab #2.\n";

	cout << "Let's calculate the residue of the form a^k MOD n.\n\n";

	do
	{	//function to collect values from user
		get_values(integer, exponent, mod);

		//captures the residue of a^1 mod n
		residue = (integer % mod);
	
		//solve the residue	
		find_residue(count, integer, exponent, mod, residue, total);

		//states entered  values
		cout << "\n\n" << integer << "^" << exponent << " MOD " << mod << " = ";
		
		//display the answer by the residue mod n
		cout << (total%mod) << endl << endl;

		//reset the values
		residue = 0;
		total = 1;
		count = 0;

	}while(repeat()); //check if user wants to repeat

	return 0;
}


//function to get values from user
int get_values(long long &a, long long &k, long long &n)
{
	cout << "Please enter a vlaue for a: ";

	cin >> a;
	cin.clear();
	cin.ignore(100, '\n');

	cout << "Please enter a value for k: ";

	cin >> k;
	cin.clear();
	cin.ignore(100, '\n');
	
	cout << "Please enter a value for n: ";

	cin >> n;
	cin.clear();
	cin.ignore(100, '\n');

	cout << endl;

	if(n == 0) return -1;
	if(k == 0) return 0;

	return 1;
}


//function to find final residue of a^k mod n
void find_residue(int &count, long long &a, long long k, long long n, long long &residue, long long &total)
{
	if(k < 1) return; //leaves if can't be divided anymore.

	//display step:
	cout << a << "^(2^" << count << ") MOD " << n << " = " << residue;

	//if k%2 = 1, then a^(2^k) mod n is relevant
	if(k % 2) 
	{
		total = (total * (residue%n));
		cout << "*";
	}
	//get the value of a^(2^(k+1)) mod n
	residue = next_res(residue, n);

	cout << endl;

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


//function to check if the user would like to go again
bool repeat()
{
	char again;
	bool repeat = true;
	do
	{
		cout << "Would you like to run the program again? y/n: ";

		cin >> again;
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n\n";

		if(again == 'y' || again == 'Y') return true;
		if(again == 'n' || again == 'N') return false;
	}while(repeat);
}
