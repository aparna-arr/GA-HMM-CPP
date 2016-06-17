#include"Main.h"
using namespace std;

int main(int argc, char * argv[])
{
	string fasta, model, template_model, output_dir;
	int pop_size, num_gens, num_threads;

	pop_size = num_gens = num_threads = 1;

	parseInput(argc, argv, fasta, model, template_model, pop_size, num_gens, num_threads, output_dir);
	
	Population pop(model, output_dir, pop_size, fasta);
	
	for(int i = 0; i < num_gens; i++) 
	{
		double max = 0;	

		pop.purge();
		pop.mate();
		pop.run(num_threads);
		pop.evaluate();
		max = pop.getCurrentMax();
		
		cout << "Round " << i << " result: MAX: " << max << endl << endl;
	}
}
