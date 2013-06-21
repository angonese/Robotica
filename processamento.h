void cort(IplImage* inicial, IplImage* final, CvMemStorage* armazem, cor use, float* x, float* y){
  int i;
	CvSeq* circulo = 0;
	float* rad;

	cvInRangeS(
			inicial, 
			CV_RGB(use.rMin, use.gMin, use.bMin),
			CV_RGB(use.rMax, use.gMax, use.bMax),
			final);

	cvSmooth(final, final, CV_GAUSSIAN, 9, 9);
	
	circulo = cvHoughCircles(
		final,								
		armazem,									
		CV_HOUGH_GRADIENT,							
		2 , 
		final->height / 4,
		100,
		50, 
		25,		// Raio minimo										
		35);	// Raio maximo							
		
	for(i = 0; i < circulo->total; i++){
		rad = (float*)cvGetSeqElem(circulo, i);
		
		*x = rad[0];		//Retorna as coordenadas X e Y
		*y = rad[1];

		cvCircle(inicial,		
			     cvPoint(cvRound(rad[0]), cvRound(rad[1])),
				 cvRound(rad[2]),
				 CV_RGB(0, 0, 0),
				 3);
			
	}	
	cvReleaseMemStorage(&armazem);
}
