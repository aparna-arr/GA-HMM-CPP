#include"Population.h"
using namespace std;

/* Unit functions */

Unit::Unit() { }

Unit::Unit(const State *& em, int num_states)
{
	score = 0.0;
	
	
}

Unit::Unit(const Unit& old)
{

}

void Unit::mutate()
{

}

void Unit::crossover()
{

}

double Unit::getScore()
{

}

State ** Unit::getEmissions(void)
{

}

/* end Unit functions */

/* Population functions */
Population::Population() { }

Population::Population(const State *& em, std::string template_model, std::string output_dir, int pop_size, std::string fasta_file)
{
	base_model = HMM(em, template_model, output_dir, fasta_file);
	num_units = pop_size;

	const State * base_em = *(base_model.getEmissions());
	int num_states = base_model.getNumStates();

	units = new Unit[pop_size];

	for (int i = 0; i < num_units; i++)
		units[i] = Unit(base_em, num_states);
}

Population::Population(std::string model_file, std::string output_dir, int pop_size, std::string fasta_file)
{
	base_model = HMM(model_file, output_dir, fasta_file);
	num_units = pop_size;

	const State * base_em = *(base_model.getEmissions());
	int num_states = base_model.getNumStates();

	units = new Unit[pop_size];

	for (int i = 0; i < num_units; i++)
		units[i] = Unit(base_em, num_states);
}

void Population::purge()
{

}

void Population::mate()
{

}

void Population::evaluate()
{

}

void Population::run(int num_threads)
{

}

double Population::getCurrentMax(void)
{

}

void Population::sortPopulation()
{

}

/* End Population functions */
