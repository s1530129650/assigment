#include<stdio.h>
#include<string.h>
#include"variant.h"  //�ṹ���һЩ��������


/*
 ���ı����ݽ���one-hot encode�ͺշ���-onehot���룬Ҫ���ı����ݱ����ĳ��Ȳ�����3ά�����ֻ��sex������one-hot���룬������úշ���-onehot���룺
 ������ɺ��豣���ı������ֱ���֮��Ķ�Ӧת�����Ա������test����ʹ�ã����������ݽ��й�һ������ʹ��ȡֵ������[0,1];Ȼ�󽫵õ������������ϲ���28ά����������
*/

void getAttriNum();               //�õ��������Ե������Լ�������
void oneHotEncode();              //one-hot encode
void dataHighRate();              //���������д���label����50k�ı���
void HuffmanCoding();             //�շ���-onehot���� 
void normalization();			  //�����ݽ��й�һ��
void getfeatureVector();		  //�õ���������
void saveText2num();			  //�����ı������ֱ���֮��Ķ�Ӧת��
void encodeText2num();			  //�ı������ֱ���֮��ı���
