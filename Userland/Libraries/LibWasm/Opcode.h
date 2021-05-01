/*
 * Copyright (c) 2021, Ali Mohammad Pur <mpfard@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/DistinctNumeric.h>

namespace Wasm {

TYPEDEF_DISTINCT_ORDERED_ID(u32, OpCode);

namespace Instructions {

static constexpr OpCode unreachable = 0x00,
                        nop = 0x01,
                        block = 0x02,
                        loop = 0x03,
                        if_ = 0x04,
                        br = 0x0c,
                        br_if = 0x0d,
                        br_table = 0x0e,
                        return_ = 0x0f,
                        call = 0x10,
                        call_indirect = 0x11,
                        drop = 0x1a,
                        select = 0x1b,
                        select_typed = 0x1c,
                        local_get = 0x20,
                        local_set = 0x21,
                        local_tee = 0x22,
                        global_get = 0x23,
                        global_set = 0x24,
                        table_get = 0x25,
                        table_set = 0x26,
                        i32_load = 0x28,
                        i64_load = 0x29,
                        f32_load = 0x2a,
                        f64_load = 0x2b,
                        i32_load8_s = 0x2c,
                        i32_load8_u = 0x2d,
                        i32_load16_s = 0x2e,
                        i32_load16_u = 0x2f,
                        i64_load8_s = 0x30,
                        i64_load8_u = 0x31,
                        i64_load16_s = 0x32,
                        i64_load16_u = 0x33,
                        i64_load32_s = 0x34,
                        i64_load32_u = 0x35,
                        i32_store = 0x36,
                        i64_store = 0x37,
                        f32_store = 0x38,
                        f64_store = 0x39,
                        i32_store8 = 0x3a,
                        i32_store16 = 0x3b,
                        i64_store8 = 0x3c,
                        i64_store16 = 0x3d,
                        i64_store32 = 0x3e,
                        memory_size = 0x3f,
                        memory_grow = 0x40,
                        i32_const = 0x41,
                        i64_const = 0x42,
                        f32_const = 0x43,
                        f64_const = 0x44,
                        i32_eqz = 0x45,
                        i32_eq = 0x46,
                        i32_ne = 0x47,
                        i32_lts = 0x48,
                        i32_ltu = 0x49,
                        i32_gts = 0x4a,
                        i32_gtu = 0x4b,
                        i32_les = 0x4c,
                        i32_leu = 0x4d,
                        i32_ges = 0x4e,
                        i32_geu = 0x4f,
                        i64_eqz = 0x50,
                        i64_eq = 0x51,
                        i64_ne = 0x52,
                        i64_lts = 0x53,
                        i64_ltu = 0x54,
                        i64_gts = 0x55,
                        i64_gtu = 0x56,
                        i64_les = 0x57,
                        i64_leu = 0x58,
                        i64_ges = 0x59,
                        i64_geu = 0x5a,
                        f32_eq = 0x5b,
                        f32_ne = 0x5c,
                        f32_lt = 0x5d,
                        f32_gt = 0x5e,
                        f32_le = 0x5f,
                        f32_ge = 0x60,
                        f64_eq = 0x61,
                        f64_ne = 0x62,
                        f64_lt = 0x63,
                        f64_gt = 0x64,
                        f64_le = 0x65,
                        f64_ge = 0x66,
                        i32_clz = 0x67,
                        i32_ctz = 0x68,
                        i32_popcnt = 0x69,
                        i32_add = 0x6a,
                        i32_sub = 0x6b,
                        i32_mul = 0x6c,
                        i32_divs = 0x6d,
                        i32_divu = 0x6e,
                        i32_rems = 0x6f,
                        i32_remu = 0x70,
                        i32_and = 0x71,
                        i32_or = 0x72,
                        i32_xor = 0x73,
                        i32_shl = 0x74,
                        i32_shrs = 0x75,
                        i32_shru = 0x76,
                        i32_rotl = 0x77,
                        i32_rotr = 0x78,
                        i64_clz = 0x79,
                        i64_ctz = 0x7a,
                        i64_popcnt = 0x7b,
                        i64_add = 0x7c,
                        i64_sub = 0x7d,
                        i64_mul = 0x7e,
                        i64_divs = 0x7f,
                        i64_divu = 0x80,
                        i64_rems = 0x81,
                        i64_remu = 0x82,
                        i64_and = 0x83,
                        i64_or = 0x84,
                        i64_xor = 0x85,
                        i64_shl = 0x86,
                        i64_shrs = 0x87,
                        i64_shru = 0x88,
                        i64_rotl = 0x89,
                        i64_rotr = 0x8a,
                        f32_abs = 0x8b,
                        f32_neg = 0x8c,
                        f32_ceil = 0x8d,
                        f32_floor = 0x8e,
                        f32_trunc = 0x8f,
                        f32_nearest = 0x90,
                        f32_sqrt = 0x91,
                        f32_add = 0x92,
                        f32_sub = 0x93,
                        f32_mul = 0x94,
                        f32_div = 0x95,
                        f32_min = 0x96,
                        f32_max = 0x97,
                        f32_copysign = 0x98,
                        f64_abs = 0x99,
                        f64_neg = 0x9a,
                        f64_ceil = 0x9b,
                        f64_floor = 0x9c,
                        f64_trunc = 0x9d,
                        f64_nearest = 0x9e,
                        f64_sqrt = 0x9f,
                        f64_add = 0xa0,
                        f64_sub = 0xa1,
                        f64_mul = 0xa2,
                        f64_div = 0xa3,
                        f64_min = 0xa4,
                        f64_max = 0xa5,
                        f64_copysign = 0xa6,
                        i32_wrap_i64 = 0xa7,
                        i32_trunc_sf32 = 0xa8,
                        i32_trunc_uf32 = 0xa9,
                        i32_trunc_sf64 = 0xaa,
                        i32_trunc_uf64 = 0xab,
                        i64_extend_si32 = 0xac,
                        i64_extend_ui32 = 0xad,
                        i64_trunc_sf32 = 0xae,
                        i64_trunc_uf32 = 0xaf,
                        i64_trunc_sf64 = 0xb0,
                        i64_trunc_uf64 = 0xb1,
                        f32_convert_si32 = 0xb2,
                        f32_convert_ui32 = 0xb3,
                        f32_convert_si64 = 0xb4,
                        f32_convert_ui64 = 0xb5,
                        f32_demote_f64 = 0xb6,
                        f64_convert_si32 = 0xb7,
                        f64_convert_ui32 = 0xb8,
                        f64_convert_si64 = 0xb9,
                        f64_convert_ui64 = 0xba,
                        f64_promote_f32 = 0xbb,
                        i32_reinterpret_f32 = 0xbc,
                        i64_reinterpret_f64 = 0xbd,
                        f32_reinterpret_i32 = 0xbe,
                        f64_reinterpret_i64 = 0xbf,
                        ref_null = 0xd0,
                        ref_is_null = 0xd1,
                        ref_func = 0xd2;

// These are synthetic opcodes, they are _not_ seen in wasm with these values.
static constexpr OpCode i32_trunc_sat_f32_s = 0xfc00,
                        i32_trunc_sat_f32_u = 0xfc01,
                        i32_trunc_sat_f64_s = 0xfc02,
                        i32_trunc_sat_f64_u = 0xfc03,
                        i64_trunc_sat_f32_s = 0xfc04,
                        i64_trunc_sat_f32_u = 0xfc05,
                        i64_trunc_sat_f64_s = 0xfc06,
                        i64_trunc_sat_f64_u = 0xfc07,
                        memory_init = 0xfc08,
                        data_drop = 0xfc09,
                        memory_copy = 0xfc0a,
                        memory_fill = 0x0fc0b,
                        table_init = 0xfc0c,
                        elem_drop = 0xfc0d,
                        table_copy = 0xfc0e,
                        table_grow = 0xfc0f,
                        table_size = 0xfc10,
                        table_fill = 0xfc11,
                        structured_else = 0xff00,
                        structured_end = 0xff01;

static constexpr u32 i32_trunc_sat_f32_s_second = 0,
                     i32_trunc_sat_f32_u_second = 1,
                     i32_trunc_sat_f64_s_second = 2,
                     i32_trunc_sat_f64_u_second = 3,
                     i64_trunc_sat_f32_s_second = 4,
                     i64_trunc_sat_f32_u_second = 5,
                     i64_trunc_sat_f64_s_second = 6,
                     i64_trunc_sat_f64_u_second = 7,
                     memory_init_second = 8,
                     data_drop_second = 9,
                     memory_copy_second = 10,
                     memory_fill_second = 11,
                     table_init_second = 12,
                     elem_drop_second = 13,
                     table_copy_second = 14,
                     table_grow_second = 15,
                     table_size_second = 16,
                     table_fill_second = 17;

}

}
