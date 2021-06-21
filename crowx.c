#define XERR_MSG_LEN 1024
char xerrmsg[XERR_MSG_LEN];

/* this can be previously defined to handle errors differently */
#ifndef xerr
    #define xerr(MSG) \
        do {\
            fprintf(stderr, "%s", (MSG)); \
            fflush(stderr); \
            exit(errno || 1); \
        } while(0)
#endif

/* 
 * using a define macro here to place this statement inside the function at
 * compile time, so __line__ is the line where the error occured 
 */
#define xok_zero(XARG) \
    do { \
        if(XARG) { \
            snprintf(xerrmsg, XERR_MSG_LEN, "NOT OK %s:%d:%s %d\n", __FILE__, __LINE__, __func__, XARG); \
            xerr(xerrmsg); \
        } \
    } while(0)

#define xok_gt(XARG) \
    do { \
        if((XARG) < 0) { \
            snprintf(xerrmsg, XERR_MSG_LEN, "GT NOT OK %s:%d:%s %d\n", __FILE__, __LINE__, __func__, XARG); \
            xerr(xerrmsg); \
        } \
    } while(0)

#define xok_not_null(XARG) \
    do { \
        if((XARG) == NULL) { \
            snprintf(xerrmsg, XERR_MSG_LEN, "PTR NOT OK %s:%d:%s\n", __FILE__, __LINE__, __func__); \
            xerr(xerrmsg); \
        } \
    } while(0)

char *xdup(char *x, size_t s){
    char *r;
    xok_not_null(r = malloc(s));
    memcpy(r, x, s);
    return r;
}

char *xdupstr(char *x){
    return xdup(x, strlen(x));
}
