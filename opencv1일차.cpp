#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main() {

	Mat img = imread("송교창.jpg",IMREAD_ANYCOLOR);
	Mat img_gray = imread("송교창.jpg", IMREAD_GRAYSCALE);
	imshow("img", img);
	imshow("송교창그레이", img_gray);
	waitKey();
	return 0;
}
