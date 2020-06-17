


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
		int distanceFromCentre = 0;
		bool isRed = false;
		for (int i =0; i < 150; i++){
			int pix = get_pixel(cameraView,93,i,3);
			int farPix = get_pixel(cameraView,75,i,3);
			int isWhite;
			if (pix > 250){
				isWhite = 1;
				whiteCount++;
				whiteIndex += i;}
			else {isWhite = 0;}	
			array[i] = isWhite;
		}
		for (int x = 75; isRed == false && x != 0; x--){
			int pixLeft = get_pixel(cameraView,75,x,0);
			if (pixLeft != 255){
				distanceFromCentre++;
			}
			else {isRed = true;}
			
		}
		if (whiteCount == 0){
			if (distanceFromCentre == 0){
				int x = 0;
				while (x < 10){
					vLeft = 30;
					vRight = 1;
					setMotors(vLeft,vRight);
					x++;
				}
			}
			if (distanceFromCentre == 75){
				int x = 0;
				int y = 0;
				while (x < 23){
					vLeft = 30;
					vRight = 30;
					setMotors(vLeft,vRight);
					x++;
				}
				while (y < 12){
					vLeft = 1;
					vRight = 30;
					setMotors(vLeft,vRight);
					y++;
				}
			}
			if (distanceFromCentre > 30 && distanceFromCentre < 70){
				vLeft = 30;
				vRight = 30;
			}
			if (distanceFromCentre < 30){
				vLeft = 20;
				vRight = 12;
			}
			if (distanceFromCentre > 70){
				vLeft = 12;
				vRight = 20;
			}
			
		}
		
		if (whiteCount != 0){
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
	}
	setMotors(vLeft,vRight);   
      std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
      usleep(10000);
  } //while
} // main


  
