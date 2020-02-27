// Programmer : Noah Klein
// Instructor : Price
// Class      : CS5201 Spring 2020
// Assignment : Homework 3 - Euler's Method for ODEs and SIR(D) Model
// Filename   : driver.cpp

#include "SIRD.h"

using namespace std;

int main()
{
	double i_pop;
	double i_infect;
	int days = 30;
	double time_step = 0.1;
	
	cin >> i_pop;
	cin >> i_infect;
	
	SIRD_model simulation(i_pop, i_infect, 0.1, MyVector<double>({.01,.1,.05}));
	
	cout << simulation;
	
	for(int i = 0; i < (days / time_step); i++)
	{
		simulation();
		cout << simulation;
	}
	return 0;
}
