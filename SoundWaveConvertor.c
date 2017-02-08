#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

//int16_t* generateSound(int max);
void adjustVolume(float factor, int max);
//int* getSong(char* wavefile);
float tableLookUp(char* factorValue, int wfv);

//void adjustVolume2(int16_t* original,int16_t* newSound,float factor,int max);

int main(int argc, char* argv[]) {
	float factor = 0.5;
	int max = 5000000;
	//char* file;
	/*
	if (argc >= 2) {
		factor = atof(argv[1]);
	}

	if (argc >= 3) {
		max = atof(argv[2]);
	}*/

	int num = factor * 10;
	switch (num) {
	case 1:
		//adjustVolume(wf, ff01, max);
		break;
	case 2:
		//adjustVolume("test.csv", "wave02.csv", max);
		break;
	case 3:
		//adjustVolume("test.csv", "wave03.csv", max);
		break;
	case 4:
		//adjustVolume("test.csv", "wave04.csv", max);
		break;
	case 5:
		adjustVolume(factor, max);
		break;
	case 6:
		//adjustVolume("test.csv", "wave06.csv", max);
		break;
	case 7:
		//adjustVolume("test.csv", "wave07.csv", max);
		break;
	case 8:
		//adjustVolume("test.csv", "wave08.csv", max);
		break;
	case 9:
		//adjustVolume("test.csv", "wave09.csv", max);
		break;
	case 10:
		//adjustVolume("test.csv", "wave10.csv", max);
		break;
	default:
		//adjustVolume("test.csv", "wave05.csv", max);
		break;
	}

	//int16_t* sound = generateSound(max);
	//int16_t* newsound = (int16_t*)malloc(max*2);

	int i;
	//struct timeval t1, t2;
	double elapsed;

	//Do not really need this code for table lookup	
	/*
	gettimeofday(&t1,NULL);
	adjustVolume2(sound,newsound,factor,max);

	gettimeofday(&t2,NULL);
	elapsed=(t2.tv_sec - t1.tv_sec)*1000+(t2.tv_usec - t1.tv_usec)/1000;
	printf("%d size sound file, new array, simple: %.2lf\n",max,elapsed);
	*/
	//gettimeofday(&t1, NULL);
	//adjustVolume(sound,factor,max);

	//gettimeofday(&t2, NULL);
	//elapsed = (t2.tv_sec - t1.tv_sec) * 1000 + (t2.tv_usec - t1.tv_usec) / 1000;
	//printf("%d size sound file, original array, simple: %.2lf\n", max, elapsed);

	system("pause");
	return 0;
}

void adjustVolume(float factor, int max) {
	long i = 0, ii = 0;
	int wfv[10000];
	float fv = 0;
	
	FILE* wf = fopen("test.csv", "r+");

	for (; ii < 10000; ii++) {
		fscanf(wf, "%d\n", &wfv[ii]);
	}

	FILE* nsf = fopen("Song05.csv", "w");

	for (; i < 10000; i++) {
		fv = tableLookUp("wave05.csv", wfv[i]);

		fprintf(nsf, "%d , %.1f\n", wfv[i], fv);
	}

	fclose(wf);
	fclose(nsf);
}

float tableLookUp(char* factorfile, int wfv) {
	int ffv = 0;
	float fv = 0;
	int i = -32768;

	FILE* ff = fopen(factorfile, "r+");

	for (; i < 32768; i++) {
		fscanf(ff, "%d , %f\n", &ffv, &fv);
		if (wfv == ffv) {
			return fv;
		}
	}

	fclose(ff);
	return -123456789.1;
}