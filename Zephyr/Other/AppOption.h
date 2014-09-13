#ifndef MainApp_H_
#define MainApp_H_

struct WinParameter
{
	int Width ,Height,BitPerPixel,Timer_Draw_Interval,Timer_Update_Interval;
	bool FullScreen , Resizable,DblBuffer,AutoSize;
	char*BmpFileName ;

	WinParameter(){Set();}
	
	WinParameter(int _Width,int _Height,int _BitPerPixel,int _Timer_Draw_Interval,int _Timer_Update_Interval,bool _FullScreen,bool _Resizable,bool _DblBuffer,bool _AutoSize,char* _BmpFileName)
	{Set(_Width,_Height,_BitPerPixel,_Timer_Draw_Interval,_Timer_Update_Interval,_FullScreen,_Resizable,_DblBuffer,_AutoSize,_BmpFileName);}
	
	void Set()
	{
		Width =800;Height=600;BitPerPixel=32,Timer_Draw_Interval=0,Timer_Update_Interval=0;
		FullScreen=false ; Resizable=true,DblBuffer=true,AutoSize=true;
		BmpFileName=NULL;
	}
	void Set(int _Width,int _Height,int _BitPerPixel,int _Timer_Draw_Interval,int _Timer_Update_Interval,bool _FullScreen,bool _Resizable,bool _DblBuffer,bool _AutoSize,char* _BmpFileName)
	{
		Width =_Width;Height=_Height;BitPerPixel=_BitPerPixel,Timer_Draw_Interval=_Timer_Draw_Interval,Timer_Update_Interval=_Timer_Update_Interval;
		FullScreen=_FullScreen; Resizable=_Resizable,DblBuffer=_DblBuffer,AutoSize=_AutoSize;
		BmpFileName=_BmpFileName;
	}

};

class MainApplication:public PW_Events
{
private :

	SDL_Surface *surface;
	SDL_Event p_Event;

	bool Doned;

	float next,next1,now ;

	char AppName[64];
	int Flags;
public:
	int i_WinX,
		i_WinY, 
		f_WinX,
		f_WinY;

	virtual void OnJoyAxisMove(int X,int Y)=0;

	virtual void OnJoyButtonDown(int Button)=0;

	virtual void OnJoyButtonUp(int Button)=0;

	virtual void OnJoyBallMove(int X,int Y)=0;

	virtual void OnJoyHat(int Direction)=0;

	WinParameter Parameter;
	
	MainApplication()
	{

		Doned=false;
		next=0;next1=0;now =0;Flags=0; i_WinX=0;i_WinY=0;f_WinX=0;f_WinY=0;
	}

	virtual ~MainApplication()
	{
		
	}

	void SetTimerInterval(int Drawing_Timer=50,int Updating_Timer=50)
	{
		Parameter.Timer_Draw_Interval=Drawing_Timer;
		Parameter.Timer_Update_Interval=Updating_Timer;
	}

	void Minimized(){SDL_WM_IconifyWindow();}

	void ToggleFullScreen(){SDL_WM_ToggleFullScreen(surface);}
		

	void  Run ()
	{	
		// Initialise le programme
		Init (Parameter.Width,Parameter.Height,Parameter.BitPerPixel,Parameter.FullScreen,Parameter.Resizable,Parameter.BmpFileName);

		pKeyBoard = SDL_GetKeyState (0);

		while ( !Doned )
		{
			HandleMessage ();		// Reçois les Messages Envoie par le system

			now = SDL_GetTicks();
			if ( next <= now ) 
			{
				next = now+Parameter.Timer_Update_Interval;
				Update ();					// Mise a jour !!
			}

			if ( next1 <= now ) 
			{
				next1 = now+Parameter.Timer_Draw_Interval;
				Draw ();					// Boucle de dessin
				glFlush ();//Force a terminé les commmandes OpenGL
			}

			if(Parameter.DblBuffer==true)Flip ();// Echange les deux Buffer
		}

		OnExit ();
		atexit(SDL_Quit);
		
	}

	bool Init( int Width = 800, int Height =600, int Bpp = 32, bool FullScreen = false ,bool Resizable=true,char*BitmapFileName=NULL)
	{

		if( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_JOYSTICK)<0  ) 
		{
			//	printf("Error initializing: %s\n", SDL_GetError());
			Doned=true;
			return false;
		}
		Parameter.FullScreen=FullScreen ; 
		Parameter.Resizable=Resizable;

