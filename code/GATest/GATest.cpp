#include "DataStruct.h"
#include "SGA.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	/*std::bitset<22> Chrom("1000101110110101000111");
	cout<<"------------------"<<Decode(Chrom)<<endl;
	double value = 0.637197;
	//std::bitset<22> tmp = Encode(0.637197);
	//std::bitset<10> bb(0);
	std::string aa = Encode(0.637197).to_string();
	cout<<aa.c_str()<<endl;
	cout<<"------------------"<<endl;*/
	cout<<"===========现在开始进行进化计算，请等待============="<<endl;
	double PCross=0.80;
	double PMutation=0.05;
	int PopSize=100;
	int MaxGen=300;
	Bestever Best = GA(PCross,PMutation,PopSize,MaxGen);
	cout<<"***********************************************************"<<endl;
	cout<<"最优X值："<<Decode(Best.Chrom)<<endl;
	cout<<"最优适应度："<<Best.Fitness<<endl;
	cout<<"最优个体产生代数："<<Best.Generation<<endl;
	cout<<"***********************************************************"<<endl;
	return 0;
}

