#include <stdio.h>
#include <hfcal.h>

void display_calories (float weight, float distance, float coeff)
{
    printf("Weight: %3.2f kg\n", weight / 2.2046);
    printf("Distance: %3.2f kms\n", distance * 1.609344);
    printf("Calories: %4.2f cal\n", weight * distance * coeff);
}
