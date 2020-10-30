/* This is program project 2 on page 695.
 * Before you begin the project, please read the project description
 * on page 695 first.
 *
 * Author: Samuel Carrasco
 * Version: 9/18/2020
 */

#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

class Fraction
{
public:
	// constructor

	Fraction(int a, int b);
	//// generate a fraction which is a/b

	Fraction(int a);
	//// generate a fraction which is a/1

	Fraction();
	// generate a fraction which is 0/1. i.e 0

	// member functions

	int get_numerator() const;
	// return the numerator of the fraction

	int get_denominator() const;
	// return the denominator of the fraction

	void reduce();
	// reduce this fraction to simplest form. For instance,
	// 2/4 will be reduced to 1/2

	Fraction reciprocal() const;
	// return the reciprocal of this Fraction

	// friend functions

	friend Fraction operator +(const Fraction& f1, const Fraction& f2);
	// return the sum of f1 and f2,
	// the result is reduced

	friend Fraction operator -(const Fraction& f1, const Fraction& f2);
	//// return the difference of f1 and f2,
	//// the result is reduced

	friend Fraction operator *(const Fraction& f1, const Fraction& f2);
	//// return the product of f1 and f2,
	//// the result is reduced

	friend Fraction operator /(const Fraction& f1, const Fraction& f2);
	//// return the quotient of f1 and f2,
	//// the result is reduced

	friend Fraction operator -(const Fraction& f);
	//// return the negation of f

	friend bool operator < (const Fraction& f1, const Fraction& f2);
	//// return true if f1 is less than f2.
	//// False otherwise

	friend bool operator > (const Fraction& f1, const Fraction& f2);
	//// return true if f1 is greater than f2.
	//// False otherwise

	friend bool operator <= (const Fraction& f1, const Fraction& f2);
	//// return true if f1 is less or equal to f2.
	//// False otherwise

	friend bool operator >= (const Fraction& f1, const Fraction& f2);
	//// return true if f1 is greater or equal to f2.
	//// False otherwise

	friend bool operator == (const Fraction& f1, const Fraction& f2);
	//// return true if f1 is equal to f2.
	//// False otherwise

	friend bool operator != (const Fraction& f1, const Fraction& f2);
	//// return true if f1 is not equal to f2.
	//// False otherwise

	friend istream& operator >> (istream& in, Fraction& f);
	//// input f in the form of a/b, where b cannot be zero. Also,
	//// if b is negative, the Fraction will change b to be positive.
	//// So, again, 1/-3 will be changed to -1/3

	friend ostream& operator << (ostream& out, Fraction& f);
	//// output a Fraction f in form of a/b

private:
	int num; // numerator of the fraction
	int den; // denominator of the fraction

	int gcd();
	// A prvate function that is used to find the gcd of numerator
	// and denominator by using Euclidean Algorithm
};

// all following test functions are given

double test1();
// test all constructors and two get methods.
// All these functions worth 1.5 points

double test2();
// test neg, reduce, and reciprocal functions.
// All these functions worth 1.5 points

double test3();
// test add, sub, mul, and div functions.
// All these functions worth 3 points

double test4();
// test less, greater, equal, less_or_equal, greater_or_equal,
// not_equal. All these functions worth 2 points

double test5();
// test input and output function. This two functions worth 1 points

int main()
{
	double totalScore = 0.0;

	cout << "Let's see your grade. \n\n";
	system("pause");
	cout << endl;

	// Test constructors, and get functions
	totalScore += test1();
	cout << "Your points so far is " << totalScore << "\n\n";
	system("pause");
	cout << endl;

	//// Test neg, reciprocal, and reduce functions
	totalScore += test2();
	cout << "Your points so far is " << totalScore << "\n\n";
	system("pause");
	cout << endl;

	// Test +, -, *, / operators
	totalScore += test3();
	cout << "Your points so far is " << totalScore << "\n\n";
	system("pause");
	cout << endl;

	// Test all >, <, >=, <=, ==, != operators
	totalScore += test4();
	cout << "Your points so far is " << totalScore << "\n\n";
	system("pause");
	cout << endl;

	// Test >> and << operators
	totalScore += test5();
	cout << "Your points so far is " << totalScore << "\n\n";
	system("pause");
	cout << endl;

	cout << "If you turn in your program to Dr. Zeng now, your will get " << totalScore << " out of 9\n";
	cout << "Dr. Zeng will read your program and decide if you will get 1 more point for program style\n";

	system("pause");
	return 0;

}

