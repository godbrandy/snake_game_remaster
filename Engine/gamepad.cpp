#include <Windows.h>
#include "gamepad.h"


void Gamepad::InitGamepad()
{
	for (DWORD i{ 0 }; i < XUSER_MAX_COUNT; i++)
	{
		XINPUT_STATE input_state{};

		if (XInputGetState(i, &input_state) == ERROR_SUCCESS) // 0 is success in this case
		{
			pad_up = (input_state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP);
			pad_down = (input_state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN);
			pad_left = (input_state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT);
			pad_right = (input_state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT);
			pad_start = (input_state.Gamepad.wButtons & XINPUT_GAMEPAD_START);
			pad_back = (input_state.Gamepad.wButtons & XINPUT_GAMEPAD_BACK);
			pad_left_shoulder = (input_state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER);
			pad_right_shoulder = (input_state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER);
			pad_A = (input_state.Gamepad.wButtons & XINPUT_GAMEPAD_A);
			pad_B = (input_state.Gamepad.wButtons & XINPUT_GAMEPAD_B);
			pad_X = (input_state.Gamepad.wButtons & XINPUT_GAMEPAD_X);
			pad_Y = (input_state.Gamepad.wButtons & XINPUT_GAMEPAD_Y);

			stick_lx = input_state.Gamepad.sThumbLX;
			stick_ly = input_state.Gamepad.sThumbLY;
			stick_rx = input_state.Gamepad.sThumbRX;
			stick_ry = input_state.Gamepad.sThumbRY;
		}
	}
}
