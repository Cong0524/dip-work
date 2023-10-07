/*===========================================================================
  This demonstrative example is provided by the teaching assistant,
  Mr. Shih-Hung Liao (���@��), and modified by the instructor, Prof. Lan.

  (1) It can be compiled and executed correctly under the DEV-C++, and Visual C++
      environments.
  (2) In order to run this program, you should also have the "bmp.h" and
      "bmp.cpp" files installed in your current directory or whichever directory
      the C++ compiler is directed to search for.
  (3) The DEV-C++ is a free C++ development environment that is recommended for
      this course. Refer to http://www.bloodshed.net/dev/devcpp.html.

                             Apr. 3, 2006
============================================================================*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "bmp.cpp"

using namespace std;

int R[MaxBMPSizeX][MaxBMPSizeY]; // MaxBMPSizeX and MaxBMPSizeY are defined in "bmp.h"
int G[1024][1024];
int B[1024][1024];
int r[MaxBMPSizeX][MaxBMPSizeY];
int g[1024][1024];
int b[1024][1024];

int main(int argc, char *argv[])
{
	int width, height;
	int i, j;
	int tempR[624][647] ;
	// �}�Ҩ�Ū�����m(24bits)bmp �v������
	// RGB �T�� channel ���Ȧs�J R, G, B �T�Ӧۭq���}�C��
	// �}�C�j�p���o�j�� 1024x1024 (�ثe�]�w) 
	// �Y�ݭn��j���v��size�A�i�Nbmp.h���� MaxBMPSizeX �P MaxBMPSizeY ���s�]�w 
	//open_bmp("lena.bmp", R, G, B, width, height); for true color images
	open_bmp("noisy_rectangle.bmp", R, R, R, height, width); // for gray images
	// The starting pixel of a bmp image is at the bottom-left corner, which has 
	// coordinates x=0 and y=0.  The last pixel is at the top-right corner.

    //*----------------------------------------------------------------------------
	for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
        	 tempR[i][j] = R[i][j];
        	 //cout << "tmp = " << tempR[i][j] << endl;
        	 //if (R[i][i] != 0)printf("tmp = %d\n", R[i][j]);
        }
    }
	
  	for (int k = 0; k < 20; k++){
		for (int i = 0; i < height; i++) {
	        for (int j = 0; j < width; j++) {
	        	 tempR[i][j] = R[i][j];
	        	 //cout << "tmp = " << tempR[i][j] << endl;
	        	 //if (R[i][i] != 0)printf("tmp = %d\n", R[i][j]);
	        }
	    }	
	 	for (int i = 1; i < height - 1; i++) {
	        for (int j = 1; j < width - 1; j++) {
	            if (tempR[i][j] == 255 && (
					tempR[i - 1][j - 1] == 0 ||
					tempR[i - 1][j]     == 0 ||
	                tempR[i - 1][j + 1] == 0 ||
					tempR[i][j - 1]     == 0 ||
					tempR[i][j + 1]     == 0 ||
	                tempR[i + 1][j - 1] == 0 ||
					tempR[i + 1][j]     == 0 ||
					tempR[i + 1][j + 1] == 0))
				{
	                R[i][j] = 0;
	            }
	        }
	    }
	}
  
  	for (int k = 0; k < 40; k++){
		for (int i = 0; i < height; i++) {
	        for (int j = 0; j < width; j++) {
	        	 tempR[i][j] = R[i][j];
	        	 //cout << "tmp = " << tempR[i][j] << endl;
	        	 //if (R[i][i] != 0)printf("tmp = %d\n", R[i][j]);
	        }
	    }	
		
	 	for (int i = 1; i < height - 1; i++) {
	        for (int j = 1; j < width - 1; j++) {
	        if (tempR[i][j] == 0 && (
					tempR[i - 1][j - 1] == 255 ||
					tempR[i - 1][j]     == 255 ||
	        tempR[i - 1][j + 1] == 255 ||
					tempR[i][j - 1]     == 255 ||
					tempR[i][j + 1]     == 255 ||
	        tempR[i + 1][j - 1] == 255 ||
					tempR[i + 1][j]     == 255 ||
					tempR[i + 1][j + 1] == 255))
				{
	                R[i][j] = 255;
	            }
	        }
	    }
	}
	
	for (int k = 0; k < 20; k++){
		for (int i = 0; i < height; i++) {
	        for (int j = 0; j < width; j++) {
	        	 tempR[i][j] = R[i][j];
	        	 //cout << "tmp = " << tempR[i][j] << endl;
	        	 //if (R[i][i] != 0)printf("tmp = %d\n", R[i][j]);
	        }
	    }	
	 	for (int i = 1; i < height - 1; i++) {
	        for (int j = 1; j < width - 1; j++) {
	            if (tempR[i][j] == 255 && (
					tempR[i - 1][j - 1] == 0 ||
					tempR[i - 1][j]     == 0 ||
	                tempR[i - 1][j + 1] == 0 ||
					tempR[i][j - 1]     == 0 ||
					tempR[i][j + 1]     == 0 ||
	                tempR[i + 1][j - 1] == 0 ||
					tempR[i + 1][j]     == 0 ||
					tempR[i + 1][j + 1] == 0))
				{
	                R[i][j] = 0;
	            }
	        }
	    }
	}
	// �x�s�B�z���G�ܷs�����ɤ�
	//save_bmp("lenna_new1.bmp", r, g, b); // for true color images
	save_bmp("new_noisy_rectangle.bmp", R, R, R); // for gray images
	printf("Job Finished!\n");
	//printf("tmp = %d\n", 10);

	// ���� bmp �v������
	close_bmp();

	system("PAUSE"); /* so that the command window holds a while */
	return 0;
}

