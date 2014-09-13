#ifndef WRITIG_H
#define WRITIG_H
extern ProWiz::MainApp*GAME ;
GLuint	Tbase;	
namespace ProWiz
	{
	namespace GraphicsManager
		{
		namespace Writing
			{

				class Text
					{
					private :
						ProWiz::State::State P;
					public :
						
						GLint Textured;
						
						
						Text::Text()
						{

						}
						Text::~Text()
						{

						}
					GLvoid Text::BuildFont(GLint xt, GLint yt,GLint SizeOfFont)	// Creé notre list de caractaire depuis bmp
						{
						float	cx;											
						float	cy;											

						Tbase=glGenLists(256);								// Creé 256 Display Lists
						glBindTexture(GL_TEXTURE_2D,Textured);
						for (GLuint loop=0; loop<256; loop++)				// Boucle 256 (Lists)
							{
							cx=float(loop%16)/16.0f;						// Position X du Caracter
							cy=float(loop/16)/16.0f;						// Position Y du Caracter

							glNewList(Tbase+loop,GL_COMPILE);				//Commence la creation de la list
							glBegin(GL_QUADS);							// Utilisé un Carré pour chaque caractaire	
							glTexCoord2f(cx,1-cy-0.0525f);			
							glVertex2i(0,0);					
							glTexCoord2f(cx+0.0625f,1-cy-0.0625f);	
							glVertex2i(SizeOfFont,0);						
							glTexCoord2f(cx+0.0625f,1-cy);			
							glVertex2i(SizeOfFont,SizeOfFont);						
							glTexCoord2f(cx,1-cy);					
							glVertex2i(0,SizeOfFont);						
							glEnd();									// Terminé le dessin du carré
							glTranslated(xt,yt,0);						//Espace entre chaque caractére 
							glEndList();									// Terminé le dessin de la list
							}													
						}

					GLvoid Text::KillFont(GLvoid)									
						{
						glDeleteLists(Tbase,256);							// Efface les 256 lists
						}

					GLvoid Text::PrintText(GLint x, GLint y, char *string, GLint blood,GLfloat valred,GLfloat valgreen,GLfloat valblue,bool Transparent)
						{
						glBindTexture(GL_TEXTURE_2D,Textured);				// applique Texture de font
						glDisable(GL_DEPTH_TEST);							
						glMatrixMode(GL_PROJECTION);						
						glPushMatrix();										// Stoke la Matrix Projection 
						glLoadIdentity();									// reset la Matrix Projection
						int HEIGHT = GAME->GetHeight();
						int WHIDTH  = GAME->GetWidth();
						glOrtho(0,HEIGHT,0,WHIDTH ,-1,1);					// DESSIN EN 2D
						glMatrixMode(GL_MODELVIEW);							// Selectione Stoke la Matrix Modelview
						glPushMatrix();										
						glLoadIdentity();									
						glTranslated(x,y,0);								// Position le Texte 
						glListBase(Tbase-32+(128*blood));					// Choix du Fonts Normal->0 Gras->1


						glEnable(GL_BLEND);	
						if (Transparent==TRUE)glBlendFunc(GL_ONE, GL_ONE);

						glColor3f(valred,valgreen,valblue);
						glCallLists(strlen(string),GL_BYTE,string);			// Ecrire le texte

						if(P.GetState(ProWiz::State::BLENDING)==false)
							{
										
							glDisable(GL_BLEND);
							glEnable(GL_DEPTH_TEST);
							}

						glMatrixMode(GL_PROJECTION);						
						glPopMatrix();									
						glMatrixMode(GL_MODELVIEW);							
						glPopMatrix();										


						}
				};
			 

			}
		}
	}
#endif