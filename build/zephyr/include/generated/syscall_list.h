
/* auto-generated by gen_syscalls.py, don't edit */
#ifndef ZEPHYR_SYSCALL_LIST_H
#define ZEPHYR_SYSCALL_LIST_H

#define K_SYSCALL_ADC_CHANNEL_SETUP 0
#define K_SYSCALL_ADC_READ 1
#define K_SYSCALL_ADC_READ_ASYNC 2
#define K_SYSCALL_ATOMIC_ADD 3
#define K_SYSCALL_ATOMIC_AND 4
#define K_SYSCALL_ATOMIC_CAS 5
#define K_SYSCALL_ATOMIC_NAND 6
#define K_SYSCALL_ATOMIC_OR 7
#define K_SYSCALL_ATOMIC_SET 8
#define K_SYSCALL_ATOMIC_SUB 9
#define K_SYSCALL_ATOMIC_XOR 10
#define K_SYSCALL_CAN_ATTACH_MSGQ 11
#define K_SYSCALL_CAN_CONFIGURE 12
#define K_SYSCALL_CAN_DETACH 13
#define K_SYSCALL_CAN_SEND 14
#define K_SYSCALL_COUNTER_GET_GUARD_PERIOD 15
#define K_SYSCALL_COUNTER_GET_MAX_RELATIVE_ALARM 16
#define K_SYSCALL_COUNTER_GET_PENDING_INT 17
#define K_SYSCALL_COUNTER_GET_TOP_VALUE 18
#define K_SYSCALL_COUNTER_READ 19
#define K_SYSCALL_COUNTER_SET_GUARD_PERIOD 20
#define K_SYSCALL_COUNTER_START 21
#define K_SYSCALL_COUNTER_STOP 22
#define K_SYSCALL_DEVICE_GET_BINDING 23
#define K_SYSCALL_DMA_START 24
#define K_SYSCALL_DMA_STOP 25
#define K_SYSCALL_ENTROPY_GET_ENTROPY 26
#define K_SYSCALL_ESPI_CONFIG 27
#define K_SYSCALL_ESPI_FLASH_ERASE 28
#define K_SYSCALL_ESPI_GET_CHANNEL_STATUS 29
#define K_SYSCALL_ESPI_READ_FLASH 30
#define K_SYSCALL_ESPI_READ_REQUEST 31
#define K_SYSCALL_ESPI_RECEIVE_OOB 32
#define K_SYSCALL_ESPI_RECEIVE_VWIRE 33
#define K_SYSCALL_ESPI_SEND_OOB 34
#define K_SYSCALL_ESPI_SEND_VWIRE 35
#define K_SYSCALL_ESPI_WRITE_FLASH 36
#define K_SYSCALL_ESPI_WRITE_REQUEST 37
#define K_SYSCALL_FLASH_ERASE 38
#define K_SYSCALL_FLASH_GET_PAGE_COUNT 39
#define K_SYSCALL_FLASH_GET_PAGE_INFO_BY_IDX 40
#define K_SYSCALL_FLASH_GET_PAGE_INFO_BY_OFFS 41
#define K_SYSCALL_FLASH_GET_WRITE_BLOCK_SIZE 42
#define K_SYSCALL_FLASH_READ 43
#define K_SYSCALL_FLASH_WRITE 44
#define K_SYSCALL_FLASH_WRITE_PROTECTION_SET 45
#define K_SYSCALL_GPIO_CONFIG 46
#define K_SYSCALL_GPIO_DISABLE_CALLBACK 47
#define K_SYSCALL_GPIO_ENABLE_CALLBACK 48
#define K_SYSCALL_GPIO_GET_PENDING_INT 49
#define K_SYSCALL_GPIO_READ 50
#define K_SYSCALL_GPIO_WRITE 51
#define K_SYSCALL_HWINFO_GET_DEVICE_ID 52
#define K_SYSCALL_I2C_CONFIGURE 53
#define K_SYSCALL_I2C_SLAVE_DRIVER_REGISTER 54
#define K_SYSCALL_I2C_SLAVE_DRIVER_UNREGISTER 55
#define K_SYSCALL_I2C_SLAVE_REGISTER 56
#define K_SYSCALL_I2C_SLAVE_UNREGISTER 57
#define K_SYSCALL_I2C_TRANSFER 58
#define K_SYSCALL_I2S_BUF_READ 59
#define K_SYSCALL_I2S_BUF_WRITE 60
#define K_SYSCALL_I2S_CONFIGURE 61
#define K_SYSCALL_I2S_TRIGGER 62
#define K_SYSCALL_IPM_MAX_DATA_SIZE_GET 63
#define K_SYSCALL_IPM_MAX_ID_VAL_GET 64
#define K_SYSCALL_IPM_SEND 65
#define K_SYSCALL_IPM_SET_ENABLED 66
#define K_SYSCALL_K_BUSY_WAIT 67
#define K_SYSCALL_K_CURRENT_GET 68
#define K_SYSCALL_K_FLOAT_DISABLE 69
#define K_SYSCALL_K_FUTEX_WAIT 70
#define K_SYSCALL_K_FUTEX_WAKE 71
#define K_SYSCALL_K_IS_PREEMPT_THREAD 72
#define K_SYSCALL_K_MSGQ_ALLOC_INIT 73
#define K_SYSCALL_K_MSGQ_GET 74
#define K_SYSCALL_K_MSGQ_GET_ATTRS 75
#define K_SYSCALL_K_MSGQ_NUM_FREE_GET 76
#define K_SYSCALL_K_MSGQ_NUM_USED_GET 77
#define K_SYSCALL_K_MSGQ_PEEK 78
#define K_SYSCALL_K_MSGQ_PURGE 79
#define K_SYSCALL_K_MSGQ_PUT 80
#define K_SYSCALL_K_MUTEX_INIT 81
#define K_SYSCALL_K_MUTEX_LOCK 82
#define K_SYSCALL_K_MUTEX_UNLOCK 83
#define K_SYSCALL_K_OBJECT_ACCESS_GRANT 84
#define K_SYSCALL_K_OBJECT_ALLOC 85
#define K_SYSCALL_K_OBJECT_RELEASE 86
#define K_SYSCALL_K_PIPE_ALLOC_INIT 87
#define K_SYSCALL_K_PIPE_GET 88
#define K_SYSCALL_K_PIPE_PUT 89
#define K_SYSCALL_K_POLL 90
#define K_SYSCALL_K_POLL_SIGNAL_CHECK 91
#define K_SYSCALL_K_POLL_SIGNAL_INIT 92
#define K_SYSCALL_K_POLL_SIGNAL_RAISE 93
#define K_SYSCALL_K_POLL_SIGNAL_RESET 94
#define K_SYSCALL_K_QUEUE_ALLOC_APPEND 95
#define K_SYSCALL_K_QUEUE_ALLOC_PREPEND 96
#define K_SYSCALL_K_QUEUE_CANCEL_WAIT 97
#define K_SYSCALL_K_QUEUE_GET 98
#define K_SYSCALL_K_QUEUE_INIT 99
#define K_SYSCALL_K_QUEUE_IS_EMPTY 100
#define K_SYSCALL_K_QUEUE_PEEK_HEAD 101
#define K_SYSCALL_K_QUEUE_PEEK_TAIL 102
#define K_SYSCALL_K_SEM_COUNT_GET 103
#define K_SYSCALL_K_SEM_GIVE 104
#define K_SYSCALL_K_SEM_INIT 105
#define K_SYSCALL_K_SEM_RESET 106
#define K_SYSCALL_K_SEM_TAKE 107
#define K_SYSCALL_K_SLEEP 108
#define K_SYSCALL_K_STACK_ALLOC_INIT 109
#define K_SYSCALL_K_STACK_POP 110
#define K_SYSCALL_K_STACK_PUSH 111
#define K_SYSCALL_K_STR_OUT 112
#define K_SYSCALL_K_THREAD_ABORT 113
#define K_SYSCALL_K_THREAD_CREATE 114
#define K_SYSCALL_K_THREAD_CUSTOM_DATA_GET 115
#define K_SYSCALL_K_THREAD_CUSTOM_DATA_SET 116
#define K_SYSCALL_K_THREAD_DEADLINE_SET 117
#define K_SYSCALL_K_THREAD_NAME_COPY 118
#define K_SYSCALL_K_THREAD_NAME_SET 119
#define K_SYSCALL_K_THREAD_PRIORITY_GET 120
#define K_SYSCALL_K_THREAD_PRIORITY_SET 121
#define K_SYSCALL_K_THREAD_RESUME 122
#define K_SYSCALL_K_THREAD_START 123
#define K_SYSCALL_K_THREAD_SUSPEND 124
#define K_SYSCALL_K_TIMER_REMAINING_GET 125
#define K_SYSCALL_K_TIMER_START 126
#define K_SYSCALL_K_TIMER_STATUS_GET 127
#define K_SYSCALL_K_TIMER_STATUS_SYNC 128
#define K_SYSCALL_K_TIMER_STOP 129
#define K_SYSCALL_K_TIMER_USER_DATA_GET 130
#define K_SYSCALL_K_TIMER_USER_DATA_SET 131
#define K_SYSCALL_K_UPTIME_GET 132
#define K_SYSCALL_K_USLEEP 133
#define K_SYSCALL_K_WAKEUP 134
#define K_SYSCALL_K_YIELD 135
#define K_SYSCALL_LED_BLINK 136
#define K_SYSCALL_LED_OFF 137
#define K_SYSCALL_LED_ON 138
#define K_SYSCALL_LED_SET_BRIGHTNESS 139
#define K_SYSCALL_LOG_BUFFERED_CNT 140
#define K_SYSCALL_LOG_FILTER_SET 141
#define K_SYSCALL_LOG_PANIC 142
#define K_SYSCALL_LOG_PROCESS 143
#define K_SYSCALL_NET_ADDR_NTOP 144
#define K_SYSCALL_NET_ADDR_PTON 145
#define K_SYSCALL_NET_ETH_GET_PTP_CLOCK_BY_INDEX 146
#define K_SYSCALL_NET_IF_IPV4_ADDR_ADD_BY_INDEX 147
#define K_SYSCALL_NET_IF_IPV4_ADDR_LOOKUP_BY_INDEX 148
#define K_SYSCALL_NET_IF_IPV4_ADDR_RM_BY_INDEX 149
#define K_SYSCALL_NET_IF_IPV4_SET_GW_BY_INDEX 150
#define K_SYSCALL_NET_IF_IPV4_SET_NETMASK_BY_INDEX 151
#define K_SYSCALL_NET_IF_IPV6_ADDR_ADD_BY_INDEX 152
#define K_SYSCALL_NET_IF_IPV6_ADDR_LOOKUP_BY_INDEX 153
#define K_SYSCALL_NET_IF_IPV6_ADDR_RM_BY_INDEX 154
#define K_SYSCALL_PTP_CLOCK_GET 155
#define K_SYSCALL_PWM_GET_CYCLES_PER_SEC 156
#define K_SYSCALL_PWM_PIN_SET_CYCLES 157
#define K_SYSCALL_RTC_DISABLE 158
#define K_SYSCALL_RTC_ENABLE 159
#define K_SYSCALL_RTC_GET_PENDING_INT 160
#define K_SYSCALL_RTC_READ 161
#define K_SYSCALL_RTC_SET_ALARM 162
#define K_SYSCALL_SENSOR_ATTR_SET 163
#define K_SYSCALL_SENSOR_CHANNEL_GET 164
#define K_SYSCALL_SENSOR_SAMPLE_FETCH 165
#define K_SYSCALL_SENSOR_SAMPLE_FETCH_CHAN 166
#define K_SYSCALL_SPI_RELEASE 167
#define K_SYSCALL_SPI_TRANSCEIVE 168
#define K_SYSCALL_UART_CONFIGURE 169
#define K_SYSCALL_UART_CONFIG_GET 170
#define K_SYSCALL_UART_DRV_CMD 171
#define K_SYSCALL_UART_ERR_CHECK 172
#define K_SYSCALL_UART_IRQ_ERR_DISABLE 173
#define K_SYSCALL_UART_IRQ_ERR_ENABLE 174
#define K_SYSCALL_UART_IRQ_IS_PENDING 175
#define K_SYSCALL_UART_IRQ_RX_DISABLE 176
#define K_SYSCALL_UART_IRQ_RX_ENABLE 177
#define K_SYSCALL_UART_IRQ_TX_DISABLE 178
#define K_SYSCALL_UART_IRQ_TX_ENABLE 179
#define K_SYSCALL_UART_IRQ_UPDATE 180
#define K_SYSCALL_UART_LINE_CTRL_GET 181
#define K_SYSCALL_UART_LINE_CTRL_SET 182
#define K_SYSCALL_UART_POLL_IN 183
#define K_SYSCALL_UART_POLL_OUT 184
#define K_SYSCALL_ZEPHYR_FPUTC 185
#define K_SYSCALL_ZEPHYR_FWRITE 186
#define K_SYSCALL_ZSOCK_ACCEPT 187
#define K_SYSCALL_ZSOCK_BIND 188
#define K_SYSCALL_ZSOCK_CLOSE 189
#define K_SYSCALL_ZSOCK_CONNECT 190
#define K_SYSCALL_ZSOCK_FCNTL 191
#define K_SYSCALL_ZSOCK_GETHOSTNAME 192
#define K_SYSCALL_ZSOCK_GETSOCKNAME 193
#define K_SYSCALL_ZSOCK_GETSOCKOPT 194
#define K_SYSCALL_ZSOCK_INET_PTON 195
#define K_SYSCALL_ZSOCK_LISTEN 196
#define K_SYSCALL_ZSOCK_POLL 197
#define K_SYSCALL_ZSOCK_RECVFROM 198
#define K_SYSCALL_ZSOCK_SENDMSG 199
#define K_SYSCALL_ZSOCK_SENDTO 200
#define K_SYSCALL_ZSOCK_SETSOCKOPT 201
#define K_SYSCALL_ZSOCK_SHUTDOWN 202
#define K_SYSCALL_ZSOCK_SOCKET 203
#define K_SYSCALL_Z_CLOCK_HW_CYCLES_PER_SEC_RUNTIME_GET 204
#define K_SYSCALL_Z_ERRNO 205
#define K_SYSCALL_Z_LOG_HEXDUMP_FROM_USER 206
#define K_SYSCALL_Z_LOG_STRING_FROM_USER 207
#define K_SYSCALL_Z_SYS_MUTEX_KERNEL_LOCK 208
#define K_SYSCALL_Z_SYS_MUTEX_KERNEL_UNLOCK 209
#define K_SYSCALL_Z_ZEPHYR_READ_STDIN 210
#define K_SYSCALL_Z_ZEPHYR_WRITE_STDOUT 211
#define K_SYSCALL_Z_ZSOCK_GETADDRINFO_INTERNAL 212
#define K_SYSCALL_BAD 213
#define K_SYSCALL_LIMIT 214


