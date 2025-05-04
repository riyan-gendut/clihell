#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

int main(int argc, char** argv){
	int el;
	if(argc==1){
    	cout<<"Please input a number: \n";
    	cin>>el;
	}
	else if (argc>=2 && atoi(argv[1]) > 0){
		el=atoi(argv[1]);
		cout<<"Counting down from: "<<el<<"\n";
	}

    int bane=0;
    while(bane<el){
		cout<<(el-bane)<<"\n";
	    bane=bane+1;
		this_thread::sleep_for(chrono::milliseconds(1000));
    }

	int status=system("aplay /home/riyan_gendut/Public/misc++/493698__stib__arpeg.wav");
	while(status==0) status=system("aplay /home/riyan_gendut/Public/misc++/493698__stib__arpeg.wav");
	cout<<endl;

    return 0;
}
