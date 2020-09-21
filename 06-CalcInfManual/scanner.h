typedef enum {t_id,t_sum,t_mul,t_constNum,t_eof} token;

#define ERROR -1

token scan(void);