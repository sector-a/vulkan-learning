import sys

cfile = open("../src/API/Vulkan/vkFunctions.c", "w")
hfile = open("../include/API/Vulkan/vkFunctions.h", "w")

loaderFuncs = []
instanceFuncs = []
deviceFuncs = []

for i in range(1, len(sys.argv)):
    func = sys.argv[i].split(':')
    match func[1]:
        case 'l': loaderFuncs.append(func[0]);
        case 'i': instanceFuncs.append(func[0]);
        case 'd': deviceFuncs.append(func[0]);



print("-- writing header file")

hfile.write("#ifndef VK_FUNCTIONS_H\n#define VK_FUNCTIONS_H\n\n#include <vulkan/vulkan.h>\n\n#ifdef VK_NO_PROTOTYPES\n");

hfile.write("// vulkan loader functions\n")
hfile.write("extern PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr;\n")
i = len(loaderFuncs) - 1
while i >= 0:
    hfile.write("extern PFN_" + loaderFuncs[i] + ' ' + loaderFuncs[i] + ";\n");
    i -= 1

hfile.write("\n");

hfile.write("// vulkan instance functions\n")
hfile.write("extern PFN_vkGetDeviceProcAddr vkGetDeviceProcAddr;\n")
i = len(instanceFuncs) - 1
while i >= 0:
    hfile.write("extern PFN_" + instanceFuncs[i] + ' ' + instanceFuncs[i] + ";\n");
    i -= 1

hfile.write("\n")

hfile.write("// vulkan device functions\n")
i = len(deviceFuncs) - 1
while i >= 0:
    hfile.write("extern PFN_" + deviceFuncs[i] + ' ' + deviceFuncs[i] + ";\n");
    i -= 1

hfile.write("#endif\n")

hfile.write("\nvoid LoadVulkanLoaderFunctions();\nvoid LoadVulkanInstanceFunctions(VkInstance instance);\nvoid LoadVulkanDeviceFunctions(VkDevice device);\n\n")

hfile.write("#endif\n")
hfile.close()



print("-- writing C file")

cfile.write("#include <vulkan/vulkan.h>\n#include <SDL3/SDL_vulkan.h>\n\n#include <stdio.h>\n#include <stdlib.h>\n\n")

cfile.write("#ifdef VK_NO_PROTOTYPES\n")
cfile.write("// vulkan loader functions\n")
cfile.write("PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr;\n")
i = len(loaderFuncs) - 1
while i >= 0:
    cfile.write("PFN_" + loaderFuncs[i] + ' ' + loaderFuncs[i] + ";\n");
    i -= 1

cfile.write("\n");

cfile.write("// vulkan instance functions\n")
cfile.write("PFN_vkGetDeviceProcAddr vkGetDeviceProcAddr;\n")
i = len(instanceFuncs) - 1
while i >= 0:
    cfile.write("PFN_" + instanceFuncs[i] + ' ' + instanceFuncs[i] + ";\n");
    i -= 1

cfile.write("\n")

cfile.write("// vulkan device functions\n")
i = len(deviceFuncs) - 1
while i >= 0:
    cfile.write("PFN_" + deviceFuncs[i] + ' ' + deviceFuncs[i] + ";\n");
    i -= 1

cfile.write("#endif\n\n")

cfile.write("void LoadVulkanLoaderFunctions() {\n\t#ifdef VK_NO_PROTOTYPES\n")
i = len(loaderFuncs) - 1
cfile.write("\tvkGetInstanceProcAddr = (PFN_vkGetInstanceProcAddr)SDL_Vulkan_GetVkGetInstanceProcAddr();\n\tif (vkGetInstanceProcAddr == VK_NULL_HANDLE) {\n\t\tprintf(\"failed to load vkGetInstanceProcAddr\\n\");\n\t\texit(1);\n\t}\n")
while i >= 0:
    cfile.write('\t' + loaderFuncs[i] + " = (PFN_" + loaderFuncs[i] + ")vkGetInstanceProcAddr(VK_NULL_HANDLE, \"" + loaderFuncs[i] + "\");\n")
    i -= 1
cfile.write("\t#endif\n}\n\n")

cfile.write("void LoadVulkanInstanceFunctions(VkInstance instance) {\n\t#ifdef VK_NO_PROTOTYPES\n")
i = len(instanceFuncs) - 1
cfile.write("\tvkGetDeviceProcAddr = (PFN_vkGetDeviceProcAddr)vkGetInstanceProcAddr(instance, \"vkGetDeviceProcAddr\");\n")
while i >= 0:
    cfile.write('\t' + instanceFuncs[i] + " = (PFN_" + instanceFuncs[i] + ")vkGetInstanceProcAddr(instance, \"" + instanceFuncs[i] + "\");\n")
    i -= 1
cfile.write("\t#endif\n}\n\n")

cfile.write("void LoadVulkanDeviceFunctions(VkDevice device) {\n\t#ifdef VK_NO_PROTOTYPES\n")
i = len(deviceFuncs) - 1
while i >= 0:
    cfile.write('\t' + deviceFuncs[i] + " = (PFN_" + deviceFuncs[i] + ")vkGetDeviceProcAddr(device, \"" + deviceFuncs[i] + "\");\n")
    i -= 1
cfile.write("\t#endif\n}\n\n")

cfile.close()

