#include <iostream>
#include <opencv2/highgui.hpp>

using namespace cv;

int main() {
    Mat src, input;
    
    src = imread(samples::findFile("lena.jpg"), IMREAD_COLOR);
    printf("press q to quit");
    
    for(;;) {
        imshow("Window", src);

        char input = (char)waitKey(0);

        if(input == 'q' || input == 'Q') {
            break;
        }   
    }
    
}