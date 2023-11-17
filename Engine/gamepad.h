#pragma once
#include <Xinput.h>
#include <cstdint>
#pragma comment(lib,"Xinput.lib")

class Gamepad
{
public:
	void InitGamepad();
	bool GetPadUp() const { return pad_up; }
	bool GetPadDown() const { return pad_down; }
	bool GetPadLeft() const { return pad_left; }
	bool GetPadRight() const { return pad_right; }
	bool GetPadStart() const { return pad_start; }
	bool GetPadBack() const { return pad_back; }
	bool GetPadLeftShoulder() const { return pad_left_shoulder; }
	bool GetPadRightShoulder() const { return pad_right_shoulder; }
	bool GetPadA() const { return pad_A; }
	bool GetPadB() const { return pad_B; }
	bool GetPadX() const { return pad_X; }
	bool GetPadY() const { return pad_Y; }
	int16_t GetStickLX() const { return stick_lx; }
	int16_t GetStickLY() const { return stick_ly; }
	int16_t GetStickRX() const { return stick_rx; }
	int16_t GetStickRY() const { return stick_ry; }
private:
	bool pad_up;
	bool pad_down;
	bool pad_left;
	bool pad_right;
	bool pad_start;
	bool pad_back;
	bool pad_left_shoulder;
	bool pad_right_shoulder;
	bool pad_A;
	bool pad_B;
	bool pad_X;
	bool pad_Y;
	int16_t stick_lx;
	int16_t stick_ly;
	int16_t stick_rx;
	int16_t stick_ry;
};

