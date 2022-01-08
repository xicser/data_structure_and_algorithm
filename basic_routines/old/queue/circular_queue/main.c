#include <stdio.h>
#include <stdlib.h>

#define u8 unsigned char
#define u16 unsigned short
#define u32 unsigned int

int main()
{
    printf("Hello world!\n");
    return 0;
}

//串口接收FIFO
#define UART_RX_FIFO_SIZE (350 * 1)//FIFO大小
typedef struct
{
    u8  data[UART_RX_FIFO_SIZE];//FIFO缓冲区
    u32 total;//FIFO中的报文数量
    u32 front;//指向队列头
    u32 rear;//指向队尾
    u32 max_size; //fifo大小

    u8 (*GetMsg) (u8 *msg); //从缓冲区获取报文
    u8 (*SetMsg) (u8 *msg); //放入报文到缓冲区
    void(*ClearBuff)(void); //清空FIFO
} Uart_Rx_Fifo_t;

//串口数据接收FIFO
static Uart_Rx_Fifo_t uart_rx_fifo;

/* 返回uart_fifo */
Uart_Rx_Fifo_t *BSP_UartGetRxFifo(void)
{
    return &uart_rx_fifo;
}
//往fifo里面存
static u8 SetToFIFO(u8 *msg)
{
    if (uart_rx_fifo.total == uart_rx_fifo.max_size)
    {
        return 0;
    }
    uart_rx_fifo.data[uart_rx_fifo.rear] = *msg;
    uart_rx_fifo.total++;
    uart_rx_fifo.rear = (uart_rx_fifo.rear + 1) % uart_rx_fifo.max_size;

    return 1;
}
//从fifo里面拿
static u8 GetFromFIFO(u8 *msg)
{
    if (uart_rx_fifo.total == 0)//先判断缓冲区空否
    {
        return 0;
    }
    *msg = uart_rx_fifo.data[uart_rx_fifo.front];
    uart_rx_fifo.total--;
    uart_rx_fifo.front = (uart_rx_fifo.front + 1) % uart_rx_fifo.max_size;

    return 1;
}
/*说明：ClearFIFO, 清空整个FIFO
* 参数：void
* 返回值：void
*/
static void ClearFIFO(void)
{
    uart_rx_fifo.max_size = UART_RX_FIFO_SIZE;
    uart_rx_fifo.total = 0;
    uart_rx_fifo.front = 0;
    uart_rx_fifo.rear = 0;
}
//初始化
void Uart_FIFO_Init(void)
{
    /*缓冲区初始化*/
    uart_rx_fifo.GetMsg = GetFromFIFO;
    uart_rx_fifo.SetMsg = SetToFIFO;
    uart_rx_fifo.ClearBuff = ClearFIFO;
    uart_rx_fifo.ClearBuff();
}
