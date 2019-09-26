#include "bt.h"

#include <shell/shell.h>
#include <shell/shell_uart.h>

// #include "dfu_ble.h"

#define DEVICE_NAME CONFIG_BT_DEVICE_NAME
#define DEVICE_NAME_LEN (sizeof(DEVICE_NAME) - 1)

#define HELP_NONE "[none]"
#define HELP_ADDR_LE "<address: XX:XX:XX:XX:XX:XX> <type: (public|random)>"

#define NAME_LEN 30
#define CHAR_SIZE_MAX 512

struct bt_conn *default_conn;

static const struct bt_data ad[] = {
    BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
    BT_DATA_BYTES(BT_DATA_UUID128_ALL, 0x84, 0xaa, 0x60, 0x74, 0x52, 0x8a, 0x8b, 0x86, 0xd3, 0x4c,
                  0xb7, 0x1d, 0x1d, 0xdc, 0x53, 0x8d),
};

static void advertise(void)
{
    int rc;

    bt_le_adv_stop();

    rc = bt_le_adv_start(BT_LE_ADV_CONN_NAME, ad, ARRAY_SIZE(ad), NULL, 0);
    if (rc) {
        printk("Advertising failed to start (rc %d)\n", rc);
        return;
    }

    printk("Advertising successfully started\n");
}

static void connected(struct bt_conn *conn, u8_t err)
{
    char addr[BT_ADDR_LE_STR_LEN];

    conn_addr_str(conn, addr, sizeof(addr));

    if (err) {
        printk("Failed to connect to %s (%u)\n", addr, err);
        // goto done;
    }

    printk("Connected: %s\n", addr);

    if (!default_conn) {
        default_conn = bt_conn_ref(conn);
    };
}

static void disconnected(struct bt_conn *conn, u8_t reason)
{
    char addr[BT_ADDR_LE_STR_LEN];

    conn_addr_str(conn, addr, sizeof(addr));
    printk("Disconnected: %s (reason %u)\n", addr, reason);

    if (default_conn == conn) {
        bt_conn_unref(default_conn);
        default_conn = NULL;
    }
}

void conn_addr_str(struct bt_conn *conn, char *addr, size_t len)
{
    struct bt_conn_info info;

    if (bt_conn_get_info(conn, &info) < 0) {
        addr[0] = '\0';
        return;
    }

    switch (info.type) {
#if defined(CONFIG_BT_BREDR)
    case BT_CONN_TYPE_BR:
        bt_addr_to_str(info.br.dst, addr, len);
        break;
#endif
    case BT_CONN_TYPE_LE:
        bt_addr_le_to_str(bt_conn_get_dst(conn), addr, len);
        break;
    }
}

static struct bt_conn_cb conn_callbacks = {
    .connected    = connected,
    .disconnected = disconnected,
};

static void bt_ready(int err)
{
    if (err) {
        printk("Bluetooth init failed (err %d)\n", err);
        return;
    }


    printk("Bluetooth initialized\n");

    if (IS_ENABLED(CONFIG_SETTINGS)) {
        settings_load();
    }

    default_conn = NULL;

    bt_conn_cb_register(&conn_callbacks);
    advertise();
}

int bt_init()
{
    int err = bt_enable(bt_ready);
    if (err) {
        printk("Bluetooth init failed (err %d)\n", err);
    }
    return err;
}