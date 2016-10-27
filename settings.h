/**The MIT License (MIT)
Copyright (c) 2015 by Daniel Eichhorn
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
See more at http://blog.squix.ch
*/

#include <simpleDSTadjust.h>

// Setup
const int UPDATE_INTERVAL_SECS = 10 * 60; // Update every 10 minutes

// Pins for a WEMOS D1 R2 to ILI9341
#define TFT_DC D3
#define TFT_CS D2

// Custom color
#define ILI9341_CLOCKGREEN 0x7FE5
#define ILI9341_SILHOUTTEGREEN 0x0280

// Change LED_SILHOUETTE to 0 to disable
#define LED_SILHOUETTE 1


// NTP settings Maximum of 3 servers
#define NTP_SERVERS "0.pool.ntp.org", "1.pool.ntp.org", "1.pool.ntp.org"

// Locales (uncomment only 1)
#define Zurich
//#define Boston
//#define Sydney


#ifdef Zurich
//DST rules for Central European Time Zone
#define UTC_OFFSET +1
struct dstRule StartRule = {"CEST", Last, Sun, Mar, 2, 3600}; // Central European Summer Time = UTC/GMT +2 hours
struct dstRule EndRule = {"CET", Last, Sun, Oct, 2, 0};       // Central European Time = UTC/GMT +1 hour

// Uncomment for 24 Hour style clock
#define STYLE_24HR

// Wunderground Settings
const boolean IS_METRIC = true;
const String WUNDERGRROUND_API_KEY = "<WUNDERGROUND KEY HERE>";
const String WUNDERGRROUND_LANGUAGE = "EN";
const String WUNDERGROUND_COUNTRY = "CH";
const String WUNDERGROUND_CITY = "Zurich";
#endif

#ifdef Boston
//DST rules for US Eastern Time Zone (New York, Boston)
#define UTC_OFFSET -5
struct dstRule StartRule = {"EDT", Second, Sun, Mar, 2, 3600}; // Eastern Daylight time = UTC/GMT -4 hours
struct dstRule EndRule = {"EST", First, Sun, Nov, 1, 0};       // Eastern Standard time = UTC/GMT -5 hour

// Uncomment for 24 Hour style clock
//#define STYLE_24HR

// Wunderground Settings
const boolean IS_METRIC = false;
const String WUNDERGRROUND_API_KEY = "<WUNDERGROUND KEY HERE>";
const String WUNDERGRROUND_LANGUAGE = "EN";
const String WUNDERGROUND_COUNTRY = "MA";
const String WUNDERGROUND_CITY = "Boston";
#endif

#ifdef Sydney
//DST Rules for Australia Eastern Time Zone (Sydney)
#define UTC_OFFSET +10
struct dstRule StartRule = {"AEDT", First, Sun, Oct, 2, 3600}; // Australia Eastern Daylight time = UTC/GMT +11 hours
struct dstRule EndRule = {"AEST", First, Sun, Apr, 2, 0};      // Australia Eastern Standard time = UTC/GMT +10 hour

// Uncomment for 24 Hour style clock
//#define STYLE_24HR

// Wunderground Settings
const boolean IS_METRIC = true;
const String WUNDERGRROUND_API_KEY = "<WUNDERGROUND KEY HERE>";
const String WUNDERGRROUND_LANGUAGE = "EN";
const String WUNDERGROUND_COUNTRY = "AU";
const String WUNDERGROUND_CITY = "Sydney";
#endif

// List, so that the downloader knows what to fetch
String wundergroundIcons [] = {"chanceflurries","chancerain","chancesleet","chancesnow","clear","cloudy","flurries","fog","hazy","mostlycloudy","mostlysunny","partlycloudy","partlysunny","rain","sleet","snow","sunny","tstorms","unknown"};

/***************************
 * End Settings
 **************************/
