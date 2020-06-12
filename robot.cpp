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
		int isEnd;
		for (int i =0; i < 150; i++){
			int pix = get_pixel(cameraView,93,i,3);
			int farPix = get_pixel(cameraView,75,i,3);
			int isWhite;
			if( pix > 250){
				isWhite = 1;
				whiteCount++;
				whiteIndex += i;}
			else {isWhite = 0;}	
			if(farPix < 10){
				isEnd = 1;
				}
			array[i] = isWhite;
		}
		if(whiteCount != 0){
		averageWhite = whiteIndex/whiteCount;}
		error = 75 - averageWhite;
		std::cout<<error;
		if(error < 5 && error > -5){
		vLeft = 30;
		vRight = 30;}
		
		else if(error < -5){
		vLeft = 10 - error;
		vRight = 10;}
		else if(error > 5){
		vLeft = 10;
		vRight = 10 + error;}
		
		if(isEnd == 1){
		vLeft = 0;
		vRight = 0;
			}
		
		else if(whiteCount == 0){
		vLeft = 30 ;
		vRight = 0;
			}
		
      setMotors(vLeft,vRight);   
      std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
       usleep(10000);
  } //while

} // main
