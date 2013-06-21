struct cor{
  int rMin;	int gMin;	int bMin;
	int rMax;	int gMax;	int bMax;
};

cor vermelho(){
	struct cor use;
	use.rMin = 125;		use.gMin = 0;	use.bMin = 0;
	use.rMax = 255;		use.gMax = 60;	use.bMax = 65;

	return use;
}

cor azul(){
	struct cor use;
	use.rMin = 0;		use.gMin = 0;		use.bMin = 125;
	use.rMax = 65;		use.gMax = 100;		use.bMax = 255;

	return use;
}

cor laranja(){
	struct cor use;
	use.rMin = 220;		use.gMin = 80;		use.bMin = 10;
	use.rMax = 250;		use.gMax = 150;		use.bMax = 100;

	return use;
}

cor roxo(){
	struct cor use;
	use.rMin = 70;		use.gMin = 20;		use.bMin = 90;
	use.rMax = 150;		use.gMax = 40;		use.bMax = 175;

	return use;
}

cor amarelo(){
	struct cor use;
	use.rMin = 170;		use.gMin = 162;		use.bMin = 62;
	use.rMax = 215;		use.gMax = 210;		use.bMax = 135;

	return use;
}

cor verde(){
	struct cor use;
	use.rMin = 20;		use.gMin = 40;		use.bMin = 35;
	use.rMax = 90;		use.gMax = 160;		use.bMax = 135;

	return use;
}

cor rosa(){
	struct cor use;
	use.rMin = 200;		use.gMin = 100;		use.bMin = 55;
	use.rMax = 245;		use.gMax = 220;		use.bMax = 205;

	return use;
}
