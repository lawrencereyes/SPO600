#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

void adjustVolume(char* songAdjFile, char* factorFile, int max);
float tableLookUp(char* factorValue, int wfv);

int main(int argc, char* argv[]) {
	float factor = 1.0;
	int max = 500;
	
	if (argc >= 2) {
		factor = atof(argv[1]);
	}

	if (argc >= 3) {
		max = atof(argv[2]);
	}

	int num = factor * 10;
	switch (num) {
	case 1:
		adjustVolume("Song01.csv", "wave01.csv", max);
		break;
	case 2:
		adjustVolume("Song02.csv", "wave02.csv", max);
		break;
	case 3:
		adjustVolume("Song03.csv", "wave03.csv", max);
		break;
	case 4:
		adjustVolume("Song04.csv", "wave04.csv", max);
		break;
	case 5:
		adjustVolume("Song05.csv", "wave05.csv", max);
		break;
	case 6:
		adjustVolume("Song06.csv", "wave06.csv", max);
		break;
	case 7:
		adjustVolume("Song07.csv", "wave07.csv", max);
		break;
	case 8:
		adjustVolume("Song08.csv", "wave08.csv", max);
		break;
	case 9:
		adjustVolume("Song09.csv", "wave09.csv", max);
		break;
	case 10:
		adjustVolume("Song10.csv", "wave10.csv", max);
		break;
	default:
		adjustVolume("Song05.csv", "wave05.csv", max);
		break;
	}

	system("pause");
	return 0;
}

void adjustVolume(char* songAdjFile, char* factorFile, int max) {
	long i = 0, ii = 0;
	int wfv[500];
	float fv = 0;
	
	FILE* wf = fopen("test.csv", "r+");

	for (; ii < max; ii++) {
		fscanf(wf, "%d\n", &wfv[ii]);
	}
	
	FILE* nsf = fopen(songAdjFile, "w");

	for (; i < max; i++) {
		fv = tableLookUp(factorFile, wfv[i]);

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