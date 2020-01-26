#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <opencv2/core/ocl.hpp>

using namespace cv;
using namespace std;

const size_t width = 300;
const size_t height = 300;

dnn::Net net;
std::vector<std::string> Names;

static bool getFileContent(std::string fileName)
{

	// Open the File
	std::ifstream in(fileName.c_str());
	// Check if object is valid
	if(!in.is_open()) return false;

	std::string str;
	// Read the next line from File untill it reaches the end.
	while (std::getline(in, str))
	{
		// Line contains string of length > 0 then save it in vector
		if(str.size()>0) Names.push_back(str);
	}
	// Close The File
	in.close();
	return true;
}

void detect_from_video(Mat &src)
{
    Mat blobimg = dnn::blobFromImage(src, 1.0, Size(300, 300), 0.0, true);

	net.setInput(blobimg);

	Mat detection = net.forward("detection_out");
//	cout << detection.size[2]<<" "<< detection.size[3] << endl;
	Mat detectionMat(detection.size[2], detection.size[3], CV_32F, detection.ptr<float>());

	const float confidence_threshold = 0.25;
	for(int i=0; i<detectionMat.rows; i++){
		float detect_confidence = detectionMat.at<float>(i, 2);

		if(detect_confidence > confidence_threshold){
			size_t det_index = (size_t)detectionMat.at<float>(i, 1);
			float x1 = detectionMat.at<float>(i, 3)*src.cols;
			float y1 = detectionMat.at<float>(i, 4)*src.rows;
			float x2 = detectionMat.at<float>(i, 5)*src.cols;
			float y2 = detectionMat.at<float>(i, 6)*src.rows;
			Rect rec((int)x1, (int)y1, (int)(x2 - x1), (int)(y2 - y1));
			rectangle(src,rec, Scalar(0, 0, 255), 1, 8, 0);
			putText(src, format("%s", Names[det_index].c_str()), Point(x1, y1-5) ,FONT_HERSHEY_SIMPLEX,0.5, Scalar(0, 0, 255), 1, 8, 0);
		}
	}
}

int main(int argc,char ** argv)
{
    float f;
    float FPS[16];
    int i, Fcnt=0;
    Mat frame;
    chrono::steady_clock::time_point Tbegin, Tend;

    for(i=0;i<16;i++) FPS[i]=0.0;

    //MobileNetV1
    net = dnn::readNetFromTensorflow("frozen_inference_graph_V1.pb","ssd_mobilenet_v1_coco_2017_11_17.pbtxt");
    //MobileNetV2
    //net = dnn::readNetFromTensorflow("frozen_inference_graph_V2.pb","ssd_mobilenet_v2_coco_2018_03_29.pbtxt");
    if (net.empty()){
        cout << "init the model net error";
        exit(-1);
    }

	// Get the names
	bool result = getFileContent("COCO_labels.txt");
	if(!result)
	{
        cout << "loading labels failed";
        exit(-1);
	}

    //cout << "Switched to " << (cv::ocl::useOpenCL() ? "OpenCL enabled" : "CPU") << endl;
    //net.setPreferableTarget(DNN_TARGET_OPENCL);

    cout << "Start grabbing, press ESC on Live window to terminate" << endl;
    while(1){
        frame=imread("Traffic.jpg");  //need to refresh frame before dnn class detection

        Tbegin = chrono::steady_clock::now();

        detect_from_video(frame);

        Tend = chrono::steady_clock::now();
        //calculate frame rate
        f = chrono::duration_cast <chrono::milliseconds> (Tend - Tbegin).count();
        if(f>0.0) FPS[((Fcnt++)&0x0F)]=1000.0/f;
        for(f=0.0, i=0;i<16;i++){ f+=FPS[i]; }
        putText(frame, format("FPS %0.2f", f/16),Point(10,20),FONT_HERSHEY_SIMPLEX,0.6, Scalar(0, 0, 255));
        //show output
        imshow("frame", frame);

        char esc = waitKey(5);
        if(esc == 27) break;
  }

  cout << "Closing the camera" << endl;
  destroyAllWindows();
  cout << "Bye!" << endl;

  return 0;
}
