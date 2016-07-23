#include "stdafx.h"
#include <cv.h>
#include <highgui.h>
#include <stdlib.h>
#include <stdio.h>
using namespace cv;

int main()
{
        // �������� ����� ������������ ������
        VideoCapture capture(0); //cvCaptureFromCAM( 0 );
      //  assert( capture );

        capture.set(CV_CAP_PROP_FRAME_WIDTH, 320);//1280); 
        capture.set(CV_CAP_PROP_FRAME_HEIGHT, 180);//960); 

        // ������ ������ � ������ �����
		double width = capture.get(CV_CAP_PROP_FRAME_WIDTH);
        double height = capture.get(CV_CAP_PROP_FRAME_HEIGHT);
        printf("[i] %.0f x %.0f\n", width, height );

        cv::Mat frame;

        namedWindow("capture", CV_WINDOW_AUTOSIZE);

        printf("[i] press Enter for capture image and Esc for quit!\n\n");

        int counter=0;
        char filename[512];
		cv::Mat mm;
        while(true){
                // �������� ����
                capture.retrieve(frame);

				cvtColor(frame, mm, CV_RGB2GRAY);
                // ����������
               imshow("capture", mm);
        
                char c = cvWaitKey(33);
                if (c == 27) { // ������ ESC
                        break;
                }
                else if(c == 13) { // Enter
                        // ��������� ���� � ����
                        sprintf(filename, "Poligon2.png", counter);
                        printf("[i] capture... %s\n", filename);
                        imwrite(filename, mm);
                        counter++;
                }
        }
        // ����������� �������
        capture.release();
        destroyWindow("capture");
        return 0;
}