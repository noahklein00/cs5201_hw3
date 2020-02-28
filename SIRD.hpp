// Programmer : Noah Klein
// Instructor : Price
// Class      : CS5201 Spring 2020
// Assignment : Homework 3 - Euler's Method for ODEs and SIR(D) Model
// Filename   : SIRD.hpp

using namespace std;

SIRD_model::SIRD_model(const double t_pop,const double i_inf, 
	const double s_size, const MyVector<double>& store)
{
	//checks for proper initialization of variables
	if(i_inf > t_pop) throw std::domain_error(to_string(i_inf));
	if(store.size() < 3) throw std::length_error(to_string(store.size()));
	
	//the vector constructors were acting weird so I had to do it this way
	h = s_size;
	MyVector<double> temp_vec({t_pop - i_inf, i_inf, 0.0, 0.0});
	SIRD_vec = temp_vec;
	
	MyVector<double> another({0,0,0,0});
	new_state = another;
	
	constants = store;
	
	//sets up the 4 different Euler objects for solving each ODE.
	Sus = Euler<double>(SIRD_vec[0], h, [&](double S) 
		{return S + ((Sus.get_step()) * -constants[0] * SIRD_vec[1] * S);});
	Inf = Euler<double>(SIRD_vec[1], h, [&](double I) 
		{return I + ((Inf.get_step()) * ((constants[0] * I * SIRD_vec[0]) 
		- (constants[1] * I) - (constants[2] * I)));});
	Rec = Euler<double>(SIRD_vec[2], h, [&](double R) 
		{return R + ((Rec.get_step()) * (constants[1] * SIRD_vec[1]));});
	Dec = Euler<double>(SIRD_vec[3], h, [&](double D) 
		{return D + ((Dec.get_step()) * (constants[2] * SIRD_vec[1]));});
	
}

SIRD_model::SIRD_model()
{
	h = .1;
	//constructors still acting weird
	for(int i = 0; i < 4; i++)
	{
		SIRD_vec.push_back(0.0);
		new_state.push_back(0.0);
	}
	
	constants.push_back(.01);
	constants.push_back(.1);
	constants.push_back(.05);
	
	Sus = Euler<double>(SIRD_vec[0], h, [&](double S) 
		{return S + ((Sus.get_step()) * -constants[0] * SIRD_vec[1] * S);});
	Inf = Euler<double>(SIRD_vec[1], h, [&](double I) 
		{return I + ((Inf.get_step()) * ((constants[0] * I * SIRD_vec[0]) 
		- (constants[1] * I) - (constants[2] * I)));});
	Rec = Euler<double>(SIRD_vec[2], h, [&](double R) 
		{return R + ((Rec.get_step()) * (constants[1] * SIRD_vec[1]));});
	Dec = Euler<double>(SIRD_vec[3], h, [&](double D) 
		{return D + ((Dec.get_step()) * (constants[2] * SIRD_vec[1]));});
}	

SIRD_model::SIRD_model(const SIRD_model& rhs)
{ 
	h = rhs.h;
	constants = rhs.constants;
	SIRD_vec = rhs.SIRD_vec;
	new_state = rhs.new_state;
	
	//have to reset each Euler object to get the correct new
	//variables captured by the lambda expression
	Sus = Euler<double>(SIRD_vec[0], h, [&](double S) 
		{return S + ((Sus.get_step()) * -constants[0] * SIRD_vec[1] * S);});
	Inf = Euler<double>(SIRD_vec[1], h, [&](double I) 
		{return I + ((Inf.get_step()) * ((constants[0] * I * SIRD_vec[0]) 
		- (constants[1] * I) - (constants[2] * I)));});
	Rec = Euler<double>(SIRD_vec[2], h, [&](double R) 
		{return R + ((Rec.get_step()) * (constants[1] * SIRD_vec[1]));});
	Dec = Euler<double>(SIRD_vec[3], h, [&](double D) 
		{return D + ((Dec.get_step()) * (constants[2] * SIRD_vec[1]));});
}

SIRD_model& SIRD_model::operator=(const SIRD_model& rhs)
{
	h = rhs.h;
	constants = rhs.constants;
	SIRD_vec = rhs.SIRD_vec;
	new_state = rhs.new_state;
	
	Sus = Euler<double>(SIRD_vec[0], h, [&](double S) 
		{return S + ((Sus.get_step()) * -constants[0] * SIRD_vec[1] * S);});
	Inf = Euler<double>(SIRD_vec[1], h, [&](double I) 
		{return I + ((Inf.get_step()) * ((constants[0] * I * SIRD_vec[0]) 
		- (constants[1] * I) - (constants[2] * I)));});
	Rec = Euler<double>(SIRD_vec[2], h, [&](double R) 
		{return R + ((Rec.get_step()) * (constants[1] * SIRD_vec[1]));});
	Dec = Euler<double>(SIRD_vec[3], h, [&](double D) 
		{return D + ((Dec.get_step()) * (constants[2] * SIRD_vec[1]));});
		
	return *this;
}
	
void SIRD_model::operator()()
{
	//advances each object by one time step and stores it 
	//in another vector so it doesn't overwrite the data
	//that the other functions need.
	new_state[0] = Sus();
	new_state[1] = Inf();
	new_state[2] = Rec();
	new_state[3] = Dec();
	
	SIRD_vec = new_state;
	return;
}

std::ostream & operator << (ostream & out, const SIRD_model & rhs)
{
	out << "Susceptible: " << rhs.SIRD_vec[0] << ", Infected: " 
		<< rhs.SIRD_vec[1] << ", Recovered: " << rhs.SIRD_vec[2] 
		<< ", Deceased: " << rhs.SIRD_vec[3];
	return out;
}
