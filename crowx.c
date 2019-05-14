char xerrmsg[1024];

#ifndef xerrlog
    #define xerrlog(x) do {\
        fprintf(stderr, "%s", (x)); \
        fflush(stderr); \
        exit(1); \
      } while(0)
#endif

#define xok(x) \
    if(x) do {\
        snprintf(xerrmsg, 1024, "NOT OK %s:%d:%s %d\n", __FILE__, __LINE__, __func__, x); \
        xerrlog(xerrmsg); \
    } while(0)

#define xokgt(x) \
    if((x) < 0) do { \
        snprintf(xerrmsg, 1024, "GT NOT OK %s:%d:%s %d\n", __FILE__, __LINE__, __func__, x); \
        xerrlog(xerrmsg); \
    } while(0)

/*
#define xokptr(x) \
    if((x) == NULL) \
        xerrlog(stderr, "PTR NOT OK %s:%s:%s %s\n", __FILE__, __LINE__, __func__, #x)

char *xdup(char *x, size_t s){
    char *r;
    xokptr(r = malloc(s));
    memcpy(r, x, s);
    return r;
}

char *xdupstr(char *x){
    return xdup(x, strlen(x));
}
*/
