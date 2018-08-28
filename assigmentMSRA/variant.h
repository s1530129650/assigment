#pragma once
#include<stdio.h>
#define MAX_LINE_SIZE 4096   //fgets������ȡ������ֽ���
#define MAX_DATA_SIZE 33000  //�������ݵ����������������
#define MAX_char_SIZE 32	 //�������ݵĵ����ַ�����������
#define MAX_kind_SIZE 50	 //���ݵ������������������� ���繤���ײ������50��
#define MAX_encode_SIZE 3	 //�ı�����ת���������ݵ���󳤶ȣ���Լ�����������Ϊ3
#define feature_SIZE 28		 //����������ά��Ϊ28


 typedef struct               //����ṹ����csv����
{
	double  age[MAX_DATA_SIZE];                           //csv�ļ����age����
	char   workclass[MAX_DATA_SIZE][MAX_char_SIZE];			//csv�ļ����workclass����
	char   education[MAX_DATA_SIZE][MAX_char_SIZE];			//csv�ļ����education���� ��������
	double  educationNum[MAX_DATA_SIZE];	
	char 	maritalStatus[MAX_DATA_SIZE][MAX_char_SIZE];	 
	char 	occupation[MAX_DATA_SIZE][MAX_char_SIZE];
	char 	relationship[MAX_DATA_SIZE][MAX_char_SIZE];	
	char	race[MAX_DATA_SIZE][MAX_char_SIZE];	
	char 	sex[MAX_DATA_SIZE][MAX_char_SIZE];	
	double	capitalGain[MAX_DATA_SIZE];
	double  capitalLoss[MAX_DATA_SIZE];
	double	hoursPerWeek[MAX_DATA_SIZE];
	char	nativeCountry[MAX_DATA_SIZE][MAX_char_SIZE];	
	

} attributes ; //��������

  typedef struct   //����ṹ��ͳ�Ƹ������Ե����������
{
	
	char   workclass[MAX_kind_SIZE][MAX_char_SIZE];   //workclassd������ ������ State-gov�� Self-emp-not-inc��private��
	int    lenWorkclass;							//workclassd�����������
	char   education[MAX_kind_SIZE][MAX_char_SIZE]; // education������ ������ HS-grad��Bachelors��
	int    lenEducation;								// education������  ��������
	char   maritalStatus[MAX_kind_SIZE][MAX_char_SIZE];	
	int    lenMaritalStatus;
	char   occupation[MAX_kind_SIZE][MAX_char_SIZE];
	int    lenOccupation;
	char   relationship[MAX_kind_SIZE][MAX_char_SIZE];	
	int    lenRelationship;
	char   race[MAX_kind_SIZE][MAX_char_SIZE];	
	int    lenRace;
	char   sex[MAX_kind_SIZE][MAX_char_SIZE];
	int    lenSex;
	char   nativeCountry[MAX_kind_SIZE][MAX_char_SIZE];	
	int    lenNativeCountry;

} attriNum ; //���Լ�������

  typedef struct{                         //��Ÿ������� ����
	double  age[MAX_DATA_SIZE];                              //����age�� ����
	int   encodeWorkclass[MAX_DATA_SIZE][MAX_encode_SIZE] ;   //����Workclass�� ���� ��������
	int   encodeEducation[MAX_DATA_SIZE][MAX_encode_SIZE];
	double  educationNum[MAX_DATA_SIZE];	
	int   encodeMaritalStatus[MAX_DATA_SIZE][MAX_encode_SIZE];		
	int  encodeOccupation[MAX_DATA_SIZE][MAX_encode_SIZE];	
	int   encodeRelationship[MAX_DATA_SIZE][MAX_encode_SIZE];	
	int   encodeRace[MAX_DATA_SIZE][MAX_encode_SIZE];	
	int   encodeSex[MAX_DATA_SIZE][MAX_encode_SIZE];
	double	capitalGain[MAX_DATA_SIZE];
	double  capitalLoss[MAX_DATA_SIZE];
	double	hoursPerWeek[MAX_DATA_SIZE];
	int  encodeNativeCountry[MAX_DATA_SIZE][MAX_encode_SIZE];	
	
  } dataEncode; //����

  typedef struct{              //��Ÿ������Ե�label����50k�ı���
	double   rateWorkclass[MAX_kind_SIZE]; //����Workclass��label����50k�ı���
	double   rateEducation[MAX_kind_SIZE];	//����Education��label����50k�ı���
	double   rateMaritalStatus[MAX_kind_SIZE];	//����eMaritalStatus��label����50k�ı���	
	double   rateOccupation[MAX_kind_SIZE];			//��������
	double   rateRelationship[MAX_kind_SIZE];	
	double   rateRace[MAX_kind_SIZE];	
	double   rateSex[MAX_kind_SIZE];
	double   rateNativeCountry[MAX_kind_SIZE];	
	
  } over50Rate; //��Ÿ������Ե�label����50k�ı���

  typedef struct{
    char   workclass[MAX_kind_SIZE][MAX_char_SIZE];   //workclassd������ ������ State-gov�� Self-emp-not-inc��private��
	int    encodeWorkclass[MAX_kind_SIZE][MAX_encode_SIZE]	; //����Workclass��Ӧ�����ֱ��� 
	char   education[MAX_kind_SIZE][MAX_char_SIZE];			// education������ ������ HS-grad��Bachelors��
	int    encodeEducation[MAX_kind_SIZE][MAX_encode_SIZE]; //����education��Ӧ�����ֱ��� ��������
	char   maritalStatus[MAX_kind_SIZE][MAX_char_SIZE];	
	int    encodeMaritalStatus[MAX_kind_SIZE][MAX_encode_SIZE];	
	char   occupation[MAX_kind_SIZE][MAX_char_SIZE];
	int    encodeOccupation[MAX_kind_SIZE][MAX_encode_SIZE];	
	char   relationship[MAX_kind_SIZE][MAX_char_SIZE];	
	int    encodeRelationship[MAX_kind_SIZE][MAX_encode_SIZE];	
	char   race[MAX_kind_SIZE][MAX_char_SIZE];	
	int    encodeRace[MAX_kind_SIZE][MAX_encode_SIZE];	
	char   sex[MAX_kind_SIZE][MAX_char_SIZE];
	int    encodeSex[MAX_kind_SIZE][MAX_encode_SIZE];
	char   nativeCountry[MAX_kind_SIZE][MAX_char_SIZE];	
	int   encodeNativeCountry[MAX_kind_SIZE][MAX_encode_SIZE];	
  } text2numcode;//�����ı������ֱ���֮��Ķ�Ӧת��

