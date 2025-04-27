#include <iostream>
#include <random>
#include <cstring>

void help(){
    std::cout<<"Simple CLI random picker test \n";
    std::cout<<"Usage: \n";
    std::cout<<"    Use 'milih -h' or 'milih --help' to show this message \n";
    std::cout<<"    Put two or more arguments to let the program randomly pick for you.\n";
    std::cout<<"	You can use the quotation mark (\") to enclose multi-word arguments.\n";

}


int main(int argc, char** argv){
    int val = argc-1;
    int innum;
    if(argc==1) std::cout<<"Please input two or more choices as arguments. Use -h or --help for help.";
    if(argc==2){
    	if(strcmp(argv[1],"-h")==0||strcmp(argv[1],"--help")==0) help();
    	else std::cout<<"Please input two or more choices as arguments. Use -h or --help for help.";
    }
    if(argc>=3){
    	std::random_device rd;
    	std::minstd_rand gen(rd());
    	std::uniform_int_distribution<> distrib(1,val);
    	innum=distrib(gen);
    	std::cout<<"The Chosen One is: "<<argv[innum]<<"!\n";
    }
    std::cout<<std::endl;

    return 0;
}
