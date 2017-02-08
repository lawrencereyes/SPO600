#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

int16_t* generateSound(int max);
void adjustVolume(int16_t* original,float factor,int max);
void adjustVolume2(int16_t* original,int16_t* newSound,float factor,int max);

int main(int argc, char* argv[]){
	float factor = 0.5;
	int max = 5000000;
	//char* file;

	if(argc >= 2){
		factor = atof(argv[1]);
	}
	
	if(argc >= 3){
		max = atof(argv[2]);
	}
	
	/*
	switch(factor){
		case 0.1:
			fp;
			break;
		case 0.3:
			fp = fopen("wave0.3.cvs", "w+");
			break;
		case 0.7:
			fp = fopen("wave0.7.cvs", "w+");
                       	break;
		default:
			fp = fopen("wave0.5.cvs", "w+");
			break;
	}*/

	/*
	 * 
	 *
	 *RIP
	 */
	
	FILE *fp;
	int wave = -32768;

	fp = fopen("test.csv", "w+");
	int16_t* cry =  generateSound(max);

	for(; wave < 32768l; wave++){
		fprintf(fp, "%d\n", cry); 
	}

	int16_t* sound = generateSound(max);
	int16_t* newsound = (int16_t*)malloc(max*2);

	int i;
	struct timeval t1, t2;
	double elapsed;

	gettimeofday(&t1,NULL);
	adjustVolume2(sound,newsound,factor,max);
		
	gettimeofday(&t2,NULL);
	elapsed=(t2.tv_sec - t1.tv_sec)*1000+(t2.tv_usec - t1.tv_usec)/1000;
	printf("%d size sound file, new array, simple: %.2lf\n",max,elapsed);
		
	gettimeofday(&t1,NULL);
	adjustVolume(sound,factor,max);
		
	gettimeofday(&t2,NULL);
	elapsed=(t2.tv_sec - t1.tv_sec)*1000+(t2.tv_usec - t1.tv_usec)/1000;
	printf("%d size sound file, original array, simple: %.2lf\n",max,elapsed);
}

int16_t* generateSound(int max){
	int16_t* rc=(int16_t*)malloc(max*2);
	int i;
	
	for(i=0;i<max;i++){
		rc[i]=(int16_t)((rand()%65536)-32768);
	}

	return rc;
}

void adjustVolume(int16_t* original,float factor,int max){
	int i;

	for(i=0;i<max;i++){
		original[i]=original[i]*factor;
	}
}

void adjustVolume2(int16_t* original,int16_t* newSound,float factor,int max){
	int i;

	for(i=0;i<max;i++){
		newSound[i]=original[i]*factor;
	}
}

