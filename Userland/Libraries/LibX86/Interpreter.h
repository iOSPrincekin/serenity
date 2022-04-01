/*
 * Copyright (c) 2020, Andreas Kling <kling@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/Types.h>

namespace X86 {

class Instruction;

class Interpreter {
public:
    virtual void AAA(Instruction const&) = 0;
    virtual void AAD(Instruction const&) = 0;
    virtual void AAM(Instruction const&) = 0;
    virtual void AAS(Instruction const&) = 0;
    virtual void ADC_AL_imm8(Instruction const&) = 0;
    virtual void ADC_AX_imm16(Instruction const&) = 0;
    virtual void ADC_EAX_imm32(Instruction const&) = 0;
    virtual void ADC_RM16_imm16(Instruction const&) = 0;
    virtual void ADC_RM16_imm8(Instruction const&) = 0;
    virtual void ADC_RM16_reg16(Instruction const&) = 0;
    virtual void ADC_RM32_imm32(Instruction const&) = 0;
    virtual void ADC_RM32_imm8(Instruction const&) = 0;
    virtual void ADC_RM32_reg32(Instruction const&) = 0;
    virtual void ADC_RM8_imm8(Instruction const&) = 0;
    virtual void ADC_RM8_reg8(Instruction const&) = 0;
    virtual void ADC_reg16_RM16(Instruction const&) = 0;
    virtual void ADC_reg32_RM32(Instruction const&) = 0;
    virtual void ADC_reg8_RM8(Instruction const&) = 0;
    virtual void ADD_AL_imm8(Instruction const&) = 0;
    virtual void ADD_AX_imm16(Instruction const&) = 0;
    virtual void ADD_EAX_imm32(Instruction const&) = 0;
    virtual void ADD_RM16_imm16(Instruction const&) = 0;
    virtual void ADD_RM16_imm8(Instruction const&) = 0;
    virtual void ADD_RM16_reg16(Instruction const&) = 0;
    virtual void ADD_RM32_imm32(Instruction const&) = 0;
    virtual void ADD_RM32_imm8(Instruction const&) = 0;
    virtual void ADD_RM32_reg32(Instruction const&) = 0;
    virtual void ADD_RM8_imm8(Instruction const&) = 0;
    virtual void ADD_RM8_reg8(Instruction const&) = 0;
    virtual void ADD_reg16_RM16(Instruction const&) = 0;
    virtual void ADD_reg32_RM32(Instruction const&) = 0;
    virtual void ADD_reg8_RM8(Instruction const&) = 0;
    virtual void AND_AL_imm8(Instruction const&) = 0;
    virtual void AND_AX_imm16(Instruction const&) = 0;
    virtual void AND_EAX_imm32(Instruction const&) = 0;
    virtual void AND_RM16_imm16(Instruction const&) = 0;
    virtual void AND_RM16_imm8(Instruction const&) = 0;
    virtual void AND_RM16_reg16(Instruction const&) = 0;
    virtual void AND_RM32_imm32(Instruction const&) = 0;
    virtual void AND_RM32_imm8(Instruction const&) = 0;
    virtual void AND_RM32_reg32(Instruction const&) = 0;
    virtual void AND_RM8_imm8(Instruction const&) = 0;
    virtual void AND_RM8_reg8(Instruction const&) = 0;
    virtual void AND_reg16_RM16(Instruction const&) = 0;
    virtual void AND_reg32_RM32(Instruction const&) = 0;
    virtual void AND_reg8_RM8(Instruction const&) = 0;
    virtual void ARPL(Instruction const&) = 0;
    virtual void BOUND(Instruction const&) = 0;
    virtual void BSF_reg16_RM16(Instruction const&) = 0;
    virtual void BSF_reg32_RM32(Instruction const&) = 0;
    virtual void BSR_reg16_RM16(Instruction const&) = 0;
    virtual void BSR_reg32_RM32(Instruction const&) = 0;
    virtual void BSWAP_reg32(Instruction const&) = 0;
    virtual void BTC_RM16_imm8(Instruction const&) = 0;
    virtual void BTC_RM16_reg16(Instruction const&) = 0;
    virtual void BTC_RM32_imm8(Instruction const&) = 0;
    virtual void BTC_RM32_reg32(Instruction const&) = 0;
    virtual void BTR_RM16_imm8(Instruction const&) = 0;
    virtual void BTR_RM16_reg16(Instruction const&) = 0;
    virtual void BTR_RM32_imm8(Instruction const&) = 0;
    virtual void BTR_RM32_reg32(Instruction const&) = 0;
    virtual void BTS_RM16_imm8(Instruction const&) = 0;
    virtual void BTS_RM16_reg16(Instruction const&) = 0;
    virtual void BTS_RM32_imm8(Instruction const&) = 0;
    virtual void BTS_RM32_reg32(Instruction const&) = 0;
    virtual void BT_RM16_imm8(Instruction const&) = 0;
    virtual void BT_RM16_reg16(Instruction const&) = 0;
    virtual void BT_RM32_imm8(Instruction const&) = 0;
    virtual void BT_RM32_reg32(Instruction const&) = 0;
    virtual void CALL_FAR_mem16(Instruction const&) = 0;
    virtual void CALL_FAR_mem32(Instruction const&) = 0;
    virtual void CALL_RM16(Instruction const&) = 0;
    virtual void CALL_RM32(Instruction const&) = 0;
    virtual void CALL_imm16(Instruction const&) = 0;
    virtual void CALL_imm16_imm16(Instruction const&) = 0;
    virtual void CALL_imm16_imm32(Instruction const&) = 0;
    virtual void CALL_imm32(Instruction const&) = 0;
    virtual void CBW(Instruction const&) = 0;
    virtual void CDQ(Instruction const&) = 0;
    virtual void CLC(Instruction const&) = 0;
    virtual void CLD(Instruction const&) = 0;
    virtual void CLI(Instruction const&) = 0;
    virtual void CLTS(Instruction const&) = 0;
    virtual void CMC(Instruction const&) = 0;
    virtual void CMOVcc_reg16_RM16(Instruction const&) = 0;
    virtual void CMOVcc_reg32_RM32(Instruction const&) = 0;
    virtual void CMPSB(Instruction const&) = 0;
    virtual void CMPSD(Instruction const&) = 0;
    virtual void CMPSW(Instruction const&) = 0;
    virtual void CMPXCHG_RM16_reg16(Instruction const&) = 0;
    virtual void CMPXCHG_RM32_reg32(Instruction const&) = 0;
    virtual void CMPXCHG_RM8_reg8(Instruction const&) = 0;
    virtual void CMP_AL_imm8(Instruction const&) = 0;
    virtual void CMP_AX_imm16(Instruction const&) = 0;
    virtual void CMP_EAX_imm32(Instruction const&) = 0;
    virtual void CMP_RM16_imm16(Instruction const&) = 0;
    virtual void CMP_RM16_imm8(Instruction const&) = 0;
    virtual void CMP_RM16_reg16(Instruction const&) = 0;
    virtual void CMP_RM32_imm32(Instruction const&) = 0;
    virtual void CMP_RM32_imm8(Instruction const&) = 0;
    virtual void CMP_RM32_reg32(Instruction const&) = 0;
    virtual void CMP_RM8_imm8(Instruction const&) = 0;
    virtual void CMP_RM8_reg8(Instruction const&) = 0;
    virtual void CMP_reg16_RM16(Instruction const&) = 0;
    virtual void CMP_reg32_RM32(Instruction const&) = 0;
    virtual void CMP_reg8_RM8(Instruction const&) = 0;
    virtual void CPUID(Instruction const&) = 0;
    virtual void CWD(Instruction const&) = 0;
    virtual void CWDE(Instruction const&) = 0;
    virtual void DAA(Instruction const&) = 0;
    virtual void DAS(Instruction const&) = 0;
    virtual void DEC_RM16(Instruction const&) = 0;
    virtual void DEC_RM32(Instruction const&) = 0;
    virtual void DEC_RM8(Instruction const&) = 0;
    virtual void DEC_reg16(Instruction const&) = 0;
    virtual void DEC_reg32(Instruction const&) = 0;
    virtual void DIV_RM16(Instruction const&) = 0;
    virtual void DIV_RM32(Instruction const&) = 0;
    virtual void DIV_RM8(Instruction const&) = 0;
    virtual void ENTER16(Instruction const&) = 0;
    virtual void ENTER32(Instruction const&) = 0;
    virtual void ESCAPE(Instruction const&) = 0;
    virtual void FADD_RM32(Instruction const&) = 0;
    virtual void FMUL_RM32(Instruction const&) = 0;
    virtual void FCOM_RM32(Instruction const&) = 0;
    virtual void FCOMP_RM32(Instruction const&) = 0;
    virtual void FSUB_RM32(Instruction const&) = 0;
    virtual void FSUBR_RM32(Instruction const&) = 0;
    virtual void FDIV_RM32(Instruction const&) = 0;
    virtual void FDIVR_RM32(Instruction const&) = 0;
    virtual void FLD_RM32(Instruction const&) = 0;
    virtual void FXCH(Instruction const&) = 0;
    virtual void FST_RM32(Instruction const&) = 0;
    virtual void FNOP(Instruction const&) = 0;
    virtual void FSTP_RM32(Instruction const&) = 0;
    virtual void FLDENV(Instruction const&) = 0;
    virtual void FCHS(Instruction const&) = 0;
    virtual void FABS(Instruction const&) = 0;
    virtual void FTST(Instruction const&) = 0;
    virtual void FXAM(Instruction const&) = 0;
    virtual void FLDCW(Instruction const&) = 0;
    virtual void FLD1(Instruction const&) = 0;
    virtual void FLDL2T(Instruction const&) = 0;
    virtual void FLDL2E(Instruction const&) = 0;
    virtual void FLDPI(Instruction const&) = 0;
    virtual void FLDLG2(Instruction const&) = 0;
    virtual void FLDLN2(Instruction const&) = 0;
    virtual void FLDZ(Instruction const&) = 0;
    virtual void FNSTENV(Instruction const&) = 0;
    virtual void F2XM1(Instruction const&) = 0;
    virtual void FYL2X(Instruction const&) = 0;
    virtual void FPTAN(Instruction const&) = 0;
    virtual void FPATAN(Instruction const&) = 0;
    virtual void FXTRACT(Instruction const&) = 0;
    virtual void FPREM1(Instruction const&) = 0;
    virtual void FDECSTP(Instruction const&) = 0;
    virtual void FINCSTP(Instruction const&) = 0;
    virtual void FNSTCW(Instruction const&) = 0;
    virtual void FPREM(Instruction const&) = 0;
    virtual void FYL2XP1(Instruction const&) = 0;
    virtual void FSQRT(Instruction const&) = 0;
    virtual void FSINCOS(Instruction const&) = 0;
    virtual void FRNDINT(Instruction const&) = 0;
    virtual void FSCALE(Instruction const&) = 0;
    virtual void FSIN(Instruction const&) = 0;
    virtual void FCOS(Instruction const&) = 0;
    virtual void FIADD_RM32(Instruction const&) = 0;
    virtual void FADDP(Instruction const&) = 0;
    virtual void FIMUL_RM32(Instruction const&) = 0;
    virtual void FCMOVE(Instruction const&) = 0;
    virtual void FICOM_RM32(Instruction const&) = 0;
    virtual void FCMOVBE(Instruction const&) = 0;
    virtual void FICOMP_RM32(Instruction const&) = 0;
    virtual void FCMOVU(Instruction const&) = 0;
    virtual void FISUB_RM32(Instruction const&) = 0;
    virtual void FISUBR_RM32(Instruction const&) = 0;
    virtual void FUCOMPP(Instruction const&) = 0;
    virtual void FIDIV_RM32(Instruction const&) = 0;
    virtual void FIDIVR_RM32(Instruction const&) = 0;
    virtual void FILD_RM32(Instruction const&) = 0;
    virtual void FCMOVNB(Instruction const&) = 0;
    virtual void FISTTP_RM32(Instruction const&) = 0;
    virtual void FCMOVNE(Instruction const&) = 0;
    virtual void FIST_RM32(Instruction const&) = 0;
    virtual void FCMOVNBE(Instruction const&) = 0;
    virtual void FISTP_RM32(Instruction const&) = 0;
    virtual void FCMOVNU(Instruction const&) = 0;
    virtual void FNENI(Instruction const&) = 0;
    virtual void FNDISI(Instruction const&) = 0;
    virtual void FNCLEX(Instruction const&) = 0;
    virtual void FNINIT(Instruction const&) = 0;
    virtual void FNSETPM(Instruction const&) = 0;
    virtual void FLD_RM80(Instruction const&) = 0;
    virtual void FUCOMI(Instruction const&) = 0;
    virtual void FCOMI(Instruction const&) = 0;
    virtual void FSTP_RM80(Instruction const&) = 0;
    virtual void FADD_RM64(Instruction const&) = 0;
    virtual void FMUL_RM64(Instruction const&) = 0;
    virtual void FCOM_RM64(Instruction const&) = 0;
    virtual void FCOMP_RM64(Instruction const&) = 0;
    virtual void FSUB_RM64(Instruction const&) = 0;
    virtual void FSUBR_RM64(Instruction const&) = 0;
    virtual void FDIV_RM64(Instruction const&) = 0;
    virtual void FDIVR_RM64(Instruction const&) = 0;
    virtual void FLD_RM64(Instruction const&) = 0;
    virtual void FFREE(Instruction const&) = 0;
    virtual void FISTTP_RM64(Instruction const&) = 0;
    virtual void FST_RM64(Instruction const&) = 0;
    virtual void FSTP_RM64(Instruction const&) = 0;
    virtual void FRSTOR(Instruction const&) = 0;
    virtual void FUCOM(Instruction const&) = 0;
    virtual void FUCOMP(Instruction const&) = 0;
    virtual void FNSAVE(Instruction const&) = 0;
    virtual void FNSTSW(Instruction const&) = 0;
    virtual void FIADD_RM16(Instruction const&) = 0;
    virtual void FCMOVB(Instruction const&) = 0;
    virtual void FIMUL_RM16(Instruction const&) = 0;
    virtual void FMULP(Instruction const&) = 0;
    virtual void FICOM_RM16(Instruction const&) = 0;
    virtual void FICOMP_RM16(Instruction const&) = 0;
    virtual void FCOMPP(Instruction const&) = 0;
    virtual void FISUB_RM16(Instruction const&) = 0;
    virtual void FSUBRP(Instruction const&) = 0;
    virtual void FISUBR_RM16(Instruction const&) = 0;
    virtual void FSUBP(Instruction const&) = 0;
    virtual void FIDIV_RM16(Instruction const&) = 0;
    virtual void FDIVRP(Instruction const&) = 0;
    virtual void FIDIVR_RM16(Instruction const&) = 0;
    virtual void FDIVP(Instruction const&) = 0;
    virtual void FILD_RM16(Instruction const&) = 0;
    virtual void FFREEP(Instruction const&) = 0;
    virtual void FISTTP_RM16(Instruction const&) = 0;
    virtual void FIST_RM16(Instruction const&) = 0;
    virtual void FISTP_RM16(Instruction const&) = 0;
    virtual void FBLD_M80(Instruction const&) = 0;
    virtual void FNSTSW_AX(Instruction const&) = 0;
    virtual void FILD_RM64(Instruction const&) = 0;
    virtual void FUCOMIP(Instruction const&) = 0;
    virtual void FBSTP_M80(Instruction const&) = 0;
    virtual void FCOMIP(Instruction const&) = 0;
    virtual void FISTP_RM64(Instruction const&) = 0;
    virtual void HLT(Instruction const&) = 0;
    virtual void IDIV_RM16(Instruction const&) = 0;
    virtual void IDIV_RM32(Instruction const&) = 0;
    virtual void IDIV_RM8(Instruction const&) = 0;
    virtual void IMUL_RM16(Instruction const&) = 0;
    virtual void IMUL_RM32(Instruction const&) = 0;
    virtual void IMUL_RM8(Instruction const&) = 0;
    virtual void IMUL_reg16_RM16(Instruction const&) = 0;
    virtual void IMUL_reg16_RM16_imm16(Instruction const&) = 0;
    virtual void IMUL_reg16_RM16_imm8(Instruction const&) = 0;
    virtual void IMUL_reg32_RM32(Instruction const&) = 0;
    virtual void IMUL_reg32_RM32_imm32(Instruction const&) = 0;
    virtual void IMUL_reg32_RM32_imm8(Instruction const&) = 0;
    virtual void INC_RM16(Instruction const&) = 0;
    virtual void INC_RM32(Instruction const&) = 0;
    virtual void INC_RM8(Instruction const&) = 0;
    virtual void INC_reg16(Instruction const&) = 0;
    virtual void INC_reg32(Instruction const&) = 0;
    virtual void INSB(Instruction const&) = 0;
    virtual void INSD(Instruction const&) = 0;
    virtual void INSW(Instruction const&) = 0;
    virtual void INT1(Instruction const&) = 0;
    virtual void INT3(Instruction const&) = 0;
    virtual void INTO(Instruction const&) = 0;
    virtual void INT_imm8(Instruction const&) = 0;
    virtual void INVLPG(Instruction const&) = 0;
    virtual void IN_AL_DX(Instruction const&) = 0;
    virtual void IN_AL_imm8(Instruction const&) = 0;
    virtual void IN_AX_DX(Instruction const&) = 0;
    virtual void IN_AX_imm8(Instruction const&) = 0;
    virtual void IN_EAX_DX(Instruction const&) = 0;
    virtual void IN_EAX_imm8(Instruction const&) = 0;
    virtual void IRET(Instruction const&) = 0;
    virtual void JCXZ_imm8(Instruction const&) = 0;
    virtual void JMP_FAR_mem16(Instruction const&) = 0;
    virtual void JMP_FAR_mem32(Instruction const&) = 0;
    virtual void JMP_RM16(Instruction const&) = 0;
    virtual void JMP_RM32(Instruction const&) = 0;
    virtual void JMP_imm16(Instruction const&) = 0;
    virtual void JMP_imm16_imm16(Instruction const&) = 0;
    virtual void JMP_imm16_imm32(Instruction const&) = 0;
    virtual void JMP_imm32(Instruction const&) = 0;
    virtual void JMP_short_imm8(Instruction const&) = 0;
    virtual void Jcc_NEAR_imm(Instruction const&) = 0;
    virtual void Jcc_imm8(Instruction const&) = 0;
    virtual void LAHF(Instruction const&) = 0;
    virtual void LAR_reg16_RM16(Instruction const&) = 0;
    virtual void LAR_reg32_RM32(Instruction const&) = 0;
    virtual void LDS_reg16_mem16(Instruction const&) = 0;
    virtual void LDS_reg32_mem32(Instruction const&) = 0;
    virtual void LEAVE16(Instruction const&) = 0;
    virtual void LEAVE32(Instruction const&) = 0;
    virtual void LEA_reg16_mem16(Instruction const&) = 0;
    virtual void LEA_reg32_mem32(Instruction const&) = 0;
    virtual void LES_reg16_mem16(Instruction const&) = 0;
    virtual void LES_reg32_mem32(Instruction const&) = 0;
    virtual void LFS_reg16_mem16(Instruction const&) = 0;
    virtual void LFS_reg32_mem32(Instruction const&) = 0;
    virtual void LGDT(Instruction const&) = 0;
    virtual void LGS_reg16_mem16(Instruction const&) = 0;
    virtual void LGS_reg32_mem32(Instruction const&) = 0;
    virtual void LIDT(Instruction const&) = 0;
    virtual void LLDT_RM16(Instruction const&) = 0;
    virtual void LMSW_RM16(Instruction const&) = 0;
    virtual void LODSB(Instruction const&) = 0;
    virtual void LODSD(Instruction const&) = 0;
    virtual void LODSW(Instruction const&) = 0;
    virtual void LOOPNZ_imm8(Instruction const&) = 0;
    virtual void LOOPZ_imm8(Instruction const&) = 0;
    virtual void LOOP_imm8(Instruction const&) = 0;
    virtual void LSL_reg16_RM16(Instruction const&) = 0;
    virtual void LSL_reg32_RM32(Instruction const&) = 0;
    virtual void LSS_reg16_mem16(Instruction const&) = 0;
    virtual void LSS_reg32_mem32(Instruction const&) = 0;
    virtual void LTR_RM16(Instruction const&) = 0;
    virtual void MOVSB(Instruction const&) = 0;
    virtual void MOVSD(Instruction const&) = 0;
    virtual void MOVSW(Instruction const&) = 0;
    virtual void MOVSX_reg16_RM8(Instruction const&) = 0;
    virtual void MOVSX_reg32_RM16(Instruction const&) = 0;
    virtual void MOVSX_reg32_RM8(Instruction const&) = 0;
    virtual void MOVZX_reg16_RM8(Instruction const&) = 0;
    virtual void MOVZX_reg32_RM16(Instruction const&) = 0;
    virtual void MOVZX_reg32_RM8(Instruction const&) = 0;
    virtual void MOV_AL_moff8(Instruction const&) = 0;
    virtual void MOV_AX_moff16(Instruction const&) = 0;
    virtual void MOV_CR_reg32(Instruction const&) = 0;
    virtual void MOV_DR_reg32(Instruction const&) = 0;
    virtual void MOV_EAX_moff32(Instruction const&) = 0;
    virtual void MOV_RM16_imm16(Instruction const&) = 0;
    virtual void MOV_RM16_reg16(Instruction const&) = 0;
    virtual void MOV_RM16_seg(Instruction const&) = 0;
    virtual void MOV_RM32_imm32(Instruction const&) = 0;
    virtual void MOV_RM32_reg32(Instruction const&) = 0;
    virtual void MOV_RM8_imm8(Instruction const&) = 0;
    virtual void MOV_RM8_reg8(Instruction const&) = 0;
    virtual void MOV_moff16_AX(Instruction const&) = 0;
    virtual void MOV_moff32_EAX(Instruction const&) = 0;
    virtual void MOV_moff8_AL(Instruction const&) = 0;
    virtual void MOV_reg16_RM16(Instruction const&) = 0;
    virtual void MOV_reg16_imm16(Instruction const&) = 0;
    virtual void MOV_reg32_CR(Instruction const&) = 0;
    virtual void MOV_reg32_DR(Instruction const&) = 0;
    virtual void MOV_reg32_RM32(Instruction const&) = 0;
    virtual void MOV_reg32_imm32(Instruction const&) = 0;
    virtual void MOV_reg8_RM8(Instruction const&) = 0;
    virtual void MOV_reg8_imm8(Instruction const&) = 0;
    virtual void MOV_seg_RM16(Instruction const&) = 0;
    virtual void MOV_seg_RM32(Instruction const&) = 0;
    virtual void MUL_RM16(Instruction const&) = 0;
    virtual void MUL_RM32(Instruction const&) = 0;
    virtual void MUL_RM8(Instruction const&) = 0;
    virtual void NEG_RM16(Instruction const&) = 0;
    virtual void NEG_RM32(Instruction const&) = 0;
    virtual void NEG_RM8(Instruction const&) = 0;
    virtual void NOP(Instruction const&) = 0;
    virtual void NOT_RM16(Instruction const&) = 0;
    virtual void NOT_RM32(Instruction const&) = 0;
    virtual void NOT_RM8(Instruction const&) = 0;
    virtual void OR_AL_imm8(Instruction const&) = 0;
    virtual void OR_AX_imm16(Instruction const&) = 0;
    virtual void OR_EAX_imm32(Instruction const&) = 0;
    virtual void OR_RM16_imm16(Instruction const&) = 0;
    virtual void OR_RM16_imm8(Instruction const&) = 0;
    virtual void OR_RM16_reg16(Instruction const&) = 0;
    virtual void OR_RM32_imm32(Instruction const&) = 0;
    virtual void OR_RM32_imm8(Instruction const&) = 0;
    virtual void OR_RM32_reg32(Instruction const&) = 0;
    virtual void OR_RM8_imm8(Instruction const&) = 0;
    virtual void OR_RM8_reg8(Instruction const&) = 0;
    virtual void OR_reg16_RM16(Instruction const&) = 0;
    virtual void OR_reg32_RM32(Instruction const&) = 0;
    virtual void OR_reg8_RM8(Instruction const&) = 0;
    virtual void OUTSB(Instruction const&) = 0;
    virtual void OUTSD(Instruction const&) = 0;
    virtual void OUTSW(Instruction const&) = 0;
    virtual void OUT_DX_AL(Instruction const&) = 0;
    virtual void OUT_DX_AX(Instruction const&) = 0;
    virtual void OUT_DX_EAX(Instruction const&) = 0;
    virtual void OUT_imm8_AL(Instruction const&) = 0;
    virtual void OUT_imm8_AX(Instruction const&) = 0;
    virtual void OUT_imm8_EAX(Instruction const&) = 0;
    virtual void PACKSSDW_mm1_mm2m64(Instruction const&) = 0;
    virtual void PACKSSWB_mm1_mm2m64(Instruction const&) = 0;
    virtual void PACKUSWB_mm1_mm2m64(Instruction const&) = 0;
    virtual void PADDB_mm1_mm2m64(Instruction const&) = 0;
    virtual void PADDW_mm1_mm2m64(Instruction const&) = 0;
    virtual void PADDD_mm1_mm2m64(Instruction const&) = 0;
    virtual void PADDSB_mm1_mm2m64(Instruction const&) = 0;
    virtual void PADDSW_mm1_mm2m64(Instruction const&) = 0;
    virtual void PADDUSB_mm1_mm2m64(Instruction const&) = 0;
    virtual void PADDUSW_mm1_mm2m64(Instruction const&) = 0;
    virtual void PAND_mm1_mm2m64(Instruction const&) = 0;
    virtual void PANDN_mm1_mm2m64(Instruction const&) = 0;
    virtual void PCMPEQB_mm1_mm2m64(Instruction const&) = 0;
    virtual void PCMPEQW_mm1_mm2m64(Instruction const&) = 0;
    virtual void PCMPEQD_mm1_mm2m64(Instruction const&) = 0;
    virtual void PCMPGTB_mm1_mm2m64(Instruction const&) = 0;
    virtual void PCMPGTW_mm1_mm2m64(Instruction const&) = 0;
    virtual void PCMPGTD_mm1_mm2m64(Instruction const&) = 0;
    virtual void PMADDWD_mm1_mm2m64(Instruction const&) = 0;
    virtual void PMULHW_mm1_mm2m64(Instruction const&) = 0;
    virtual void PMULLW_mm1_mm2m64(Instruction const&) = 0;
    virtual void POPA(Instruction const&) = 0;
    virtual void POPAD(Instruction const&) = 0;
    virtual void POPF(Instruction const&) = 0;
    virtual void POPFD(Instruction const&) = 0;
    virtual void POP_DS(Instruction const&) = 0;
    virtual void POP_ES(Instruction const&) = 0;
    virtual void POP_FS(Instruction const&) = 0;
    virtual void POP_GS(Instruction const&) = 0;
    virtual void POP_RM16(Instruction const&) = 0;
    virtual void POP_RM32(Instruction const&) = 0;
    virtual void POP_SS(Instruction const&) = 0;
    virtual void POP_reg16(Instruction const&) = 0;
    virtual void POP_reg32(Instruction const&) = 0;
    virtual void POR_mm1_mm2m64(Instruction const&) = 0;
    virtual void PSLLW_mm1_mm2m64(Instruction const&) = 0;
    virtual void PSLLW_mm1_imm8(Instruction const&) = 0;
    virtual void PSLLD_mm1_mm2m64(Instruction const&) = 0;
    virtual void PSLLD_mm1_imm8(Instruction const&) = 0;
    virtual void PSLLQ_mm1_mm2m64(Instruction const&) = 0;
    virtual void PSLLQ_mm1_imm8(Instruction const&) = 0;
    virtual void PSRAW_mm1_mm2m64(Instruction const&) = 0;
    virtual void PSRAW_mm1_imm8(Instruction const&) = 0;
    virtual void PSRAD_mm1_mm2m64(Instruction const&) = 0;
    virtual void PSRAD_mm1_imm8(Instruction const&) = 0;
    virtual void PSRLW_mm1_mm2m64(Instruction const&) = 0;
    virtual void PSRLW_mm1_imm8(Instruction const&) = 0;
    virtual void PSRLD_mm1_mm2m64(Instruction const&) = 0;
    virtual void PSRLD_mm1_imm8(Instruction const&) = 0;
    virtual void PSRLQ_mm1_mm2m64(Instruction const&) = 0;
    virtual void PSRLQ_mm1_imm8(Instruction const&) = 0;
    virtual void PSUBB_mm1_mm2m64(Instruction const&) = 0;
    virtual void PSUBW_mm1_mm2m64(Instruction const&) = 0;
    virtual void PSUBD_mm1_mm2m64(Instruction const&) = 0;
    virtual void PSUBSB_mm1_mm2m64(Instruction const&) = 0;
    virtual void PSUBSW_mm1_mm2m64(Instruction const&) = 0;
    virtual void PSUBUSB_mm1_mm2m64(Instruction const&) = 0;
    virtual void PSUBUSW_mm1_mm2m64(Instruction const&) = 0;
    virtual void PUNPCKHBW_mm1_mm2m64(Instruction const&) = 0;
    virtual void PUNPCKHWD_mm1_mm2m64(Instruction const&) = 0;
    virtual void PUNPCKHDQ_mm1_mm2m64(Instruction const&) = 0;
    virtual void PUNPCKLBW_mm1_mm2m32(Instruction const&) = 0;
    virtual void PUNPCKLWD_mm1_mm2m32(Instruction const&) = 0;
    virtual void PUNPCKLDQ_mm1_mm2m32(Instruction const&) = 0;
    virtual void PUSHA(Instruction const&) = 0;
    virtual void PUSHAD(Instruction const&) = 0;
    virtual void PUSHF(Instruction const&) = 0;
    virtual void PUSHFD(Instruction const&) = 0;
    virtual void PUSH_CS(Instruction const&) = 0;
    virtual void PUSH_DS(Instruction const&) = 0;
    virtual void PUSH_ES(Instruction const&) = 0;
    virtual void PUSH_FS(Instruction const&) = 0;
    virtual void PUSH_GS(Instruction const&) = 0;
    virtual void PUSH_RM16(Instruction const&) = 0;
    virtual void PUSH_RM32(Instruction const&) = 0;
    virtual void PUSH_SP_8086_80186(Instruction const&) = 0;
    virtual void PUSH_SS(Instruction const&) = 0;
    virtual void PUSH_imm16(Instruction const&) = 0;
    virtual void PUSH_imm32(Instruction const&) = 0;
    virtual void PUSH_imm8(Instruction const&) = 0;
    virtual void PUSH_reg16(Instruction const&) = 0;
    virtual void PUSH_reg32(Instruction const&) = 0;
    virtual void PXOR_mm1_mm2m64(Instruction const&) = 0;
    virtual void RCL_RM16_1(Instruction const&) = 0;
    virtual void RCL_RM16_CL(Instruction const&) = 0;
    virtual void RCL_RM16_imm8(Instruction const&) = 0;
    virtual void RCL_RM32_1(Instruction const&) = 0;
    virtual void RCL_RM32_CL(Instruction const&) = 0;
    virtual void RCL_RM32_imm8(Instruction const&) = 0;
    virtual void RCL_RM8_1(Instruction const&) = 0;
    virtual void RCL_RM8_CL(Instruction const&) = 0;
    virtual void RCL_RM8_imm8(Instruction const&) = 0;
    virtual void RCR_RM16_1(Instruction const&) = 0;
    virtual void RCR_RM16_CL(Instruction const&) = 0;
    virtual void RCR_RM16_imm8(Instruction const&) = 0;
    virtual void RCR_RM32_1(Instruction const&) = 0;
    virtual void RCR_RM32_CL(Instruction const&) = 0;
    virtual void RCR_RM32_imm8(Instruction const&) = 0;
    virtual void RCR_RM8_1(Instruction const&) = 0;
    virtual void RCR_RM8_CL(Instruction const&) = 0;
    virtual void RCR_RM8_imm8(Instruction const&) = 0;
    virtual void RDTSC(Instruction const&) = 0;
    virtual void RET(Instruction const&) = 0;
    virtual void RETF(Instruction const&) = 0;
    virtual void RETF_imm16(Instruction const&) = 0;
    virtual void RET_imm16(Instruction const&) = 0;
    virtual void ROL_RM16_1(Instruction const&) = 0;
    virtual void ROL_RM16_CL(Instruction const&) = 0;
    virtual void ROL_RM16_imm8(Instruction const&) = 0;
    virtual void ROL_RM32_1(Instruction const&) = 0;
    virtual void ROL_RM32_CL(Instruction const&) = 0;
    virtual void ROL_RM32_imm8(Instruction const&) = 0;
    virtual void ROL_RM8_1(Instruction const&) = 0;
    virtual void ROL_RM8_CL(Instruction const&) = 0;
    virtual void ROL_RM8_imm8(Instruction const&) = 0;
    virtual void ROR_RM16_1(Instruction const&) = 0;
    virtual void ROR_RM16_CL(Instruction const&) = 0;
    virtual void ROR_RM16_imm8(Instruction const&) = 0;
    virtual void ROR_RM32_1(Instruction const&) = 0;
    virtual void ROR_RM32_CL(Instruction const&) = 0;
    virtual void ROR_RM32_imm8(Instruction const&) = 0;
    virtual void ROR_RM8_1(Instruction const&) = 0;
    virtual void ROR_RM8_CL(Instruction const&) = 0;
    virtual void ROR_RM8_imm8(Instruction const&) = 0;
    virtual void SAHF(Instruction const&) = 0;
    virtual void SALC(Instruction const&) = 0;
    virtual void SAR_RM16_1(Instruction const&) = 0;
    virtual void SAR_RM16_CL(Instruction const&) = 0;
    virtual void SAR_RM16_imm8(Instruction const&) = 0;
    virtual void SAR_RM32_1(Instruction const&) = 0;
    virtual void SAR_RM32_CL(Instruction const&) = 0;
    virtual void SAR_RM32_imm8(Instruction const&) = 0;
    virtual void SAR_RM8_1(Instruction const&) = 0;
    virtual void SAR_RM8_CL(Instruction const&) = 0;
    virtual void SAR_RM8_imm8(Instruction const&) = 0;
    virtual void SBB_AL_imm8(Instruction const&) = 0;
    virtual void SBB_AX_imm16(Instruction const&) = 0;
    virtual void SBB_EAX_imm32(Instruction const&) = 0;
    virtual void SBB_RM16_imm16(Instruction const&) = 0;
    virtual void SBB_RM16_imm8(Instruction const&) = 0;
    virtual void SBB_RM16_reg16(Instruction const&) = 0;
    virtual void SBB_RM32_imm32(Instruction const&) = 0;
    virtual void SBB_RM32_imm8(Instruction const&) = 0;
    virtual void SBB_RM32_reg32(Instruction const&) = 0;
    virtual void SBB_RM8_imm8(Instruction const&) = 0;
    virtual void SBB_RM8_reg8(Instruction const&) = 0;
    virtual void SBB_reg16_RM16(Instruction const&) = 0;
    virtual void SBB_reg32_RM32(Instruction const&) = 0;
    virtual void SBB_reg8_RM8(Instruction const&) = 0;
    virtual void SCASB(Instruction const&) = 0;
    virtual void SCASD(Instruction const&) = 0;
    virtual void SCASW(Instruction const&) = 0;
    virtual void SETcc_RM8(Instruction const&) = 0;
    virtual void SGDT(Instruction const&) = 0;
    virtual void SHLD_RM16_reg16_CL(Instruction const&) = 0;
    virtual void SHLD_RM16_reg16_imm8(Instruction const&) = 0;
    virtual void SHLD_RM32_reg32_CL(Instruction const&) = 0;
    virtual void SHLD_RM32_reg32_imm8(Instruction const&) = 0;
    virtual void SHL_RM16_1(Instruction const&) = 0;
    virtual void SHL_RM16_CL(Instruction const&) = 0;
    virtual void SHL_RM16_imm8(Instruction const&) = 0;
    virtual void SHL_RM32_1(Instruction const&) = 0;
    virtual void SHL_RM32_CL(Instruction const&) = 0;
    virtual void SHL_RM32_imm8(Instruction const&) = 0;
    virtual void SHL_RM8_1(Instruction const&) = 0;
    virtual void SHL_RM8_CL(Instruction const&) = 0;
    virtual void SHL_RM8_imm8(Instruction const&) = 0;
    virtual void SHRD_RM16_reg16_CL(Instruction const&) = 0;
    virtual void SHRD_RM16_reg16_imm8(Instruction const&) = 0;
    virtual void SHRD_RM32_reg32_CL(Instruction const&) = 0;
    virtual void SHRD_RM32_reg32_imm8(Instruction const&) = 0;
    virtual void SHR_RM16_1(Instruction const&) = 0;
    virtual void SHR_RM16_CL(Instruction const&) = 0;
    virtual void SHR_RM16_imm8(Instruction const&) = 0;
    virtual void SHR_RM32_1(Instruction const&) = 0;
    virtual void SHR_RM32_CL(Instruction const&) = 0;
    virtual void SHR_RM32_imm8(Instruction const&) = 0;
    virtual void SHR_RM8_1(Instruction const&) = 0;
    virtual void SHR_RM8_CL(Instruction const&) = 0;
    virtual void SHR_RM8_imm8(Instruction const&) = 0;
    virtual void SIDT(Instruction const&) = 0;
    virtual void SLDT_RM16(Instruction const&) = 0;
    virtual void SMSW_RM16(Instruction const&) = 0;
    virtual void STC(Instruction const&) = 0;
    virtual void STD(Instruction const&) = 0;
    virtual void STI(Instruction const&) = 0;
    virtual void STOSB(Instruction const&) = 0;
    virtual void STOSD(Instruction const&) = 0;
    virtual void STOSW(Instruction const&) = 0;
    virtual void STR_RM16(Instruction const&) = 0;
    virtual void SUB_AL_imm8(Instruction const&) = 0;
    virtual void SUB_AX_imm16(Instruction const&) = 0;
    virtual void SUB_EAX_imm32(Instruction const&) = 0;
    virtual void SUB_RM16_imm16(Instruction const&) = 0;
    virtual void SUB_RM16_imm8(Instruction const&) = 0;
    virtual void SUB_RM16_reg16(Instruction const&) = 0;
    virtual void SUB_RM32_imm32(Instruction const&) = 0;
    virtual void SUB_RM32_imm8(Instruction const&) = 0;
    virtual void SUB_RM32_reg32(Instruction const&) = 0;
    virtual void SUB_RM8_imm8(Instruction const&) = 0;
    virtual void SUB_RM8_reg8(Instruction const&) = 0;
    virtual void SUB_reg16_RM16(Instruction const&) = 0;
    virtual void SUB_reg32_RM32(Instruction const&) = 0;
    virtual void SUB_reg8_RM8(Instruction const&) = 0;
    virtual void TEST_AL_imm8(Instruction const&) = 0;
    virtual void TEST_AX_imm16(Instruction const&) = 0;
    virtual void TEST_EAX_imm32(Instruction const&) = 0;
    virtual void TEST_RM16_imm16(Instruction const&) = 0;
    virtual void TEST_RM16_reg16(Instruction const&) = 0;
    virtual void TEST_RM32_imm32(Instruction const&) = 0;
    virtual void TEST_RM32_reg32(Instruction const&) = 0;
    virtual void TEST_RM8_imm8(Instruction const&) = 0;
    virtual void TEST_RM8_reg8(Instruction const&) = 0;
    virtual void UD0(Instruction const&) = 0;
    virtual void UD1(Instruction const&) = 0;
    virtual void UD2(Instruction const&) = 0;
    virtual void VERR_RM16(Instruction const&) = 0;
    virtual void VERW_RM16(Instruction const&) = 0;
    virtual void WAIT(Instruction const&) = 0;
    virtual void WBINVD(Instruction const&) = 0;
    virtual void XADD_RM16_reg16(Instruction const&) = 0;
    virtual void XADD_RM32_reg32(Instruction const&) = 0;
    virtual void XADD_RM8_reg8(Instruction const&) = 0;
    virtual void XCHG_AX_reg16(Instruction const&) = 0;
    virtual void XCHG_EAX_reg32(Instruction const&) = 0;
    virtual void XCHG_reg16_RM16(Instruction const&) = 0;
    virtual void XCHG_reg32_RM32(Instruction const&) = 0;
    virtual void XCHG_reg8_RM8(Instruction const&) = 0;
    virtual void XLAT(Instruction const&) = 0;
    virtual void XOR_AL_imm8(Instruction const&) = 0;
    virtual void XOR_AX_imm16(Instruction const&) = 0;
    virtual void XOR_EAX_imm32(Instruction const&) = 0;
    virtual void XOR_RM16_imm16(Instruction const&) = 0;
    virtual void XOR_RM16_imm8(Instruction const&) = 0;
    virtual void XOR_RM16_reg16(Instruction const&) = 0;
    virtual void XOR_RM32_imm32(Instruction const&) = 0;
    virtual void XOR_RM32_imm8(Instruction const&) = 0;
    virtual void XOR_RM32_reg32(Instruction const&) = 0;
    virtual void XOR_RM8_imm8(Instruction const&) = 0;
    virtual void XOR_RM8_reg8(Instruction const&) = 0;
    virtual void XOR_reg16_RM16(Instruction const&) = 0;
    virtual void XOR_reg32_RM32(Instruction const&) = 0;
    virtual void XOR_reg8_RM8(Instruction const&) = 0;
    virtual void MOVQ_mm1_mm2m64(Instruction const&) = 0;
    virtual void MOVQ_mm1m64_mm2(Instruction const&) = 0;
    virtual void MOVD_mm1_rm32(Instruction const&) = 0;
    virtual void MOVQ_mm1_rm64(Instruction const&) = 0; // long mode
    virtual void MOVD_rm32_mm2(Instruction const&) = 0;
    virtual void MOVQ_rm64_mm2(Instruction const&) = 0; // long mode
    virtual void EMMS(Instruction const&) = 0;
    virtual void wrap_0xC0(Instruction const&) = 0;
    virtual void wrap_0xC1_16(Instruction const&) = 0;
    virtual void wrap_0xC1_32(Instruction const&) = 0;
    virtual void wrap_0xD0(Instruction const&) = 0;
    virtual void wrap_0xD1_16(Instruction const&) = 0;
    virtual void wrap_0xD1_32(Instruction const&) = 0;
    virtual void wrap_0xD2(Instruction const&) = 0;
    virtual void wrap_0xD3_16(Instruction const&) = 0;
    virtual void wrap_0xD3_32(Instruction const&) = 0;

    virtual void PREFETCHTNTA(Instruction const&) = 0;
    virtual void PREFETCHT0(Instruction const&) = 0;
    virtual void PREFETCHT1(Instruction const&) = 0;
    virtual void PREFETCHT2(Instruction const&) = 0;
    virtual void LDMXCSR(Instruction const&) = 0;
    virtual void STMXCSR(Instruction const&) = 0;
    virtual void MOVUPS_xmm1_xmm2m128(Instruction const&) = 0;
    virtual void MOVSS_xmm1_xmm2m32(Instruction const&) = 0;
    virtual void MOVUPS_xmm1m128_xmm2(Instruction const&) = 0;
    virtual void MOVSS_xmm1m32_xmm2(Instruction const&) = 0;
    virtual void MOVLPS_xmm1_xmm2m64(Instruction const&) = 0;
    virtual void MOVLPS_m64_xmm2(Instruction const&) = 0;
    virtual void UNPCKLPS_xmm1_xmm2m128(Instruction const&) = 0;
    virtual void UNPCKHPS_xmm1_xmm2m128(Instruction const&) = 0;
    virtual void MOVHPS_xmm1_xmm2m64(Instruction const&) = 0;
    virtual void MOVHPS_m64_xmm2(Instruction const&) = 0;
    virtual void MOVAPS_xmm1_xmm2m128(Instruction const&) = 0;
    virtual void MOVAPS_xmm1m128_xmm2(Instruction const&) = 0;
    virtual void CVTTPS2PI_mm1_xmm2m64(Instruction const&) = 0;
    virtual void CVTTPS2PI_r32_xmm2m32(Instruction const&) = 0;
    virtual void CVTPI2PS_xmm1_mm2m64(Instruction const&) = 0;
    virtual void CVTSI2SS_xmm1_rm32(Instruction const&) = 0;
    virtual void MOVNTPS_xmm1m128_xmm2(Instruction const&) = 0;
    virtual void CVTPS2PI_xmm1_mm2m64(Instruction const&) = 0;
    virtual void CVTSS2SI_xmm1_rm32(Instruction const&) = 0;
    virtual void UCOMISS_xmm1_xmm2m32(Instruction const&) = 0;
    virtual void COMISS_xmm1_xmm2m32(Instruction const&) = 0;
    virtual void MOVMSKPS_reg_xmm(Instruction const&) = 0;
    virtual void SQRTPS_xmm1_xmm2m128(Instruction const&) = 0;
    virtual void SQRTSS_xmm1_xmm2m32(Instruction const&) = 0;
    virtual void RSQRTPS_xmm1_xmm2m128(Instruction const&) = 0;
    virtual void RSQRTSS_xmm1_xmm2m32(Instruction const&) = 0;
    virtual void RCPPS_xmm1_xmm2m128(Instruction const&) = 0;
    virtual void RCPSS_xmm1_xmm2m32(Instruction const&) = 0;
    virtual void ANDPS_xmm1_xmm2m128(Instruction const&) = 0;
    virtual void ANDNPS_xmm1_xmm2m128(Instruction const&) = 0;
    virtual void ORPS_xmm1_xmm2m128(Instruction const&) = 0;
    virtual void XORPS_xmm1_xmm2m128(Instruction const&) = 0;
    virtual void ADDPS_xmm1_xmm2m128(Instruction const&) = 0;
    virtual void ADDSS_xmm1_xmm2m32(Instruction const&) = 0;
    virtual void MULPS_xmm1_xmm2m128(Instruction const&) = 0;
    virtual void MULSS_xmm1_xmm2m32(Instruction const&) = 0;
    virtual void SUBPS_xmm1_xmm2m128(Instruction const&) = 0;
    virtual void SUBSS_xmm1_xmm2m32(Instruction const&) = 0;
    virtual void MINPS_xmm1_xmm2m128(Instruction const&) = 0;
    virtual void MINSS_xmm1_xmm2m32(Instruction const&) = 0;
    virtual void DIVPS_xmm1_xmm2m128(Instruction const&) = 0;
    virtual void DIVSS_xmm1_xmm2m32(Instruction const&) = 0;
    virtual void MAXPS_xmm1_xmm2m128(Instruction const&) = 0;
    virtual void MAXSS_xmm1_xmm2m32(Instruction const&) = 0;
    virtual void PSHUFW_mm1_mm2m64_imm8(Instruction const&) = 0;
    virtual void CMPPS_xmm1_xmm2m128_imm8(Instruction const&) = 0;
    virtual void CMPSS_xmm1_xmm2m32_imm8(Instruction const&) = 0;
    virtual void PINSRW_mm1_r32m16_imm8(Instruction const&) = 0;
    virtual void PINSRW_xmm1_r32m16_imm8(Instruction const&) = 0;
    virtual void PEXTRW_reg_mm1_imm8(Instruction const&) = 0;
    virtual void PEXTRW_reg_xmm1_imm8(Instruction const&) = 0;
    virtual void SHUFPS_xmm1_xmm2m128_imm8(Instruction const&) = 0;
    virtual void PMOVMSKB_reg_mm1(Instruction const&) = 0;
    virtual void PMOVMSKB_reg_xmm1(Instruction const&) = 0;
    virtual void PMINUB_mm1_mm2m64(Instruction const&) = 0;
    virtual void PMINUB_xmm1_xmm2m128(Instruction const&) = 0;
    virtual void PMAXUB_mm1_mm2m64(Instruction const&) = 0;
    virtual void PMAXUB_xmm1_xmm2m128(Instruction const&) = 0;
    virtual void PAVGB_mm1_mm2m64(Instruction const&) = 0;
    virtual void PAVGB_xmm1_xmm2m128(Instruction const&) = 0;
    virtual void PAVGW_mm1_mm2m64(Instruction const&) = 0;
    virtual void PAVGW_xmm1_xmm2m128(Instruction const&) = 0;
    virtual void PMULHUW_mm1_mm2m64(Instruction const&) = 0;
    virtual void PMULHUW_xmm1_xmm2m64(Instruction const&) = 0;
    virtual void MOVNTQ_m64_mm1(Instruction const&) = 0;
    virtual void PMINSB_mm1_mm2m64(Instruction const&) = 0;
    virtual void PMINSB_xmm1_xmm2m128(Instruction const&) = 0;
    virtual void PMAXSB_mm1_mm2m64(Instruction const&) = 0;
    virtual void PMAXSB_xmm1_xmm2m128(Instruction const&) = 0;
    virtual void PSADBB_mm1_mm2m64(Instruction const&) = 0;
    virtual void PSADBB_xmm1_xmm2m128(Instruction const&) = 0;
    virtual void MASKMOVQ_mm1_mm2m64(Instruction const&) = 0;

protected:
    virtual ~Interpreter() = default;
};

typedef void (Interpreter::*InstructionHandler)(Instruction const&);

}
