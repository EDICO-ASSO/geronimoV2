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

| Component | Cost (in €uro) | Shopping link |
| --------- | -------------- | ------------- |
| CJMCU BEETLE Keyboard BadUSB ATMEGA32U4 DC 5V 16MHz MINI Development Board| 19.92 | [link](https://www.amazon.fr/gp/product/B07VL6G914/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1) |
| Cable jack 3.5 mm| 0.79 | [link](https://www.amazon.fr/HDSupply-ac011-025-C%C3%A2ble-audio-st%C3%A9r%C3%A9o-Blanc/dp/B01ITXL90O/ref=sr_1_5?crid=41CSOGJSMDH3&keywords=jack+jack+cable+ster%C3%A9o&qid=1654676796&refinements=p_76%3A437878031&rnid=1680780031&rps=1&s=electronics&sprefix=jack+jack+cable+ster%C3%A9o%2Caps%2C75&sr=1-5) |
| Buzzer piézo RS PRO 724-3162| 0.75 | [link](https://fr.rs-online.com/web/p/buzzers-piezo/7243162) |
| Potentiometer B5K| 1.4 | [link](https://www.amazon.fr/potentiom%C3%A8tre-Arduino-Raspberry-dautres-projets/dp/B07B2SB19M/ref=pd_day0_sccl_2_7/257-9752886-0228840?pd_rd_w=NV1um&content-id=amzn1.sym.5a3d874f-f0eb-4ad9-ac25-35518704bcec&pf_rd_p=5a3d874f-f0eb-4ad9-ac25-35518704bcec&pf_rd_r=6VSNYYHM0JT6VPH556WK&pd_rd_wg=5jNif&pd_rd_r=9a3f21e7-2d93-4f15-) |
| velcro  round pad fixation| 0.28 | [link](https://www.amazon.fr/HIMRY-Pastille-Fixation-Agrippant-Autocollantes/dp/B08CF2PYFL/ref=sr_1_3_sspa?crid=2Z23M4KMWPKMH&keywords=velcro+rond&qid=1654678881&sprefix=velcro+rond%2Caps%2C57&sr=8-3-spons&psc=1) |
| arduino jack audio module| 1.26 | [link](https://www.amazon.fr/modules-audio-Breakout-st%C3%A9r%C3%A9o-Arduino/dp/B088QXGQTH/ref=sr_1_9?crid=O1ZEXZ5M01AW&keywords=jack+adapter+arduino&qid=1654678994&sprefix=jack+adapter+arduino%2Caps%2C73&sr=8-9) |
| PCB proto board 3x7| 1.18 | [link](https://www.amazon.fr/Prototype-Circuit-Imprim%C3%A9-Universel-Soudure/dp/B0B27JBKQV/ref=sr_1_13?crid=24M8BKCWI5VT&keywords=pcb+board+kit+3x7&qid=1654679314&sprefix=pcb+board+kit+3x7%2Caps%2C51&sr=8-13) |
| simple LED| 0.2 | [link](https://www.amazon.fr/10-LED-lumi%C3%A8re-diffuse-luminosit%C3%A9-Lumi%C3%A8re/dp/B06XXWS741/ref=sr_1_6?crid=3O49ZQD18U9K&keywords=led+arduino&qid=1654679466&sprefix=led+arduino%2Caps%2C65&sr=8-6) |
| 3M Resistor| 0.2 | [link](https://www.amazon.fr/10x-R%C3%A9sistance-Film-Carbone-171res381/dp/B07FKTBZYW/ref=sr_1_8?crid=1UEQQGWHLY41L&keywords=3MOhm+Resistor&qid=1654679523&sprefix=3mohm%2Caps%2C48&sr=8-8) |
| 327  ohm Resitor| 0.08 | [link](https://www.amazon.fr/R%C3%A9sistances-carbone-300-Ohms-Watts/dp/B01JPAYU1A/ref=sr_1_11?crid=2498MVFIYNG2P&keywords=300+ohms+resistor&qid=1654679960&sprefix=300+ohms+resistor%2Caps%2C62&sr=8-11) |
| | | |
| **Total** | **26.06 €** | |
  
### Schema

![schema](https://user-images.githubusercontent.com/106146411/172566455-401bdcc8-9a14-453b-8b7c-2d24d1731a99.png)
  
**A0, A1**: analog input on arduino
**D9**: digital output on arduino

![1 (2)](https://user-images.githubusercontent.com/106146411/172565982-fa904ce2-4385-43cf-8b7a-1d3f7f06c9d2.jpg)

![1 (1)](https://user-images.githubusercontent.com/106146411/172566037-27336535-7fee-4f2a-b97d-f61aa87611ae.jpg)

![1 (4)](https://user-images.githubusercontent.com/106146411/172566006-c45f5198-c682-4a5c-8f26-8f5d52493cd0.jpg)

![piezo](https://user-images.githubusercontent.com/106146411/172583981-3703cc41-dc47-45ab-a96c-9b57718d0427.jpg)


![1 (3)](https://user-images.githubusercontent.com/106146411/172566065-585cd0fb-e5dd-4c06-aed6-ac5812e4cc59.jpg)


## License

The peakDetector Library was written by Leandro César, and is licensed under MIT license.

The Arduino code was written by Samuel BERNARDET and Damien PERRIER, from the [EDICO association](http://www.edico-asso.fr), and is licensed under [WTFPL license](http://www.wtfpl.net/).
