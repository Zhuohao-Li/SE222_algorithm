#include "SGA.h"
#include <math.h>
#include <time.h>
#include <iostream>

using namespace std;

std::bitset<22> Encode(const double DblVaule)
{
	return std::bitset<22>(static_cast<unsigned long>((DblVaule + 1) * (pow(2,22) -1) / 3.0));
}


double Decode(std::bitset<22> BitValue)
{
	return -1.0 + ( BitValue.to_ulong() ) * 3 /static_cast<double>( pow(2,22) -1 ) ;
}

double CmpFitness(std::bitset<22> Chrom)
{
	double PI = 3.14159265;
	double X = Decode(Chrom);
	return X * sin(10*PI*X) + 2.0;
}

double PreSelect(std::vector<Individual> &OldPop)
{
	std::vector<Individual>::iterator OldPop_Iter;
	double SumFitness = 0;

	for ( OldPop_Iter = OldPop.begin( ) ; OldPop_Iter != OldPop.end( ) ; OldPop_Iter++ )
	{
		SumFitness += CmpFitness((*OldPop_Iter).Chrom);
	}
	
	return SumFitness;
}

Individual Select(std::vector<Individual> &OldPop, double SumFitness)
{
	double Pick = rand()/static_cast<double>(RAND_MAX);/*应注意在调用之前调用srand()*/
	double Sum = 0;
	int i = 0;
	int PopSize = OldPop.size();
	if(SumFitness != 0)
	{
		for(i = 0; (Sum < Pick) && (i < PopSize); i++)
		{
			Sum += OldPop[i].Fitness/SumFitness;
		}
		if(i>=PopSize)
		{
			i = PopSize -1;
		}
	}
	else
	{
		i = rand()%PopSize;
	}
	
	return OldPop[i];
}

void Crossover(Individual &Parent1, Individual &Parent2, Individual &Child1, Individual &Child2)
{
	int Pos = rand() % 22;

	for(int i=0; i<Pos; i++)
	{
		Child1.Chrom[i] = Parent1.Chrom[i];
		Child2.Chrom[i] = Parent2.Chrom[i];
	}

	for(int j=Pos; j<22; j++)
	{
		Child1.Chrom[j] = Parent2.Chrom[j];
		Child2.Chrom[j] = Parent1.Chrom[j];
	}
}

void  Mutation(Individual &Child)
{
	int Pos = rand() % 22;

	Child.Chrom.flip(Pos);
}

std::vector<Individual> Initialize(int PopSize, Bestever &Best)
{
	Best.Chrom = std::bitset<22>(0);
	Best.Fitness = -99999999;
	Best.Generation = -1;
	std::vector<Individual> RetPop;
	RetPop.clear();
	double rate;
	for(int i=0; i<PopSize; i++)
	{
		rate = rand()/static_cast<double>(RAND_MAX);
		std::bitset<22> Chrom(rate*4194303/*pow(2,22)-1*/);
		Individual IDL;
		IDL.Chrom = Chrom;
		IDL.Fitness = CmpFitness(Chrom);
		if(Best.Fitness<IDL.Fitness)
		{
			Best.Chrom=IDL.Chrom;
			Best.Fitness=IDL.Fitness;
			Best.Generation=0;
		}
		RetPop.push_back(IDL);
	}
	
	return RetPop;
}

void Generation(std::vector<Individual> &OldPop, std::vector<Individual> &NewPop, 
		double PCross, double PMutation, Bestever &Best, int CurrGen)
{
	Individual Mate1, Mate2;
	Individual Child1,Child2;
	int i = 0;
	int PopSize = OldPop.size();
	double SumFitness = PreSelect(OldPop);
	NewPop.clear();
	do
	{
		Mate1 = Select(OldPop,SumFitness);
		Mate2 = Select(OldPop,SumFitness);
		Child1 = Mate1;
		Child2 = Mate2;
		double Rnd;
		Rnd = rand()/static_cast<double>(RAND_MAX);
		if(Rnd<=PCross)
		{
			Crossover(Mate1,Mate2,Child1,Child2);
		}
		Rnd = rand()/static_cast<double>(RAND_MAX);
		if(Rnd<=PMutation)
		{
			if(rand()%2==0)
			{
				Mutation(Child1);
			}
			else
			{
				Mutation(Child2);
			}
		}
		
		Child1.Fitness = CmpFitness(Child1.Chrom);
		if(Best.Fitness<Child1.Fitness)
		{
			Best.Chrom = Child1.Chrom;
			Best.Fitness = Child1.Fitness;
			Best.Generation = CurrGen;
		}
		
		Child2.Fitness = CmpFitness(Child2.Chrom);
		if(Best.Fitness<Child2.Fitness)
		{
			Best.Chrom = Child2.Chrom;
			Best.Fitness = Child2.Fitness;
			Best.Generation = CurrGen;
		}
		
		NewPop.push_back(Child1);
		NewPop.push_back(Child2);
		i = i + 2;
	}
	while(i < (PopSize-1));
	
	return;
}

Bestever GA(double PCross, double PMutation, int PopSize, int MaxGen)
{
	srand( (unsigned)time( NULL ) );//初始化随机数种子
	
	Bestever Best;
	std::vector<Individual> InitPop = Initialize(PopSize, Best);
	std::bitset<22> Chorm;
	std::vector<Individual> NewPop;
	for(int i=0; i<MaxGen; i++)
	{
		Generation(InitPop, NewPop, PCross, PMutation, Best, i);
		InitPop = NewPop;
		double sum=0;
		//for(int j=0;j<InitPop.size();j++)
		//{
		//	sum+=CmpFitness(InitPop[j].Chrom);
		//}
		//cout<<"第"<<i+1<<"代平均适应度："<<sum/InitPop.size()<<endl;
		if((i%10)==0)
		{
			cout<<"第"<<i+1<<"代进化完成!"<<endl;
		}
	}
	return Best;
}