#include "robot.hpp"
int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
    double vLeft = 3.0;
    double vRight = 3.0;
    takePicture();
    SavePPMFile("i0.ppm",cameraView);
    while(1){
		takePicture();
		double error = 0.0;
		for (int i =0; i < 150; i++){
			int pix = get_pixel(cameraView,50,i,3);
			int isWhite;
			if( pix > 250){isWhite = 1;
				error = error;}
			else {isWhite = 0;}	
		}
		
		vLeft;
		vRight;
      setMotors(vLeft,vRight);   
      std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
       usleep(10000);
  } //while