attributes trainDATA;     //���ѵ������ԭʼcsv����
attributes testDATA;      //��Ų��Լ���csv����

attriNum trainAttriTextData;   //���ѵ������ĳЩ���ı������йصı���
dataEncode trainDataEncode;    //���ѵ������ĳЩ���ı������йصı���
over50Rate trainover50Rate;    //��Ÿ������Ե�label����50k�ı���
text2numcode Text2Num;		   //�����ı������ֱ���֮��Ķ�Ӧת��


int label[MAX_DATA_SIZE];		 //��ǩ��int��

int trainNumRow ;				 //�ļ�����
int trainNumCol ;				 // �ļ��������Ե�һ��Ϊ׼��
int trainRealNumRow ;            //ɾ������Ҫ�ģ�ʵ���õ�������

double  trainFeatureVector[MAX_DATA_SIZE][feature_SIZE];		//��������Ϊfeature_SIZEά
int    lenPositive;												//���������ȣ�
int    lenNegative;												//���������ȣ�
double  postivefeatureVector[MAX_DATA_SIZE][feature_SIZE];		//��������������
double  negativefeatureVector[MAX_DATA_SIZE][feature_SIZE];		//��������������
double  trainingFeatureVector[MAX_DATA_SIZE][feature_SIZE];		//���ڽ�����֤��ѵ����
int     traininglabel[MAX_DATA_SIZE];							//ѵ������ǩ
int     lenTraining;											//ѵ��������
double  ValidationFeatureVector[MAX_DATA_SIZE][feature_SIZE];	//���ڽ�����֤����֤��
int     Validationlabel[MAX_DATA_SIZE];							//��֤����ǩ
int     lenValidation;											//��֤�����ȣ�

double w[feature_SIZE] ;										//Ȩ��w����