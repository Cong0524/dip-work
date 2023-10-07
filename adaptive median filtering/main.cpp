/*===========================================================================
  This demonstrative example is provided by the teaching assistant,
  Mr. Shih-Hung Liao (¹ù¥@§»), and modified by the instructor, Prof. Lan.

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
#include "bmp.h"

using namespace std;

int R[MaxBMPSizeX][MaxBMPSizeY]; // MaxBMPSizeX and MaxBMPSizeY are defined in "bmp.h"
//int G[1024][1024];
//int B[1024][1024];
int r[MaxBMPSizeX][MaxBMPSizeY];
//int g[1024][1024];
//int b[1024][1024];

void sort(int* , int );

int main(int argc, char* argv[])
{
	int width, height;

	open_bmp((char *)"lena_pepper_and_salt_noise10%.bmp", R, R, R, width, height); // for gray images

	int arrTmp[121];
	int appendData = 0;
	int flag_oversize = 0;
	int min, max, idx;
	for (int i=0; i < width; i++){
		for (int j=0; j < height; j++){ 
			flag_oversize = 0;
			int mask = 3;
			// ====================== stage A ======================
			while(mask <= 11){
				min = 255;
				max = 0;
				// run the mask windows
				idx = 0;
				for (int m = -1*((mask - 1) / 2); m < ((mask - 1) / 2) + 1; m++) {
					for (int n = -1 * ((mask - 1) / 2); n < ((mask - 1) / 2) + 1; n++) {
						if (i + m >= width || i + m <= -1 || j + n >= width || j + n <= -1)appendData = 0;
						else appendData = R[i + m][j + n];
					
						//max & min
						if (appendData > max)max = appendData;
						if (appendData < min)min = appendData;

						arrTmp[idx++] = appendData;
					
					}
				}
				
				sort(arrTmp, mask* mask);
				
				//printf("%d %d %d\n", max, min, arrTmp[int(mask * mask / 2)]);

				if ((arrTmp[int(mask * mask / 2)] - min > 0) && (arrTmp[int(mask * mask / 2)] - max < 0)) {
					break;// go to B
				}
				else {
					if (mask == 11) {
						flag_oversize = 1;
						r[i][j] = arrTmp[int(mask * mask / 2)];
					}
				}
				mask += 2;
			}

			// ====================== stage B ======================
			if (flag_oversize == 0) {
				if((R[i][j] - min > 0) && (R[i][j] - max < 0))r[i][j] = R[i][j];
				else r[i][j] = arrTmp[int(mask * mask / 2)];
			}
		} 
	}

	
	save_bmp((char *)"new_lena_pepper_and_salt_noise10%.bmp", r, r, r); // for gray images
	printf("Job Finished!\n");

	close_bmp();

	system("PAUSE"); /* so that the command window holds a while */
	return 0;
}

void sort(int* arrIn, int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (*(arrIn + i) < *(arrIn + j)) {
				*(arrIn + i) = *(arrIn + i) ^ *(arrIn + j);
				*(arrIn + j) = *(arrIn + i) ^ *(arrIn + j);
				*(arrIn + i) = *(arrIn + i) ^ *(arrIn + j);
			}
		}
	}
}
