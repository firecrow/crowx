 /*
 * Copyright 2020-2021 Firecrow Silvernight
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
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
