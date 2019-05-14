char xerrmsg[1024];

#ifndef xerrlog
    #define xerrlog(XARG) do {\
        fprintf(stderr, "%s", (XARG)); \
        fflush(stderr); \
        exit(errno || 1); \
      } while(0)
#endif

#define xok(XARG) \
    if(XARG) do {\
        snprintf(xerrmsg, 1024, "NOT OK %s:%d:%s %d\n", __FILE__, __LINE__, __func__, XARG); \
        xerrlog(xerrmsg); \
    } while(0)

#define xokgt(XARG) \
    if((XARG) < 0) do { \
        snprintf(xerrmsg, 1024, "GT NOT OK %s:%d:%s %d\n", __FILE__, __LINE__, __func__, XARG); \
        xerrlog(xerrmsg); \
    } while(0)

#define xokptr(XARG) \
    if((XARG) == NULL) do { \
        snprintf(xerrmsg, 1024, "PTR NOT OK %s:%d:%s\n", __FILE__, __LINE__, __func__); \
        xerrlog(xerrmsg); \
    } while(0)

char *xdup(char *x, size_t s){
    char *r;
    xokptr(r = malloc(s));
    memcpy(r, x, s);
    return r;
}

char *xdupstr(char *x){
    return xdup(x, strlen(x));
}
