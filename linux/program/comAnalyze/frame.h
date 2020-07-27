#ifdef __cplusplus
extern "C" {

#endif

typedef void (*comFcb)(unsigned char * pData, int *pSize);


void registCb(comFcb pFcb);
void cmd_handle(unsigned short data);

#ifdef __cplusplus
}
#endif
