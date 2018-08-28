#define _CRT_SECURE_NO_WARNINGS
#include"Datapreprocessing.h"
typedef struct{
	 double weight;
     int parent,lchild,rchild;
}HTNode;  //�շ������ṹ  weight����Ȩ�أ�parent,lchild,rchild�ֱ��Ǹ�ĸ�������Һ��ӽڵ㣬ע��lchild��Ȩ��С��rchlid��Ȩ��




int getAttriRespectively(char init[MAX_DATA_SIZE][MAX_char_SIZE],char treat[MAX_kind_SIZE][MAX_char_SIZE] ,double overrate[MAX_kind_SIZE]);//�ֱ����������,���ͳ���
void oneHotEncodeRespectively(char init[MAX_DATA_SIZE][MAX_char_SIZE],char mask[MAX_kind_SIZE][MAX_char_SIZE],int count,int encode[MAX_DATA_SIZE][MAX_encode_SIZE]);//�Ը������Զ�������
void HuffmanCodingRespectively(HTNode HT[],char init[MAX_DATA_SIZE][MAX_char_SIZE],int encode[MAX_DATA_SIZE][MAX_encode_SIZE],double weight[],int count,char Alpha[MAX_kind_SIZE][MAX_char_SIZE]);//����������
void normalizationrespectively(double data[],double dataencode[]);//�ֱ�����ݽ��й�һ��
void encodeText2numRespectively(int length,char text[MAX_DATA_SIZE][MAX_char_SIZE],int data2number[MAX_DATA_SIZE][MAX_encode_SIZE],
								char mask[MAX_DATA_SIZE][MAX_char_SIZE],int maskcode[MAX_DATA_SIZE][MAX_encode_SIZE]);//���������ı������ֱ���֮��ı���
