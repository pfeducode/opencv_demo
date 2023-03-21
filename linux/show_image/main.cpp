#include <iostream>
#include <opencv2/opencv.hpp>
 
using namespace std;
using namespace cv;
 
int main(int argc,char** argv)
{   //"/home/pfrobot/CV/show_image/27.jpg"
    std::cerr<<"Usage:"<<argv[0]<<",image_file_path:"<<argv[1]<<std::endl;
    Mat srcImage = imread(std::string(argv[1]));
    imshow("Display Image window",srcImage);
    waitKey(0);
    return 0;
}
