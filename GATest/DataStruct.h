#ifndef __DATA_STRUCT_H
#define __DATA_STRUCT_H

#include <bitset>

//����
struct Individual
{
	std::bitset<22> Chrom;//Ⱦɫ��
	double Fitness;//��Ӧ��
};

//��Ѹ���
struct Bestever
{
	std::bitset<22> Chrom;//���Ⱦɫ��
	double Fitness;//�����Ӧ��
	int Generation;//��Ѹ������ɴ�
};

#endif