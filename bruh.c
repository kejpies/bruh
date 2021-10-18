// Copyright 2021 Konrad Sekuła
#include <stdio.h>

const float ver = 2.0f;

float version(void);
void bruh(void);
int main(int argc, char* argv[]){
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
    
}
float version(void){
    return ver;
}
void bruh(void){
    if (system("aplay /usr/share/bruh/bruh.wav &> /dev/null")!=0)
        system("paplay /usr/share/bruh/bruh.wav &> /dev/null");
}