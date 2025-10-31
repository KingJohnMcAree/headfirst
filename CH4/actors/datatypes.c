#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(int argc, char *argv[]) {
 
    printf("The value of INT_MAX:%i\n",INT_MAX);
    printf("The value of INT_MIN:%i\n",INT_MIN);
    printf("An int takes %Zu bytes\n",sizeof(int));
    printf("The value of FLT_MAX:%f\n",FLT_MAX);
    printf("The value of FLT_MIN:%.39f\n",FLT_MIN);
    printf("An float takes %Zu bytes\n",sizeof(float));
    return 0;
}
