# studio42-usb-pid

Minimal USB example for RP2040/RP2350 using TinyUSB.  
Sets custom **Manufacturer**, **Product**, and **iSerial** descriptors.

> This repository only shows a basic USB descriptor configuration to
> demonstrate the use of the allocated PID.  
> Proprietary features are **not** included.

## Build (Arduino)

- **Board**: Raspberry Pi RP2040 (Arduino Mbed OS core)  
- **Tools → USB Stack**: Adafruit TinyUSB  
- Open `sl-usb-pid.ino` and upload.

> Optional (after pid.codes approval):  
> Set VID/PID to **0x1209 / 0x2A42** via `TinyUSBDevice.setID()` (if supported).  
> If not supported in your core version, update VID/PID in the board package
> (e.g., `boards.txt` or variant files).

## Verify on Linux

Unplug/replug once after flashing.

```bash
# find your device
lsusb

# show strings (iManufacturer / iProduct / iSerial)
sudo lsusb -v -d 1209:2a42 | grep -E 'i(Ma|Pro|Ser)ial' -n
# Note: before it's registered in usb.ids, the lsusb summary may show "Generic ..."
#       That's normal; the detailed -v output will still show your descriptors.
```