void getAttriNum()//�õ��������Ե������Լ�������
{
	int t;
	//ͳ��workclass�����
	trainAttriTextData.lenWorkclass=getAttriRespectively(trainDATA.workclass,trainAttriTextData.workclass,trainover50Rate.rateWorkclass); //ͳ��workclass�����
	
    printf("workclass��%d�֣��ֱ��ǣ� \n",trainAttriTextData.lenWorkclass);
	for(t=0;t<trainAttriTextData.lenWorkclass;t++)
	{
		trainover50Rate.rateWorkclass[t] = trainover50Rate.rateWorkclass[t]/trainRealNumRow;
		printf("%s\t\t\t label over50k��ռ %.4f\n",trainAttriTextData.workclass[t],trainover50Rate.rateWorkclass[t]);
	}
	printf("\n");
	
	//ͳ��education�����
	trainAttriTextData.lenEducation=getAttriRespectively(trainDATA.education,trainAttriTextData.education,trainover50Rate.rateEducation); //ͳ��workclass�����
	
    printf("education��%d�֣��ֱ��ǣ�    \n",trainAttriTextData.lenEducation);
	for(t=0;t<trainAttriTextData.lenEducation;t++)
	{
		trainover50Rate.rateEducation[t] = trainover50Rate.rateEducation[t]/trainRealNumRow;
		printf("%s\t\t\t label over50k��ռ %.4f\n",trainAttriTextData.education[t],trainover50Rate.rateEducation[t]);
	}
	printf("\n");
	
	//ͳ��maritalStatus�����
	trainAttriTextData.lenMaritalStatus=getAttriRespectively(trainDATA.maritalStatus,trainAttriTextData.maritalStatus,trainover50Rate.rateMaritalStatus); //ͳ��workclass�����
	
    printf("maritalStatus��%d�֣�    \n",trainAttriTextData.lenMaritalStatus);
	for(t=0;t<trainAttriTextData.lenMaritalStatus;t++)
	{
		trainover50Rate.rateMaritalStatus[t] = trainover50Rate.rateMaritalStatus[t]/trainRealNumRow;
		//printf("%s\t\t\t label over50k��ռ%.4f\n",trainAttriTextData.maritalStatus[t],trainover50Rate.rateMaritalStatus[t]);
	}
	printf("\n");
	
	
	//ͳ�� occupation�����
	trainAttriTextData.lenOccupation =getAttriRespectively(trainDATA.occupation,trainAttriTextData.occupation,trainover50Rate.rateOccupation); //ͳ��workclass�����
	
    printf("occupation��%d��    \n",trainAttriTextData.lenOccupation);
	for(t=0;t<trainAttriTextData.lenOccupation;t++)
	{
		trainover50Rate.rateOccupation[t] = trainover50Rate.rateOccupation[t]/trainRealNumRow;
		//printf("%s\n",trainAttriTextData.occupation[t]);
	}
	printf("\n");
	

	//ͳ�� relationship�����
	trainAttriTextData.lenRelationship =getAttriRespectively(trainDATA.relationship,trainAttriTextData.relationship,trainover50Rate.rateRelationship); //ͳ��workclass�����
	
    printf("relationship��%d��   \n",trainAttriTextData.lenRelationship);
	for(t=0;t<trainAttriTextData.lenRelationship;t++)
	{
		trainover50Rate.rateRelationship[t] = trainover50Rate.rateRelationship[t]/trainRealNumRow;
		//printf("%s\n",trainAttriTextData.relationship[t]);
	}
	printf("\n");
	

	//ͳ�� race�����
	trainAttriTextData.lenRace =getAttriRespectively(trainDATA.race,trainAttriTextData.race,trainover50Rate.rateRace); //ͳ��workclass�����
	
    printf("race��%d�� \n",trainAttriTextData.lenRace);
	for(t=0;t<trainAttriTextData.lenRace;t++)
	{
		trainover50Rate.rateRace[t] = trainover50Rate.rateRace[t]/trainRealNumRow;
		//printf("%s\n",trainAttriTextData.race[t]);
	}
	printf("\n");
	

	//ͳ�� sex�����
	trainAttriTextData.lenSex =getAttriRespectively(trainDATA.sex,trainAttriTextData.sex,trainover50Rate.rateSex); //ͳ��workclass�����
	
    printf("race��%d�� \n",trainAttriTextData.lenSex);
	for(t=0;t<trainAttriTextData.lenSex;t++)
	{
		trainover50Rate.rateSex[t] = trainover50Rate.rateSex[t]/trainRealNumRow;
		//printf("%s\n",trainAttriTextData.sex[t]);
	}
	printf("\n");
	

	//ͳ��nativeCountry�����
	trainAttriTextData.lenNativeCountry =getAttriRespectively(trainDATA.nativeCountry,trainAttriTextData.nativeCountry,trainover50Rate.rateNativeCountry); //ͳ��workclass�����
	
    printf("nativeCountry��%d��  \n",trainAttriTextData.lenNativeCountry);
	for(t=0;t<trainAttriTextData.lenNativeCountry;t++)
	{
		trainover50Rate.rateNativeCountry[t] = trainover50Rate.rateNativeCountry[t]/trainRealNumRow;
		//printf("%s\n",trainAttriTextData.nativeCountry[t]);
	}
	printf("\n");
	
}  
int getAttriRespectively(char init[MAX_DATA_SIZE][MAX_char_SIZE],char treat[MAX_kind_SIZE][MAX_char_SIZE] ,double overrate[MAX_kind_SIZE] ) //�ֱ����������,���ͳ���
{//��workclassΪ�� init�����csv���ȡ��ԭʼ���ݣ�treat��Ҫ ��õ�workclass�����������overrate�Ǹ�����������50k�ı���
	//����ֵΪk
	int i,j,k=1;
	strcpy(treat[0],init[0]);//�����һ������
	overrate[0] = 1;
    for(i=1;i<trainRealNumRow;i++)
    {
    	for(j=0;j<k;j++)
    	{
    		if(strcmp(init[i],treat[j]) == 0)  //����Ժ���ֵ�������֮ǰ�����಻�ظ��򱣴棬�򱣴������
    		{
				if(label[i]>0)
					{overrate[j]=overrate[j]+1;} //Ϊ�˺����Ļ�����-one hot���� ͳ�������и�������label����50k��������
    			break;
			}
		}
		if(j>=k)              //k��Ŀǰ����������j>k ������������֮ǰδ���֣�Ӧ�ñ���
		{   overrate[j] =0;
		    if(label[i]>0)
			{overrate[j]=overrate[j]+1; }  //ͳ�������и�������label����50k������
			strcpy(treat[k],init[i]);      //����������뵽���༯��
			k++;	
		}
		
	}
	return k;   //�����������
}
void oneHotEncode() //�õ��������Ե�onehot����  ��ʵ������ֻ��sex���������
{
	int i,j;
	
	//�õ�sex��one-hot���� sex ֻ���������ܼ� maleΪ10 female��01
	oneHotEncodeRespectively(trainDATA.sex,trainAttriTextData.sex,trainAttriTextData.lenSex,trainDataEncode.encodeSex);
	
	printf("sex��one-hot����Ϊ��(��ǰ�˸�Ϊ��)\n");
	for ( i = 0; i < 8; i++ )
	{
		printf( "%s:\t", trainDATA.sex[i] );
		for(j=0;j<trainAttriTextData.lenSex;j++)
      	  {
			  
			printf( "%d ", trainDataEncode.encodeSex[i][j] ); 
     		
	 		 }
  		printf("\n");
	} 
	printf("\n");//for test 
	
}
void oneHotEncodeRespectively(char init[MAX_DATA_SIZE][MAX_char_SIZE],char mask[MAX_kind_SIZE][MAX_char_SIZE],int count,int encode[MAX_DATA_SIZE][MAX_encode_SIZE]) //�Ը������Զ�������
{ //�Ը������Զ������룬��workclassΪ�� ��init�����csv���ȡ��ԭʼ���ݣ�mask����֮ǰ�õ���workclass���������count��ʵ�����ݳ��ȣ�encode��init�ı���
	int i,j;

		for(i=0;i<trainRealNumRow;i++)
	{
		for(j=0;j<count;j++)
		{    encode[i][j] = 0;
			if(strcmp(mask[j],init[i]) == 0)  
		 		encode[i][j]=1;
		}	

	}
}

