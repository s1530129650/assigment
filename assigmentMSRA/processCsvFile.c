#define _CRT_SECURE_NO_WARNINGS
#include"processCSVFile.h"

int GetTotalLineCount(FILE* fp);              //����csv�ļ��е�������
int GetTotalColCount(FILE * fp);              //����csv�ļ��е����������Ե�һ�е�����Ϊ��׼��

//����csv�ļ��е�������
int GetTotalLineCount(FILE * fp)
{   
    int i = 0;
    char strLine[MAX_LINE_SIZE];                 //��Ŵ��ļ��ж������ַ�����
    fseek(fp,0,SEEK_SET);                       //�ض�λ���ϵ��ļ�ָ�� fpָ��SEEK_SET(��ͷ��+0 
    while (fgets(strLine, MAX_LINE_SIZE, fp))
        i++;                                      //��������
    fseek(fp,0,SEEK_SET);                        //��ԭfpָ�� 
    return i;
}

//����csv�ļ��е����������Ե�һ�е�����Ϊ��׼��
int GetTotalColCount(FILE * fp)
{   
    int i = 0;
    char strLine[MAX_LINE_SIZE];                 //��Ŵ��ļ��ж������ַ�����
    fseek(fp,0,SEEK_SET);                       //�ض�λ���ϵ��ļ�ָ�� fpָ��SEEK_SET(��ͷ��+0 
    if (fgets(strLine, MAX_LINE_SIZE, fp))
    {
        i=strlen(strLine)/2;          //��Ϊcsv�ļ��Զ���','��Ϊ�ָ��������Դ˴�����2,�����ܴ������⣬Ӧ����split��ͳ�ƣ��˴�ֻ���ᵽ������ܣ���δʹ��
    }
    else
    {
        fseek(fp,0,SEEK_SET);
        return -1;
    }
    fseek(fp,0,SEEK_SET);
    return i;
}


// ��csv�ļ��ж�ȡ����
int ReadCsvData(char* csvFilePath)
{
    FILE* fCsv;               //csvFilePath�ļ�ָ�� 
	char *err = " ?";              //�ָ�������ַ���Ϊ��������ɾ����������
    char strLine[MAX_LINE_SIZE];   //��Ŵ��ļ���ȡ����������

	 
    int i,j,k,t;
	char *ptr;						//�ָ�����ĵ����ַ�������
	char *tempString[15];          //��ʱ���ĳһ�зָ�������ַ�������
	int flag =1;                  //��־ ����ָ�������ַ���Ϊ����������flag��0
	

    // ���ļ�
    if( fopen_s( &fCsv, csvFilePath, "r" ) != 0 )
    {
        printf("open file %s failed",csvFilePath);
        return -1;
    }
    else
    {

        trainNumRow = GetTotalLineCount(fCsv); // ��ȡ���ݵ����� �����һ��
    
		fgets(strLine,MAX_LINE_SIZE,fCsv);		//ȥ����һ�У���Ϊ��һ���Ǳ�ͷ

        // ��ȡ����
        for (i = 0,k=0; i < trainNumRow; i++)			
        {   memset(tempString,'\0',sizeof(tempString)); //��tempString��ʼ��Ϊ��
			flag = 1;
            j=0;
            if(fgets(strLine,MAX_LINE_SIZE,fCsv))
            {
				
                ptr=strtok(strLine,",");  //�����ַ��������ַ���,��֮ǰ���ַ���ʣ�µı�������̬������
                while(ptr!=NULL)
                {
                    tempString[j]= ptr;				//���ַ�ת��Ϊint�������ݲ����浽������
                    j++;
                    ptr = strtok(NULL,",");                //�����ļ��ж�ȡ�ĵ�ǰ��ʣ���ַ����飬��ȡ�ַ���,��ǰ����ֽ�				
                }
				
				for(t=0;t<j;t++)	
				{
					if (strcmp(tempString[t],err) == 0)   //����ָ�������ַ���Ϊ����������flag��0
						{
							flag = 0;                      //Ϊ�˺���ɾ�����С������Ĵ�������
							break;
						}
				}

				if (flag == 0)                               ///ɾ��ɾ�����С������Ĵ�������
					continue;
				
				//���������ݰ����Է��ౣ����trainDATA����ṹ������
				trainDATA.age[k] = atoi(tempString[0]);
				strcpy(trainDATA.workclass[k],tempString[1]);
				strcpy(trainDATA.education[k] , tempString[2]);
				trainDATA.educationNum[k] = atoi(tempString[3]);
				strcpy(trainDATA.maritalStatus[k] , tempString[4]);
			    strcpy(trainDATA.occupation[k],tempString[5]);
				strcpy(trainDATA.relationship[k] ,tempString[6]);
				strcpy(trainDATA.race[k] , tempString[7]);
				strcpy(trainDATA.sex[k] , tempString[8]);
				trainDATA.capitalGain[k] = atoi(tempString[9]);
				trainDATA.capitalLoss[k] = atoi(tempString[10]);
				trainDATA.hoursPerWeek[k] =  atoi(tempString[11]);
				strcpy(trainDATA.nativeCountry[k],tempString[12]);
				label[k] = atoi(tempString[13]);
				k++;
				
            }
        }
		
    fclose(fCsv); //�ر��ļ�
    }
	trainRealNumRow = k; //�õ�ɾ�����������е�����
	
	printf("��������%d�������г���������� %d��\n",trainNumRow-1,trainNumRow-trainRealNumRow -1); //��ʾ�������
	printf("\n");

    return 1;
}

//ͨ������̨��ʾ��ȡ��csv����
void  ShowCsvData()                           
{
    int i;
   
    for (i = 0; i < trainRealNumRow ; i++)
    {
        printf("Line %d :",i+1);    //���ÿ�е��к� Line :

            printf("%f,%s,%s,%f,%s,%s,%s,%s,%s,%f,%f,%f,%s\n",trainDATA.age[i],trainDATA.workclass[i], 
		    trainDATA.education[i], trainDATA.educationNum[i], trainDATA.maritalStatus[i], trainDATA.occupation[i],
            trainDATA.relationship[i], trainDATA.race[i], trainDATA.sex[i], trainDATA.capitalGain[i], 
			trainDATA.capitalLoss[i], trainDATA.hoursPerWeek[i], trainDATA.nativeCountry[i] );  // ��ӡCSV����

        printf("\n");                           //�������
    }
}

 int writeCsvData(char* csvFilePath)          //������ȡ������д�뵽csv�ļ���
{

    FILE *fp = NULL; //��Ҫע��
	int i;
    fp = fopen(csvFilePath, "w");//�򿪻����½�
    if(NULL == fp)
    {

        return -1; //���ش������
     }
    for (i = 0; i < trainRealNumRow ; i++)
    {
		fprintf(fp,"%f %s %s %f %s %s %s %s %s %f %f %f %s\n",trainDATA.age[i],trainDATA.workclass[i], 
		trainDATA.education[i], trainDATA.educationNum[i], trainDATA.maritalStatus[i], trainDATA.occupation[i],
        trainDATA.relationship[i], trainDATA.race[i], trainDATA.sex[i], trainDATA.capitalGain[i], 
		trainDATA.capitalLoss[i], trainDATA.hoursPerWeek[i], trainDATA.nativeCountry[i] );  // ��ӡCSV����
    }

   fclose(fp);
   fp = NULL; //��Ҫָ��գ������ָ��ԭ���ļ���ַ
   return 0;
 }
