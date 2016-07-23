#include "stdafx.h"
#include <cv.h>
#include <highgui.h>
#include <cmath>
#include <iostream>
using namespace cv;
using namespace std;

const int xmatrix = 640;
const double matrix = 0.5773; //tg (60/2) - ���� ������ ������
const double focus = 554; //�������� ���������� � ��������

double course(int x) //���������� � �������� �� ������ ���� �����������
{
	double cour;
	cour = 180 * atan((x-xmatrix/2)/focus)/3.1415;
	return cour;
}

int distanse(int H, int h) //H - ������ �������, L - ���������� �� �������, h - ������ �����������
{
	double dist;
	dist = H*focus/h;
	return dist;
}

int main()
{
	int a;
	cin>>a;
	cout<<course(a)<<endl;
	main();
}
