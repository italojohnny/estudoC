/*
 * gcc -lopencv_core -lopencv_highgui main.c
 * gcc `pkg-config --cflags opencv` `pkg-config --libs opencv` main.c
 * 
 */ 
#include <stdlib.h>
#include <stdio.h>

#include <opencv/cv.h>
#include <opencv/highgui.h>

int
main(int argc, char *argv[])
{
    IplImage *img;
	

    if (argc != 2) {
        puts("Usage: cinza file");
        return EXIT_FAILURE;
    }

    img = cvLoadImage(argv[1], CV_LOAD_IMAGE_GRAYSCALE);

    if (img == NULL) {
        puts("Could not load image file.");
        return EXIT_FAILURE;
    }

    cvSaveImage("cinza.png", img, 0);

    cvReleaseImage(&img);
    return EXIT_SUCCESS;
}
