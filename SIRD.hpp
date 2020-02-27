// Programmer : Noah Klein
// Instructor : Price
// Class      : CS5201 Spring 2020
// Assignment : Homework 3 - Euler's Method for ODEs and SIR(D) Model
// Filename   : SIRD.hpp

using namespace std;

SIRD_model::SIRD_model(const double t_pop,const double i_inf, const double s_size, const MyVector<double>& store)
{
	h = s_size;
	MyVector<double> temp_vec({t_pop - i_inf, i_inf, 0.0, 0.0});
	SIRD_vec = temp_vec;
	
	MyVector<double> another({0,0,0,0});
	new_state = another;
	
	constants = store;
	
	Sus = Euler<double>(SIRD_vec[0], h, [&](double S) {return S + (h * -constants[0] * SIRD_vec[1] * S);});
	Inf = Euler<double>(SIRD_vec[1], h, [&](double I) {return I + (h * ((constants[0] * I * SIRD_vec[0]) 
														- (constants[1] * I) - (constants[2] * I)));});
	Rec = Euler<double>(SIRD_vec[2], h, [&](double R) {return R + (h * (constants[1] * SIRD_vec[1]));});
	Dec = Euler<double>(SIRD_vec[3], h, [&](double D) {return D + (h * (constants[2] * SIRD_vec[1]));});
	
}

SIRD_model::SIRD_model()
{
	h = .1;
	for(int i = 0; i < 4; i++)
	{
		SIRD_vec.push_back(0.0);
		new_state.push_back(0.0);
	}
	
	constants.push_back(.01);
	constants.push_back(.1);
	constants.push_back(.05);
	
	Sus = Euler<double>(SIRD_vec[0], h, [&](double S) {return S + (h * -constants[0] * SIRD_vec[1] * S);});
	Inf = Euler<double>(SIRD_vec[1], h, [&](double I) {return I + (h * ((constants[0] * I * SIRD_vec[0]) 
														- (constants[1] * I) - (constants[2] * I)));});
	Rec = Euler<double>(SIRD_vec[2], h, [&](double R) {return R + (h * (constants[1] * SIRD_vec[1]));});
	Dec = Euler<double>(SIRD_vec[3], h, [&](double D) {return D + (h * (constants[2] * SIRD_vec[1]));});
}	 

void SIRD_model::operator()()
{
	new_state[0] = Sus();
	new_state[1] = Inf();
	new_state[2] = Rec();
	new_state[3] = Dec();
	
	SIRD_vec = new_state;
	return;
}

std::ostream & operator << (ostream & out, const SIRD_model & rhs)
{
	out << "Susceptible: " << rhs.SIRD_vec[0] << ", Infected: " << rhs.SIRD_vec[1] << ", Recovered: "
		<< rhs.SIRD_vec[2] << ", Deceased: " << rhs.SIRD_vec[3] << endl;
	return out;
}

double SIRD_model::total()
{
	double tot = 0;
	for(int i = 0; i < 4; i++)
		tot += SIRD_vec[i];
	return tot;
}