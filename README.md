# esp8266-weather-station-color-DST

Customizations of ESP8266 Weather Station in Color using ILI9341 TFT 240x320 display

## Customizations by Neptune

| Zurich | Boston | Sydney |
|:------:|:------:|:------:|
| ![Zurich](https://github.com/neptune2/esp8266-weather-station-color-DST/raw/master/resources/Zurich.jpg) | ![Boston](https://github.com/neptune2/esp8266-weather-station-color-DST/raw/master/resources/Boston.jpg) | ![Sydney](https://github.com/neptune2/esp8266-weather-station-color-DST/raw/master/resources/Sydney.jpg) |
![silhoutte](https://github.com/neptune2/esp8266-weather-station-color-DST/raw/master/resources/7seg_silhoutte.jpg)

## Specific customizations include:

* Changed TimeClient to built-in ESP8266 NTP client
 * Selectable NTP servers in settings.h
* Added auto Daylight Saving Time adjust using simpleDSTadjust library
 * https://github.com/neptune2/simpleDSTadjust
 * DST rules and timezone settings customizable in settings.h
* Special version of ArialRoundedMtBold_36 with Degree symbol
 * added degree symbol to temperature display
* Changed Clock to retro 7-segment look with optional silhoutte background
 * used DSEG7ClassicBold_44 font (from http://www.keshikan.net/fonts-e.html)
* Added Blinking colon to clock - 1 sec on , 1 sec off
* Added choice of 24 hour or 12 hour clock
* Slight adjustment to various fields (to fit 7-seg clock)
* various small fixes


## Hardware Requirements

This code is made for an 240x320 65K ILI9341 display with code running on an ESP8266.
You can buy such a display here: 

[http://www.banggood.com/2_2-Inch-Serial-TFT-SPI-Screen-p-912854.html](http://www.banggood.com/2_2-Inch-Serial-TFT-SPI-LCD-Screen-Module-HD-240-x-320-5110-Compatible-p-912854.html?p=6R31122484684201508S)

## Software Requirements/ Libraries

* Arduino IDE with ESP8266 platform installed
* [Weather Station Library](https://github.com/squix78/esp8266-weather-station) or through Library Manager
* [Adafruit ILI9341](https://github.com/adafruit/Adafruit_ILI9341) or through Library Manager
* [Adafruit GFX](https://github.com/adafruit/Adafruit-GFX-Library) or through Library Manager
* [WifiManager](https://github.com/tzapu/WiFiManager)
* [simpleDSTadjust](https://github.com/neptune2/simpleDSTadjust)

You also need to get an API key for the Wunderground data: https://www.wunderground.com/

## Wiring for Wemos D1R2

| ILI9341       | Wemos D1R2    |
| ------------- |:-------------:| 
| MISO          | -             | 
| LED           | 3V3           | 
| SCK           | SCLK/D5       | 
| MOSI          | MOSI/D7       |
| DC/RS         | D3            |
| RESET         | RST           |
| CS            | D2            |
| GND           | GND           |
| VCC           | 3V3           |

