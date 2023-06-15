#ifndef BIT_MATH
#define BIT_MATH
#define SET_BIT(reg,b) ((reg)|=1<<(b))
#define CLR_BIT(reg,b) ((reg)&=~(1<<(b)))
#define TOG_BIT(reg,b) ((reg)^=(1<<(b)))
#define GET_BIT(reg,b) (((reg)>>(b))&1)
#endif
