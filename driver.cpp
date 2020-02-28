// Programmer : Noah Klein
// Instructor : Price
// Class      : CS5201 Spring 2020
// Assignment : Homework 3 - Euler's Method for ODEs and SIR(D) Model
// Filename   : driver.cpp

#include "SIRD.h"
#include <cstdlib>

using namespace std;
using std::strtod;

int main(int argc, char* argv[])
{
	try
	{
		double i_pop = strtod(argv[1], nullptr);
		double i_infect = strtod(argv[2],nullptr);
		
		//constants
		const int days = 30;
		const double time_step = 0.1;
		const double beta = .01;
		const double nu = .1;
		const double delta = .05;
		
		SIRD_model simulation(i_pop, i_infect, time_step, 
			MyVector<double>({beta, nu, delta}));
		
		cout << simulation << endl;
		
		for(int i = 0; i < (days / time_step); i++)
		{
			simulation();
			cout << simulation << endl;
		}
	}
	catch(std::domain_error& e)
	{
		std::cerr << "Exception caught, index out of range: " 
			<< e.what() << endl;
	}
	catch(std::length_error& e)
	{
		std::cerr << "Exception caught, incorrect vector length: " 
			<< e.what() << endl;
	}
	return 0;
}
