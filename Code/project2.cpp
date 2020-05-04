/*********************** Documentation *******************************
 Project Name: Homework 1 Solution
 Project goal: To utilize Eulers method and the true math model to compute the population growth of given unknowns. Finally 
			   the goal is to compute the relative error between these two computations.
 Authors Name: nferry@email.sc.edu
 Version: 1.00
**********************************************************************/

/* **************************************************
 ********    1. Library and Header Files   **********
 ****************************************************/
#include <iostream>
//#include <vector>

 // using namespace std;
 /* **************************************************
  ********      2. Global Variables         **********
  ****************************************************/

  /* **************************************************
   ********    3. Function Prototypes        **********
   ****************************************************/
void populationCalculator(double numAttempts, double deltaT, double r, double pZero);

   /* **************************************************
	********       4. Main Function           **********
	****************************************************/
int main()
{
	std::cout << "Mathematical model displaying an exponential population growth rate. Our initial population size is 1000 and our growth rate is 0.015%\n";

	std::cout << "This is the computation with the change in time being 0.05, until time reaches 20\n";
	populationCalculator(20, 0.05, 0.015, 1000);

	std::cout << "This is the computation with the change in time being 1.0, until time reaches 20\n";
	populationCalculator(20, 1.0, 0.015, 1000);

} // end main

/* **************************************************
 ********    4. Function Definitions       **********
 ****************************************************/

/*
 * Procedure: Uses the input to compute calculations for Eulers method of a population growth model, then the true value of
			  the model, and then finally computes the error between the two
 * Input: 4 doubles 
 * Output: Nothing
 */
void populationCalculator(double numAttempts, double deltaT, double r, double pZero) {

	// initialize all of our arrays for computation -- the problem here is that arrays cannot be dynamically allocated in c++
	// so it is initialized to be the amount necessary to solve the problem, but in the case of the second step size where we only
	// use 20 steps, 400 is too big for what we need.
	double estimate[401], actual[401], error[401]; 
	// initialize our step size for Eulers method and runtime for loop iterations
	double h = deltaT, runTime = numAttempts / deltaT;
	
	/* This can be used for a dynamically allocated array. This will allow the user to select the amount of times the test
	   is to be run, in the function call 
	std::vector<double> Population;
	std::vector<double>::iterator iterator;
	
	Population.push_back(pZero);
		
	for (int g = 0; g < runTime; g + deltaT) {
		Population.push_back((Population.end() + deltaT * (r ** Population.end() ))
	}
	*/

	// Here we will add the initial population to the first slot in each calculation holding array
	estimate[0] = pZero; 
    actual[0] = pZero;

	// loop through until we reach our runTime. Perform the calculation on each value within the array 
	// until the result is found
	for (int i = 1; i <= runTime; i++) {

		// perform Eulers method to solve for P through each iteration
		estimate[i] = estimate[i - 1] + h * (r * estimate[i - 1]);

		h += 0.05; // increase our step size as we iterate

		std::cout << "The estimated value at iteration " << i << " is " << estimate[i] << "\n";
		
	} // end for	
	
	h = deltaT; // reset our step size for the calculation of the actual value 

	for (int j = 1; j <= runTime; j++) {

		// use the actual math model to solve for P through each iteration 
		actual[j] = actual[j - 1] * exp(r * h);
		
		h += 0.05; // increase our step size as we iterate
		
		std::cout << "The actual value at iteration " << j << " is " << actual[j] << "\n";

	} // end for
	
	// loop through performing the error calculation on each calculation in the arrays
	for (int k = 0; k <= runTime; k++) {

		// calculate the relative error between the two arrays 
		error[k] = abs((estimate[k] - actual[k]) / actual[k]);

		std::cout << "The relative error at iteration " << k << " is: " << error[k] << "\n";

	} // end for

	
} // end function populationCalculator 