void HuffmanCoding() //�õ��������ԵĻ�����-onehot����
{//���ǽ�����������Ȩ�ش���ַ��̵ı�������ԣ������볤�Ȳ������ݹ�Ϊһ�࣬���˱���
	int i,j;
	HTNode tree[2*MAX_kind_SIZE-1];    //���������ĳ�ʼ��
    
	//workclass�Ļ�����-onehot����
	memset(tree,0,sizeof(tree));
	
	memset(trainDataEncode.encodeWorkclass,0,sizeof(trainDataEncode.encodeWorkclass));//��ʼ��Ϊ0
	HuffmanCodingRespectively(tree,trainDATA.workclass,trainDataEncode.encodeWorkclass , trainover50Rate.rateWorkclass, trainAttriTextData.lenWorkclass, trainAttriTextData.workclass);
	
	printf("workclass�ĵȳ�������-onehot���룺����ǰ8��Ϊ����    \n");
	for ( i = 0; i < 8; i++ )
	{
		for(j=0;j<MAX_encode_SIZE;j++)
      	  {
			printf( "%d ", trainDataEncode.encodeWorkclass[i][j] ); 
     		
	 		 }
  		printf("\n");
	}

	//Education�Ļ�����-onehot����
	memset(tree,0,sizeof(tree));
	memset(trainDataEncode.encodeEducation,0,sizeof(trainDataEncode.encodeEducation));
	HuffmanCodingRespectively(tree,trainDATA.education,trainDataEncode.encodeEducation , trainover50Rate.rateEducation, trainAttriTextData.lenEducation, trainAttriTextData.education);
	/*printf("Education�ĵȳ�������-onehot���룺����ǰ8��Ϊ����    \n");
	for ( i = 0; i < 8; i++ )
	{
		for(j=0;j<MAX_encode_SIZE;j++)
      	  {
			printf( "%d ", trainDataEncode.encodeEducation[i][j] ); 
     		
	 		 }
  		printf("\n");
	}*/

	//maritalStatus�Ļ�����-onehot����
	memset(tree,0,sizeof(tree));
	memset(trainDataEncode.encodeMaritalStatus,0,sizeof(trainDataEncode.encodeMaritalStatus));
	HuffmanCodingRespectively(tree,trainDATA.maritalStatus,trainDataEncode.encodeMaritalStatus , trainover50Rate.rateMaritalStatus, trainAttriTextData.lenMaritalStatus, trainAttriTextData.maritalStatus);
	/*printf("maritalStatus�ĵȳ�������-onehot���룺����ǰ8��Ϊ����    \n");
	for ( i = 0; i < 8; i++ )
	{
		for(j=0;j<MAX_encode_SIZE;j++)
      	  {
			printf( "%d ", trainDataEncode.encodeMaritalStatus[i][j] ); 
     		
	 		 }
  		printf("\n");
	}*/

	//occupation�Ļ�����-onehot����
	memset(tree,0,sizeof(tree));
	memset(trainDataEncode.encodeOccupation,0,sizeof(trainDataEncode.encodeOccupation));
	HuffmanCodingRespectively(tree,trainDATA.occupation,trainDataEncode.encodeOccupation , trainover50Rate.rateOccupation, trainAttriTextData.lenOccupation, trainAttriTextData.occupation);
	/*printf("occupation�ĵȳ�������-onehot���룺����ǰ8��Ϊ����    \n");
	for ( i = 0; i < 8; i++ )
	{
		for(j=0;j<MAX_encode_SIZE;j++)
      	  {
			printf( "%d ", trainDataEncode.encodeOccupation[i][j] ); 
     		
	 		 }
  		printf("\n");
	 }*/

   //relationship�Ļ�����-onehot����
	memset(tree,0,sizeof(tree));
	memset(trainDataEncode.encodeRelationship,0,sizeof(trainDataEncode.encodeRelationship));
	HuffmanCodingRespectively(tree,trainDATA.relationship,trainDataEncode.encodeRelationship , trainover50Rate.rateRelationship, trainAttriTextData.lenRelationship, trainAttriTextData.relationship);
	/*printf("relationship�ĵȳ�������-onehot���룺����ǰ8��Ϊ����    \n");
	for ( i = 0; i < 8; i++ )
	{
		for(j=0;j<MAX_encode_SIZE;j++)
      	  {
			printf( "%d ", trainDataEncode.encodeRelationship[i][j] ); 
     		
	 		 }
  		printf("\n");
	}*/

	//race�Ļ�����-onehot����
	memset(tree,0,sizeof(tree));
	memset(trainDataEncode.encodeRace,0,sizeof(trainDataEncode.encodeRace));
	HuffmanCodingRespectively(tree,trainDATA.race,trainDataEncode.encodeRace , trainover50Rate.rateRace, trainAttriTextData.lenRace, trainAttriTextData.race);
	/* printf("race�ĵȳ�������-onehot���룺����ǰ8��Ϊ����    \n");
	for ( i = 0; i < 8; i++ )
	{
		for(j=0;j<MAX_encode_SIZE;j++)
      	  {
			printf( "%d ", trainDataEncode.encodeRace[i][j] ); 
     		
	 		 }
  		printf("\n");
	}*/

	//nativeCountry�Ļ�����-onehot����
	memset(tree,0,sizeof(tree));
	memset(trainDataEncode.encodeNativeCountry,0,sizeof(trainDataEncode.encodeNativeCountry));
	HuffmanCodingRespectively(tree,trainDATA.nativeCountry,trainDataEncode.encodeNativeCountry , trainover50Rate.rateNativeCountry, trainAttriTextData.lenNativeCountry, trainAttriTextData.nativeCountry);
	/* printf("nativeCountry�ĵȳ�������-onehot���룺����ǰ8��Ϊ����    \n");
	for ( i = 0; i < 8; i++ )
	{
		for(j=0;j<MAX_encode_SIZE;j++)
      	  {
			printf( "%d ", trainDataEncode.encodeNativeCountry[i][j] ); 
     		
	 		 }
  		printf("\n");
	}*/

}

