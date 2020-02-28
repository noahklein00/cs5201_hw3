/*! \file
 *
 * Definitions for the Euler class. \n
 * Programmer: Noah Klein \n
 * Class: CS5201 \n
 * Assignment: Homework 3 \n
 */

#ifndef EULER_H
#define EULER_H

#include "MyVector.h"

using namespace std;

//! Euler class.
/*!
 * This class uses std::function to simulate the Euler
 * methed of solving ODEs.
 */
template <typename T>
class Euler
{
	private:
		double m_step_size; /*!< A double representing the step size (h)
				   * of each iteration of the Euler method.
				   */
		T m_state; /*!< A type T object that stores the original state 
				    * of the ODE. 
				    */
		std::function<T (T)> m_ODE; /*!< A std::function that holds a functor
					* that takes a type T and returns a type T. Used to
					* simulate the ODE.
				    */
		
	public:
	
		/*! \brief consructor
		 *
		 * Description: Constructor that takes the initial state of the ODE,
		 * the step size, and a function representing the ODE.
		 * \param i_state represents the initial state of the ODE.
		 * \param s_size represents the step size (h) of the ODE.
		 * \param callback_ode is the function that represents the ODE.
		 * \pre callback_ode needs to be a function that takes a type T
		 * and returns a type T.
		 * \post A Euler object is initialized with the following data.
		 */
		Euler(T& i_state, double& s_size, 
			const std::function<T(T)>& callback_ode);
		
		/*! \brief default constructor
		 *
		 * Description: Initializes an Euler object with default values.
		 * \post An Euler object is created with nothing in the callback_ode
		 * or i_state variables and a default step size of 0.1.
		 */
		Euler();
		
		/*! \brief copy constructor
		 *
		 * Description: Allows construction of a new Euler object based
		 * off of one passed through the parameters.
		 * \param rhs is an already initialized Euler object.
		 * \post A new Euler object is initialized with member variables equal
		 * to rhs's member variables.
		 */
		Euler(const Euler<T>& rhs);
		
		/*! \brief = operator
		 *
		 * Description: Allows assignment of a calling Euler object based
		 * off of another one passed.
		 * \param rhs is an already initialized Euler object.
		 * \return Returns a reference to *this Euler object.
		 * \post The calling object is set equal to the parameter passed.
		 */
		Euler<T>& operator=(const Euler<T>& rhs);
		
		/*! \brief step size accessor
		 *
		 * Description: Allows the user to view the step size for a 
		 * given Euler object.
		 * \return Returns a double equal to the step size of the 
		 * calling object.
		 */
		double get_step();
		
		/*! \brief () operator (unary)
		 *
		 * Description: Advances the ODE forward by one time step.
		 * \return Returns a T object representing the new state of
		 * the ODE.
		 * \pre All operations used in the function must be defined for type T.
		 * \post The Euler object is advanced by one time step and the new 
		 * state is stored in the object.
		 */
		T operator()();
		
		/*! \brief () operator (binary)
		 *
		 * Description: Advances the ODE forward by a custom time step
		 * passed by the user.
		 * \param new_step is the new time step that will be used by the 
		 * Euler object.
		 * \return Returns a T object representing the new state of the ODE.
		 * \pre All operations used in the function must be defined for type T.
		 * \post The Euler object is advanced by one (new) time step, the new
		 * time step is now stored as s_size in the object, and the new state
		 * is stored in the object.
		 */
		T operator()(const double new_step);
};


#include "Euler.hpp"
#endif