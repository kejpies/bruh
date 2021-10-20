// Copyright 2021 Konrad Sekuła
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include "bruh_sound.h"

const float ver = 2.1f;

char* bruh_bytes;
int bruh_len;

float version(void);
void bruh(void);
void initialize(void);

int main(int argc, char* argv[]){
	initialize();

    int times=1;
    if(argc>1)
    {
        if(strcmp(argv[1], "--version-plain")==0){
            printf("%.1f", version());
            return 0;
        }
        if(argv[1][0]=='-'&&argv[1][1]=='n'){
            int iargv12=argv[1][2]-'0';
            times=iargv12;
        }
    }
    for(int i=0;i<times;i++) bruh();
    free(bruh_bytes);
}
float version(void){
    return ver;
}
void initialize(void){
	bruh_len=strlen(bruh_sound);
	bruh_bytes=base64Decoder(bruh_sound,bruh_len);
}
void bruh(void){
	FILE* stream = popen("aplay -f dat &> /dev/null","w");
	if (NULL == stream) printf("%s",strerror(errno));
	fwrite(bruh_bytes, sizeof(char), bruh_len, stream);
    pclose(stream);
}