void HuffmanCodingRespectively(HTNode HT[],char init[MAX_DATA_SIZE][MAX_char_SIZE],int encode[MAX_DATA_SIZE][MAX_encode_SIZE],double weight[],int count,char mask[MAX_kind_SIZE][MAX_char_SIZE])
{
	//HTΪ�������� initΪĳ�������������ԭʼ���� encodeΪ�������µĶ��ȱ��� weightΪÿ���ַ����ֵ�Ƶ�ʡ�Ȩ�� countΪ������������������ALpha��Ϊ�������µ��������
	double HC[2*MAX_kind_SIZE-1]={0};   //���ÿ���ڵ�ı���
	int m,i,j,c,f;
    int s1,s2;
	double m1,m2;
	if( count<=1) return ;
	m=2* count-1;
		
	for(i=1;i<= count;++i) 
	{HT[i].weight=weight[i-1];
	
	}
	for(i= count+1;i<=m;++i){                         //�����շ�����
	  
	   s1=s2=0;m1=m2=3;
	   for(j=1;j<i;++j)
	   {
		   if(HT[j].parent==0&&HT[j].weight<m1)    //ȨֵС��Ϊ��ڵ㣬Ȩֵ���Ϊ�ҽڵ�
		   {m2=m1;s2=s1;m1=HT[j].weight;s1=j;}
		   else if(HT[j].weight<m2&&HT[j].parent==0)   
		   {m2=HT[j].weight;s2=j;}
	   }
	   HT[s1].parent=i;HT[s2].parent=i; //��Ȩֵ��С�������ڵ�Ȩ����ӣ���Ϊ�丸ĸ�ڵ��Ȩ��
	   HT[i].lchild=s1;HT[i].rchild=s2;
	   HT[i].weight=HT[s1].weight+HT[s2].weight;
	 
	}//�������
	//��Ҷ�ӵ���������ÿ���ַ��ĺշ�������
	for(i=1;i<= count;++i){
		for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
		{
			if(HT[f].lchild==c) 
				HC[i-1] = HC[i-1]+1.1;//ȨֵС��Ϊ��ڵ㣬Ȩֵ���Ϊ�ҽڵ�,������Ǹ��ҽڵ��С��Ȩ��
			else 
				HC[i-1] = HC[i-1]+1;
		}	
		
		
	}
   //һ�¾�������onehot���룬��Ϊ����ֻ�������࣬���ÿһ���Ӧһ�ֱ���ֱ�Ϊ[1 0 0 ]��[0 1 0 ]��[0 0 1]��
	for(i=0;i< trainRealNumRow;i++)
	{
		for(j=0;j<count;j++)
		{
			if(strcmp(init[i],mask[j]) == 0) 
			{
				if(HC[j] <= 2)            //��Ȩֵ��������2�ı���Ϊ[1 0 0]
                  encode[i][0]=1; 
			    else
					{
						if(HC[j] <= 4 )    //��Ȩֵ����2С��4�ı���Ϊ[0 1 0]
							encode[i][1]=1;
						else 
							encode[i][2]=1; //��Ȩֵ����4�ı���Ϊ[0 0 1]
					}
				break;
			}
		}
	}
}//HuffmanTree

