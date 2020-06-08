
#include "robot.hpp"


int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}

    double vLeft = 28.0;
    double vRight = 25.0;
    int red;
    int green;
    int blue;
    int whiteTotal=0;
    bool isWhite = false;
    ImagePPM image = cameraView;
    double totalRowPixels = image.width;
    double totalRowNotWhitePrevious = 0;
    double totalRowNotWhite = 0;
    
    
    
   while(1){
    
    	totalRowNotWhite = 0;
   	takePicture();
   	SavePPMFile("i0.ppm",cameraView);
	setMotors(vLeft,vRight);
	usleep(10000);
    	for (int row = 0; row < 50; row++){ //takes the first 50 rows of the image
		isWhite = false;
		for (int column = 0; isWhite == false && column < image.width; column++){ //checks each pixel until it reach a white pixel, or it reaches the end of the image
			int pixel = get_pixel(image,row,column,0);
			int address = image.width*row*3 + column*3;
			unsigned char r = image.data[address];
			unsigned char g = image.data[address+1];
			unsigned char b = image.data[address+2];
			if ((int)r==255 && (int)g==255 && (int)b==255){ //checks to see if the pixel is white
				isWhite = true;
			}
			else {
				totalRowNotWhite++;
				
			}
		}
		if (totalRowNotWhite < (totalRowPixels/3)*2 && totalRowNotWhite > totalRowPixels/3) { //checks that the white line is in the middle of the image
		std::cout<<"OK"<<std::endl;
		vLeft = 22.0;
		vRight = 22.0;
		}
		if ((totalRowNotWhite > 130 && totalRowNotWhitePrevious < 50) || totalRowNotWhite == 0){ //checks for a sharp left corner
			int x = 0;
			while (x < 5){ //if it detects a sharp corner it will run this 5 times to ensure it turns enough
			std::cout<<"Left corner"<<std::endl;
			vLeft = 20.0;
			vRight = 30.0;
			setMotors(vLeft,vRight);
			usleep(10000);
			x++;
	}
	    }
		
		if (isWhite = false){
		std::cout<<"No white"<<std::endl;
		}
		if (totalRowNotWhite > (totalRowPixels/3)*2){ //if the white line is too far to the right it will turn the car right to centre the line again
		std::cout<<"Go Right"<<std::endl;
		vLeft = 30.0;
		vRight = 22.0;
		}
		if (totalRowNotWhite < totalRowPixels/3){ //if the white line is too far away to the left it will turn the car left to centre the line again
		std::cout<<"Go left"<<std::endl;
		vLeft = 22.0;
		vRight = 28.0;
		}
		totalRowNotWhitePrevious = totalRowNotWhite; //remembers the previous totalRowNotWhite value
		totalRowNotWhite = 0; //resets the totalRowNotWhite back to 0
		
		
	}
	
			
    
    
  } //while

} // main
