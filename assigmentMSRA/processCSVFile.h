#pragma once
#include <stdio.h>
#include <memory.h>		 // for memset
#include <stdlib.h>		 // for malloc, free
#include <string.h>		 // for strtok
#include "variant.h"	 //�ṹ���һЩ��������

/*
���ļ����ڵ�һ��Data Loading�����ݵ������������ᱣ����trainNumRow �� trainNumCol�У����������ݰ����Է��ౣ����trainDATA����ṹ�����棻

*/

int ReadCsvData(char* csvFilePath);           //��ȡCsv������
void  ShowCsvData();                          //ͨ������̨��ʾ��ȡ��csv����
int writeCsvData(char* csvFilePath);          //д��csv����
