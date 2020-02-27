// Programmer : Noah Klein
// Instructor : Price
// Class      : CS5201 Spring 2020
// Assignment : Homework 3 - Euler's Method for ODEs and SIR(D) Model
// Filename   : Euler.hpp

using namespace std;

template <typename T>
Euler<T>::Euler(T& i_state, double& s_size,const std::function<T(T)>& callback_ode)
{
	m_state = i_state;
	m_step_size = s_size;
	m_ODE = callback_ode;
}

template <typename T>
Euler<T>::Euler()
{
	m_step_size = 0.1;
}

template <typename T>
T Euler<T>::operator()()
{
	m_state = m_ODE(m_state);
	return m_state;
}