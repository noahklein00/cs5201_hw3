// Programmer : Noah Klein
// Instructor : Price
// Class      : CS5201 Spring 2020
// Assignment : Homework 3 - Euler's Method for ODEs and SIR(D) Model
// Filename   : SIRD.h

#ifndef SIRD_H
#define SIRD_H

#include "MyVector.h"
#include "Euler.h"

using namespace std;

class SIRD_model
{
	private:
		double h;
		MyVector<double> SIRD_vec;
		MyVector<double> constants;
		MyVector<double> new_state;
		
		Euler<double> Sus;
		Euler<double> Inf;
		Euler<double> Rec;
		Euler<double> Dec;
				
	public:
		SIRD_model(const double t_pop,const double i_inf,const double s_size,const MyVector<double>& store);
		SIRD_model();
		void operator()();
		
		double total();
		
		friend std::ostream & operator << (ostream & out, const SIRD_model & rhs);
			
};

std::ostream & operator << (ostream & out, const SIRD_model & rhs);



#include "SIRD.hpp"
#endif