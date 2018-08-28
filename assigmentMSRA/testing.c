#define _CRT_SECURE_NO_WARNINGS
#include"testing.h"

double  testSetAccuracy()     //����׼ȷ��
{
	int i,j;
	double accuracy=0,count=0;           //count���ͳ�� Ԥ����ȷ������
	double fxi;                          //���f(xi)��ֵ
	int testlabel[MAX_DATA_SIZE];		//�����֤����ǩ
	memset(	testlabel,0,sizeof(testlabel));    //��ʼ�����Խ���ı�ǩ
	//ʹ�����Ժ���Ԥ��label
	for(i=0;i<lenTraining;i++)
	{
		  fxi = 0;
          for(j=0;j<feature_SIZE;j++)          //feature_SIZE������������ά��
		  {
			  fxi = fxi + w[j]*trainFeatureVector[i][j];		//����f(xi)
		  }
		  testlabel[i]=(int)(fxi+0.5)>(int)fxi?(int)fxi+1:(int)fxi;   //��f(xi)������������
	}
	 //������ȷ��
	for(i=0;i<trainRealNumRow;i++ )
	{
		if(testlabel[i] == label[i])  //���������ȷ����count��1
			count++;
	}
	accuracy = count/(double)trainRealNumRow;  //�õ���ȷ��
	return accuracy;         //������ȷ�� 
}