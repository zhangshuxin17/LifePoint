#ifdef __cplusplus
extern "C" {

#endif

typedef void (*comFcb)(unsigned char * pData, int Size);


void registCb(comFcb pFcb);
void cmd_handle(unsigned short data);
void make_frame(unsigned char *pData, int size,unsigned char *pOutData, int *pNum);

#ifdef __cplusplus
}
#endif
