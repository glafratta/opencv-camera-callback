#include "camera.h"
#include <stdlib.h>
struct CameraCallback:Camera::SceneCallback{
    void nextScene(const cv::Mat&mat){
        printf("dimensions = %i\n", mat.dims);
    }
};

int main(int argc, char** argv){
    int deviceID=0;
    int apiID=0;
    if (argc>1){
        deviceID = atoi(argv[1]);
    }
    if (argc>2){
        apiID = atoi(argv[2]);
    }
    printf("deviceID =%i API = %i\n", deviceID, apiID);
    Camera camera;
    CameraCallback cameraCallback;
    camera.registerSceneCallback(&cameraCallback);
    camera.start(deviceID, apiID);
    //camera.start("/dev/video0"); 
    do {
    }while(getchar());
    camera.stop();
}