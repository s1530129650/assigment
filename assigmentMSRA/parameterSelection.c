#define _CRT_SECURE_NO_WARNINGS
#include"parameterSelection.h"

double  lamdaset[2] ={0.01,0.001};								//������
double Betaset[4] = {0.001,0.01,0.1,1};

void xiPaiRand(int randarray[],int Times);						//ϴ���㷨���ɷ�ΧΪ[0,Times-1]���ظ����������randarray
void Samping(int randArrayPostive[MAX_DATA_SIZE],int randArrayNegative[MAX_DATA_SIZE]);   ///ȡǰ70%Ϊѵ���� ��30%Ϊ��֤��
void computeRespectively(double LAmda,double BEta);				//�ֱ���㲻ͬ��������ȷ��
double lossFunction(double Lamda,double Beta);                  //����lossfunction��ֵ
void updateW(double Lamda,double Beta);                         //����Ȩ��w
double  ValidationAccuracytest();								//����֤���ϼ�����ȷ��

void computeFull(double LAmda,double BEta);				//��ȫ��ѵ�����Ļ����ϼ������Ų����õ���Ȩ��
double lossFunctionFull(double Lamda,double Beta);                  //��ȫ��ѵ�����Ļ����ϼ���lossfunction��ֵ
void updateWFull(double Lamda,double Beta);                         //��ȫ��ѵ�����Ļ����ϸ���Ȩ��w

