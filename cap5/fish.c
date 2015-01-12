#include <stdio.h>
struct preferences {
    const char *food;
    float exercise_hours;
};
struct fish {
    const char *name;
    const char *species;
    int teeth;
    int age;
    struct preferences care;
};
void preferences (struct fish f)
{
    printf("%s like to eat %s\n", f.name, f.care.food);
    printf("%s like to exercise for %f hours\n", f.name,
    f.care.exercise_hours);
}

void catalog (struct fish f)
{
    printf("%s is a %s with %i teeth. He is %i\n", f.name, f.species, f.teeth,
    f.age); 
}

void label (struct fish f) 
{
    printf("Name: %s\nSpecies: %s\n%i years old, %i teeth\n", f.name, f.species,
    f.teeth, f.age); 
}

int main ()
{
    struct fish snappy = {"Snappy", "Piranha", 69, 4, {"Meat", 7.5}};
    catalog(snappy);
    label(snappy);
    preferences(snappy);
    return 0;    
}
