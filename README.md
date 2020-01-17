# MobileNetV1/V2_SSD for the DNN modul of OpenCV
A example of OpenCV dnn framework working on a bare Raspberry Pi with TensorFlow models.
Papers <br/>
https://arxiv.org/abs/1611.10012 <br/>
Training set: COCO <br/>
Size: 300x300 <br/>
Frame rate V1: 3.16 FPS (RPi 4) <br/>
Frame rate V2: 2.01 FPS (RPi 4) <br/>
<br/>
Special made for a bare Raspberry Pi see: https://qengineering.eu/deep-learning-with-opencv-on-raspberry-pi-4.html <br/>
<br/>
To extract and run the network in Code::Blocks <br/>
$ mkdir *MyDir* <br/>
$ cd *MyDir* <br/>
$ wget https://github.com/Qengineering/MobileNet_SSD_OpenCV_TensorFlow/archive/master.zip <br/>
$ unzip -j master.zip <br/>
Remove master.zip and README.md as they are no longer needed. <br/> 
$ rm master.zip <br/>
$ rm README.md <br/> <br/>
Your *MyDir* folder must now look like this: <br/> 
04545.jpg <br/>
MobileNetSSD_deploy.caffemodel <br/>
MobileNetSSD_deploy.prototxt <br/>
TestOpenCV_Caffe.cpb <br/>
MobileNet.cpp <br/>
 <br/>
Run TestOpenCV_Caffe.cpb with Code::Blocks. Remember, you also need a working OpenCV 4 on your Raspberry. <br/>

![output image]( https://qengineering.eu/images/V1_FPS.png )
![output image]( https://qengineering.eu/images/V2_FPS.png )

