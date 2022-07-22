#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <stdlib.h>
#include <thread>

/*!
 * Camera class with callback
 * GNU GPL v3.0
 * (C) 2022
 * [Ross Gardiner](https://github.com/rossGardiner)
 * [Adam Frew](https://github.com/Saweenbarra) 
 * [Alban Joseph](https://github.com/albanjoseph)
 * [Lewis Russell](https://github.com/charger4241)
 * Bernd Porr
 */
class Camera {
public:
	struct SceneCallback {
		virtual void nextScene(cv::Mat) = 0;
	};
	
	Camera() = default;
	void Start(int deviceID = 0, int apiID = 0);
	void Stop();
    
private:
	void postFrame();
	void threadLoop();
	cv::VideoCapture videoCapture;
	//! Private member thread
	std::thread cameraThread;
	//! Private member variable containing camera object status.
	/*!
	  false = Camera is off.
	  true = Camera is on.
	*/
	bool isOn = false;
	SceneCallback* sceneCallback = nullptr;
};
