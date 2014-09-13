#ifndef Joystick_H
#define Joystick_H
namespace ProWiz
{
	namespace Joystick
	{
		enum Axes
		{
		XAxes=0,
		YAxes= !0,
		XYAxes = XAxes |YAxes
		};
		enum ButtonCode
		{
			//No Comment :D so easy
			BUTTON_1          = 0,
			BUTTON_2          = 1,
			BUTTON_3          = 2,
			BUTTON_4          = 3,
			BUTTON_R1         = 7,
			BUTTON_R2         = 5,
			BUTTON_L1         = 6,
			BUTTON_L2         = 4,
			BUTTON_START      = 9,
			BUTTON_SELECT     = 8,

            HAT_LEFT    = 0x08,
			HAT_RIGHT    = 0x02,
			HAT_UP		= 0x01,
			HAT_DOWN    = 0x04,
			HAT_CENTERED  = 0x00,

			HAT_RIGHTUP =(HAT_UP|HAT_RIGHT ),
			HAT_RIGHTDOWN=(HAT_RIGHT|HAT_DOWN),
			HAT_LEFTUP=(HAT_UP|HAT_LEFT),
			HAT_LEFTDOWN=(HAT_DOWN|HAT_LEFT ),

			DIRECTION_LEFT = -32768,
			DIRECTION_UP =DIRECTION_LEFT,
			DIRECTION_RIGHT = 32767,
			DIRECTION_DOWN=DIRECTION_RIGHT

		};
		class Joystick:public PW_Singleton<Joystick>
		{
		private:
		SDL_Joystick* Joypad[6];
		public :
		Joystick()
		{
			//Joypad= new SDL_Joystick[6];
		}
		Joystick(int Number)
		{
		//	Joypad=new SDL_Joystick[Number];
		}
		virtual ~Joystick()
		{
			delete[] Joypad;
		}
			//void  SetNbrEnabledJoy(int Number){Joypad= new SDL_Joystick[Number];}
			int   GetNumButton(int JoyNumber){SDL_JoystickNumButtons(Joypad[JoyNumber]);}
			int	  GetNumAxes(int JoyNumber){SDL_JoystickNumAxes(Joypad[JoyNumber]);}
			int   GetNumBalls(int JoyNumber){SDL_JoystickNumBalls(Joypad[JoyNumber]);}
			int   GetNumHats(int JoyNumber){SDL_JoystickNumHats(Joypad[JoyNumber]);}
			char* GetJoyName(int JoyNumber){SDL_JoystickName(JoyNumber);}
			
			int   GetConected(){return SDL_NumJoysticks();}
			int	  IsOpened(int JoyNumber){SDL_JoystickOpened(JoyNumber);}

			void  OpenJoy(int JoyNumber){Joypad[JoyNumber] = SDL_JoystickOpen(JoyNumber);}
			void  CloseJoy(int JoyNumber){SDL_JoystickClose(Joypad[JoyNumber]);}
		
			int IsButton(int JoyNumber,int Button)
			{return SDL_JoystickGetButton(Joypad[JoyNumber],Button);}

			int IsAxisMoved(int JoyNumber,int Axis =XYAxes)
			{return SDL_JoystickGetAxis(Joypad[JoyNumber],Axis);}

			int IsHat(int JoyNumber,int Direction)
			{return SDL_JoystickGetHat(Joypad[JoyNumber],Direction);}
			
			int IsBall(int JoyNumber,int X,int Y)
			{return SDL_JoystickGetBall(Joypad[JoyNumber],0,&X,&Y);}

	
		};
	}
}
#endif