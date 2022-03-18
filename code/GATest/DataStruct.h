#ifndef __DATA_STRUCT_H
#define __DATA_STRUCT_H

#include <bitset>

//个体
struct Individual
{
	std::bitset<22> Chrom;//染色体
	double Fitness;//适应度
};

//最佳个体
struct Bestever
{
	std::bitset<22> Chrom;//最佳染色体
	double Fitness;//最佳适应度
	int Generation;//最佳个体生成代
};

#endif