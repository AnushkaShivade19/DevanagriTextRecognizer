#ifndef RECOGNIZER_H
#define RECOGNIZER_H

#include <string>
#include <opencv2/opencv.hpp>

class Image {
public:
    Image() = default;
    explicit Image(const std::string &path);  // Constructor reads image from path
    cv::Mat getimage() const;                 // Getter for image data
    void setImage(const cv::Mat &img);        // Setter for image data
private:
    cv::Mat imageData;                        // Stores grayscale image
};

// Recognize the test image by comparing with dataset
// Returns the folder name of the closest match
std::string recognize(const std::string &dataset_path, const std::string &test_image_path);

#endif // RECOGNIZER_H
