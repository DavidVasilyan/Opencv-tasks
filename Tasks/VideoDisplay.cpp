#include <iostream>
#include <opencv2/highgui.hpp>

using namespace cv;

int main() {
    VideoCapture video(0);

    if(!video.isOpened()) {return -1;}

    Mat frame;

    while(video.read(frame)) {
        imshow("Video stream", frame);
        char c = waitKey(1);
        if (c == 'q' || c == 'Q') {
            break;
        }
    }
}