void normalization() //���������ݽ��й�һ��
{
	int i;

	//��age���й�һ��
    normalizationrespectively(trainDATA.age,trainDataEncode.age);
	printf("\n");
	printf("��age���й�һ���������Ϊ��(��ǰ�˸�Ϊ��)\n");
	for ( i = 0; i < 8; i++ )
	{	
		printf( "%.4f\t",trainDataEncode.age[i] ); 
	} 
	printf("\n");
	printf("\n");
	//for test 


	//��educationNum���й�һ��
	//printf("educationNum��");
    normalizationrespectively(trainDATA.educationNum,trainDataEncode.educationNum);
	/*printf("\n");
	printf("��educationNum���й�һ���������Ϊ��(��ǰ�˸�Ϊ��)\n");
	for ( i = 0; i < 8; i++ )
	{	
		printf( "%.4f\t",trainDataEncode.educationNum[i] ); // a[ 0 ] ���ǵ�һ��
	} 
	printf("\n");//for test 
	*/

	//��capitalGain���й�һ��
	//printf("capitalGain��");
    normalizationrespectively(trainDATA.capitalGain,trainDataEncode.capitalGain);
	/*printf("\n");
	printf("��capitalGaine���й�һ���������Ϊ��(��ǰ�˸�Ϊ��)\n");
	for ( i = 0; i < 8; i++ )
	{	
		printf( "%.4f\t",trainDataEncode.capitalGain[i] ); // a[ 0 ] ���ǵ�һ��
	} 
	printf("\n");//for test 
	*/

	//��capitalLoss���й�һ��
	//printf("capitalLoss��");
    normalizationrespectively(trainDATA.capitalLoss,trainDataEncode.capitalLoss);
	/*printf("\n");
	printf("��capitalLoss���й�һ���������Ϊ��(��ǰ�˸�Ϊ��)\n");
	for ( i = 0; i < 8; i++ )
	{	
		printf( "%.4f\t",trainDataEncode.capitalLoss[i] ); // a[ 0 ] ���ǵ�һ��
	} 
	printf("\n");//for test 
	*/

    //��hoursPerWeek���й�һ��
	//printf("hoursPerWeek��");
    normalizationrespectively(trainDATA.hoursPerWeek,trainDataEncode.hoursPerWeek);
	/*printf("\n");
	printf("��hoursPerWeek���й�һ���������Ϊ��(��ǰ�˸�Ϊ��)\n");
	for ( i = 0; i < 8; i++ )
	{	
		printf( "%.4f\t",trainDataEncode.hoursPerWeek[i] ); // a[ 0 ] ���ǵ�һ��
	} 
	printf("\n");//for test 
	*/
	 
}

void normalizationrespectively(double data[],double dataencode[])
{//�����ݽ��й�һ���� data[]�ǹ�һ��ǰ�����ݣ�dataencode[]�ǹ�һ����[0,1]������
	double maxtemp=0,mintemp=100;
	int i;
	//������ֵ//�����Сֵ
	for(i=0;i< trainRealNumRow ;i++)
	{
		maxtemp = (data[i] > maxtemp? data[i] : maxtemp);		//������ֵ
		mintemp = (data[i] < mintemp? data[i] : mintemp);		//�����Сֵ
		
	}
	//printf("���ֵΪ %.4f   ��Сֵ��%.4f\n",maxtemp,mintemp);
	for(i=0;i< trainRealNumRow ;i++)
	{
		dataencode[i] = (data[i]-mintemp)/(maxtemp-mintemp); //��һ����[0,1]
	}	
}

