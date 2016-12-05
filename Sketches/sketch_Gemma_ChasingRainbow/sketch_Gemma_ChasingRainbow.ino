    //Chasing Rainbow
    //code by Chris Pietschmann - http://pietschsoft.com
     
    #include <Adafruit_NeoPixel.h>
     
    #define PIN 1
     
    // Parameter 1 = number of pixels in strip
    // Parameter 2 = pin number (most are valid)
    // Parameter 3 = pixel type flags, add together as needed:
    //   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
    //   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
    //   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
    //   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
    Adafruit_NeoPixel strip = Adafruit_NeoPixel(17, PIN, NEO_GRB + NEO_KHZ800);
    
    unsigned int rgbColor[3];
    int fadeColor = 0;
    int minBrightness = 0;
    int maxBrightness = 40;
    
    int lights[17];
    int lightIndex = 0;
    
    void setup() {
      rgbColor[0] = maxBrightness;
      rgbColor[1] = 0;
      rgbColor[2] = 0;
      
      colorWipe(strip.Color(0, 0, 0));
      
      strip.begin();
      strip.show(); // Initialize all pixels to 'off'
    }
     
    void loop() {
      rgbColor[fadeColor] = rgbColor[fadeColor] - 1;

      int nextColor = fadeColor + 1;
      if (nextColor > 2) nextColor = 0;
      
      rgbColor[nextColor] = rgbColor[nextColor] + 1;
      if (rgbColor[nextColor] > maxBrightness)
      {
        rgbColor[nextColor] = maxBrightness; 
      }
      
      if (rgbColor[fadeColor] == minBrightness)
      {
        fadeColor = nextColor;
      }
      
      //colorWipe(strip.Color(rgbColor[0], rgbColor[1], rgbColor[2]));
      
      strip.setPixelColor(lightIndex,
        strip.Color(rgbColor[0], rgbColor[1], rgbColor[2])
        );
      strip.show();
        
      lightIndex = lightIndex - 1;
      if (lightIndex < 0) lightIndex = 16;
      
      
      delay(65);
      
    }
     
    // Fill the dots one after the other with a color
    void colorWipe(uint32_t c) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
          strip.setPixelColor(i, c);
          strip.show();
      }
    }