void stratifiedSampling()			//�ֲ���� 
{
	int randArrayPositive[MAX_DATA_SIZE];				 //�������
	int randArrayNegative[MAX_DATA_SIZE];
	int i,j;
	
	memset(	postivefeatureVector,0,sizeof(	postivefeatureVector));//��ʼ��������������
	memset(	negativefeatureVector,0,sizeof(	negativefeatureVector));
	lenPositive = 0;     //��ʼ��������������
	lenNegative = 0;
	//�ֳ���������
	for(i = 0 ; i < trainRealNumRow; i++)
	{
		if(label[i] == 0)
		{
			 lenNegative++;
			for(j =0;j<feature_SIZE ;j++)
			negativefeatureVector[lenNegative-1][j] = trainFeatureVector[i][j];   //����������
		}
		else
		{
			lenPositive++;	
			for(j =0;j<feature_SIZE ;j++)
				postivefeatureVector[lenPositive-1][j] = trainFeatureVector[i][j];   //��������
		}
	}
	
	printf("��������%d��   ��������%d��\n", lenPositive, lenNegative);
	printf("\n");

  //��ӡpostivefeatureVector
	printf("postivefeatureVector�ǣ�\n");
	for ( i = 0; i <3000; i=i+1000 )
	{
		for(j=0;j<feature_SIZE;j++)
			printf( "%.2f ",postivefeatureVector[i][j] ); 	
			printf("\n");
		
	}
	printf("\n");
	
	//��ӡnegativefeatureVector
	printf("negativefeatureVector�ǣ�\n");
	for (  i = 0; i <3000; i=i+1000 )
	{
		for(j=0;j<feature_SIZE;j++)
			printf( "%.2f ", negativefeatureVector[i][j] ); 	
			printf("\n");
		
	}
	printf("\n");



	xiPaiRand(randArrayPositive,lenPositive);  //ϴ���㷨���ɲ��ظ��������
	xiPaiRand(randArrayNegative, lenNegative);                                       
	//ȡǰ70%������� Ϊѵ���� ��30%Ϊ��֤��
	Samping(randArrayPositive,randArrayNegative);

	//��ӡtraning set
	printf("�ֲ�����Ľ����(��ǰ����Ϊ��)��\n");
	printf("traning set�ǣ�\n");
	for ( i = 0; i <3; i++ )
	{
		for(j=0;j<feature_SIZE;j++)
			printf( "%.2f ", trainingFeatureVector[i][j] ); 	
			printf("\n");
		
	}
	printf("\n");
	//��ӡtraininglabel��ǩ
	printf("��ǩ�ǣ�\n");
	for ( i = 0; i <20000; i=i+1000 )
	{
		
			printf("%d\t",traininglabel[i]);
	}
	printf("\n");

	//��ӡ��֤��
	printf("validation set��(��ǰ����Ϊ��)��\n");
	for ( i = 0; i <3; i++ )
	{
		for(j=0;j<feature_SIZE;j++)
			printf( "%.2f ", ValidationFeatureVector[i][j] ); 	
			printf("\n");
	}
	printf("\n");

	//��ӡValidationlabel��ǩ
	printf("��ǩ�ǣ�\n");
	for ( i = 0; i <9000; i=i+1000 )
	{
		
			printf("%d\t",Validationlabel[i]);
	}
	printf("\n");
	
}
void xiPaiRand(int randarray[],int Times) //ϴ���㷨���ɷ�ΧΪ[0,Times-1]���ظ��Ļ�����randarray
{//randarray�����ɵ���������У����ɷ�ΧΪ[0,Times-1]
	
	int i,j,tmp,count;
	count =Times;
	for(i=0;i<Times;i++) //��ʼ���������
	{
		randarray[i]=i;
	}

	while(count--)		//�����ȡ����������������������
	{
		i=rand()%Times;
		j=rand()%Times;
		tmp=randarray[i];
		randarray[i]=randarray[j];
		randarray[j]=tmp;
	}

	//for test
	/*printf("���ɵ������Ϊ��\n");
	for(i=0;i<19;i++)
		printf("%d ",randarray[i]);
	puts("");*/
	
}
void Samping(int randArrayPostive[MAX_DATA_SIZE],int randArrayNegative[MAX_DATA_SIZE])   ///ȡǰ70%Ϊѵ���� ��30%Ϊ��֤��
{ //randArrayPostive��ΧΪ[0,����������-1]��������У�randArrayNegative��ΧΪ[0,����������-1]���������
	int i,j,k;
	int countPositive,countNegative;  //ѵ���������Ϊ��֤�����ԣ��ĳ���

	memset(	trainingFeatureVector,0,sizeof(	trainingFeatureVector));	//��ʼ��ѵ��������֤��
	memset(	ValidationFeatureVector,0,sizeof(ValidationFeatureVector));

	countPositive =  (int)lenPositive*0.7;
	//printf("countPositive ��%d.\n\n",countPositive );
	for(i=0;i<lenPositive;i++)
	{
		
		k = randArrayPostive[i];
		if( i < countPositive)
		{   traininglabel[i] = 1;
			for(j=0;j<feature_SIZE;j++)
			{trainingFeatureVector[i][j] = postivefeatureVector[k][j];} //�ֲ��ȡ���������õ�ѵ����
		}
		else
		{
			Validationlabel[i-countPositive] = 1;
			for(j=0;j<feature_SIZE;j++)
			{ValidationFeatureVector[i-countPositive][j] = postivefeatureVector[k][j];}//�ֲ��ȡ���������õ���֤��
		}	
	}

	countNegative =  (int)lenNegative*0.7;
	//printf("countNegative ��%d.\n\n",countNegative );
	for(i=0;i<lenNegative;i++)
	{
		
		k = randArrayNegative[i];
		if( i < countNegative)
		{    
			traininglabel[i+countPositive] = 0;
			for(j=0;j<feature_SIZE;j++)
			{trainingFeatureVector[i+countPositive][j] = negativefeatureVector[k][j];} //�ֲ��ȡ���������õ�ѵ����
		}
		else
		{
			Validationlabel[i+lenPositive-countPositive] = 0;
			for(j=0;j<feature_SIZE;j++)
			{ValidationFeatureVector[i+lenPositive-countPositive- countNegative][j] = negativefeatureVector[k][j];}//�ֲ��ȡ���������õ���֤��
		}	
	}
	lenTraining = countNegative+countPositive ;
	printf("training set�� %d��.\n\n",lenTraining  );
	lenValidation = lenNegative- countNegative+lenPositive-countPositive;
	printf("Validation set�� %d��.\n\n",lenValidation );
}