void  getfeatureVector()//�õ���������
{

	int i,j;
	memset(	trainFeatureVector,0,sizeof(	trainFeatureVector));		 //��ʼ����������
	for (i=0;i< trainRealNumRow ;i++)
	{
		trainFeatureVector[i][0] = trainDataEncode.age[i];               //���������Ե�ֵ�ϲ���һ��õ���������
		for(j=1;j<4;j++)
			trainFeatureVector[i][j] = trainDataEncode.encodeWorkclass[i][j-1];
		for(j=1;j<4;j++)
			trainFeatureVector[i][j+3] = trainDataEncode.encodeEducation[i][j-1];
		trainFeatureVector[i][7] = trainDataEncode.educationNum[i];
		for(j=1;j<4;j++)
			trainFeatureVector[i][j+7] = trainDataEncode.encodeMaritalStatus[i][j-1];
		for(j=1;j<4;j++)
			trainFeatureVector[i][j+10] = trainDataEncode.encodeOccupation[i][j-1];
		for(j=1;j<4;j++)
			trainFeatureVector[i][j+13] = trainDataEncode.encodeRelationship[i][j-1];
		for(j=1;j<4;j++)
			trainFeatureVector[i][j+16] = trainDataEncode.encodeRace[i][j-1];
		for(j=1;j<3;j++)
			trainFeatureVector[i][j+19] = trainDataEncode.encodeSex[i][j-1];
		trainFeatureVector[i][22] = trainDataEncode.capitalGain[i];
		trainFeatureVector[i][23] = trainDataEncode.capitalLoss[i];
		trainFeatureVector[i][24] = trainDataEncode.hoursPerWeek[i];
		for(j=1;j<3;j++)
			trainFeatureVector[i][j+24] = trainDataEncode.encodeNativeCountry[i][j-1];
	}
	printf("�õ�����������(28ά)Ϊ������ǰ3��Ϊ����\n");
	for ( i = 0; i <3; i++ )
	{
		for(j=0;j<feature_SIZE;j++)
			printf( "%.2f ", trainFeatureVector[i][j] ); 	
			printf("\n");
	}
	printf("\n");
	
}

