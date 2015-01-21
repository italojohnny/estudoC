typedef struct {
    char *name;
    char *opens;
    char *closes;
    struct island *next;
} island;

island* create (char* name);
void release (island *start);
void display (island *start);

