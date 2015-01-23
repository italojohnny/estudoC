#include <stdio.h>
#include <string.h>

int NUM_ADS = 7;
char *ADS[] = {
    "William: SBM GSOH like sports, TV, dining",
    "Matt: SWM NS likes art, movies, theater",
    "Luis: SLM ND likes books, theater, art",
    "Mike: DWM DS likes trucks, sports and bieber",
    "Peter: SAM likes chess, working out and art",
    "Josh:  SJM likes sports, movies and theater",
    "Jed: DBM likes theater, books and dining"
};

void find (int(*match)(char*));
int sports_no_bieber (char*);
int sports_or_workout (char*);
int ns_theater (char*);
int arts_theater_or_dining (char*);

void find (int(*match)(char*))
{
    int i;
    puts("Seach results:");
    puts("--------------------------------------------");
    for (i = 0; i <  NUM_ADS; i++) {
        if (match(ADS[i])) {
            printf("%s\n", ADS[i]);
        }
    }
    puts("--------------------------------------------");
}

int sport_no_bieber (char *s)
{
    return strstr(s, "sports") && !strstr(s, "bieber");
}

int sports_or_workout (char *s)
{
    return strstr(s, "sports") || strstr(s, "working");
}

int ns_theater (char *s)
{
    return strstr(s, "NS") && strstr(s, "theater");
}

int arts_theater_or_dining (char *s)
{
    return strstr(s, "arts") || strstr(s, "theater") || strstr(s, "dining");
}
