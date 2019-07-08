// C++ program to find multiplicative modulo inverse using 
// Extended Euclid algorithm. 
#include<iostream> 
using namespace std; 

// C function for extended Euclidean Algorithm 
long long int gcdExtended(long long int a, long long int b, long long int *x, long long int *y); 

// Function to find modulo inverse of a 
void modInverse(long long int a, long long int m) 
{ 
	long long int x, y; 
	long long int g = gcdExtended(a, m, &x, &y); 
	if (g != 1) 
		cout << "Inverse doesn't exist"; 
	else
	{ 
		// m is added to handle negative x 
		long long int res = (x%m + m) % m; 
		cout << "Modular multiplicative inverse is " << res; 
	} 
} 

// C function for extended Euclidean Algorithm 
long long int gcdExtended(long long int a, long long int b, long long int *x, long long int *y) 
{ 
	// Base Case 
	if (a == 0) 
	{ 
		*x = 0, *y = 1; 
		return b; 
	} 

	long long int x1, y1; // To store results of recursive call 
	long long int gcd = gcdExtended(b%a, a, &x1, &y1); 

	// Update x and y using results of recursive 
	// call 
	*x = y1 - (b/a) * x1; 
	*y = x1; 

	return gcd; 
} 

// Driver Program 
int main() 
{ 
	long long int a = 6, m = 1000000007; 
	modInverse(a, m); 
	return 0; 
} 