		MouseState[0] = false;
		MouseState[1] = false;
		MouseState[2] = false;

		i_WinX=0;
		f_WinX=0;
		f_WinX = Parameter.Width= Width;
		f_WinY = Parameter.Height =Height;

		Parameter.BitPerPixel  = Bpp;

		// Nettoyer en quittant
		atexit( SDL_Quit );

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		Flags = SDL_OPENGL;

		if (FullScreen )Flags |= SDL_FULLSCREEN;
		if (Resizable)Flags |=SDL_RESIZABLE;

		if (BitmapFileName != NULL)SDL_WM_SetIcon(SDL_LoadBMP(BitmapFileName), NULL);

		surface=SDL_SetVideoMode(f_WinX, f_WinY, Parameter.BitPerPixel, Flags);
		if( surface== NULL)
		{
			//printf("\n Errorr !!! : %s \n", SDL_GetError());
			Doned=true;
			return false;
		}

		//BackColor
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);//

		glShadeModel(GL_SMOOTH);// Dégradé de couleur
		glEnable(GL_TEXTURE_2D);
		glEnable (GL_COLOR_MATERIAL);// Active les couleurs pour les objets
				
		glHint(GL_POINT_SMOOTH_HINT,GL_NICEST);	// Really Nice Point Smoothing
		glHint(GL_POLYGON_SMOOTH_HINT,GL_NICEST);// Really Nice Polygon Smoothing
		glHint(GL_LINE_SMOOTH_HINT,GL_NICEST);// Really Nice Line Smoothing
  
		SDL_JoystickEventState(SDL_ENABLE);

		SDL_JoystickUpdate();

		SDL_ShowCursor (false);

		SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL+40);

		SetApplicationTitle("ProWiz 2D Game Engine By[Tazi Mehdi]");


		Resize (0,0,f_WinX, f_WinY);
		OnInit();
		return true;
	}
	void  Resize (int iWidth, int iHeight,int fWidth, int fHeight)
	{
		i_WinX = iWidth;
		i_WinY = iHeight;
		f_WinX = fWidth;
		f_WinY = fHeight;

		Parameter.Width=f_WinX-i_WinX;
		Parameter.Height=f_WinY-i_WinY;
		
		glViewport(i_WinX, i_WinY,f_WinX, f_WinY);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity ();
		glOrtho(i_WinX, f_WinX, i_WinY, f_WinY, -1, 1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity ();
	}
	int SetDelayKey(int Delay=500,int Interval=90)
	{return SDL_EnableKeyRepeat(Delay,Interval);}

	/*
	Swap le back buffer avec le front buffer
	*/
	void Flip ()
	{
		//double buffering
		SDL_GL_SwapBuffers();
		glClear(GL_COLOR_BUFFER_BIT);
		glLoadIdentity(); 
	}
	void SetBackColor(PW_Color Color)
	{glClearColor(Color.Red/100.0f, Color.Green/100.0f, Color.Blue/100.0f, Color.Alpha/100.0f);}

	void SetBackColor(float Red=0.0f,float Green=0.0f,float Blue=0.0f,float Alpha=50.0f)
	{glClearColor(Red/100.0f, Green/100.0f, Blue/100.0f, Alpha/100.0f);}

	void ShowCursor(bool Stat=true){SDL_ShowCursor(Stat);}

	

	void SetApplicationTitle ( char* Title="ProWiz Engine" )
	{
		strncpy ( AppName, Title, 64 );
		SDL_WM_SetCaption ( Title, NULL );
	}
	void Quit ()
	{Doned = true;}

	inline int GetWidth(){ return f_WinX- i_WinX;}
	inline int GetHeight(){ return f_WinY-i_WinY;}
	inline int GetBpp()	{ return Parameter.BitPerPixel;}

	PWI_Vector2D GetWindowSize ()
	{return PWI_Vector2D ((int)f_WinX- i_WinX, (int)f_WinY-i_WinY);}

private:
	int JoyValX,JoyValY;
BOOL JoyButton[JOY_MAX_BUTTON];
	void  HandleMessage()
	{
		// Gestion des messages
		while( SDL_PollEvent( &p_Event ) )
		{

			switch( p_Event.type )
			{		

			case SDL_QUIT:
				Doned = true;
				
				break;

			case SDL_ACTIVEEVENT:
				if ( p_Event.active.state & SDL_APPACTIVE ) {
					if( p_Event.active.gain )OnActivate();
				}
				break;
				
			case SDL_VIDEORESIZE  :

				if (Parameter.AutoSize==true)
				{
					if(Init(p_Event.resize.w,p_Event.resize.h,Parameter.BitPerPixel,Parameter.FullScreen,Parameter.Resizable,Parameter.BmpFileName)==false)Doned=true;
					Resize(0,0, p_Event.resize.w, p_Event.resize.h );
				}
				OnResize();
				break;

			case SDL_MOUSEMOTION:
				//	Mouse Position
				MousePos.X = p_Event.motion.x;
				MousePos.Y = p_Event.motion.y;
				OnMouseMove();
				break;

			case SDL_MOUSEBUTTONUP:

				switch ( p_Event.button.button )
				{

				case SDL_BUTTON_LEFT:
					MouseState[0] = false;
					OnMouseUp(p_Event.button.button);
					break;

				case  SDL_BUTTON_MIDDLE:
					MouseState[1] = false;
					OnMouseUp(p_Event.button.button);
					break;

				case  SDL_BUTTON_RIGHT:
					MouseState[2] = false;
					OnMouseUp(p_Event.button.button);
					break;

				default:
					break;
				}
				break;

			case SDL_MOUSEBUTTONDOWN:
				switch ( p_Event.button.button )
				{

				case  SDL_BUTTON_LEFT:
					MouseState[0] = true;
					OnClick ();			
					OnMouseDown(p_Event.button.button);
					break;

				case  SDL_BUTTON_MIDDLE:
					MouseState[0] = true;
					OnClick ();
					OnMouseDown(p_Event.button.button);
					break;

				case  SDL_BUTTON_RIGHT:
					MouseState[0] = true;
					OnClick ();
					OnMouseDown(p_Event.button.button);
					break;

				default:
					break;
				}
				break;
			case SDL_KEYDOWN:

				OnKeyPress(p_Event.key.keysym.sym);
				OnKeyDown(p_Event.key.keysym.sym);
				pKeyBoard[p_Event.key.keysym.sym] = 1;

				break;

			case SDL_KEYUP:
				OnKeyUp(p_Event.key.keysym.sym);
				pKeyBoard[p_Event.key.keysym.sym] = 0;
				break;

			case SDL_JOYAXISMOTION:

				 if( p_Event.jaxis.axis == 0)
					
				 { 
					 JoyValX=p_Event.jaxis.value;
					 JoyValY=0;
				 }
				
				 else

				 {
					 JoyValY= p_Event.jaxis.value;
					 JoyValX=0;
				 }
					OnJoyAxisMove(JoyValX,JoyValY);
				break;
	
			case SDL_JOYBUTTONDOWN:
				
				JoyButton[p_Event.jbutton.button]=true;
				OnJoyButtonDown(p_Event.jbutton.button);
	
				break;

			case SDL_JOYBUTTONUP:

				JoyButton[p_Event.jbutton.button]=false;
				OnJoyButtonUp(p_Event.jbutton.button);

				break;

			case SDL_JOYBALLMOTION:  /* Handle Joyball Motion */

				if( p_Event.jball.ball == 0 )
				OnJoyBallMove(p_Event.jball.xrel ,p_Event.jball.yrel);
	
				break;

			case SDL_JOYHATMOTION:  /* Handle Hat Motion */

					OnJoyHat(p_Event.jhat.value);
							
				break;


			default:
				break;
			}

		}
	}
};

