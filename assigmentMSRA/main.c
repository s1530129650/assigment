#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "processCSVFile.h"			//1.Data Loading
#include "Datapreprocessing.h"		//2.Data Preprocessing
#include"parameterSelection.h"      //3.Model Training and Parameter Selection
#include"testing.h"                 //4.Testing

int main()
{
    
	char *fpTrain1="census.csv";
	char *fpTest1="census-test.csv";
    double accuracy = 0;
  
	//1.data loading
	ReadCsvData(fpTrain1);           //��ȡcsv����
	

	//2.data preprocessing
	getAttriNum();					 //�õ��������Ե������Լ�������
	oneHotEncode();					 //one-hot encode
	HuffmanCoding();				 //�շ���-onehot���� 
    saveText2num();					 //�����ı������ֱ���֮��Ķ�Ӧת��
	normalization();				 //�����ݽ��й�һ��
	getfeatureVector();				 //�õ���������


	//3.parameter selection and model training 
	stratifiedSampling();    //�ֲ���� 
	computeWeight();		 //���㲻ͬ������Ȩ�ز�ѡ�����ŵĽ���ģ�͵�ѵ��
	

	//4.testing

	//4.1data loading
	ReadCsvData(fpTest1);           //��ȡcsv����

	//4.2.data preprocessing
	getAttriNum();					 //�õ��������Ե������Լ�������
	encodeText2num();				 //�ı������ֱ���֮��ı���ת��
	normalization();				 //�����ݽ��й�һ��
	getfeatureVector();				 //�õ���������

	//4.3����accuracy
	accuracy = testSetAccuracy();     //�����ڲ��Լ��ϵ�׼ȷ��
	printf("�ڲ��Լ��ϵ�׼ȷ��Ϊ��%.8f\n",accuracy);
	
	return 0;
 } 
 
