#ifndef POPULATION_H
#define POPULATION_H

#include"Globals.h"
#include"IO.h"
#include<string>

class Unit
{
	public:
	Unit();
	Unit(const State *& em, int num_states);
	Unit(const Unit& old);

	void mutate();
	void crossover();
	double getScore();

	State ** getEmissions(void);
	
	private:
	double score;
	int num_states;
	State * em;
};

class Population 
{
	public:
	Population();
	Population(const State *& em, std::string template_model, std::string output_dir, int pop_size, std::string fasta_file);
	Population(std::string model_file, std::string output_dir, int pop_size, std::string fasta_file);

	void purge();
	void mate();
	void evaluate();
	void run(int num_threads);
	double getCurrentMax(void);

	private:
	void sortPopulation();

	int num_units;
	Unit * units;
	HMM base_model;
};

#endif
