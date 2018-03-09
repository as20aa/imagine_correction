// imagine_correction.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main(int argc,char **argv)
{
	double alpha = 1.0;
	int beta = 0;
	Mat origin;
	string filename = "C:\\Users\\11235\\Pictures\\Camera Roll\\IMG_20170915_171544.jpg";
	if (argc > 1) {
		filename = argv[1];
	}
	origin = cv::imread(filename);
	Mat new_img=Mat::zeros(origin.size(), origin.type());
	cout << " Basic Linear Transforms " << endl;
	cout << "-------------------------" << endl;
	cout << "* Enter the alpha value [1.0-3.0]: "; cin >> alpha;
	cout << "* Enter the beta value [0-100]: ";    cin >> beta;

	for (int x = 0; x < origin.rows; x++)
		for (int y = 0; y < origin.cols; y++)
			for (int c = 0; c < 3; c++)
				new_img.at<Vec3b>(x, y)[c] = saturate_cast<uchar>(alpha*(origin.at<Vec3b>(x, y)[c]) + beta);
	
	namedWindow("Original Image", WINDOW_NORMAL);
	namedWindow("New Image", WINDOW_NORMAL);

	imshow("Original Image", origin);
	imshow("New Image", new_img);

	waitKey();
    return 0;
}

