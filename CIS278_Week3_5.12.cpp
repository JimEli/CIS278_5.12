/*************************************************************************
* Title: Calculating the Product of Odd Integers
* File: CIS278_Week3_5.12.cpp
* Author: James Eli
* Date: 1/22/2018
*
* Write an application that calculates the product of the odd integers 
* from 1 to 15.
*
* Recursive algorithm calculating product of odd integers between 1...n:
*   oddProduct( n ) {
*     if (n < 2) return n 
*     if (n % 2) 
*       return oddProduct(n - 2) * n
*     else 
*       return oddProduct(--n)
*   }
*
* Notes:
*  (1) Algorithm uses recursion.
*  (2) oddProduct only works for integral types.
*  (3) Requires C++14 or greater.
*  (3) WARNING: No range checking is prformed on the result, which can 
*      overflow! Therefore, return type is long long.
*  (4) Compiled with MS Visual Studio 2017 Community (v141).
*
* Submitted in partial fulfillment of the requirements of PCC CIS-278.
*************************************************************************
* Change Log:
*   01/22/2018: Initial release. JME
*************************************************************************/
#include <iostream>    // cout/endl
#include <type_traits> // enable_if_t/is_integral

using namespace std;

// Recursively calculate the product of odd integers between 1...n.
template<typename T>
inline auto oddProduct(T n) -> enable_if_t<is_integral<T>::value, unsigned long long> {
	if (n < 0) 
		throw invalid_argument("oddProduct - negative value");
	return n < T{ 2 } ? n : (n % T{ 2 }) ? oddProduct(n - T{ 2 }) * n : oddProduct(--n);
}

int main() 
{
	const int oddNumber{ 15 };

	try
	{
		cout << "The product of the odd integers from 1 to " << oddNumber << " is " 
			 << oddProduct(oddNumber) << endl;
	}
	catch (invalid_argument &invalidArgument)
	{
		cout << "Exception: " << invalidArgument.what() << "\n";
	}

	return 0;
}