void computeWeight()//���㲻ͬ������Ȩ��
{
	FILE *fpweight = NULL; //��Ҫע��
	int i,j;
	double Accuracy[2][4];
	double maxAccuracy = 0;
	double paraLamda,paraBeta;
	double a=0;

	printf("��ȷ��Ϊ��\n");
	for(i=0;i<2;i++)
	{	for(j=0;j<4;j++)
		{    Accuracy[i][j]=0; 
	       
			computeRespectively(lamdaset[i],Betaset[j]);//���벻ͬ�Ĳ���������ȷ��
			Accuracy[i][j] = ValidationAccuracytest();
			printf("%.4f\n",Accuracy[i][j]);
		}
	}
	printf("\n");
	//�ĵõ���Ѳ���
	for(i=0;i<2;i++)
	{	for(j=0;j<4;j++)
		{    
			if(Accuracy[i][j]>maxAccuracy) 
			{
				maxAccuracy = Accuracy[i][j];
				paraLamda = lamdaset[i];
				paraBeta = Betaset[j];
			}
		}
	}
	printf("��Ѳ���Ϊ��lamda= %.4f\t beta = %.4f\n",paraLamda,paraBeta );
	printf("��ȷ��Ϊ %.4f\n\n",maxAccuracy  );
	
	//������Ѳ��� ��Ȩ��
	computeFull(paraLamda,paraBeta);
	fpweight = fopen("weight_and_parameter.txt","w+");//�򿪻����½�
    if(NULL ==  fpweight )
    {

        printf("weight_and_parameter.txt\n") ; //���ش������
		return ;
     }
	fprintf(fpweight ,"��Ѳ���Ϊ��lamda= %.4f\t beta = %.4f\n",paraLamda,paraBeta );
	fprintf(fpweight ,"Ȩ��ϵ��w��28ά��������Ϊ��\n" );
	 for (i = 0; i <  feature_SIZE; i++)
    {
		
		fprintf( fpweight ,"%.8f\t",w[i]); // ��ӡtraining����}
		
    }
	fclose(fpweight);
   fpweight = NULL; //��Ҫָ��գ������ָ��ԭ���ļ���ַ
   printf("Ȩ��ϵ��w����Ѳ����ºͦ��ѱ�����weight_and_parameter.txt�ĵ���\n\n");

	
}
void computeRespectively(double LAmda,double BEta)
{
	int i;
	double wt[feature_SIZE] ;  //���w������ǰһ�ε������
	double lossValue=0;         //lossfunction��ֵ
	double eplise = 0;          //���ε����õ���w�ı仯��С

	for(i=0;i<feature_SIZE;i++) //feature_SIZE�����������ĳ���
	{
		w[i] = 0.1;             //Ȩ�س�ʼΪ[0.1,0.1...0.1]
	}
	
	//������ֹ����
	while(lossValue<1e-10 || eplise <1e-10 )//����֮��w�ı仯��С ����lossvalue�����ֵ��С
	{
		eplise =0;
		 for(i=0;i<feature_SIZE;i++) //feature_SIZE�����������ĳ���
		{
			wt[i] = w[i];                 //���w������ǰһ�ε������
		}
		
		lossValue = lossFunction( LAmda,BEta);//����loss function��ֵ
		updateW( LAmda,BEta);		//����w
		//�������ǰ��ı仯��С
		 for(i=0;i<feature_SIZE;i++) //feature_SIZE�����������ĳ���
		{
			eplise =eplise+ fabs((wt[i] - w[i])); //�������ǰ��ı仯��С
		}  
	}
}
double lossFunction(double Lamda,double Beta)
{//����lossfunction��ֵ
	int i,j;
	double fxi,lossSum,weigh2Sum;           //f(xi) �� lossFunction��wƽ����ֵ 
	
	lossSum = 0;      //loss function��ֵ                     
	weigh2Sum = 0;    //��� w��ƽ�� ��ֵ
	for(i= 0;i<feature_SIZE;i++) //feature_SIZE�����������ĳ���
	{
		weigh2Sum = weigh2Sum +w[i]*w[i];//���� wi��ƽ���ۼӺ� ��ֵ
	}
	for(i=0;i<lenTraining;i++)
	{
		  fxi = 0;
          for(j=0;j<feature_SIZE;j++) //feature_SIZE�����������ĳ���
		  {
			  fxi = fxi + w[j]*trainingFeatureVector[i][j];		//����f(xi)
		  }
    lossSum = lossSum +(fxi-traininglabel[i])*(fxi-traininglabel[i]); //�õ�loss function��ֵ 
	}
	lossSum = lossSum/lenTraining + Lamda*weigh2Sum;
	return lossSum;//���صõ���loss function��ֵ 
}
void updateW(double Lamda,double Beta)
{  //����w��Ȩ��
	int i,j,k;
	double fxi;                 //f(xi)��ֵ
	double errorSum;           //f(xi)-yi��ֵ��֮��������ʾ�ݶ� 

	for(k=0;k<feature_SIZE;k++) //feature_SIZE�����������ĳ���
	{
		errorSum = 0;
        for(i=0;i<lenTraining;i++)
		{
		   fxi = 0;
           for(j=0;j<feature_SIZE;j++)
		   {
			  fxi = fxi + w[j]*trainingFeatureVector[i][j];		//����f(xi)
		   }
		   errorSum = errorSum +trainingFeatureVector[i][k]*(fxi-traininglabel[i]);
		}
	    errorSum = -2*errorSum/lenTraining + 2*Lamda*w[k];  //����õ��ݶ�
		w[k] = w[k]+ Beta*errorSum ;						//����w
		
	}
}
double  ValidationAccuracytest()
{//������֤���ϵ�׼ȷ��
	int i,j;
	double accuracy=0,count=0;   
	double fxi;
	int testValidationlabel[MAX_DATA_SIZE];								//�����֤����ǩ
	memset(	testValidationlabel,0,sizeof(testValidationlabel));    //��ʼ�����Խ���ı�ǩ
	//ʹ�����Ժ���Ԥ��label
	for(i=0;i<lenTraining;i++)
	{
		  fxi = 0;
          for(j=0;j<feature_SIZE;j++)
		  {
			  fxi = fxi + w[j]*ValidationFeatureVector[i][j];		//����f(xi)
		  }
   testValidationlabel[i]=(int)(fxi+0.5)>(int)fxi?(int)fxi+1:(int)fxi;//��f(xi)��ֵ������������

	}

	for(i=0;i<lenValidation;i++ )
	{
		if(testValidationlabel[i] == Validationlabel[i]) //���Ԥ����ȷ,��count��1
			count++;
	}
	accuracy = count/(double)lenValidation;  //�õ���ȷ��
	return accuracy;    // ���صõ�����ȷ��
}

