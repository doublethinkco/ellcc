// REQUIRES: aarch64-registered-target
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +neon \
// RUN:   -ffp-contract=fast -S -O3 -o - %s | FileCheck %s

// Test new aarch64 intrinsics and types

#include <arm_neon.h>

int8x8_t test_vadd_s8(int8x8_t v1, int8x8_t v2) {
   // CHECK: test_vadd_s8
  return vadd_s8(v1, v2);
  // CHECK: add {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

int16x4_t test_vadd_s16(int16x4_t v1, int16x4_t v2) {
   // CHECK: test_vadd_s16
  return vadd_s16(v1, v2);
  // CHECK: add {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

int32x2_t test_vadd_s32(int32x2_t v1, int32x2_t v2) {
   // CHECK: test_vadd_s32
  return vadd_s32(v1, v2);
  // CHECK: add {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

int64x1_t test_vadd_s64(int64x1_t v1, int64x1_t v2) {
  // CHECK: test_vadd_s64
  return vadd_s64(v1, v2);
  // CHECK: add {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

float32x2_t test_vadd_f32(float32x2_t v1, float32x2_t v2) {
   // CHECK: test_vadd_f32
  return vadd_f32(v1, v2);
  // CHECK: fadd {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint8x8_t test_vadd_u8(uint8x8_t v1, uint8x8_t v2) {
   // CHECK: test_vadd_u8
  return vadd_u8(v1, v2);
  // CHECK: add {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vadd_u16(uint16x4_t v1, uint16x4_t v2) {
   // CHECK: test_vadd_u16
  return vadd_u16(v1, v2);
  // CHECK: add {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

uint32x2_t test_vadd_u32(uint32x2_t v1, uint32x2_t v2) {
   // CHECK: test_vadd_u32
  return vadd_u32(v1, v2);
  // CHECK: add {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint64x1_t test_vadd_u64(uint64x1_t v1, uint64x1_t v2) {
   // CHECK: test_vadd_u64
  return vadd_u64(v1, v2);
  // CHECK: add {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

int8x16_t test_vaddq_s8(int8x16_t v1, int8x16_t v2) {
   // CHECK: test_vaddq_s8
  return vaddq_s8(v1, v2);
  // CHECK: add {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

int16x8_t test_vaddq_s16(int16x8_t v1, int16x8_t v2) {
   // CHECK: test_vaddq_s16
  return vaddq_s16(v1, v2);
  // CHECK: add {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

int32x4_t test_vaddq_s32(int32x4_t v1,int32x4_t  v2) {
   // CHECK: test_vaddq_s32
  return vaddq_s32(v1, v2);
  // CHECK: add {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

int64x2_t test_vaddq_s64(int64x2_t v1, int64x2_t v2) {
   // CHECK: test_vaddq_s64
  return vaddq_s64(v1, v2);
  // CHECK: add {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

float32x4_t test_vaddq_f32(float32x4_t v1, float32x4_t v2) {
   // CHECK: test_vaddq_f32
  return vaddq_f32(v1, v2);
  // CHECK: fadd {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

float64x2_t test_vaddq_f64(float64x2_t v1, float64x2_t v2) {
  // CHECK: test_vaddq_f64
  return vaddq_f64(v1, v2);
  // CHECK: fadd {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

uint8x16_t test_vaddq_u8(uint8x16_t v1, uint8x16_t v2) {
   // CHECK: test_vaddq_u8
  return vaddq_u8(v1, v2);
  // CHECK: add {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vaddq_u16(uint16x8_t v1, uint16x8_t v2) {
   // CHECK: test_vaddq_u16
  return vaddq_u16(v1, v2);
  // CHECK: add {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

uint32x4_t test_vaddq_u32(uint32x4_t v1, uint32x4_t v2) {
   // CHECK: vaddq_u32
  return vaddq_u32(v1, v2);
  // CHECK: add {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint64x2_t test_vaddq_u64(uint64x2_t v1, uint64x2_t v2) {
   // CHECK: test_vaddq_u64
  return vaddq_u64(v1, v2);
  // CHECK: add {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

int8x8_t test_vsub_s8(int8x8_t v1, int8x8_t v2) {
   // CHECK: test_vsub_s8
  return vsub_s8(v1, v2);
  // CHECK: sub {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}
int16x4_t test_vsub_s16(int16x4_t v1, int16x4_t v2) {
   // CHECK: test_vsub_s16
  return vsub_s16(v1, v2);
  // CHECK: sub {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}
int32x2_t test_vsub_s32(int32x2_t v1, int32x2_t v2) {
   // CHECK: test_vsub_s32
  return vsub_s32(v1, v2);
  // CHECK: sub {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

int64x1_t test_vsub_s64(int64x1_t v1, int64x1_t v2) {
   // CHECK: test_vsub_s64
  return vsub_s64(v1, v2);
  // CHECK: sub {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

float32x2_t test_vsub_f32(float32x2_t v1, float32x2_t v2) {
   // CHECK: test_vsub_f32
  return vsub_f32(v1, v2);
  // CHECK: fsub {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint8x8_t test_vsub_u8(uint8x8_t v1, uint8x8_t v2) {
   // CHECK: test_vsub_u8
  return vsub_u8(v1, v2);
  // CHECK: sub {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vsub_u16(uint16x4_t v1, uint16x4_t v2) {
   // CHECK: test_vsub_u16
  return vsub_u16(v1, v2);
  // CHECK: sub {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

uint32x2_t test_vsub_u32(uint32x2_t v1, uint32x2_t v2) {
   // CHECK: test_vsub_u32
  return vsub_u32(v1, v2);
  // CHECK: sub {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint64x1_t test_vsub_u64(uint64x1_t v1, uint64x1_t v2) {
   // CHECK: test_vsub_u64
  return vsub_u64(v1, v2);
  // CHECK: sub {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

int8x16_t test_vsubq_s8(int8x16_t v1, int8x16_t v2) {
   // CHECK: test_vsubq_s8
  return vsubq_s8(v1, v2);
  // CHECK: sub {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

int16x8_t test_vsubq_s16(int16x8_t v1, int16x8_t v2) {
   // CHECK: test_vsubq_s16
  return vsubq_s16(v1, v2);
  // CHECK: sub {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

int32x4_t test_vsubq_s32(int32x4_t v1,int32x4_t  v2) {
   // CHECK: test_vsubq_s32
  return vsubq_s32(v1, v2);
  // CHECK: sub {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

int64x2_t test_vsubq_s64(int64x2_t v1, int64x2_t v2) {
   // CHECK: test_vsubq_s64
  return vsubq_s64(v1, v2);
  // CHECK: sub {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

float32x4_t test_vsubq_f32(float32x4_t v1, float32x4_t v2) {
   // CHECK: test_vsubq_f32
  return vsubq_f32(v1, v2);
  // CHECK: fsub {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

float64x2_t test_vsubq_f64(float64x2_t v1, float64x2_t v2) {
  // CHECK: test_vsubq_f64
  return vsubq_f64(v1, v2);
  // CHECK: fsub {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

uint8x16_t test_vsubq_u8(uint8x16_t v1, uint8x16_t v2) {
   // CHECK: test_vsubq_u8
  return vsubq_u8(v1, v2);
  // CHECK: sub {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vsubq_u16(uint16x8_t v1, uint16x8_t v2) {
   // CHECK: test_vsubq_u16
  return vsubq_u16(v1, v2);
  // CHECK: sub {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

uint32x4_t test_vsubq_u32(uint32x4_t v1, uint32x4_t v2) {
   // CHECK: vsubq_u32
  return vsubq_u32(v1, v2);
  // CHECK: sub {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint64x2_t test_vsubq_u64(uint64x2_t v1, uint64x2_t v2) {
   // CHECK: test_vsubq_u64
  return vsubq_u64(v1, v2);
  // CHECK: sub {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

int8x8_t test_vmul_s8(int8x8_t v1, int8x8_t v2) {
  // CHECK: test_vmul_s8
  return vmul_s8(v1, v2);
  // CHECK: mul {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

int16x4_t test_vmul_s16(int16x4_t v1, int16x4_t v2) {
  // CHECK: test_vmul_s16
  return vmul_s16(v1, v2);
  // CHECK: mul {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

int32x2_t test_vmul_s32(int32x2_t v1, int32x2_t v2) {
  // CHECK: test_vmul_s32
  return vmul_s32(v1, v2);
  // CHECK: mul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

float32x2_t test_vmul_f32(float32x2_t v1, float32x2_t v2) {
  // CHECK: test_vmul_f32
  return vmul_f32(v1, v2);
  // CHECK: fmul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}


uint8x8_t test_vmul_u8(uint8x8_t v1, uint8x8_t v2) {
  // CHECK: test_vmul_u8
  return vmul_u8(v1, v2);
  // CHECK: mul {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vmul_u16(uint16x4_t v1, uint16x4_t v2) {
  // CHECK: test_vmul_u16
  return vmul_u16(v1, v2);
  // CHECK: mul {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

uint32x2_t test_vmul_u32(uint32x2_t v1, uint32x2_t v2) {
  // CHECK: test_vmul_u32
  return vmul_u32(v1, v2);
  // CHECK: mul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

int8x16_t test_vmulq_s8(int8x16_t v1, int8x16_t v2) {
  // CHECK: test_vmulq_s8
  return vmulq_s8(v1, v2);
  // CHECK: mul {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

int16x8_t test_vmulq_s16(int16x8_t v1, int16x8_t v2) {
  // CHECK: test_vmulq_s16
  return vmulq_s16(v1, v2);
  // CHECK: mul {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

int32x4_t test_vmulq_s32(int32x4_t v1, int32x4_t v2) {
  // CHECK: test_vmulq_s32
  return vmulq_s32(v1, v2);
  // CHECK: mul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}
    
uint8x16_t test_vmulq_u8(uint8x16_t v1, uint8x16_t v2) {
  // CHECK: test_vmulq_u8
  return vmulq_u8(v1, v2);
  // CHECK: mul {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vmulq_u16(uint16x8_t v1, uint16x8_t v2) {
  // CHECK: test_vmulq_u16
  return vmulq_u16(v1, v2);
  // CHECK: mul {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

uint32x4_t test_vmulq_u32(uint32x4_t v1, uint32x4_t v2) {
  // CHECK: test_vmulq_u32
  return vmulq_u32(v1, v2);
  // CHECK: mul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

float32x4_t test_vmulq_f32(float32x4_t v1, float32x4_t v2) {
  // CHECK: test_vmulq_f32
  return vmulq_f32(v1, v2);
  // CHECK: fmul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

float64x2_t test_vmulq_f64(float64x2_t v1, float64x2_t v2) {
  // CHECK: test_vmulq_f64
  return vmulq_f64(v1, v2);
  // CHECK: fmul {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

poly8x8_t test_vmul_p8(poly8x8_t v1, poly8x8_t v2) {
  //  test_vmul_p8
  return vmul_p8(v1, v2);
  //  pmul {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

poly8x16_t test_vmulq_p8(poly8x16_t v1, poly8x16_t v2) {
  // test_vmulq_p8
  return vmulq_p8(v1, v2);
  // pmul {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}


int8x8_t test_vmla_s8(int8x8_t v1, int8x8_t v2, int8x8_t v3) {
  // CHECK: test_vmla_s8
  return vmla_s8(v1, v2, v3);
  // CHECK: mla {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

int8x8_t test_vmla_s16(int16x4_t v1, int16x4_t v2, int16x4_t v3) {
  // CHECK: test_vmla_s16
  return vmla_s16(v1, v2, v3);
  // CHECK: mla {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

int32x2_t test_vmla_s32(int32x2_t v1, int32x2_t v2, int32x2_t v3) {
  // CHECK: test_vmla_s32
  return vmla_s32(v1, v2, v3);
  // CHECK: mla {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

float32x2_t test_vmla_f32(float32x2_t v1, float32x2_t v2, float32x2_t v3) {
  // CHECK: test_vmla_f32
  return vmla_f32(v1, v2, v3);
  // CHECK: fmla {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint8x8_t test_vmla_u8(uint8x8_t v1, uint8x8_t v2, uint8x8_t v3) {
  // CHECK: test_vmla_u8
  return vmla_u8(v1, v2, v3);
  // CHECK: mla {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vmla_u16(uint16x4_t v1, uint16x4_t v2, uint16x4_t v3) {
  // CHECK: test_vmla_u16
  return vmla_u16(v1, v2, v3);
  // CHECK: mla {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

uint32x2_t test_vmla_u32(uint32x2_t v1, uint32x2_t v2, uint32x2_t v3) {
  // CHECK: test_vmla_u32
  return vmla_u32(v1, v2, v3);
  // CHECK: mla {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

int8x16_t test_vmlaq_s8(int8x16_t v1, int8x16_t v2, int8x16_t v3) {
  // CHECK: test_vmlaq_s8
  return vmlaq_s8(v1, v2, v3);
  // CHECK: mla {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

int16x8_t test_vmlaq_s16(int16x8_t v1, int16x8_t v2, int16x8_t v3) {
  // CHECK: test_vmlaq_s16
  return vmlaq_s16(v1, v2, v3);
  // CHECK: mla {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

int32x4_t test_vmlaq_s32(int32x4_t v1, int32x4_t v2, int32x4_t v3) {
  // CHECK: test_vmlaq_s32
  return vmlaq_s32(v1, v2, v3);
  // CHECK: mla {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
} 

float32x4_t test_vmlaq_f32(float32x4_t v1, float32x4_t v2, float32x4_t v3) {
  // CHECK: test_vmlaq_f32
  return vmlaq_f32(v1, v2, v3);
  // CHECK: fmla {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint8x16_t test_vmlaq_u8(uint8x16_t v1, uint8x16_t v2, uint8x16_t v3) {
   // CHECK: test_vmlaq_u8
  return vmlaq_u8(v1, v2, v3);
  // CHECK: mla {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vmlaq_u16(uint16x8_t v1, uint16x8_t v2, uint16x8_t v3) {
  // CHECK: test_vmlaq_u16
  return vmlaq_u16(v1, v2, v3);
  // CHECK: mla {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

uint32x4_t test_vmlaq_u32(uint32x4_t v1, uint32x4_t v2, uint32x4_t v3) {
  // CHECK: test_vmlaq_u32
  return vmlaq_u32(v1, v2, v3);
  // CHECK: mla {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

float64x2_t test_vmlaq_f64(float64x2_t v1, float64x2_t v2, float64x2_t v3) {
  // CHECK: test_vmlaq_f64
  return vmlaq_f64(v1, v2, v3);
  // CHECK: fmla {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

int8x8_t test_vmls_s8(int8x8_t v1, int8x8_t v2, int8x8_t v3) {
  // CHECK: test_vmls_s8
  return vmls_s8(v1, v2, v3);
  // CHECK: mls {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

int8x8_t test_vmls_s16(int16x4_t v1, int16x4_t v2, int16x4_t v3) {
  // CHECK: test_vmls_s16
  return vmls_s16(v1, v2, v3);
  // CHECK: mls {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

int32x2_t test_vmls_s32(int32x2_t v1, int32x2_t v2, int32x2_t v3) {
  // CHECK: test_vmls_s32
  return vmls_s32(v1, v2, v3);
  // CHECK: mls {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

float32x2_t test_vmls_f32(float32x2_t v1, float32x2_t v2, float32x2_t v3) {
  // CHECK: test_vmls_f32
  return vmls_f32(v1, v2, v3);
  // CHECK: fmls {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint8x8_t test_vmls_u8(uint8x8_t v1, uint8x8_t v2, uint8x8_t v3) {
  // CHECK: test_vmls_u8
  return vmls_u8(v1, v2, v3);
  // CHECK: mls {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vmls_u16(uint16x4_t v1, uint16x4_t v2, uint16x4_t v3) {
  // CHECK: test_vmls_u16
  return vmls_u16(v1, v2, v3);
  // CHECK: mls {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

uint32x2_t test_vmls_u32(uint32x2_t v1, uint32x2_t v2, uint32x2_t v3) {
  // CHECK: test_vmls_u32
  return vmls_u32(v1, v2, v3);
  // CHECK: mls {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}
int8x16_t test_vmlsq_s8(int8x16_t v1, int8x16_t v2, int8x16_t v3) {
  // CHECK: test_vmlsq_s8
  return vmlsq_s8(v1, v2, v3);
  // CHECK: mls {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

int16x8_t test_vmlsq_s16(int16x8_t v1, int16x8_t v2, int16x8_t v3) {
  // CHECK: test_vmlsq_s16
  return vmlsq_s16(v1, v2, v3);
  // CHECK: mls {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

int32x4_t test_vmlsq_s32(int32x4_t v1, int32x4_t v2, int32x4_t v3) {
  // CHECK: test_vmlsq_s32
  return vmlsq_s32(v1, v2, v3);
  // CHECK: mls {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

float32x4_t test_vmlsq_f32(float32x4_t v1, float32x4_t v2, float32x4_t v3) {
  // CHECK: test_vmlsq_f32
  return vmlsq_f32(v1, v2, v3);
  // CHECK: fmls {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}
uint8x16_t test_vmlsq_u8(uint8x16_t v1, uint8x16_t v2, uint8x16_t v3) {
  // CHECK: test_vmlsq_u8
  return vmlsq_u8(v1, v2, v3);
  // CHECK: mls {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vmlsq_u16(uint16x8_t v1, uint16x8_t v2, uint16x8_t v3) {
  // CHECK: test_vmlsq_u16
  return vmlsq_u16(v1, v2, v3);
  // CHECK: mls {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

uint32x4_t test_vmlsq_u32(uint32x4_t v1, uint32x4_t v2, uint32x4_t v3) {
  // CHECK: test_vmlsq_u32
  return vmlsq_u32(v1, v2, v3);
  // CHECK: mls {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

float64x2_t test_vmlsq_f64(float64x2_t v1, float64x2_t v2, float64x2_t v3) {
  // CHECK: test_vmlsq_f64
  return vmlsq_f64(v1, v2, v3);
  // CHECK: fmls {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}
float32x2_t test_vfma_f32(float32x2_t v1, float32x2_t v2, float32x2_t v3) {
  // CHECK: test_vfma_f32
  return vfma_f32(v1, v2, v3);
  // CHECK: fmla {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

float32x4_t test_vfmaq_f32(float32x4_t v1, float32x4_t v2, float32x4_t v3) {
  // CHECK: test_vfmaq_f32
  return vfmaq_f32(v1, v2, v3);
  // CHECK: fmla {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

float64x2_t test_vfmaq_f64(float64x2_t v1, float64x2_t v2, float64x2_t v3) {
  // CHECK: test_vfmaq_f64
  return vfmaq_f64(v1, v2, v3);
  // CHECK: fmla {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}
float32x2_t test_vfms_f32(float32x2_t v1, float32x2_t v2, float32x2_t v3) {
  // CHECK: test_vfms_f32
  return vfms_f32(v1, v2, v3);
  // CHECK: fmls v0.2s, v1.2s, v2.2s
}

float32x4_t test_vfmsq_f32(float32x4_t v1, float32x4_t v2, float32x4_t v3) {
  // CHECK: test_vfmsq_f32
  return vfmsq_f32(v1, v2, v3);
  // CHECK: fmls v0.4s, v1.4s, v2.4s
}

float64x2_t test_vfmsq_f64(float64x2_t v1, float64x2_t v2, float64x2_t v3) {
  // CHECK: vfmsq_f64
  return vfmsq_f64(v1, v2, v3);
  // CHECK: fmls v0.2d, v1.2d, v2.2d
}

float64x2_t test_vdivq_f64(float64x2_t v1, float64x2_t v2) {
  // CHECK: test_vdivq_f64
  return vdivq_f64(v1, v2);
  // CHECK: fdiv {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

float32x4_t test_vdivq_f32(float32x4_t v1, float32x4_t v2) {
  // CHECK: test_vdivq_f32
  return vdivq_f32(v1, v2);
  // CHECK: fdiv {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

float32x2_t test_vdiv_f32(float32x2_t v1, float32x2_t v2) {
  // CHECK: test_vdiv_f32
  return vdiv_f32(v1, v2);
  // CHECK: fdiv {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

int8x8_t test_vaba_s8(int8x8_t v1, int8x8_t v2, int8x8_t v3) {
  // CHECK: test_vaba_s8
  return vaba_s8(v1, v2, v3);
  // CHECK: saba {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

int16x4_t test_vaba_s16(int16x4_t v1, int16x4_t v2, int16x4_t v3) {
  // CHECK: test_vaba_s16
  return vaba_s16(v1, v2, v3);
  // CHECK: saba {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

int32x2_t test_vaba_s32(int32x2_t v1, int32x2_t v2, int32x2_t v3) {
  // CHECK: test_vaba_s32
  return vaba_s32(v1, v2, v3);
  // CHECK: saba {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint8x8_t test_vaba_u8(uint8x8_t v1, uint8x8_t v2, uint8x8_t v3) {
  // CHECK: test_vaba_u8
  return vaba_u8(v1, v2, v3);
  // CHECK: uaba {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vaba_u16(uint16x4_t v1, uint16x4_t v2, uint16x4_t v3) {
  // CHECK: test_vaba_u16
  return vaba_u16(v1, v2, v3);
  // CHECK: uaba {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

uint32x2_t test_vaba_u32(uint32x2_t v1, uint32x2_t v2, uint32x2_t v3) {
  // CHECK: test_vaba_u32
  return vaba_u32(v1, v2, v3);
  // CHECK: uaba {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

int8x16_t test_vabaq_s8(int8x16_t v1, int8x16_t v2, int8x16_t v3) {
  // CHECK: test_vabaq_s8
  return vabaq_s8(v1, v2, v3);
  // CHECK: saba {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

int16x8_t test_vabaq_s16(int16x8_t v1, int16x8_t v2, int16x8_t v3) {
  // CHECK: test_vabaq_s16
  return vabaq_s16(v1, v2, v3);
  // CHECK: saba {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

int32x4_t test_vabaq_s32(int32x4_t v1, int32x4_t v2, int32x4_t v3) {
  // CHECK: test_vabaq_s32
  return vabaq_s32(v1, v2, v3);
  // CHECK: saba {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint8x16_t test_vabaq_u8(uint8x16_t v1, uint8x16_t v2, uint8x16_t v3) {
  // CHECK: test_vabaq_u8
  return vabaq_u8(v1, v2, v3);
  // CHECK: uaba {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vabaq_u16(uint16x8_t v1, uint16x8_t v2, uint16x8_t v3) {
  // CHECK: test_vabaq_u16
  return vabaq_u16(v1, v2, v3);
  // CHECK: uaba {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

uint32x4_t test_vabaq_u32(uint32x4_t v1, uint32x4_t v2, uint32x4_t v3) {
  // CHECK: test_vabaq_u32
  return vabaq_u32(v1, v2, v3);
  // CHECK: uaba {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

int8x8_t test_vabd_s8(int8x8_t v1, int8x8_t v2) {
  // CHECK: test_vabd_s8
  return vabd_s8(v1, v2);
  // CHECK: sabd {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

int16x4_t test_vabd_s16(int16x4_t v1, int16x4_t v2) {
  // CHECK: test_vabd_s16
  return vabd_s16(v1, v2);
  // CHECK: sabd {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

int32x2_t test_vabd_s32(int32x2_t v1, int32x2_t v2) {
  // CHECK: test_vabd_s32
  return vabd_s32(v1, v2);
  // CHECK: sabd {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint8x8_t test_vabd_u8(uint8x8_t v1, uint8x8_t v2) {
  // CHECK: test_vabd_u8
  return vabd_u8(v1, v2);
  // CHECK: uabd {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vabd_u16(uint16x4_t v1, uint16x4_t v2) {
  // CHECK: test_vabd_u16
  return vabd_u16(v1, v2);
  // CHECK: uabd {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

uint32x2_t test_vabd_u32(uint32x2_t v1, uint32x2_t v2) {
  // CHECK: test_vabd_u32
  return vabd_u32(v1, v2);
  // CHECK: uabd {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

float32x2_t test_vabd_f32(float32x2_t v1, float32x2_t v2) {
  // CHECK: test_vabd_f32
  return vabd_f32(v1, v2);
  // CHECK: fabd {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

int8x16_t test_vabdq_s8(int8x16_t v1, int8x16_t v2) {
  // CHECK: test_vabdq_s8
  return vabdq_s8(v1, v2);
  // CHECK: sabd {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

int16x8_t test_vabdq_s16(int16x8_t v1, int16x8_t v2) {
  // CHECK: test_vabdq_s16
  return vabdq_s16(v1, v2);
  // CHECK: sabd {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

int32x4_t test_vabdq_s32(int32x4_t v1, int32x4_t v2) {
  // CHECK: test_vabdq_s32
  return vabdq_s32(v1, v2);
  // CHECK: sabd {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint8x16_t test_vabdq_u8(uint8x16_t v1, uint8x16_t v2) {
  // CHECK: test_vabdq_u8
  return vabdq_u8(v1, v2);
  // CHECK: uabd {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vabdq_u16(uint16x8_t v1, uint16x8_t v2) {
  // CHECK: test_vabdq_u16
  return vabdq_u16(v1, v2);
  // CHECK: uabd {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

uint32x4_t test_vabdq_u32(uint32x4_t v1, uint32x4_t v2) {
  // CHECK: test_vabdq_u32
  return vabdq_u32(v1, v2);
  // CHECK: uabd {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

float32x4_t test_vabdq_f32(float32x4_t v1, float32x4_t v2) {
  // CHECK: test_vabdq_f32
  return vabdq_f32(v1, v2);
  // CHECK: fabd {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

float64x2_t test_vabdq_f64(float64x2_t v1, float64x2_t v2) {
  // CHECK: test_vabdq_f64
  return vabdq_f64(v1, v2);
  // CHECK: fabd {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}


int8x8_t test_vbsl_s8(uint8x8_t v1, int8x8_t v2, int8x8_t v3) {
  // CHECK: test_vbsl_s8
  return vbsl_s8(v1, v2, v3);
  // CHECK: bsl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

int8x8_t test_vbsl_s16(uint16x4_t v1, int16x4_t v2, int16x4_t v3) {
  // CHECK: test_vbsl_s16
  return vbsl_s16(v1, v2, v3);
  // CHECK: bsl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

int32x2_t test_vbsl_s32(uint32x2_t v1, int32x2_t v2, int32x2_t v3) {
  // CHECK: test_vbsl_s32
  return vbsl_s32(v1, v2, v3);
  // CHECK: bsl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint64x1_t test_vbsl_s64(uint64x1_t v1, uint64x1_t v2, uint64x1_t v3) {
  // CHECK: test_vbsl_s64
  return vbsl_s64(v1, v2, v3);
  // CHECK: bsl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint8x8_t test_vbsl_u8(uint8x8_t v1, uint8x8_t v2, uint8x8_t v3) {
  // CHECK: test_vbsl_u8
  return vbsl_u8(v1, v2, v3);
  // CHECK: bsl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vbsl_u16(uint16x4_t v1, uint16x4_t v2, uint16x4_t v3) {
  // CHECK: test_vbsl_u16
  return vbsl_u16(v1, v2, v3);
  // CHECK: bsl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint32x2_t test_vbsl_u32(uint32x2_t v1, uint32x2_t v2, uint32x2_t v3) {
  // CHECK: test_vbsl_u32
  return vbsl_u32(v1, v2, v3);
  // CHECK: bsl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint64x1_t test_vbsl_u64(uint64x1_t v1, uint64x1_t v2, uint64x1_t v3) {
  // CHECK: test_vbsl_u64
  return vbsl_u64(v1, v2, v3);
  // CHECK: bsl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

float32x2_t test_vbsl_f32(float32x2_t v1, float32x2_t v2, float32x2_t v3) {
  // CHECK: test_vbsl_f32
  return vbsl_f32(v1, v2, v3);
  // CHECK: bsl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

poly8x8_t test_vbsl_p8(uint8x8_t v1, poly8x8_t v2, poly8x8_t v3) {
  // CHECK: test_vbsl_p8
  return vbsl_p8(v1, v2, v3);
  // CHECK: bsl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

poly16x4_t test_vbsl_p16(uint16x4_t v1, poly16x4_t v2, poly16x4_t v3) {
  // CHECK: test_vbsl_p16
  return vbsl_p16(v1, v2, v3);
  // CHECK: bsl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

int8x16_t test_vbslq_s8(uint8x16_t v1, int8x16_t v2, int8x16_t v3) {
  // CHECK: test_vbslq_s8
  return vbslq_s8(v1, v2, v3);
  // CHECK: bsl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

int16x8_t test_vbslq_s16(uint16x8_t v1, int16x8_t v2, int16x8_t v3) {
  // CHECK: test_vbslq_s16
  return vbslq_s16(v1, v2, v3);
  // CHECK: bsl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

int32x4_t test_vbslq_s32(uint32x4_t v1, int32x4_t v2, int32x4_t v3) {
  // CHECK: test_vbslq_s32
  return vbslq_s32(v1, v2, v3);
  // CHECK: bsl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

int64x2_t test_vbslq_s64(uint64x2_t v1, int64x2_t v2, int64x2_t v3) {
  // CHECK: test_vbslq_s64
  return vbslq_s64(v1, v2, v3);
  // CHECK: bsl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint8x16_t test_vbslq_u8(uint8x16_t v1, uint8x16_t v2, uint8x16_t v3) {
  // CHECK: test_vbslq_u8
  return vbslq_u8(v1, v2, v3);
  // CHECK: bsl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vbslq_u16(uint16x8_t v1, uint16x8_t v2, uint16x8_t v3) {
  // CHECK: test_vbslq_u16
  return vbslq_u16(v1, v2, v3);
  // CHECK: bsl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

int32x4_t test_vbslq_u32(uint32x4_t v1, int32x4_t v2, int32x4_t v3) {
  // CHECK: test_vbslq_u32
  return vbslq_s32(v1, v2, v3);
  // CHECK: bsl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint64x2_t test_vbslq_u64(uint64x2_t v1, uint64x2_t v2, uint64x2_t v3) {
  // CHECK: test_vbslq_u64
  return vbslq_u64(v1, v2, v3);
  // CHECK: bsl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

float32x4_t test_vbslq_f32(uint32x4_t v1, float32x4_t v2, float32x4_t v3) {
  // CHECK: test_vbslq_f32
  return vbslq_f32(v1, v2, v3);
  // CHECK: bsl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

poly8x16_t test_vbslq_p8(uint8x16_t v1, poly8x16_t v2, poly8x16_t v3) {
  // CHECK: test_vbslq_p8
  return vbslq_p8(v1, v2, v3);
  // CHECK: bsl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

poly16x8_t test_vbslq_p16(uint16x8_t v1, poly16x8_t v2, poly16x8_t v3) {
  // CHECK: test_vbslq_p16
  return vbslq_p16(v1, v2, v3);
  // CHECK: bsl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

float64x2_t test_vbslq_f64(uint64x2_t v1, float64x2_t v2, float64x2_t v3) {
  // CHECK: test_vbslq_f64
  return vbslq_f64(v1, v2, v3);
  // CHECK: bsl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

float32x2_t test_vrecps_f32(float32x2_t v1, float32x2_t v2) {
   // CHECK: test_vrecps_f32
   return vrecps_f32(v1, v2);
   // CHECK: frecps {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

float32x4_t test_vrecpsq_f32(float32x4_t v1, float32x4_t v2) {
   // CHECK: test_vrecpsq_f32
   return vrecpsq_f32(v1, v2);
   // CHECK: frecps {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

float64x2_t test_vrecpsq_f64(float64x2_t v1, float64x2_t v2) {
   // CHECK: test_vrecpsq_f64
  return vrecpsq_f64(v1, v2);
  // CHECK: frecps {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

float32x2_t test_vrsqrts_f32(float32x2_t v1, float32x2_t v2) {
   // CHECK: test_vrsqrts_f32
  return vrsqrts_f32(v1, v2);
  // CHECK: frsqrts {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

float32x4_t test_vrsqrtsq_f32(float32x4_t v1, float32x4_t v2) {
   // CHECK: test_vrsqrtsq_f32
  return vrsqrtsq_f32(v1, v2);
  // CHECK: frsqrts {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

float64x2_t test_vrsqrtsq_f64(float64x2_t v1, float64x2_t v2) {
   // CHECK: test_vrsqrtsq_f64
  return vrsqrtsq_f64(v1, v2);
  // CHECK: frsqrts {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

uint32x2_t test_vcage_f32(float32x2_t v1, float32x2_t v2) {
  // CHECK: test_vcage_f32
  return vcage_f32(v1, v2);
  // CHECK: facge {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint32x4_t test_vcageq_f32(float32x4_t v1, float32x4_t v2) {
  // CHECK: test_vcageq_f32
  return vcageq_f32(v1, v2);
  // CHECK: facge {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint64x2_t test_vcageq_f64(float64x2_t v1, float64x2_t v2) {
  // CHECK: test_vcageq_f64
  return vcageq_f64(v1, v2);
  // CHECK: facge {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

uint32x2_t test_vcagt_f32(float32x2_t v1, float32x2_t v2) {
  // CHECK: test_vcagt_f32
  return vcagt_f32(v1, v2);
  // CHECK: facgt {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint32x4_t test_vcagtq_f32(float32x4_t v1, float32x4_t v2) {
  // CHECK: test_vcagtq_f32
  return vcagtq_f32(v1, v2);
  // CHECK: facgt {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint64x2_t test_vcagtq_f64(float64x2_t v1, float64x2_t v2) {
  // CHECK: test_vcagtq_f64
  return vcagtq_f64(v1, v2);
  // CHECK: facgt {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

uint32x2_t test_vcale_f32(float32x2_t v1, float32x2_t v2) {
  // CHECK: test_vcale_f32
  return vcale_f32(v1, v2);
 // Using registers other than v0, v1 are possible, but would be odd.
  // CHECK: facge {{v[0-9]+}}.2s, v1.2s, v0.2s
}

uint32x4_t test_vcaleq_f32(float32x4_t v1, float32x4_t v2) {
  // CHECK: test_vcaleq_f32
  return vcaleq_f32(v1, v2);
  // Using registers other than v0, v1 are possible, but would be odd.
  // CHECK: facge {{v[0-9]+}}.4s, v1.4s, v0.4s
}

uint64x2_t test_vcaleq_f64(float64x2_t v1, float64x2_t v2) {
  // CHECK: test_vcaleq_f64
  return vcaleq_f64(v1, v2);
  // Using registers other than v0, v1 are possible, but would be odd.
  // CHECK: facge {{v[0-9]+}}.2d, v1.2d, v0.2d
}

uint32x2_t test_vcalt_f32(float32x2_t v1, float32x2_t v2) {
  // CHECK: test_vcalt_f32
  return vcalt_f32(v1, v2);
  // Using registers other than v0, v1 are possible, but would be odd.
  // CHECK: facgt {{v[0-9]+}}.2s, v1.2s, v0.2s
}

uint32x4_t test_vcaltq_f32(float32x4_t v1, float32x4_t v2) {
  // CHECK: test_vcaltq_f32
  return vcaltq_f32(v1, v2);
  // Using registers other than v0, v1 are possible, but would be odd.
  // CHECK: facgt {{v[0-9]+}}.4s, v1.4s, v0.4s
}

uint64x2_t test_vcaltq_f64(float64x2_t v1, float64x2_t v2) {
  // CHECK: test_vcaltq_f64
  return vcaltq_f64(v1, v2);
  // Using registers other than v0, v1 are possible, but would be odd.
  // CHECK: facgt {{v[0-9]+}}.2d, v1.2d, v0.2d
}

uint8x8_t test_vtst_s8(int8x8_t v1, int8x8_t v2) {
   // CHECK: test_vtst_s8
  return vtst_s8(v1, v2);
  // CHECK: cmtst {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vtst_s16(int16x4_t v1, int16x4_t v2) {
   // CHECK: test_vtst_s16
  return vtst_s16(v1, v2);
  // CHECK: cmtst {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

uint32x2_t test_vtst_s32(int32x2_t v1, int32x2_t v2) {
   // CHECK: test_vtst_s32
  return vtst_s32(v1, v2);
  // CHECK: cmtst {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint8x8_t test_vtst_u8(uint8x8_t v1, uint8x8_t v2) {
   // CHECK: test_vtst_u8
  return vtst_u8(v1, v2);
  // CHECK: cmtst {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vtst_u16(uint16x4_t v1, uint16x4_t v2) {
   // CHECK: test_vtst_u16
  return vtst_u16(v1, v2);
  // CHECK: cmtst {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

uint32x2_t test_vtst_u32(uint32x2_t v1, uint32x2_t v2) {
   // CHECK: test_vtst_u32
  return vtst_u32(v1, v2);
  // CHECK: cmtst {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint8x16_t test_vtstq_s8(int8x16_t v1, int8x16_t v2) {
   // CHECK: test_vtstq_s8
  return vtstq_s8(v1, v2);
  // CHECK: cmtst {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vtstq_s16(int16x8_t v1, int16x8_t v2) {
   // CHECK: test_vtstq_s16
  return vtstq_s16(v1, v2);
  // CHECK: cmtst {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

uint32x4_t test_vtstq_s32(int32x4_t v1, int32x4_t v2) {
   // CHECK: test_vtstq_s32
  return vtstq_s32(v1, v2);
  // CHECK: cmtst {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint8x16_t test_vtstq_u8(uint8x16_t v1, uint8x16_t v2) {
   // CHECK: test_vtstq_u8
  return vtstq_u8(v1, v2);
  // CHECK: cmtst {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vtstq_u16(uint16x8_t v1, uint16x8_t v2) {
   // CHECK: test_vtstq_u16
  return vtstq_u16(v1, v2);
  // CHECK: cmtst {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

uint32x4_t test_vtstq_u32(uint32x4_t v1, uint32x4_t v2) {
   // CHECK: test_vtstq_u32
  return vtstq_u32(v1, v2);
  // CHECK: cmtst {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint64x2_t test_vtstq_s64(int64x2_t v1, int64x2_t v2) {
   // CHECK: test_vtstq_s64
  return vtstq_s64(v1, v2);
  // CHECK: cmtst {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

uint64x2_t test_vtstq_u64(uint64x2_t v1, uint64x2_t v2) {
   // CHECK: test_vtstq_u64
  return vtstq_u64(v1, v2);
  // CHECK: cmtst {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

uint8x8_t test_vtst_p8(poly8x8_t v1, poly8x8_t v2) {
   // CHECK: test_vtst_p8
  return vtst_p8(v1, v2);
  // CHECK: cmtst {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vtst_p16(poly16x4_t v1, poly16x4_t v2) {
   // CHECK: test_vtst_p16
  return vtst_p16(v1, v2);
  // CHECK: cmtst {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

uint8x16_t test_vtstq_p8(poly8x16_t v1, poly8x16_t v2) {
   // CHECK: test_vtstq_p8
  return vtstq_p8(v1, v2);
  // CHECK: cmtst {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vtstq_p16(poly16x8_t v1, poly16x8_t v2) {
   // CHECK: test_vtstq_p16
  return vtstq_p16(v1, v2);
  // CHECK: cmtst {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}


uint8x8_t test_vceq_s8(int8x8_t v1, int8x8_t v2) {
  // CHECK: test_vceq_s8
  return vceq_s8(v1, v2);
  // CHECK: cmeq {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vceq_s16(int16x4_t v1, int16x4_t v2) {
  // CHECK: test_vceq_s16
  return vceq_s16(v1, v2);
  // CHECK: cmeq {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

uint32x2_t test_vceq_s32(int32x2_t v1, int32x2_t v2) {
  // CHECK: test_vceq_s32
  return vceq_s32(v1, v2);
  // CHECK: cmeq {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint32x2_t test_vceq_f32(float32x2_t v1, float32x2_t v2) {
  // CHECK: test_vceq_f32
  return vceq_f32(v1, v2);
  // CHECK: fcmeq {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint8x8_t test_vceq_u8(uint8x8_t v1, uint8x8_t v2) {
  // CHECK: test_vceq_u8
  return vceq_u8(v1, v2);
  // CHECK: cmeq {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vceq_u16(uint16x4_t v1, uint16x4_t v2) {
  // CHECK: test_vceq_u16
  return vceq_u16(v1, v2);
  // CHECK: cmeq {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

uint32x2_t test_vceq_u32(uint32x2_t v1, uint32x2_t v2) {
  // CHECK: test_vceq_u32
  return vceq_u32(v1, v2);
  // CHECK: cmeq {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint8x8_t test_vceq_p8(poly8x8_t v1, poly8x8_t v2) {
  // CHECK: test_vceq_p8
  return vceq_p8(v1, v2);
  // CHECK: cmeq {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint8x16_t test_vceqq_s8(int8x16_t v1, int8x16_t v2) {
  // CHECK: test_vceqq_s8
  return vceqq_s8(v1, v2);
  // CHECK: cmeq {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vceqq_s16(int16x8_t v1, int16x8_t v2) {
  // CHECK: test_vceqq_s16
  return vceqq_s16(v1, v2);
  // CHECK: cmeq {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

uint32x4_t test_vceqq_s32(int32x4_t v1, int32x4_t v2) {
  // CHECK: test_vceqq_s32
  return vceqq_s32(v1, v2);
  // CHECK: cmeq {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint32x4_t test_vceqq_f32(float32x4_t v1, float32x4_t v2) {
  // CHECK: test_vceqq_f32
  return vceqq_f32(v1, v2);
  // CHECK: fcmeq {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint8x16_t test_vceqq_u8(uint8x16_t v1, uint8x16_t v2) {
  // CHECK: test_vceqq_u8
  return vceqq_u8(v1, v2);
  // CHECK: cmeq {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vceqq_u16(uint16x8_t v1, uint16x8_t v2) {
  // CHECK: test_vceqq_u16
  return vceqq_u16(v1, v2);
  // CHECK: cmeq {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

uint32x4_t test_vceqq_u32(uint32x4_t v1, uint32x4_t v2) {
  // CHECK: test_vceqq_u32
  return vceqq_u32(v1, v2);
  // CHECK: cmeq {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint8x16_t test_vceqq_p8(poly8x16_t v1, poly8x16_t v2) {
  // CHECK: test_vceqq_p8
  return vceqq_p8(v1, v2);
  // CHECK: cmeq {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}


uint64x2_t test_vceqq_s64(int64x2_t v1, int64x2_t v2) {
  // CHECK: test_vceqq_s64
  return vceqq_s64(v1, v2);
  // CHECK: cmeq {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

uint64x2_t test_vceqq_u64(uint64x2_t v1, uint64x2_t v2) {
  // CHECK: test_vceqq_u64
  return vceqq_u64(v1, v2);
  // CHECK: cmeq {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

uint64x2_t test_vceqq_f64(float64x2_t v1, float64x2_t v2) {
  // CHECK: test_vceqq_f64
  return vceqq_f64(v1, v2);
  // CHECK: fcmeq {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}
uint8x8_t test_vcge_s8(int8x8_t v1, int8x8_t v2) {
// CHECK: test_vcge_s8
  return vcge_s8(v1, v2);
// CHECK: cmge {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vcge_s16(int16x4_t v1, int16x4_t v2) {
// CHECK: test_vcge_s16
  return vcge_s16(v1, v2);
// CHECK: cmge {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

uint32x2_t test_vcge_s32(int32x2_t v1, int32x2_t v2) {
// CHECK: test_vcge_s32
  return vcge_s32(v1, v2);
// CHECK: cmge {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint32x2_t test_vcge_f32(float32x2_t v1, float32x2_t v2) {
// CHECK: test_vcge_f32
  return vcge_f32(v1, v2);
// CHECK: fcmge {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint8x8_t test_vcge_u8(uint8x8_t v1, uint8x8_t v2) {
// CHECK: test_vcge_u8
  return vcge_u8(v1, v2);
// CHECK: cmhs {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vcge_u16(uint16x4_t v1, uint16x4_t v2) {
// CHECK: test_vcge_u16
  return vcge_u16(v1, v2);
// CHECK: cmhs {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

uint32x2_t test_vcge_u32(uint32x2_t v1, uint32x2_t v2) {
// CHECK: test_vcge_u32
  return vcge_u32(v1, v2);
// CHECK: cmhs {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint8x16_t test_vcgeq_s8(int8x16_t v1, int8x16_t v2) {
// CHECK: test_vcgeq_s8
  return vcgeq_s8(v1, v2);
// CHECK: cmge {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vcgeq_s16(int16x8_t v1, int16x8_t v2) {
// CHECK: test_vcgeq_s16
  return vcgeq_s16(v1, v2);
// CHECK: cmge {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

uint32x4_t test_vcgeq_s32(int32x4_t v1, int32x4_t v2) {
// CHECK: test_vcgeq_s32
  return vcgeq_s32(v1, v2);
// CHECK: cmge {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint32x4_t test_vcgeq_f32(float32x4_t v1, float32x4_t v2) {
// CHECK: test_vcgeq_f32
  return vcgeq_f32(v1, v2);
// CHECK: fcmge {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint8x16_t test_vcgeq_u8(uint8x16_t v1, uint8x16_t v2) {
// CHECK: test_vcgeq_u8
  return vcgeq_u8(v1, v2);
// CHECK: cmhs {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vcgeq_u16(uint16x8_t v1, uint16x8_t v2) {
// CHECK: test_vcgeq_u16
  return vcgeq_u16(v1, v2);
// CHECK: cmhs {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

uint32x4_t test_vcgeq_u32(uint32x4_t v1, uint32x4_t v2) {
// CHECK: test_vcgeq_u32
  return vcgeq_u32(v1, v2);
// CHECK: cmhs {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint64x2_t test_vcgeq_s64(int64x2_t v1, int64x2_t v2) {
// CHECK: test_vcgeq_s64
  return vcgeq_s64(v1, v2);
// CHECK: cmge {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

uint64x2_t test_vcgeq_u64(uint64x2_t v1, uint64x2_t v2) {
// CHECK: test_vcgeq_u64
  return vcgeq_u64(v1, v2);
// CHECK: cmhs {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

uint64x2_t test_vcgeq_f64(float64x2_t v1, float64x2_t v2) {
// CHECK: test_vcgeq_f64
  return vcgeq_f64(v1, v2);
// CHECK: fcmge {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

// Notes about vcle:
// LE condition predicate implemented as GE, so check reversed operands.
// Using registers other than v0, v1 are possible, but would be odd.
uint8x8_t test_vcle_s8(int8x8_t v1, int8x8_t v2) {
  // CHECK: test_vcle_s8
  return vcle_s8(v1, v2);
  // CHECK: cmge {{v[0-9]+}}.8b, v1.8b, v0.8b
}

uint16x4_t test_vcle_s16(int16x4_t v1, int16x4_t v2) {
  // CHECK: test_vcle_s16
  return vcle_s16(v1, v2);
  // CHECK: cmge {{v[0-9]+}}.4h, v1.4h, v0.4h
}

uint32x2_t test_vcle_s32(int32x2_t v1, int32x2_t v2) {
  // CHECK: test_vcle_s32
  return vcle_s32(v1, v2);
  // CHECK: cmge {{v[0-9]+}}.2s, v1.2s, v0.2s
}

uint32x2_t test_vcle_f32(float32x2_t v1, float32x2_t v2) {
  // CHECK: test_vcle_f32
  return vcle_f32(v1, v2);
  // CHECK: fcmge {{v[0-9]+}}.2s, v1.2s, v0.2s
}

uint8x8_t test_vcle_u8(uint8x8_t v1, uint8x8_t v2) {
  // CHECK: test_vcle_u8
  return vcle_u8(v1, v2);
  // CHECK: cmhs {{v[0-9]+}}.8b, v1.8b, v0.8b
}

uint16x4_t test_vcle_u16(uint16x4_t v1, uint16x4_t v2) {
  // CHECK: test_vcle_u16
  return vcle_u16(v1, v2);
  // CHECK: cmhs {{v[0-9]+}}.4h, v1.4h, v0.4h
}

uint32x2_t test_vcle_u32(uint32x2_t v1, uint32x2_t v2) {
  // CHECK: test_vcle_u32
  return vcle_u32(v1, v2);
  // CHECK: cmhs {{v[0-9]+}}.2s, v1.2s, v0.2s
}

uint8x16_t test_vcleq_s8(int8x16_t v1, int8x16_t v2) {
  // CHECK: test_vcleq_s8
  return vcleq_s8(v1, v2);
  // CHECK: cmge {{v[0-9]+}}.16b, v1.16b, v0.16b
}

uint16x8_t test_vcleq_s16(int16x8_t v1, int16x8_t v2) {
  // CHECK: test_vcleq_s16
  return vcleq_s16(v1, v2);
  // CHECK: cmge {{v[0-9]+}}.8h, v1.8h, v0.8h
}

uint32x4_t test_vcleq_s32(int32x4_t v1, int32x4_t v2) {
  // CHECK: test_vcleq_s32
  return vcleq_s32(v1, v2);
  // CHECK: cmge {{v[0-9]+}}.4s, v1.4s, v0.4s
}

uint32x4_t test_vcleq_f32(float32x4_t v1, float32x4_t v2) {
  // CHECK: test_vcleq_f32
  return vcleq_f32(v1, v2);
  // CHECK: fcmge {{v[0-9]+}}.4s, v1.4s, v0.4s
}

uint8x16_t test_vcleq_u8(uint8x16_t v1, uint8x16_t v2) {
  // CHECK: test_vcleq_u8
  return vcleq_u8(v1, v2);
  // CHECK: cmhs {{v[0-9]+}}.16b, v1.16b, v0.16b
}

uint16x8_t test_vcleq_u16(uint16x8_t v1, uint16x8_t v2) {
  // CHECK: test_vcleq_u16
  return vcleq_u16(v1, v2);
  // CHECK: cmhs {{v[0-9]+}}.8h, v1.8h, v0.8h
}

uint32x4_t test_vcleq_u32(uint32x4_t v1, uint32x4_t v2) {
  // CHECK: test_vcleq_u32
  return vcleq_u32(v1, v2);
  // CHECK: cmhs {{v[0-9]+}}.4s, v1.4s, v0.4s
}

uint64x2_t test_vcleq_s64(int64x2_t v1, int64x2_t v2) {
  // CHECK: test_vcleq_s64
  return vcleq_s64(v1, v2);
  // CHECK: cmge {{v[0-9]+}}.2d, v1.2d, v0.2d
}

uint64x2_t test_vcleq_u64(uint64x2_t v1, uint64x2_t v2) {
  // CHECK: test_vcleq_u64
  return vcleq_u64(v1, v2);
  // CHECK: cmhs {{v[0-9]+}}.2d, v1.2d, v0.2d
}

uint64x2_t test_vcleq_f64(float64x2_t v1, float64x2_t v2) {
  // CHECK: test_vcleq_f64
  return vcleq_f64(v1, v2);
  // CHECK: fcmge {{v[0-9]+}}.2d, v1.2d, v0.2d
}


uint8x8_t test_vcgt_s8(int8x8_t v1, int8x8_t v2) {
  // CHECK: test_vcgt_s8
  return vcgt_s8(v1, v2);
  // CHECK: cmgt {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vcgt_s16(int16x4_t v1, int16x4_t v2) {
  // CHECK: test_vcgt_s16
  return vcgt_s16(v1, v2);
  // CHECK: cmgt {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

uint32x2_t test_vcgt_s32(int32x2_t v1, int32x2_t v2) {
  // CHECK: test_vcgt_s32
  return vcgt_s32(v1, v2);
  // CHECK: cmgt {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint32x2_t test_vcgt_f32(float32x2_t v1, float32x2_t v2) {
  // CHECK: test_vcgt_f32
  return vcgt_f32(v1, v2);
  // CHECK: fcmgt {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint8x8_t test_vcgt_u8(uint8x8_t v1, uint8x8_t v2) {
  // CHECK: test_vcgt_u8
  return vcgt_u8(v1, v2);
  // CHECK: cmhi {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vcgt_u16(uint16x4_t v1, uint16x4_t v2) {
  // CHECK: test_vcgt_u16
  return vcgt_u16(v1, v2);
  // CHECK: cmhi {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

uint32x2_t test_vcgt_u32(uint32x2_t v1, uint32x2_t v2) {
  // CHECK: test_vcgt_u32
  return vcgt_u32(v1, v2);
  // CHECK: cmhi {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint8x16_t test_vcgtq_s8(int8x16_t v1, int8x16_t v2) {
  // CHECK: test_vcgtq_s8
  return vcgtq_s8(v1, v2);
  // CHECK: cmgt {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vcgtq_s16(int16x8_t v1, int16x8_t v2) {
  // CHECK: test_vcgtq_s16
  return vcgtq_s16(v1, v2);
  // CHECK: cmgt {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

uint32x4_t test_vcgtq_s32(int32x4_t v1, int32x4_t v2) {
  // CHECK: test_vcgtq_s32
  return vcgtq_s32(v1, v2);
  // CHECK: cmgt {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint32x4_t test_vcgtq_f32(float32x4_t v1, float32x4_t v2) {
  // CHECK: test_vcgtq_f32
  return vcgtq_f32(v1, v2);
  // CHECK: fcmgt {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint8x16_t test_vcgtq_u8(uint8x16_t v1, uint8x16_t v2) {
  // CHECK: test_vcgtq_u8
  return vcgtq_u8(v1, v2);
  // CHECK: cmhi {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vcgtq_u16(uint16x8_t v1, uint16x8_t v2) {
  // CHECK: test_vcgtq_u16
  return vcgtq_u16(v1, v2);
  // CHECK: cmhi {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

uint32x4_t test_vcgtq_u32(uint32x4_t v1, uint32x4_t v2) {
  // CHECK: test_vcgtq_u32
  return vcgtq_u32(v1, v2);
  // CHECK: cmhi {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint64x2_t test_vcgtq_s64(int64x2_t v1, int64x2_t v2) {
  // CHECK: test_vcgtq_s64
  return vcgtq_s64(v1, v2);
  // CHECK: cmgt {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

uint64x2_t test_vcgtq_u64(uint64x2_t v1, uint64x2_t v2) {
  // CHECK: test_vcgtq_u64
  return vcgtq_u64(v1, v2);
  // CHECK: cmhi {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

uint64x2_t test_vcgtq_f64(float64x2_t v1, float64x2_t v2) {
  // CHECK: test_vcgtq_f64
  return vcgtq_f64(v1, v2);
  // CHECK: fcmgt {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}


// Notes about vclt:
// LT condition predicate implemented as GT, so check reversed operands.
// Using registers other than v0, v1 are possible, but would be odd.

uint8x8_t test_vclt_s8(int8x8_t v1, int8x8_t v2) {
  // CHECK: test_vclt_s8
  return vclt_s8(v1, v2);
  // CHECK: cmgt {{v[0-9]+}}.8b, v1.8b, v0.8b
}

uint16x4_t test_vclt_s16(int16x4_t v1, int16x4_t v2) {
  // CHECK: test_vclt_s16
  return vclt_s16(v1, v2);
  // CHECK: cmgt {{v[0-9]+}}.4h, v1.4h, v0.4h
}

uint32x2_t test_vclt_s32(int32x2_t v1, int32x2_t v2) {
  // CHECK: test_vclt_s32
  return vclt_s32(v1, v2);
  // CHECK: cmgt {{v[0-9]+}}.2s, v1.2s, v0.2s
}

uint32x2_t test_vclt_f32(float32x2_t v1, float32x2_t v2) {
  // CHECK: test_vclt_f32
  return vclt_f32(v1, v2);
  // CHECK: fcmgt {{v[0-9]+}}.2s, v1.2s, v0.2s
}

uint8x8_t test_vclt_u8(uint8x8_t v1, uint8x8_t v2) {
  // CHECK: test_vclt_u8
  return vclt_u8(v1, v2);
  // CHECK: cmhi {{v[0-9]+}}.8b, v1.8b, v0.8b
}

uint16x4_t test_vclt_u16(uint16x4_t v1, uint16x4_t v2) {
  // CHECK: test_vclt_u16
  return vclt_u16(v1, v2);
  // CHECK: cmhi {{v[0-9]+}}.4h, v1.4h, v0.4h
}

uint32x2_t test_vclt_u32(uint32x2_t v1, uint32x2_t v2) {
  // CHECK: test_vclt_u32
  return vclt_u32(v1, v2);
  // CHECK: cmhi {{v[0-9]+}}.2s, v1.2s, v0.2s
}

uint8x16_t test_vcltq_s8(int8x16_t v1, int8x16_t v2) {
  // CHECK: test_vcltq_s8
  return vcltq_s8(v1, v2);
  // CHECK: cmgt {{v[0-9]+}}.16b, v1.16b, v0.16b
}

uint16x8_t test_vcltq_s16(int16x8_t v1, int16x8_t v2) {
  // CHECK: test_vcltq_s16
  return vcltq_s16(v1, v2);
  // CHECK: cmgt {{v[0-9]+}}.8h, v1.8h, v0.8h
}

uint32x4_t test_vcltq_s32(int32x4_t v1, int32x4_t v2) {
  // CHECK: test_vcltq_s32
  return vcltq_s32(v1, v2);
  // CHECK: cmgt {{v[0-9]+}}.4s, v1.4s, v0.4s
}

uint32x4_t test_vcltq_f32(float32x4_t v1, float32x4_t v2) {
  // CHECK: test_vcltq_f32
  return vcltq_f32(v1, v2);
  // CHECK: fcmgt {{v[0-9]+}}.4s, v1.4s, v0.4s
}

uint8x16_t test_vcltq_u8(uint8x16_t v1, uint8x16_t v2) {
  // CHECK: test_vcltq_u8
  return vcltq_u8(v1, v2);
  // CHECK: cmhi {{v[0-9]+}}.16b, v1.16b, v0.16b
}

uint16x8_t test_vcltq_u16(uint16x8_t v1, uint16x8_t v2) {
  // CHECK: test_vcltq_u16
  return vcltq_u16(v1, v2);
  // CHECK: cmhi {{v[0-9]+}}.8h, v1.8h, v0.8h
}

uint32x4_t test_vcltq_u32(uint32x4_t v1, uint32x4_t v2) {
  // CHECK: test_vcltq_u32
  return vcltq_u32(v1, v2);
  // CHECK: cmhi {{v[0-9]+}}.4s, v1.4s, v0.4s
}

uint64x2_t test_vcltq_s64(int64x2_t v1, int64x2_t v2) {
  // CHECK: test_vcltq_s64
  return vcltq_s64(v1, v2);
  // CHECK: cmgt {{v[0-9]+}}.2d, v1.2d, v0.2d
}

uint64x2_t test_vcltq_u64(uint64x2_t v1, uint64x2_t v2) {
  // CHECK: test_vcltq_u64
  return vcltq_u64(v1, v2);
  // CHECK: cmhi {{v[0-9]+}}.2d, v1.2d, v0.2d
}

uint64x2_t test_vcltq_f64(float64x2_t v1, float64x2_t v2) {
  // CHECK: test_vcltq_f64
  return vcltq_f64(v1, v2);
  // CHECK: fcmgt {{v[0-9]+}}.2d, v1.2d, v0.2d
}


int8x8_t test_vhadd_s8(int8x8_t v1, int8x8_t v2) {
// CHECK: test_vhadd_s8
  return vhadd_s8(v1, v2);
  // CHECK: shadd {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

int16x4_t test_vhadd_s16(int16x4_t v1, int16x4_t v2) {
// CHECK: test_vhadd_s16
  return vhadd_s16(v1, v2);
  // CHECK: shadd {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

int32x2_t test_vhadd_s32(int32x2_t v1, int32x2_t v2) {
// CHECK: test_vhadd_s32
  return vhadd_s32(v1, v2);
  // CHECK: shadd {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint8x8_t test_vhadd_u8(uint8x8_t v1, uint8x8_t v2) {
// CHECK: test_vhadd_u8
  return vhadd_u8(v1, v2);
  // CHECK: uhadd {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vhadd_u16(uint16x4_t v1, uint16x4_t v2) {
// CHECK: test_vhadd_u16
  return vhadd_u16(v1, v2);
  // CHECK: uhadd {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

uint32x2_t test_vhadd_u32(uint32x2_t v1, uint32x2_t v2) {
// CHECK: test_vhadd_u32
  return vhadd_u32(v1, v2);
  // CHECK: uhadd {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

int8x16_t test_vhaddq_s8(int8x16_t v1, int8x16_t v2) {
// CHECK: test_vhaddq_s8
  return vhaddq_s8(v1, v2);
  // CHECK: shadd {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

int16x8_t test_vhaddq_s16(int16x8_t v1, int16x8_t v2) {
// CHECK: test_vhaddq_s16
  return vhaddq_s16(v1, v2);
  // CHECK: shadd {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

int32x4_t test_vhaddq_s32(int32x4_t v1, int32x4_t v2) {
// CHECK: test_vhaddq_s32
  return vhaddq_s32(v1, v2);
  // CHECK: shadd {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint8x16_t test_vhaddq_u8(uint8x16_t v1, uint8x16_t v2) {
// CHECK: test_vhaddq_u8
  return vhaddq_u8(v1, v2);
  // CHECK: uhadd {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vhaddq_u16(uint16x8_t v1, uint16x8_t v2) {
// CHECK: test_vhaddq_u16
  return vhaddq_u16(v1, v2);
  // CHECK: uhadd {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

uint32x4_t test_vhaddq_u32(uint32x4_t v1, uint32x4_t v2) {
// CHECK: test_vhaddq_u32
  return vhaddq_u32(v1, v2);
  // CHECK: uhadd {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}


int8x8_t test_vhsub_s8(int8x8_t v1, int8x8_t v2) {
// CHECK: test_vhsub_s8
  return vhsub_s8(v1, v2);
  // CHECK: shsub {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

int16x4_t test_vhsub_s16(int16x4_t v1, int16x4_t v2) {
// CHECK: test_vhsub_s16
  return vhsub_s16(v1, v2);
  // CHECK: shsub {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

int32x2_t test_vhsub_s32(int32x2_t v1, int32x2_t v2) {
// CHECK: test_vhsub_s32
  return vhsub_s32(v1, v2);
  // CHECK: shsub {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint8x8_t test_vhsub_u8(uint8x8_t v1, uint8x8_t v2) {
// CHECK: test_vhsub_u8
  return vhsub_u8(v1, v2);
  // CHECK: uhsub {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vhsub_u16(uint16x4_t v1, uint16x4_t v2) {
// CHECK: test_vhsub_u16
  return vhsub_u16(v1, v2);
  // CHECK: uhsub {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

uint32x2_t test_vhsub_u32(uint32x2_t v1, uint32x2_t v2) {
// CHECK: test_vhsub_u32
  return vhsub_u32(v1, v2);
  // CHECK: uhsub {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

int8x16_t test_vhsubq_s8(int8x16_t v1, int8x16_t v2) {
// CHECK: test_vhsubq_s8
  return vhsubq_s8(v1, v2);
  // CHECK: shsub {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

int16x8_t test_vhsubq_s16(int16x8_t v1, int16x8_t v2) {
// CHECK: test_vhsubq_s16
  return vhsubq_s16(v1, v2);
  // CHECK: shsub {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

int32x4_t test_vhsubq_s32(int32x4_t v1, int32x4_t v2) {
// CHECK: test_vhsubq_s32
  return vhsubq_s32(v1, v2);
  // CHECK: shsub {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint8x16_t test_vhsubq_u8(uint8x16_t v1, uint8x16_t v2) {
// CHECK: test_vhsubq_u8
  return vhsubq_u8(v1, v2);
  // CHECK: uhsub {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vhsubq_u16(uint16x8_t v1, uint16x8_t v2) {
// CHECK: test_vhsubq_u16
  return vhsubq_u16(v1, v2);
  // CHECK: uhsub {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

uint32x4_t test_vhsubq_u32(uint32x4_t v1, uint32x4_t v2) {
// CHECK: test_vhsubq_u32
  return vhsubq_u32(v1, v2);
  // CHECK: uhsub {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}


int8x8_t test_vrhadd_s8(int8x8_t v1, int8x8_t v2) {
// CHECK: test_vrhadd_s8
  return vrhadd_s8(v1, v2);
// CHECK: srhadd {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

int16x4_t test_vrhadd_s16(int16x4_t v1, int16x4_t v2) {
// CHECK: test_vrhadd_s16
  return vrhadd_s16(v1, v2);
// CHECK: srhadd {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

int32x2_t test_vrhadd_s32(int32x2_t v1, int32x2_t v2) {
// CHECK: test_vrhadd_s32
  return vrhadd_s32(v1, v2);
// CHECK: srhadd {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint8x8_t test_vrhadd_u8(uint8x8_t v1, uint8x8_t v2) {
// CHECK: test_vrhadd_u8
  return vrhadd_u8(v1, v2);
// CHECK: urhadd {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vrhadd_u16(uint16x4_t v1, uint16x4_t v2) {
// CHECK: test_vrhadd_u16
  return vrhadd_u16(v1, v2);
// CHECK: urhadd {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

uint32x2_t test_vrhadd_u32(uint32x2_t v1, uint32x2_t v2) {
// CHECK: test_vrhadd_u32
  return vrhadd_u32(v1, v2);
// CHECK: urhadd {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

int8x16_t test_vrhaddq_s8(int8x16_t v1, int8x16_t v2) {
// CHECK: test_vrhaddq_s8
  return vrhaddq_s8(v1, v2);
// CHECK: srhadd {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

int16x8_t test_vrhaddq_s16(int16x8_t v1, int16x8_t v2) {
// CHECK: test_vrhaddq_s16
  return vrhaddq_s16(v1, v2);
// CHECK: srhadd {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

int32x4_t test_vrhaddq_s32(int32x4_t v1, int32x4_t v2) {
// CHECK: test_vrhaddq_s32
  return vrhaddq_s32(v1, v2);
// CHECK: srhadd {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint8x16_t test_vrhaddq_u8(uint8x16_t v1, uint8x16_t v2) {
// CHECK: test_vrhaddq_u8
  return vrhaddq_u8(v1, v2);
// CHECK: urhadd {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vrhaddq_u16(uint16x8_t v1, uint16x8_t v2) {
// CHECK: test_vrhaddq_u16
  return vrhaddq_u16(v1, v2);
// CHECK: urhadd {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

uint32x4_t test_vrhaddq_u32(uint32x4_t v1, uint32x4_t v2) {
// CHECK: test_vrhaddq_u32
  return vrhaddq_u32(v1, v2);
// CHECK: urhadd {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}
int8x8_t test_vqadd_s8(int8x8_t a, int8x8_t b) {
// CHECK: test_vqadd_s8
  return vqadd_s8(a, b);
  // CHECK: sqadd {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

int16x4_t test_vqadd_s16(int16x4_t a, int16x4_t b) {
// CHECK: test_vqadd_s16
  return vqadd_s16(a, b);
  // CHECK: sqadd {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

int32x2_t test_vqadd_s32(int32x2_t a, int32x2_t b) {
// CHECK: test_vqadd_s32
  return vqadd_s32(a, b);
  // CHECK: sqadd {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

int64x1_t test_vqadd_s64(int64x1_t a, int64x1_t b) {
// CHECK: test_vqadd_s64
  return vqadd_s64(a, b);
// CHECK:  sqadd {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

uint8x8_t test_vqadd_u8(uint8x8_t a, uint8x8_t b) {
// CHECK: test_vqadd_u8
  return vqadd_u8(a, b);
  // CHECK: uqadd {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vqadd_u16(uint16x4_t a, uint16x4_t b) {
// CHECK: test_vqadd_u16
  return vqadd_u16(a, b);
  // CHECK: uqadd {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

uint32x2_t test_vqadd_u32(uint32x2_t a, uint32x2_t b) {
// CHECK: test_vqadd_u32
  return vqadd_u32(a, b);
  // CHECK: uqadd {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint64x1_t test_vqadd_u64(uint64x1_t a, uint64x1_t b) {
// CHECK:  test_vqadd_u64
  return vqadd_u64(a, b);
// CHECK:  uqadd {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

int8x16_t test_vqaddq_s8(int8x16_t a, int8x16_t b) {
// CHECK: test_vqaddq_s8
  return vqaddq_s8(a, b);
  // CHECK: sqadd {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

int16x8_t test_vqaddq_s16(int16x8_t a, int16x8_t b) {
// CHECK: test_vqaddq_s16
  return vqaddq_s16(a, b);
  // CHECK: sqadd {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

int32x4_t test_vqaddq_s32(int32x4_t a, int32x4_t b) {
// CHECK: test_vqaddq_s32
  return vqaddq_s32(a, b);
  // CHECK: sqadd {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

int64x2_t test_vqaddq_s64(int64x2_t a, int64x2_t b) {
// CHECK: test_vqaddq_s64
  return vqaddq_s64(a, b);
// CHECK: sqadd {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

uint8x16_t test_vqaddq_u8(uint8x16_t a, uint8x16_t b) {
// CHECK: test_vqaddq_u8
  return vqaddq_u8(a, b);
  // CHECK: uqadd {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vqaddq_u16(uint16x8_t a, uint16x8_t b) {
// CHECK: test_vqaddq_u16
  return vqaddq_u16(a, b);
  // CHECK: uqadd {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

uint32x4_t test_vqaddq_u32(uint32x4_t a, uint32x4_t b) {
// CHECK: test_vqaddq_u32
  return vqaddq_u32(a, b);
  // CHECK: uqadd {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint64x2_t test_vqaddq_u64(uint64x2_t a, uint64x2_t b) {
// CHECK: test_vqaddq_u64
  return vqaddq_u64(a, b);
// CHECK: uqadd {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}


int8x8_t test_vqsub_s8(int8x8_t a, int8x8_t b) {
// CHECK: test_vqsub_s8
  return vqsub_s8(a, b);
  // CHECK: sqsub {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

int16x4_t test_vqsub_s16(int16x4_t a, int16x4_t b) {
// CHECK: test_vqsub_s16
  return vqsub_s16(a, b);
  // CHECK: sqsub {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

int32x2_t test_vqsub_s32(int32x2_t a, int32x2_t b) {
// CHECK: test_vqsub_s32
  return vqsub_s32(a, b);
  // CHECK: sqsub {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

int64x1_t test_vqsub_s64(int64x1_t a, int64x1_t b) {
// CHECK: test_vqsub_s64
  return vqsub_s64(a, b);
// CHECK: sqsub {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

uint8x8_t test_vqsub_u8(uint8x8_t a, uint8x8_t b) {
// CHECK: test_vqsub_u8
  return vqsub_u8(a, b);
  // CHECK: uqsub {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vqsub_u16(uint16x4_t a, uint16x4_t b) {
// CHECK: test_vqsub_u16
  return vqsub_u16(a, b);
  // CHECK: uqsub {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

uint32x2_t test_vqsub_u32(uint32x2_t a, uint32x2_t b) {
// CHECK: test_vqsub_u32
  return vqsub_u32(a, b);
  // CHECK: uqsub {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint64x1_t test_vqsub_u64(uint64x1_t a, uint64x1_t b) {
// CHECK: test_vqsub_u64
  return vqsub_u64(a, b);
// CHECK:  uqsub {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

int8x16_t test_vqsubq_s8(int8x16_t a, int8x16_t b) {
// CHECK: test_vqsubq_s8
  return vqsubq_s8(a, b);
  // CHECK: sqsub {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

int16x8_t test_vqsubq_s16(int16x8_t a, int16x8_t b) {
// CHECK: test_vqsubq_s16
  return vqsubq_s16(a, b);
  // CHECK: sqsub {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

int32x4_t test_vqsubq_s32(int32x4_t a, int32x4_t b) {
// CHECK: test_vqsubq_s32
  return vqsubq_s32(a, b);
  // CHECK: sqsub {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

int64x2_t test_vqsubq_s64(int64x2_t a, int64x2_t b) {
// CHECK: test_vqsubq_s64
  return vqsubq_s64(a, b);
// CHECK: sqsub {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

uint8x16_t test_vqsubq_u8(uint8x16_t a, uint8x16_t b) {
// CHECK: test_vqsubq_u8
  return vqsubq_u8(a, b);
  // CHECK: uqsub {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vqsubq_u16(uint16x8_t a, uint16x8_t b) {
// CHECK: test_vqsubq_u16
  return vqsubq_u16(a, b);
  // CHECK: uqsub {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

uint32x4_t test_vqsubq_u32(uint32x4_t a, uint32x4_t b) {
// CHECK: test_vqsubq_u32
  return vqsubq_u32(a, b);
  // CHECK: uqsub {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint64x2_t test_vqsubq_u64(uint64x2_t a, uint64x2_t b) {
// CHECK: test_vqsubq_u64
  return vqsubq_u64(a, b);
  // CHECK: uqsub {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}


int8x8_t test_vshl_s8(int8x8_t a, int8x8_t b) {
// CHECK: test_vshl_s8
  return vshl_s8(a, b);
// CHECK: sshl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

int16x4_t test_vshl_s16(int16x4_t a, int16x4_t b) {
// CHECK: test_vshl_s16
  return vshl_s16(a, b);
// CHECK: sshl {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

int32x2_t test_vshl_s32(int32x2_t a, int32x2_t b) {
// CHECK: test_vshl_s32
  return vshl_s32(a, b);
// CHECK: sshl {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

int64x1_t test_vshl_s64(int64x1_t a, int64x1_t b) {
// CHECK: test_vshl_s64
  return vshl_s64(a, b);
// CHECK: sshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

uint8x8_t test_vshl_u8(uint8x8_t a, int8x8_t b) {
// CHECK: test_vshl_u8
  return vshl_u8(a, b);
// CHECK: ushl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vshl_u16(uint16x4_t a, int16x4_t b) {
// CHECK: test_vshl_u16
  return vshl_u16(a, b);
// CHECK: ushl {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

uint32x2_t test_vshl_u32(uint32x2_t a, int32x2_t b) {
// CHECK: test_vshl_u32
  return vshl_u32(a, b);
// CHECK: ushl {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint64x1_t test_vshl_u64(uint64x1_t a, int64x1_t b) {
// CHECK: test_vshl_u64
  return vshl_u64(a, b);
// CHECK: ushl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

int8x16_t test_vshlq_s8(int8x16_t a, int8x16_t b) {
// CHECK: test_vshlq_s8
  return vshlq_s8(a, b);
// CHECK: sshl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

int16x8_t test_vshlq_s16(int16x8_t a, int16x8_t b) {
// CHECK: test_vshlq_s16
  return vshlq_s16(a, b);
// CHECK: sshl {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

int32x4_t test_vshlq_s32(int32x4_t a, int32x4_t b) {
// CHECK: test_vshlq_s32
  return vshlq_s32(a, b);
// CHECK: sshl {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

int64x2_t test_vshlq_s64(int64x2_t a, int64x2_t b) {
// CHECK: test_vshlq_s64
  return vshlq_s64(a, b);
// CHECK: sshl {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

uint8x16_t test_vshlq_u8(uint8x16_t a, int8x16_t b) {
// CHECK: test_vshlq_u8
  return vshlq_u8(a, b);
// CHECK: ushl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vshlq_u16(uint16x8_t a, int16x8_t b) {
// CHECK: test_vshlq_u16
  return vshlq_u16(a, b);
// CHECK: ushl {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

uint32x4_t test_vshlq_u32(uint32x4_t a, int32x4_t b) {
// CHECK: test_vshlq_u32
  return vshlq_u32(a, b);
// CHECK: ushl {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint64x2_t test_vshlq_u64(uint64x2_t a, int64x2_t b) {
// CHECK: test_vshlq_u64
  return vshlq_u64(a, b);
// CHECK: ushl {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}


int8x8_t test_vqshl_s8(int8x8_t a, int8x8_t b) {
// CHECK: test_vqshl_s8
  return vqshl_s8(a, b);
// CHECK: sqshl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

int16x4_t test_vqshl_s16(int16x4_t a, int16x4_t b) {
// CHECK: test_vqshl_s16
  return vqshl_s16(a, b);
// CHECK: sqshl {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

int32x2_t test_vqshl_s32(int32x2_t a, int32x2_t b) {
// CHECK: test_vqshl_s32
  return vqshl_s32(a, b);
// CHECK: sqshl {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

int64x1_t test_vqshl_s64(int64x1_t a, int64x1_t b) {
// CHECK: test_vqshl_s64
  return vqshl_s64(a, b);
// CHECK: sqshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

uint8x8_t test_vqshl_u8(uint8x8_t a, int8x8_t b) {
// CHECK: test_vqshl_u8
  return vqshl_u8(a, b);
// CHECK: uqshl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vqshl_u16(uint16x4_t a, int16x4_t b) {
// CHECK: test_vqshl_u16
  return vqshl_u16(a, b);
// CHECK: uqshl {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

uint32x2_t test_vqshl_u32(uint32x2_t a, int32x2_t b) {
// CHECK: test_vqshl_u32
  return vqshl_u32(a, b);
// CHECK: uqshl {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint64x1_t test_vqshl_u64(uint64x1_t a, int64x1_t b) {
// CHECK: test_vqshl_u64
  return vqshl_u64(a, b);
// CHECK: uqshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

int8x16_t test_vqshlq_s8(int8x16_t a, int8x16_t b) {
// CHECK: test_vqshlq_s8
  return vqshlq_s8(a, b);
// CHECK: sqshl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

int16x8_t test_vqshlq_s16(int16x8_t a, int16x8_t b) {
// CHECK: test_vqshlq_s16
  return vqshlq_s16(a, b);
// CHECK: sqshl {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

int32x4_t test_vqshlq_s32(int32x4_t a, int32x4_t b) {
// CHECK: test_vqshlq_s32
  return vqshlq_s32(a, b);
// CHECK: sqshl {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

int64x2_t test_vqshlq_s64(int64x2_t a, int64x2_t b) {
// CHECK: test_vqshlq_s64
  return vqshlq_s64(a, b);
// CHECK: sqshl {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

uint8x16_t test_vqshlq_u8(uint8x16_t a, int8x16_t b) {
// CHECK: test_vqshlq_u8
  return vqshlq_u8(a, b);
// CHECK: uqshl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vqshlq_u16(uint16x8_t a, int16x8_t b) {
// CHECK: test_vqshlq_u16
  return vqshlq_u16(a, b);
// CHECK: uqshl {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

uint32x4_t test_vqshlq_u32(uint32x4_t a, int32x4_t b) {
// CHECK: test_vqshlq_u32
  return vqshlq_u32(a, b);
// CHECK: uqshl {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint64x2_t test_vqshlq_u64(uint64x2_t a, int64x2_t b) {
// CHECK: test_vqshlq_u32
  return vqshlq_u64(a, b);
// CHECK: uqshl {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

int8x8_t test_vrshl_s8(int8x8_t a, int8x8_t b) {
// CHECK: test_vrshl_s8
  return vrshl_s8(a, b);
// CHECK: srshl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

int16x4_t test_vrshl_s16(int16x4_t a, int16x4_t b) {
// CHECK: test_vrshl_s16
  return vrshl_s16(a, b);
// CHECK: srshl {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

int32x2_t test_vrshl_s32(int32x2_t a, int32x2_t b) {
// CHECK: test_vrshl_s32
  return vrshl_s32(a, b);
// CHECK: srshl {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

int64x1_t test_vrshl_s64(int64x1_t a, int64x1_t b) {
// CHECK: test_vrshl_s64
  return vrshl_s64(a, b);
// CHECK: srshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

uint8x8_t test_vrshl_u8(uint8x8_t a, int8x8_t b) {
// CHECK: test_vrshl_u8
  return vrshl_u8(a, b);
// CHECK: urshl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vrshl_u16(uint16x4_t a, int16x4_t b) {
// CHECK: test_vrshl_u16
  return vrshl_u16(a, b);
// CHECK: urshl {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

uint32x2_t test_vrshl_u32(uint32x2_t a, int32x2_t b) {
// CHECK: test_vrshl_u32
  return vrshl_u32(a, b);
// CHECK: urshl {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint64x1_t test_vrshl_u64(uint64x1_t a, int64x1_t b) {
// CHECK: test_vrshl_u64
  return vrshl_u64(a, b);
// CHECK: urshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

int8x16_t test_vrshlq_s8(int8x16_t a, int8x16_t b) {
// CHECK: test_vrshlq_s8
  return vrshlq_s8(a, b);
// CHECK: srshl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

int16x8_t test_vrshlq_s16(int16x8_t a, int16x8_t b) {
// CHECK: test_vrshlq_s16
  return vrshlq_s16(a, b);
// CHECK: srshl {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

int32x4_t test_vrshlq_s32(int32x4_t a, int32x4_t b) {
// CHECK: test_vrshlq_s32
  return vrshlq_s32(a, b);
// CHECK: srshl {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

int64x2_t test_vrshlq_s64(int64x2_t a, int64x2_t b) {
// CHECK: test_vrshlq_s64
  return vrshlq_s64(a, b);
// CHECK: srshl {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

uint8x16_t test_vrshlq_u8(uint8x16_t a, int8x16_t b) {
// CHECK: test_vrshlq_u8
  return vrshlq_u8(a, b);
// CHECK: urshl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vrshlq_u16(uint16x8_t a, int16x8_t b) {
// CHECK: test_vrshlq_u16
  return vrshlq_u16(a, b);
// CHECK: urshl {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

uint32x4_t test_vrshlq_u32(uint32x4_t a, int32x4_t b) {
// CHECK: test_vrshlq_u32
  return vrshlq_u32(a, b);
// CHECK: urshl {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint64x2_t test_vrshlq_u64(uint64x2_t a, int64x2_t b) {
// CHECK: test_vrshlq_u64
  return vrshlq_u64(a, b);
// CHECK: urshl {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}


int8x8_t test_vqrshl_s8(int8x8_t a, int8x8_t b) {
// CHECK: test_vqrshl_s8
  return vqrshl_s8(a, b);
// CHECK: sqrshl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

int16x4_t test_vqrshl_s16(int16x4_t a, int16x4_t b) {
// CHECK: test_vqrshl_s16
  return vqrshl_s16(a, b);
// CHECK: sqrshl {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

int32x2_t test_vqrshl_s32(int32x2_t a, int32x2_t b) {
// CHECK: test_vqrshl_s32
  return vqrshl_s32(a, b);
// CHECK: sqrshl {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

int64x1_t test_vqrshl_s64(int64x1_t a, int64x1_t b) {
// CHECK: test_vqrshl_s64
  return vqrshl_s64(a, b);
// CHECK: sqrshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

uint8x8_t test_vqrshl_u8(uint8x8_t a, int8x8_t b) {
// CHECK: test_vqrshl_u8
  return vqrshl_u8(a, b);
// CHECK: uqrshl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vqrshl_u16(uint16x4_t a, int16x4_t b) {
// CHECK: test_vqrshl_u16
  return vqrshl_u16(a, b);
// CHECK: uqrshl {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

uint32x2_t test_vqrshl_u32(uint32x2_t a, int32x2_t b) {
// CHECK: test_vqrshl_u32
  return vqrshl_u32(a, b);
// CHECK: uqrshl {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint64x1_t test_vqrshl_u64(uint64x1_t a, int64x1_t b) {
// CHECK: test_vqrshl_u64
  return vqrshl_u64(a, b);
// CHECK: uqrshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

int8x16_t test_vqrshlq_s8(int8x16_t a, int8x16_t b) {
// CHECK: test_vqrshlq_s8
  return vqrshlq_s8(a, b);
// CHECK: sqrshl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

int16x8_t test_vqrshlq_s16(int16x8_t a, int16x8_t b) {
// CHECK: test_vqrshlq_s16
  return vqrshlq_s16(a, b);
// CHECK: sqrshl {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

int32x4_t test_vqrshlq_s32(int32x4_t a, int32x4_t b) {
// CHECK: test_vqrshlq_s32
  return vqrshlq_s32(a, b);
// CHECK: sqrshl {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

int64x2_t test_vqrshlq_s64(int64x2_t a, int64x2_t b) {
// CHECK: test_vqrshlq_s64
  return vqrshlq_s64(a, b);
// CHECK: sqrshl {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

// CHECK: test_vqrshlq_u8
uint8x16_t test_vqrshlq_u8(uint8x16_t a, int8x16_t b) {
  return vqrshlq_u8(a, b);
// CHECK: uqrshl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vqrshlq_u16(uint16x8_t a, int16x8_t b) {
// CHECK: test_vqrshlq_u16
  return vqrshlq_u16(a, b);
// CHECK: uqrshl {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

uint32x4_t test_vqrshlq_u32(uint32x4_t a, int32x4_t b) {
// CHECK: test_vqrshlq_u32
  return vqrshlq_u32(a, b);
// CHECK: uqrshl {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint64x2_t test_vqrshlq_u64(uint64x2_t a, int64x2_t b) {
// CHECK: test_vqrshlq_u64
  return vqrshlq_u64(a, b);
// CHECK: uqrshl {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

int8x8_t test_vmax_s8(int8x8_t a, int8x8_t b) {
// CHECK: test_vmax_s8
  return vmax_s8(a, b);
// CHECK: smax {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

int16x4_t test_vmax_s16(int16x4_t a, int16x4_t b) {
// CHECK: test_vmax_s16
  return vmax_s16(a, b);
// CHECK: smax {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

int32x2_t test_vmax_s32(int32x2_t a, int32x2_t b) {
// CHECK: test_vmax_s32
  return vmax_s32(a, b);
// CHECK: smax {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint8x8_t test_vmax_u8(uint8x8_t a, uint8x8_t b) {
// CHECK: test_vmax_u8
  return vmax_u8(a, b);
// CHECK: umax {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vmax_u16(uint16x4_t a, uint16x4_t b) {
// CHECK: test_vmax_u16
  return vmax_u16(a, b);
// CHECK: umax {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

uint32x2_t test_vmax_u32(uint32x2_t a, uint32x2_t b) {
// CHECK: test_vmax_u32
  return vmax_u32(a, b);
// CHECK: umax {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

float32x2_t test_vmax_f32(float32x2_t a, float32x2_t b) {
// CHECK: test_vmax_f32
  return vmax_f32(a, b);
// CHECK: fmax {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

int8x16_t test_vmaxq_s8(int8x16_t a, int8x16_t b) {
// CHECK: test_vmaxq_s8
  return vmaxq_s8(a, b);
// CHECK: smax {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

int16x8_t test_vmaxq_s16(int16x8_t a, int16x8_t b) {
// CHECK: test_vmaxq_s16
  return vmaxq_s16(a, b);
// CHECK: smax {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

int32x4_t test_vmaxq_s32(int32x4_t a, int32x4_t b) {
// CHECK: test_vmaxq_s32
  return vmaxq_s32(a, b);
// CHECK: smax {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint8x16_t test_vmaxq_u8(uint8x16_t a, uint8x16_t b) {
// CHECK: test_vmaxq_u8
  return vmaxq_u8(a, b);
// CHECK: umax {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vmaxq_u16(uint16x8_t a, uint16x8_t b) {
// CHECK: test_vmaxq_u16
  return vmaxq_u16(a, b);
// CHECK: umax {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

uint32x4_t test_vmaxq_u32(uint32x4_t a, uint32x4_t b) {
// CHECK: test_vmaxq_u32
  return vmaxq_u32(a, b);
// CHECK: umax {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

float32x4_t test_vmaxq_f32(float32x4_t a, float32x4_t b) {
// CHECK: test_vmaxq_f32
  return vmaxq_f32(a, b);
// CHECK: fmax {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

float64x2_t test_vmaxq_f64(float64x2_t a, float64x2_t b) {
// CHECK: test_vmaxq_f64
  return vmaxq_f64(a, b);
// CHECK: fmax {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}


int8x8_t test_vmin_s8(int8x8_t a, int8x8_t b) {
// CHECK: test_vmin_s8
  return vmin_s8(a, b);
// CHECK: smin {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

int16x4_t test_vmin_s16(int16x4_t a, int16x4_t b) {
// CHECK: test_vmin_s16
  return vmin_s16(a, b);
// CHECK: smin {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

int32x2_t test_vmin_s32(int32x2_t a, int32x2_t b) {
// CHECK: test_vmin_s32
  return vmin_s32(a, b);
// CHECK: smin {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint8x8_t test_vmin_u8(uint8x8_t a, uint8x8_t b) {
// CHECK: test_vmin_u8
  return vmin_u8(a, b);
// CHECK: umin {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vmin_u16(uint16x4_t a, uint16x4_t b) {
// CHECK: test_vmin_u16
  return vmin_u16(a, b);
// CHECK: umin {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

uint32x2_t test_vmin_u32(uint32x2_t a, uint32x2_t b) {
// CHECK: test_vmin_u32
  return vmin_u32(a, b);
// CHECK: umin {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

float32x2_t test_vmin_f32(float32x2_t a, float32x2_t b) {
// CHECK: test_vmin_f32
  return vmin_f32(a, b);
// CHECK: fmin {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

int8x16_t test_vminq_s8(int8x16_t a, int8x16_t b) {
// CHECK: test_vminq_s8
  return vminq_s8(a, b);
// CHECK: smin {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

int16x8_t test_vminq_s16(int16x8_t a, int16x8_t b) {
// CHECK: test_vminq_s16
  return vminq_s16(a, b);
// CHECK: smin {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

int32x4_t test_vminq_s32(int32x4_t a, int32x4_t b) {
// CHECK: test_vminq_s32
  return vminq_s32(a, b);
// CHECK: smin {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint8x16_t test_vminq_u8(uint8x16_t a, uint8x16_t b) {
// CHECK: test_vminq_u8
  return vminq_u8(a, b);
// CHECK: umin {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vminq_u16(uint16x8_t a, uint16x8_t b) {
// CHECK: test_vminq_u16
  return vminq_u16(a, b);
// CHECK: umin {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

uint32x4_t test_vminq_u32(uint32x4_t a, uint32x4_t b) {
// CHECK: test_vminq_u32
  return vminq_u32(a, b);
// CHECK: umin {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

float32x4_t test_vminq_f32(float32x4_t a, float32x4_t b) {
// CHECK: test_vminq_f32
  return vminq_f32(a, b);
// CHECK: fmin {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

float64x2_t test_vminq_f64(float64x2_t a, float64x2_t b) {
// CHECK: test_vminq_f64
  return vminq_f64(a, b);
// CHECK: fmin {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

float32x2_t test_vmaxnm_f32(float32x2_t a, float32x2_t b) {
// CHECK: test_vmaxnm_f32
  return vmaxnm_f32(a, b);
// CHECK: fmaxnm {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

float32x4_t test_vmaxnmq_f32(float32x4_t a, float32x4_t b) {
// CHECK: test_vmaxnmq_f32
  return vmaxnmq_f32(a, b);
// CHECK: fmaxnm {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

float64x2_t test_vmaxnmq_f64(float64x2_t a, float64x2_t b) {
// CHECK: test_vmaxnmq_f64
  return vmaxnmq_f64(a, b);
// CHECK: fmaxnm {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

float32x2_t test_vminnm_f32(float32x2_t a, float32x2_t b) {
// CHECK: test_vminnm_f32
  return vminnm_f32(a, b);
// CHECK: fminnm {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

float32x4_t test_vminnmq_f32(float32x4_t a, float32x4_t b) {
// CHECK: test_vminnmq_f32
  return vminnmq_f32(a, b);
// CHECK: fminnm {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

float64x2_t test_vminnmq_f64(float64x2_t a, float64x2_t b) {
// CHECK: test_vminnmq_f64
  return vminnmq_f64(a, b);
// CHECK: fminnm {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

int8x8_t test_vpmax_s8(int8x8_t a, int8x8_t b) {
// CHECK: test_vpmax_s8
  return vpmax_s8(a, b);
// CHECK: smaxp {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

int16x4_t test_vpmax_s16(int16x4_t a, int16x4_t b) {
// CHECK: test_vpmax_s16
  return vpmax_s16(a, b);
// CHECK: smaxp {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

int32x2_t test_vpmax_s32(int32x2_t a, int32x2_t b) {
// CHECK: test_vpmax_s32
  return vpmax_s32(a, b);
// CHECK: smaxp {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint8x8_t test_vpmax_u8(uint8x8_t a, uint8x8_t b) {
// CHECK: test_vpmax_u8
  return vpmax_u8(a, b);
// CHECK: umaxp {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vpmax_u16(uint16x4_t a, uint16x4_t b) {
// CHECK: test_vpmax_u16
  return vpmax_u16(a, b);
// CHECK: umaxp {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

uint32x2_t test_vpmax_u32(uint32x2_t a, uint32x2_t b) {
// CHECK: test_vpmax_u32
  return vpmax_u32(a, b);
// CHECK: umaxp {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

float32x2_t test_vpmax_f32(float32x2_t a, float32x2_t b) {
// CHECK: test_vpmax_f32
  return vpmax_f32(a, b);
// CHECK: fmaxp {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

int8x16_t test_vpmaxq_s8(int8x16_t a, int8x16_t b) {
// CHECK: test_vpmaxq_s8
  return vpmaxq_s8(a, b);
// CHECK: smaxp {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

int16x8_t test_vpmaxq_s16(int16x8_t a, int16x8_t b) {
// CHECK: test_vpmaxq_s16
  return vpmaxq_s16(a, b);
// CHECK: smaxp {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

int32x4_t test_vpmaxq_s32(int32x4_t a, int32x4_t b) {
// CHECK: test_vpmaxq_s32
  return vpmaxq_s32(a, b);
// CHECK: smaxp {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint8x16_t test_vpmaxq_u8(uint8x16_t a, uint8x16_t b) {
// CHECK: test_vpmaxq_u8
  return vpmaxq_u8(a, b);
// CHECK: umaxp {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vpmaxq_u16(uint16x8_t a, uint16x8_t b) {
// CHECK: test_vpmaxq_u16
  return vpmaxq_u16(a, b);
// CHECK: umaxp {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

uint32x4_t test_vpmaxq_u32(uint32x4_t a, uint32x4_t b) {
// CHECK: test_vpmaxq_u32
  return vpmaxq_u32(a, b);
// CHECK: umaxp {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

float32x4_t test_vpmaxq_f32(float32x4_t a, float32x4_t b) {
// CHECK: test_vpmaxq_f32
  return vpmaxq_f32(a, b);
// CHECK: fmaxp {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

float64x2_t test_vpmaxq_f64(float64x2_t a, float64x2_t b) {
// CHECK: test_vpmaxq_f64
  return vpmaxq_f64(a, b);
// CHECK: fmaxp {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

int8x8_t test_vpmin_s8(int8x8_t a, int8x8_t b) {
// CHECK: test_vpmin_s8
  return vpmin_s8(a, b);
// CHECK: sminp {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

int16x4_t test_vpmin_s16(int16x4_t a, int16x4_t b) {
// CHECK: test_vpmin_s16
  return vpmin_s16(a, b);
// CHECK: sminp {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

int32x2_t test_vpmin_s32(int32x2_t a, int32x2_t b) {
// CHECK: test_vpmin_s32
  return vpmin_s32(a, b);
// CHECK: sminp {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint8x8_t test_vpmin_u8(uint8x8_t a, uint8x8_t b) {
// CHECK: test_vpmin_u8
  return vpmin_u8(a, b);
// CHECK: uminp {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vpmin_u16(uint16x4_t a, uint16x4_t b) {
// CHECK: test_vpmin_u16
  return vpmin_u16(a, b);
// CHECK: uminp {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

uint32x2_t test_vpmin_u32(uint32x2_t a, uint32x2_t b) {
// CHECK: test_vpmin_u32
  return vpmin_u32(a, b);
// CHECK: uminp {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

float32x2_t test_vpmin_f32(float32x2_t a, float32x2_t b) {
// CHECK: test_vpmin_f32
  return vpmin_f32(a, b);
// CHECK: fminp {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

int8x16_t test_vpminq_s8(int8x16_t a, int8x16_t b) {
// CHECK: test_vpminq_s8
  return vpminq_s8(a, b);
// CHECK: sminp {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

int16x8_t test_vpminq_s16(int16x8_t a, int16x8_t b) {
// CHECK: test_vpminq_s16
  return vpminq_s16(a, b);
// CHECK: sminp {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

int32x4_t test_vpminq_s32(int32x4_t a, int32x4_t b) {
// CHECK: test_vpminq_s32
  return vpminq_s32(a, b);
// CHECK: sminp {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint8x16_t test_vpminq_u8(uint8x16_t a, uint8x16_t b) {
// CHECK: test_vpminq_u8
  return vpminq_u8(a, b);
// CHECK: uminp {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vpminq_u16(uint16x8_t a, uint16x8_t b) {
// CHECK: test_vpminq_u16
  return vpminq_u16(a, b);
// CHECK: uminp {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

uint32x4_t test_vpminq_u32(uint32x4_t a, uint32x4_t b) {
// CHECK: test_vpminq_u32
  return vpminq_u32(a, b);
// CHECK: uminp {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

float32x4_t test_vpminq_f32(float32x4_t a, float32x4_t b) {
// CHECK: test_vpminq_f32
  return vpminq_f32(a, b);
// CHECK: fminp {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

float64x2_t test_vpminq_f64(float64x2_t a, float64x2_t b) {
// CHECK: test_vpminq_f64
  return vpminq_f64(a, b);
// CHECK: fminp {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

float32x2_t test_vpmaxnm_f32(float32x2_t a, float32x2_t b) {
// CHECK: test_vpmaxnm_f32
  return vpmaxnm_f32(a, b);
// CHECK: fmaxnmp {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

float32x4_t test_vpmaxnmq_f32(float32x4_t a, float32x4_t b) {
// CHECK: test_vpmaxnmq_f32
  return vpmaxnmq_f32(a, b);
// CHECK: fmaxnmp {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

float64x2_t test_vpmaxnmq_f64(float64x2_t a, float64x2_t b) {
// CHECK: test_vpmaxnmq_f64
  return vpmaxnmq_f64(a, b);
// CHECK: fmaxnmp {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

float32x2_t test_vpminnm_f32(float32x2_t a, float32x2_t b) {
// CHECK: test_vpminnm_f32
  return vpminnm_f32(a, b);
// CHECK: fminnmp {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

float32x4_t test_vpminnmq_f32(float32x4_t a, float32x4_t b) {
// CHECK: test_vpminnmq_f32
  return vpminnmq_f32(a, b);
// CHECK: fminnmp {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

float64x2_t test_vpminnmq_f64(float64x2_t a, float64x2_t b) {
// CHECK: test_vpminnmq_f64
  return vpminnmq_f64(a, b);
// CHECK: fminnmp {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

int8x8_t test_vpadd_s8(int8x8_t a, int8x8_t b) {
// CHECK: test_vpadd_s8
  return vpadd_s8(a, b);
// CHECK: addp {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

int16x4_t test_vpadd_s16(int16x4_t a, int16x4_t b) {
// CHECK: test_vpadd_s16
  return vpadd_s16(a, b);
// CHECK: addp {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

int32x2_t test_vpadd_s32(int32x2_t a, int32x2_t b) {
// CHECK: test_vpadd_s32
  return vpadd_s32(a, b);
// CHECK: addp {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

uint8x8_t test_vpadd_u8(uint8x8_t a, uint8x8_t b) {
// CHECK: test_vpadd_u8
  return vpadd_u8(a, b);
// CHECK: addp {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
}

uint16x4_t test_vpadd_u16(uint16x4_t a, uint16x4_t b) {
// CHECK: test_vpadd_u16
  return vpadd_u16(a, b);
// CHECK: addp {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

uint32x2_t test_vpadd_u32(uint32x2_t a, uint32x2_t b) {
// CHECK: test_vpadd_u32
  return vpadd_u32(a, b);
// CHECK: addp {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

float32x2_t test_vpadd_f32(float32x2_t a, float32x2_t b) {
// CHECK: test_vpadd_f32
  return vpadd_f32(a, b);
// CHECK: faddp {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

int8x16_t test_vpaddq_s8(int8x16_t a, int8x16_t b) {
// CHECK: test_vpaddq_s8
  return vpaddq_s8(a, b);
// CHECK: addp {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

int16x8_t test_vpaddq_s16(int16x8_t a, int16x8_t b) {
// CHECK: test_vpaddq_s16
  return vpaddq_s16(a, b);
// CHECK: addp {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

int32x4_t test_vpaddq_s32(int32x4_t a, int32x4_t b) {
// CHECK: test_vpaddq_s32
  return vpaddq_s32(a, b);
// CHECK: addp {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

uint8x16_t test_vpaddq_u8(uint8x16_t a, uint8x16_t b) {
// CHECK: test_vpaddq_u8
  return vpaddq_u8(a, b);
// CHECK: addp {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
}

uint16x8_t test_vpaddq_u16(uint16x8_t a, uint16x8_t b) {
// CHECK: test_vpaddq_u16
  return vpaddq_u16(a, b);
// CHECK: addp {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

uint32x4_t test_vpaddq_u32(uint32x4_t a, uint32x4_t b) {
// CHECK: test_vpaddq_u32
  return vpaddq_u32(a, b);
// CHECK: addp {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

float32x4_t test_vpaddq_f32(float32x4_t a, float32x4_t b) {
// CHECK: test_vpaddq_f32
  return vpaddq_f32(a, b);
// CHECK: faddp {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

float64x2_t test_vpaddq_f64(float64x2_t a, float64x2_t b) {
// CHECK: test_vpaddq_f64
  return vpaddq_f64(a, b);
// CHECK: faddp {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

int16x4_t test_vqdmulh_s16(int16x4_t a, int16x4_t b) {
// CHECK: test_vqdmulh_s16
  return vqdmulh_s16(a, b);
// CHECK: sqdmulh {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

int32x2_t test_vqdmulh_s32(int32x2_t a, int32x2_t b) {
// CHECK: test_vqdmulh_s32
  return vqdmulh_s32(a, b);
// CHECK: sqdmulh {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

int16x8_t test_vqdmulhq_s16(int16x8_t a, int16x8_t b) {
// CHECK: test_vqdmulhq_s16
  return vqdmulhq_s16(a, b);
// CHECK: sqdmulh {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

int32x4_t test_vqdmulhq_s32(int32x4_t a, int32x4_t b) {
// CHECK: test_vqdmulhq_s32
  return vqdmulhq_s32(a, b);
// CHECK: sqdmulh {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

int16x4_t test_vqrdmulh_s16(int16x4_t a, int16x4_t b) {
// CHECK: test_vqrdmulh_s16
  return vqrdmulh_s16(a, b);
// CHECK: sqrdmulh {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
}

int32x2_t test_vqrdmulh_s32(int32x2_t a, int32x2_t b) {
// CHECK: test_vqrdmulh_s32
  return vqrdmulh_s32(a, b);
// CHECK: sqrdmulh {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

int16x8_t test_vqrdmulhq_s16(int16x8_t a, int16x8_t b) {
// CHECK: test_vqrdmulhq_s16
  return vqrdmulhq_s16(a, b);
// CHECK: sqrdmulh {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
}

int32x4_t test_vqrdmulhq_s32(int32x4_t a, int32x4_t b) {
// CHECK: test_vqrdmulhq_s32
  return vqrdmulhq_s32(a, b);
// CHECK: sqrdmulh {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}


float32x2_t test_vmulx_f32(float32x2_t a, float32x2_t b) {
// CHECK: test_vmulx_f32
  return vmulx_f32(a, b);
// CHECK: fmulx {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
}

float32x4_t test_vmulxq_f32(float32x4_t a, float32x4_t b) {
// CHECK: test_vmulxq_f32
  return vmulxq_f32(a, b);
// CHECK: fmulx {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
}

float64x2_t test_vmulxq_f64(float64x2_t a, float64x2_t b) {
// CHECK: test_vmulxq_f64
  return vmulxq_f64(a, b);
// CHECK: fmulx {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
}

int8x8_t test_vshl_n_s8(int8x8_t a) {
// CHECK: test_vshl_n_s8
  return vshl_n_s8(a, 3);
// CHECK: shl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
}

int16x4_t test_vshl_n_s16(int16x4_t a) {
// CHECK: test_vshl_n_s16
  return vshl_n_s16(a, 3);
// CHECK: shl {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #3
}

int32x2_t test_vshl_n_s32(int32x2_t a) {
// CHECK: test_vshl_n_s32
  return vshl_n_s32(a, 3);
// CHECK: shl {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #3
}

int8x16_t test_vshlq_n_s8(int8x16_t a) {
// CHECK: test_vshlq_n_s8
  return vshlq_n_s8(a, 3);
// CHECK: shl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
}

int16x8_t test_vshlq_n_s16(int16x8_t a) {
// CHECK: test_vshlq_n_s16
  return vshlq_n_s16(a, 3);
// CHECK: shl {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #3
}

int32x4_t test_vshlq_n_s32(int32x4_t a) {
// CHECK: test_vshlq_n_s32
  return vshlq_n_s32(a, 3);
// CHECK: shl {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #3
}

int64x2_t test_vshlq_n_s64(int64x2_t a) {
// CHECK: test_vshlq_n_s64
  return vshlq_n_s64(a, 3);
// CHECK: shl {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #3
}

int8x8_t test_vshl_n_u8(int8x8_t a) {
// CHECK: test_vshl_n_u8
  return vshl_n_u8(a, 3);
// CHECK: shl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
}

int16x4_t test_vshl_n_u16(int16x4_t a) {
// CHECK: test_vshl_n_u16
  return vshl_n_u16(a, 3);
// CHECK: shl {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #3
}

int32x2_t test_vshl_n_u32(int32x2_t a) {
// CHECK: test_vshl_n_u32
  return vshl_n_u32(a, 3);
// CHECK: shl {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #3
}

int8x16_t test_vshlq_n_u8(int8x16_t a) {
// CHECK: test_vshlq_n_u8
  return vshlq_n_u8(a, 3);
// CHECK: shl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
}

int16x8_t test_vshlq_n_u16(int16x8_t a) {
// CHECK: test_vshlq_n_u16
  return vshlq_n_u16(a, 3);
// CHECK: shl {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #3
}

int32x4_t test_vshlq_n_u32(int32x4_t a) {
// CHECK: test_vshlq_n_u32
  return vshlq_n_u32(a, 3);
// CHECK: shl {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #3
}

int64x2_t test_vshlq_n_u64(int64x2_t a) {
// CHECK: test_vshlq_n_u64
  return vshlq_n_u64(a, 3);
// CHECK: shl {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #3
}

int8x8_t test_vshr_n_s8(int8x8_t a) {
  // CHECK: test_vshr_n_s8
  return vshr_n_s8(a, 3);
  // CHECK: sshr {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
}

int16x4_t test_vshr_n_s16(int16x4_t a) {
  // CHECK: test_vshr_n_s16
  return vshr_n_s16(a, 3);
  // CHECK: sshr {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #3
}

int32x2_t test_vshr_n_s32(int32x2_t a) {
  // CHECK: test_vshr_n_s32
  return vshr_n_s32(a, 3);
  // CHECK: sshr {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #3
}

int8x16_t test_vshrq_n_s8(int8x16_t a) {
  // CHECK: test_vshrq_n_s8
  return vshrq_n_s8(a, 3);
  // CHECK: sshr {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
}

int16x8_t test_vshrq_n_s16(int16x8_t a) {
  // CHECK: test_vshrq_n_s16
  return vshrq_n_s16(a, 3);
  // CHECK: sshr {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #3
}

int32x4_t test_vshrq_n_s32(int32x4_t a) {
  // CHECK: test_vshrq_n_s32
  return vshrq_n_s32(a, 3);
  // CHECK: sshr {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #3
}

int64x2_t test_vshrq_n_s64(int64x2_t a) {
  // CHECK: test_vshrq_n_s64
  return vshrq_n_s64(a, 3);
  // CHECK: sshr {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #3
}

int8x8_t test_vshr_n_u8(int8x8_t a) {
  // CHECK: test_vshr_n_u8
  return vshr_n_u8(a, 3);
  // CHECK: ushr {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
}

int16x4_t test_vshr_n_u16(int16x4_t a) {
  // CHECK: test_vshr_n_u16
  return vshr_n_u16(a, 3);
  // CHECK: ushr {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #3
}

int32x2_t test_vshr_n_u32(int32x2_t a) {
  // CHECK: test_vshr_n_u32
  return vshr_n_u32(a, 3);
  // CHECK: ushr {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #3
}

int8x16_t test_vshrq_n_u8(int8x16_t a) {
  // CHECK: test_vshrq_n_u8
  return vshrq_n_u8(a, 3);
  // CHECK: ushr {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
}

int16x8_t test_vshrq_n_u16(int16x8_t a) {
  // CHECK: test_vshrq_n_u16
  return vshrq_n_u16(a, 3);
  // CHECK: ushr {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #3
}

int32x4_t test_vshrq_n_u32(int32x4_t a) {
  // CHECK: test_vshrq_n_u32
  return vshrq_n_u32(a, 3);
  // CHECK: ushr {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #3
}

int64x2_t test_vshrq_n_u64(int64x2_t a) {
  // CHECK: test_vshrq_n_u64
  return vshrq_n_u64(a, 3);
  // CHECK: ushr {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #3
}

int8x8_t test_vsra_n_s8(int8x8_t a, int8x8_t b) {
  // CHECK: test_vsra_n_s8
  return vsra_n_s8(a, b, 3);
  // CHECK: ssra {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
}

int16x4_t test_vsra_n_s16(int16x4_t a, int16x4_t b) {
  // CHECK: test_vsra_n_s16
  return vsra_n_s16(a, b, 3);
  // CHECK: ssra {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #3
}

int32x2_t test_vsra_n_s32(int32x2_t a, int32x2_t b) {
  // CHECK: test_vsra_n_s32
  return vsra_n_s32(a, b, 3);
  // CHECK: ssra {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #3
}

int8x16_t test_vsraq_n_s8(int8x16_t a, int8x16_t b) {
  // CHECK: test_vsraq_n_s8
  return vsraq_n_s8(a, b, 3);
  // CHECK: ssra {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
}

int16x8_t test_vsraq_n_s16(int16x8_t a, int16x8_t b) {
  // CHECK: test_vsraq_n_s16
  return vsraq_n_s16(a, b, 3);
  // CHECK: ssra {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #3
}

int32x4_t test_vsraq_n_s32(int32x4_t a, int32x4_t b) {
  // CHECK: test_vsraq_n_s32
  return vsraq_n_s32(a, b, 3);
  // CHECK: ssra {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #3
}

int64x2_t test_vsraq_n_s64(int64x2_t a, int64x2_t b) {
  // CHECK: test_vsraq_n_s64
  return vsraq_n_s64(a, b, 3);
  // CHECK: ssra {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #3
}

int8x8_t test_vsra_n_u8(int8x8_t a, int8x8_t b) {
  // CHECK: test_vsra_n_u8
  return vsra_n_u8(a, b, 3);
  // CHECK: usra {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
}

int16x4_t test_vsra_n_u16(int16x4_t a, int16x4_t b) {
  // CHECK: test_vsra_n_u16
  return vsra_n_u16(a, b, 3);
  // CHECK: usra {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #3
}

int32x2_t test_vsra_n_u32(int32x2_t a, int32x2_t b) {
  // CHECK: test_vsra_n_u32
  return vsra_n_u32(a, b, 3);
  // CHECK: usra {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #3
}

int8x16_t test_vsraq_n_u8(int8x16_t a, int8x16_t b) {
  // CHECK: test_vsraq_n_u8
  return vsraq_n_u8(a, b, 3);
  // CHECK: usra {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
}

int16x8_t test_vsraq_n_u16(int16x8_t a, int16x8_t b) {
  // CHECK: test_vsraq_n_u16
  return vsraq_n_u16(a, b, 3);
  // CHECK: usra {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #3
}

int32x4_t test_vsraq_n_u32(int32x4_t a, int32x4_t b) {
  // CHECK: test_vsraq_n_u32
  return vsraq_n_u32(a, b, 3);
  // CHECK: usra {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #3
}

int64x2_t test_vsraq_n_u64(int64x2_t a, int64x2_t b) {
  // CHECK: test_vsraq_n_u64
  return vsraq_n_u64(a, b, 3);
  // CHECK: usra {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #3
}

int8x8_t test_vrshr_n_s8(int8x8_t a) {
  // CHECK: test_vrshr_n_s8
  return vrshr_n_s8(a, 3);
  // CHECK: srshr {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
}

int16x4_t test_vrshr_n_s16(int16x4_t a) {
  // CHECK: test_vrshr_n_s16
  return vrshr_n_s16(a, 3);
  // CHECK: srshr {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #3
}

int32x2_t test_vrshr_n_s32(int32x2_t a) {
  // CHECK: test_vrshr_n_s32
  return vrshr_n_s32(a, 3);
  // CHECK: srshr {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #3
}

int8x16_t test_vrshrq_n_s8(int8x16_t a) {
  // CHECK: test_vrshrq_n_s8
  return vrshrq_n_s8(a, 3);
  // CHECK: srshr {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
}

int16x8_t test_vrshrq_n_s16(int16x8_t a) {
  // CHECK: test_vrshrq_n_s16
  return vrshrq_n_s16(a, 3);
  // CHECK: srshr {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #3
}

int32x4_t test_vrshrq_n_s32(int32x4_t a) {
  // CHECK: test_vrshrq_n_s32
  return vrshrq_n_s32(a, 3);
  // CHECK: srshr {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #3
}

int64x2_t test_vrshrq_n_s64(int64x2_t a) {
  // CHECK: test_vrshrq_n_s64
  return vrshrq_n_s64(a, 3);
  // CHECK: srshr {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #3
}

int8x8_t test_vrshr_n_u8(int8x8_t a) {
  // CHECK: test_vrshr_n_u8
  return vrshr_n_u8(a, 3);
  // CHECK: urshr {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
}

int16x4_t test_vrshr_n_u16(int16x4_t a) {
  // CHECK: test_vrshr_n_u16
  return vrshr_n_u16(a, 3);
  // CHECK: urshr {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #3
}

int32x2_t test_vrshr_n_u32(int32x2_t a) {
  // CHECK: test_vrshr_n_u32
  return vrshr_n_u32(a, 3);
  // CHECK: urshr {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #3
}

int8x16_t test_vrshrq_n_u8(int8x16_t a) {
  // CHECK: test_vrshrq_n_u8
  return vrshrq_n_u8(a, 3);
  // CHECK: urshr {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
}

int16x8_t test_vrshrq_n_u16(int16x8_t a) {
  // CHECK: test_vrshrq_n_u16
  return vrshrq_n_u16(a, 3);
  // CHECK: urshr {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #3
}

int32x4_t test_vrshrq_n_u32(int32x4_t a) {
  // CHECK: test_vrshrq_n_u32
  return vrshrq_n_u32(a, 3);
  // CHECK: urshr {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #3
}

int64x2_t test_vrshrq_n_u64(int64x2_t a) {
  // CHECK: test_vrshrq_n_u64
  return vrshrq_n_u64(a, 3);
  // CHECK: urshr {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #3
}

int8x8_t test_vrsra_n_s8(int8x8_t a, int8x8_t b) {
  // CHECK: test_vrsra_n_s8
  return vrsra_n_s8(a, b, 3);
  // CHECK: srsra {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
}

int16x4_t test_vrsra_n_s16(int16x4_t a, int16x4_t b) {
  // CHECK: test_vrsra_n_s16
  return vrsra_n_s16(a, b, 3);
  // CHECK: srsra {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #3
}

int32x2_t test_vrsra_n_s32(int32x2_t a, int32x2_t b) {
  // CHECK: test_vrsra_n_s32
  return vrsra_n_s32(a, b, 3);
  // CHECK: srsra {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #3
}

int8x16_t test_vrsraq_n_s8(int8x16_t a, int8x16_t b) {
  // CHECK: test_vrsraq_n_s8
  return vrsraq_n_s8(a, b, 3);
  // CHECK: srsra {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
}

int16x8_t test_vrsraq_n_s16(int16x8_t a, int16x8_t b) {
  // CHECK: test_vrsraq_n_s16
  return vrsraq_n_s16(a, b, 3);
  // CHECK: srsra {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #3
}

int32x4_t test_vrsraq_n_s32(int32x4_t a, int32x4_t b) {
  // CHECK: test_vrsraq_n_s32
  return vrsraq_n_s32(a, b, 3);
  // CHECK: srsra {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #3
}

int64x2_t test_vrsraq_n_s64(int64x2_t a, int64x2_t b) {
  // CHECK: test_vrsraq_n_s64
  return vrsraq_n_s64(a, b, 3);
  // CHECK: srsra {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #3
}

int8x8_t test_vrsra_n_u8(int8x8_t a, int8x8_t b) {
  // CHECK: test_vrsra_n_u8
  return vrsra_n_u8(a, b, 3);
  // CHECK: ursra {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
}

int16x4_t test_vrsra_n_u16(int16x4_t a, int16x4_t b) {
  // CHECK: test_vrsra_n_u16
  return vrsra_n_u16(a, b, 3);
  // CHECK: ursra {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #3
}

int32x2_t test_vrsra_n_u32(int32x2_t a, int32x2_t b) {
  // CHECK: test_vrsra_n_u32
  return vrsra_n_u32(a, b, 3);
  // CHECK: ursra {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #3
}

int8x16_t test_vrsraq_n_u8(int8x16_t a, int8x16_t b) {
  // CHECK: test_vrsraq_n_u8
  return vrsraq_n_u8(a, b, 3);
  // CHECK: ursra {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
}

int16x8_t test_vrsraq_n_u16(int16x8_t a, int16x8_t b) {
  // CHECK: test_vrsraq_n_u16
  return vrsraq_n_u16(a, b, 3);
  // CHECK: ursra {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #3
}

int32x4_t test_vrsraq_n_u32(int32x4_t a, int32x4_t b) {
  // CHECK: test_vrsraq_n_u32
  return vrsraq_n_u32(a, b, 3);
  // CHECK: ursra {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #3
}

int64x2_t test_vrsraq_n_u64(int64x2_t a, int64x2_t b) {
  // CHECK: test_vrsraq_n_u64
  return vrsraq_n_u64(a, b, 3);
  // CHECK: ursra {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #3
}

int8x8_t test_vsri_n_s8(int8x8_t a, int8x8_t b) {
  // CHECK: test_vsri_n_s8
  return vsri_n_s8(a, b, 3);
  // CHECK: sri {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
}

int16x4_t test_vsri_n_s16(int16x4_t a, int16x4_t b) {
  // CHECK: test_vsri_n_s16
  return vsri_n_s16(a, b, 3);
  // CHECK: sri {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #3
}

int32x2_t test_vsri_n_s32(int32x2_t a, int32x2_t b) {
  // CHECK: test_vsri_n_s32
  return vsri_n_s32(a, b, 3);
  // CHECK: sri {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #3
}

int8x16_t test_vsriq_n_s8(int8x16_t a, int8x16_t b) {
  // CHECK: test_vsriq_n_s8
  return vsriq_n_s8(a, b, 3);
  // CHECK: sri {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
}

int16x8_t test_vsriq_n_s16(int16x8_t a, int16x8_t b) {
  // CHECK: test_vsriq_n_s16
  return vsriq_n_s16(a, b, 3);
  // CHECK: sri {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #3
}

int32x4_t test_vsriq_n_s32(int32x4_t a, int32x4_t b) {
  // CHECK: test_vsriq_n_s32
  return vsriq_n_s32(a, b, 3);
  // CHECK: sri {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #3
}

int64x2_t test_vsriq_n_s64(int64x2_t a, int64x2_t b) {
  // CHECK: test_vsriq_n_s64
  return vsriq_n_s64(a, b, 3);
  // CHECK: sri {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #3
}

int8x8_t test_vsri_n_u8(int8x8_t a, int8x8_t b) {
  // CHECK: test_vsri_n_u8
  return vsri_n_u8(a, b, 3);
  // CHECK: sri {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
}

int16x4_t test_vsri_n_u16(int16x4_t a, int16x4_t b) {
  // CHECK: test_vsri_n_u16
  return vsri_n_u16(a, b, 3);
  // CHECK: sri {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #3
}

int32x2_t test_vsri_n_u32(int32x2_t a, int32x2_t b) {
  // CHECK: test_vsri_n_u32
  return vsri_n_u32(a, b, 3);
  // CHECK: sri {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #3
}

int8x16_t test_vsriq_n_u8(int8x16_t a, int8x16_t b) {
  // CHECK: test_vsriq_n_u8
  return vsriq_n_u8(a, b, 3);
  // CHECK: sri {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
}

int16x8_t test_vsriq_n_u16(int16x8_t a, int16x8_t b) {
  // CHECK: test_vsriq_n_u16
  return vsriq_n_u16(a, b, 3);
  // CHECK: sri {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #3
}

int32x4_t test_vsriq_n_u32(int32x4_t a, int32x4_t b) {
  // CHECK: test_vsriq_n_u32
  return vsriq_n_u32(a, b, 3);
  // CHECK: sri {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #3
}

int64x2_t test_vsriq_n_u64(int64x2_t a, int64x2_t b) {
  // CHECK: test_vsriq_n_u64
  return vsriq_n_u64(a, b, 3);
  // CHECK: sri {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #3
}

poly8x8_t test_vsri_n_p8(poly8x8_t a, poly8x8_t b) {
  // CHECK: test_vsri_n_p8
  return vsri_n_p8(a, b, 3);
  // CHECK: sri {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
}

poly16x4_t test_vsri_n_p16(poly16x4_t a, poly16x4_t b) {
  // CHECK: test_vsri_n_p16
  return vsri_n_p16(a, b, 15);
  // CHECK: sri {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #15
}

poly8x16_t test_vsriq_n_p8(poly8x16_t a, poly8x16_t b) {
  // CHECK: test_vsriq_n_p8
  return vsriq_n_p8(a, b, 3);
  // CHECK: sri {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
}

poly16x8_t test_vsriq_n_p16(poly16x8_t a, poly16x8_t b) {
  // CHECK: test_vsriq_n_p16
  return vsriq_n_p16(a, b, 15);
  // CHECK: sri {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #15
}

int8x8_t test_vsli_n_s8(int8x8_t a, int8x8_t b) {
  // CHECK: test_vsli_n_s8
  return vsli_n_s8(a, b, 3);
  // CHECK: sli {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
}

int16x4_t test_vsli_n_s16(int16x4_t a, int16x4_t b) {
  // CHECK: test_vsli_n_s16
  return vsli_n_s16(a, b, 3);
  // CHECK: sli {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #3
}

int32x2_t test_vsli_n_s32(int32x2_t a, int32x2_t b) {
  // CHECK: test_vsli_n_s32
  return vsli_n_s32(a, b, 3);
  // CHECK: sli {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #3
}

int8x16_t test_vsliq_n_s8(int8x16_t a, int8x16_t b) {
  // CHECK: test_vsliq_n_s8
  return vsliq_n_s8(a, b, 3);
  // CHECK: sli {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
}

int16x8_t test_vsliq_n_s16(int16x8_t a, int16x8_t b) {
  // CHECK: test_vsliq_n_s16
  return vsliq_n_s16(a, b, 3);
  // CHECK: sli {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #3
}

int32x4_t test_vsliq_n_s32(int32x4_t a, int32x4_t b) {
  // CHECK: test_vsliq_n_s32
  return vsliq_n_s32(a, b, 3);
  // CHECK: sli {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #3
}

int64x2_t test_vsliq_n_s64(int64x2_t a, int64x2_t b) {
  // CHECK: test_vsliq_n_s64
  return vsliq_n_s64(a, b, 3);
  // CHECK: sli {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #3
}

uint8x8_t test_vsli_n_u8(uint8x8_t a, uint8x8_t b) {
  // CHECK: test_vsli_n_u8
  return vsli_n_u8(a, b, 3);
  // CHECK: sli {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
}

uint16x4_t test_vsli_n_u16(uint16x4_t a, uint16x4_t b) {
  // CHECK: test_vsli_n_u16
  return vsli_n_u16(a, b, 3);
  // CHECK: sli {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #3
}

uint32x2_t test_vsli_n_u32(uint32x2_t a, uint32x2_t b) {
  // CHECK: test_vsli_n_u32
  return vsli_n_u32(a, b, 3);
  // CHECK: sli {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #3
}

uint8x16_t test_vsliq_n_u8(uint8x16_t a, uint8x16_t b) {
  // CHECK: test_vsliq_n_u8
  return vsliq_n_u8(a, b, 3);
  // CHECK: sli {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
}

uint16x8_t test_vsliq_n_u16(uint16x8_t a, uint16x8_t b) {
  // CHECK: test_vsliq_n_u16
  return vsliq_n_u16(a, b, 3);
  // CHECK: sli {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #3
}

uint32x4_t test_vsliq_n_u32(uint32x4_t a, uint32x4_t b) {
  // CHECK: test_vsliq_n_u32
  return vsliq_n_u32(a, b, 3);
  // CHECK: sli {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #3
}

uint64x2_t test_vsliq_n_u64(uint64x2_t a, uint64x2_t b) {
  // CHECK: test_vsliq_n_u64
  return vsliq_n_u64(a, b, 3);
  // CHECK: sli {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #3
}

poly8x8_t test_vsli_n_p8(poly8x8_t a, poly8x8_t b) {
  // CHECK: test_vsli_n_p8
  return vsli_n_p8(a, b, 3);
  // CHECK: sli {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
}

poly16x4_t test_vsli_n_p16(poly16x4_t a, poly16x4_t b) {
  // CHECK: test_vsli_n_p16
  return vsli_n_p16(a, b, 15);
  // CHECK: sli {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #15
}

poly8x16_t test_vsliq_n_p8(poly8x16_t a, poly8x16_t b) {
  // CHECK: test_vsliq_n_p8
  return vsliq_n_p8(a, b, 3);
  // CHECK: sli {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
}

poly16x8_t test_vsliq_n_p16(poly16x8_t a, poly16x8_t b) {
  // CHECK: test_vsliq_n_p16
  return vsliq_n_p16(a, b, 15);
  // CHECK: sli {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #15
}

int8x8_t test_vqshlu_n_s8(int8x8_t a) {
  // CHECK: test_vqshlu_n_s8
  return vqshlu_n_s8(a, 3);
  // CHECK: sqshlu {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
}

int16x4_t test_vqshlu_n_s16(int16x4_t a) {
  // CHECK: test_vqshlu_n_s16
  return vqshlu_n_s16(a, 3);
  // CHECK: sqshlu {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #3
}

int32x2_t test_vqshlu_n_s32(int32x2_t a) {
  // CHECK: test_vqshlu_n_s32
  return vqshlu_n_s32(a, 3);
  // CHECK: sqshlu {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #3
}

int8x16_t test_vqshluq_n_s8(int8x16_t a) {
  // CHECK: test_vqshluq_n_s8
  return vqshluq_n_s8(a, 3);
  // CHECK: sqshlu {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
}

int16x8_t test_vqshluq_n_s16(int16x8_t a) {
  // CHECK: test_vqshluq_n_s16
  return vqshluq_n_s16(a, 3);
  // CHECK: sqshlu {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #3
}

int32x4_t test_vqshluq_n_s32(int32x4_t a) {
  // CHECK: test_vqshluq_n_s32
  return vqshluq_n_s32(a, 3);
  // CHECK: sqshlu {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #3
}

int64x2_t test_vqshluq_n_s64(int64x2_t a) {
  // CHECK: test_vqshluq_n_s64
  return vqshluq_n_s64(a, 3);
  // CHECK: sqshlu {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #3
}

int8x8_t test_vshrn_n_s16(int16x8_t a) {
  // CHECK: test_vshrn_n_s16
  return vshrn_n_s16(a, 3);
  // CHECK: shrn {{v[0-9]+}}.8b, {{v[0-9]+}}.8h, #3
}

int16x4_t test_vshrn_n_s32(int32x4_t a) {
  // CHECK: test_vshrn_n_s32
  return vshrn_n_s32(a, 9);
  // CHECK: shrn {{v[0-9]+}}.4h, {{v[0-9]+}}.4s, #9
}

int32x2_t test_vshrn_n_s64(int64x2_t a) {
  // CHECK: test_vshrn_n_s64
  return vshrn_n_s64(a, 19);
  // CHECK: shrn {{v[0-9]+}}.2s, {{v[0-9]+}}.2d, #19
}

uint8x8_t test_vshrn_n_u16(uint16x8_t a) {
  // CHECK: test_vshrn_n_u16
  return vshrn_n_u16(a, 3);
  // CHECK: shrn {{v[0-9]+}}.8b, {{v[0-9]+}}.8h, #3
}

uint16x4_t test_vshrn_n_u32(uint32x4_t a) {
  // CHECK: test_vshrn_n_u32
  return vshrn_n_u32(a, 9);
  // CHECK: shrn {{v[0-9]+}}.4h, {{v[0-9]+}}.4s, #9
}

uint32x2_t test_vshrn_n_u64(uint64x2_t a) {
  // CHECK: test_vshrn_n_u64
  return vshrn_n_u64(a, 19);
  // CHECK: shrn {{v[0-9]+}}.2s, {{v[0-9]+}}.2d, #19
}

int8x16_t test_vshrn_high_n_s16(int8x8_t a, int16x8_t b) {
  // CHECK: test_vshrn_high_n_s16
  return vshrn_high_n_s16(a, b, 3);
  // CHECK: shrn2 {{v[0-9]+}}.16b, {{v[0-9]+}}.8h, #3
}

int16x8_t test_vshrn_high_n_s32(int16x4_t a, int32x4_t b) {
  // CHECK: test_vshrn_high_n_s32
  return vshrn_high_n_s32(a, b, 9);
  // CHECK: shrn2 {{v[0-9]+}}.8h, {{v[0-9]+}}.4s, #9
}

int32x4_t test_vshrn_high_n_s64(int32x2_t a, int64x2_t b) {
  // CHECK: test_vshrn_high_n_s64
  return vshrn_high_n_s64(a, b, 19);
  // CHECK: shrn2 {{v[0-9]+}}.4s, {{v[0-9]+}}.2d, #19
}

uint8x16_t test_vshrn_high_n_u16(uint8x8_t a, uint16x8_t b) {
  // CHECK: test_vshrn_high_n_u16
  return vshrn_high_n_u16(a, b, 3);
  // CHECK: shrn2 {{v[0-9]+}}.16b, {{v[0-9]+}}.8h, #3
}

uint16x8_t test_vshrn_high_n_u32(uint16x4_t a, uint32x4_t b) {
  // CHECK: test_vshrn_high_n_u32
  return vshrn_high_n_u32(a, b, 9);
  // CHECK: shrn2 {{v[0-9]+}}.8h, {{v[0-9]+}}.4s, #9
}

uint32x4_t test_vshrn_high_n_u64(uint32x2_t a, uint64x2_t b) {
  // CHECK: test_vshrn_high_n_u64
  return vshrn_high_n_u64(a, b, 19);
  // CHECK: shrn2 {{v[0-9]+}}.4s, {{v[0-9]+}}.2d, #19
}

int8x8_t test_vqshrun_n_s16(int16x8_t a) {
  // CHECK: test_vqshrun_n_s16
  return vqshrun_n_s16(a, 3);
  // CHECK: sqshrun {{v[0-9]+}}.8b, {{v[0-9]+}}.8h, #3
}

int16x4_t test_vqshrun_n_s32(int32x4_t a) {
  // CHECK: test_vqshrun_n_s32
  return vqshrun_n_s32(a, 9);
  // CHECK: sqshrun {{v[0-9]+}}.4h, {{v[0-9]+}}.4s, #9
}

int32x2_t test_vqshrun_n_s64(int64x2_t a) {
  // CHECK: test_vqshrun_n_s64
  return vqshrun_n_s64(a, 19);
  // CHECK: sqshrun {{v[0-9]+}}.2s, {{v[0-9]+}}.2d, #19
}

int8x16_t test_vqshrun_high_n_s16(int8x8_t a, int16x8_t b) {
  // CHECK: test_vqshrun_high_n_s16
  return vqshrun_high_n_s16(a, b, 3);
  // CHECK: sqshrun2 {{v[0-9]+}}.16b, {{v[0-9]+}}.8h, #3
}

int16x8_t test_vqshrun_high_n_s32(int16x4_t a, int32x4_t b) {
  // CHECK: test_vqshrun_high_n_s32
  return vqshrun_high_n_s32(a, b, 9);
  // CHECK: sqshrun2 {{v[0-9]+}}.8h, {{v[0-9]+}}.4s, #9
}

int32x4_t test_vqshrun_high_n_s64(int32x2_t a, int64x2_t b) {
  // CHECK: test_vqshrun_high_n_s64
  return vqshrun_high_n_s64(a, b, 19);
  // CHECK: sqshrun2 {{v[0-9]+}}.4s, {{v[0-9]+}}.2d, #19
}

int8x8_t test_vrshrn_n_s16(int16x8_t a) {
  // CHECK: test_vrshrn_n_s16
  return vrshrn_n_s16(a, 3);
  // CHECK: rshrn {{v[0-9]+}}.8b, {{v[0-9]+}}.8h, #3
}

int16x4_t test_vrshrn_n_s32(int32x4_t a) {
  // CHECK: test_vrshrn_n_s32
  return vrshrn_n_s32(a, 9);
  // CHECK: rshrn {{v[0-9]+}}.4h, {{v[0-9]+}}.4s, #9
}

int32x2_t test_vrshrn_n_s64(int64x2_t a) {
  // CHECK: test_vrshrn_n_s64
  return vrshrn_n_s64(a, 19);
  // CHECK: rshrn {{v[0-9]+}}.2s, {{v[0-9]+}}.2d, #19
}

uint8x8_t test_vrshrn_n_u16(uint16x8_t a) {
  // CHECK: test_vrshrn_n_u16
  return vrshrn_n_u16(a, 3);
  // CHECK: rshrn {{v[0-9]+}}.8b, {{v[0-9]+}}.8h, #3
}

uint16x4_t test_vrshrn_n_u32(uint32x4_t a) {
  // CHECK: test_vrshrn_n_u32
  return vrshrn_n_u32(a, 9);
  // CHECK: rshrn {{v[0-9]+}}.4h, {{v[0-9]+}}.4s, #9
}

uint32x2_t test_vrshrn_n_u64(uint64x2_t a) {
  // CHECK: test_vrshrn_n_u64
  return vrshrn_n_u64(a, 19);
  // CHECK: rshrn {{v[0-9]+}}.2s, {{v[0-9]+}}.2d, #19
}

int8x16_t test_vrshrn_high_n_s16(int8x8_t a, int16x8_t b) {
  // CHECK: test_vrshrn_high_n_s16
  return vrshrn_high_n_s16(a, b, 3);
  // CHECK: rshrn2 {{v[0-9]+}}.16b, {{v[0-9]+}}.8h, #3
}

int16x8_t test_vrshrn_high_n_s32(int16x4_t a, int32x4_t b) {
  // CHECK: test_vrshrn_high_n_s32
  return vrshrn_high_n_s32(a, b, 9);
  // CHECK: rshrn2 {{v[0-9]+}}.8h, {{v[0-9]+}}.4s, #9
}

int32x4_t test_vrshrn_high_n_s64(int32x2_t a, int64x2_t b) {
  // CHECK: test_vrshrn_high_n_s64
  return vrshrn_high_n_s64(a, b, 19);
  // CHECK: rshrn2 {{v[0-9]+}}.4s, {{v[0-9]+}}.2d, #19
}

uint8x16_t test_vrshrn_high_n_u16(uint8x8_t a, uint16x8_t b) {
  // CHECK: test_vrshrn_high_n_u16
  return vrshrn_high_n_u16(a, b, 3);
  // CHECK: rshrn2 {{v[0-9]+}}.16b, {{v[0-9]+}}.8h, #3
}

uint16x8_t test_vrshrn_high_n_u32(uint16x4_t a, uint32x4_t b) {
  // CHECK: test_vrshrn_high_n_u32
  return vrshrn_high_n_u32(a, b, 9);
  // CHECK: rshrn2 {{v[0-9]+}}.8h, {{v[0-9]+}}.4s, #9
}

uint32x4_t test_vrshrn_high_n_u64(uint32x2_t a, uint64x2_t b) {
  // CHECK: test_vrshrn_high_n_u64
  return vrshrn_high_n_u64(a, b, 19);
  // CHECK: rshrn2 {{v[0-9]+}}.4s, {{v[0-9]+}}.2d, #19
}

int8x8_t test_vqrshrun_n_s16(int16x8_t a) {
  // CHECK: test_vqrshrun_n_s16
  return vqrshrun_n_s16(a, 3);
  // CHECK: sqrshrun {{v[0-9]+}}.8b, {{v[0-9]+}}.8h, #3
}

int16x4_t test_vqrshrun_n_s32(int32x4_t a) {
  // CHECK: test_vqrshrun_n_s32
  return vqrshrun_n_s32(a, 9);
  // CHECK: sqrshrun {{v[0-9]+}}.4h, {{v[0-9]+}}.4s, #9
}

int32x2_t test_vqrshrun_n_s64(int64x2_t a) {
  // CHECK: test_vqrshrun_n_s64
  return vqrshrun_n_s64(a, 19);
  // CHECK: sqrshrun {{v[0-9]+}}.2s, {{v[0-9]+}}.2d, #19
}

int8x16_t test_vqrshrun_high_n_s16(int8x8_t a, int16x8_t b) {
  // CHECK: test_vqrshrun_high_n_s16
  return vqrshrun_high_n_s16(a, b, 3);
  // CHECK: sqrshrun2 {{v[0-9]+}}.16b, {{v[0-9]+}}.8h, #3
}

int16x8_t test_vqrshrun_high_n_s32(int16x4_t a, int32x4_t b) {
  // CHECK: test_vqrshrun_high_n_s32
  return vqrshrun_high_n_s32(a, b, 9);
  // CHECK: sqrshrun2 {{v[0-9]+}}.8h, {{v[0-9]+}}.4s, #9
}

int32x4_t test_vqrshrun_high_n_s64(int32x2_t a, int64x2_t b) {
  // CHECK: test_vqrshrun_high_n_s64
  return vqrshrun_high_n_s64(a, b, 19);
  // CHECK: sqrshrun2 {{v[0-9]+}}.4s, {{v[0-9]+}}.2d, #19
}

int8x8_t test_vqshrn_n_s16(int16x8_t a) {
  // CHECK: test_vqshrn_n_s16
  return vqshrn_n_s16(a, 3);
  // CHECK: sqshrn {{v[0-9]+}}.8b, {{v[0-9]+}}.8h, #3
}

int16x4_t test_vqshrn_n_s32(int32x4_t a) {
  // CHECK: test_vqshrn_n_s32
  return vqshrn_n_s32(a, 9);
  // CHECK: sqshrn {{v[0-9]+}}.4h, {{v[0-9]+}}.4s, #9
}

int32x2_t test_vqshrn_n_s64(int64x2_t a) {
  // CHECK: test_vqshrn_n_s64
  return vqshrn_n_s64(a, 19);
  // CHECK: sqshrn {{v[0-9]+}}.2s, {{v[0-9]+}}.2d, #19
}

uint8x8_t test_vqshrn_n_u16(uint16x8_t a) {
  // CHECK: test_vqshrn_n_u16
  return vqshrn_n_u16(a, 3);
  // CHECK: uqshrn {{v[0-9]+}}.8b, {{v[0-9]+}}.8h, #3
}

uint16x4_t test_vqshrn_n_u32(uint32x4_t a) {
  // CHECK: test_vqshrn_n_u32
  return vqshrn_n_u32(a, 9);
  // CHECK: uqshrn {{v[0-9]+}}.4h, {{v[0-9]+}}.4s, #9
}

uint32x2_t test_vqshrn_n_u64(uint64x2_t a) {
  // CHECK: test_vqshrn_n_u64
  return vqshrn_n_u64(a, 19);
  // CHECK: uqshrn {{v[0-9]+}}.2s, {{v[0-9]+}}.2d, #19
}

int8x16_t test_vqshrn_high_n_s16(int8x8_t a, int16x8_t b) {
  // CHECK: test_vqshrn_high_n_s16
  return vqshrn_high_n_s16(a, b, 3);
  // CHECK: sqshrn2 {{v[0-9]+}}.16b, {{v[0-9]+}}.8h, #3
}

int16x8_t test_vqshrn_high_n_s32(int16x4_t a, int32x4_t b) {
  // CHECK: test_vqshrn_high_n_s32
  return vqshrn_high_n_s32(a, b, 9);
  // CHECK: sqshrn2 {{v[0-9]+}}.8h, {{v[0-9]+}}.4s, #9
}

int32x4_t test_vqshrn_high_n_s64(int32x2_t a, int64x2_t b) {
  // CHECK: test_vqshrn_high_n_s64
  return vqshrn_high_n_s64(a, b, 19);
  // CHECK: sqshrn2 {{v[0-9]+}}.4s, {{v[0-9]+}}.2d, #19
}

uint8x16_t test_vqshrn_high_n_u16(uint8x8_t a, uint16x8_t b) {
  // CHECK: test_vqshrn_high_n_u16
  return vqshrn_high_n_u16(a, b, 3);
  // CHECK: uqshrn2 {{v[0-9]+}}.16b, {{v[0-9]+}}.8h, #3
}

uint16x8_t test_vqshrn_high_n_u32(uint16x4_t a, uint32x4_t b) {
  // CHECK: test_vqshrn_high_n_u32
  return vqshrn_high_n_u32(a, b, 9);
  // CHECK: uqshrn2 {{v[0-9]+}}.8h, {{v[0-9]+}}.4s, #9
}

uint32x4_t test_vqshrn_high_n_u64(uint32x2_t a, uint64x2_t b) {
  // CHECK: test_vqshrn_high_n_u64
  return vqshrn_high_n_u64(a, b, 19);
  // CHECK: uqshrn2 {{v[0-9]+}}.4s, {{v[0-9]+}}.2d, #19
}

int8x8_t test_vqrshrn_n_s16(int16x8_t a) {
  // CHECK: test_vqrshrn_n_s16
  return vqrshrn_n_s16(a, 3);
  // CHECK: sqrshrn {{v[0-9]+}}.8b, {{v[0-9]+}}.8h, #3
}

int16x4_t test_vqrshrn_n_s32(int32x4_t a) {
  // CHECK: test_vqrshrn_n_s32
  return vqrshrn_n_s32(a, 9);
  // CHECK: sqrshrn {{v[0-9]+}}.4h, {{v[0-9]+}}.4s, #9
}

int32x2_t test_vqrshrn_n_s64(int64x2_t a) {
  // CHECK: test_vqrshrn_n_s64
  return vqrshrn_n_s64(a, 19);
  // CHECK: sqrshrn {{v[0-9]+}}.2s, {{v[0-9]+}}.2d, #19
}

uint8x8_t test_vqrshrn_n_u16(uint16x8_t a) {
  // CHECK: test_vqrshrn_n_u16
  return vqrshrn_n_u16(a, 3);
  // CHECK: uqrshrn {{v[0-9]+}}.8b, {{v[0-9]+}}.8h, #3
}

uint16x4_t test_vqrshrn_n_u32(uint32x4_t a) {
  // CHECK: test_vqrshrn_n_u32
  return vqrshrn_n_u32(a, 9);
  // CHECK: uqrshrn {{v[0-9]+}}.4h, {{v[0-9]+}}.4s, #9
}

uint32x2_t test_vqrshrn_n_u64(uint64x2_t a) {
  // CHECK: test_vqrshrn_n_u64
  return vqrshrn_n_u64(a, 19);
  // CHECK: uqrshrn {{v[0-9]+}}.2s, {{v[0-9]+}}.2d, #19
}

int8x16_t test_vqrshrn_high_n_s16(int8x8_t a, int16x8_t b) {
  // CHECK: test_vqrshrn_high_n_s16
  return vqrshrn_high_n_s16(a, b, 3);
  // CHECK: sqrshrn2 {{v[0-9]+}}.16b, {{v[0-9]+}}.8h, #3
}

int16x8_t test_vqrshrn_high_n_s32(int16x4_t a, int32x4_t b) {
  // CHECK: test_vqrshrn_high_n_s32
  return vqrshrn_high_n_s32(a, b, 9);
  // CHECK: sqrshrn2 {{v[0-9]+}}.8h, {{v[0-9]+}}.4s, #9
}

int32x4_t test_vqrshrn_high_n_s64(int32x2_t a, int64x2_t b) {
  // CHECK: test_vqrshrn_high_n_s64
  return vqrshrn_high_n_s64(a, b, 19);
  // CHECK: sqrshrn2 {{v[0-9]+}}.4s, {{v[0-9]+}}.2d, #19
}

uint8x16_t test_vqrshrn_high_n_u16(uint8x8_t a, uint16x8_t b) {
  // CHECK: test_vqrshrn_high_n_u16
  return vqrshrn_high_n_u16(a, b, 3);
  // CHECK: uqrshrn2 {{v[0-9]+}}.16b, {{v[0-9]+}}.8h, #3
}

uint16x8_t test_vqrshrn_high_n_u32(uint16x4_t a, uint32x4_t b) {
  // CHECK: test_vqrshrn_high_n_u32
  return vqrshrn_high_n_u32(a, b, 9);
  // CHECK: uqrshrn2 {{v[0-9]+}}.8h, {{v[0-9]+}}.4s, #9
}

uint32x4_t test_vqrshrn_high_n_u64(uint32x2_t a, uint64x2_t b) {
  // CHECK: test_vqrshrn_high_n_u64
  return vqrshrn_high_n_u64(a, b, 19);
  // CHECK: uqrshrn2 {{v[0-9]+}}.4s, {{v[0-9]+}}.2d, #19
}

int16x8_t test_vshll_n_s8(int8x8_t a) {
// CHECK: test_vshll_n_s8
  return vshll_n_s8(a, 3);
// CHECK: sshll {{v[0-9]+}}.8h, {{v[0-9]+}}.8b, #3
}

int32x4_t test_vshll_n_s16(int16x4_t a) {
// CHECK: test_vshll_n_s16
  return vshll_n_s16(a, 9);
// CHECK: sshll {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, #9
}

int64x2_t test_vshll_n_s32(int32x2_t a) {
// CHECK: test_vshll_n_s32
  return vshll_n_s32(a, 19);
// CHECK: sshll {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, #19
}

uint16x8_t test_vshll_n_u8(uint8x8_t a) {
// CHECK: test_vshll_n_u8
  return vshll_n_u8(a, 3);
// CHECK: ushll {{v[0-9]+}}.8h, {{v[0-9]+}}.8b, #3
}

uint32x4_t test_vshll_n_u16(uint16x4_t a) {
// CHECK: test_vshll_n_u16
  return vshll_n_u16(a, 9);
// CHECK: ushll {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, #9
}

uint64x2_t test_vshll_n_u32(uint32x2_t a) {
// CHECK: test_vshll_n_u32
  return vshll_n_u32(a, 19);
// CHECK: ushll {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, #19
}

int16x8_t test_vshll_high_n_s8(int8x16_t a) {
// CHECK: test_vshll_high_n_s8
  return vshll_high_n_s8(a, 3);
// CHECK: sshll2 {{v[0-9]+}}.8h, {{v[0-9]+}}.16b, #3
}

int32x4_t test_vshll_high_n_s16(int16x8_t a) {
// CHECK: test_vshll_high_n_s16
  return vshll_high_n_s16(a, 9);
// CHECK: sshll2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, #9
}

int64x2_t test_vshll_high_n_s32(int32x4_t a) {
// CHECK: test_vshll_high_n_s32
  return vshll_high_n_s32(a, 19);
// CHECK: sshll2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, #19
}

uint16x8_t test_vshll_high_n_u8(uint8x16_t a) {
// CHECK: test_vshll_high_n_u8
  return vshll_high_n_u8(a, 3);
// CHECK: ushll2 {{v[0-9]+}}.8h, {{v[0-9]+}}.16b, #3
}

uint32x4_t test_vshll_high_n_u16(uint16x8_t a) {
// CHECK: test_vshll_high_n_u16
  return vshll_high_n_u16(a, 9);
// CHECK: ushll2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, #9
}

uint64x2_t test_vshll_high_n_u32(uint32x4_t a) {
// CHECK: test_vshll_high_n_u32
  return vshll_high_n_u32(a, 19);
// CHECK: ushll2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, #19
}

int16x8_t test_vmovl_s8(int8x8_t a) {
// CHECK: test_vmovl_s8
  return vmovl_s8(a);
// CHECK: sshll {{v[0-9]+}}.8h, {{v[0-9]+}}.8b, #0
}

int32x4_t test_vmovl_s16(int16x4_t a) {
// CHECK: test_vmovl_s16
  return vmovl_s16(a);
// CHECK: sshll {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, #0
}

int64x2_t test_vmovl_s32(int32x2_t a) {
// CHECK: test_vmovl_s32
  return vmovl_s32(a);
// CHECK: sshll {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, #0
}

uint16x8_t test_vmovl_u8(uint8x8_t a) {
// CHECK: test_vmovl_u8
  return vmovl_u8(a);
// CHECK: ushll {{v[0-9]+}}.8h, {{v[0-9]+}}.8b, #0
}

uint32x4_t test_vmovl_u16(uint16x4_t a) {
// CHECK: test_vmovl_u16
  return vmovl_u16(a);
// CHECK: ushll {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, #0
}

uint64x2_t test_vmovl_u32(uint32x2_t a) {
// CHECK: test_vmovl_u32
  return vmovl_u32(a);
// CHECK: ushll {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, #0
}

int16x8_t test_vmovl_high_s8(int8x16_t a) {
// CHECK: test_vmovl_high_s8
  return vmovl_high_s8(a);
// CHECK: sshll2 {{v[0-9]+}}.8h, {{v[0-9]+}}.16b, #0
}

int32x4_t test_vmovl_high_s16(int16x8_t a) {
// CHECK: test_vmovl_high_s16
  return vmovl_high_s16(a);
// CHECK: sshll2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, #0
}

int64x2_t test_vmovl_high_s32(int32x4_t a) {
// CHECK: test_vmovl_high_s32
  return vmovl_high_s32(a);
// CHECK: sshll2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, #0
}

uint16x8_t test_vmovl_high_u8(uint8x16_t a) {
// CHECK: test_vmovl_high_u8
  return vmovl_high_u8(a);
// CHECK: ushll2 {{v[0-9]+}}.8h, {{v[0-9]+}}.16b, #0
}

uint32x4_t test_vmovl_high_u16(uint16x8_t a) {
// CHECK: test_vmovl_high_u16
  return vmovl_high_u16(a);
// CHECK: ushll2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, #0
}

uint64x2_t test_vmovl_high_u32(uint32x4_t a) {
// CHECK: test_vmovl_high_u32
  return vmovl_high_u32(a);
// CHECK: ushll2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, #0
}

float32x2_t test_vcvt_n_f32_s32(int32x2_t a) {
  // CHECK: test_vcvt_n_f32_s32
  return vcvt_n_f32_s32(a, 31);
  // CHECK: scvtf {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #31
}

float32x4_t test_vcvtq_n_f32_s32(int32x4_t a) {
  // CHECK: test_vcvtq_n_f32_s32
  return vcvtq_n_f32_s32(a, 31);
  // CHECK: scvtf {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #31
}

float64x2_t test_vcvtq_n_f64_s64(int64x2_t a) {
  // CHECK: test_vcvtq_n_f64_s64
  return vcvtq_n_f64_s64(a, 50);
  // CHECK: scvtf {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #50
}

float32x2_t test_vcvt_n_f32_u32(uint32x2_t a) {
  // CHECK: test_vcvt_n_f32_u32
  return vcvt_n_f32_u32(a, 31);
  // CHECK: ucvtf {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #31
}

float32x4_t test_vcvtq_n_f32_u32(uint32x4_t a) {
  // CHECK: test_vcvtq_n_f32_u32
  return vcvtq_n_f32_u32(a, 31);
  // CHECK: ucvtf {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #31
}

float64x2_t test_vcvtq_n_f64_u64(uint64x2_t a) {
  // CHECK: test_vcvtq_n_f64_u64
  return vcvtq_n_f64_u64(a, 50);
  // CHECK: ucvtf {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #50
}

int32x2_t test_vcvt_n_s32_f32(float32x2_t a) {
  // CHECK: test_vcvt_n_s32_f32
  return vcvt_n_s32_f32(a, 31);
  // CHECK: fcvtzs {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #31
}

int32x4_t test_vcvtq_n_s32_f32(float32x4_t a) {
  // CHECK: test_vcvtq_n_s32_f32
  return vcvtq_n_s32_f32(a, 31);
  // CHECK: fcvtzs {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #31
}

int64x2_t test_vcvtq_n_s64_f64(float64x2_t a) {
  // CHECK: test_vcvtq_n_s64_f64
  return vcvtq_n_s64_f64(a, 50);
  // CHECK: fcvtzs {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #50
}

uint32x2_t test_vcvt_n_u32_f32(float32x2_t a) {
  // CHECK: test_vcvt_n_u32_f32
  return vcvt_n_u32_f32(a, 31);
  // CHECK: fcvtzu {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #31
}

uint32x4_t test_vcvtq_n_u32_f32(float32x4_t a) {
  // CHECK: test_vcvt_n_u32_f32
  return vcvtq_n_u32_f32(a, 31);
  // CHECK: fcvtzu {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #31
}

uint64x2_t test_vcvtq_n_u64_f64(float64x2_t a) {
  // CHECK: test_vcvtq_n_u64_f64
  return vcvtq_n_u64_f64(a, 50);
  // CHECK: fcvtzu {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #50
}

int16x8_t test_vaddl_s8(int8x8_t a, int8x8_t b) {
  // CHECK: test_vaddl_s8
  return vaddl_s8(a, b);
  // CHECK: saddl {{v[0-31]+}}.8h, {{v[0-31]+}}.8b, {{v[0-31]+}}.8b
}

int32x4_t test_vaddl_s16(int16x4_t a, int16x4_t b) {
  // CHECK: test_vaddl_s16
  return vaddl_s16(a, b);
  // CHECK: saddl {{v[0-31]+}}.4s, {{v[0-31]+}}.4h, {{v[0-31]+}}.4h
}

int64x2_t test_vaddl_s32(int32x2_t a, int32x2_t b) {
  // CHECK: test_vaddl_s32
  return vaddl_s32(a, b);
  // CHECK: saddl {{v[0-31]+}}.2d, {{v[0-31]+}}.2s, {{v[0-31]+}}.2s
}

uint16x8_t test_vaddl_u8(uint8x8_t a, uint8x8_t b) {
  // CHECK: test_vaddl_u8
  return vaddl_u8(a, b);
  // CHECK: uaddl {{v[0-31]+}}.8h, {{v[0-31]+}}.8b, {{v[0-31]+}}.8b
}

uint32x4_t test_vaddl_u16(uint16x4_t a, uint16x4_t b) {
  // CHECK: test_vaddl_u16
  return vaddl_u16(a, b);
  // CHECK: uaddl {{v[0-31]+}}.4s, {{v[0-31]+}}.4h, {{v[0-31]+}}.4h
}

uint64x2_t test_vaddl_u32(uint32x2_t a, uint32x2_t b) {
  // CHECK: test_vaddl_u32
  return vaddl_u32(a, b);
  // CHECK: uaddl {{v[0-31]+}}.2d, {{v[0-31]+}}.2s, {{v[0-31]+}}.2s
}

int16x8_t test_vaddl_high_s8(int8x16_t a, int8x16_t b) {
  // CHECK: test_vaddl_high_s8
  return vaddl_high_s8(a, b);
  // CHECK: saddl2 {{v[0-31]+}}.8h, {{v[0-31]+}}.16b, {{v[0-31]+}}.16b
}

int32x4_t test_vaddl_high_s16(int16x8_t a, int16x8_t b) {
  // CHECK: test_vaddl_high_s16
  return vaddl_high_s16(a, b);
  // CHECK: saddl2 {{v[0-31]+}}.4s, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}

int64x2_t test_vaddl_high_s32(int32x4_t a, int32x4_t b) {
  // CHECK: test_vaddl_high_s32
  return vaddl_high_s32(a, b);
  // CHECK: saddl2 {{v[0-31]+}}.2d, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}

uint16x8_t test_vaddl_high_u8(uint8x16_t a, uint8x16_t b) {
  // CHECK: test_vaddl_high_u8
  return vaddl_high_u8(a, b);
  // CHECK: uaddl2 {{v[0-31]+}}.8h, {{v[0-31]+}}.16b, {{v[0-31]+}}.16b
}

uint32x4_t test_vaddl_high_u16(uint16x8_t a, uint16x8_t b) {
  // CHECK: test_vaddl_high_u16
  return vaddl_high_u16(a, b);
  // CHECK: uaddl2 {{v[0-31]+}}.4s, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}

uint64x2_t test_vaddl_high_u32(uint32x4_t a, uint32x4_t b) {
  // CHECK: test_vaddl_high_u32
  return vaddl_high_u32(a, b);
  // CHECK: uaddl2 {{v[0-31]+}}.2d, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}

int16x8_t test_vaddw_s8(int16x8_t a, int8x8_t b) {
  // CHECK: test_vaddw_s8
  return vaddw_s8(a, b);
  // CHECK: saddw {{v[0-31]+}}.8h, {{v[0-31]+}}.8h, {{v[0-31]+}}.8b
}

int32x4_t test_vaddw_s16(int32x4_t a, int16x4_t b) {
  // CHECK: test_vaddw_s16
  return vaddw_s16(a, b);
  // CHECK: saddw {{v[0-31]+}}.4s, {{v[0-31]+}}.4s, {{v[0-31]+}}.4h
}

int64x2_t test_vaddw_s32(int64x2_t a, int32x2_t b) {
  // CHECK: test_vaddw_s32
  return vaddw_s32(a, b);
  // CHECK: saddw {{v[0-31]+}}.2d, {{v[0-31]+}}.2d, {{v[0-31]+}}.2s
}

uint16x8_t test_vaddw_u8(uint16x8_t a, uint8x8_t b) {
  // CHECK: test_vaddw_u8
  return vaddw_u8(a, b);
  // CHECK: uaddw {{v[0-31]+}}.8h, {{v[0-31]+}}.8h, {{v[0-31]+}}.8b
}

uint32x4_t test_vaddw_u16(uint32x4_t a, uint16x4_t b) {
  // CHECK: test_vaddw_u16
  return vaddw_u16(a, b);
  // CHECK: uaddw {{v[0-31]+}}.4s, {{v[0-31]+}}.4s, {{v[0-31]+}}.4h
}

uint64x2_t test_vaddw_u32(uint64x2_t a, uint32x2_t b) {
  // CHECK: test_vaddw_u32
  return vaddw_u32(a, b);
  // CHECK: uaddw {{v[0-31]+}}.2d, {{v[0-31]+}}.2d, {{v[0-31]+}}.2s
}

int16x8_t test_vaddw_high_s8(int16x8_t a, int8x16_t b) {
  // CHECK: test_vaddw_high_s8
  return vaddw_high_s8(a, b);
  // CHECK: saddw2 {{v[0-31]+}}.8h, {{v[0-31]+}}.8h, {{v[0-31]+}}.16b
}

int32x4_t test_vaddw_high_s16(int32x4_t a, int16x8_t b) {
  // CHECK: test_vaddw_high_s16
  return vaddw_high_s16(a, b);
  // CHECK: saddw2 {{v[0-31]+}}.4s, {{v[0-31]+}}.4s, {{v[0-31]+}}.8h
}

int64x2_t test_vaddw_high_s32(int64x2_t a, int32x4_t b) {
  // CHECK: test_vaddw_high_s32
  return vaddw_high_s32(a, b);
  // CHECK: saddw2 {{v[0-31]+}}.2d, {{v[0-31]+}}.2d, {{v[0-31]+}}.4s
}

uint16x8_t test_vaddw_high_u8(uint16x8_t a, uint8x16_t b) {
  // CHECK: test_vaddw_high_u8
  return vaddw_high_u8(a, b);
  // CHECK: uaddw2 {{v[0-31]+}}.8h, {{v[0-31]+}}.8h, {{v[0-31]+}}.16b
}

uint32x4_t test_vaddw_high_u16(uint32x4_t a, uint16x8_t b) {
  // CHECK: test_vaddw_high_u16
  return vaddw_high_u16(a, b);
  // CHECK: uaddw2 {{v[0-31]+}}.4s, {{v[0-31]+}}.4s, {{v[0-31]+}}.8h
}

uint64x2_t test_vaddw_high_u32(uint64x2_t a, uint32x4_t b) {
  // CHECK: test_vaddw_high_u32
  return vaddw_high_u32(a, b);
  // CHECK: uaddw2 {{v[0-31]+}}.2d, {{v[0-31]+}}.2d, {{v[0-31]+}}.4s
}

int16x8_t test_vsubl_s8(int8x8_t a, int8x8_t b) {
  // CHECK: test_vsubl_s8
  return vsubl_s8(a, b);
  // CHECK: ssubl {{v[0-31]+}}.8h, {{v[0-31]+}}.8b, {{v[0-31]+}}.8b
}

int32x4_t test_vsubl_s16(int16x4_t a, int16x4_t b) {
  // CHECK: test_vsubl_s16
  return vsubl_s16(a, b);
  // CHECK: ssubl {{v[0-31]+}}.4s, {{v[0-31]+}}.4h, {{v[0-31]+}}.4h
}

int64x2_t test_vsubl_s32(int32x2_t a, int32x2_t b) {
  // CHECK: test_vsubl_s32
  return vsubl_s32(a, b);
  // CHECK: ssubl {{v[0-31]+}}.2d, {{v[0-31]+}}.2s, {{v[0-31]+}}.2s
}

uint16x8_t test_vsubl_u8(uint8x8_t a, uint8x8_t b) {
  // CHECK: test_vsubl_u8
  return vsubl_u8(a, b);
  // CHECK: usubl {{v[0-31]+}}.8h, {{v[0-31]+}}.8b, {{v[0-31]+}}.8b
}

uint32x4_t test_vsubl_u16(uint16x4_t a, uint16x4_t b) {
  // CHECK: test_vsubl_u16
  return vsubl_u16(a, b);
  // CHECK: usubl {{v[0-31]+}}.4s, {{v[0-31]+}}.4h, {{v[0-31]+}}.4h
}

uint64x2_t test_vsubl_u32(uint32x2_t a, uint32x2_t b) {
  // CHECK: test_vsubl_u32
  return vsubl_u32(a, b);
  // CHECK: usubl {{v[0-31]+}}.2d, {{v[0-31]+}}.2s, {{v[0-31]+}}.2s
}

int16x8_t test_vsubl_high_s8(int8x16_t a, int8x16_t b) {
  // CHECK: test_vsubl_high_s8
  return vsubl_high_s8(a, b);
  // CHECK: ssubl2 {{v[0-31]+}}.8h, {{v[0-31]+}}.16b, {{v[0-31]+}}.16b
}

int32x4_t test_vsubl_high_s16(int16x8_t a, int16x8_t b) {
  // CHECK: test_vsubl_high_s16
  return vsubl_high_s16(a, b);
  // CHECK: ssubl2 {{v[0-31]+}}.4s, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}

int64x2_t test_vsubl_high_s32(int32x4_t a, int32x4_t b) {
  // CHECK: test_vsubl_high_s32
  return vsubl_high_s32(a, b);
  // CHECK: ssubl2 {{v[0-31]+}}.2d, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}

uint16x8_t test_vsubl_high_u8(uint8x16_t a, uint8x16_t b) {
  // CHECK: test_vsubl_high_u8
  return vsubl_high_u8(a, b);
  // CHECK: usubl2 {{v[0-31]+}}.8h, {{v[0-31]+}}.16b, {{v[0-31]+}}.16b
}

uint32x4_t test_vsubl_high_u16(uint16x8_t a, uint16x8_t b) {
  // CHECK: test_vsubl_high_u16
  return vsubl_high_u16(a, b);
  // CHECK: usubl2 {{v[0-31]+}}.4s, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}

uint64x2_t test_vsubl_high_u32(uint32x4_t a, uint32x4_t b) {
  // CHECK: test_vsubl_high_u32
  return vsubl_high_u32(a, b);
  // CHECK: usubl2 {{v[0-31]+}}.2d, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}

int16x8_t test_vsubw_s8(int16x8_t a, int8x8_t b) {
  // CHECK: test_vsubw_s8
  return vsubw_s8(a, b);
  // CHECK: ssubw {{v[0-31]+}}.8h, {{v[0-31]+}}.8h, {{v[0-31]+}}.8b
}

int32x4_t test_vsubw_s16(int32x4_t a, int16x4_t b) {
  // CHECK: test_vsubw_s16
  return vsubw_s16(a, b);
  // CHECK: ssubw {{v[0-31]+}}.4s, {{v[0-31]+}}.4s, {{v[0-31]+}}.4h
}

int64x2_t test_vsubw_s32(int64x2_t a, int32x2_t b) {
  // CHECK: test_vsubw_s32
  return vsubw_s32(a, b);
  // CHECK: ssubw {{v[0-31]+}}.2d, {{v[0-31]+}}.2d, {{v[0-31]+}}.2s
}

uint16x8_t test_vsubw_u8(uint16x8_t a, uint8x8_t b) {
  // CHECK: test_vsubw_u8
  return vsubw_u8(a, b);
  // CHECK: usubw {{v[0-31]+}}.8h, {{v[0-31]+}}.8h, {{v[0-31]+}}.8b
}

uint32x4_t test_vsubw_u16(uint32x4_t a, uint16x4_t b) {
  // CHECK: test_vsubw_u16
  return vsubw_u16(a, b);
  // CHECK: usubw {{v[0-31]+}}.4s, {{v[0-31]+}}.4s, {{v[0-31]+}}.4h
}

uint64x2_t test_vsubw_u32(uint64x2_t a, uint32x2_t b) {
  // CHECK: test_vsubw_u32
  return vsubw_u32(a, b);
  // CHECK: usubw {{v[0-31]+}}.2d, {{v[0-31]+}}.2d, {{v[0-31]+}}.2s
}

int16x8_t test_vsubw_high_s8(int16x8_t a, int8x16_t b) {
  // CHECK: test_vsubw_high_s8
  return vsubw_high_s8(a, b);
  // CHECK: ssubw2 {{v[0-31]+}}.8h, {{v[0-31]+}}.8h, {{v[0-31]+}}.16b
}

int32x4_t test_vsubw_high_s16(int32x4_t a, int16x8_t b) {
  // CHECK: test_vsubw_high_s16
  return vsubw_high_s16(a, b);
  // CHECK: ssubw2 {{v[0-31]+}}.4s, {{v[0-31]+}}.4s, {{v[0-31]+}}.8h
}

int64x2_t test_vsubw_high_s32(int64x2_t a, int32x4_t b) {
  // CHECK: test_vsubw_high_s32
  return vsubw_high_s32(a, b);
  // CHECK: ssubw2 {{v[0-31]+}}.2d, {{v[0-31]+}}.2d, {{v[0-31]+}}.4s
}

uint16x8_t test_vsubw_high_u8(uint16x8_t a, uint8x16_t b) {
  // CHECK: test_vsubw_high_u8
  return vsubw_high_u8(a, b);
  // CHECK: usubw2 {{v[0-31]+}}.8h, {{v[0-31]+}}.8h, {{v[0-31]+}}.16b
}

uint32x4_t test_vsubw_high_u16(uint32x4_t a, uint16x8_t b) {
  // CHECK: test_vsubw_high_u16
  return vsubw_high_u16(a, b);
  // CHECK: usubw2 {{v[0-31]+}}.4s, {{v[0-31]+}}.4s, {{v[0-31]+}}.8h
}

uint64x2_t test_vsubw_high_u32(uint64x2_t a, uint32x4_t b) {
  // CHECK: test_vsubw_high_u32
  return vsubw_high_u32(a, b);
  // CHECK: usubw2 {{v[0-31]+}}.2d, {{v[0-31]+}}.2d, {{v[0-31]+}}.4s
}

int8x8_t test_vaddhn_s16(int16x8_t a, int16x8_t b) {
  // CHECK: test_vaddhn_s16
  return vaddhn_s16(a, b);
  // CHECK: addhn {{v[0-31]+}}.8b, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}

int16x4_t test_vaddhn_s32(int32x4_t a, int32x4_t b) {
  // CHECK: test_vaddhn_s32
  return vaddhn_s32(a, b);
  // CHECK: addhn {{v[0-31]+}}.4h, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}

int32x2_t test_vaddhn_s64(int64x2_t a, int64x2_t b) {
  // CHECK: test_vaddhn_s64
  return vaddhn_s64(a, b);
  // CHECK: addhn {{v[0-31]+}}.2s, {{v[0-31]+}}.2d, {{v[0-31]+}}.2d
}

uint8x8_t test_vaddhn_u16(uint16x8_t a, uint16x8_t b) {
  // CHECK: test_vaddhn_u16
  return vaddhn_u16(a, b);
  // CHECK: addhn {{v[0-31]+}}.8b, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}

uint16x4_t test_vaddhn_u32(uint32x4_t a, uint32x4_t b) {
  // CHECK: test_vaddhn_u32
  return vaddhn_u32(a, b);
  // CHECK: addhn {{v[0-31]+}}.4h, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}

uint32x2_t test_vaddhn_u64(uint64x2_t a, uint64x2_t b) {
  // CHECK: test_vaddhn_u64
  return vaddhn_u64(a, b);
  // CHECK: addhn {{v[0-31]+}}.2s, {{v[0-31]+}}.2d, {{v[0-31]+}}.2d
}

int8x16_t test_vaddhn_high_s16(int8x8_t r, int16x8_t a, int16x8_t b) {
  // CHECK: test_vaddhn_high_s16
  return vaddhn_high_s16(r, a, b);
  // CHECK: addhn2 {{v[0-31]+}}.16b, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}

int16x8_t test_vaddhn_high_s32(int16x4_t r, int32x4_t a, int32x4_t b) {
  // CHECK: test_vaddhn_high_s32
  return vaddhn_high_s32(r, a, b);
  // CHECK: addhn2 {{v[0-31]+}}.8h, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}

int32x4_t test_vaddhn_high_s64(int32x2_t r, int64x2_t a, int64x2_t b) {
  // CHECK: test_vaddhn_high_s64
  return vaddhn_high_s64(r, a, b);
  // CHECK: addhn2 {{v[0-31]+}}.4s, {{v[0-31]+}}.2d, {{v[0-31]+}}.2d
}

uint8x16_t test_vaddhn_high_u16(uint8x8_t r, uint16x8_t a, uint16x8_t b) {
  // CHECK: test_vaddhn_high_u16
  return vaddhn_high_u16(r, a, b);
  // CHECK: addhn2 {{v[0-31]+}}.16b, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}

uint16x8_t test_vaddhn_high_u32(uint16x4_t r, uint32x4_t a, uint32x4_t b) {
  // CHECK: test_vaddhn_high_u32
  return vaddhn_high_u32(r, a, b);
  // CHECK: addhn2 {{v[0-31]+}}.8h, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}

uint32x4_t test_vaddhn_high_u64(uint32x2_t r, uint64x2_t a, uint64x2_t b) {
  // CHECK: test_vaddhn_high_u64
  return vaddhn_high_u64(r, a, b);
  // CHECK: addhn2 {{v[0-31]+}}.4s, {{v[0-31]+}}.2d, {{v[0-31]+}}.2d
}

int8x8_t test_vraddhn_s16(int16x8_t a, int16x8_t b) {
  // CHECK: test_vraddhn_s16
  return vraddhn_s16(a, b);
  // CHECK: raddhn {{v[0-31]+}}.8b, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}

int16x4_t test_vraddhn_s32(int32x4_t a, int32x4_t b) {
  // CHECK: test_vraddhn_s32
  return vraddhn_s32(a, b);
  // CHECK: raddhn {{v[0-31]+}}.4h, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}

int32x2_t test_vraddhn_s64(int64x2_t a, int64x2_t b) {
  // CHECK: test_vraddhn_s64
  return vraddhn_s64(a, b);
  // CHECK: raddhn {{v[0-31]+}}.2s, {{v[0-31]+}}.2d, {{v[0-31]+}}.2d
}

uint8x8_t test_vraddhn_u16(uint16x8_t a, uint16x8_t b) {
  // CHECK: test_vraddhn_u16
  return vraddhn_u16(a, b);
  // CHECK: raddhn {{v[0-31]+}}.8b, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}

uint16x4_t test_vraddhn_u32(uint32x4_t a, uint32x4_t b) {
  // CHECK: test_vraddhn_u32
  return vraddhn_u32(a, b);
  // CHECK: raddhn {{v[0-31]+}}.4h, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}

uint32x2_t test_vraddhn_u64(uint64x2_t a, uint64x2_t b) {
  // CHECK: test_vraddhn_u64
  return vraddhn_u64(a, b);
  // CHECK: raddhn {{v[0-31]+}}.2s, {{v[0-31]+}}.2d, {{v[0-31]+}}.2d
}

int8x16_t test_vraddhn_high_s16(int8x8_t r, int16x8_t a, int16x8_t b) {
  // CHECK: test_vraddhn_high_s16
  return vraddhn_high_s16(r, a, b);
  // CHECK: raddhn2 {{v[0-31]+}}.16b, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}

int16x8_t test_vraddhn_high_s32(int16x4_t r, int32x4_t a, int32x4_t b) {
  // CHECK: test_vraddhn_high_s32
  return vraddhn_high_s32(r, a, b);
  // CHECK: raddhn2 {{v[0-31]+}}.8h, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}

int32x4_t test_vraddhn_high_s64(int32x2_t r, int64x2_t a, int64x2_t b) {
  // CHECK: test_vraddhn_high_s64
  return vraddhn_high_s64(r, a, b);
  // CHECK: raddhn2 {{v[0-31]+}}.4s, {{v[0-31]+}}.2d, {{v[0-31]+}}.2d
}

uint8x16_t test_vraddhn_high_u16(uint8x8_t r, uint16x8_t a, uint16x8_t b) {
  // CHECK: test_vraddhn_high_u16
  return vraddhn_high_u16(r, a, b);
  // CHECK: raddhn2 {{v[0-31]+}}.16b, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}

uint16x8_t test_vraddhn_high_u32(uint16x4_t r, uint32x4_t a, uint32x4_t b) {
  // CHECK: test_vraddhn_high_u32
  return vraddhn_high_u32(r, a, b);
  // CHECK: raddhn2 {{v[0-31]+}}.8h, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}

uint32x4_t test_vraddhn_high_u64(uint32x2_t r, uint64x2_t a, uint64x2_t b) {
  // CHECK: test_vraddhn_high_u64
  return vraddhn_high_u64(r, a, b);
  // CHECK: raddhn2 {{v[0-31]+}}.4s, {{v[0-31]+}}.2d, {{v[0-31]+}}.2d
}

int8x8_t test_vsubhn_s16(int16x8_t a, int16x8_t b) {
  // CHECK: test_vsubhn_s16
  return vsubhn_s16(a, b);
  // CHECK: subhn {{v[0-31]+}}.8b, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}

int16x4_t test_vsubhn_s32(int32x4_t a, int32x4_t b) {
  // CHECK: test_vsubhn_s32
  return vsubhn_s32(a, b);
  // CHECK: subhn {{v[0-31]+}}.4h, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}

int32x2_t test_vsubhn_s64(int64x2_t a, int64x2_t b) {
  // CHECK: test_vsubhn_s64
  return vsubhn_s64(a, b);
  // CHECK: subhn {{v[0-31]+}}.2s, {{v[0-31]+}}.2d, {{v[0-31]+}}.2d
}

uint8x8_t test_vsubhn_u16(uint16x8_t a, uint16x8_t b) {
  // CHECK: test_vsubhn_u16
  return vsubhn_u16(a, b);
  // CHECK: subhn {{v[0-31]+}}.8b, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}

uint16x4_t test_vsubhn_u32(uint32x4_t a, uint32x4_t b) {
  // CHECK: test_vsubhn_u32
  return vsubhn_u32(a, b);
  // CHECK: subhn {{v[0-31]+}}.4h, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}

uint32x2_t test_vsubhn_u64(uint64x2_t a, uint64x2_t b) {
  // CHECK: test_vsubhn_u64
  return vsubhn_u64(a, b);
  // CHECK: subhn {{v[0-31]+}}.2s, {{v[0-31]+}}.2d, {{v[0-31]+}}.2d
}

int8x16_t test_vsubhn_high_s16(int8x8_t r, int16x8_t a, int16x8_t b) {
  // CHECK: test_vsubhn_high_s16
  return vsubhn_high_s16(r, a, b);
  // CHECK: subhn2 {{v[0-31]+}}.16b, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}

int16x8_t test_vsubhn_high_s32(int16x4_t r, int32x4_t a, int32x4_t b) {
  // CHECK: test_vsubhn_high_s32
  return vsubhn_high_s32(r, a, b);
  // CHECK: subhn2 {{v[0-31]+}}.8h, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}

int32x4_t test_vsubhn_high_s64(int32x2_t r, int64x2_t a, int64x2_t b) {
  // CHECK: test_vsubhn_high_s64
  return vsubhn_high_s64(r, a, b);
  // CHECK: subhn2 {{v[0-31]+}}.4s, {{v[0-31]+}}.2d, {{v[0-31]+}}.2d
}

uint8x16_t test_vsubhn_high_u16(uint8x8_t r, uint16x8_t a, uint16x8_t b) {
  // CHECK: test_vsubhn_high_u16
  return vsubhn_high_u16(r, a, b);
  // CHECK: subhn2 {{v[0-31]+}}.16b, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}

uint16x8_t test_vsubhn_high_u32(uint16x4_t r, uint32x4_t a, uint32x4_t b) {
  // CHECK: test_vsubhn_high_u32
  return vsubhn_high_u32(r, a, b);
  // CHECK: subhn2 {{v[0-31]+}}.8h, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}

uint32x4_t test_vsubhn_high_u64(uint32x2_t r, uint64x2_t a, uint64x2_t b) {
  // CHECK: test_vsubhn_high_u64
  return vsubhn_high_u64(r, a, b);
  // CHECK: subhn2 {{v[0-31]+}}.4s, {{v[0-31]+}}.2d, {{v[0-31]+}}.2d
}

int8x8_t test_vrsubhn_s16(int16x8_t a, int16x8_t b) {
  // CHECK: test_vrsubhn_s16
  return vrsubhn_s16(a, b);
  // CHECK: rsubhn {{v[0-31]+}}.8b, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}

int16x4_t test_vrsubhn_s32(int32x4_t a, int32x4_t b) {
  // CHECK: test_vrsubhn_s32
  return vrsubhn_s32(a, b);
  // CHECK: rsubhn {{v[0-31]+}}.4h, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}

int32x2_t test_vrsubhn_s64(int64x2_t a, int64x2_t b) {
  // CHECK: test_vrsubhn_s64
  return vrsubhn_s64(a, b);
  // CHECK: rsubhn {{v[0-31]+}}.2s, {{v[0-31]+}}.2d, {{v[0-31]+}}.2d
}

uint8x8_t test_vrsubhn_u16(uint16x8_t a, uint16x8_t b) {
  // CHECK: test_vrsubhn_u16
  return vrsubhn_u16(a, b);
  // CHECK: rsubhn {{v[0-31]+}}.8b, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}

uint16x4_t test_vrsubhn_u32(uint32x4_t a, uint32x4_t b) {
  // CHECK: test_vrsubhn_u32
  return vrsubhn_u32(a, b);
  // CHECK: rsubhn {{v[0-31]+}}.4h, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}

uint32x2_t test_vrsubhn_u64(uint64x2_t a, uint64x2_t b) {
  // CHECK: test_vrsubhn_u64
  return vrsubhn_u64(a, b);
  // CHECK: rsubhn {{v[0-31]+}}.2s, {{v[0-31]+}}.2d, {{v[0-31]+}}.2d
}

int8x16_t test_vrsubhn_high_s16(int8x8_t r, int16x8_t a, int16x8_t b) {
  // CHECK: test_vrsubhn_high_s16
  return vrsubhn_high_s16(r, a, b);
  // CHECK: rsubhn2 {{v[0-31]+}}.16b, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}

int16x8_t test_vrsubhn_high_s32(int16x4_t r, int32x4_t a, int32x4_t b) {
  // CHECK: test_vrsubhn_high_s32
  return vrsubhn_high_s32(r, a, b);
  // CHECK: rsubhn2 {{v[0-31]+}}.8h, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}

int32x4_t test_vrsubhn_high_s64(int32x2_t r, int64x2_t a, int64x2_t b) {
  // CHECK: test_vrsubhn_high_s64
  return vrsubhn_high_s64(r, a, b);
  // CHECK: rsubhn2 {{v[0-31]+}}.4s, {{v[0-31]+}}.2d, {{v[0-31]+}}.2d
}

uint8x16_t test_vrsubhn_high_u16(uint8x8_t r, uint16x8_t a, uint16x8_t b) {
  // CHECK: test_vrsubhn_high_u16
  return vrsubhn_high_u16(r, a, b);
  // CHECK: rsubhn2 {{v[0-31]+}}.16b, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}

uint16x8_t test_vrsubhn_high_u32(uint16x4_t r, uint32x4_t a, uint32x4_t b) {
  // CHECK: test_vrsubhn_high_u32
  return vrsubhn_high_u32(r, a, b);
  // CHECK: rsubhn2 {{v[0-31]+}}.8h, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}

uint32x4_t test_vrsubhn_high_u64(uint32x2_t r, uint64x2_t a, uint64x2_t b) {
  // CHECK: test_vrsubhn_high_u64
  return vrsubhn_high_u64(r, a, b);
  // CHECK: rsubhn2 {{v[0-31]+}}.4s, {{v[0-31]+}}.2d, {{v[0-31]+}}.2d
}

int16x8_t test_vabdl_s8(int8x8_t a, int8x8_t b) {
  // CHECK: test_vabdl_s8
  return vabdl_s8(a, b);
  // CHECK: sabdl {{v[0-31]+}}.8h, {{v[0-31]+}}.8b, {{v[0-31]+}}.8b
}
int32x4_t test_vabdl_s16(int16x4_t a, int16x4_t b) {
  // CHECK: test_vabdl_s16
  return vabdl_s16(a, b);
  // CHECK: sabdl {{v[0-31]+}}.4s, {{v[0-31]+}}.4h, {{v[0-31]+}}.4h
}
int64x2_t test_vabdl_s32(int32x2_t a, int32x2_t b) {
  // CHECK: test_vabdl_s32
  return vabdl_s32(a, b);
  // CHECK: sabdl {{v[0-31]+}}.2d, {{v[0-31]+}}.2s, {{v[0-31]+}}.2s
}
uint16x8_t test_vabdl_u8(uint8x8_t a, uint8x8_t b) {
  // CHECK: test_vabdl_u8
  return vabdl_u8(a, b);
  // CHECK: uabdl {{v[0-31]+}}.8h, {{v[0-31]+}}.8b, {{v[0-31]+}}.8b
}
uint32x4_t test_vabdl_u16(uint16x4_t a, uint16x4_t b) {
  // CHECK: test_vabdl_u16
  return vabdl_u16(a, b);
  // CHECK: uabdl {{v[0-31]+}}.4s, {{v[0-31]+}}.4h, {{v[0-31]+}}.4h
}
uint64x2_t test_vabdl_u32(uint32x2_t a, uint32x2_t b) {
  // CHECK: test_vabdl_u32
  return vabdl_u32(a, b);
  // CHECK: uabdl {{v[0-31]+}}.2d, {{v[0-31]+}}.2s, {{v[0-31]+}}.2s
}

int16x8_t test_vabal_s8(int16x8_t a, int8x8_t b, int8x8_t c) {
  // CHECK: test_vabal_s8
  return vabal_s8(a, b, c);
  // CHECK: sabal {{v[0-31]+}}.8h, {{v[0-31]+}}.8b, {{v[0-31]+}}.8b
}
int32x4_t test_vabal_s16(int32x4_t a, int16x4_t b, int16x4_t c) {
  // CHECK: test_vabal_s16
  return vabal_s16(a, b, c);
  // CHECK: sabal {{v[0-31]+}}.4s, {{v[0-31]+}}.4h, {{v[0-31]+}}.4h
}
int64x2_t test_vabal_s32(int64x2_t a, int32x2_t b, int32x2_t c) {
  // CHECK: test_vabal_s32
  return vabal_s32(a, b, c);
  // CHECK: sabal {{v[0-31]+}}.2d, {{v[0-31]+}}.2s, {{v[0-31]+}}.2s
}
uint16x8_t test_vabal_u8(uint16x8_t a, uint8x8_t b, uint8x8_t c) {
  // CHECK: test_vabal_u8
  return vabal_u8(a, b, c);
  // CHECK: uabal {{v[0-31]+}}.8h, {{v[0-31]+}}.8b, {{v[0-31]+}}.8b
}
uint32x4_t test_vabal_u16(uint32x4_t a, uint16x4_t b, uint16x4_t c) {
  // CHECK: test_vabal_u16
  return vabal_u16(a, b, c);
  // CHECK: uabal {{v[0-31]+}}.4s, {{v[0-31]+}}.4h, {{v[0-31]+}}.4h
}
uint64x2_t test_vabal_u32(uint64x2_t a, uint32x2_t b, uint32x2_t c) {
  // CHECK: test_vabal_u32
  return vabal_u32(a, b, c);
  // CHECK: uabal {{v[0-31]+}}.2d, {{v[0-31]+}}.2s, {{v[0-31]+}}.2s
}

int16x8_t test_vabdl_high_s8(int8x16_t a, int8x16_t b) {
  // CHECK: test_vabdl_high_s8
  return vabdl_high_s8(a, b);
  // CHECK: sabdl2 {{v[0-31]+}}.8h, {{v[0-31]+}}.16b, {{v[0-31]+}}.16b
}
int32x4_t test_vabdl_high_s16(int16x8_t a, int16x8_t b) {
  // CHECK: test_vabdl_high_s16
  return vabdl_high_s16(a, b);
  // CHECK: sabdl2 {{v[0-31]+}}.4s, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}
int64x2_t test_vabdl_high_s32(int32x4_t a, int32x4_t b) {
  // CHECK: test_vabdl_high_s32
  return vabdl_high_s32(a, b);
  // CHECK: sabdl2 {{v[0-31]+}}.2d, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}
uint16x8_t test_vabdl_high_u8(uint8x16_t a, uint8x16_t b) {
  // CHECK: test_vabdl_high_u8
  return vabdl_high_u8(a, b);
  // CHECK: uabdl2 {{v[0-31]+}}.8h, {{v[0-31]+}}.16b, {{v[0-31]+}}.16b
}
uint32x4_t test_vabdl_high_u16(uint16x8_t a, uint16x8_t b) {
  // CHECK: test_vabdl_high_u16
  return vabdl_high_u16(a, b);
  // CHECK: uabdl2 {{v[0-31]+}}.4s, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}
uint64x2_t test_vabdl_high_u32(uint32x4_t a, uint32x4_t b) {
  // CHECK: test_vabdl_high_u32
  return vabdl_high_u32(a, b);
  // CHECK: uabdl2 {{v[0-31]+}}.2d, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}

int16x8_t test_vabal_high_s8(int16x8_t a, int8x16_t b, int8x16_t c) {
  // CHECK: test_vabal_high_s8
  return vabal_high_s8(a, b, c);
  // CHECK: sabal2 {{v[0-31]+}}.8h, {{v[0-31]+}}.16b, {{v[0-31]+}}.16b
}
int32x4_t test_vabal_high_s16(int32x4_t a, int16x8_t b, int16x8_t c) {
  // CHECK: test_vabal_high_s16
  return vabal_high_s16(a, b, c);
  // CHECK: sabal2 {{v[0-31]+}}.4s, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}
int64x2_t test_vabal_high_s32(int64x2_t a, int32x4_t b, int32x4_t c) {
  // CHECK: test_vabal_high_s32
  return vabal_high_s32(a, b, c);
  // CHECK: sabal2 {{v[0-31]+}}.2d, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}
uint16x8_t test_vabal_high_u8(uint16x8_t a, uint8x16_t b, uint8x16_t c) {
  // CHECK: test_vabal_high_u8
  return vabal_high_u8(a, b, c);
  // CHECK: uabal2 {{v[0-31]+}}.8h, {{v[0-31]+}}.16b, {{v[0-31]+}}.16b
}
uint32x4_t test_vabal_high_u16(uint32x4_t a, uint16x8_t b, uint16x8_t c) {
  // CHECK: test_vabal_high_u16
  return vabal_high_u16(a, b, c);
  // CHECK: uabal2 {{v[0-31]+}}.4s, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}
uint64x2_t test_vabal_high_u32(uint64x2_t a, uint32x4_t b, uint32x4_t c) {
  // CHECK: test_vabal_high_u32
  return vabal_high_u32(a, b, c);
  // CHECK: uabal2 {{v[0-31]+}}.2d, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}

int16x8_t test_vmull_s8(int8x8_t a, int8x8_t b) {
  // CHECK: test_vmull_s8
  return vmull_s8(a, b);
  // CHECK: smull {{v[0-31]+}}.8h, {{v[0-31]+}}.8b, {{v[0-31]+}}.8b
}
int32x4_t test_vmull_s16(int16x4_t a, int16x4_t b) {
  // CHECK: test_vmull_s16
  return vmull_s16(a, b);
  // CHECK: smull {{v[0-31]+}}.4s, {{v[0-31]+}}.4h, {{v[0-31]+}}.4h
}
int64x2_t test_vmull_s32(int32x2_t a, int32x2_t b) {
  // CHECK: test_vmull_s32
  return vmull_s32(a, b);
  // CHECK: smull {{v[0-31]+}}.2d, {{v[0-31]+}}.2s, {{v[0-31]+}}.2s
}
uint16x8_t test_vmull_u8(uint8x8_t a, uint8x8_t b) {
  // CHECK: test_vmull_u8
  return vmull_u8(a, b);
  // CHECK: umull {{v[0-31]+}}.8h, {{v[0-31]+}}.8b, {{v[0-31]+}}.8b
}
uint32x4_t test_vmull_u16(uint16x4_t a, uint16x4_t b) {
  // CHECK: test_vmull_u16
  return vmull_u16(a, b);
  // CHECK: umull {{v[0-31]+}}.4s, {{v[0-31]+}}.4h, {{v[0-31]+}}.4h
}
uint64x2_t test_vmull_u32(uint32x2_t a, uint32x2_t b) {
  // CHECK: test_vmull_u32
  return vmull_u32(a, b);
  // CHECK: umull {{v[0-31]+}}.2d, {{v[0-31]+}}.2s, {{v[0-31]+}}.2s
}

int16x8_t test_vmull_high_s8(int8x16_t a, int8x16_t b) {
  // CHECK: test_vmull_high_s8
  return vmull_high_s8(a, b);
  // CHECK: smull2 {{v[0-31]+}}.8h, {{v[0-31]+}}.16b, {{v[0-31]+}}.16b
}
int32x4_t test_vmull_high_s16(int16x8_t a, int16x8_t b) {
  // CHECK: test_vmull_high_s16
  return vmull_high_s16(a, b);
  // CHECK: smull2 {{v[0-31]+}}.4s, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}
int64x2_t test_vmull_high_s32(int32x4_t a, int32x4_t b) {
  // CHECK: test_vmull_high_s32
  return vmull_high_s32(a, b);
  // CHECK: smull2 {{v[0-31]+}}.2d, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}
uint16x8_t test_vmull_high_u8(uint8x16_t a, uint8x16_t b) {
  // CHECK: test_vmull_high_u8
  return vmull_high_u8(a, b);
  // CHECK: umull2 {{v[0-31]+}}.8h, {{v[0-31]+}}.16b, {{v[0-31]+}}.16b
}
uint32x4_t test_vmull_high_u16(uint16x8_t a, uint16x8_t b) {
  // CHECK: test_vmull_high_u16
  return vmull_high_u16(a, b);
  // CHECK: umull2 {{v[0-31]+}}.4s, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}
uint64x2_t test_vmull_high_u32(uint32x4_t a, uint32x4_t b) {
  // CHECK: test_vmull_high_u32
  return vmull_high_u32(a, b);
  // CHECK: umull2 {{v[0-31]+}}.2d, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}

int16x8_t test_vmlal_s8(int16x8_t a, int8x8_t b, int8x8_t c) {
  // CHECK: test_vmlal_s8
  return vmlal_s8(a, b, c);
  // CHECK: smlal {{v[0-31]+}}.8h, {{v[0-31]+}}.8b, {{v[0-31]+}}.8b
}
int32x4_t test_vmlal_s16(int32x4_t a, int16x4_t b, int16x4_t c) {
  // CHECK: test_vmlal_s16
  return vmlal_s16(a, b, c);
  // CHECK: smlal {{v[0-31]+}}.4s, {{v[0-31]+}}.4h, {{v[0-31]+}}.4h
}
int64x2_t test_vmlal_s32(int64x2_t a, int32x2_t b, int32x2_t c) {
  // CHECK: test_vmlal_s32
  return vmlal_s32(a, b, c);
  // CHECK: smlal {{v[0-31]+}}.2d, {{v[0-31]+}}.2s, {{v[0-31]+}}.2s
}
uint16x8_t test_vmlal_u8(uint16x8_t a, uint8x8_t b, uint8x8_t c) {
  // CHECK: test_vmlal_u8
  return vmlal_u8(a, b, c);
  // CHECK: umlal {{v[0-31]+}}.8h, {{v[0-31]+}}.8b, {{v[0-31]+}}.8b
}
uint32x4_t test_vmlal_u16(uint32x4_t a, uint16x4_t b, uint16x4_t c) {
  // CHECK: test_vmlal_u16
  return vmlal_u16(a, b, c);
  // CHECK: umlal {{v[0-31]+}}.4s, {{v[0-31]+}}.4h, {{v[0-31]+}}.4h
}
uint64x2_t test_vmlal_u32(uint64x2_t a, uint32x2_t b, uint32x2_t c) {
  // CHECK: test_vmlal_u32
  return vmlal_u32(a, b, c);
  // CHECK: umlal {{v[0-31]+}}.2d, {{v[0-31]+}}.2s, {{v[0-31]+}}.2s
}

int16x8_t test_vmlal_high_s8(int16x8_t a, int8x16_t b, int8x16_t c) {
  // CHECK: test_vmlal_high_s8
  return vmlal_high_s8(a, b, c);
  // CHECK: smlal2 {{v[0-31]+}}.8h, {{v[0-31]+}}.16b, {{v[0-31]+}}.16b
}
int32x4_t test_vmlal_high_s16(int32x4_t a, int16x8_t b, int16x8_t c) {
  // CHECK: test_vmlal_high_s16
  return vmlal_high_s16(a, b, c);
  // CHECK: smlal2 {{v[0-31]+}}.4s, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}
int64x2_t test_vmlal_high_s32(int64x2_t a, int32x4_t b, int32x4_t c) {
  // CHECK: test_vmlal_high_s32
  return vmlal_high_s32(a, b, c);
  // CHECK: smlal2 {{v[0-31]+}}.2d, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}
uint16x8_t test_vmlal_high_u8(uint16x8_t a, uint8x16_t b, uint8x16_t c) {
  // CHECK: test_vmlal_high_u8
  return vmlal_high_u8(a, b, c);
  // CHECK: umlal2 {{v[0-31]+}}.8h, {{v[0-31]+}}.16b, {{v[0-31]+}}.16b
}
uint32x4_t test_vmlal_high_u16(uint32x4_t a, uint16x8_t b, uint16x8_t c) {
  // CHECK: test_vmlal_high_u16
  return vmlal_high_u16(a, b, c);
  // CHECK: umlal2 {{v[0-31]+}}.4s, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}
uint64x2_t test_vmlal_high_u32(uint64x2_t a, uint32x4_t b, uint32x4_t c) {
  // CHECK: test_vmlal_high_u32
  return vmlal_high_u32(a, b, c);
  // CHECK: umlal2 {{v[0-31]+}}.2d, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}

int16x8_t test_vmlsl_s8(int16x8_t a, int8x8_t b, int8x8_t c) {
  // CHECK: test_vmlsl_s8
  return vmlsl_s8(a, b, c);
  // CHECK: smlsl {{v[0-31]+}}.8h, {{v[0-31]+}}.8b, {{v[0-31]+}}.8b
}
int32x4_t test_vmlsl_s16(int32x4_t a, int16x4_t b, int16x4_t c) {
  // CHECK: test_vmlsl_s16
  return vmlsl_s16(a, b, c);
  // CHECK: smlsl {{v[0-31]+}}.4s, {{v[0-31]+}}.4h, {{v[0-31]+}}.4h
}
int64x2_t test_vmlsl_s32(int64x2_t a, int32x2_t b, int32x2_t c) {
  // CHECK: test_vmlsl_s32
  return vmlsl_s32(a, b, c);
  // CHECK: smlsl {{v[0-31]+}}.2d, {{v[0-31]+}}.2s, {{v[0-31]+}}.2s
}
uint16x8_t test_vmlsl_u8(uint16x8_t a, uint8x8_t b, uint8x8_t c) {
  // CHECK: test_vmlsl_u8
  return vmlsl_u8(a, b, c);
  // CHECK: umlsl {{v[0-31]+}}.8h, {{v[0-31]+}}.8b, {{v[0-31]+}}.8b
}
uint32x4_t test_vmlsl_u16(uint32x4_t a, uint16x4_t b, uint16x4_t c) {
  // CHECK: test_vmlsl_u16
  return vmlsl_u16(a, b, c);
  // CHECK: umlsl {{v[0-31]+}}.4s, {{v[0-31]+}}.4h, {{v[0-31]+}}.4h
}
uint64x2_t test_vmlsl_u32(uint64x2_t a, uint32x2_t b, uint32x2_t c) {
  // CHECK: test_vmlsl_u32
  return vmlsl_u32(a, b, c);
  // CHECK: umlsl {{v[0-31]+}}.2d, {{v[0-31]+}}.2s, {{v[0-31]+}}.2s
}

int16x8_t test_vmlsl_high_s8(int16x8_t a, int8x16_t b, int8x16_t c) {
  // CHECK: test_vmlsl_high_s8
  return vmlsl_high_s8(a, b, c);
  // CHECK: smlsl2 {{v[0-31]+}}.8h, {{v[0-31]+}}.16b, {{v[0-31]+}}.16b
}
int32x4_t test_vmlsl_high_s16(int32x4_t a, int16x8_t b, int16x8_t c) {
  // CHECK: test_vmlsl_high_s16
  return vmlsl_high_s16(a, b, c);
  // CHECK: smlsl2 {{v[0-31]+}}.4s, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}
int64x2_t test_vmlsl_high_s32(int64x2_t a, int32x4_t b, int32x4_t c) {
  // CHECK: test_vmlsl_high_s32
  return vmlsl_high_s32(a, b, c);
  // CHECK: smlsl2 {{v[0-31]+}}.2d, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}
uint16x8_t test_vmlsl_high_u8(uint16x8_t a, uint8x16_t b, uint8x16_t c) {
  // CHECK: test_vmlsl_high_u8
  return vmlsl_high_u8(a, b, c);
  // CHECK: umlsl2 {{v[0-31]+}}.8h, {{v[0-31]+}}.16b, {{v[0-31]+}}.16b
}
uint32x4_t test_vmlsl_high_u16(uint32x4_t a, uint16x8_t b, uint16x8_t c) {
  // CHECK: test_vmlsl_high_u16
  return vmlsl_high_u16(a, b, c);
  // CHECK: umlsl2 {{v[0-31]+}}.4s, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}
uint64x2_t test_vmlsl_high_u32(uint64x2_t a, uint32x4_t b, uint32x4_t c) {
  // CHECK: test_vmlsl_high_u32
  return vmlsl_high_u32(a, b, c);
  // CHECK: umlsl2 {{v[0-31]+}}.2d, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}

int32x4_t test_vqdmull_s16(int16x4_t a, int16x4_t b) {
  // CHECK: test_vqdmull_s16
  return vqdmull_s16(a, b);
  // CHECK: sqdmull {{v[0-31]+}}.4s, {{v[0-31]+}}.4h, {{v[0-31]+}}.4h
}
int64x2_t test_vqdmull_s32(int32x2_t a, int32x2_t b) {
  // CHECK: test_vqdmull_s32
  return vqdmull_s32(a, b);
  // CHECK: sqdmull {{v[0-31]+}}.2d, {{v[0-31]+}}.2s, {{v[0-31]+}}.2s
}

int32x4_t test_vqdmlal_s16(int32x4_t a, int16x4_t b, int16x4_t c) {
  // CHECK: test_vqdmlal_s16
  return vqdmlal_s16(a, b, c);
  // CHECK: sqdmlal {{v[0-31]+}}.4s, {{v[0-31]+}}.4h, {{v[0-31]+}}.4h
}

int64x2_t test_vqdmlal_s32(int64x2_t a, int32x2_t b, int32x2_t c) {
  // CHECK: test_vqdmlal_s32
  return vqdmlal_s32(a, b, c);
  // CHECK: sqdmlal {{v[0-31]+}}.2d, {{v[0-31]+}}.2s, {{v[0-31]+}}.2s
}

int32x4_t test_vqdmlsl_s16(int32x4_t a, int16x4_t b, int16x4_t c) {
  // CHECK: test_vqdmlsl_s16
  return vqdmlsl_s16(a, b, c);
  // CHECK: sqdmlsl {{v[0-31]+}}.4s, {{v[0-31]+}}.4h, {{v[0-31]+}}.4h
}

int64x2_t test_vqdmlsl_s32(int64x2_t a, int32x2_t b, int32x2_t c) {
  // CHECK: test_vqdmlsl_s32
  return vqdmlsl_s32(a, b, c);
  // CHECK: sqdmlsl {{v[0-31]+}}.2d, {{v[0-31]+}}.2s, {{v[0-31]+}}.2s
}

int32x4_t test_vqdmull_high_s16(int16x8_t a, int16x8_t b) {
  // CHECK: test_vqdmull_high_s16
  return vqdmull_high_s16(a, b);
  // CHECK: sqdmull2 {{v[0-31]+}}.4s, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}
int64x2_t test_vqdmull_high_s32(int32x4_t a, int32x4_t b) {
  // CHECK: test_vqdmull_high_s32
  return vqdmull_high_s32(a, b);
  // CHECK: sqdmull2 {{v[0-31]+}}.2d, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}

int32x4_t test_vqdmlal_high_s16(int32x4_t a, int16x8_t b, int16x8_t c) {
  // CHECK: test_vqdmlal_high_s16
  return vqdmlal_high_s16(a, b, c);
  // CHECK: sqdmlal2 {{v[0-31]+}}.4s, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}

int64x2_t test_vqdmlal_high_s32(int64x2_t a, int32x4_t b, int32x4_t c) {
  // CHECK: test_vqdmlal_high_s32
  return vqdmlal_high_s32(a, b, c);
  // CHECK: sqdmlal2 {{v[0-31]+}}.2d, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}

int32x4_t test_vqdmlsl_high_s16(int32x4_t a, int16x8_t b, int16x8_t c) {
  // CHECK: test_vqdmlsl_high_s16
  return vqdmlsl_high_s16(a, b, c);
  // CHECK: sqdmlsl2 {{v[0-31]+}}.4s, {{v[0-31]+}}.8h, {{v[0-31]+}}.8h
}

int64x2_t test_vqdmlsl_high_s32(int64x2_t a, int32x4_t b, int32x4_t c) {
  // CHECK: test_vqdmlsl_high_s32
  return vqdmlsl_high_s32(a, b, c);
  // CHECK: sqdmlsl2 {{v[0-31]+}}.2d, {{v[0-31]+}}.4s, {{v[0-31]+}}.4s
}

poly16x8_t test_vmull_p8(poly8x8_t a, poly8x8_t b) {
  // CHECK: test_vmull_p8
  return vmull_p8(a, b);
  // CHECK: pmull {{v[0-31]+}}.8h, {{v[0-31]+}}.8b, {{v[0-31]+}}.8b
}

poly16x8_t test_vmull_high_p8(poly8x16_t a, poly8x16_t b) {
  // CHECK: test_vmull_high_p8
  return vmull_high_p8(a, b);
  // CHECK: pmull2 {{v[0-31]+}}.8h, {{v[0-31]+}}.16b, {{v[0-31]+}}.16b
}

int64_t test_vaddd_s64(int64_t a, int64_t b) {
// CHECK: test_vaddd_s64
  return vaddd_s64(a, b);
// CHECK: add {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

uint64_t test_vaddd_u64(uint64_t a, uint64_t b) {
// CHECK: test_vaddd_u64
  return vaddd_u64(a, b);
// CHECK: add {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

int64_t test_vsubd_s64(int64_t a, int64_t b) {
// CHECK: test_vsubd_s64
  return vsubd_s64(a, b);
// CHECK: sub {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

uint64_t test_vsubd_u64(uint64_t a, uint64_t b) {
// CHECK: test_vsubd_u64
  return vsubd_u64(a, b);
// CHECK: sub {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

int8_t test_vqaddb_s8(int8_t a, int8_t b) {
// CHECK: test_vqaddb_s8
  return vqaddb_s8(a, b);
// CHECK: sqadd {{b[0-9]+}}, {{b[0-9]+}}, {{b[0-9]+}}
}

int16_t test_vqaddh_s16(int16_t a, int16_t b) {
// CHECK: test_vqaddh_s16
  return vqaddh_s16(a, b);
// CHECK: sqadd {{h[0-9]+}}, {{h[0-9]+}}, {{h[0-9]+}}
}

int32_t test_vqadds_s32(int32_t a, int32_t b) {
// CHECK: test_vqadds_s32
  return vqadds_s32(a, b);
// CHECK: sqadd {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
}

int64_t test_vqaddd_s64(int64_t a, int64_t b) {
// CHECK: test_vqaddd_s64
  return vqaddd_s64(a, b);
// CHECK: sqadd {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

uint8_t test_vqaddb_u8(uint8_t a, uint8_t b) {
// CHECK: test_vqaddb_u8
  return vqaddb_u8(a, b);
// CHECK: uqadd {{b[0-9]+}}, {{b[0-9]+}}, {{b[0-9]+}}
}

uint16_t test_vqaddh_u16(uint16_t a, uint16_t b) {
// CHECK: test_vqaddh_u16
  return vqaddh_u16(a, b);
// CHECK: uqadd {{h[0-9]+}}, {{h[0-9]+}}, {{h[0-9]+}}
}

uint32_t test_vqadds_u32(uint32_t a, uint32_t b) {
// CHECK: test_vqadds_u32
  return vqadds_u32(a, b);
// CHECK: uqadd {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
}

uint64_t test_vqaddd_u64(uint64_t a, uint64_t b) {
// CHECK: test_vqaddd_u64
  return vqaddd_u64(a, b);
// CHECK: uqadd {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

int8_t test_vqsubb_s8(int8_t a, int8_t b) {
// CHECK: test_vqsubb_s8
  return vqsubb_s8(a, b);
// CHECK: sqsub {{b[0-9]+}}, {{b[0-9]+}}, {{b[0-9]+}}
}

int16_t test_vqsubh_s16(int16_t a, int16_t b) {
// CHECK: test_vqsubh_s16
  return vqsubh_s16(a, b);
// CHECK: sqsub {{h[0-9]+}}, {{h[0-9]+}}, {{h[0-9]+}}
}

int32_t test_vqsubs_s32(int32_t a, int32_t b) {
  // CHECK: test_vqsubs_s32
  return vqsubs_s32(a, b);
// CHECK: sqsub {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
}

int64_t test_vqsubd_s64(int64_t a, int64_t b) {
// CHECK: test_vqsubd_s64
  return vqsubd_s64(a, b);
// CHECK: sqsub {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

uint8_t test_vqsubb_u8(uint8_t a, uint8_t b) {
// CHECK: test_vqsubb_u8
  return vqsubb_u8(a, b);
// CHECK: uqsub {{b[0-9]+}}, {{b[0-9]+}}, {{b[0-9]+}}
}

uint16_t test_vqsubh_u16(uint16_t a, uint16_t b) {
// CHECK: test_vqsubh_u16
  return vqsubh_u16(a, b);
// CHECK: uqsub {{h[0-9]+}}, {{h[0-9]+}}, {{h[0-9]+}}
}

uint32_t test_vqsubs_u32(uint32_t a, uint32_t b) {
// CHECK: test_vqsubs_u32
  return vqsubs_u32(a, b);
// CHECK: uqsub {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
}

uint64_t test_vqsubd_u64(uint64_t a, uint64_t b) {
// CHECK: test_vqsubd_u64
  return vqsubd_u64(a, b);
// CHECK: uqsub {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

int64_t test_vshld_s64(int64_t a, int64_t b) {
// CHECK: test_vshld_s64
  return vshld_s64(a, b);
// CHECK: sshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

uint64_t test_vshld_u64(uint64_t a, uint64_t b) {
// CHECK: test_vshld_u64
  return vshld_u64(a, b);
// CHECK: ushl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

// CHECK: test_vqshlb_s8
int8_t test_vqshlb_s8(int8_t a, int8_t b) {
  return vqshlb_s8(a, b);
// CHECK: sqshl {{b[0-9]+}}, {{b[0-9]+}}, {{b[0-9]+}}
}

// CHECK: test_vqshlh_s16
int16_t test_vqshlh_s16(int16_t a, int16_t b) {
  return vqshlh_s16(a, b);
// CHECK: sqshl {{h[0-9]+}}, {{h[0-9]+}}, {{h[0-9]+}}
}

// CHECK: test_vqshls_s32
int32_t test_vqshls_s32(int32_t a, int32_t b) {
  return vqshls_s32(a, b);
// CHECK: sqshl {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
}

// CHECK: test_vqshld_s64
int64_t test_vqshld_s64(int64_t a, int64_t b) {
  return vqshld_s64(a, b);
// CHECK: sqshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

// CHECK: test_vqshlb_u8
uint8_t test_vqshlb_u8(uint8_t a, uint8_t b) {
  return vqshlb_u8(a, b);
// CHECK: uqshl {{b[0-9]+}}, {{b[0-9]+}}, {{b[0-9]+}}
}

// CHECK: test_vqshlh_u16
uint16_t test_vqshlh_u16(uint16_t a, uint16_t b) {
  return vqshlh_u16(a, b);
// CHECK: uqshl {{h[0-9]+}}, {{h[0-9]+}}, {{h[0-9]+}}
}

// CHECK: test_vqshls_u32
uint32_t test_vqshls_u32(uint32_t a, uint32_t b) {
  return vqshls_u32(a, b);
// CHECK: uqshl {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
}

// CHECK: test_vqshld_u64
uint64_t test_vqshld_u64(uint64_t a, uint64_t b) {
  return vqshld_u64(a, b);
// CHECK: uqshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

// CHECK: test_vrshld_s64
int64_t test_vrshld_s64(int64_t a, int64_t b) {
  return vrshld_s64(a, b);
// CHECK: srshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}


// CHECK: test_vrshld_u64
uint64_t test_vrshld_u64(uint64_t a, uint64_t b) {
  return vrshld_u64(a, b);
// CHECK: urshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

// CHECK: test_vqrshlb_s8
int8_t test_vqrshlb_s8(int8_t a, int8_t b) {
  return vqrshlb_s8(a, b);
// CHECK: sqrshl {{b[0-9]+}}, {{b[0-9]+}}, {{b[0-9]+}}
}

// CHECK: test_vqrshlh_s16
int16_t test_vqrshlh_s16(int16_t a, int16_t b) {
  return vqrshlh_s16(a, b);
// CHECK: sqrshl {{h[0-9]+}}, {{h[0-9]+}}, {{h[0-9]+}}
}

// CHECK: test_vqrshls_s32
int32_t test_vqrshls_s32(int32_t a, int32_t b) {
  return vqrshls_s32(a, b);
// CHECK: sqrshl {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
}

// CHECK: test_vqrshld_s64
int64_t test_vqrshld_s64(int64_t a, int64_t b) {
  return vqrshld_s64(a, b);
// CHECK: sqrshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

// CHECK: test_vqrshlb_u8
uint8_t test_vqrshlb_u8(uint8_t a, uint8_t b) {
  return vqrshlb_u8(a, b);
// CHECK: uqrshl {{b[0-9]+}}, {{b[0-9]+}}, {{b[0-9]+}}
}

// CHECK: test_vqrshlh_u16
uint16_t test_vqrshlh_u16(uint16_t a, uint16_t b) {
  return vqrshlh_u16(a, b);
// CHECK: uqrshl {{h[0-9]+}}, {{h[0-9]+}}, {{h[0-9]+}}
}

// CHECK: test_vqrshls_u32
uint32_t test_vqrshls_u32(uint32_t a, uint32_t b) {
  return vqrshls_u32(a, b);
// CHECK: uqrshl {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
}

// CHECK: test_vqrshld_u64
uint64_t test_vqrshld_u64(uint64_t a, uint64_t b) {
  return vqrshld_u64(a, b);
// CHECK: uqrshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

// CHECK: test_vpaddd_s64
int64_t test_vpaddd_s64(int64x2_t a) {
  return vpaddd_s64(a);
// CHECK: addp {{d[0-9]+}}, {{v[0-9]+}}.2d
}

// CHECK: test_vpadds_f32
float32_t test_vpadds_f32(float32x2_t a) {
  return vpadds_f32(a);
// CHECK: faddp {{s[0-9]+}}, {{v[0-9]+}}.2s
}

// CHECK: test_vpaddd_f64
float64_t test_vpaddd_f64(float64x2_t a) {
  return vpaddd_f64(a);
// CHECK: faddp {{d[0-9]+}}, {{v[0-9]+}}.2d
}

// CHECK: test_vpmaxnms_f32
float32_t test_vpmaxnms_f32(float32x2_t a) {
  return vpmaxnms_f32(a);
// CHECK: fmaxnmp {{s[0-9]+}}, {{v[0-9]+}}.2s
}

// CHECK: test_vpmaxnmqd_f64
float64_t test_vpmaxnmqd_f64(float64x2_t a) {
  return vpmaxnmqd_f64(a);
// CHECK: fmaxnmp {{d[0-9]+}}, {{v[0-9]+}}.2d
}

// CHECK: test_vpmaxs_f32
float32_t test_vpmaxs_f32(float32x2_t a) {
  return vpmaxs_f32(a);
// CHECK: fmaxp {{s[0-9]+}}, {{v[0-9]+}}.2s
}

// CHECK: test_vpmaxqd_f64
float64_t test_vpmaxqd_f64(float64x2_t a) {
  return vpmaxqd_f64(a);
// CHECK: fmaxp {{d[0-9]+}}, {{v[0-9]+}}.2d
}

// CHECK: test_vpminnms_f32
float32_t test_vpminnms_f32(float32x2_t a) {
  return vpminnms_f32(a);
// CHECK: fminnmp {{s[0-9]+}}, {{v[0-9]+}}.2s
}

// CHECK: test_vpminnmqd_f64
float64_t test_vpminnmqd_f64(float64x2_t a) {
  return vpminnmqd_f64(a);
// CHECK: fminnmp {{d[0-9]+}}, {{v[0-9]+}}.2d
}

// CHECK: test_vpmins_f32
float32_t test_vpmins_f32(float32x2_t a) {
  return vpmins_f32(a);
// CHECK: fminp {{s[0-9]+}}, {{v[0-9]+}}.2s
}

// CHECK: test_vpminqd_f64
float64_t test_vpminqd_f64(float64x2_t a) {
  return vpminqd_f64(a);
// CHECK: fminp {{d[0-9]+}}, {{v[0-9]+}}.2d
}

int16_t test_vqdmulhh_s16(int16_t a, int16_t b) {
// CHECK: test_vqdmulhh_s16
  return vqdmulhh_s16(a, b);
// CHECK: sqdmulh {{h[0-9]+}}, {{h[0-9]+}}, {{h[0-9]+}}
}

int32_t test_vqdmulhs_s32(int32_t a, int32_t b) {
// CHECK: test_vqdmulhs_s32
  return vqdmulhs_s32(a, b);
// CHECK: sqdmulh {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
}

int16_t test_vqrdmulhh_s16(int16_t a, int16_t b) {
// CHECK: test_vqrdmulhh_s16
  return vqrdmulhh_s16(a, b);
// CHECK: sqrdmulh {{h[0-9]+}}, {{h[0-9]+}}, {{h[0-9]+}}
}

int32_t test_vqrdmulhs_s32(int32_t a, int32_t b) {
// CHECK: test_vqrdmulhs_s32
  return vqrdmulhs_s32(a, b);
// CHECK: sqrdmulh {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
}

float32_t test_vmulxs_f32(float32_t a, float32_t b) {
// CHECK: test_vmulxs_f32
  return vmulxs_f32(a, b);
// CHECK: fmulx {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
}

float64_t test_vmulxd_f64(float64_t a, float64_t b) {
// CHECK: test_vmulxd_f64
  return vmulxd_f64(a, b);
// CHECK: fmulx {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

float32_t test_vrecpss_f32(float32_t a, float32_t b) {
// CHECK: test_vrecpss_f32
  return vrecpss_f32(a, b);
// CHECK: frecps {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
}

float64_t test_vrecpsd_f64(float64_t a, float64_t b) {
// CHECK: test_vrecpsd_f64
  return vrecpsd_f64(a, b);
// CHECK: frecps {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

float32_t test_vrsqrtss_f32(float32_t a, float32_t b) {
// CHECK: test_vrsqrtss_f32
  return vrsqrtss_f32(a, b);
// CHECK: frsqrts {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
}

float64_t test_vrsqrtsd_f64(float64_t a, float64_t b) {
// CHECK: test_vrsqrtsd_f64
  return vrsqrtsd_f64(a, b);
// CHECK: frsqrts {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
}

float32_t test_vcvts_f32_s32(int32_t a) {
// CHECK: test_vcvts_f32_s32
// CHECK: scvtf {{s[0-9]+}}, {{s[0-9]+}}
  return (float32_t)vcvts_f32_s32(a);
}

float64_t test_vcvtd_f64_s64(int64_t a) {
// CHECK: test_vcvtd_f64_s64
// CHECK: scvtf {{d[0-9]+}}, {{d[0-9]+}}
  return (float64_t)vcvtd_f64_s64(a);
}

float32_t test_vcvts_f32_u32(uint32_t a) {
// CHECK: test_vcvts_f32_u32
// CHECK: ucvtf {{s[0-9]+}}, {{s[0-9]+}}
  return (float32_t)vcvts_f32_u32(a);
}

float64_t test_vcvtd_f64_u64(uint64_t a) {
// CHECK: test_vcvtd_f64_u64
// CHECK: ucvtf {{d[0-9]+}}, {{d[0-9]+}}
  return (float64_t)vcvtd_f64_u64(a);
}

float32_t test_vrecpes_f32(float32_t a) {
// CHECK: test_vrecpes_f32
// CHECK: frecpe {{s[0-9]+}}, {{s[0-9]+}}
  return vrecpes_f32(a);
}
 
float64_t test_vrecped_f64(float64_t a) {
// CHECK: test_vrecped_f64
// CHECK: frecpe {{d[0-9]+}}, {{d[0-9]+}}
  return vrecped_f64(a);
}
 
float32_t test_vrecpxs_f32(float32_t a) {
// CHECK: test_vrecpxs_f32
// CHECK: frecpx {{s[0-9]+}}, {{s[0-9]+}}
  return vrecpxs_f32(a);
 }
 
float64_t test_vrecpxd_f64(float64_t a) {
// CHECK: test_vrecpxd_f64
// CHECK: frecpx {{d[0-9]+}}, {{d[0-9]+}}
  return vrecpxd_f64(a);
}

float32_t test_vrsqrtes_f32(float32_t a) {
// CHECK: vrsqrtes_f32
// CHECK: frsqrte {{s[0-9]+}}, {{s[0-9]+}}
  return vrsqrtes_f32(a);
}

float64_t test_vrsqrted_f64(float64_t a) {
// CHECK: vrsqrted_f64
// CHECK: frsqrte {{d[0-9]+}}, {{d[0-9]+}}
  return vrsqrted_f64(a);
}

uint8x16_t test_vld1q_u8(uint8_t const *a) {
  // CHECK: test_vld1q_u8
  return vld1q_u8(a);
  // CHECK: ld1 {v{{[0-9]+}}.16b}, [{{x[0-9]+|sp}}]
}

uint16x8_t test_vld1q_u16(uint16_t const *a) {
  // CHECK: test_vld1q_u16
  return vld1q_u16(a);
  // CHECK: ld1 {v{{[0-9]+}}.8h}, [{{x[0-9]+|sp}}]
}

uint32x4_t test_vld1q_u32(uint32_t const *a) {
  // CHECK: test_vld1q_u32
  return vld1q_u32(a);
  // CHECK: ld1 {v{{[0-9]+}}.4s}, [{{x[0-9]+|sp}}]
}

uint64x2_t test_vld1q_u64(uint64_t const *a) {
  // CHECK: test_vld1q_u64
  return vld1q_u64(a);
  // CHECK: ld1 {v{{[0-9]+}}.2d}, [{{x[0-9]+|sp}}]
}

int8x16_t test_vld1q_s8(int8_t const *a) {
  // CHECK: test_vld1q_s8
  return vld1q_s8(a);
  // CHECK: ld1 {v{{[0-9]+}}.16b}, [{{x[0-9]+|sp}}]
}

int16x8_t test_vld1q_s16(int16_t const *a) {
  // CHECK: test_vld1q_s16
  return vld1q_s16(a);
  // CHECK: ld1 {v{{[0-9]+}}.8h}, [{{x[0-9]+|sp}}]
}

int32x4_t test_vld1q_s32(int32_t const *a) {
  // CHECK: test_vld1q_s32
  return vld1q_s32(a);
  // CHECK: ld1 {v{{[0-9]+}}.4s}, [{{x[0-9]+|sp}}]
}

int64x2_t test_vld1q_s64(int64_t const *a) {
  // CHECK: test_vld1q_s64
  return vld1q_s64(a);
  // CHECK: ld1 {v{{[0-9]+}}.2d}, [{{x[0-9]+|sp}}]
}

float16x8_t test_vld1q_f16(float16_t const *a) {
  // CHECK: test_vld1q_f16
  return vld1q_f16(a);
  // CHECK: ld1 {v{{[0-9]+}}.8h}, [{{x[0-9]+|sp}}]
}

float32x4_t test_vld1q_f32(float32_t const *a) {
  // CHECK: test_vld1q_f32
  return vld1q_f32(a);
  // CHECK: ld1 {v{{[0-9]+}}.4s}, [{{x[0-9]+|sp}}]
}

float64x2_t test_vld1q_f64(float64_t const *a) {
  // CHECK: test_vld1q_f64
  return vld1q_f64(a);
  // CHECK: ld1 {v{{[0-9]+}}.2d}, [{{x[0-9]+|sp}}]
}

poly8x16_t test_vld1q_p8(poly8_t const *a) {
  // CHECK: test_vld1q_p8
  return vld1q_p8(a);
  // CHECK: ld1 {v{{[0-9]+}}.16b}, [{{x[0-9]+|sp}}]
}

poly16x8_t test_vld1q_p16(poly16_t const *a) {
  // CHECK: test_vld1q_p16
  return vld1q_p16(a);
  // CHECK: ld1 {v{{[0-9]+}}.8h}, [{{x[0-9]+|sp}}]
}

uint8x8_t test_vld1_u8(uint8_t const *a) {
  // CHECK: test_vld1_u8
  return vld1_u8(a);
  // CHECK: ld1 {v{{[0-9]+}}.8b}, [{{x[0-9]+|sp}}]
}

uint16x4_t test_vld1_u16(uint16_t const *a) {
  // CHECK: test_vld1_u16
  return vld1_u16(a);
  // CHECK: ld1 {v{{[0-9]+}}.4h}, [{{x[0-9]+|sp}}]
}

uint32x2_t test_vld1_u32(uint32_t const *a) {
  // CHECK: test_vld1_u32
  return vld1_u32(a);
  // CHECK: ld1 {v{{[0-9]+}}.2s}, [{{x[0-9]+|sp}}]
}

uint64x1_t test_vld1_u64(uint64_t const *a) {
  // CHECK: test_vld1_u64
  return vld1_u64(a);
  // CHECK: ld1 {v{{[0-9]+}}.1d}, [{{x[0-9]+|sp}}]
}

int8x8_t test_vld1_s8(int8_t const *a) {
  // CHECK: test_vld1_s8
  return vld1_s8(a);
  // CHECK: ld1 {v{{[0-9]+}}.8b}, [{{x[0-9]+|sp}}]
}

int16x4_t test_vld1_s16(int16_t const *a) {
  // CHECK: test_vld1_s16
  return vld1_s16(a);
  // CHECK: ld1 {v{{[0-9]+}}.4h}, [{{x[0-9]+|sp}}]
}

int32x2_t test_vld1_s32(int32_t const *a) {
  // CHECK: test_vld1_s32
  return vld1_s32(a);
  // CHECK: ld1 {v{{[0-9]+}}.2s}, [{{x[0-9]+|sp}}]
}

int64x1_t test_vld1_s64(int64_t const *a) {
  // CHECK: test_vld1_s64
  return vld1_s64(a);
  // CHECK: ld1 {v{{[0-9]+}}.1d}, [{{x[0-9]+|sp}}]
}

float16x4_t test_vld1_f16(float16_t const *a) {
  // CHECK: test_vld1_f16
  return vld1_f16(a);
  // CHECK: ld1 {v{{[0-9]+}}.4h}, [{{x[0-9]+|sp}}]
}

float32x2_t test_vld1_f32(float32_t const *a) {
  // CHECK: test_vld1_f32
  return vld1_f32(a);
  // CHECK: ld1 {v{{[0-9]+}}.2s}, [{{x[0-9]+|sp}}]
}

float64x1_t test_vld1_f64(float64_t const *a) {
  // CHECK: test_vld1_f64
  return vld1_f64(a);
  // CHECK: ld1 {v{{[0-9]+}}.1d}, [{{x[0-9]+|sp}}]
}

poly8x8_t test_vld1_p8(poly8_t const *a) {
  // CHECK: test_vld1_p8
  return vld1_p8(a);
  // CHECK: ld1 {v{{[0-9]+}}.8b}, [{{x[0-9]+|sp}}]
}

poly16x4_t test_vld1_p16(poly16_t const *a) {
  // CHECK: test_vld1_p16
  return vld1_p16(a);
  // CHECK: ld1 {v{{[0-9]+}}.4h}, [{{x[0-9]+|sp}}]
}

uint8x16x2_t test_vld2q_u8(uint8_t const *a) {
  // CHECK: test_vld2q_u8
  return vld2q_u8(a);
  // CHECK: ld2 {v{{[0-9]+}}.16b, v{{[0-9]+}}.16b}, [{{x[0-9]+|sp}}]
}

uint16x8x2_t test_vld2q_u16(uint16_t const *a) {
  // CHECK: test_vld2q_u16
  return vld2q_u16(a);
  // CHECK: ld2 {v{{[0-9]+}}.8h, v{{[0-9]+}}.8h}, [{{x[0-9]+|sp}}]
}

uint32x4x2_t test_vld2q_u32(uint32_t const *a) {
  // CHECK: test_vld2q_u32
  return vld2q_u32(a);
  // CHECK: ld2 {v{{[0-9]+}}.4s, v{{[0-9]+}}.4s}, [{{x[0-9]+|sp}}]
}

uint64x2x2_t test_vld2q_u64(uint64_t const *a) {
  // CHECK: test_vld2q_u64
  return vld2q_u64(a);
  // CHECK: ld2 {v{{[0-9]+}}.2d, v{{[0-9]+}}.2d}, [{{x[0-9]+|sp}}]
}

int8x16x2_t test_vld2q_s8(int8_t const *a) {
  // CHECK: test_vld2q_s8
  return vld2q_s8(a);
  // CHECK: ld2 {v{{[0-9]+}}.16b, v{{[0-9]+}}.16b}, [{{x[0-9]+|sp}}]
}

int16x8x2_t test_vld2q_s16(int16_t const *a) {
  // CHECK: test_vld2q_s16
  return vld2q_s16(a);
  // CHECK: ld2 {v{{[0-9]+}}.8h, v{{[0-9]+}}.8h}, [{{x[0-9]+|sp}}]
}

int32x4x2_t test_vld2q_s32(int32_t const *a) {
  // CHECK: test_vld2q_s32
  return vld2q_s32(a);
  // CHECK: ld2 {v{{[0-9]+}}.4s, v{{[0-9]+}}.4s}, [{{x[0-9]+|sp}}]
}

int64x2x2_t test_vld2q_s64(int64_t const *a) {
  // CHECK: test_vld2q_s64
  return vld2q_s64(a);
  // CHECK: ld2 {v{{[0-9]+}}.2d, v{{[0-9]+}}.2d}, [{{x[0-9]+|sp}}]
}

float16x8x2_t test_vld2q_f16(float16_t const *a) {
  // CHECK: test_vld2q_f16
  return vld2q_f16(a);
  // CHECK: ld2 {v{{[0-9]+}}.8h, v{{[0-9]+}}.8h}, [{{x[0-9]+|sp}}]
}

float32x4x2_t test_vld2q_f32(float32_t const *a) {
  // CHECK: test_vld2q_f32
  return vld2q_f32(a);
  // CHECK: ld2 {v{{[0-9]+}}.4s, v{{[0-9]+}}.4s}, [{{x[0-9]+|sp}}]
}

float64x2x2_t test_vld2q_f64(float64_t const *a) {
  // CHECK: test_vld2q_f64
  return vld2q_f64(a);
  // CHECK: ld2 {v{{[0-9]+}}.2d, v{{[0-9]+}}.2d}, [{{x[0-9]+|sp}}]
}

poly8x16x2_t test_vld2q_p8(poly8_t const *a) {
  // CHECK: test_vld2q_p8
  return vld2q_p8(a);
  // CHECK: ld2 {v{{[0-9]+}}.16b, v{{[0-9]+}}.16b}, [{{x[0-9]+|sp}}]
}

poly16x8x2_t test_vld2q_p16(poly16_t const *a) {
  // CHECK: test_vld2q_p16
  return vld2q_p16(a);
  // CHECK: ld2 {v{{[0-9]+}}.8h, v{{[0-9]+}}.8h}, [{{x[0-9]+|sp}}]
}

uint8x8x2_t test_vld2_u8(uint8_t const *a) {
  // CHECK: test_vld2_u8
  return vld2_u8(a);
  // CHECK: ld2 {v{{[0-9]+}}.8b, v{{[0-9]+}}.8b}, [{{x[0-9]+|sp}}]
}

uint16x4x2_t test_vld2_u16(uint16_t const *a) {
  // CHECK: test_vld2_u16
  return vld2_u16(a);
  // CHECK: ld2 {v{{[0-9]+}}.4h, v{{[0-9]+}}.4h}, [{{x[0-9]+|sp}}]
}

uint32x2x2_t test_vld2_u32(uint32_t const *a) {
  // CHECK: test_vld2_u32
  return vld2_u32(a);
  // CHECK: ld2 {v{{[0-9]+}}.2s, v{{[0-9]+}}.2s}, [{{x[0-9]+|sp}}]
}

uint64x1x2_t test_vld2_u64(uint64_t const *a) {
  // CHECK: test_vld2_u64
  return vld2_u64(a);
  // CHECK: ld1 {v{{[0-9]+}}.1d, v{{[0-9]+}}.1d}, [{{x[0-9]+|sp}}]
}

int8x8x2_t test_vld2_s8(int8_t const *a) {
  // CHECK: test_vld2_s8
  return vld2_s8(a);
  // CHECK: ld2 {v{{[0-9]+}}.8b, v{{[0-9]+}}.8b}, [{{x[0-9]+|sp}}]
}

int16x4x2_t test_vld2_s16(int16_t const *a) {
  // CHECK: test_vld2_s16
  return vld2_s16(a);
  // CHECK: ld2 {v{{[0-9]+}}.4h, v{{[0-9]+}}.4h}, [{{x[0-9]+|sp}}]
}

int32x2x2_t test_vld2_s32(int32_t const *a) {
  // CHECK: test_vld2_s32
  return vld2_s32(a);
  // CHECK: ld2 {v{{[0-9]+}}.2s, v{{[0-9]+}}.2s}, [{{x[0-9]+|sp}}]
}

int64x1x2_t test_vld2_s64(int64_t const *a) {
  // CHECK: test_vld2_s64
  return vld2_s64(a);
  // CHECK: ld1 {v{{[0-9]+}}.1d, v{{[0-9]+}}.1d}, [{{x[0-9]+|sp}}]
}

float16x4x2_t test_vld2_f16(float16_t const *a) {
  // CHECK: test_vld2_f16
  return vld2_f16(a);
  // CHECK: ld2 {v{{[0-9]+}}.4h, v{{[0-9]+}}.4h}, [{{x[0-9]+|sp}}]
}

float32x2x2_t test_vld2_f32(float32_t const *a) {
  // CHECK: test_vld2_f32
  return vld2_f32(a);
  // CHECK: ld2 {v{{[0-9]+}}.2s, v{{[0-9]+}}.2s}, [{{x[0-9]+|sp}}]
}

float64x1x2_t test_vld2_f64(float64_t const *a) {
  // CHECK: test_vld2_f64
  return vld2_f64(a);
  // CHECK: ld1 {v{{[0-9]+}}.1d, v{{[0-9]+}}.1d}, [{{x[0-9]+|sp}}]
}

poly8x8x2_t test_vld2_p8(poly8_t const *a) {
  // CHECK: test_vld2_p8
  return vld2_p8(a);
  // CHECK: ld2 {v{{[0-9]+}}.8b, v{{[0-9]+}}.8b}, [{{x[0-9]+|sp}}]
}

poly16x4x2_t test_vld2_p16(poly16_t const *a) {
  // CHECK: test_vld2_p16
  return vld2_p16(a);
  // CHECK: ld2 {v{{[0-9]+}}.4h, v{{[0-9]+}}.4h}, [{{x[0-9]+|sp}}]
}

uint8x16x3_t test_vld3q_u8(uint8_t const *a) {
  // CHECK: test_vld3q_u8
  return vld3q_u8(a);
  // CHECK: ld3 {v{{[0-9]+}}.16b, v{{[0-9]+}}.16b, v{{[0-9]+}}.16b},
  // [{{x[0-9]+|sp}}]
}

uint16x8x3_t test_vld3q_u16(uint16_t const *a) {
  // CHECK: test_vld3q_u16
  return vld3q_u16(a);
  // CHECK: ld3 {v{{[0-9]+}}.8h, v{{[0-9]+}}.8h, v{{[0-9]+}}.8h},
  // [{{x[0-9]+|sp}}]
}

uint32x4x3_t test_vld3q_u32(uint32_t const *a) {
  // CHECK: test_vld3q_u32
  return vld3q_u32(a);
  // CHECK: ld3 {v{{[0-9]+}}.4s, v{{[0-9]+}}.4s, v{{[0-9]+}}.4s},
  // [{{x[0-9]+|sp}}]
}

uint64x2x3_t test_vld3q_u64(uint64_t const *a) {
  // CHECK: test_vld3q_u64
  return vld3q_u64(a);
  // CHECK: ld3 {v{{[0-9]+}}.2d, v{{[0-9]+}}.2d, v{{[0-9]+}}.2d},
  // [{{x[0-9]+|sp}}]
}

int8x16x3_t test_vld3q_s8(int8_t const *a) {
  // CHECK: test_vld3q_s8
  return vld3q_s8(a);
  // CHECK: ld3 {v{{[0-9]+}}.16b, v{{[0-9]+}}.16b, v{{[0-9]+}}.16b},
  // [{{x[0-9]+|sp}}]
}

int16x8x3_t test_vld3q_s16(int16_t const *a) {
  // CHECK: test_vld3q_s16
  return vld3q_s16(a);
  // CHECK: ld3 {v{{[0-9]+}}.8h, v{{[0-9]+}}.8h, v{{[0-9]+}}.8h},
  // [{{x[0-9]+|sp}}]
}

int32x4x3_t test_vld3q_s32(int32_t const *a) {
  // CHECK: test_vld3q_s32
  return vld3q_s32(a);
  // CHECK: ld3 {v{{[0-9]+}}.4s, v{{[0-9]+}}.4s, v{{[0-9]+}}.4s},
  // [{{x[0-9]+|sp}}]
}

int64x2x3_t test_vld3q_s64(int64_t const *a) {
  // CHECK: test_vld3q_s64
  return vld3q_s64(a);
  // CHECK: ld3 {v{{[0-9]+}}.2d, v{{[0-9]+}}.2d, v{{[0-9]+}}.2d},
  // [{{x[0-9]+|sp}}]
}

float16x8x3_t test_vld3q_f16(float16_t const *a) {
  // CHECK: test_vld3q_f16
  return vld3q_f16(a);
  // CHECK: ld3 {v{{[0-9]+}}.8h, v{{[0-9]+}}.8h, v{{[0-9]+}}.8h},
  // [{{x[0-9]+|sp}}]
}

float32x4x3_t test_vld3q_f32(float32_t const *a) {
  // CHECK: test_vld3q_f32
  return vld3q_f32(a);
  // CHECK: ld3 {v{{[0-9]+}}.4s, v{{[0-9]+}}.4s, v{{[0-9]+}}.4s},
  // [{{x[0-9]+|sp}}]
}

float64x2x3_t test_vld3q_f64(float64_t const *a) {
  // CHECK: test_vld3q_f64
  return vld3q_f64(a);
  // CHECK: ld3 {v{{[0-9]+}}.2d, v{{[0-9]+}}.2d, v{{[0-9]+}}.2d},
  // [{{x[0-9]+|sp}}]
}

poly8x16x3_t test_vld3q_p8(poly8_t const *a) {
  // CHECK: test_vld3q_p8
  return vld3q_p8(a);
  // CHECK: ld3 {v{{[0-9]+}}.16b, v{{[0-9]+}}.16b, v{{[0-9]+}}.16b},
  // [{{x[0-9]+|sp}}]
}

poly16x8x3_t test_vld3q_p16(poly16_t const *a) {
  // CHECK: test_vld3q_p16
  return vld3q_p16(a);
  // CHECK: ld3 {v{{[0-9]+}}.8h, v{{[0-9]+}}.8h, v{{[0-9]+}}.8h},
  // [{{x[0-9]+|sp}}]
}

uint8x8x3_t test_vld3_u8(uint8_t const *a) {
  // CHECK: test_vld3_u8
  return vld3_u8(a);
  // CHECK: ld3 {v{{[0-9]+}}.8b, v{{[0-9]+}}.8b, v{{[0-9]+}}.8b},
  // [{{x[0-9]+|sp}}]
}

uint16x4x3_t test_vld3_u16(uint16_t const *a) {
  // CHECK: test_vld3_u16
  return vld3_u16(a);
  // CHECK: ld3 {v{{[0-9]+}}.4h, v{{[0-9]+}}.4h, v{{[0-9]+}}.4h},
  // [{{x[0-9]+|sp}}]
}

uint32x2x3_t test_vld3_u32(uint32_t const *a) {
  // CHECK: test_vld3_u32
  return vld3_u32(a);
  // CHECK: ld3 {v{{[0-9]+}}.2s, v{{[0-9]+}}.2s, v{{[0-9]+}}.2s},
  // [{{x[0-9]+|sp}}]
}

uint64x1x3_t test_vld3_u64(uint64_t const *a) {
  // CHECK: test_vld3_u64
  return vld3_u64(a);
  // CHECK: ld1 {v{{[0-9]+}}.1d, v{{[0-9]+}}.1d, v{{[0-9]+}}.1d},
  // [{{x[0-9]+|sp}}]
}

int8x8x3_t test_vld3_s8(int8_t const *a) {
  // CHECK: test_vld3_s8
  return vld3_s8(a);
  // CHECK: ld3 {v{{[0-9]+}}.8b, v{{[0-9]+}}.8b, v{{[0-9]+}}.8b},
  // [{{x[0-9]+|sp}}]
}

int16x4x3_t test_vld3_s16(int16_t const *a) {
  // CHECK: test_vld3_s16
  return vld3_s16(a);
  // CHECK: ld3 {v{{[0-9]+}}.4h, v{{[0-9]+}}.4h, v{{[0-9]+}}.4h},
  // [{{x[0-9]+|sp}}]
}

int32x2x3_t test_vld3_s32(int32_t const *a) {
  // CHECK: test_vld3_s32
  return vld3_s32(a);
  // CHECK: ld3 {v{{[0-9]+}}.2s, v{{[0-9]+}}.2s, v{{[0-9]+}}.2s},
  // [{{x[0-9]+|sp}}]
}

int64x1x3_t test_vld3_s64(int64_t const *a) {
  // CHECK: test_vld3_s64
  return vld3_s64(a);
  // CHECK: ld1 {v{{[0-9]+}}.1d, v{{[0-9]+}}.1d, v{{[0-9]+}}.1d},
  // [{{x[0-9]+|sp}}]
}

float16x4x3_t test_vld3_f16(float16_t const *a) {
  // CHECK: test_vld3_f16
  return vld3_f16(a);
  // CHECK: ld3 {v{{[0-9]+}}.4h, v{{[0-9]+}}.4h, v{{[0-9]+}}.4h},
  // [{{x[0-9]+|sp}}]
}

float32x2x3_t test_vld3_f32(float32_t const *a) {
  // CHECK: test_vld3_f32
  return vld3_f32(a);
  // CHECK: ld3 {v{{[0-9]+}}.2s, v{{[0-9]+}}.2s, v{{[0-9]+}}.2s},
  // [{{x[0-9]+|sp}}]
}

float64x1x3_t test_vld3_f64(float64_t const *a) {
  // CHECK: test_vld3_f64
  return vld3_f64(a);
  // CHECK: ld1 {v{{[0-9]+}}.1d, v{{[0-9]+}}.1d, v{{[0-9]+}}.1d},
  // [{{x[0-9]+|sp}}]
}

poly8x8x3_t test_vld3_p8(poly8_t const *a) {
  // CHECK: test_vld3_p8
  return vld3_p8(a);
  // CHECK: ld3 {v{{[0-9]+}}.8b, v{{[0-9]+}}.8b, v{{[0-9]+}}.8b},
  // [{{x[0-9]+|sp}}]
}

poly16x4x3_t test_vld3_p16(poly16_t const *a) {
  // CHECK: test_vld3_p16
  return vld3_p16(a);
  // CHECK: ld3 {v{{[0-9]+}}.4h, v{{[0-9]+}}.4h, v{{[0-9]+}}.4h},
  // [{{x[0-9]+|sp}}]
}

uint8x16x4_t test_vld4q_u8(uint8_t const *a) {
  // CHECK: test_vld4q_u8
  return vld4q_u8(a);
  // CHECK: ld4 {v{{[0-9]+}}.16b, v{{[0-9]+}}.16b, v{{[0-9]+}}.16b,
  // v{{[0-9]+}}.16b}, [{{x[0-9]+|sp}}]
}

uint16x8x4_t test_vld4q_u16(uint16_t const *a) {
  // CHECK: test_vld4q_u16
  return vld4q_u16(a);
  // CHECK: ld4 {v{{[0-9]+}}.8h, v{{[0-9]+}}.8h, v{{[0-9]+}}.8h,
  // v{{[0-9]+}}.8h}, [{{x[0-9]+|sp}}]
}

uint32x4x4_t test_vld4q_u32(uint32_t const *a) {
  // CHECK: test_vld4q_u32
  return vld4q_u32(a);
  // CHECK: ld4 {v{{[0-9]+}}.4s, v{{[0-9]+}}.4s, v{{[0-9]+}}.4s,
  // v{{[0-9]+}}.4s}, [{{x[0-9]+|sp}}]
}

uint64x2x4_t test_vld4q_u64(uint64_t const *a) {
  // CHECK: test_vld4q_u64
  return vld4q_u64(a);
  // CHECK: ld4 {v{{[0-9]+}}.2d, v{{[0-9]+}}.2d, v{{[0-9]+}}.2d,
  // v{{[0-9]+}}.2d}, [{{x[0-9]+|sp}}]
}

int8x16x4_t test_vld4q_s8(int8_t const *a) {
  // CHECK: test_vld4q_s8
  return vld4q_s8(a);
  // CHECK: ld4 {v{{[0-9]+}}.16b, v{{[0-9]+}}.16b, v{{[0-9]+}}.16b,
  // v{{[0-9]+}}.16b}, [{{x[0-9]+|sp}}]
}

int16x8x4_t test_vld4q_s16(int16_t const *a) {
  // CHECK: test_vld4q_s16
  return vld4q_s16(a);
  // CHECK: ld4 {v{{[0-9]+}}.8h, v{{[0-9]+}}.8h, v{{[0-9]+}}.8h,
  // v{{[0-9]+}}.8h}, [{{x[0-9]+|sp}}]
}

int32x4x4_t test_vld4q_s32(int32_t const *a) {
  // CHECK: test_vld4q_s32
  return vld4q_s32(a);
  // CHECK: ld4 {v{{[0-9]+}}.4s, v{{[0-9]+}}.4s, v{{[0-9]+}}.4s,
  // v{{[0-9]+}}.4s}, [{{x[0-9]+|sp}}]
}

int64x2x4_t test_vld4q_s64(int64_t const *a) {
  // CHECK: test_vld4q_s64
  return vld4q_s64(a);
  // CHECK: ld4 {v{{[0-9]+}}.2d, v{{[0-9]+}}.2d, v{{[0-9]+}}.2d,
  // v{{[0-9]+}}.2d}, [{{x[0-9]+|sp}}]
}

float16x8x4_t test_vld4q_f16(float16_t const *a) {
  // CHECK: test_vld4q_f16
  return vld4q_f16(a);
  // CHECK: ld4 {v{{[0-9]+}}.8h, v{{[0-9]+}}.8h, v{{[0-9]+}}.8h,
  // v{{[0-9]+}}.8h}, [{{x[0-9]+|sp}}]
}

float32x4x4_t test_vld4q_f32(float32_t const *a) {
  // CHECK: test_vld4q_f32
  return vld4q_f32(a);
  // CHECK: ld4 {v{{[0-9]+}}.4s, v{{[0-9]+}}.4s, v{{[0-9]+}}.4s,
  // v{{[0-9]+}}.4s}, [{{x[0-9]+|sp}}]
}

float64x2x4_t test_vld4q_f64(float64_t const *a) {
  // CHECK: test_vld4q_f64
  return vld4q_f64(a);
  // CHECK: ld4 {v{{[0-9]+}}.2d, v{{[0-9]+}}.2d, v{{[0-9]+}}.2d,
  // v{{[0-9]+}}.4s}, [{{x[0-9]+|sp}}]
}

poly8x16x4_t test_vld4q_p8(poly8_t const *a) {
  // CHECK: test_vld4q_p8
  return vld4q_p8(a);
  // CHECK: ld4 {v{{[0-9]+}}.16b, v{{[0-9]+}}.16b, v{{[0-9]+}}.16b,
  // v{{[0-9]+}}.16b}, [{{x[0-9]+|sp}}]
}

poly16x8x4_t test_vld4q_p16(poly16_t const *a) {
  // CHECK: test_vld4q_p16
  return vld4q_p16(a);
  // CHECK: ld4 {v{{[0-9]+}}.8h, v{{[0-9]+}}.8h, v{{[0-9]+}}.8h,
  // v{{[0-9]+}}.8h}, [{{x[0-9]+|sp}}]
}

uint8x8x4_t test_vld4_u8(uint8_t const *a) {
  // CHECK: test_vld4_u8
  return vld4_u8(a);
  // CHECK: ld4 {v{{[0-9]+}}.8b, v{{[0-9]+}}.8b, v{{[0-9]+}}.8b,
  // v{{[0-9]+}}.8b}, [{{x[0-9]+|sp}}]
}

uint16x4x4_t test_vld4_u16(uint16_t const *a) {
  // CHECK: test_vld4_u16
  return vld4_u16(a);
  // CHECK: ld4 {v{{[0-9]+}}.4h, v{{[0-9]+}}.4h, v{{[0-9]+}}.4h,
  // v{{[0-9]+}}.4h}, [{{x[0-9]+|sp}}]
}

uint32x2x4_t test_vld4_u32(uint32_t const *a) {
  // CHECK: test_vld4_u32
  return vld4_u32(a);
  // CHECK: ld4 {v{{[0-9]+}}.2s, v{{[0-9]+}}.2s, v{{[0-9]+}}.2s,
  // v{{[0-9]+}}.2s}, [{{x[0-9]+|sp}}]
}

uint64x1x4_t test_vld4_u64(uint64_t const *a) {
  // CHECK: test_vld4_u64
  return vld4_u64(a);
  // CHECK: ld1 {v{{[0-9]+}}.1d, v{{[0-9]+}}.1d, v{{[0-9]+}}.1d,
  // v{{[0-9]+}}.1d}, [{{x[0-9]+|sp}}]
}

int8x8x4_t test_vld4_s8(int8_t const *a) {
  // CHECK: test_vld4_s8
  return vld4_s8(a);
  // CHECK: ld4 {v{{[0-9]+}}.8b, v{{[0-9]+}}.8b, v{{[0-9]+}}.8b,
  // v{{[0-9]+}}.8b}, [{{x[0-9]+|sp}}]
}

int16x4x4_t test_vld4_s16(int16_t const *a) {
  // CHECK: test_vld4_s16
  return vld4_s16(a);
  // CHECK: ld4 {v{{[0-9]+}}.4h, v{{[0-9]+}}.4h, v{{[0-9]+}}.4h,
  // v{{[0-9]+}}.4h}, [{{x[0-9]+|sp}}]
}

int32x2x4_t test_vld4_s32(int32_t const *a) {
  // CHECK: test_vld4_s32
  return vld4_s32(a);
  // CHECK: ld4 {v{{[0-9]+}}.2s, v{{[0-9]+}}.2s, v{{[0-9]+}}.2s,
  // v{{[0-9]+}}.2s}, [{{x[0-9]+|sp}}]
}

int64x1x4_t test_vld4_s64(int64_t const *a) {
  // CHECK: test_vld4_s64
  return vld4_s64(a);
  // CHECK: ld1 {v{{[0-9]+}}.1d, v{{[0-9]+}}.1d, v{{[0-9]+}}.1d,
  // v{{[0-9]+}}.1d}, [{{x[0-9]+|sp}}]
}

float16x4x4_t test_vld4_f16(float16_t const *a) {
  // CHECK: test_vld4_f16
  return vld4_f16(a);
  // CHECK: ld4 {v{{[0-9]+}}.4h, v{{[0-9]+}}.4h, v{{[0-9]+}}.4h,
  // v{{[0-9]+}}.4h}, [{{x[0-9]+|sp}}]
}

float32x2x4_t test_vld4_f32(float32_t const *a) {
  // CHECK: test_vld4_f32
  return vld4_f32(a);
  // CHECK: ld4 {v{{[0-9]+}}.2s, v{{[0-9]+}}.2s, v{{[0-9]+}}.2s,
  // v{{[0-9]+}}.2s}, [{{x[0-9]+|sp}}]
}

float64x1x4_t test_vld4_f64(float64_t const *a) {
  // CHECK: test_vld4_f64
  return vld4_f64(a);
  // CHECK: ld1 {v{{[0-9]+}}.1d, v{{[0-9]+}}.1d, v{{[0-9]+}}.1d,
  // v{{[0-9]+}}.1d}, [{{x[0-9]+|sp}}]
}

poly8x8x4_t test_vld4_p8(poly8_t const *a) {
  // CHECK: test_vld4_p8
  return vld4_p8(a);
  // CHECK: ld4 {v{{[0-9]+}}.8b, v{{[0-9]+}}.8b, v{{[0-9]+}}.8b,
  // v{{[0-9]+}}.8b}, [{{x[0-9]+|sp}}]
}

poly16x4x4_t test_vld4_p16(poly16_t const *a) {
  // CHECK: test_vld4_p16
  return vld4_p16(a);
  // CHECK: ld4 {v{{[0-9]+}}.4h, v{{[0-9]+}}.4h, v{{[0-9]+}}.4h,
  // v{{[0-9]+}}.4h}, [{{x[0-9]+|sp}}]
}

void test_vst1q_u8(uint8_t *a, uint8x16_t b) {
  // CHECK: test_vst1q_u8
  vst1q_u8(a, b);
  // CHECK: st1 {v{{[0-9]+}}.16b}, [{{x[0-9]+|sp}}]
}

void test_vst1q_u16(uint16_t *a, uint16x8_t b) {
  // CHECK: test_vst1q_u16
  vst1q_u16(a, b);
  // CHECK: st1 {v{{[0-9]+}}.8h}, [{{x[0-9]+|sp}}]
}

void test_vst1q_u32(uint32_t *a, uint32x4_t b) {
  // CHECK: test_vst1q_u32
  vst1q_u32(a, b);
  // CHECK: st1 {v{{[0-9]+}}.4s}, [{{x[0-9]+|sp}}]
}

void test_vst1q_u64(uint64_t *a, uint64x2_t b) {
  // CHECK: test_vst1q_u64
  vst1q_u64(a, b);
  // CHECK: st1 {v{{[0-9]+}}.2d}, [{{x[0-9]+|sp}}]
}

void test_vst1q_s8(int8_t *a, int8x16_t b) {
  // CHECK: test_vst1q_s8
  vst1q_s8(a, b);
  // CHECK: st1 {v{{[0-9]+}}.16b}, [{{x[0-9]+|sp}}]
}

void test_vst1q_s16(int16_t *a, int16x8_t b) {
  // CHECK: test_vst1q_s16
  vst1q_s16(a, b);
  // CHECK: st1 {v{{[0-9]+}}.8h}, [{{x[0-9]+|sp}}]
}

void test_vst1q_s32(int32_t *a, int32x4_t b) {
  // CHECK: test_vst1q_s32
  vst1q_s32(a, b);
  // CHECK: st1 {v{{[0-9]+}}.4s}, [{{x[0-9]+|sp}}]
}

void test_vst1q_s64(int64_t *a, int64x2_t b) {
  // CHECK: test_vst1q_s64
  vst1q_s64(a, b);
  // CHECK: st1 {v{{[0-9]+}}.2d}, [{{x[0-9]+|sp}}]
}

void test_vst1q_f16(float16_t *a, float16x8_t b) {
  // CHECK: test_vst1q_f16
  vst1q_f16(a, b);
  // CHECK: st1 {v{{[0-9]+}}.8h}, [{{x[0-9]+|sp}}]
}

void test_vst1q_f32(float32_t *a, float32x4_t b) {
  // CHECK: test_vst1q_f32
  vst1q_f32(a, b);
  // CHECK: st1 {v{{[0-9]+}}.4s}, [{{x[0-9]+|sp}}]
}

void test_vst1q_f64(float64_t *a, float64x2_t b) {
  // CHECK: test_vst1q_f64
  vst1q_f64(a, b);
  // CHECK: st1 {v{{[0-9]+}}.2d}, [{{x[0-9]+|sp}}]
}

void test_vst1q_p8(poly8_t *a, poly8x16_t b) {
  // CHECK: test_vst1q_p8
  vst1q_p8(a, b);
  // CHECK: st1 {v{{[0-9]+}}.16b}, [{{x[0-9]+|sp}}]
}

void test_vst1q_p16(poly16_t *a, poly16x8_t b) {
  // CHECK: test_vst1q_p16
  vst1q_p16(a, b);
  // CHECK: st1 {v{{[0-9]+}}.8h}, [{{x[0-9]+|sp}}]
}

void test_vst1_u8(uint8_t *a, uint8x8_t b) {
  // CHECK: test_vst1_u8
  vst1_u8(a, b);
  // CHECK: st1 {v{{[0-9]+}}.8b}, [{{x[0-9]+|sp}}]
}

void test_vst1_u16(uint16_t *a, uint16x4_t b) {
  // CHECK: test_vst1_u16
  vst1_u16(a, b);
  // CHECK: st1 {v{{[0-9]+}}.4h}, [{{x[0-9]+|sp}}]
}

void test_vst1_u32(uint32_t *a, uint32x2_t b) {
  // CHECK: test_vst1_u32
  vst1_u32(a, b);
  // CHECK: st1 {v{{[0-9]+}}.2s}, [{{x[0-9]+|sp}}]
}

void test_vst1_u64(uint64_t *a, uint64x1_t b) {
  // CHECK: test_vst1_u64
  vst1_u64(a, b);
  // CHECK: st1 {v{{[0-9]+}}.1d}, [{{x[0-9]+|sp}}]
}

void test_vst1_s8(int8_t *a, int8x8_t b) {
  // CHECK: test_vst1_s8
  vst1_s8(a, b);
  // CHECK: st1 {v{{[0-9]+}}.8b}, [{{x[0-9]+|sp}}]
}

void test_vst1_s16(int16_t *a, int16x4_t b) {
  // CHECK: test_vst1_s16
  vst1_s16(a, b);
  // CHECK: st1 {v{{[0-9]+}}.4h}, [{{x[0-9]+|sp}}]
}

void test_vst1_s32(int32_t *a, int32x2_t b) {
  // CHECK: test_vst1_s32
  vst1_s32(a, b);
  // CHECK: st1 {v{{[0-9]+}}.2s}, [{{x[0-9]+|sp}}]
}

void test_vst1_s64(int64_t *a, int64x1_t b) {
  // CHECK: test_vst1_s64
  vst1_s64(a, b);
  // CHECK: st1 {v{{[0-9]+}}.1d}, [{{x[0-9]+|sp}}]
}

void test_vst1_f16(float16_t *a, float16x4_t b) {
  // CHECK: test_vst1_f16
  vst1_f16(a, b);
  // CHECK: st1 {v{{[0-9]+}}.4h}, [{{x[0-9]+|sp}}]
}

void test_vst1_f32(float32_t *a, float32x2_t b) {
  // CHECK: test_vst1_f32
  vst1_f32(a, b);
  // CHECK: st1 {v{{[0-9]+}}.2s}, [{{x[0-9]+|sp}}]
}

void test_vst1_f64(float64_t *a, float64x1_t b) {
  // CHECK: test_vst1_f64
  vst1_f64(a, b);
  // CHECK: st1 {v{{[0-9]+}}.1d}, [{{x[0-9]+|sp}}]
}

void test_vst1_p8(poly8_t *a, poly8x8_t b) {
  // CHECK: test_vst1_p8
  vst1_p8(a, b);
  // CHECK: st1 {v{{[0-9]+}}.8b}, [{{x[0-9]+|sp}}]
}

void test_vst1_p16(poly16_t *a, poly16x4_t b) {
  // CHECK: test_vst1_p16
  vst1_p16(a, b);
  // CHECK: st1 {v{{[0-9]+}}.4h}, [{{x[0-9]+|sp}}]
}

void test_vst2q_u8(uint8_t *a, uint8x16x2_t b) {
  // CHECK: test_vst2q_u8
  vst2q_u8(a, b);
  // CHECK: st2 {v{{[0-9]+}}.16b, v{{[0-9]+}}.16b}, [{{x[0-9]+|sp}}]
}

void test_vst2q_u16(uint16_t *a, uint16x8x2_t b) {
  // CHECK: test_vst2q_u16
  vst2q_u16(a, b);
  // CHECK: st2 {v{{[0-9]+}}.8h, v{{[0-9]+}}.8h}, [{{x[0-9]+|sp}}]
}

void test_vst2q_u32(uint32_t *a, uint32x4x2_t b) {
  // CHECK: test_vst2q_u32
  vst2q_u32(a, b);
  // CHECK: st2 {v{{[0-9]+}}.4s, v{{[0-9]+}}.4s}, [{{x[0-9]+|sp}}]
}

void test_vst2q_u64(uint64_t *a, uint64x2x2_t b) {
  // CHECK: test_vst2q_u64
  vst2q_u64(a, b);
  // CHECK: st2 {v{{[0-9]+}}.2d, v{{[0-9]+}}.2d}, [{{x[0-9]+|sp}}]
}

void test_vst2q_s8(int8_t *a, int8x16x2_t b) {
  // CHECK: test_vst2q_s8
  vst2q_s8(a, b);
  // CHECK: st2 {v{{[0-9]+}}.16b, v{{[0-9]+}}.16b}, [{{x[0-9]+|sp}}]
}

void test_vst2q_s16(int16_t *a, int16x8x2_t b) {
  // CHECK: test_vst2q_s16
  vst2q_s16(a, b);
  // CHECK: st2 {v{{[0-9]+}}.8h, v{{[0-9]+}}.8h}, [{{x[0-9]+|sp}}]
}

void test_vst2q_s32(int32_t *a, int32x4x2_t b) {
  // CHECK: test_vst2q_s32
  vst2q_s32(a, b);
  // CHECK: st2 {v{{[0-9]+}}.4s, v{{[0-9]+}}.4s}, [{{x[0-9]+|sp}}]
}

void test_vst2q_s64(int64_t *a, int64x2x2_t b) {
  // CHECK: test_vst2q_s64
  vst2q_s64(a, b);
  // CHECK: st2 {v{{[0-9]+}}.2d, v{{[0-9]+}}.2d}, [{{x[0-9]+|sp}}]
}

void test_vst2q_f16(float16_t *a, float16x8x2_t b) {
  // CHECK: test_vst2q_f16
  vst2q_f16(a, b);
  // CHECK: st2 {v{{[0-9]+}}.8h, v{{[0-9]+}}.8h}, [{{x[0-9]+|sp}}]
}

void test_vst2q_f32(float32_t *a, float32x4x2_t b) {
  // CHECK: test_vst2q_f32
  vst2q_f32(a, b);
  // CHECK: st2 {v{{[0-9]+}}.4s, v{{[0-9]+}}.4s}, [{{x[0-9]+|sp}}]
}

void test_vst2q_f64(float64_t *a, float64x2x2_t b) {
  // CHECK: test_vst2q_f64
  vst2q_f64(a, b);
  // CHECK: st2 {v{{[0-9]+}}.2d, v{{[0-9]+}}.2d}, [{{x[0-9]+|sp}}]
}

void test_vst2q_p8(poly8_t *a, poly8x16x2_t b) {
  // CHECK: test_vst2q_p8
  vst2q_p8(a, b);
  // CHECK: st2 {v{{[0-9]+}}.16b, v{{[0-9]+}}.16b}, [{{x[0-9]+|sp}}]
}

void test_vst2q_p16(poly16_t *a, poly16x8x2_t b) {
  // CHECK: test_vst2q_p16
  vst2q_p16(a, b);
  // CHECK: st2 {v{{[0-9]+}}.8h, v{{[0-9]+}}.8h}, [{{x[0-9]+|sp}}]
}

void test_vst2_u8(uint8_t *a, uint8x8x2_t b) {
  // CHECK: test_vst2_u8
  vst2_u8(a, b);
  // CHECK: st2 {v{{[0-9]+}}.8b, v{{[0-9]+}}.8b}, [{{x[0-9]+|sp}}]
}

void test_vst2_u16(uint16_t *a, uint16x4x2_t b) {
  // CHECK: test_vst2_u16
  vst2_u16(a, b);
  // CHECK: st2 {v{{[0-9]+}}.4h, v{{[0-9]+}}.4h}, [{{x[0-9]+|sp}}]
}

void test_vst2_u32(uint32_t *a, uint32x2x2_t b) {
  // CHECK: test_vst2_u32
  vst2_u32(a, b);
  // CHECK: st2 {v{{[0-9]+}}.2s, v{{[0-9]+}}.2s}, [{{x[0-9]+|sp}}]
}

void test_vst2_u64(uint64_t *a, uint64x1x2_t b) {
  // CHECK: test_vst2_u64
  vst2_u64(a, b);
  // CHECK: st1 {v{{[0-9]+}}.1d, v{{[0-9]+}}.1d}, [{{x[0-9]+|sp}}]
}

void test_vst2_s8(int8_t *a, int8x8x2_t b) {
  // CHECK: test_vst2_s8
  vst2_s8(a, b);
  // CHECK: st2 {v{{[0-9]+}}.8b, v{{[0-9]+}}.8b}, [{{x[0-9]+|sp}}]
}

void test_vst2_s16(int16_t *a, int16x4x2_t b) {
  // CHECK: test_vst2_s16
  vst2_s16(a, b);
  // CHECK: st2 {v{{[0-9]+}}.4h, v{{[0-9]+}}.4h}, [{{x[0-9]+|sp}}]
}

void test_vst2_s32(int32_t *a, int32x2x2_t b) {
  // CHECK: test_vst2_s32
  vst2_s32(a, b);
  // CHECK: st2 {v{{[0-9]+}}.2s, v{{[0-9]+}}.2s}, [{{x[0-9]+|sp}}]
}

void test_vst2_s64(int64_t *a, int64x1x2_t b) {
  // CHECK: test_vst2_s64
  vst2_s64(a, b);
  // CHECK: st1 {v{{[0-9]+}}.1d, v{{[0-9]+}}.1d}, [{{x[0-9]+|sp}}]
}

void test_vst2_f16(float16_t *a, float16x4x2_t b) {
  // CHECK: test_vst2_f16
  vst2_f16(a, b);
  // CHECK: st2 {v{{[0-9]+}}.4h, v{{[0-9]+}}.4h}, [{{x[0-9]+|sp}}]
}

void test_vst2_f32(float32_t *a, float32x2x2_t b) {
  // CHECK: test_vst2_f32
  vst2_f32(a, b);
  // CHECK: st2 {v{{[0-9]+}}.2s, v{{[0-9]+}}.2s}, [{{x[0-9]+|sp}}]
}

void test_vst2_f64(float64_t *a, float64x1x2_t b) {
  // CHECK: test_vst2_f64
  vst2_f64(a, b);
  // CHECK: st1 {v{{[0-9]+}}.1d, v{{[0-9]+}}.1d}, [{{x[0-9]+|sp}}]
}

void test_vst2_p8(poly8_t *a, poly8x8x2_t b) {
  // CHECK: test_vst2_p8
  vst2_p8(a, b);
  // CHECK: st2 {v{{[0-9]+}}.8b, v{{[0-9]+}}.8b}, [{{x[0-9]+|sp}}]
}

void test_vst2_p16(poly16_t *a, poly16x4x2_t b) {
  // CHECK: test_vst2_p16
  vst2_p16(a, b);
  // CHECK: st2 {v{{[0-9]+}}.4h, v{{[0-9]+}}.4h}, [{{x[0-9]+|sp}}]
}

void test_vst3q_u8(uint8_t *a, uint8x16x3_t b) {
  // CHECK: test_vst3q_u8
  vst3q_u8(a, b);
  // CHECK: st3 {v{{[0-9]+}}.16b, v{{[0-9]+}}.16b, v{{[0-9]+}}.16b},
  // [{{x[0-9]+|sp}}]
}

void test_vst3q_u16(uint16_t *a, uint16x8x3_t b) {
  // CHECK: test_vst3q_u16
  vst3q_u16(a, b);
  // CHECK: st3 {v{{[0-9]+}}.8h, v{{[0-9]+}}.8h, v{{[0-9]+}}.8h},
  // [{{x[0-9]+|sp}}]
}

void test_vst3q_u32(uint32_t *a, uint32x4x3_t b) {
  // CHECK: test_vst3q_u32
  vst3q_u32(a, b);
  // CHECK: st3 {v{{[0-9]+}}.4s, v{{[0-9]+}}.4s, v{{[0-9]+}}.4s},
  // [{{x[0-9]+|sp}}]
}

void test_vst3q_u64(uint64_t *a, uint64x2x3_t b) {
  // CHECK: test_vst3q_u64
  vst3q_u64(a, b);
  // CHECK: st3 {v{{[0-9]+}}.2d, v{{[0-9]+}}.2d, v{{[0-9]+}}.2d},
  // [{{x[0-9]+|sp}}]
}

void test_vst3q_s8(int8_t *a, int8x16x3_t b) {
  // CHECK: test_vst3q_s8
  vst3q_s8(a, b);
  // CHECK: st3 {v{{[0-9]+}}.16b, v{{[0-9]+}}.16b, v{{[0-9]+}}.16b},
  // [{{x[0-9]+|sp}}]
}

void test_vst3q_s16(int16_t *a, int16x8x3_t b) {
  // CHECK: test_vst3q_s16
  vst3q_s16(a, b);
  // CHECK: st3 {v{{[0-9]+}}.8h, v{{[0-9]+}}.8h, v{{[0-9]+}}.8h},
  // [{{x[0-9]+|sp}}]
}

void test_vst3q_s32(int32_t *a, int32x4x3_t b) {
  // CHECK: test_vst3q_s32
  vst3q_s32(a, b);
  // CHECK: st3 {v{{[0-9]+}}.4s, v{{[0-9]+}}.4s, v{{[0-9]+}}.4s},
  // [{{x[0-9]+|sp}}]
}

void test_vst3q_s64(int64_t *a, int64x2x3_t b) {
  // CHECK: test_vst3q_s64
  vst3q_s64(a, b);
  // CHECK: st3 {v{{[0-9]+}}.2d, v{{[0-9]+}}.2d, v{{[0-9]+}}.2d},
  // [{{x[0-9]+|sp}}]
}

void test_vst3q_f16(float16_t *a, float16x8x3_t b) {
  // CHECK: test_vst3q_f16
  vst3q_f16(a, b);
  // CHECK: st3 {v{{[0-9]+}}.8h, v{{[0-9]+}}.8h, v{{[0-9]+}}.8h},
  // [{{x[0-9]+|sp}}]
}

void test_vst3q_f32(float32_t *a, float32x4x3_t b) {
  // CHECK: test_vst3q_f32
  vst3q_f32(a, b);
  // CHECK: st3 {v{{[0-9]+}}.4s, v{{[0-9]+}}.4s, v{{[0-9]+}}.4s},
  // [{{x[0-9]+|sp}}]
}

void test_vst3q_f64(float64_t *a, float64x2x3_t b) {
  // CHECK: test_vst3q_f64
  vst3q_f64(a, b);
  // CHECK: st3 {v{{[0-9]+}}.2d, v{{[0-9]+}}.2d, v{{[0-9]+}}.2d},
  // [{{x[0-9]+|sp}}]
}

void test_vst3q_p8(poly8_t *a, poly8x16x3_t b) {
  // CHECK: test_vst3q_p8
  vst3q_p8(a, b);
  // CHECK: st3 {v{{[0-9]+}}.16b, v{{[0-9]+}}.16b, v{{[0-9]+}}.16b},
  // [{{x[0-9]+|sp}}]
}

void test_vst3q_p16(poly16_t *a, poly16x8x3_t b) {
  // CHECK: test_vst3q_p16
  vst3q_p16(a, b);
  // CHECK: st3 {v{{[0-9]+}}.8h, v{{[0-9]+}}.8h, v{{[0-9]+}}.8h},
  // [{{x[0-9]+|sp}}]
}

void test_vst3_u8(uint8_t *a, uint8x8x3_t b) {
  // CHECK: test_vst3_u8
  vst3_u8(a, b);
  // CHECK: st3 {v{{[0-9]+}}.8b, v{{[0-9]+}}.8b, v{{[0-9]+}}.8b},
  // [{{x[0-9]+|sp}}]
}

void test_vst3_u16(uint16_t *a, uint16x4x3_t b) {
  // CHECK: test_vst3_u16
  vst3_u16(a, b);
  // CHECK: st3 {v{{[0-9]+}}.4h, v{{[0-9]+}}.4h, v{{[0-9]+}}.4h},
  // [{{x[0-9]+|sp}}]
}

void test_vst3_u32(uint32_t *a, uint32x2x3_t b) {
  // CHECK: test_vst3_u32
  vst3_u32(a, b);
  // CHECK: st3 {v{{[0-9]+}}.2s, v{{[0-9]+}}.2s, v{{[0-9]+}}.2s},
  // [{{x[0-9]+|sp}}]
}

void test_vst3_u64(uint64_t *a, uint64x1x3_t b) {
  // CHECK: test_vst3_u64
  vst3_u64(a, b);
  // CHECK: st1 {v{{[0-9]+}}.1d, v{{[0-9]+}}.1d, v{{[0-9]+}}.1d},
  // [{{x[0-9]+|sp}}]
}

void test_vst3_s8(int8_t *a, int8x8x3_t b) {
  // CHECK: test_vst3_s8
  vst3_s8(a, b);
  // CHECK: st3 {v{{[0-9]+}}.8b, v{{[0-9]+}}.8b, v{{[0-9]+}}.8b},
  // [{{x[0-9]+|sp}}]
}

void test_vst3_s16(int16_t *a, int16x4x3_t b) {
  // CHECK: test_vst3_s16
  vst3_s16(a, b);
  // CHECK: st3 {v{{[0-9]+}}.4h, v{{[0-9]+}}.4h, v{{[0-9]+}}.4h},
  // [{{x[0-9]+|sp}}]
}

void test_vst3_s32(int32_t *a, int32x2x3_t b) {
  // CHECK: test_vst3_s32
  vst3_s32(a, b);
  // CHECK: st3 {v{{[0-9]+}}.2s, v{{[0-9]+}}.2s, v{{[0-9]+}}.2s},
  // [{{x[0-9]+|sp}}]
}

void test_vst3_s64(int64_t *a, int64x1x3_t b) {
  // CHECK: test_vst3_s64
  vst3_s64(a, b);
  // CHECK: st1 {v{{[0-9]+}}.1d, v{{[0-9]+}}.1d, v{{[0-9]+}}.1d},
  // [{{x[0-9]+|sp}}]
}

void test_vst3_f16(float16_t *a, float16x4x3_t b) {
  // CHECK: test_vst3_f16
  vst3_f16(a, b);
  // CHECK: st3 {v{{[0-9]+}}.4h, v{{[0-9]+}}.4h, v{{[0-9]+}}.4h},
  // [{{x[0-9]+|sp}}]
}

void test_vst3_f32(float32_t *a, float32x2x3_t b) {
  // CHECK: test_vst3_f32
  vst3_f32(a, b);
  // CHECK: st3 {v{{[0-9]+}}.2s, v{{[0-9]+}}.2s, v{{[0-9]+}}.2s},
  // [{{x[0-9]+|sp}}]
}

void test_vst3_f64(float64_t *a, float64x1x3_t b) {
  // CHECK: test_vst3_f64
  vst3_f64(a, b);
  // CHECK: st1 {v{{[0-9]+}}.1d, v{{[0-9]+}}.1d, v{{[0-9]+}}.1d},
  // [{{x[0-9]+|sp}}]
}

void test_vst3_p8(poly8_t *a, poly8x8x3_t b) {
  // CHECK: test_vst3_p8
  vst3_p8(a, b);
  // CHECK: st3 {v{{[0-9]+}}.8b, v{{[0-9]+}}.8b, v{{[0-9]+}}.8b},
  // [{{x[0-9]+|sp}}]
}

void test_vst3_p16(poly16_t *a, poly16x4x3_t b) {
  // CHECK: test_vst3_p16
  vst3_p16(a, b);
  // CHECK: st3 {v{{[0-9]+}}.4h, v{{[0-9]+}}.4h, v{{[0-9]+}}.4h},
  // [{{x[0-9]+|sp}}]
}

void test_vst4q_u8(uint8_t *a, uint8x16x4_t b) {
  // CHECK: test_vst4q_u8
  vst4q_u8(a, b);
  // CHECK: st4 {v{{[0-9]+}}.16b, v{{[0-9]+}}.16b, v{{[0-9]+}}.16b,
  // v{{[0-9]+}}.16b}, [{{x[0-9]+|sp}}]
}

void test_vst4q_u16(uint16_t *a, uint16x8x4_t b) {
  // CHECK: test_vst4q_u16
  vst4q_u16(a, b);
  // CHECK: st4 {v{{[0-9]+}}.8h, v{{[0-9]+}}.8h, v{{[0-9]+}}.8h,
  // v{{[0-9]+}}.8h}, [{{x[0-9]+|sp}}]
}

void test_vst4q_u32(uint32_t *a, uint32x4x4_t b) {
  // CHECK: test_vst4q_u32
  vst4q_u32(a, b);
  // CHECK: st4 {v{{[0-9]+}}.4s, v{{[0-9]+}}.4s, v{{[0-9]+}}.4s,
  // v{{[0-9]+}}.4s}, [{{x[0-9]+|sp}}]
}

void test_vst4q_u64(uint64_t *a, uint64x2x4_t b) {
  // CHECK: test_vst4q_u64
  vst4q_u64(a, b);
  // CHECK: st4 {v{{[0-9]+}}.2d, v{{[0-9]+}}.2d, v{{[0-9]+}}.2d,
  // v{{[0-9]+}}.2d}, [{{x[0-9]+|sp}}]
}

void test_vst4q_s8(int8_t *a, int8x16x4_t b) {
  // CHECK: test_vst4q_s8
  vst4q_s8(a, b);
  // CHECK: st4 {v{{[0-9]+}}.16b, v{{[0-9]+}}.16b, v{{[0-9]+}}.16b,
  // v{{[0-9]+}}.16b}, [{{x[0-9]+|sp}}]
}

void test_vst4q_s16(int16_t *a, int16x8x4_t b) {
  // CHECK: test_vst4q_s16
  vst4q_s16(a, b);
  // CHECK: st4 {v{{[0-9]+}}.8h, v{{[0-9]+}}.8h, v{{[0-9]+}}.8h,
  // v{{[0-9]+}}.8h}, [{{x[0-9]+|sp}}]
}

void test_vst4q_s32(int32_t *a, int32x4x4_t b) {
  // CHECK: test_vst4q_s32
  vst4q_s32(a, b);
  // CHECK: st4 {v{{[0-9]+}}.4s, v{{[0-9]+}}.4s, v{{[0-9]+}}.4s,
  // v{{[0-9]+}}.4s}, [{{x[0-9]+|sp}}]
}

void test_vst4q_s64(int64_t *a, int64x2x4_t b) {
  // CHECK: test_vst4q_s64
  vst4q_s64(a, b);
  // CHECK: st4 {v{{[0-9]+}}.2d, v{{[0-9]+}}.2d, v{{[0-9]+}}.2d,
  // v{{[0-9]+}}.2d}, [{{x[0-9]+|sp}}]
}

void test_vst4q_f16(float16_t *a, float16x8x4_t b) {
  // CHECK: test_vst4q_f16
  vst4q_f16(a, b);
  // CHECK: st4 {v{{[0-9]+}}.8h, v{{[0-9]+}}.8h, v{{[0-9]+}}.8h,
  // v{{[0-9]+}}.8h}, [{{x[0-9]+|sp}}]
}

void test_vst4q_f32(float32_t *a, float32x4x4_t b) {
  // CHECK: test_vst4q_f32
  vst4q_f32(a, b);
  // CHECK: st4 {v{{[0-9]+}}.4s, v{{[0-9]+}}.4s, v{{[0-9]+}}.4s,
  // v{{[0-9]+}}.4s}, [{{x[0-9]+|sp}}]
}

void test_vst4q_f64(float64_t *a, float64x2x4_t b) {
  // CHECK: test_vst4q_f64
  vst4q_f64(a, b);
  // CHECK: st4 {v{{[0-9]+}}.2d, v{{[0-9]+}}.2d, v{{[0-9]+}}.2d,
  // v{{[0-9]+}}.2d}, [{{x[0-9]+|sp}}]
}

void test_vst4q_p8(poly8_t *a, poly8x16x4_t b) {
  // CHECK: test_vst4q_p8
  vst4q_p8(a, b);
  // CHECK: st4 {v{{[0-9]+}}.16b, v{{[0-9]+}}.16b, v{{[0-9]+}}.16b,
  // v{{[0-9]+}}.16b}, [{{x[0-9]+|sp}}]
}

void test_vst4q_p16(poly16_t *a, poly16x8x4_t b) {
  // CHECK: test_vst4q_p16
  vst4q_p16(a, b);
  // CHECK: st4 {v{{[0-9]+}}.8h, v{{[0-9]+}}.8h, v{{[0-9]+}}.8h,
  // v{{[0-9]+}}.8h}, [{{x[0-9]+|sp}}]
}

void test_vst4_u8(uint8_t *a, uint8x8x4_t b) {
  // CHECK: test_vst4_u8
  vst4_u8(a, b);
  // CHECK: st4 {v{{[0-9]+}}.8b, v{{[0-9]+}}.8b, v{{[0-9]+}}.8b,
  // v{{[0-9]+}}.8b}, [{{x[0-9]+|sp}}]
}

void test_vst4_u16(uint16_t *a, uint16x4x4_t b) {
  // CHECK: test_vst4_u16
  vst4_u16(a, b);
  // CHECK: st4 {v{{[0-9]+}}.4h, v{{[0-9]+}}.4h, v{{[0-9]+}}.4h,
  // v{{[0-9]+}}.4h}, [{{x[0-9]+|sp}}]
}

void test_vst4_u32(uint32_t *a, uint32x2x4_t b) {
  // CHECK: test_vst4_u32
  vst4_u32(a, b);
  // CHECK: st4 {v{{[0-9]+}}.2s, v{{[0-9]+}}.2s, v{{[0-9]+}}.2s,
  // v{{[0-9]+}}.2s}, [{{x[0-9]+|sp}}]
}

void test_vst4_u64(uint64_t *a, uint64x1x4_t b) {
  // CHECK: test_vst4_u64
  vst4_u64(a, b);
  // CHECK: st1 {v{{[0-9]+}}.1d, v{{[0-9]+}}.1d, v{{[0-9]+}}.1d,
  // v{{[0-9]+}}.1d}, [{{x[0-9]+|sp}}]
}

void test_vst4_s8(int8_t *a, int8x8x4_t b) {
  // CHECK: test_vst4_s8
  vst4_s8(a, b);
  // CHECK: st4 {v{{[0-9]+}}.8b, v{{[0-9]+}}.8b, v{{[0-9]+}}.8b,
  // v{{[0-9]+}}.8b}, [{{x[0-9]+|sp}}]
}

void test_vst4_s16(int16_t *a, int16x4x4_t b) {
  // CHECK: test_vst4_s16
  vst4_s16(a, b);
  // CHECK: st4 {v{{[0-9]+}}.4h, v{{[0-9]+}}.4h, v{{[0-9]+}}.4h,
  // v{{[0-9]+}}.4h}, [{{x[0-9]+|sp}}]
}

void test_vst4_s32(int32_t *a, int32x2x4_t b) {
  // CHECK: test_vst4_s32
  vst4_s32(a, b);
  // CHECK: st4 {v{{[0-9]+}}.2s, v{{[0-9]+}}.2s, v{{[0-9]+}}.2s,
  // v{{[0-9]+}}.2s}, [{{x[0-9]+|sp}}]
}

void test_vst4_s64(int64_t *a, int64x1x4_t b) {
  // CHECK: test_vst4_s64
  vst4_s64(a, b);
  // CHECK: st1 {v{{[0-9]+}}.1d, v{{[0-9]+}}.1d, v{{[0-9]+}}.1d,
  // v{{[0-9]+}}.1d}, [{{x[0-9]+|sp}}]
}

void test_vst4_f16(float16_t *a, float16x4x4_t b) {
  // CHECK: test_vst4_f16
  vst4_f16(a, b);
  // CHECK: st4 {v{{[0-9]+}}.4h, v{{[0-9]+}}.4h, v{{[0-9]+}}.4h,
  // v{{[0-9]+}}.4h}, [{{x[0-9]+|sp}}]
}

void test_vst4_f32(float32_t *a, float32x2x4_t b) {
  // CHECK: test_vst4_f32
  vst4_f32(a, b);
  // CHECK: st4 {v{{[0-9]+}}.2s, v{{[0-9]+}}.2s, v{{[0-9]+}}.2s,
  // v{{[0-9]+}}.2s}, [{{x[0-9]+|sp}}]
}

void test_vst4_f64(float64_t *a, float64x1x4_t b) {
  // CHECK: test_vst4_f64
  vst4_f64(a, b);
  // CHECK: st1 {v{{[0-9]+}}.1d, v{{[0-9]+}}.1d, v{{[0-9]+}}.1d,
  // v{{[0-9]+}}.1d}, [{{x[0-9]+|sp}}]
}

void test_vst4_p8(poly8_t *a, poly8x8x4_t b) {
  // CHECK: test_vst4_p8
  vst4_p8(a, b);
  // CHECK: st4 {v{{[0-9]+}}.8b, v{{[0-9]+}}.8b, v{{[0-9]+}}.8b,
  // v{{[0-9]+}}.8b}, [{{x[0-9]+|sp}}]
}

void test_vst4_p16(poly16_t *a, poly16x4x4_t b) {
  // CHECK: test_vst4_p16
  vst4_p16(a, b);
  // CHECK: st4 {v{{[0-9]+}}.4h, v{{[0-9]+}}.4h, v{{[0-9]+}}.4h,
  // v{{[0-9]+}}.4h}, [{{x[0-9]+|sp}}]
}

int64_t test_vceqd_s64(int64_t a, int64_t b) {
// CHECK: test_vceqd_s64
// CHECK: cmeq {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
  return (int64_t)vceqd_s64(a, b);
}

uint64_t test_vceqd_u64(uint64_t a, uint64_t b) {
// CHECK: test_vceqd_u64
// CHECK: cmeq {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
  return (int64_t)vceqd_u64(a, b);
} 

int64_t test_vceqzd_s64(int64_t a) {
// CHECK: test_vceqzd_s64
// CHECK: cmeq {{d[0-9]+}}, {{d[0-9]+}}, #0x0
  return (int64_t)vceqzd_s64(a);
}

int64_t test_vceqzd_u64(int64_t a) {
// CHECK: test_vceqzd_u64
// CHECK: cmeq {{d[0-9]+}}, {{d[0-9]+}}, #0x0
  return (int64_t)vceqzd_u64(a);
}

int64_t test_vcged_s64(int64_t a, int64_t b) {
// CHECK: test_vcged_s64
// CHECK: cmge {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
  return (int64_t)vcged_s64(a, b);
}

uint64_t test_vcged_u64(uint64_t a, uint64_t b) {
// CHECK: test_vcged_u64
// CHECK: cmhs {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
    return (uint64_t)vcged_u64(a, b);
}

int64_t test_vcgezd_s64(int64_t a) {
// CHECK: test_vcgezd_s64
// CHECK: cmge {{d[0-9]+}}, {{d[0-9]+}}, #0x0
  return (int64_t)vcgezd_s64(a);
}

int64_t test_vcgtd_s64(int64_t a, int64_t b) {
// CHECK: test_vcgtd_s64
// CHECK: cmgt {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
  return (int64_t)vcgtd_s64(a, b);
}

uint64_t test_vcgtd_u64(uint64_t a, uint64_t b) {
// CHECK: test_vcgtd_u64
// CHECK: cmhi {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
  return (uint64_t)vcgtd_u64(a, b);
}

int64_t test_vcgtzd_s64(int64_t a) {
// CHECK: test_vcgtzd_s64
// CHECK: cmgt {{d[0-9]+}}, {{d[0-9]+}}, #0x0
  return (int64_t)vcgtzd_s64(a);
}

int64_t test_vcled_s64(int64_t a, int64_t b) {
// CHECK: test_vcled_s64
// CHECK: cmge {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
  return (int64_t)vcled_s64(a, b);
}

uint64_t test_vcled_u64(uint64_t a, uint64_t b) {
// CHECK: test_vcled_u64
// CHECK: cmhs {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
  return (uint64_t)vcled_u64(a, 0);
}

int64_t test_vclezd_s64(int64_t a) {
// CHECK: test_vclezd_s64
// CHECK: cmle {{d[0-9]+}}, {{d[0-9]+}}, #0x0
  return (int64_t)vclezd_s64(a);
}

int64_t test_vcltd_s64(int64_t a, int64_t b) {
// CHECK: test_vcltd_s64
// CHECK: cmgt {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
  return (int64_t)vcltd_s64(a, b);
}

uint64_t test_vcltd_u64(uint64_t a, uint64_t b) {
// CHECK: test_vcltd_u64
// CHECK: cmhi {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
  return (uint64_t)vcltd_u64(a, b);
}

int64_t test_vcltzd_s64(int64_t a) {
// CHECK: test_vcltzd_s64
// CHECK: cmlt {{d[0-9]+}}, {{d[0-9]+}}, #0x0
  return (int64_t)vcltzd_s64(a);
}

int64_t test_vtstd_s64(int64_t a, int64_t b) {
// CHECK: test_vtstd_s64
// CHECK: cmtst {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
  return (int64_t)vtstd_s64(a, b);
}

uint64_t test_vtstd_u64(uint64_t a, uint64_t b) {
// CHECK: test_vtstd_u64
// CHECK: cmtst {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
  return (uint64_t)vtstd_u64(a, b);
}

int64_t test_vabsd_s64(int64_t a) {
// CHECK: test_vabsd_s64
// CHECK: abs {{d[0-9]+}}, {{d[0-9]+}}
  return (int64_t)vabsd_s64(a);
}

int8_t test_vqabsb_s8(int8_t a) {
// CHECK: test_vqabsb_s8
// CHECK: sqabs {{b[0-9]+}}, {{b[0-9]+}}
  return (int8_t)vqabsb_s8(a);
}

int16_t test_vqabsh_s16(int16_t a) {
// CHECK: test_vqabsh_s16
// CHECK: sqabs {{h[0-9]+}}, {{h[0-9]+}}
  return (int16_t)vqabsh_s16(a);
}

int32_t test_vqabss_s32(int32_t a) {
// CHECK: test_vqabss_s32
// CHECK: sqabs {{s[0-9]+}}, {{s[0-9]+}}
  return (int32_t)vqabss_s32(a);
}

int64_t test_vqabsd_s64(int64_t a) {
// CHECK: test_vqabsd_s64
// CHECK: sqabs {{d[0-9]+}}, {{d[0-9]+}}
  return (int64_t)vqabsd_s64(a);
}

int64_t test_vnegd_s64(int64_t a) {
// CHECK: test_vnegd_s64
// CHECK: neg {{d[0-9]+}}, {{d[0-9]+}}
  return (int64_t)vnegd_s64(a);
}

int8_t test_vqnegb_s8(int8_t a) {
// CHECK: test_vqnegb_s8
// CHECK: sqneg {{b[0-9]+}}, {{b[0-9]+}}
  return (int8_t)vqnegb_s8(a);
}

int16_t test_vqnegh_s16(int16_t a) {
// CHECK: test_vqnegh_s16
// CHECK: sqneg {{h[0-9]+}}, {{h[0-9]+}}
  return (int16_t)vqnegh_s16(a);
}

int32_t test_vqnegs_s32(int32_t a) {
// CHECK: test_vqnegs_s32
// CHECK: sqneg {{s[0-9]+}}, {{s[0-9]+}}
  return (int32_t)vqnegs_s32(a);
}

int64_t test_vqnegd_s64(int64_t a) {
// CHECK: test_vqnegd_s64
// CHECK: sqneg {{d[0-9]+}}, {{d[0-9]+}}
  return (int64_t)vqnegd_s64(a);
}

int8_t test_vuqaddb_s8(int8_t a, int8_t b) {
// CHECK: test_vuqaddb_s8
// CHECK: suqadd {{b[0-9]+}}, {{b[0-9]+}}
  return (int8_t)vuqaddb_s8(a, b);
}

int16_t test_vuqaddh_s16(int16_t a, int16_t b) {
// CHECK: test_vuqaddh_s16
// CHECK: suqadd {{h[0-9]+}}, {{h[0-9]+}}
  return (int16_t)vuqaddh_s16(a, b);
}

int32_t test_vuqadds_s32(int32_t a, int32_t b) {
// CHECK: test_vuqadds_s32
// CHECK: suqadd {{s[0-9]+}}, {{s[0-9]+}}
  return (int32_t)vuqadds_s32(a, b);
}

int64_t test_vuqaddd_s64(int64_t a, int64_t b) {
// CHECK: test_vuqaddd_s64
// CHECK: suqadd {{d[0-9]+}}, {{d[0-9]+}}
  return (int64_t)vuqaddd_s64(a, b);
}

uint8_t test_vsqaddb_u8(uint8_t a, uint8_t b) {
// CHECK: test_vsqaddb_u8
// CHECK: usqadd {{b[0-9]+}}, {{b[0-9]+}}
  return (uint8_t)vsqaddb_u8(a, b);
}

uint16_t test_vsqaddh_u16(uint16_t a, uint16_t b) {
// CHECK: test_vsqaddh_u16
// CHECK: usqadd {{h[0-9]+}}, {{h[0-9]+}}
  return (uint16_t)vsqaddh_u16(a, b);
}

uint32_t test_vsqadds_u32(uint32_t a, uint32_t b) {
// CHECK: test_vsqadds_u32
// CHECK: usqadd {{s[0-9]+}}, {{s[0-9]+}}
  return (uint32_t)vsqadds_u32(a, b);
}

uint64_t test_vsqaddd_u64(uint64_t a, uint64_t b) {
// CHECK: test_vsqaddd_u64
// CHECK: usqadd {{d[0-9]+}}, {{d[0-9]+}}
  return (uint64_t)vsqaddd_u64(a, b);
}

int32_t test_vqdmlalh_s16(int16_t a, int16_t b) {
// CHECK: test_vqdmlalh_s16
// CHECK: sqdmlal {{s[0-9]+}}, {{h[0-9]+}}, {{h[0-9]+}}
  return (int32_t)vqdmlalh_s16(a, b);
}

int64_t test_vqdmlals_s32(int32_t a, int32_t b) {
// CHECK: test_vqdmlals_s32
// CHECK: sqdmlal {{d[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
  return (int64_t)vqdmlals_s32(a, b);
}

int32_t test_vqdmlslh_s16(int16_t a, int16_t b) {
// CHECK: test_vqdmlslh_s16
// CHECK: sqdmlsl {{s[0-9]+}}, {{h[0-9]+}}, {{h[0-9]+}}
  return (int32_t)vqdmlslh_s16(a, b);
}

int64_t test_vqdmlsls_s32(int32_t a, int32_t b) {
// CHECK: test_vqdmlsls_s32
// CHECK: sqdmlsl {{d[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
  return (int64_t)vqdmlsls_s32(a, b);
}

int32_t test_vqdmullh_s16(int16_t a, int16_t b) {
// CHECK: test_vqdmullh_s16
// CHECK: sqdmull {{s[0-9]+}}, {{h[0-9]+}}, {{h[0-9]+}}
  return (int32_t)vqdmullh_s16(a, b);
}

int64_t test_vqdmulls_s32(int32_t a, int32_t b) {
// CHECK: test_vqdmulls_s32
// CHECK: sqdmull {{d[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
  return (int64_t)vqdmulls_s32(a, b);
}