#ifndef _ASMLANGUAGE

#include <zephyr/types.h>

#ifdef __cplusplus
extern "C" {
#endif


extern u32_t z_hdlr_device_get_binding(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_espi_config(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_espi_get_channel_status(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_espi_read_request(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_espi_write_request(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_espi_send_vwire(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_espi_receive_vwire(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_espi_send_oob(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_espi_receive_oob(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_espi_read_flash(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_espi_write_flash(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_espi_flash_erase(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_object_access_grant(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_object_release(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_object_alloc(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_thread_create(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_sleep(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_usleep(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_busy_wait(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_yield(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_wakeup(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_current_get(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_thread_abort(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_thread_start(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_thread_priority_get(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_thread_priority_set(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_thread_deadline_set(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_thread_suspend(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_thread_resume(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_is_preempt_thread(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_thread_custom_data_set(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_thread_custom_data_get(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_thread_name_set(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_thread_name_copy(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_timer_start(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_timer_stop(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_timer_status_get(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_timer_status_sync(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_timer_remaining_get(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_timer_user_data_set(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_timer_user_data_get(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_uptime_get(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_queue_init(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_queue_cancel_wait(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_queue_alloc_append(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_queue_alloc_prepend(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_queue_get(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_queue_is_empty(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_queue_peek_head(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_queue_peek_tail(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_futex_wait(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_futex_wake(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_stack_alloc_init(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_stack_push(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_stack_pop(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_mutex_init(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_mutex_lock(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_mutex_unlock(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_sem_init(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_sem_take(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_sem_give(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_sem_reset(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_sem_count_get(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_msgq_alloc_init(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_msgq_put(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_msgq_get(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_msgq_peek(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_msgq_purge(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_msgq_num_free_get(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_msgq_get_attrs(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_msgq_num_used_get(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_pipe_alloc_init(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_pipe_put(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_pipe_get(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_poll(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_poll_signal_init(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_poll_signal_reset(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_poll_signal_check(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_poll_signal_raise(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_str_out(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_k_float_disable(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_ptp_clock_get(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_z_clock_hw_cycles_per_sec_runtime_get(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_adc_channel_setup(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_adc_read(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_adc_read_async(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_can_send(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_can_attach_msgq(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_can_detach(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_can_configure(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_counter_start(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_counter_stop(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_counter_read(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_counter_get_pending_int(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_counter_get_top_value(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_counter_get_max_relative_alarm(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_counter_set_guard_period(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_counter_get_guard_period(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_dma_start(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_dma_stop(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_entropy_get_entropy(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_flash_read(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_flash_write(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_flash_erase(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_flash_write_protection_set(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_flash_get_page_info_by_offs(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_flash_get_page_info_by_idx(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_flash_get_page_count(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_flash_get_write_block_size(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_gpio_config(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_gpio_write(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_gpio_read(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_gpio_enable_callback(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_gpio_disable_callback(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_gpio_get_pending_int(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_hwinfo_get_device_id(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_i2c_configure(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_i2c_transfer(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_i2c_slave_register(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_i2c_slave_unregister(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_i2c_slave_driver_register(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_i2c_slave_driver_unregister(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_i2s_configure(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_i2s_buf_read(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_i2s_buf_write(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_i2s_trigger(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_ipm_send(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_ipm_max_data_size_get(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_ipm_max_id_val_get(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_ipm_set_enabled(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_led_blink(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_led_set_brightness(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_led_on(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_led_off(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_pwm_pin_set_cycles(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_pwm_get_cycles_per_sec(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_rtc_read(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_rtc_enable(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_rtc_disable(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_rtc_set_alarm(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_rtc_get_pending_int(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_sensor_attr_set(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_sensor_sample_fetch(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_sensor_sample_fetch_chan(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_sensor_channel_get(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_spi_transceive(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_spi_release(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_uart_err_check(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_uart_poll_in(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_uart_poll_out(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_uart_configure(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_uart_config_get(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_uart_irq_tx_enable(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_uart_irq_tx_disable(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_uart_irq_rx_enable(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_uart_irq_rx_disable(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_uart_irq_err_enable(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_uart_irq_err_disable(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_uart_irq_is_pending(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_uart_irq_update(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_uart_line_ctrl_set(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_uart_line_ctrl_get(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_uart_drv_cmd(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_z_log_string_from_user(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_z_log_hexdump_from_user(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_log_panic(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_log_process(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_log_buffered_cnt(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_log_filter_set(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_net_eth_get_ptp_clock_by_index(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_net_if_ipv6_addr_lookup_by_index(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_net_if_ipv6_addr_add_by_index(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_net_if_ipv6_addr_rm_by_index(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_net_if_ipv4_addr_lookup_by_index(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_net_if_ipv4_addr_add_by_index(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_net_if_ipv4_addr_rm_by_index(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_net_if_ipv4_set_netmask_by_index(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_net_if_ipv4_set_gw_by_index(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_net_addr_pton(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_net_addr_ntop(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_zsock_socket(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_zsock_close(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_zsock_shutdown(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_zsock_bind(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_zsock_connect(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_zsock_listen(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_zsock_accept(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_zsock_sendto(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_zsock_sendmsg(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_zsock_recvfrom(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_zsock_fcntl(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_zsock_poll(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_zsock_getsockopt(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_zsock_setsockopt(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_zsock_getsockname(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_zsock_gethostname(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_zsock_inet_pton(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_z_zsock_getaddrinfo_internal(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_atomic_cas(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_atomic_add(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_atomic_sub(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_atomic_set(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_atomic_or(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_atomic_xor(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_atomic_and(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_atomic_nand(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_z_errno(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_z_zephyr_read_stdin(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_z_zephyr_write_stdout(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_zephyr_fputc(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_zephyr_fwrite(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_z_sys_mutex_kernel_lock(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t z_hdlr_z_sys_mutex_kernel_unlock(u32_t arg1, u32_t arg2, u32_t arg3,
                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);


#ifdef __cplusplus
}
#endif

#endif /* _ASMLANGUAGE */

#endif /* ZEPHYR_SYSCALL_LIST_H */
