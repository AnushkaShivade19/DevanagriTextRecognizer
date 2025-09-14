#include "recognizer.h"
#include <iostream>
#include <filesystem>
#include <cmath>
#include <opencv2/opencv.hpp>
#include <limits>

using namespace std;
using namespace cv;
namespace fs = std::filesystem;

// -------------------
// Helper: Compute squared difference sum between two images
// -------------------
static double similarity_matrix_sum(const Mat &data_image, const Mat &test_image) {
    if (data_image.empty() || test_image.empty()) return std::numeric_limits<double>::infinity();
    if (data_image.size() != test_image.size()) {
        Mat tmp;
        resize(data_image, tmp, test_image.size(), 0, 0, INTER_LINEAR);
        return norm(tmp, test_image, NORM_L2SQR); // Use OpenCV fast norm
    }

    double sum = 0.0;
    for (int i = 0; i < test_image.rows; ++i) {
        for (int j = 0; j < test_image.cols; ++j) {
            int diff = test_image.at<uchar>(i, j) - data_image.at<uchar>(i, j);
            sum += diff * diff;
        }
    }
    return sum;
}

// -------------------
// Check dataset for best matching label
// -------------------
string check_match(const Mat &test_image, const string &dataset_path) {
    if (test_image.empty()) return "";

    string best_label;
    double min_sum = std::numeric_limits<double>::infinity();

    for (const auto &labelDir : fs::directory_iterator(dataset_path)) {
        if (!labelDir.is_directory()) continue;

        for (const auto &imgFile : fs::directory_iterator(labelDir.path())) {
            Mat data_image = imread(imgFile.path().string(), IMREAD_GRAYSCALE);
            if (data_image.empty()) continue;

            double score = similarity_matrix_sum(data_image, test_image);
            if (score < min_sum) {
                min_sum = score;
                best_label = labelDir.path().stem().string(); // folder name as label
            }
        }
    }
    return best_label;
}

// -------------------
// Image class
// -------------------
Image::Image(const string &path) {
    imageData = imread(path, IMREAD_GRAYSCALE);
}

Mat Image::getimage() const {
    return imageData;
}

void Image::setImage(const Mat &img) {
    imageData = img.clone();
}

// -------------------
// Recognize function
// -------------------
string recognize(const string &dataset_path, const string &test_image_path) {
    Image img(test_image_path);
    Mat test_image = img.getimage();
    if (test_image.empty()) return "";

    // Optional: resize to canonical size if needed
    // Size canonicalSize(28,28);
    // if(test_image.size() != canonicalSize) resize(test_image, test_image, canonicalSize);

    return check_match(test_image, dataset_path);
}