void computeFull(double LAmda,double BEta)
{
	int i;
	double wt[feature_SIZE] ;  //���w������ǰһ�ε������
	double lossValue=0;         //lossfunction��ֵ
	double eplise = 0;          //���ε����õ���w�ı仯��С

	for(i=0;i<feature_SIZE;i++) //feature_SIZE�����������ĳ���
	{
		w[i] = 0.1;             //Ȩ�س�ʼΪ[0.1,0.1...0.1]
	}
	
	//������ֹ����
	while(lossValue<1e-10 || eplise <1e-10 )//����֮��w�ı仯��С ����lossvalue�����ֵ��С
	{
		eplise =0;
		 for(i=0;i<feature_SIZE;i++) //feature_SIZE�����������ĳ���
		{
			wt[i] = w[i];                 //���w������ǰһ�ε������
		}
		
		lossValue = lossFunctionFull( LAmda,BEta);//����loss function��ֵ
		updateWFull( LAmda,BEta);		//����w
		//�������ǰ��ı仯��С
		 for(i=0;i<feature_SIZE;i++) //feature_SIZE�����������ĳ���
		{
			eplise =eplise+ fabs((wt[i] - w[i])); //�������ǰ��ı仯��С
		}  
	}
}
double lossFunctionFull(double Lamda,double Beta)
{//����lossfunction��ֵ
	int i,j;
	double fxi,lossSum,weigh2Sum;           //f(xi) �� lossFunction��wƽ����ֵ 
	
	lossSum = 0;      //loss function��ֵ                     
	weigh2Sum = 0;    //��� w��ƽ�� ��ֵ
	for(i= 0;i<feature_SIZE;i++) //feature_SIZE�����������ĳ���
	{
		weigh2Sum = weigh2Sum +w[i]*w[i];//���� wi��ƽ���ۼӺ� ��ֵ
	}
	for(i=0;i<trainRealNumRow;i++)
	{
		  fxi = 0;
          for(j=0;j<feature_SIZE;j++) //feature_SIZE�����������ĳ���
		  {
			  fxi = fxi + w[j]*trainFeatureVector[i][j];		//����f(xi)
		  }
    lossSum = lossSum +(fxi-label[i])*(fxi-label[i]); //�õ�loss function��ֵ 
	}
	lossSum = lossSum/trainRealNumRow + Lamda*weigh2Sum;
	return lossSum;//���صõ���loss function��ֵ 
}
void updateWFull(double Lamda,double Beta)
{  //����w��Ȩ��
	int i,j,k;
	double fxi;                 //f(xi)��ֵ
	double errorSum;           //f(xi)-yi��ֵ��֮��������ʾ�ݶ� 

	for(k=0;k<feature_SIZE;k++) //feature_SIZE�����������ĳ���
	{
		errorSum = 0;
        for(i=0;i<trainRealNumRow;i++)
		{
		   fxi = 0;
           for(j=0;j<feature_SIZE;j++)
		   {
			  fxi = fxi + w[j]*trainFeatureVector[i][j];		//����f(xi)
		   }
		   errorSum = errorSum +trainFeatureVector[i][k]*(fxi-label[i]);
		}
	    errorSum = -2*errorSum/trainRealNumRow + 2*Lamda*w[k];  //����õ��ݶ�
		w[k] = w[k]+ Beta*errorSum ;						//����w
		
	}
}

