#ifndef DNest4_MyModel
#define DNest4_MyModel

#include <vector>
#include "MyConditionalPrior.h"
#include "RJObject/RJObject.h"
#include "RNG.h"

class MyModel
{
	private:
		DNest4::RJObject<MyConditionalPrior> objects;
		double sigma; // Noise standard deviation

		// The signal
		std::vector<long double> mu;
		void calculate_mu();

	public:
		MyModel();

		// Generate the point from the prior
		void from_prior(DNest4::RNG& rng);

		// Metropolis-Hastings proposals
		double perturb(DNest4::RNG& rng);

		// Likelihood function
		double log_likelihood() const;

		// Print to stream
		void print(std::ostream& out) const;

		// Return string with column information
		std::string description() const;
};

#endif

