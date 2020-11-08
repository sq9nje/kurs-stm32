/*
 * button.h
 *
 *  Created on: Aug 3, 2020
 *      Author: Mateusz Salamon
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

typedef enum
{
	IDLE = 0,
	DEBOUNCE, // 1
	PRESSED,  // 2
	REPEAT,   // 3
	RELEASED  // 4
} BUTTON_STATE;

typedef struct button_struct
{
	BUTTON_STATE 	State;
	GPIO_TypeDef* 	GpioPort;
	uint16_t 		GpioPin;
	uint32_t		LastTick;
	uint32_t		Timer;
	uint32_t		TimerIdle;
	uint32_t		TimerDebounce;
	uint32_t		TimerPressed;
	uint32_t		TimerRepeat;
	void(*ButtonPress)(void);
	void(*ButtonLongPress)(void);
	void(*ButtonRepeatPress)(void);
	void(*ButtonRelease)(void);
} TButton;

void ButtonInitKey(TButton* Key, GPIO_TypeDef* GpioPort, uint16_t GpioPin, uint32_t TimerIdle,
					uint32_t TimerDebounce, uint32_t TimerPressed, uint32_t TimerRepeat);

void ButtonRegisterPressCallback(TButton* Key, void* Callback);
void ButtonRegisterLongPressCallback(TButton* Key, void* Callback);
void ButtonRegisterRepeatPressCallback(TButton* Key, void* Callback);
void ButtonRegisterReleaseCallback(TButton* Key, void* Callback);


void ButtonTask(TButton* Key);

#endif /* INC_BUTTON_H_ */
