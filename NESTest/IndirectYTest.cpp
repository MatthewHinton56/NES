
#pragma once

#include "pch.h"

#include <chrono>


#define COMMA ,

using namespace mos6502;

namespace {

	class IndirectYTest : public ::testing::Test {
	protected:

		IndirectYTest() :
			PC(),
			mem(),
			registerMap()
		{}


		void SetUp() override
		{
		}

		Word PC;
		Memory<PAGE_SIZE, NUM_PAGES> mem;
		RegisterMap registerMap;
	};

	TEST_F(IndirectYTest, indYOra)
	{
		registerMap[SR] = 0x00;
		registerMap[AC] = 0x55;
		registerMap[Y] = 0x5;
		IndirectY instr(0x11);
		PC++;
		mem.writeByte(0x1, 0x11);
		mem.writeByte(0x11, 0x34);
		mem.writeByte(0x12, 0x12);
		mem.writeByte(0x1239, 0xAA);
		ASSERT_EQ(instr.getStepCount(), 1);
		ASSERT_EQ(instr.getOpcode(), 0x11);
		ASSERT_EQ(instr.getInstruction(), InstructionOpcodeIndirectY::iOra);
		ASSERT_EQ(instr.getType(), InstructionTypeIndirectY::read);
		ASSERT_EQ(instr.getGroup(), InstructionGroups::ora);
		ASSERT_EQ(PC, 1);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 0);
		ASSERT_EQ(instr.getStepCount(), 2);
		ASSERT_EQ(PC, 2);
		ASSERT_EQ(instr.getPointer(), 0x11);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 0);
		ASSERT_EQ(instr.getStepCount(), 3);
		ASSERT_EQ(instr.getLowAddressByte(), 0x34);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 0);
		ASSERT_EQ(instr.getStepCount(), 4);
		ASSERT_EQ(instr.getLowAddressByte(), 0x39);
		ASSERT_EQ(instr.getHighAddressByte(), 0x12);
		ASSERT_EQ(instr.getAddress(), 0x1239);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 2);
		ASSERT_EQ(instr.getStepCount(), 5);
		ASSERT_EQ(instr.getAddress(), 0x1239);
		ASSERT_EQ(instr.getData(), 0xAA);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 1);
		ASSERT_EQ(instr.getStepCount(), 6);
		ASSERT_EQ(registerMap[AC], 0xFF);
		ASSERT_EQ(registerMap[SR], 0x80);
	}

	TEST_F(IndirectYTest, indYAnd)
	{
		registerMap[SR] = 0x00;
		registerMap[AC] = 0x55;
		registerMap[Y] = 0x5;
		IndirectY instr(0x31);
		PC++;
		mem.writeByte(0x1, 0x11);
		mem.writeByte(0x11, 0x34);
		mem.writeByte(0x12, 0x12);
		mem.writeByte(0x1239, 0xAA);
		ASSERT_EQ(instr.getStepCount(), 1);
		ASSERT_EQ(instr.getOpcode(), 0x31);
		ASSERT_EQ(instr.getInstruction(), InstructionOpcodeIndirectY::iAnd);
		ASSERT_EQ(instr.getType(), InstructionTypeIndirectY::read);
		ASSERT_EQ(instr.getGroup(), InstructionGroups::nnand);
		ASSERT_EQ(PC, 1);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 0);
		ASSERT_EQ(instr.getStepCount(), 2);
		ASSERT_EQ(PC, 2);
		ASSERT_EQ(instr.getPointer(), 0x11);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 0);
		ASSERT_EQ(instr.getStepCount(), 3);
		ASSERT_EQ(instr.getLowAddressByte(), 0x34);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 0);
		ASSERT_EQ(instr.getStepCount(), 4);
		ASSERT_EQ(instr.getLowAddressByte(), 0x39);
		ASSERT_EQ(instr.getHighAddressByte(), 0x12);
		ASSERT_EQ(instr.getAddress(), 0x1239);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 2);
		ASSERT_EQ(instr.getStepCount(), 5);
		ASSERT_EQ(instr.getAddress(), 0x1239);
		ASSERT_EQ(instr.getData(), 0xAA);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 1);
		ASSERT_EQ(instr.getStepCount(), 6);
		ASSERT_EQ(registerMap[AC], 0x00);
		ASSERT_EQ(registerMap[SR], 0x02);
	}

	TEST_F(IndirectYTest, indYEor)
	{
		registerMap[SR] = 0x00;
		registerMap[AC] = 0x55;
		registerMap[Y] = 0x5;
		IndirectY instr(0x51);
		PC++;
		mem.writeByte(0x1, 0x11);
		mem.writeByte(0x11, 0x34);
		mem.writeByte(0x12, 0x12);
		mem.writeByte(0x3, 0x39);
		mem.writeByte(0x1239, 0x55);
		ASSERT_EQ(instr.getStepCount(), 1);
		ASSERT_EQ(instr.getOpcode(), 0x51);
		ASSERT_EQ(instr.getInstruction(), InstructionOpcodeIndirectY::iEor);
		ASSERT_EQ(instr.getType(), InstructionTypeIndirectY::read);
		ASSERT_EQ(instr.getGroup(), InstructionGroups::eor);
		ASSERT_EQ(PC, 1);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 0);
		ASSERT_EQ(instr.getStepCount(), 2);
		ASSERT_EQ(PC, 2);
		ASSERT_EQ(instr.getPointer(), 0x11);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 0);
		ASSERT_EQ(instr.getStepCount(), 3);
		ASSERT_EQ(instr.getLowAddressByte(), 0x34);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 0);
		ASSERT_EQ(instr.getStepCount(), 4);
		ASSERT_EQ(instr.getLowAddressByte(), 0x39);
		ASSERT_EQ(instr.getHighAddressByte(), 0x12);
		ASSERT_EQ(instr.getAddress(), 0x1239);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 2);
		ASSERT_EQ(instr.getStepCount(), 5);
		ASSERT_EQ(instr.getAddress(), 0x1239);
		ASSERT_EQ(instr.getData(), 0x55);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 1);
		ASSERT_EQ(instr.getStepCount(), 6);
		ASSERT_EQ(registerMap[AC], 0x00);
		ASSERT_EQ(registerMap[SR], 0x02);
	}

	TEST_F(IndirectYTest, indYAdc)
	{
		registerMap[SR] = 0x01;
		registerMap[AC] = 0x01;
		registerMap[Y] = 0x5;
		IndirectY instr(0x71);
		PC++;
		mem.writeByte(0x1, 0x11);
		mem.writeByte(0x11, 0x34);
		mem.writeByte(0x12, 0x12);
		mem.writeByte(0x1239, 0x1);
		ASSERT_EQ(instr.getStepCount(), 1);
		ASSERT_EQ(instr.getOpcode(), 0x71);
		ASSERT_EQ(instr.getInstruction(), InstructionOpcodeIndirectY::iAdc);
		ASSERT_EQ(instr.getType(), InstructionTypeIndirectY::read);
		ASSERT_EQ(instr.getGroup(), InstructionGroups::adc);
		ASSERT_EQ(PC, 1);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 0);
		ASSERT_EQ(instr.getStepCount(), 2);
		ASSERT_EQ(PC, 2);
		ASSERT_EQ(instr.getPointer(), 0x11);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 0);
		ASSERT_EQ(instr.getStepCount(), 3);
		ASSERT_EQ(instr.getLowAddressByte(), 0x34);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 0);
		ASSERT_EQ(instr.getStepCount(), 4);
		ASSERT_EQ(instr.getLowAddressByte(), 0x39);
		ASSERT_EQ(instr.getHighAddressByte(), 0x12);
		ASSERT_EQ(instr.getAddress(), 0x1239);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 2);
		ASSERT_EQ(instr.getStepCount(), 5);
		ASSERT_EQ(instr.getAddress(), 0x1239);
		ASSERT_EQ(instr.getData(), 0x1);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 1);
		ASSERT_EQ(instr.getStepCount(), 6);
		ASSERT_EQ(registerMap[AC], 0x03);
		ASSERT_EQ(registerMap[SR], 0x00);
	}

	TEST_F(IndirectYTest, indYSta)
	{
		registerMap[AC] = 0xAC;
		registerMap[Y] = 0x5;
		IndirectY instr(0x91);
		PC++;
		mem.writeByte(0x1, 0x11);
		mem.writeByte(0x11, 0x34);
		mem.writeByte(0x12, 0x12);
		mem.writeByte(0x1239, 0xBF);
		ASSERT_EQ(instr.getStepCount(), 1);
		ASSERT_EQ(instr.getOpcode(), 0x91);
		ASSERT_EQ(instr.getInstruction(), InstructionOpcodeIndirectY::iSta);
		ASSERT_EQ(instr.getType(), InstructionTypeIndirectY::write);
		ASSERT_EQ(instr.getGroup(), InstructionGroups::st);
		ASSERT_EQ(PC, 1);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 0);
		ASSERT_EQ(instr.getStepCount(), 2);
		ASSERT_EQ(PC, 2);
		ASSERT_EQ(instr.getPointer(), 0x11);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 0);
		ASSERT_EQ(instr.getStepCount(), 3);
		ASSERT_EQ(instr.getLowAddressByte(), 0x34);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 0);
		ASSERT_EQ(instr.getStepCount(), 4);
		ASSERT_EQ(instr.getLowAddressByte(), 0x39);
		ASSERT_EQ(instr.getHighAddressByte(), 0x12);
		ASSERT_EQ(instr.getAddress(), 0x1239);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 0);
		ASSERT_EQ(instr.getStepCount(), 5);
		ASSERT_EQ(instr.getAddress(), 0x1239);
		ASSERT_EQ(instr.getData(), 0xBF);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 1);
		ASSERT_EQ(instr.getStepCount(), 6);
		ASSERT_EQ(mem.readByte(0x1239), 0xAC);
	}

	TEST_F(IndirectYTest, indYLda)
	{
		registerMap[SR] = 0xFF;
		registerMap[AC] = 0xAC;
		registerMap[Y] = 0x5;
		IndirectY instr(0xB1);
		PC++;
		mem.writeByte(0x1, 0x11);
		mem.writeByte(0x11, 0x34);
		mem.writeByte(0x12, 0x12);
		mem.writeByte(0x1239, 0x2F);
		ASSERT_EQ(instr.getStepCount(), 1);
		ASSERT_EQ(instr.getOpcode(), 0xB1);
		ASSERT_EQ(instr.getInstruction(), InstructionOpcodeIndirectY::iLda);
		ASSERT_EQ(instr.getType(), InstructionTypeIndirectY::read);
		ASSERT_EQ(instr.getGroup(), InstructionGroups::ld);
		ASSERT_EQ(PC, 1);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 0);
		ASSERT_EQ(instr.getStepCount(), 2);
		ASSERT_EQ(PC, 2);
		ASSERT_EQ(instr.getPointer(), 0x11);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 0);
		ASSERT_EQ(instr.getStepCount(), 3);
		ASSERT_EQ(instr.getLowAddressByte(), 0x34);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 0);
		ASSERT_EQ(instr.getStepCount(), 4);
		ASSERT_EQ(instr.getLowAddressByte(), 0x39);
		ASSERT_EQ(instr.getHighAddressByte(), 0x12);
		ASSERT_EQ(instr.getAddress(), 0x1239);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 2);
		ASSERT_EQ(instr.getStepCount(), 5);
		ASSERT_EQ(instr.getAddress(), 0x1239);
		ASSERT_EQ(instr.getData(), 0x2F);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 1);
		ASSERT_EQ(instr.getStepCount(), 6);
		ASSERT_EQ(registerMap[AC], 0x2F);
		ASSERT_EQ(registerMap[SR], 0x7D);
	}

	TEST_F(IndirectYTest, indYCmp)
	{
		registerMap[SR] = 0x00;
		registerMap[AC] = 0;
		registerMap[Y] = 0x5;
		IndirectY instr(0xD1);
		PC++;
		mem.writeByte(0x1, 0x11);
		mem.writeByte(0x11, 0x34);
		mem.writeByte(0x12, 0x12);
		mem.writeByte(0x1239, 0x0);
		ASSERT_EQ(instr.getStepCount(), 1);
		ASSERT_EQ(instr.getOpcode(), 0xD1);
		ASSERT_EQ(instr.getInstruction(), InstructionOpcodeIndirectY::iCmp);
		ASSERT_EQ(instr.getType(), InstructionTypeIndirectY::read);
		ASSERT_EQ(instr.getGroup(), InstructionGroups::cmp);
		ASSERT_EQ(PC, 1);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 0);
		ASSERT_EQ(instr.getStepCount(), 2);
		ASSERT_EQ(PC, 2);
		ASSERT_EQ(instr.getPointer(), 0x11);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 0);
		ASSERT_EQ(instr.getStepCount(), 3);
		ASSERT_EQ(instr.getLowAddressByte(), 0x34);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 0);
		ASSERT_EQ(instr.getStepCount(), 4);
		ASSERT_EQ(instr.getLowAddressByte(), 0x39);
		ASSERT_EQ(instr.getHighAddressByte(), 0x12);
		ASSERT_EQ(instr.getAddress(), 0x1239);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 2);
		ASSERT_EQ(instr.getStepCount(), 5);
		ASSERT_EQ(instr.getAddress(), 0x1239);
		ASSERT_EQ(instr.getData(), 0x0);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 1);
		ASSERT_EQ(instr.getStepCount(), 6);
		ASSERT_EQ(registerMap[AC], 0x0);
		ASSERT_EQ(registerMap[SR], 0x03);
	}

	TEST_F(IndirectYTest, indYSbc)
	{
		registerMap[Y] = 0xFF;
		registerMap[SR] = 0x01;
		registerMap[AC] = 0x01;
		IndirectY instr(0xF1);
		PC++;
		mem.writeByte(0x1, 0x11);
		mem.writeByte(0x11, 0x01);
		mem.writeByte(0x12, 0x12);
		mem.writeByte(0x1200, 0xDD);
		mem.writeByte(0x1300, 0x1);
		ASSERT_EQ(instr.getStepCount(), 1);
		ASSERT_EQ(instr.getOpcode(), 0xF1);
		ASSERT_EQ(instr.getInstruction(), InstructionOpcodeIndirectY::iSbc);
		ASSERT_EQ(instr.getType(), InstructionTypeIndirectY::read);
		ASSERT_EQ(instr.getGroup(), InstructionGroups::sbc);
		ASSERT_EQ(PC, 1);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 0);
		ASSERT_EQ(instr.getStepCount(), 2);
		ASSERT_EQ(PC, 2);
		ASSERT_EQ(instr.getPointer(), 0x11);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 0);
		ASSERT_EQ(instr.getStepCount(), 3);
		ASSERT_EQ(instr.getLowAddressByte(), 0x1);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 0);
		ASSERT_EQ(instr.getStepCount(), 4);
		ASSERT_EQ(instr.getLowAddressByte(), 0x0);
		ASSERT_EQ(instr.getHighAddressByte(), 0x12);
		ASSERT_EQ(instr.getAddress(), 0x1200);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 0);
		ASSERT_EQ(instr.getStepCount(), 5);
		ASSERT_EQ(instr.getAddress(), 0x1300);
		ASSERT_EQ(instr.getData(), 0xDD);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 2);
		ASSERT_EQ(instr.getStepCount(), 6);
		ASSERT_EQ(instr.getAddress(), 0x1300);
		ASSERT_EQ(instr.getData(), 0x1);

		ASSERT_EQ(instr.step(PC, registerMap, mem), 1);
		ASSERT_EQ(instr.getStepCount(), 7);
		ASSERT_EQ(registerMap[AC], 0x00);
		ASSERT_EQ(registerMap[SR], 0x03);
	}
}
