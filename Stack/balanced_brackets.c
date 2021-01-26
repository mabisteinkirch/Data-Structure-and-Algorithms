#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

int same(char a,char b)
    {
    if(a=='['&& b==']')
        return 1;
    if(a=='{'&& b=='}')
        return 1;
    if(a=='('&& b==')')
        return 1;
    return 0;
}

char* isBalanced(char* a) {

    char stack[1001],top=-1;
    for(int j=0;j<strlen(a);j++){
        if(a[j]=='['||a[j]=='{'||a[j]=='(')
            stack[++top]=a[j]; 
        if(a[j]==']'||a[j]=='}'||a[j]==')'){
            if(top==-1){
                return "NO";
            }
            else{
                if(!same(stack[top--],a[j])){
                    return "NO";
                }
            }
        } 
    }
    if(top!=-1){
        return "NO";
    }
    return "YES";
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* t_endptr;
    char* t_str = readline();
    int t = strtol(t_str, &t_endptr, 10);

    if (t_endptr == t_str || *t_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int t_itr = 0; t_itr < t; t_itr++) {
        char* s = readline();

        char* result = isBalanced(s);

        fprintf(fptr, "%s\n", result);
    }

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
