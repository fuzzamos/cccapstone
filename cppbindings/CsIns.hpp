#pragma once

#include <capstone.h>
#include "CsCapstoneHelper.h"

//x86_insn_group, x86_reg, x86_op_type, x86_insn
template<typename InsGroup_t, typename Reg_t, typename Op_t, typename Ins_t>
class CCsIns
{
	CS_HANDLE m_csh;
	cs_insn m_ins;

	void operator=(CCsIns const&) = delete;
public: 
	CCsIns(
		__in CS_HANDLE& csh,
		__in cs_insn& ins
		) : m_csh(csh),
			m_ins(ins)
	{
	}

	cs_insn*
	operator->()
	{
		return &m_ins;
	}

	__forceinline
	bool 
	IsInInsGroup(
		__in InsGroup_t groupId
		)
	{
		return cs_insn_group(*m_csh.get(), &m_ins, groupId);
	}

	__forceinline
	bool 
	RegRead(
		__in Reg_t regId
		)
	{
		return cs_reg_read(*m_csh.get(), &m_ins, regId);
	}

	__forceinline
	bool 
	RegWrite(
		__in Reg_t regId
		)
	{
		return cs_reg_write(*m_csh.get(), &m_ins, regId);
	}

	__forceinline
	int
	OpcodeCount(
		__in Op_t opType
		)
	{
		return cs_op_count(*m_csh.get(), &m_ins, opType);
	}

	__forceinline
	int
	OpcodeIndex(
		__in Op_t opType,
		__in unsigned int opcodePosition = 0
		)
	{
		return cs_op_index(*m_csh.get(), &m_ins, opType, opcodePosition);
	}

	__forceinline
	const char* 
	RegName(
		__in Reg_t reg
		)
	{
		return cs_reg_name(*m_csh.get(), reg);
	}

	__forceinline
	const char* 
	InsName(
		__in Ins_t ins
		)
	{
		return cs_insn_name(*m_csh.get(), ins);
	}

	static
	__forceinline
	const char* 
	RegName(
		__in csh& cs,
		__in Reg_t reg
		)
	{
		return cs_reg_name(cs, reg);
	}

	static
	__forceinline
	const char* 
	InsName(
		__in csh& cs,
		__in Ins_t ins
		)
	{
		return cs_insn_name(cs, ins);
	}
};
