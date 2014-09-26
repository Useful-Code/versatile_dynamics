/*
*		Versatile Dynamics Class
*		This class implements an IIR filter to model dynamics
*
*		The design is (heavily) inspired by Dr. Alexander Lenz' (BRL) Dynamics Class.
*
*		Author: Raphael Nagel
*		Date: 25/Sept/2014
*/

#ifndef __VERSATILE_DYNAMICS__
#define __VERSATILE_DYNAMICS__

#include <vector>


class versatile_dynamics
{

public:
	versatile_dynamics();
	versatile_dynamics(std::vector<double> , std::vector<double>);
	~versatile_dynamics();

	int reset(std::vector<double> , std::vector<double>);
	void reset();

	void set_a(std::vector<double>);
	void set_b(std::vector<double>);

	int put_in(double force, unsigned int periods_since_last);
	int put_in(double force);

	int get_out(double *);
	double get_out(void);
private:
	void shift(double);
	void IIR(void);


	std::vector<double> b;
	std::vector<double> a;

	std::vector<double> out;
	std::vector<double> in;
	unsigned int vector_size;

};

#endif