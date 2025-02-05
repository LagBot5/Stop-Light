# On a pi pico (Python)
from machine import PWM, Pin, ADC
from servo import Servo
import time


# Defines
STATE_OFF = 0
STATE_EW_Turning = 1
STATE_EW_Straight = 2
STATE_Yellow1 = 3
STATE_Yellow2 = 4
STATE_NS_Straight = 5
STATE_NS_Turning = 6
NS_Walking = 7
EW_Walking = 8
EMERGENCY1 = 9
EMERGENCY2 = 10
SERVO_PIN = 26
LDR = 28
Blink_Off = 13
Blink_On = 12


#Pins
GreenArrow1 = Pin(0, Pin.OUT)
GreenLight1 = Pin(1, Pin.OUT)
YellowLight1 = Pin(2, Pin.OUT)
RedLight1 = Pin(3, Pin.OUT)
GreenArrow2 = Pin(4, Pin.OUT)
GreenLight2 = Pin(5, Pin.OUT)
YellowLight2 = Pin(6, Pin.OUT)
RedLight2 = Pin(7, Pin.OUT)
RedWalking1 = Pin(8, Pin.OUT)
WhiteWalking1 = Pin(9, Pin.OUT)
WhiteWalking2 = Pin(10, Pin.OUT)
RedWalking2 = Pin(11, Pin.OUT)
Blink = Pin(12, Pin.OUT)
LDR = Pin(28, Pin.IN)
SwitchLED = Pin(13, Pin.IN, Pin.PULL_DOWN)
SwitchWalking = Pin(14, Pin.IN, Pin.PULL_DOWN)
GreenLight1.value(0)


#GPIO pins for 7-segment display segments (a-g)
segments = [
    machine.Pin(17, machine.Pin.OUT), #a
    machine.Pin(16, machine.Pin.OUT), #b
    machine.Pin(22, machine.Pin.OUT), #c
    machine.Pin(21, machine.Pin.OUT), #d
    machine.Pin(20, machine.Pin.OUT), #e
    machine.Pin(18, machine.Pin.OUT), #f
    machine.Pin(19, machine.Pin.OUT), #g
    machine.Pin(15, machine.Pin.OUT)  #dp
]


# pin states for each digit to display numbers 0-9
number_map = [
    [1, 1, 1, 1, 0, 1, 1],  # 9
    [1, 1, 1, 1, 1, 1, 1],  # 8
    [1, 1, 1, 0, 0, 0, 0],  # 7
    [1, 0, 1, 1, 1, 1, 1],  # 6
    [1, 0, 1, 1, 0, 1, 1],  # 5
    [0, 1, 1, 0, 0, 1, 1],  # 4
    [1, 1, 1, 1, 0, 0, 1],  # 3
    [1, 1, 0, 1, 1, 0, 1],  # 2
    [0, 1, 1, 0, 0, 0, 0],  # 1
]


#function to display a specific number on the 7-segment display
def display_number(number):
    segments_values = number_map[number]
    for i in range(len(segments)):
        segments[i-1].value(segments_values[i-1])


myServo = Servo(SERVO_PIN)


State = STATE_OFF
StateTime = 0


def readLight(LDRGP):
    LDR = ADC(Pin(13))
   
def setStateTimeToNow():
    global StateTime
    StateTime = utime.ticks_ms
   
def Emergency1():
    GreenArrow1.value(0),
    GreenLight1.value(0),
    YellowLight1.value(0),
    RedLight1.value(0),
    GreenArrow2.value(0),
    GreenLight2.value(0),
    YellowLight2.value(0),
    RedLight2.value(0),
    RedWalking1.value(1),
    WhiteWalking1.value(0),
    WhiteWalking2.value(0),
    RedWalking2.value(1)


def Emergency2():
    GreenArrow1.value(0),
    GreenLight1.value(0),
    YellowLight1.value(0),
    RedLight1.value(1),
    GreenArrow2.value(0),
    GreenLight2.value(0),
    YellowLight2.value(0),
    RedLight2.value(1),
    RedWalking1.value(1),
    WhiteWalking1.value(0),
    WhiteWalking2.value(0),
    RedWalking2.value(1)


now = time.ticks_ms()


def TurnONEmergency():
    if State == EMERGENCY1 :
        #Light Stuff
        Emergency1()
        # check for time to transition
       
        now = utime.ticks_ms()
       
        if utime.diff(now, StateTime) >= 500:
            State = EMERGENCY2
            setStateTimeToNow()
   
    elif State == Emergency2:
         #Light Stuff
         Emergency2()
         # check for time to transition
         now = utime.ticks_ms()
         if utime.diff(now, StateTime) >= 500:
              State = EMERGENCY1
              setStateTimeToNow()
             
def EWTurning():
    WhiteWalking1.value(0),
    WhiteWalking2.value(0),
    RedWalking1.value(1),
    RedWalking2.value(1),
    YellowLight1.value(0),
    YellowLight2.value(0),
    GreenLight2.value(0),
    RedLight1.value(1),
    RedLight2.value(0),
    GreenArrow2.value(1),


def EWStraight():
    RedWalking1.value(1),
    RedWalking2.value(0),
    YellowLight1.value(0),
    YellowLight2.value(0),
    GreenLight2.value(1),
    RedLight1.value(1),
    RedLight2.value(0),
    GreenArrow2.value(0)


