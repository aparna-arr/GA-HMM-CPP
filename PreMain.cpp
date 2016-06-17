#include"Preprocess.h"
using namespace std;

int main (int argc, char * argv[])
{
	if (argc < 2)
	{
		cout << "usage: preprocess-GA-HMM <format file>" << endl;
		return 1;
	}

	PreprocessUnit preproc(string(argv[1]));
}
