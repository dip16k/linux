#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/vmalloc.h>
#include <linux/mm.h>

static int __init my_module_init(void)
{
    size_t size = PAGE_SIZE; // Example size
    void *ptr;

    // Allocate memory
    ptr = vmalloc(size);
    if (!ptr) {
        pr_err("vmalloc failed\n");
        return -ENOMEM;
    }

    // Mark the allocated memory as read-only (non-executable)
    if (set_memory_ro((unsigned long)ptr, size / PAGE_SIZE) != 0) {
        pr_err("set_memory_ro failed\n");
        vfree(ptr);
        return -EINVAL;
    }

    pr_info("Memory allocated and marked as non-executable\n");

    // Mark the memory as writable again before freeing
    if (set_memory_rw((unsigned long)ptr, size / PAGE_SIZE) != 0) {
        pr_err("set_memory_rw failed\n");
        vfree(ptr);
        return -EINVAL;
    }

    // Free the allocated memory
    vfree(ptr);

    return 0;
}

static void __exit my_module_exit(void)
{
    pr_info("Module exiting\n");
}

module_init(my_module_init);
module_exit(my_module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A module to allocate non-executable memory using vmalloc");
