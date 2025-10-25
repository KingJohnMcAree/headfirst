#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]){

    if(argc != 6){
        fprintf(stderr,"You need to give 5 arguments!\n");
        return 1;
    }
    char line[80];
    FILE *in = fopen("warpeace.txt","r");
    FILE *file1 = fopen(argv[2],"w");
    FILE *file2 = fopen(argv[4],"w");
    FILE *file3 = fopen(argv[5],"w");
    
    int count1=0;
    int count2=0;
    int count3=0;

    while (fscanf(in,"%79[^\n]\n",line)==1){
        if (strstr(line,argv[1])){
            fprintf(file1, "%s\n", line);
            count1 +=1;
        }
        else if (strstr(line,argv[3])){
            fprintf(file2, "%s\n", line);
            count2 +=1;
        }
        else{
            fprintf(file3, "%s\n", line);
            count3 +=1;
        }
}
int total = count1 + count2 + count3;
printf("%s: %d\n%s: %d\nOthers: %d\n",argv[1], count1, argv[3], count2, count3);
printf("Total lines:%d\n\n",total);
return 0;
}