void saveText2num()	//�����ı������ֱ���֮��Ķ�Ӧת��
{
	int i,j,k;
	
	//workclass���ı������ֱ����Ӧ
	printf("workclass�ı����Ӧ��ϵΪ��\n");
	for(i=0;i<trainAttriTextData.lenWorkclass;i++)
	{
		strcpy(Text2Num.workclass[i],trainAttriTextData.workclass[i]);//��ʼ��workplace �洢�ı�������
	}
	for(i=0;i<trainNumRow;i++)
	{  
		for(k=0;k<trainAttriTextData.lenWorkclass;k++)
		{
				if(strcmp(Text2Num.workclass[k],trainDATA.workclass[i])==0)
				{
					for(j=0;j<MAX_encode_SIZE;j++)
					{Text2Num.encodeWorkclass[k][j] = trainDataEncode.encodeWorkclass[i][j];}//�����ı������ֱ���֮��Ķ�Ӧ��ϵ
				}
		}
	}
	//for test
	for(i=0;i<trainAttriTextData.lenWorkclass;i++)
	{
		printf("%s:\t",Text2Num.workclass[i]);
		for(j=0;j<MAX_encode_SIZE;j++)
		{
			printf("%d\t",Text2Num.encodeWorkclass[i][j] );
		}
		printf("\n");
	}
	printf("\n");

	//Education���ı������ֱ����Ӧ
	
	for(i=0;i<trainAttriTextData.lenEducation;i++)
	{
		strcpy(Text2Num.education[i],trainAttriTextData.education[i]);//��ʼ��workplace �洢�ı�������
	}
	for(i=0;i<trainNumRow;i++)
	{    
		
		for(k=0;k<trainAttriTextData.lenEducation;k++)
		{
				if(strcmp(Text2Num.education[k],trainDATA.education[i])==0)
				{
					
					for(j=0;j<MAX_encode_SIZE;j++)
					{Text2Num.encodeEducation[k][j] = trainDataEncode.encodeEducation[i][j];}//�����ı������ֱ���֮��Ķ�Ӧ��ϵ
				}
		}
	}
	/*
	printf("Education�ı����Ӧ��ϵΪ��\n");	
	for(i=0;i<trainAttriTextData.lenEducation;i++)
	{
		printf("%s:\t",Text2Num.education[i]);
		for(j=0;j<MAX_encode_SIZE;j++)
		{
			printf("%d\t",Text2Num.encodeEducation[i][j] );
		}
		printf("\n");
	}
	printf("\n");*/

	//maritalStatus���ı������ֱ����Ӧ
	for(i=0;i<trainAttriTextData.lenMaritalStatus;i++)
	{
		strcpy(Text2Num.maritalStatus[i],trainAttriTextData.maritalStatus[i]);//��ʼ��workplace �洢�ı�������
	}
	for(i=0;i<trainNumRow;i++)
	{    
		
		for(k=0;k<trainAttriTextData.lenMaritalStatus;k++)
		{
				if(strcmp(Text2Num.maritalStatus[k],trainDATA.maritalStatus[i])==0)
				{
					
					for(j=0;j<MAX_encode_SIZE;j++)
					{Text2Num.encodeMaritalStatus[k][j] = trainDataEncode.encodeMaritalStatus[i][j];}//�����ı������ֱ���֮��Ķ�Ӧ��ϵ
				}
		}
	}
	/*
	printf("maritalStatus�ı����Ӧ��ϵΪ��\n");	
	for(i=0;i<trainAttriTextData.lenMaritalStatus;i++)
	{
		printf("%s:\t",Text2Num.maritalStatus[i]);
		for(j=0;j<MAX_encode_SIZE;j++)
		{
			printf("%d\t",Text2Num.encodeMaritalStatus[i][j] );
		}
		printf("\n");
	}
	printf("\n");
	*/

	//occupation���ı������ֱ����Ӧ
	for(i=0;i<trainAttriTextData.lenOccupation;i++)
	{
		strcpy(Text2Num.occupation[i],trainAttriTextData.occupation[i]);//��ʼ��workplace �洢�ı�������
	}
	for(i=0;i<trainNumRow;i++)
	{    
		
		for(k=0;k<trainAttriTextData.lenOccupation;k++)
		{
				if(strcmp(Text2Num.occupation[k],trainDATA.occupation[i])==0)
				{
					
					for(j=0;j<MAX_encode_SIZE;j++)
					{Text2Num.encodeOccupation[k][j] = trainDataEncode.encodeOccupation[i][j];}//�����ı������ֱ���֮��Ķ�Ӧ��ϵ
				}
		}
	}
	/*
	printf("occupation�ı����Ӧ��ϵΪ��\n");	
	for(i=0;i<trainAttriTextData.lenOccupation;i++)
	{
		printf("%s:\t",Text2Num.occupation[i]);
		for(j=0;j<MAX_encode_SIZE;j++)
		{
			printf("%d\t",Text2Num.encodeOccupation[i][j] );
		}
		printf("\n");
	}
	printf("\n");*/

	//relationship���ı������ֱ����Ӧ
	for(i=0;i<trainAttriTextData.lenRelationship;i++)
	{
		strcpy(Text2Num.relationship[i],trainAttriTextData.relationship[i]);//��ʼ��workplace �洢�ı�������
	}
	for(i=0;i<trainNumRow;i++)
	{    
		
		for(k=0;k<trainAttriTextData.lenRelationship;k++)
		{
				if(strcmp(Text2Num.relationship[k],trainDATA.relationship[i])==0)
				{
					
					for(j=0;j<MAX_encode_SIZE;j++)
					{Text2Num.encodeRelationship[k][j] = trainDataEncode.encodeRelationship[i][j];}//�����ı������ֱ���֮��Ķ�Ӧ��ϵ
				}
		}
	}
	/*
	printf("relationship�ı����Ӧ��ϵΪ��\n");	
	for(i=0;i<trainAttriTextData.lenRelationship;i++)
	{
		printf("%s:\t",Text2Num.relationship[i]);
		for(j=0;j<MAX_encode_SIZE;j++)
		{
			printf("%d\t",Text2Num.encodeRelationship[i][j] );
		}
		printf("\n");
	}
	printf("\n");*/


	//race���ı������ֱ����Ӧ
	for(i=0;i<trainAttriTextData.lenRace;i++)
	{
		strcpy(Text2Num.race[i],trainAttriTextData.race[i]);//��ʼ��workplace �洢�ı�������
	}
	for(i=0;i<trainNumRow;i++)
	{    
		
		for(k=0;k<trainAttriTextData.lenRace;k++)
		{
				if(strcmp(Text2Num.race[k],trainDATA.race[i])==0)
				{
					
					for(j=0;j<MAX_encode_SIZE;j++)
					{Text2Num.encodeRace[k][j] = trainDataEncode.encodeRace[i][j];}//�����ı������ֱ���֮��Ķ�Ӧ��ϵ
				}
		}
	}
	
	printf("race�ı����Ӧ��ϵΪ��\n");	
	for(i=0;i<trainAttriTextData.lenRace;i++)
	{
		printf("%s:\t",Text2Num.race[i]);
		for(j=0;j<MAX_encode_SIZE;j++)
		{
			printf("%d\t",Text2Num.encodeRace[i][j] );
		}
		printf("\n");
	}
	printf("\n");

  //nativeCountry���ı������ֱ����Ӧ
	for(i=0;i<trainAttriTextData.lenNativeCountry;i++)
	{
		strcpy(Text2Num.nativeCountry[i],trainAttriTextData.nativeCountry[i]);//��ʼ��workplace �洢�ı�������
	}
	for(i=0;i<trainNumRow;i++)
	{    
		
		for(k=0;k<trainAttriTextData.lenNativeCountry;k++)
		{
				if(strcmp(Text2Num.nativeCountry[k],trainDATA.nativeCountry[i])==0)
				{
					
					for(j=0;j<MAX_encode_SIZE;j++)
					{Text2Num.encodeNativeCountry[k][j] = trainDataEncode.encodeNativeCountry[i][j];}//�����ı������ֱ���֮��Ķ�Ӧ��ϵ
				}
		}
	}
	/*
	printf("nativeCountry�ı����Ӧ��ϵΪ��\n");	
	for(i=0;i<trainAttriTextData.lenNativeCountry;i++)
	{
		printf("%s:\t",Text2Num.nativeCountry[i]);
		for(j=0;j<MAX_encode_SIZE;j++)
		{
			printf("%d\t",Text2Num.encodeNativeCountry[i][j] );
		}
		printf("\n");
	}
	printf("\n");*/

}

