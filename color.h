#ifndef COLOR_H_
#define COLOR_H_

#include <ostream>

 /*
  *const string NC = "\E[0m"; // No Color (reset to default)
  *const string HOME_CURSOR  = "\E[0;0H"; // Place the cursor at 0;0 position.
  *const string CLEAR_SCREEN = "\E[2J";
  */

namespace Color {
  enum Tipe {
    RESET             = 0,
    BRIGHT            = 1,
    DIM               = 2,
    UK03                = 3,
    UNDERSCORE        = 4,
    BLINK             = 5,
    UK06                = 6,
    REVERSE           = 7,
    HIDDEN            = 8,
    STRIKEOUT         = 9
    };

  enum FColor {
    FG_BLACK          = 30, 
    FG_RED            = 31, 
    FG_GREEN          = 32,
    FG_YELLOW         = 33, 
    FG_BLUE           = 34, 
    FG_MAGENTA        = 35, 
    FG_CYAN           = 36, 
    FG_LIGHT_GRAY     = 37,
    UK38                = 38,
    FG_DEFAULT        = 39,

    FG_DARK_GRAY      = 90, 
    FG_LIGHT_RED      = 91, 
    FG_LIGHT_GREEN    = 92, 
    FG_LIGHT_YELLOW   = 93, 
    FG_LIGHT_BLUE     = 94, 
    FG_LIGHT_MAGENTA  = 95, 
    FG_LIGHT_CYAN     = 96, 
    FG_WHITE          = 97,
    UK98                = 98,
    UK99                = 99
    };

  enum BColor {
    BG_BLACK          = 40, 
    BG_RED            = 41, 
    BG_GREEN          = 42,
    BG_YELLOW         = 43, 
    BG_BLUE           = 44, 
    BG_MAGENTA        = 45, 
    BG_CYAN           = 46, 
    BG_LIGHT_GRAY     = 47, 
    UK48                = 48,
    BG_DEFAULT        = 49,

    BG_DARK_GRAY      = 100, 
    BG_LIGHT_RED      = 101, 
    BG_LIGHT_GREEN    = 102, 
    BG_LIGHT_YELLOW   = 103, 
    BG_LIGHT_BLUE     = 104, 
    BG_LIGHT_MAGENTA  = 105, 
    BG_LIGHT_CYAN     = 106, 
    BG_WHITE          = 107,
    UK108                = 108,
    UK109                = 109
  };

  class Font {
    private:
      Tipe t;
      FColor fg;
      BColor bg;

      friend std::ostream&
      std::ostream& print(std::ostream& out) const{
        return out << "\E[" << f.t << ';' << f.fg << ';' << f.bg << "m";
      }
    public:
      Font(Tipe myT, FColor myFG, BColor myBG): t(myT), fg(myFG), bg(myBG) {}
      Font(Tipe myT): t(myT), fg(FG_DEFAULT), bg(BG_DEFAULT) {}
      Font(FColor myFG): t(RESET), fg(myFG), bg(BG_DEFAULT) {}
      Font(BColor myBG): t(RESET), fg(FG_DEFAULT), bg(myBG) {}
                  
      friend std::ostream&
      operator<<(std::ostream& out, const Font& f){
        return f.print(out);
      }
      bool operator=(const Font &f ) { 
        return (this->t = f.t && this->fg = f.fg && this->bg = f.bg);
      }
      bool operator==(const Font &f ) { 
        return (this->t == f.t && this->fg == f.fg && this->bg == f.bg);
      }
  };
}
#endif //COLOR_H_
