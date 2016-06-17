#ifndef IO_H
#define IO_H

#include"Globals.h"
#include<string>
#include<sstream>

void parseInput(int argc, char * argv[], std::string& fasta, std::string& model, std::string& template_model, int popsize, int num_gens, int num_threads, std::string& output_dir);

void convert(char * arg, std::string& str);
void convert(char * arg, int i);

typedef struct {
	std::string state_name;	
	int * emissions;
} State;

class HMM 
{
	public: 
	HMM();
	HMM(std::string model_file, std::string output_dir, std::string fasta_file);
	HMM(const State *& em, std::string template_file, std::string output_dir, std::string fasta_file);
	HMM(const HMM& oldHMM, const State *& em);
 
	State ** getEmissions(void);
	void replaceEmissions(const State *& em);

	int getNumStates(void);

	void print(std::string filename);
	void print(std::string filename, const State*& em);

	void runStochHMM(void);

	private:
	void parseTemplate(std::string template_file);
	void parseModel(std::string model_file);	

	int num_states; 
	State ** states;

	std::string output_dir;
	std::string fasta_file;
	std::string * blocks;
};

#endif