namespace ProWiz
{
	namespace KeyCode
	{
		enum CMode{
			m_NONE     = 0x0000,
			m_LSHIFT   = 0x0001,
			m_RSHIFT   = 0x0002,
			m_LCTRL    = 0x0040,
			m_RCTRL    = 0x0080,
			m_LALT     = 0x0100,
			m_RALT     = 0x0200,
			m_LMETA    = 0x0400,
			m_RMETA    = 0x0800,
			m_NUM      = 0x1000,
			m_CAPS     = 0x2000,
			m_MODE     = 0x4000,
			m_RESERVED = 0x8000
		} ;
		enum CMouse
		{
			XBUTTON1      = 0x05,  // Windows 2000/XP: X1 mouse button 
			XBUTTON2      = 0x06,  // Windows 2000/XP: X2 mouse button 
			LEFT_BUTTON   = 0x01,  // Left mouse button  
			RIGHT_BUTTON  = 0x02,  // Right mouse button  
			MIDDLE_BUTTON = 0x04,  // Middle mouse button (three-button mouse)  
		};
		enum CKeyBoard{
			/* The keyboard syms have been cleverly chosen to map to ASCII */
			_UNKNOWN	= 0,
			_FIRST		= 0,
			BACKSPACE	= 8,
			TAB		= 9,
			CLEAR		= 12,
			RETURN		= 13,
			PAUSE		= 19,
			ESCAPE		= 27,
			SPACE		= 32,
			EXCLAIM	= 33,
			QUOTEDBL	= 34,
			HASH		= 35,
			DOLLAR		= 36,
			AMPERSAND	= 38,
			QUOTE		= 39,
			LEFTPAREN	= 40,
			RIGHTPAREN	= 41,
			ASTERISK	= 42,
			PLUS		= 43,
			COMMA		= 44,
			MINUS		= 45,
			PERIOD		= 46,
			SLASH		= 47,
			_0			= 48,
			_1			= 49,
			_2			= 50,
			_3			= 51,
			_4			= 52,
			_5			= 53,
			_6			= 54,
			_7			= 55,
			_8			= 56,
			_9			= 57,
			COLON		= 58,
			SEMICOLON	= 59,
			LESS		= 60,
			EQUALS		= 61,
			GREATER		= 62,
			QUESTION		= 63,
			AT			= 64,
			/* 
			Skip uppercase letters
			*/
			LEFTBRACKET	= 91,
			BACKSLASH		= 92,
			RIGHTBRACKET	= 93,
			CARET			= 94,
			UNDERSCORE		= 95,
			BACKQUOTE		= 96,
			a				= 97,
			b				= 98,
			c				= 99,
			d				= 100,
			e				= 101,
			f				= 102,
			g				= 103,
			h				= 104,
			i				= 105,
			j				= 106,
			k				= 107,
			l				= 108,
			m				= 109,
			n				= 110,
			o				= 111,
			p				= 112,
			q				= 113,
			r				= 114,
			s				= 115,
			t				= 116,
			u				= 117,
			v				= 118,
			w				= 119,
			x				= 120,
			y				= 121,
			z				= 122,
			DELETE_			= 127,
			/* End of ASCII mapped keysyms */

