#ifndef ProWiz_H
#define ProWiz_H
//Permet de corriger les bug de cast (ex : permet de passer int,long... a la stl)
#if (_MSC_VER >= 1300) && (WINVER < 0x0500) 

extern "C" long _ftol( double );
extern "C" long _ftol2( double dblSource ) { return _ftol( dblSource ); }
#endif

#include"Application.h"
	
	#ifdef WIN32
		#include <windows.h>
	#endif //Win32

		//Library
		#include <gl/gl.h>
		#include <gl/glu.h>
		#include<fmod.h>
		#include<SDL.h>
		//STD
		#include <ctime>
		//Other
		#include "Other\Singelton.h"
		#include "Other\Stat.h"
		//Tools
		#include "Tools\Color.h"
		#include "Tools\Time.h"
		#include <math.h>
		//Dossier Math
		#include "math\Vector.h"
		#include "math\Function.h"
		#include "math\Matrice.h"
		#include "math\Point.h"
		#include "math\dimension.h"
	
		//Dossier Sound 
		#include "Sound\Sound.h"
		//Graphics
		#include "Graphics\PrimerObjects.h"
		#include "Graphics\Sprite.h"
		//Physics
		
		#include "Physics\Collision.h"
		//Texture
		#include "TGA LOADER\TGALoader.h"

		//Other
		#include "Other\Typedef.h"

		#include "Other\Joystick.h"
		//Effects
	
		#include "Effects\glPrimerEffects.h"
		//Tools
		#include "Tools\events.h"

		//MainApplication
		#include "Other\Appoption.h"
#endif//ProWiz_H