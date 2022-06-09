# Geronimo v2

## Introduction

Geronimo v2 is a low cost muscle switch, with a usb interface, to command a computer with any scrolling interruption software, like the famous [ACAT used by Stephen HAWKING](https://01.org/acat/switches)

The sensor is a simple piezo tranducer.

It is interfaced to an arduino Clone with ATMEGA32U4 controller. 

## Details

This controller has integrated HID functions: it can trigger a keyboard or mouse event.

The raw piezo signal is analyzed with peakDetector Library.

When the signal overcomes a limit tunable with the potentiometer, it triggers a keyboard event and powers the LED on (F12 Press for example).

### Bill of material

| Component | Cost (in €uro) |
| CJMCU BEETLE Keyboard BadUSB ATMEGA32U4 DC 5V 16MHz MINI Development Board| 19.92 |
| Cable jack 3.5 mm| 0.79 |
| Buzzer piézo RS PRO 724-3162| 0.75 |
| Potentiometer B5K| 1.4 |
| velcro  round pad fixation| 0.28 |
| arduino jack audio module| 1.26 |
| PCB proto board 3x7| 1.18 |
| simple LED| 0.2 |
| 3M Resistor| 0.2 |
| 327  ohm Resitor| 0.08 |
| | |
| Total | 26.06 € |
  
### Schema

![schema](https://user-images.githubusercontent.com/106146411/172566455-401bdcc8-9a14-453b-8b7c-2d24d1731a99.png)
  
  A0, A1 : analog input on arduino
  D9 : digital output on arduino

![1 (2)](https://user-images.githubusercontent.com/106146411/172565982-fa904ce2-4385-43cf-8b7a-1d3f7f06c9d2.jpg)

![1 (1)](https://user-images.githubusercontent.com/106146411/172566037-27336535-7fee-4f2a-b97d-f61aa87611ae.jpg)

![1 (4)](https://user-images.githubusercontent.com/106146411/172566006-c45f5198-c682-4a5c-8f26-8f5d52493cd0.jpg)

![piezo](https://user-images.githubusercontent.com/106146411/172583981-3703cc41-dc47-45ab-a96c-9b57718d0427.jpg)


![1 (3)](https://user-images.githubusercontent.com/106146411/172566065-585cd0fb-e5dd-4c06-aed6-ac5812e4cc59.jpg)


## License

The peakDetector Library was written by Leandro César, and is licensed under MIT license.

The Arduino code was written by Samuel BERNARDET and Damien PERRIER, from the [EDICO association](http://www.edico-asso.fr), and is licensed under [WTFPL license](http://www.wtfpl.net/).
