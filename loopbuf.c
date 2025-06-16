#include "stdio.h"
#define uint32_t unsigned int
#define uint16_t unsigned short
#define uint8_t unsigned char

/* 
    这个程序的好处在于不用写多个read，write函数了，极大的简化了代码，增强了复用。
 */

uint8_t write_circle_buf(p_circle_buf pCircleBuf,uint8_t val);
uint8_t read_circle_buf(p_circle_buf pCircleBuf,uint8_t* pVal);
void init_circle_buf(p_circle_buf pCircleBuf,uint32_t len, uint8_t *buf);

typedef struct circle_buf
{
    uint32_t r;     // 读index
    uint32_t w;     // 写index
    uint32_t len;   // 环形缓冲区长度
    uint8_t *buf;   // 环形缓冲区
}circle_buf,*p_circle_buf;

void init_circle_buf(p_circle_buf pCircleBuf,uint32_t len, uint8_t *buf)
{
    pCircleBuf->r = 0;
    pCircleBuf->w = 0;
    pCircleBuf->buf = buf;
    pCircleBuf->len = len;
}

uint8_t read_circle_buf(p_circle_buf pCircleBuf,uint8_t* pVal)
{
    if(pCircleBuf->r != pCircleBuf->w){
        *pVal = pCircleBuf->buf[pCircleBuf->r];
        pCircleBuf->r++;
        if(pCircleBuf->r == pCircleBuf->len){
            pCircleBuf->r = 0;
        }
        return 1;
    }else{
        return 0;
    }
}

uint8_t write_circle_buf(p_circle_buf pCircleBuf,uint8_t val)
{
    uint32_t next_w;
    next_w = pCircleBuf->w + 1;
    if(next_w == pCircleBuf->len){
        next_w = 0;
    }
    if(next_w != pCircleBuf->r){
        pCircleBuf->buf[pCircleBuf->w] = val;
        pCircleBuf->w = next_w;
        return 1;
    }else{
        return 0;
    }
}

/* 使用 */
static uint8_t buf[100];
static circle_buf circle_buf_1;
int main()
{
    init_circle_buf(&circle_buf_1,100,buf);
    while (1)
    {
        
    }
    
}