void encodeText2num()//�����ı������ֱ���֮��ı���,���ڲ��Լ�
{
	int i,j;
	//��workclass���б���
	memset(trainDataEncode.encodeWorkclass,0,sizeof(trainDataEncode.encodeWorkclass));
	encodeText2numRespectively(trainAttriTextData.lenWorkclass,trainDATA.workclass,trainDataEncode.encodeWorkclass,Text2Num.workclass,Text2Num.encodeWorkclass);
	//��Education���б���
	memset(trainDataEncode.encodeEducation,0,sizeof(trainDataEncode.encodeEducation));
	encodeText2numRespectively(trainAttriTextData.lenEducation,trainDATA.education,trainDataEncode.encodeEducation,Text2Num.education,Text2Num.encodeEducation);
	//��maritalStatus���б���
	memset(trainDataEncode.encodeMaritalStatus,0,sizeof(trainDataEncode.encodeMaritalStatus));
	encodeText2numRespectively(trainAttriTextData.lenMaritalStatus,trainDATA.maritalStatus,trainDataEncode.encodeMaritalStatus,Text2Num.maritalStatus,Text2Num.encodeMaritalStatus);
	//��occupation���б���
	memset(trainDataEncode.encodeOccupation,0,sizeof(trainDataEncode.encodeOccupation));
	encodeText2numRespectively(trainAttriTextData.lenOccupation,trainDATA.occupation,trainDataEncode.encodeOccupation,Text2Num.occupation,Text2Num.encodeOccupation);
	//��relationship���б���
	memset(trainDataEncode.encodeRelationship,0,sizeof(trainDataEncode.encodeRelationship));
	encodeText2numRespectively(trainAttriTextData.lenRelationship,trainDATA.relationship,trainDataEncode.encodeRelationship,Text2Num.relationship,Text2Num.encodeRelationship);
	//��race���б���
	memset(trainDataEncode.encodeRace,0,sizeof(trainDataEncode.encodeRace));
	encodeText2numRespectively(trainAttriTextData.lenRace,trainDATA.race,trainDataEncode.encodeRace,Text2Num.race,Text2Num.encodeRace);
	//��sex���б��� ������ֻ�ж�ά���Խ��м򵥵�one-hot����
	memset(trainDataEncode.encodeSex,0,sizeof(trainDataEncode.encodeSex));
	
	for(i=0;i<trainNumRow;i++)
	{    
		
		for(j=0;j<2;j++)
		{
				if(strcmp("Male",trainDATA.workclass[i])==0)
				{
					 Text2Num.encodeRace[i][0] =1 ;  //Male����Ϊ1 0 
					 Text2Num.encodeRace[i][1] =0 ;

				}
				else
				{
					Text2Num.encodeRace[i][0] =0 ;  //Female����Ϊ1 0 
					 Text2Num.encodeRace[i][1] =1 ;
				}
		}
	}
	//��nativeCountry���б���
	memset(trainDataEncode.encodeNativeCountry,0,sizeof(trainDataEncode.encodeNativeCountry));
	encodeText2numRespectively(trainAttriTextData.lenNativeCountry,trainDATA.nativeCountry,trainDataEncode.encodeNativeCountry,Text2Num.nativeCountry,Text2Num.encodeNativeCountry);
	

}
void encodeText2numRespectively(int length,char text[MAX_DATA_SIZE][MAX_char_SIZE],int data2number[MAX_DATA_SIZE][MAX_encode_SIZE],
								char mask[MAX_DATA_SIZE][MAX_char_SIZE],int maskcode[MAX_DATA_SIZE][MAX_encode_SIZE])				//���������ı������ֱ���֮��ı���
{//��workclassΪ��  lengthΪworkclass���е����������7��;text����Ҫ������ı����ݣ�data2number���ı����ݱ������������;maskhe maskcode���ı��Ͷ�Ӧ���ı��ı���
	int i,j,k;
	
	for(i=0;i<trainNumRow;i++)
	{    
		
		for(k=0;k<length;k++)
		{
				if(strcmp(mask[k],text[i])==0)
				{
					
					for(j=0;j<MAX_encode_SIZE;j++)
					{  data2number[i][j] = maskcode[k][j] ;}//�ı������ֱ���֮��Ķ�Ӧ��ϵ
				}
				
		}

	}

}


	
	
	

