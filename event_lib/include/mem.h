#ifndef _MEM_H_
#define _MEM_H_

#define __FORCEINLINE           static inline __attribute__((always_inline)) 
#define GEN_NOP                 __asm("nop\n\t")

__FORCEINLINE void sleep(int t)
{
        for(int i = 0; i < (t * 100000); i++) {
                GEN_NOP;
        }
}

__FORCEINLINE void memset(char* d, char v, int l)  {
        for(int i = 0; i < l; ++i) {
                d[i] = v;
        }
}

__FORCEINLINE void memcpy(char* d, char* s, int l) {
        for(int i = 0; i < l; ++i) {
                d[i] = s[i];
        }
}

#endif