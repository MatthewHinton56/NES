#pragma once

#include "Absolute.h"
using namespace mos6502;

static Byte UNUSED = 0;

Absolute::Absolute
(
	Byte _opcode
)	:
	stepCount(1),
	opcode(_opcode),
	instruction(static_cast<InstructionOpcodeAbsolute>(opcode)),
	type(InstructionToTypeAbsolute[instruction]),
	group(InstructionToGroupAbsolute[instruction]),
	lowAddressByte(0),
	highAddressByte(0),
	address(0),
	data(0)
{
	switch (instruction)
	{
		default:
			reg = AC;
			break;

		case InstructionOpcodeAbsolute::iStx:
		case InstructionOpcodeAbsolute::iLdx:
			reg = X;
			break;

		case InstructionOpcodeAbsolute::iSty:
		case InstructionOpcodeAbsolute::iLdy:
			reg = Y;
			break;
	}
}


int32_t Absolute::step
(
	Word& PC,
	RegisterMap& registerMap,
	Memory<PAGE_SIZE, NUM_PAGES>& mem
)
{
	stepCount++;
	switch (stepCount)
	{
		case 2:
			lowAddressByte = mem.readByte(PC);
			PC++;
			return 0;

		case 3:
			highAddressByte = mem.readByte(PC);
			PC++;
			address = (highAddressByte << 8) | lowAddressByte;
			if (type == InstructionTypeAbsolute::jmp)
			{
				PC = address;
				return 1;
			}

			return 0;

		case 4:
			switch (type)
			{
				case InstructionTypeAbsolute::rmw:
				case InstructionTypeAbsolute::read:
					data = mem.readByte(address);
					return (type == InstructionTypeAbsolute::read) ? 2 : 0;

				case InstructionTypeAbsolute::write:
					mem.writeByte(address, registerMap[reg]);
					return 1;
			}

		case 5:
			if (type == InstructionTypeAbsolute::rmw) mem.writeByte(address, data);
			groupStep
			(
				group,
				PC,
				mem,
				registerMap[SR],
				data,
				registerMap[reg]
			);

			return (type == InstructionTypeAbsolute::rmw) ? 0 : 1;

		case 6:
			mem.writeByte(address, data);
			return 1;
	}

	return -1;
}



