#include<stdio.h>
#include "razerdevice.h"
#include "razerkbd_driver.h"

int main(int argc, const char * argv[]) {
    RazerDevices allDevices = getAllRazerDevices();
    RazerDevice *razerDevices = allDevices.devices;

    printf("%d Razer device(s) found:\n", allDevices.size);

    for (int i = 0; i < allDevices.size; i++) {
        RazerDevice device = razerDevices[i];
        printf("%#06x\n", device.productId);

        // Testing out the blackwidow v3 pro changes by switching to wave
        if (device.productId == 0x025A)
        {
            printf("Found blackwidow v3 pro keyboard (wired)\n");
            razer_attr_write_mode_wave(device.usbDevice, "1", 0, 0x90);
        }
        if (device.productId == 0x0271)
        {
            printf("Found blackwidow v3 mini keyboard (dongle)\n");
            razer_attr_write_mode_wave(device.usbDevice, "1", 0, 0x90);
        }
        if (device.productId == 0x0258)
        {
            printf("Found blackwidow v3 mini keyboard (usb)\n");
            razer_attr_write_mode_wave(device.usbDevice, "1", 0, 0x90);
        }
        if (device.productId == 0x0088 || device.productId == 0x0086)
        {
            printf("Found basilisk ultimate mouse receiver (dongle)\n");
            razer_attr_write_mode_wave(device.usbDevice, "1", 0, 0x90);
        }
    }

    closeAllRazerDevices(allDevices);
    return 0;

}
