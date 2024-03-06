#ifndef BLUETOOTH_H
#define BLUETOOTH_H

char *TAG = "BLE-Server";
uint8_t ble_addr_type;
struct ble_gap_adv_params adv_params;
bool status = false;

int device_write(uint16_t conn_handle, uint16_t attr_handle, struct ble_gatt_access_ctxt *ctxt, void *arg);

int device_read(uint16_t con_handle, uint16_t attr_handle, struct ble_gatt_access_ctxt *ctxt, void *arg);

int ble_gap_event(struct ble_gap_event *event, void *arg);

void ble_app_advertise(void);

void ble_app_on_sync(void);

void host_task(void *param);

void connect_ble(void);

void boot_creds_clear(void *param);

#endif