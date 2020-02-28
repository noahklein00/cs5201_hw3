// Programmer : Noah Klein
// Instructor : Price
// Class      : CS5201 Spring 2020
// Assignment : Homework 3 - Euler's Method for ODEs and SIR(D) Model
// Filename   : Euler.hpp

using namespace std;

template <typename T>
Euler<T>::Euler(T& i_state, double& s_size,
	const std::function<T(T)>& callback_ode)
{
	m_state = i_state;
	m_step_size = s_size;
	m_ODE = callback_ode;
}

template <typename T>
Euler<T>::Euler()
{
	m_step_size = 0.1; //default step size
}

template <typename T>
Euler<T>::Euler(const Euler<T>& rhs)
{
	m_state = rhs.m_state;
	m_step_size = rhs.m_step_size;
	m_ODE = rhs.m_ODE;
}

template <typename T>
Euler<T>& Euler<T>::operator=(const Euler<T>& rhs)
{
	m_state = rhs.m_state;
	m_step_size = rhs.m_step_size;
	m_ODE = rhs.m_ODE;
	return *this;
}

template <typename T>
double Euler<T>::get_step()
{
	return m_step_size;
}
	
template <typename T>
T Euler<T>::operator()()
{
	m_state = m_ODE(m_state);
	return m_state;
}

template <typename T> 
T Euler<T>::operator()(const double new_step)
{
	//allows for the user to override the initialized step size
	m_step_size = new_step;
	m_state = m_ODE(m_state);
	return m_state;
}