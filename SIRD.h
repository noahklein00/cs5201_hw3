/*! \file
 *
 * Definitions for the SIRD_model class. \n
 * Programmer: Noah Klein \n
 * Class: CS5201 \n
 * Assignment: Homework 3 \n
 */

#ifndef SIRD_H
#define SIRD_H

#include "MyVector.h"
#include "Euler.h"

using namespace std;

//! SIRD_model class.
/*!
 * This class uses 4 Euler objects and 3 MyVectors to represent
 * the spread of a disease throughout a population with respect
 * to discrete time steps.
 */
class SIRD_model
{
	private:
		double h; /*!< A double representing the step size used in the Euler
				   * method of solving the ODEs.
				   */
		MyVector<double> SIRD_vec; /*!< A MyVector object that stores the 
				   * current state of the system of ODEs.
				   */
		MyVector<double> constants; /*!< A MyVector object that stores the 
				   * constants used in the SIRD model computations.
				   */
		MyVector<double> new_state; /*!< A MyVector object that stores the
				   * new state of the system of ODEs.
				   */
		
		Euler<double> Sus; /*!< An Euler object that holds the data for
				   * the Susceptible member of the ODE system.
				   */
		Euler<double> Inf; /*!< An Euler object that holds the data for
				   * the Infected member of the ODE system.
				   */
		Euler<double> Rec; /*!< An Euler object that holds the data for
				   * the Recovered member of the ODE system.
				   */
		Euler<double> Dec; /*!< An Euler object that holds the data for
				   * the Deceased member of the ODE system.
				   */
				
	public:
	
		/*! \brief constructor
		 *
		 * Description: Constructs a new SIRD_model with a total population,
		 * initial infected, step size, and vector of constants.
		 * \param t_pop is the total population.
		 * \param i_inf is the initial amount of infected people.
		 * \param s_size is the step size for the Euler method.
		 * \param store is a MyVector that stores the constants used in the
		 * calculations.
		 * \pre store needs to be a MyVector of at least size 3. i_inf can not
		 * be greater than t_pop.
		 * \post A SIRD_model is created with the appropriate specifications.
		 * \throws Throws a std::domain_error object if i_inf > t_pop.
		 * \throws Throws a std::length_error object if store.size() < 3. 
		 */
		SIRD_model(const double t_pop,const double i_inf,
			const double s_size,const MyVector<double>& store);
		
		/*! \brief constructor
		 *
		 * Description: Constructs a SIRD_model with default initializations
		 * of the member variables.
		 * \post A SIRD_model object is constructed with default initializations.
		 */
		SIRD_model();
		
		/*! \brief copy constructor
		 *
		 * Description: Constructs a new SIRD_model with the same 
		 * member variable values as the parameter rhs.
		 * \param rhs is an already constructed SIRD_model.
		 * \post A new SIRD_model is constructed with the same 
		 * member variables as the parameter rhs. 
		 */
		SIRD_model(const SIRD_model& rhs);
		
		/*! \brief operator =
		 *
		 * Description: Sets the calling object's member variables
		 * equal to the member variables of the parameter rhs.
		 * \param rhs is an already initialized SIRD_model.
		 * \return Returns *this to the calling object.
		 * \post The calling object is set equal to the parameter passed.
		 */
		SIRD_model& operator=(const SIRD_model& rhs);
		
		/*! \brief operator ()
		 *
		 * Description: Allows the user to advance the simulation forward
		 * by one time step.
		 * \pre All the data in all the member variables must be initialized.
		 * \post The SIRD_model is advanced by one time step. */
		void operator()();
		
		/*! \brief operator <<
		 *
		 * Description: Insertion operator overload to properly print 
		 * the SIRD_model class.
		 * \param out is the ostream passed.
		 * \param rhs is the SIRD_model to be output.
		 * \return Returns the ostream.
		 * \post Outputs the calling object to the stream.
		 */
		friend std::ostream & operator << 
			(ostream & out, const SIRD_model & rhs);
			
};

/*! \brief operator <<
 *
 * Description: Insertion operator overload to properly print 
 * the SIRD_model class.
 * \param out is the ostream passed.
 * \param rhs is the SIRD_model to be output.
 * \return Returns the ostream.
 * \post Outputs the calling object to the stream.
 */
std::ostream & operator << (ostream & out, const SIRD_model & rhs);



#include "SIRD.hpp"
#endif