			/* International keyboard syms */
			WORLD_0		= 160,		/* 0xA0 */
			WORLD_1		= 161,
			WORLD_2		= 162,
			WORLD_3		= 163,
			WORLD_4		= 164,
			WORLD_5		= 165,
			WORLD_6		= 166,
			WORLD_7		= 167,
			WORLD_8		= 168,
			WORLD_9		= 169,
			WORLD_10		= 170,
			WORLD_11		= 171,
			WORLD_12		= 172,
			WORLD_13		= 173,
			WORLD_14		= 174,
			WORLD_15		= 175,
			WORLD_16		= 176,
			WORLD_17		= 177,
			WORLD_18		= 178,
			WORLD_19		= 179,
			WORLD_20		= 180,
			WORLD_21		= 181,
			WORLD_22		= 182,
			WORLD_23		= 183,
			WORLD_24		= 184,
			WORLD_25		= 185,
			WORLD_26		= 186,
			WORLD_27		= 187,
			WORLD_28		= 188,
			WORLD_29		= 189,
			WORLD_30		= 190,
			WORLD_31		= 191,
			WORLD_32		= 192,
			WORLD_33		= 193,
			WORLD_34		= 194,
			WORLD_35		= 195,
			WORLD_36		= 196,
			WORLD_37		= 197,
			WORLD_38		= 198,
			WORLD_39		= 199,
			WORLD_40		= 200,
			WORLD_41		= 201,
			WORLD_42		= 202,
			WORLD_43		= 203,
			WORLD_44		= 204,
			WORLD_45		= 205,
			WORLD_46		= 206,
			WORLD_47		= 207,
			WORLD_48		= 208,
			WORLD_49		= 209,
			WORLD_50		= 210,
			WORLD_51		= 211,
			WORLD_52		= 212,
			WORLD_53		= 213,
			WORLD_54		= 214,
			WORLD_55		= 215,
			WORLD_56		= 216,
			WORLD_57		= 217,
			WORLD_58		= 218,
			WORLD_59		= 219,
			WORLD_60		= 220,
			WORLD_61		= 221,
			WORLD_62		= 222,
			WORLD_63		= 223,
			WORLD_64		= 224,
			WORLD_65		= 225,
			WORLD_66		= 226,
			WORLD_67		= 227,
			WORLD_68		= 228,
			WORLD_69		= 229,
			WORLD_70		= 230,
			WORLD_71		= 231,
			WORLD_72		= 232,
			WORLD_73		= 233,
			WORLD_74		= 234,
			WORLD_75		= 235,
			WORLD_76		= 236,
			WORLD_77		= 237,
			WORLD_78		= 238,
			WORLD_79		= 239,
			WORLD_80		= 240,
			WORLD_81		= 241,
			WORLD_82		= 242,
			WORLD_83		= 243,
			WORLD_84		= 244,
			WORLD_85		= 245,
			WORLD_86		= 246,
			WORLD_87		= 247,
			WORLD_88		= 248,
			WORLD_89		= 249,
			WORLD_90		= 250,
			WORLD_91		= 251,
			WORLD_92		= 252,
			WORLD_93		= 253,
			WORLD_94		= 254,
			WORLD_95		= 255,		/* 0xFF */

