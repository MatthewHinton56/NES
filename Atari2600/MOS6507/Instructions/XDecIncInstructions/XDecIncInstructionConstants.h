#pragma once
#include "../Binary.h"
#include "../InstructionConstants.h"
#include <array>

namespace mos6507
{
	enum class XDecIncInstructions
	{
		iStx = 024,
		iLdx,
		iDec,
		iInc,
		iTxa,
		iTxs,
		iTax,
		iTsx,
		iDex,
		iNop
	};

	static const size_t IMPLIED_INSTRUCTION_COUNT = 6;

	static const std::array< XDecIncInstructions, IMPLIED_INSTRUCTION_COUNT> IMPLIED_INSTRUCTIONS
	{
		XDecIncInstructions::iTxa,
		XDecIncInstructions::iTxs,
		XDecIncInstructions::iTax,
		XDecIncInstructions::iTsx,
		XDecIncInstructions::iDex,
		XDecIncInstructions::iNop
	};

	static std::map<InstructionAddressingMode, uint8_t> incDecCycleTimes
	{
		{InstructionAddressingMode::zeroPage, 5},
		{InstructionAddressingMode::xZeroPage, 6},
		{InstructionAddressingMode::absolute, 6},
		{InstructionAddressingMode::absoluteX, 7}

	};

	static std::map<InstructionAddressingMode, uint8_t> stxCycleTimes
	{
		{InstructionAddressingMode::zeroPage, 3},
		{InstructionAddressingMode::xZeroPage, 4},
		{InstructionAddressingMode::absolute, 4}
	};

	static std::map<InstructionAddressingMode, uint8_t> ldxCycleTimes
	{
		{InstructionAddressingMode::immediate, 3},
		{InstructionAddressingMode::xZeroPage, 3},
		{InstructionAddressingMode::xZeroPage, 4},
		{InstructionAddressingMode::absolute, 4},
		{InstructionAddressingMode::absoluteX, 4}
	};

}