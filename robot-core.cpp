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
		int array[150];
		int whiteCount = 0;
		double averageWhite = 0.0;
		int whiteIndex = 0;
		for (int i =0; i < 150; i++){
			int pix = get_pixel(cameraView,95,i,3);
			int isWhite;
			if( pix > 250){
				isWhite = 1;
				whiteCount++;
				whiteIndex += i;}
			else {isWhite = 0;}	
			array[i] = isWhite;
		}
		
		averageWhite = whiteIndex/whiteCount;
		error = 75 - averageWhite;
		std::cout<<error;
		if(error < 10 && error > -10){
		vLeft = 30;
		vRight = 30;}
		else{
		vLeft = 30 - error;
		vRight = 30;
		error = 0;
			}
		
      setMotors(vLeft,vRight);   
      std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
       usleep(10000);
  } //while

} // main
