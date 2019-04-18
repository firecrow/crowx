
void xerrlog(char *str){
    fprintf(stderr, str);
}

#define xok(x) \
    if(x) \
        xerrlog(stderr, "NOT OK %s:%s:%s %s\n", __file__, __line__, __FUNC__, #x)

#define xptrok(x) (!(x))
    if((x) == NULL) \
        xerrlog(stderr, "PTR NOT OK %s:%s:%s %s\n", __file__, __line__, __FUNC__, #x)

char *xdup(char *x, size_t s){
    char *r;
    xptrok(r = malloc(s));
    memcpy(r, x, s);
    return r;
}

char *xdupstr(char *x){
    return xdup(x, strlen(x));
}
