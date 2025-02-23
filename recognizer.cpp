#include "recognizer.h"
#include<iostream>
#include<filesystem>
#include<cmath>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int similarity_matrix_sum(Mat data_image , Mat test_image){

    //Store data image matrix
    vector <vector<int>> dataimg_matrix(test_image.rows ,vector<int>(test_image.cols,0));
    int sum=0;

    //Calculate the sum
    for(int  i=0;i<data_image.rows;i++){      
        for(int j=0;j<data_image.cols ;j++){          
            dataimg_matrix[i][j] =pow((test_image.at<u_char>(i ,j)-data_image.at<u_char>(i ,j)),2);
            sum+=dataimg_matrix[i][j];
        }  
    }
    return sum;
}

string check_match (Mat test_image ,const string &dataset_path){
    Mat data_image;

    string ans_min;
    int min_sum=INT_MAX; 

    // Iterate over the refrence img
    for(const auto it: filesystem::directory_iterator(dataset_path)){ 
        //iterate over the each charater directory             
        for(const auto it2: filesystem::directory_iterator(it.path().string())){
            
            data_image = imread(it2.path().string() ,IMREAD_GRAYSCALE);

            int sum=similarity_matrix_sum( data_image ,test_image);
            
            if(sum<min_sum){
                min_sum=sum;
                ans_min=it.path().stem().string();
                
            }
        }
    }
    return ans_min;

}

Image:: Image(const string &path){
    Mat data_image = imread(path ,IMREAD_GRAYSCALE);
}
string recognize(const string &dataset_path, const string &test_image_path){

    Image i(test_image_path);
    //Set Matrix for data_image and test_image
    Mat data_image, test_image; 
    i.setImage(imread(test_image_path,IMREAD_GRAYSCALE));
    //Reading the test image
    test_image=i.getimage();
    if(test_image.empty())
    {
        return "\0";
    }
    
    // Recognition : Function Call to 
    return check_match(test_image ,dataset_path); //
    
    //return s;
}
