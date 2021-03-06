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
	//注意是Mat::zeros()，不是cv::zeros()
	Mat new_img=Mat::zeros(origin.size(), origin.type());
	cout << " Basic Linear Transforms " << endl;
	cout << "-------------------------" << endl;
	cout << "* Enter the alpha value [1.0-3.0]: "; cin >> alpha;
	cout << "* Enter the beta value [0-100]: ";    cin >> beta;
	//注意左边是行，右边是列
	for (int x = 0; x < origin.rows; x++)
		for (int y = 0; y < origin.cols; y++)
			for (int c = 0; c < 3; c++)
				//注意是Vec3b,而不是Vec3f；加上saturate_cast这是一个模板类型，转化为uchar类型的数据
				new_img.at<Vec3b>(x, y)[c] = saturate_cast<uchar>(alpha*(origin.at<Vec3b>(x, y)[c]) + beta);
	
	namedWindow("Original Image", WINDOW_NORMAL);
	namedWindow("New Image", WINDOW_NORMAL);

	imshow("Original Image", origin);
	imshow("New Image", new_img);
	//注意此处的waitkey()不是cv::waitkey()
	waitKey();
    return 0;
}

