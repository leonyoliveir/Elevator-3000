#include <bluetooth/uuid.h>
#include <errno.h>
#include <logging/log.h>
#include <misc/byteorder.h>
#include <misc/reboot.h>
#include <misc/util.h>
#include <shell/shell.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <zephyr.h>
#include <zephyr/types.h>
#include <bluetooth/gatt.h>

LOG_MODULE_REGISTER(input_ble, 4);

/* EFU - OTA service.
 * {FFF5E361-853B-482D-B102-46412D9A7413}
 */
static struct bt_uuid_128 efu_bt_svc_uuid = BT_UUID_INIT_128(
    0x13, 0x74, 0x9a, 0x2d, 0x41, 0x46, 0x02, 0xb1, 0x2d, 0x48, 0x3b, 0x85, 0x61, 0xe3, 0xf5, 0xff);

/* EFU - OTA data exchange characteristic; used for both requests and responses.
 * {FFF5E364-853B-482D-B102-46412D9A7413}
 */
static struct bt_uuid_128 efu_bt_chr_exg_uuid = BT_UUID_INIT_128(
    0x13, 0x74, 0x9a, 0x2d, 0x41, 0x46, 0x02, 0xb1, 0x2d, 0x48, 0x3b, 0x85, 0x64, 0xe3, 0xf5, 0xff);

/*
 * Write handler for the OTA characteristic; processes an incoming OTA request.
 */
static ssize_t dfu_bt_chr_write(struct bt_conn *conn, const struct bt_gatt_attr *attr,
                                const void *buf, u16_t len, u16_t offset, u8_t flags)
{
    LOG_DBG("Arrived %d bytes", len);

    return len;
}

/*
 * GATT attributs 
 */

static struct bt_gatt_attr efu_bt_attrs[] = {
    BT_GATT_PRIMARY_SERVICE(&efu_bt_svc_uuid),
    BT_GATT_CHARACTERISTIC( &efu_bt_chr_exg_uuid.uuid, 
                            BT_GATT_CHRC_WRITE_WITHOUT_RESP,
                            BT_GATT_PERM_WRITE, // | BT_GATT_PERM_WRITE_AUTHEN | BT_GATT_PERM_WRITE_ENCRYPT, 
                            NULL, 
                            dfu_bt_chr_write, 
                            NULL),
};

/*
 * GATT service 
 */

static struct bt_gatt_service efu_bt_svc = BT_GATT_SERVICE(efu_bt_attrs);

int dfu_bt_register(void)
{
    LOG_INF("DFU Service register!");
    return bt_gatt_service_register(&efu_bt_svc);
}

int dfu_bt_unregister(void)
{
    LOG_INF("DFU Service unregister!");
    return bt_gatt_service_unregister(&efu_bt_svc);
}