#ifndef RECOGNIZER_H
#define RECOGNIZER_H

#include <string>
#include<vector>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

string recognize(const std::string &dataset_path, const std::string &test_image_path);

class Image{
  public:
     Image(const string &path);
     Mat getimage()
     {
        return imageData;
     }
     void setImage(Mat image)
     {
        imageData=image;
     }
     private:
     Mat imageData;
 
};

#endif
