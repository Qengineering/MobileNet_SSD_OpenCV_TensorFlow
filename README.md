# MobileNetV1/V2_SSD for the DNN modul of OpenCV
![output image]( https://qengineering.eu/images/V1_FPS.png )
## A example of OpenCV dnn framework working on a bare Raspberry Pi with TensorFlow models. <br/>
[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)<br/><br/>
Paper: https://arxiv.org/abs/1611.10012<br/><br/>
Special made for a bare Raspberry Pi 4 see [Q-engineering deep learning examples](https://qengineering.eu/deep-learning-examples-on-raspberry-32-64-os.html)

------------

Training set: COCO <br/>
Size: 300x300 <br/>
Frame rate V1     : 3.19 FPS (RPi 4) <br/>
Frame rate V1_0.75: 4.98 FPS (RPi 4) <br/>
Frame rate V2     : 2.02 FPS (RPi 4) <br/>
Frame rate V2 Lite: 3.86 FPS (RPi 4) <br/>


------------

## Dependencies.<br/>
To run the application, you have to:
- A raspberry Pi 4 with a 32 or 64-bit operating system. It can be the Raspberry 64-bit OS, or Ubuntu 18.04 / 20.04. [Install 64-bit OS](https://qengineering.eu/install-raspberry-64-os.html) <br/>
- OpenCV 64 bit installed. [Install OpenCV 4.5](https://qengineering.eu/install-opencv-4.5-on-raspberry-64-os.html) <br/>
- Code::Blocks installed. (```$ sudo apt-get install codeblocks```)

------------

## Installing the app.
To extract and run the network in Code::Blocks <br/>
$ mkdir *MyDir* <br/>
$ cd *MyDir* <br/>
$ wget https://github.com/Qengineering/MobileNet_SSD_OpenCV_TensorFlow/archive/refs/heads/master.zip <br/>
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

------------

## Running the app.
To run the application load the project file TestOpenCV_TensorFlow.cbp in Code::Blocks. More info or<br/> 
if you want to connect a camera to the app, follow the instructions at [Hands-On](https://qengineering.eu/deep-learning-examples-on-raspberry-32-64-os.html#HandsOn).<br/><br/>
![output image]( https://qengineering.eu/images/V1_075_FPS.png )
![output image]( https://qengineering.eu/images/V2_FPS.png )

------------

[![paypal](https://qengineering.eu/images/TipJarSmall4.png)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=CPZTM5BB3FCYL) 

![output image]( https://qengineering.eu/images/V2_Lite_FPS.png )

