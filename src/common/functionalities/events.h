//
// Created by Colliot on 2016/9/6.
//

#ifndef PROJECT_EVENTS_H
#define PROJECT_EVENTS_H

typedef enum {
  NO_BUTTON = 0,
  LEFT_BUTTON,
  MIDDLE_BUTTON,
  RIGHT_BUTTON
} ACL_Mouse_Button;

typedef enum {
  BUTTON_DOWN,
  BUTTON_DOUBLECLICK,
  BUTTON_UP,
  ROLL_UP,
  ROLL_DOWN,
  MOUSEMOVE
} ACL_Mouse_Event;

typedef enum {
  KEY_DOWN,
  KEY_UP
} ACL_Keyboard_Event;


typedef void (*KeyboardEventCallback)(int key, int event);
typedef void (*CharEventCallback)(char c);
typedef void (*MouseEventCallback)(int x, int y, int button, int event);
typedef void (*TimerEventCallback)(int timerID);


void registerKeyboardEvent(KeyboardEventCallback callback);
void registerCharEvent(CharEventCallback callback);
void registerMouseEvent(MouseEventCallback callback);
void registerTimerEvent(TimerEventCallback callback);


void startTimer(int timerID, int timeinterval);
void cancelTimer(int timerID);



#endif //PROJECT_EVENTS_H
