// Programmer : Noah Klein
// Instructor : Price
// Class      : CS5201 Spring 2020
// Assignment : Homework 3 - Euler's Method for ODEs and SIR(D) Model
// Filename   : Euler.h

#ifndef EULER_H
#define EULER_H

#include "MyVector.h"

using namespace std;

template <typename T>
class Euler
{
	private:
		double m_step_size;
		T m_state;
		std::function<T (T)> m_ODE;
		
	public:
		Euler(T& i_state, double& s_size,const std::function<T(T)>& callback_ode);
		Euler();
		T operator()();
		
};


#include "Euler.hpp"
#endif