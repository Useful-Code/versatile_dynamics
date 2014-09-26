/*
*		TO BE USED IN the robot operating system ROS (ros.org)	
*			Use this snippets to load the IIR filter parameters from the parameter server
*			See the .yaml file on how to load them beforehand
*			
*		Author: Raphael Nagel
*		Date: 26/Sept/2014
*
*/

#include "ros/ros.h"


class your_class{
	public:
		your_class();
		~your_class();	

		int read(void);

	private:
		int set_a_b_from_rosparam(void);
		// versatile_dynamics coefficients and object
		std::vector<double> coeff_b, coeff_a;
		versatile_dynamics dynamics_x;
		int simulation_rate;
	};



int your_class::set_a_b_from_rosparam(){
		double vector_size;

		/// get the dynamics parameters from the parameter server
		if (!nh_.getParam("/simulation/x/vector_size", vector_size)){
			  
			ROS_ERROR("your_class: Could not find vector_size\n");
			return EXIT_FAILURE;
		}	

		///prepare the vector to hold them
		coeff_b.resize(vector_size);
		coeff_a.resize(vector_size);

		if (!nh_.getParam("/simulation/x/coeff_b", coeff_b)){
			  
			ROS_ERROR("your_class: Could not find coeff_b\n");
			return EXIT_FAILURE;
		}		
		if (!nh_.getParam("/simulation/x/coeff_a", coeff_a)){
			  
			ROS_ERROR("your_class: Could not find coeff_a\n");
			return EXIT_FAILURE;
		}		

		dynamics_x.reset(coeff_b, coeff_a);		

		if (!nh_.getParam("/simulation/x/simulation_rate", simulation_rate)){
			  
			ROS_ERROR("your_class: Could not find simulation_rate\n");
			return EXIT_FAILURE;
		}	

	}


	int your_class::read(void){

		dynamics_x.put_in(cmd[0], (simulation_rate / loop_hz_));
		pos[0] = dynamics_x.get_out();
	}