def YellowNS():
    WhiteWalking1.value(0),
    WhiteWalking2.value(0),
    YellowLight1.value(1),
    YellowLight2.value(0),
    RedLight1.value(0),
    RedLight2.value(1),
    RedWalking1.value(1),
    RedWalking2.value(1),
    GreenArrow1.value(0),
    GreenArrow2.value(0),
    GreenLight1.value(0),
    GreenLight2.value(0)


def YellowEW():
    WhiteWalking1.value(0),
    WhiteWalking2.value(0),
    YellowLight1.value(0),
    YellowLight2.value(1),
    RedLight1.value(1),
    RedLight2.value(0),
    RedWalking1.value(1),
    RedWalking2.value(1),
    GreenArrow1.value(0),
    GreenArrow2.value(0),
    GreenLight1.value(0),
    GreenLight2.value(0)


def NSStraight():
    YellowLight1.value(0),
    YellowLight2.value(0),
    RedLight1.value(0),
    RedLight2.value(1),
    RedWalking1.value(0),
    RedWalking2.value(1),
    GreenArrow1.value(0),
    GreenArrow2.value(0),
    GreenLight1.value(1),
    GreenLight2.value(0)


def NSTurning():
    WhiteWalking1.value(0),
    WhiteWalking2.value(0),
    YellowLight1.value(0),
    YellowLight2.value(0),
    RedLight1.value(0),
    RedLight2.value(1),
    RedWalking1.value(1),
    RedWalking2.value(1),
    GreenArrow1.value(1),
    GreenArrow2.value(0),
    GreenLight1.value(0),
    GreenLight2.value(0)
   
def WalkingLED1():
    WhiteWalking1.value(0),
    WhiteWalking2.value(1)


def WalkingLED2():
    WhiteWalking1.value(1),
    WhiteWalking2.value(0)    
   
CrossWalkTime = 0
CrossWalkCounter = 0
   
# A whole operation to combine other function
def RunNormal():
    global State
    if State == STATE_OFF or State == EMERGENCY1 or State == EMERGENCY2:
        State = STATE_EW_Straight


    if State == STATE_EW_Straight:
        # do lights stuff
        EWStraight()
        # check for time to transition
        now = utime.ticks_ms()
        if utime.ticks_diff(now, StateTime) >= 10000:
            State = STATE_Yellow1
            setStateTimeToNow()
           
        if SwitchWalking.value() and STATE_EW_Straight == 0:
            CrossWalkCounter = 9
            WalkingLED1()
            display_number(CrossWalkCounter)
            CrossWalkCounter = now
           
       
        if CrossWalkCounter > 0:
            if utime.ticks_diff(now, CrossWalkTime) > 1000:
                CrossWalkCounter -= 1
                WalkingLED1()
                display_number(CrossWalkCounter)
                CrossWalkTime = now
               


    elif State == STATE_EW_Turning:
        # Light Stuff
        EWTurning()
        # check for time to transition
        now = utime.ticks_ms()
        if utime.ticks_diff(now, StateTime) >= 6000:
            State = STATE_EW_Straight
            setStateTimeToNow()


    elif State == STATE_Yellow1:
        # Light Stuff
        YellowEW()
        # check for time to transition
        now = utime.ticks_ms()
        if utime.ticks_diff(now, StateTime) >= 5000:
            State = STATE_NS_Turning
            setStateTimeToNow()


    elif State == STATE_NS_Straight:
        # Light Stuff
        NSStraight()
        # check for time to transition
        now = utime.ticks_ms()
        if utime.ticks_diff(now, StateTime) >= 7000:
            State = STATE_Yellow2
            setStateTimeToNow()
           
        if SwitchWalking.value() and STATE_NS_Straight == 0:
            CrossWalkCounter = 9
            WalkingLED2()
            display_number(CrossWalkCounter)
            CrossWalkCounter = now
           
       
        if CrossWalkCounter > 0:
            if utime.ticks_diff(now, CrossWalkTime) > 1000:
                CrossWalkCounter -= 1
                WalkingLED2()
                display_number(CrossWalkCounter)
                CrossWalkTime = now


    elif State == STATE_NS_Turning:
        # Light Stuff
        NSTurning()
        # check for time to transition
        now = utime.ticks_ms()
        if utime.ticks_diff(now, StateTime) >= 6000:
            State = STATE_NS_Straight
            setStateTimeToNow()


    elif State == STATE_Yellow2:
        # Light Stuff
        YellowNS()
        # check for time to transition
        now = utime.ticks_ms()
        if utime.ticks_diff(now, StateTime) >= 5000:
            State = STATE_EW_Turning
            setStateTimeToNow()
           
def Servo0():
    myServo.move(0)
 #   Blink.value(0)
   
def Servo90():
    myServo.move(90)
    if State == Blink_On:
        #Light Stuff
        Blink.value(1)
        #check for time to transition
        now = utime.ticks_ms()
        if utime.diff(now, StateTime) >= 500:
            State = Blink_Off
            setStateTimeToNow()
           
    elif State == Blink_Off:
         #Light Stuff
        Blink.value(0)
        #check for time to transition
        now = utime.ticks_ms()
        if utime.diff(now, StateTime) >= 500:
            State = Blink_On
            setStateTimeToNow()
   
while True:
    Luminosity = ADC(2)
    print(Luminosity)
   
    if SwitchLED.value():
        RunNormal()
       
    elif SwitchWalking.value():
        TurnONEmergency()
       
    if Luminosity.read_u16() < 15:
        Servo90()
       
    elif Luminosity.read_u16() >= 0:
         Servo0()
