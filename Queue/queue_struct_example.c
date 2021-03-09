typedef struct elem{
    NO *reg;
    struct elem *next;
} ELEMENT;

typedef struct queue{
    ELEMENT *head;
} QUEUE;