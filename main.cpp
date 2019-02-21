/*
Name: Gilbert Grundy
Assignment: Lab #3
*/

#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char ** argv)
{
	cout << "Gilbert Grundy CS251 Lab #3.\n";
    	
	//checks if there is the correct amount of arguments
    	//there should just be one file passed in.
    	if(argc != 2)
    	{
        	fprintf(stderr, "Codebreaker: Invalid amount of arguments.\n");
        	return -1;
    	}
	
	
	return 0;
}
