/*************************************************************************
* Title: Calculating the Product of Odd Integers
* File: CIS278_Week3_5.12.cpp
* Author: James Eli
* Date: 1/17/2018
*
* Write an application that calculates the product of the odd integers from 
* 1 to 15.
*
* Notes:
*  (1) Compiled with MS Visual Studio 2017 Community (v141).
*
* Submitted in partial fulfillment of the requirements of PCC CIS-278.
*************************************************************************
* Change Log:
*   01/17/2018: Initial release. JME
*************************************************************************/
#include <iostream>  // cout

// recursively calculate the product of the odd integers between 1...n
int oddProduct(unsigned int n) 
{
	return (n <= 1) ? n : (n % 2) ? oddProduct(n - 2) * n : oddProduct(--n);
}

int main() 
{
	std::cout << "The product of the odd integers from 1 to 15 is " << oddProduct(15) << std::endl;
	return 0;
}