// implement all class member functions here, gcd function is given

int Fraction::gcd()
{
	if (num == 0) return 1;

	int a = max(abs(num), abs(den));
	int b = min(abs(num), abs(den));

	while (b != 0)
	{
		int result = a % b;
		a = b;
		b = result;
	}

	return a;
}


Fraction::Fraction(int a, int b) 
{
	//set numerator to argument a and denomenator to argument b creates a fraction with numerator and denominator
	num = a;
	den = b;
	// if the denomenator "b" is a negative number then we will negate the numerator and turn the denominator to a positive number
	if(b < 0 )
	{ 
		num = a * -1;
		den = abs(b);
	
	}
}

//creates a fraction numerator over 1

Fraction::Fraction(int a)
{
	num = a;
	den = 1;
}

//creates a fraction with 0 over denominator meaning 0
Fraction::Fraction()
{
	num = 0;
	den = 1;
}
// simple return numerator
int Fraction::get_numerator() const
{
	return num;
}


//return denominator
int Fraction::get_denominator() const
{
	return den;
}

//reduce the fraction to its simplest form
void Fraction::reduce()
{
	//create placeholder variable and use given gcd function to get the gcd
	int g = gcd();
	num /= g;
	den /= g;
}
//function to find the reciprocal of a fraction
Fraction Fraction::reciprocal() const
{
	//must create placeholder variables to access the data in the private class data in numerator will be copied to temp then numerator will equal denominator and denominator will equal the value in temp (numerator) 
	int tempNum = num;
	int tempDen = den;
	int temp = tempNum;
	tempNum = tempDen;
	tempDen = temp;


	return Fraction(tempNum, tempDen);
}
//function to add fractions
Fraction operator+(const Fraction& f1, const Fraction& f2)
{
	//multiply denominators for common denominators
	int d = f1.den * f2.den;
	// multiply numerators to get the correct adjusted fractions and then add numerators to get proper numerator
	int n = f1.num * f2.den + f1.den * f2.num;
	//result is numerator will be n and denominator will be d
	Fraction f = Fraction(n, d);
	
	
	return Fraction(f);
}

//function to describe subtraction of fractions
Fraction operator-(const Fraction& f1, const Fraction& f2)
{
	//create commmon denominator by multiplying them together
	int d = f1.den * f2.den;
	//same as addition function but now subtracting them instead
	int n = f1.num * f2.den - f1.den * f2.num;
	Fraction f = Fraction(n, d);
	
	return Fraction(f);
}

//function to multiply fractions
Fraction operator *(const Fraction& f1, const Fraction& f2)
{
	//multiply the denominators
	int d = f1.den * f2.den;
	//multiply numerators
	int n = f1.num * f2.num;

	//creates the fraction
	Fraction f = Fraction(n, d);
	
	return f;
}

