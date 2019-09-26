#include <bluetooth/bluetooth.h>
#include <bluetooth/conn.h>
#include <bluetooth/gatt.h>
#include <bluetooth/hci.h>
#include <bluetooth/uuid.h>
#include <errno.h>
#include <misc/byteorder.h>
#include <misc/printk.h>
#include <settings/settings.h>
#include <stddef.h>
#include <string.h>
#include <zephyr.h>
#include <zephyr/types.h>

int dfu_bt_register(void);

/**
 * @brief 
 * 
 * @return int 
 */
int dfu_bt_unregister(void);
