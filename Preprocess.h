#ifndef PREPROCESS_H
#define PREPROCESS_H

#include<iostream>
#include<string>
#include<cstdlib>
#include"IO.h"

class PreprocessUnit
{
	public:
	PreprocessUnit();
	PreprocessUnit(std::string formatfile);

	private:
	WigFile mainwig;
	std::string runfasta, testfasta, modelfasta;
	HMM model;
	std::string * statebedfiles;
}

class WigFile 
{
	public:
	WigFile();
	WigFile(std::string filename);

	std::string extractWig(std::string chr, int start, int end); // converts to customfa, returns small fasta name
	std::string normalize(void); // returns normalized wig name

	private:
	std::string wigToFasta(void);	// returns .customfa name
	std::string filename;
};

#endif