//Fraction division function
Fraction operator/(const Fraction& f1, const Fraction& f2)
{
	//in order to divide function you multiply by the reciprocal this code shows f1den* f2 num so demonstrate that process.
		int d = f1.den * f2.num;
		int n = f1.num * f2.den;
		Fraction f = Fraction(n, d);
		return f;
	
	return Fraction();
}
//negation of the fraction
Fraction operator-(const Fraction& f)
{
	 //multiply the numerator by -1 to get the opposite value of the fraction
	return Fraction(f.get_numerator() * -1, f.get_denominator() );

}
// less than function
bool operator < (const Fraction& f1, const Fraction& f2)
{
	// returns true if f1 is less than f2.
	// False otherwise
	Fraction f = f1 - f2;
	return f.num < 0;

}
// greater than function
bool operator > (const Fraction& f1, const Fraction& f2)
{
	// returns true if f1 is greater than f2.
	// False otherwise
	Fraction f = f1 - f2;
	return f.num > 0;
}
//less than or equal too function
bool operator <= (const Fraction& f1, const Fraction& f2)
{
	// returns true if f1 is less or equal to f2.
	// False otherwise
	Fraction f = f1 - f2;
	return f.num <= 0;
}
//greater than or equal to.
bool operator >= (const Fraction& f1, const Fraction& f2)
{
	// returns true if f1 is greater or equal to f2.
	// False otherwise
	Fraction f = f1 - f2;
	return f.num >= 0;
}
//equal to function
bool operator == (const Fraction& f1, const Fraction& f2)
{
	// returns true if f1 is equal to f2.
	// False otherwise
	Fraction f = f1 - f2;
	return f.num == 0;
}
//not equal to function
bool operator != (const Fraction& f1, const Fraction& f2)
{
	// returns true if f1 is not equal to f2.
	 // False otherwise
	Fraction f = f1 - f2;
	return f.num != 0;
}
//istream operator
istream& operator >> (istream& in, Fraction& f)
{
	// input f as a/b, and b cannot be zero.
	// if b is negative, the Fraction will change b to a positive.
	// example: 1/-3 will be changed to -1/3
	int n, d;
	char slash;
	cin >> n;
	cin >> slash;
	cin >> d;
	f = Fraction(n, d);
	return in;
}
//ostream operator
ostream& operator << (ostream& out, Fraction& f)
{
	// output a Fraction f as a/b
	out << f.num << "/" << f.den;
	return out;
}

// test all constructors and two get methods.
// All these functions worth 1 points
double test1()
{
	double result = 1.5;
	// Test no argument constructor
	Fraction f1; // the fraction should be 0/1
	if (f1.get_numerator() != 0 || f1.get_denominator() != 1)
	{
		cout << "The constructor with no argument was wrong.\n";
		result -= 0.5;
	}
	// Test one argument constructor
	Fraction f2(2); // the fraction should shoule be 2/1
	if (f2.get_numerator() != 2 || f2.get_denominator() != 1)
	{
		cout << "The constructor with one argument was wrong.\n";
		result -= 0.5;
	}

	//// Test two arguments constructors
	Fraction f3(3, -4); // the fraction should be -3/4
	if (f3.get_numerator() != -3 || f3.get_denominator() != 4)
	{
		cout << "The constructor with two argument was wrong. Make sure that the denomunator always positive.\n";
		result -= 0.5;
	}
	// finish test
	if (result < 1.5 && result > 0)
		cout << "Test 1 partially failed. You got " << result << " more points\n";
	else if (result > 1.4)
		cout << "Test 1 fully passed. You got 1.5 more points\n";
	else
		cout << "Test 1 completely failed. You may check your constructors and get methods\n";
	return result;
}

// test neg, reduce, and reciprocal functions.
// All these functions worth 1.5 points
double test2()
{
	double result = 1.5;
	Fraction f1(12, -15), f2(2, 3), f3, f4;
	// test neg
	f3 = -f1; // f3 is 12/15
	f4 = -f2; // f4 is -2/3
	if (f3.get_numerator() != 12 || f3.get_denominator() != 15
		|| f4.get_numerator() != -2 || f4.get_denominator() != 3)
	{
		cout << "the negation function was wrong.\n";
		result -= 0.5;
	}


	//// test reciprocal
	f3 = f1.reciprocal(); // f3 is -15/12
	f4 = f2.reciprocal(); // f4 is 3/2
	if (f3.get_numerator() != -15 || f3.get_denominator() != 12
		|| f4.get_numerator() != 3 || f4.get_denominator() != 2)
	{
		cout << "the reciprocal function was wrong.\n";
	result -= 0.5;
	}

	//// test reduce
	f1.reduce(); // f1 is -4/5
	f2.reduce(); // f2 is 2/3
	if (f1.get_numerator() != -4 || f1.get_denominator() != 5 || f2.get_numerator() != 2 || f2.get_denominator() != 3)
	{
		cout << "the reduce function was wrong.\n";
		result -= 0.5;
	}
	// finish test
	if (result < 1.5 && result > 0)
		cout << "test 2 partially failed. you got " << result << " more points\n";
	else if (result > 1.4)
		cout << "test 2 fully passed. you got 1.5 more points\n";
	else
		cout << "test 2 completely failed. \n";
	return result;
}

