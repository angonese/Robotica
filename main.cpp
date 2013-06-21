#include <opencv/cvaux.h>
#include <opencv/highgui.h>
#include <opencv/cxcore.h>

#include <stdio.h>
#include <stdlib.h>

#include "cores.h"
#include "processamento.h"

int main(){
  CvSize padrao = cvSize(640, 480);	

	CvCapture* camera;					
	camera = cvCaptureFromCAM(1);       	  							//ID DA CAMERA USADA, 0 = Padrão, 1 = Secundária;

	IplImage* inicial = cvQueryFrame(camera);	
	IplImage* img[4];
	
	int n = 2;                					  								//NUMERO DE CORES ALOCADAS;
	
	for(int i = 0 ; i < n ; i++){
		img[i] = cvQueryFrame(camera);
		img[i] = cvCreateImage(padrao, IPL_DEPTH_8U, 1);
	}

	CvMemStorage* c[4];
		
	float x[4] = {0,0,0,0}, y[4] = {0,0,0,0};
	int render = 0;

	struct cor structc[4];

	structc[0] = azul();						              				// DEFINICAO DAS CORES USADAS;
	structc[1] = vermelho();

	cvNamedWindow("Vision", CV_WINDOW_AUTOSIZE);

	while(1){					
		inicial = cvQueryFrame(camera);
		if(render == 0){
			system("cls");
			render = 18;
			printf("ESC -> Sair\n+------------------------------------------------------------+\n");
		}
		for(int i = 0 ; i < 2 ; i++){
			c[i] = cvCreateMemStorage(0);										
			cort(inicial, img[i], c[i], structc[i], &x[i], &y[i]);
			printf(" (%3.f,%3.f)  ", x[i], y[i]);
			if(i == 1){
				printf("\n");
			}
		}
		render--;
    
    //_sleep(200);
		cvShowImage("Vision", inicial);						          	//IMAGEM MOSTRADA NA TELA, Inicial = Não tratada, img[i] = VETOR DAS CORES;
		//cvShowImage("Vision[i]", img[i]);
		if(cvWaitKey(33) == 27){
			break;	
		}
	}
	
	cvReleaseCapture(&camera);
	cvDestroyWindow("Vision");		
	return (0);
}
