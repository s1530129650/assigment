#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include"variant.h"  //��Žṹ�����

/*
Ϊ��֤�ֲ�����ı��������ǽ����ݼ���Ϊ�����������ϣ������postivefeatureVector��negativefeatureVector��	
��ϴ���㷨������������ֱ�����������г�ȡ70%��������Ϊѵ������ʣ���30%Ϊ��֤�����Դ����ֲ������
֮��ѡ��ͬ�Ĳ�����ѵ������ѵ��ģ�ͣ��õ�ѡ����Ѳ�����ȫ������������ģ�͵�ѵ����
�����Ų�����ѵ��������Ȩ�ر����ڡ�weight_and_parameter.txt����
*/

void  stratifiedSampling();          //�ֲ���� 
void  computeWeight();				//���㲻ͬ������Ȩ�ز�ѡ�����ŵĽ���ģ�͵�ѵ��
