#include"IO.h"
using namespace std;

void parseInput(int argc, char * argv[], std::string& fasta, std::string& model, std::string& template_model, int popsize, int num_gens, int num_threads, std::string& output_dir)
{
	if (argc < 7)
		throw(1);

	convert(argv[1], fasta);
	convert(argv[2], model);
	convert(argv[3], template_model);
	convert(argv[4], popsize);
	convert(argv[5], num_gens);
	convert(argv[6], num_threads);
	convert(argv[7], output_dir);
}

void convert(char * arg, std::string& str)
{
	stringstream ss(arg);
	
	if (!(ss >> str))
		throw(1);
}

void convert(char * arg, int i)
{
	stringstream ss(arg);
	
	if (!(ss >> i))
		throw(1);
}

/* start HMM functions */
HMM::HMM()
{

}

HMM::HMM(std::string model_file, std::string output_dir, std::string fasta_file)
{

}

HMM::HMM(const State *& em, std::string template_file, std::string output_dir, std::string fasta_file)
{

}

HMM::HMM(const HMM& oldHMM, const State *& em)
{

}
 
State ** HMM::getEmissions(void)
{	
	State ** new_ptr = NULL;	
	*new_ptr = new State[num_states];

	for (int i = 0; i < num_states; i++)
	{	
		new_ptr[i]->state_name = states[i]->state_name;

		// copy array of ints
	}		

	return new_ptr;
}

int HMM::getNumStates(void)
{
	return num_states;
}

void HMM::replaceEmissions(const State *& em)
{
	for (int i = 0; i < num_states; i++)
	{

	}
}

void HMM::print(std::string filename)
{

}

void HMM::print(std::string filename, const State*& em)
{

}


void HMM::runStochHMM(void)
{

}

void HMM::parseTemplate(std::string template_file)
{

}

void HMM::parseModel(std::string model_file)
{

}

/* end HMM functions */