			/* Numeric keypad */
			KP0		= 256,
			KP1		= 257,
			KP2		= 258,
			KP3		= 259,
			KP4		= 260,
			KP5		= 261,
			KP6		= 262,
			KP7		= 263,
			KP8		= 264,
			KP9		= 265,
			KP_PERIOD	= 266,
			KP_DIVIDE	= 267,
			KP_MULTIPLY= 268,
			KP_MINUS	= 269,
			KP_PLUS	= 270,
			KP_ENTER	= 271,
			KP_EQUALS	= 272,

			/* Arrows + Home/End pad */
			UP			= 273,
			DOWN		= 274,
			RIGHT		= 275,
			LEFT		= 276,
			INSERT		= 277,
			HOME		= 278,
			END		= 279,
			PAGEUP		= 280,
			PAGEDOWN	= 281,

			/* Function keys */
			F1			= 282,
			F2			= 283,
			F3			= 284,
			F4			= 285,
			F5			= 286,
			F6			= 287,
			F7			= 288,
			F8			= 289,
			F9			= 290,
			F10		= 291,
			F11		= 292,
			F12		= 293,
			F13		= 294,
			F14		= 295,
			F15		= 296,

			/* Key state modifier keys */
			NUMLOCK	= 300,
			CAPSLOCK	= 301,
			SCROLLOCK	= 302,
			RSHIFT		= 303,
			LSHIFT		= 304,
			RCTRL		= 305,
			LCTRL		= 306,
			RALT		= 307,
			LALT		= 308,
			RMETA		= 309,
			LMETA		= 310,
			LSUPER		= 311,		/* Left "Windows" key */
			RSUPER		= 312,		/* Right "Windows" key */
			MODE		= 313,		/* "Alt Gr" key */
			COMPOSE	= 314,		/* Multi-key compose key */

			/* Miscellaneous function keys */
			HELP		= 315,
			PRINT		= 316,
			SYSREQ		= 317,
			BREAK		= 318,
			MENU		= 319,
			POWER		= 320,		/* Power Macintosh power key */
			EURO		= 321,		/* Some european keyboards */
			UNDO		= 322,		/* Atari keyboard has Undo */

			CTRL	=LCTRL|RCTRL,
			SHIFT	=LSHIFT|RSHIFT,
			ALT		= LALT|RALT,
			META	=LMETA|RMETA
		};
	}
	class MainApp : public MainApplication ,public PW_Singleton<MainApp>
	{
	
	public:

		void OnActivate();

		void OnClick();

		void OnMouseUp(int Key);

		void OnMouseDown(int Key);

		void OnMouseMove();

		void OnJoyAxisMove(int XValue,int YValue);

		void OnJoyButtonDown(int Button);

		void OnJoyButtonUp(int Button);

		void OnJoyBallMove(int XValue,int YValue);

		void  OnJoyHat(int Direction);

		void OnInit();

		void OnKeyPress(int Key);

		void OnKeyDown(int Key);

		void OnKeyUp(int Key);

		void Update();

		void Draw() ;

		void OnResize();

		void OnExit();
	};
}
#endif
