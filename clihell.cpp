#include <iostream>
#include <stdlib.h>
#include <string.h>


void toexdel(int elte){
int i,j;
for( i=0; i<=elte; i++){
    for( j=0; j<=elte; j++){
        if(j==i || j==elte-i){
            std::cout<<"x";
             }
        else std::cout<<" ";
        if(j==elte) std::cout<<"\n";
        }
    }
std::cout<<std::endl;
for(i=0; i<=elte; i++){
    for(j=0; j<=i; j++) std::cout<<"x";
    std::cout<<"\n";
    }
std::cout<<std::endl;
}

void erka (int xin){
    try{
        if(xin==0) throw 0;
        else if (xin>=100) throw 100;
        else toexdel(xin-1);
        }
    catch(int x){
        if (x==0) std::cout<<"  Input cannot be zero or not a number."<<std::endl;
        else if (x==100) std::cout<<"   Input number too large."<<std::endl;
        else std::cout<<"   Unexpected error."<<std::endl;
        }
}

void help(){
    std::cout<<"Simple CLI and iterator test \n";
    std::cout<<"Usage: \n";
    std::cout<<"    Use clihell -h or --help to show this message \n";
    std::cout<<"    Use clihell [NUMBER] to make X and triangle that size.\n";
    std::cout<<"        (Extraneous arguments will be ignored.) \n";
    std::cout<<"    Otherwise you will be prompted to input a number"<<std::endl;
}


int main(int argc, char** argv){
int el;
std::cout<<"Hello World! Use -h or --help for help \n \n";
if(argc==1){
    std::cout<<"Please input a number:";
    std::cin>>el;
    erka(el);
}
else if (argc>=2){
    if(strcmp(argv[1],"-h")==0||strcmp(argv[1],"--help")==0) help();
    else {
        el=atoi(argv[1]);
        erka(el);
        }
}
return 0;
}
