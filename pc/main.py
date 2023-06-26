import serial
import pyautogui

# change "COM8" with the port of your esp32
ser = serial.Serial("COM8", 115200, timeout=1)

while True:
    data = ser.readline().decode().strip()
    if data:
        if data == "A1":
            pyautogui.keyDown("space")
        elif data == "A0":
            pyautogui.keyUp("space")
        elif data == "B1":
            pyautogui.keyDown("down")
        elif data == "B0":
            pyautogui.keyUp("down")
        else:
            print(data)
