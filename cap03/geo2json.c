/*
    gcc geo2json.c -o geo2json && ./geo2json < gpsdata.csv > output.json
*/
#include <stdio.h>

int main (void)
{
    float latitude;
    float longitude;
    char info[80];
    int started = 0;

    puts("data=[");
    while (scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3) {
        if (started)
            printf(",\n");
        else 
            started = 1;
        if ((latitude < -90.0)||(latitude > 90.0)) {
            //printf("Invalid latitude: %f\n", latitude);
            fprintf(stderr, "Invalid latitude: %f\n", latitude);
            return 2;
        }
        if ((longitude < -180.0)||(longitude > 180.0)){
            //printf("Invalid longitude: %f\n", longitude);
            fprintf(stderr, "Invalid longitude: %f\n", longitude);
            return 2;
        }
        printf("{latitude: %f, longitude: %f, info: '%s'}", latitude, longitude, info);
    }
    puts("\n");

    return 0;
}
