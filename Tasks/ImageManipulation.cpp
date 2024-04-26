#include <iostream>
#include <opencv2/highgui.hpp>
#include<opencv2/opencv.hpp>

using namespace cv;

int main() {
    Mat img;
    img = imread(samples::findFile("lena.jpg"), IMREAD_COLOR);

    if(img.empty()) {
        std::cout << "ERROR";
        return 0;
    }

    Mat Resize;
    resize(img, Resize, Size(1600, 900),INTER_LINEAR);

    Mat Fl;
    flip(img, Fl, 0);
    flip(Fl, Fl, 1);

    Mat Crop = img(Range(150,300), Range(200, 330));

    Point2f center((img.cols - 1)/2.0, (img.rows - 1)/2.0);
    Mat matRotation = getRotationMatrix2D(center, 45, 1.0);
    Mat rotated_image;
    warpAffine(img, rotated_image, matRotation, img.size());

    imshow("RESIZE", Resize);
        
    imshow("FLIP", Fl);
    
    imshow("CROP", Crop);
        
    imshow("ROTATE", rotated_image);

    char c = (char)waitKey(0);

    imwrite("resize.jpg", Resize);
    imwrite("flip.jpg", Fl);
    imwrite("crop.jpg", Crop);
    imwrite("rotate.jpg", rotated_image);
    destroyAllWindows();
}  