// test +, -, *, and / operators.
// All these functions worth 3 points
double test3()
{
	Fraction f1(-1, 2), f2(3, 5), f;
	double result = 3.0;
	// Test +
	f = f1 + f2; // f is -1/2+3/5 = 1/10
	if (f.get_numerator() != 1 || f.get_denominator() != 10)
	{
		cout << "The add function was wrong.\n";
		result -= 1.0;
	}
	// Test subtraction
	f = f1 - f2; // f is -1/2 - 3/5 = -11/10
	if (f.get_numerator() != -11 || f.get_denominator() != 10)
	{
		cout << "The sub function was wrong.\n";
		result -= 0.5;
	}
	// Test multiplication
	f = f1 * f2; // f is -3/10
	if (f.get_numerator() != -3 || f.get_denominator() != 10)
	{
		cout << "The mul function was wrong.\n";
		result -= 1.0;
	}
	// Test division
	f = f1 / f2; // f is -5/6
	if (f.get_numerator() != -5 || f.get_denominator() != 6)
	{
		cout << "The div function was wrong.\n";
		result -= 0.5;
	}
	// finish test
	if (result < 3.0 && result > 0)
		cout << "Test 3 partially failed. You got " << result << " more points\n";
	else if (result > 2.9)
		cout << "Test 3 fully passed. You got 3.0 more points\n";
	else
		cout << "Test 3 completely failed. \n";
	return result;

}

// test less, greater, equal, less_or_equal, greater_or_equal,
//// not_equal. All these functions worth 2 points
double test4()
{

	Fraction f1(-1, 2), f2(3, 5), f3(2, -4);
	double result = 2.0;
	// Test <
	if (!(f1 < f2) || f1 < f3 || f2 < f3)
	{
		cout << "The < operator was wrong.\n";
		result -= 0.5;
	}
	// Test >
	if (f1 > f2 || !(f2 > f1) || f1 > f3)
	{
		cout << "The > operator was wrong.\n";
		result -= 0.5;
	}
	// Test ==
	if (f1 == f2 || !(f1 == f3) || f2 == f3)
	{
		cout << "The equal function was wrong.\n";
		result -= 0.5;
	}
	// Test <=
	if (!(f1 <= f2) || !(f1 <= f3) || f2 <= f3)
	{
		cout << "The less_or_equal function was wrong.\n";
		result -= 0.5;
	}
	// Test >=
	if (f1 >= f2 || !(f1 >= f3) || !(f2 >= f3))
	{
		cout << "The greater_or_equal function was wrong.\n";
		result -= 0.5;
	}
	// Test !=
	if (!(f1 != f2) || f1 != f3 || !(f2 != f3))
	{
		cout << "The not_equal function was wrong.\n";
		result -= 0.5;
	}
//
	// finish test
	if (result < 2.0 && result > 0)
		cout << "Test 4 partially failed. You got " << result << " more points\n";
	else if (result > 1.9)
		cout << "Test 4 fully passed. You got 2.0 more points\n";
	else
		cout << "Test 4 completely failed. \n";
	return max(result, 0.0); // the student will not get negative points for any test
}

// test input and output function. This two functions worth 1 points
double test5()
{
	double result = 1.0;
	Fraction f;
	cout << "This test has to be interactive, please follow the instruction\n";
	cout << "Enter a fraction exactly as 3/-4:";
	cin >> f;
	if (f.get_denominator() != 4 || f.get_numerator() != -3)
	{
		cout << "The input function is not correct\n";
		result -= 0.5;
	}
	Fraction f1(3, -4);
	cout << f1;
	cout << "\nDoes the previous line show you -3/4? Y or N: ";
	char choice;
	cin >> choice;
	if (choice != 'y' && choice != 'Y')
	{
		cout << "The output function is not correct\n";
		result -= 0.5;
	}
	// finish test
	if (result < 1.0 && result > 0)
		cout << "Test 5 partially failed. You got " << result << " more points\n";
	else if (result > 0.9)
		cout << "Test 5 fully passed. You got 1.0 more points\n";
	else
		cout << "Test 5 completely failed. \n";
	return result;
}