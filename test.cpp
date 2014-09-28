#include "versatile_dynamics.hpp"
#include "dynamics.h"
#include <fstream>
#include <iostream>

#define INPUT_RATE 50
#define TEN_SECS  10
#define SIM_RATE 200

int main(){
	unsigned int i;
	unsigned int count = 0;
	double response_rapha = 0.0;

	double demand = 0.0;

	versatile_dynamics rapha;


	std::ofstream a_file ( "demand_response.txt" );

	std::vector<double> coef_b(2), coef_a(2);

	coef_b[0] = 0.0;
	coef_b[1] = 0.048770575499286;


	coef_a[0] = 1.0;
	coef_a[1] = -0.951229424500714;


	rapha.reset(coef_b, coef_a);

	for(i = 0; i < (INPUT_RATE * TEN_SECS); i++){
		if(i == INPUT_RATE){
			demand = 1.0;
		}
		for(unsigned int k = 0; k < (SIM_RATE / INPUT_RATE); k++){
			rapha.get_out(&response_rapha);
			rapha.put_in(demand);

			a_file << (((double)count)/SIM_RATE )<< ", "<< demand << ", " << response_rapha  <<  "\n";

			count++;
		}


	}	
	a_file.close();

}