#include <linux/module.h>
#include <linux/usb.h>

#define USB_PIXLINK_VENDOR_ID  0x0bda
#define USB_PIXLINK_PRODUCT_ID 0xc820

static struct usb_device_id pixlink_table[] = {
    { USB_DEVICE(USB_PIXLINK_VENDOR_ID, USB_PIXLINK_PRODUCT_ID) },
    {}
};
MODULE_DEVICE_TABLE(usb, pixlink_table);

static int pixlink_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
    printk(KERN_INFO "Pixlink USB WiFi device plugged in\n");
    return 0;
}

static void pixlink_disconnect(struct usb_interface *interface)
{
    printk(KERN_INFO "Pixlink USB WiFi device removed\n");
}

static struct usb_driver pixlink_driver = {
    .name = "pixlink_driver",
    .id_table = pixlink_table,
    .probe = pixlink_probe,
    .disconnect = pixlink_disconnect,
};

static int __init pixlink_init(void)
{
    printk(KERN_INFO "Pixlink driver init\n");
    return usb_register(&pixlink_driver);
}

static void __exit pixlink_exit(void)
{
    usb_deregister(&pixlink_driver);
    printk(KERN_INFO "Pixlink driver exit\n");
}

module_init(pixlink_init);
module_exit(pixlink_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Howard");
MODULE_DESCRIPTION("Minimal Pixlink USB WiFi Driver Skeleton");
