#include "API/Vulkan/vkPhysicalDevice.h"
#include "API/Vulkan/global.h"
#include <string.h>

void GetPhysicalDevice(VkPhysicalDevice* physicalDevice)
{
    *physicalDevice = VK_NULL_HANDLE;

    u32 physicalDeviceCount;
    vkEnumeratePhysicalDevices(vkExterns.instance, &physicalDeviceCount, VK_NULL_HANDLE);

    VkPhysicalDevice physicalDevices[physicalDeviceCount];
    vkEnumeratePhysicalDevices(vkExterns.instance, &physicalDeviceCount, physicalDevices);

    for (u32 i = 0; i < physicalDeviceCount; i++)
    {
        u32 extensionPropertyCount;
        vkEnumerateDeviceExtensionProperties(physicalDevices[i], VK_NULL_HANDLE, &extensionPropertyCount, VK_NULL_HANDLE);

        VkExtensionProperties extensionProperties[extensionPropertyCount];
        vkEnumerateDeviceExtensionProperties(physicalDevices[i], VK_NULL_HANDLE, &extensionPropertyCount, extensionProperties);

        u8 foundExts;
        for (u32 requiredExtension = 0; requiredExtension < VULKAN_DEVICE_EXTENSION_COUNT; requiredExtension++) {
            foundExts = 0;

            for (u32 availableExtension = 0; availableExtension < extensionPropertyCount; availableExtension++) {
                if (strcmp(deviceExtensions[requiredExtension], extensionProperties[availableExtension].extensionName) == 0)
                {
                    foundExts = 1;
                }
            }

            if (!foundExts) {
                break;
            }
        }

        if (!foundExts) continue;

        u32 queueFamilyPropertyCount;
        vkGetPhysicalDeviceQueueFamilyProperties(physicalDevices[i], &queueFamilyPropertyCount, VK_NULL_HANDLE);

        VkQueueFamilyProperties queueFamilyProperties[queueFamilyPropertyCount];
        vkGetPhysicalDeviceQueueFamilyProperties(physicalDevices[i], &queueFamilyPropertyCount, queueFamilyProperties);

        u8 hasFoundFamily = 0;
        for (u32 queueFamilyIndex = 0; queueFamilyIndex < queueFamilyPropertyCount; queueFamilyIndex++)
        {
            VkQueueFlags queueFlags = queueFamilyProperties[queueFamilyIndex].queueFlags;
            if (queueFlags & VK_QUEUE_GRAPHICS_BIT && queueFlags & VK_QUEUE_TRANSFER_BIT)
            {
                VkBool32 supported;
                vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevices[i], queueFamilyIndex, vkExterns.surface, &supported);

                if (supported == VK_TRUE)
                {
                    vkExterns.mainQueueFamilyIndex = queueFamilyIndex;
                    hasFoundFamily = 1;
                    break;
                }
            }
        }

        if (!hasFoundFamily) continue;

        physicalDevice = &physicalDevices[i];
        break;
    }

    if (*physicalDevice == VK_NULL_HANDLE)
    {
        printf("Couldn't find a supported physical device\n");
        exit(1);
    }
}