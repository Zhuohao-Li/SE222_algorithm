#ifndef __SGA_H
#define __SGA_H

#include <bitset>
#include <vector>
#include "DataStruct.h"

//对整形变量进行编码，返回bitset型的编码值
std::bitset<22> Encode(const double DblVaule);

//对整形变量进行解码，返回double型的解码值
double Decode(std::bitset<22> BitValue);

//进行进化搜索
Bestever GA(double PCross, double PMutation, int PopSize, int MaxGen);

//对每一代进行进化操作
void Generation(std::vector<Individual> &OldPop, std::vector<Individual> &NewPop, 
		double PCross, double PMutation, Bestever &Best, int CurrGen);

//计算个体适应度
double CmpFitness(std::bitset<22> Chrom);

//算法初始化
std::vector<Individual> Initialize(int PopSize, Bestever &Best);

//选择操作
Individual Select(std::vector<Individual> &OldPop, double SumFitness);

//预选择操作
double PreSelect(std::vector<Individual> &OldPop);

//交叉操作
void Crossover(Individual &Parent1, Individual &Parent2, Individual &Child1, Individual &Child2);

//变异操作
void  Mutation(Individual &Child);

#endif