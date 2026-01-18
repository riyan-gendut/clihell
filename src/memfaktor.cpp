#include <iostream>
#include <string>
#include <stdexcept>

void help(){
	std::cout<<"================================= \n";
    std::cout<<"Simple CLI number factorizer test \n";
	std::cout<<"================================= \n\n";
    std::cout<<"WARNING: This program performs factorization by brute force without any tricks, \n";
	std::cout<<"i.e. it would go through every number less than half the input number to find its factor. \n\n";
    std::cout<<"Usage: \n";
    std::cout<<"    Use 'faktor -h' or 'faktor --help' to show this message \n";
    std::cout<<"    Use a number as argument to find all factors of the number \n";
    std::cout<<"    Input must be a number greater than 0 and less than 2^63 (i.e. 64-bit integer limit) \n";
    std::cout<<"    As a bonus the program would tell you when a number is a prime or perfect number \n";

}

long parsenum(std::string instring){
	long outnum = 0; 
    try{
		outnum = std::stol(instring);
    }
    catch(const std::invalid_argument& ex){
		std::cout<<"[ERROR] Input is not a number or otherwise invalid."<<std::endl;
    }
	catch(const std::out_of_range& ex){
		std::cout<<"[ERROR] Input is too large."<<std::endl;
    }
	catch(...){
		std::cout<<"[ERROR] Invalid input."<<std::endl;
	}
	return outnum;
}



int main(int argc, char** argv){
    long opsinput = 0;
	long perfchk = 0;
	long limf = 0;
    if(argc==1) std::cout<<"Please input a number.";
    if(argc==2){
		std::string dinput(argv[1]);
    	if(dinput=="-h"||dinput=="--help") help();
    	else {
			opsinput = parsenum(dinput);
			if (opsinput <= 1){
				std::cout<<"Input must be a number greater than one and less than 2^63."<<std::endl;
				return 0;
			}
			if (opsinput%2 != 0) limf = (opsinput+1)/2;
			else limf = opsinput/2;
			for(long i = 1; i<=limf; i++){
				if((opsinput % i) == 0){
					std::cout<<"The number "<<i<<" is a factor of "<<opsinput<<".\n";
					perfchk = perfchk + i;
				}
			}
		if(perfchk == 1) std::cout<<"The number "<<opsinput<<" is a prime!\n";
		if(perfchk == opsinput) std::cout<<"The number "<<opsinput<<" is a perfect number!\n";
		}
    }
    std::cout<<std::endl;

    return 0;
}
