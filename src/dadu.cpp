#include <iostream>
#include <random>
#include <string>

void help(){
    std::cout<<"Simple CLI dice roller test \n";
    std::cout<<"Usage: \n";
    std::cout<<"    Use 'dadu -h' or 'dadu --help' to show this message \n";
    std::cout<<"    Use argument in format of #d# where first number is the amount of dice to roll and second number is the size of the die \n";
    std::cout<<"    e.g 4d6 would roll four six-sided die. \n";
	std::cout<<"    Note that both numbers must be less than 2^31 \n";
}

void parseDice(std::string strin, int& dnumout, int& dsizout){
	if (strin.find("d")==std::string::npos) std::cout<<"Please input die size and number as #d#. Use -h or --help for help.";
	else{
		int dposit = strin.find("d");
		dnumout = std::stoi(strin.substr(0,dposit));
		dsizout = std::stoi(strin.substr(dposit+1,strin.length()-dposit));
//		std::cout<<dnumout<<" "<<dsizout<<"\n";
	}
}


int main(int argc, char** argv){
    int innum=0;
    int dnum,dsiz,rollput;
    if(argc==1) std::cout<<"Please input die size and number.";
    if(argc==2){
		std::string dinput(argv[1]);
    	if(dinput=="-h"||dinput=="--help") help();
    	else {
			parseDice(dinput,dnum,dsiz);
//			std::cout<<dnum<<" "<<dsiz<<"\n";
	    	std::random_device rd;
	    	std::minstd_rand gen(rd());
	    	std::uniform_int_distribution<> distrib(1,dsiz);
	    	for (int i=1; i<=dnum; i++){
				rollput=distrib(gen);
				innum=innum+rollput;
				std::cout<<"Die no. "<<i<<" rolls a "<<rollput<<"\n";
			}
	    	std::cout<<"The RNG blesses you with number thus: "<<innum<<"!\n";

		}
    }
    std::cout<<std::endl;

    return 0;
}
