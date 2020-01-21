# MobileNetV1/V2_SSD for the DNN modul of OpenCV
A example of OpenCV dnn framework working on a bare Raspberry Pi with TensorFlow models.
Papers <br/>
https://arxiv.org/abs/1611.10012 <br/>
Training set: COCO <br/>
Size: 300x300 <br/>
Frame rate V1     : 3.19 FPS (RPi 4) <br/>
Frame rate V1_0.75: 4.98 FPS (RPi 4) <br/>
Frame rate V2     : 2.02 FPS (RPi 4) <br/>
Frame rate V2 Lite: 3.86 FPS (RPi 4) <br/>
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
Traffic.jpg <br/>
COCO_labels.txt <br/>
frozen_inference_graph_V1.pb (download this file from: https://drive.google.com/open?id=1sDn1guYV6oj-AeYuC-riGRh4kv9XBTMz )<br/>
frozen_inference_graph_V2.pb (download this file from: https://drive.google.com/open?id=1EU6tVcDNLNwv-pbJUXL7wYUchFHxr5fw )<br/>
ssd_mobilenet_v1_coco_2017_11_17.pbtxt <br/>
ssd_mobilenet_v2_coco_2018_03_29.pbtxt <br/>
TestOpenCV_TensorFlow.cpb <br/>
MobileNetV1.cpp (can be use for V2 version also)<br/>
 <br/>
Run TestOpenCV_Caffe.cpb with Code::Blocks. Remember, you also need a working OpenCV 4 on your Raspberry. <br/>

![output image]( https://qengineering.eu/images/V1_FPS.png )
![output image]( https://qengineering.eu/images/V1_075_FPS.png )
![output image]( https://qengineering.eu/images/V2_FPS.png )
![output image]( https://qengineering.eu/images/V2_Lite_FPS.png )

