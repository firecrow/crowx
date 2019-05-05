#ifndef xerrlog 
    #define xerrlog(x) \
        fprintf(stderr, (x))
#endif

#define xok(x) \
    if(x) \
        xerrlog(stderr, "NOT OK %s:%s:%s %s\n", __FILE__, __LINE__, __func__, #x)

#define xptrok(x) (!(x))
    if((x) == NULL) \
        xerrlog(stderr, "PTR NOT OK %s:%s:%s %s\n", __FILE__, __LINE__, __func__, #x)

char *xdup(char *x, size_t s){
    char *r;
    xptrok(r = malloc(s));
    memcpy(r, x, s);
    return r;
}

char *xdupstr(char *x){
    return xdup(x, strlen(x));
}
