/**********************************************************************\
*                                                                      *
* PiLED - GoGo Gaybar!										           *
*                                                                      *
\**********************************************************************/

#include <stdio.h>
#include "PiLED.h"
#include "pixelmapping.h"
#include "image_element.h"

#define RESET_BYTE 1
#define FRAME_INTERVALL 40000


/********************************************\
*  MAIN                                      *
\********************************************/

int main(int argc, char **argv) {

	perror("init started");
	initRealTime();
	initGPIO();
	initUART();
	initTimer();
	perror("init complete");
	sendByte(RESET_BYTE);

	printf("args: %d\n", argc);

	char *filename;
	if (argc < 2) {
		filename = "../res/default.ledbar";
		printf("using default.ledbar\n");
	} else {
		filename = argv[1];
		printf("using ledbarfile %s\n", filename);
	}

	FILE *f;

	f = fopen(filename, "rb");
	if (f)
	{
        perror("file opened");
		unsigned char width;
		unsigned char height;
	    	fread(&width, 1, 1, f);
	    	fread(&height, 1, 1, f);
		int bufferSize = width * height * 3;
		unsigned char data[bufferSize];
		while (1)
		{
			while(1)
			{
				ResetStartTime();
				gpioBit ( kGPIODirectionPort, kFromPi );
			    size_t bytesread = fread(&data, 1, bufferSize, f);
				if (bytesread < bufferSize)
					break;

				int n;
				for (n = 0; n < bufferSize; n++)
				{
					unsigned char byteToSend = data[n];
					if (byteToSend == RESET_BYTE)
						byteToSend += 1;

					sendByte(byteToSend);
				}

				sendByte(RESET_BYTE);

				WaitForSendingToComplete();
				Wait(FRAME_INTERVALL);
			}
			fseek ( f , 2, SEEK_SET );
		}
	} else {
    perror("no file found");
  }
}

/**********************************************************************\
* initRealTime                                                         *
* Set the process as a real-time process to stop daemons getting the   *
* processor and causing timing problems.  This should lock out system  *
* when running, but it doesn't for me.  TODO Requires investigation.   *
\**********************************************************************/

int initRealTime() {
	struct sched_param param;
	param.sched_priority = 99;
	int status = sched_setscheduler ( 0, SCHED_RR, &param );
	if ( status != 0 ) {
		perror ( "Can't set realtime scheduling policy" );
	}
}

void sendPixel ( struct sPixel *pixel )
{
	if(pixel->red == RESET_BYTE)
		pixel->red = RESET_BYTE + 1;
	sendByte(pixel->red);
	if(pixel->green == RESET_BYTE)
		pixel->green = RESET_BYTE + 1;
	sendByte(pixel->green);
	if(pixel->blue == RESET_BYTE)
		pixel->blue = RESET_BYTE + 1;
	sendByte(pixel->blue);
}

void sendFrame ()
{
	//perror("sendFrame");
	int screenWidth = 128;
	int screenHeight = 8;
	int n;
	for (n = 0; n < screenWidth*screenHeight; n++)
	{
		struct sPixel pixel;
		pixel.red   =0;
		pixel.green =255;
		pixel.blue  =0;

		sendPixel(&pixel);
	}

	sendByte(RESET_BYTE);
}


