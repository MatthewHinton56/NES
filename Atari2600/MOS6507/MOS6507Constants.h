#pragma once
#pragma once
#include <cstdint>
#include <vector>
#include <array>
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <map>

#define getCarryFlag(x) x & 0x1
#define getZeroFlag(x) ((x & 0x2) >> 1)
#define getInterruptFlag(x) ((x & 0x4) >> 2)
#define getDecimalFlag(x) ((x & 0x8) >> 3)
#define getBreakFlag(x) ((x & 0x10) >> 4)
#define getOverflowFlag(x) ((x & 0x40) >> 6)
#define getNegativeFlag(x) ((x & 0x80) >> 7)

#define setCarryFlag(x) x | 0x1
#define setZeroFlag(x) x | 0x2
#define setInterruptFlag(x) x | 0x4
#define setDecimalFlag(x) x | 0x8
#define setBreakFlag(x) x | 0x10
#define setOverflowFlag(x) x | 0x40
#define setNegativeFlag(x) x | 0x80

#define clearCarryFlag(x) x & ~0x1
#define clearZeroFlag(x) x & ~0x2
#define clearInterruptFlag(x) x & ~0x4
#define clearDecimalFlag(x) x & ~0x8
#define clearBreakFlag(x) x & ~0x10
#define clearOverflowFlag(x) x & ~0x40
#define clearNegativeFlag(x) x & ~0x80


namespace mos6507
{
	typedef uint16_t Word;
	typedef uint8_t Byte;

	typedef std::map<std::string, Byte> RegisterMap;

	static const unsigned int NUM_PAGES = 32;
	static const unsigned int PAGE_SIZE = 256;
	
	static const unsigned int aMask = 0xE0;
	static const unsigned int bMask = 0x1C;
	static const unsigned int cMask = 0x02;
}