#include "Utils/mathUtils.h"
#include "Utils/numtypes.h"

void clamp(u32* v, u32 min, u32 max) {
    if (*v < min) *v = min;
    if (*v > max) *v = max;
}

void clampf(f32* v, f32 min, f32 max) {
    if (*v < min) *v = min;
    if (*v > max) *v = max;
}

f32 lerpf(f32 a, f32 b, f32 factor) {
    return a * (1.0f - factor) + b * factor;
}

u32 gcd(u32 a, u32 b) {
    return b == 0 ? a : gcd(b, a % b);
}

u32 lcm(u32 a, u32 b) {
    return (a / gcd(a, b)) * b;
}