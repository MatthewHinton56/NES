#pragma once

namespace mos6507
{
	enum class InstructionAddressingMode
	{
		xIndirect,
		zeroPage,
		immediate,
		absolute,
		yIndirect,
		xZeroPage,
		absoluteY,
		absoluteX,
		implied,
		yZeroPage
	};

	static std::map<InstructionAddressingMode, uint8_t> InstructionSizes
	{
		{InstructionAddressingMode::xIndirect, 2},
		{InstructionAddressingMode::zeroPage, 2},
		{InstructionAddressingMode::immediate, 2},
		{InstructionAddressingMode::absolute, 3},
		{InstructionAddressingMode::yIndirect, 2},
		{InstructionAddressingMode::xZeroPage, 2},
		{InstructionAddressingMode::absoluteY, 3},
		{InstructionAddressingMode::absoluteX, 3}
	};
}