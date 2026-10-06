#include <stdio.h>
#include <math.h>

/* Function to calculate index and return status*/

char *water_quality(float temp, float turb, float *index)
{
    float tempDeviation = fabs(temp - 25);
    float TurbidityPenalty  =  turb / 2.0;

    *index = 100.0 - (tempDeviation + TurbidityPenalty);

    if (*index >= 80)
            return ("Good");
    else if (*index >= 60)
            return ("Warning");
    else
            return ("Critical");
}

int main(void)
{
    /*Hard coded for sensor readings*/
    float temp = 45.0;
    float turb = 50.0;
    float index;
    char *status;

    /*Checking status of the water*/
    status = water_quality(temp, turb, &index);
    
    /*Printing the Water Quality Report*/
    printf("WATER QUALITY REPORT\n");
    printf("Temperature: %.1f C\n", temp);
    printf("Turbidity: %.1f NTU\n", turb);
    printf("Index: %.1f\n", index);
    printf("Status: %s\n", status);
    printf("END OF REPORT!\n");

    return (0);
}