#
# Linux kernel configuration
#

# kernel fundamentals
LX_ENABLE += TTY SERIAL_EARLYCON SERIAL_OF_PLATFORM PRINTK HAS_IOMEM SMP

# support disabling ticking during idle
LX_ENABLE  += NO_HZ_IDLE

# initrd support
LX_ENABLE += BINFMT_ELF BINFMT_SCRIPT BLK_DEV_INITRD

# UART device
LX_ENABLE += SERIAL_8250 SERIAL_8250_CONSOLE

# PCI support
LX_ENABLE += PCI PCI_MSI

# IOMMU support (used by Intel fb to apply scanout scratch page workaround)
LX_ENABLE += IOMMU_SUPPORT INTEL_IOMMU

# ACPI support
LX_ENABLE += ACPI

# general network and WLAN support
LX_ENABLE += NET NETDEVICES PACKET
LX_ENABLE += WLAN CFG80211 MAC80211
LX_ENABLE += RFKILL

# iwlwifi
LX_ENABLE += WLAN_VENDOR_INTEL IWLWIFI IWLDVM IWLMVM

# rtlwifi
LX_ENABLE += WLAN_VENDOR_REALTEK RTL_CARDS RTL8188EE RTL8192CE

# ath9k
LX_ENABLE += WLAN_VENDOR_ATH ATH_COMMON ATH9K ATH9K_PCI
LX_ENABLE += ATH9K_DEBUGFS
#LX_ENABLE += ATH9K_RFKILL ATH9K_PCI_NO_EEPROM
#LX_ENABLE += ATH9K_HTC

# USB host-controller support
LX_ENABLE += USB_SUPPORT USB USB_ARCH_HAS_HCD USB_XHCI_HCD USB_EHCI_HCD USB_OHCI_HCD
LX_ENABLE += USB_PCI USB_UHCI_HCD USB_USBNET

# Intel framebuffer
LX_ENABLE += DRM DRM_I915

# to automatically set up screen mode at boot time
LX_ENABLE += FB

# mandatory fs support
LX_ENABLE += PROC_FS SYSFS

# disable cpu frequency scaling
LX_DISABLE += SCHED_MC CPU_FREQ

# disable optimization not possible in PIC code under Genode
LX_DISABLE += CC_HAS_ASM_GOTO

# slim down kernel by removing superfluous drivers
LX_DISABLE += HID HID_GENERIC USB_HID VGA_CONSOLE DUMMY_CONSOLE NLS VGA_ARB DEBUG_LIST
