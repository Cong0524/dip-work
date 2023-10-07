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
#include "bmp.h"

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

	// �}�Ҩ�Ū�����m(24bits)bmp �v������
	// RGB �T�� channel ���Ȧs�J R, G, B �T�Ӧۭq���}�C��
	// �}�C�j�p���o�j�� 1024x1024 (�ثe�]�w) 
	// �Y�ݭn��j���v��size�A�i�Nbmp.h���� MaxBMPSizeX �P MaxBMPSizeY ���s�]�w 
	//open_bmp("lena.bmp", R, G, B, width, height); for true color images
	open_bmp("skin_det_1.bmp", R, G, B, height, width); // for gray images
	// The starting pixel of a bmp image is at the bottom-left corner, which has 
	// coordinates x=0 and y=0.  The last pixel is at the top-right corner.

    //*----------------------------------------------------------------------------
	      


    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            //int RGB_pixel = image[i][j];

            float nB = B[i][j] / 255.0;
            float nG = G[i][j] / 255.0;
            float nR = R[i][j] / 255.0;

            float maximum = nB;
            float minimum = nB;

            if (nR > maximum) maximum = nR;
            if (nR < minimum) minimum = nR;

            if (nG > maximum) maximum = nG;
            if (nG < minimum) minimum = nG;

            float V = maximum;
            float delta = maximum - minimum;
            float S = delta / V;

            float H;
            if (nR == maximum) {
                H = 1.0 / 6.0 * (nG - nB) / delta;
            } else if (nG == maximum) {
                H = 1.0 / 6.0 * (2.0 + (nB - nR) / delta);
            } else {
                H = 1.0 / 6.0 * (4.0 + (nR - nG) / delta);
            }
            
                 float H_min = 2;
   				 float H_max = 29;
					
    		     float S_min = 0.09;
                 float S_max = 0.7;

            if (!(H * 255 >= H_min && H * 255 <= H_max && S <= S_max && S >= S_min) || j < 50) {
                R[i][j]=0;
                B[i][j]=0;
                G[i][j]=0;
            }
        }
    }



	      
	      
	      
	      
	      
    //----------------------------------------------------------------------------*/
	
	// �x�s�B�z���G�ܷs�����ɤ�
	//save_bmp("lenna_new1.bmp", r, g, b); // for true color images
	save_bmp("new_skin_det_1.bmp", R, G, B); // for gray images
	printf("Job Finished!\n");

	// ���� bmp �v������
	close_bmp();

	system("PAUSE"); /* so that the command window holds a while */
	return 0;
}
 
