#include "ASiftDetector.h"

int main( int argc, char** argv ){
	if( argc != 2)
	{
		cout << " Need to give an image filepath!" << endl; 
		return -1; 
	} 
	
	Mat my_image; 
	my_image = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE); 
	std::vector > keypoints;
	Mat descriptors;
	ASiftDetector asd;
	asd.detectAndCompute(my_image, keypoints, descriptors);
	
	return 0;
}