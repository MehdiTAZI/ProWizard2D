
#ifndef _STATE_H
#define _STATE_H

bool STATE[10];

namespace ProWiz
{

namespace State
{
	enum States
	{
	TRANSPATENCY=1,TEXTURE=2,ALPHA_TEST=3,BLENDING=4,LIGHTING=5
	};
	
	class State:public PW_Singleton<State>
	{

	public:

		void Enable (int state)
		{
		STATE[state]=true;
		if (state == TEXTURE)
			glEnable (GL_TEXTURE_2D);

		if (state == ALPHA_TEST)
		{
			glEnable( GL_ALPHA_TEST );
			glAlphaFunc( GL_GREATER, 0.0f );
		}
		if (state ==BLENDING)
		{
			glEnable (GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
		}

		if(state==TRANSPATENCY)
		{
			glEnable (GL_BLEND);
			glBlendFunc(GL_ONE,GL_ONE);
		}

		if(state==LIGHTING)
		{
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT0);
		}
	}

	bool GetState(int states){return STATE[states];}

		 void Disable(int state)
			{
		
				STATE[state]=false;
				if (state == TEXTURE)
					glDisable (GL_TEXTURE_2D);
				
				if (state == ALPHA_TEST)
						{
							glDisable( GL_ALPHA_TEST );
							glAlphaFunc( GL_GREATER, 0.0f );
						}
				if (state == BLENDING ||state == TRANSPATENCY)
						{
							glDisable (GL_BLEND);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 

						}
				if(state==LIGHTING)
					{
						glDisable(GL_LIGHTING);
						glDisable(GL_LIGHT0);
					}
						
					}
	};
}

}
#endif