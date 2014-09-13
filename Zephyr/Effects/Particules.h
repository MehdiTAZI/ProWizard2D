#ifndef __Particules_H__
#define __Particules_H__

struct Particles_Structure// Particles Structure	
{
	bool active;// Active (Yes/No)
	float life, Masse,Raduis,Angle;// Particle Life
	PW_Color Color;//color+fade
	PWF_Point2D Position;
	PWF_Vector2D Speed,Acceleration,Direction,Rotation;
	ProWiz::Tools::Array<PWF_Vector2D> Gravity;
	PWF_Dimension2D Dimension;
};

namespace ProWiz
{
namespace GraphicsManager
{
	
	namespace Effects
	{
		namespace Particule
		{
			enum Axes
			{
				XYAxi =0,XAxi = 1,YAxi = 2
			};
			enum Movements
			{
				Linear= 0,Straight = 1,Circular = 2
			};
			namespace ColorEffects
			{
				// Hyper
				//// Shadow effect palette
				static float Shadow[1][3]=
				{
					{0.3f, 0.3f,0.3f}
				};
				static float Wa[13][3]=
				{
					{0.15f,0.30f,1.0f},{0.15f,0.30f,1.0f},{0.15f,0.30f,1.0f},{0.15f,0.30f,1.0f},
					{0.15f,0.30f,1.0f},{0.15f,0.30f,1.0f},{0.15f,0.65f,1.0f},{0.15f,0.45f,1.0f},
					{0.15f,0.30f,1.0f},{0.15f,0.30f,1.0f},{0.15f,0.35f,1.0f},{0.15f,0.35f,1.0f}
				};
				static float Sdd[13][3]=		//  Colors
				{
					{0.5f,0.5f,0.5f},{0.5f,0.5f,0.5f},{0.5f,0.5f,0.5f},{0.5f,0.5f,0.5f},
					{0.3f,0.3f,0.3f},{0.3f,0.3f,0.3f},{0.3f,0.3f,0.3f},{0.3f,0.3f,0.3f},
					{0.2f,0.2f,0.2f},{0.2f,0.2f,0.2f},{0.2f,0.2f,0.2f},{0.2f,0.2f,0.2f}
				};
				static float colorsX[13][3]=		//  Colors
				{
					{1.0f,0.5f,0.5f},{1.0f,0.75f,0.5f},{1.0f,1.0f,0.5f},{0.75f,1.0f,0.5f},
					{0.5f,1.0f,0.5f},{0.5f,1.0f,0.75f},{0.5f,1.0f,1.0f},{0.5f,0.75f,1.0f},
					{0.5f,0.5f,1.0f},{0.75f,0.5f,1.0f},{1.0f,0.5f,1.0f},{1.0f,0.5f,0.75f}
				};

				//// Forest effect palette
				static float Forest[13][3]=
				{
					{0.50f,1.0f,0.25f},{0.50f,1.0f,0.25f},{0.50f,1.0f,0.25f},{0.50f,1.0f,0.25f},
					{0.50f,1.0f,0.25f},{0.50f,1.0f,0.25f},{0.65f,1.0f,0.25f},{0.65f,1.0f,0.25f},
					{0.50f,1.0f,0.25f},{0.50f,1.0f,0.25f},{0.55f,1.0f,0.25f},{0.55f,1.0f,0.25f}
				};

				//// Fire effect palette
				static float Fire[13][3]=
				{
					{1.0f,0.50f,0.25f},{1.0f,0.50f,0.25f},{1.0f,0.50f,0.25f},{1.0f,0.50f,0.25f},
					{1.0f,0.50f,0.25f},{1.0f,0.50f,0.25f},{1.0f,0.65f,0.25f},{1.0f,0.65f,0.25f},
					{1.0f,0.50f,0.25f},{1.0f,0.50f,0.25f},{1.0f,0.55f,0.25f},{1.0f,0.55f,0.25f}
				};


				//// Water effect palette

				//// Fire effect palette
				static float FFX[13][3]=
				{
					{1.0f,0.25f,0.0f},{1.0f,0.25f,0.0f},{1.0f,0.25f,0.0f},{1.0f,0.25f,0.0f},
					{1.0f,0.0f,0.0f},{1.0f,0.0f,0.0f},{1.0f,0.0f,0.0f},{1.0f,0.0f,0.0f},
					{1.0f,0.25f,0.25f},{1.0f,0.25f,0.25f},{1.0f,0.25f,0.25f},{1.0f,0.25f,0.25f}
				};

				//// effect palette
				static float WFX[13][3]=
				{
					{0.0f,0.0f,0.8f},{0.0f,0.0f,5.0f},{0.0f,0.0f,1.0f},{0.25f,0.25f,1.0f},
					{0.0f,0.0f,0.7f},{0.0f,0.0f,4.0f},{0.0f,0.0f,1.0f},{0.25f,0.25f,1.0f},
					{0.0f,0.0f,1.6f},{0.0f,0.0f,3.0f},{0.0f,0.0f,1.0f},{0.25f,0.25f,1.0f}
				};
				//// Plasma effect palette
				static float Plasma[7][3]=
				{
					{0.3f,0.2f,0.4f},{0.32f,0.22f,0.42f},{0.35f,0.25f,0.45f},
					{0.37f,0.27f,0.47f},{0.4f,0.3f,0.5f},{0.55f,0.35f,0.55f}
				};

				//// Neon effect palette
				static float Neon[7][3]=
				{
					{1.0f,0.2f,0.2f},{0.2f,0.2f,1.0f},{0.2f,1.0f,0.2f},{1.0f,0.2f,1.0f},
					{0.2f,1.0f,1.0f},{1.0f,1.0f,0.2f}
				};
				//// Snow effect palette
				static float Snow[13][3]=
				{
					{1.0f,1.00f,1.00f},{0.75f,0.75f,0.75f},{0.50f,0.50f,0.50f},{0.25f,0.25f,0.25f},
					{1.0f,1.00f,1.00f},{0.75f,0.75f,0.75f},{0.50f,0.50f,0.50f},{0.25f,0.25f,0.25f},
					{1.0f,1.00f,1.00f},{0.75f,0.75f,0.75f},{0.50f,0.50f,0.50f},{0.25f,0.25f,0.25f}
				};
			}
			class Particules
			{
			private :
				Particles_Structure * particle;
				unsigned __int16 MAX_PARTICLES,loop,NbrColors;
			public :
				/*
				Proleme Non resolue :
				Rotation
				Color[Min,MAX]/Color[Tableau]
				variable
				type de mouvement
				axe de mouvemeent
				Angle
				*/
		 
			PWF_IntervalPoint2D Position;//Position
				PWF_IntervalDimension2D Dimension;//Dimention des particule
				PWF_IntervalVector2D Speed,Rotation,Direction,Acceleration;
				ProWiz::Tools::Array<PWF_IntervalVector2D> Gravity;
				
				
				int AngleStyle,Mouvement_Style;
				float EngineGravity,ColorEffect[MAX_COLOR_EFFECT][3];
				//CHANGER LE SYSTEM DE COULEUR METTRE UNE CLASS AVEC PUSH(array)
				PWF_Point2D EnginePosition;
				PWF_Vector2D EngineRotation;
				PWF_Interval Fading,Life,Masse,Raduis,Angle;

				Particules(unsigned __int16 nbr_particules=100)
				{
					Mouvement_Style=0;
					//ColorEffect=;
					EnginePosition.Set();
					EngineRotation.Set();
					EngineGravity=9.8;
					AngleStyle = XYAxi;
					MAX_PARTICLES=nbr_particules;
					Life.Set(1,1);
					particle=new Particles_Structure[MAX_PARTICLES] ;
					NbrColors=1;
					for (loop=0;loop<MAX_PARTICLES;loop++)							// Initials All The Textures
					{
						particle[loop].active=true;								// Make All The Particles Active
						particle[loop].life=0.1f;								// Give All The Particles Full Life
						particle[loop].Color.Alpha=0.1f;								// Fade Speed
						particle[loop].Color.Red=0;										// Select Red Rainbow Color
						particle[loop].Color.Green=0;										// Select Red Rainbow Color
						particle[loop].Color.Blue=0;										// Select Red Rainbow Color
					}
				}

				virtual ~Particules()
				{
					//Gravity.RemoveAll();
					delete[] particle;
				}

				void SetColorEffect(float _ColorEffect[][3]=ColorEffects::Fire,unsigned __int16 NbrColor=12)
				{
					if (NbrColor==0) NbrColor=1;
					NbrColors=NbrColor;
					for(unsigned __int16 j=0;j<=3;j++)
					{
						for(unsigned __int16 i=0;i<=NbrColor;i++)
						{
							ColorEffect[i][j] = _ColorEffect[i][j];
						}
					}
				}
				void SetChange()
				{
					unsigned __int16 sz=Gravity.GetSize();
					for (loop=0;loop<MAX_PARTICLES;loop++)							// Initials All The Textures
					{
						particle[loop].Gravity.Alloc(sz);
					}
				}
				void Particules::Draw(unsigned __int16 Texture)
				{
					
					unsigned __int16 sz=Gravity.GetSize();
					
					glPushMatrix();
					glTranslatef(EnginePosition.X ,EnginePosition.Y,0);
				//	glRotatef(EngineRotation.X,1,0,0);
				//	glRotatef(EngineRotation.Y,0,1,0);
					for (loop=0;loop<MAX_PARTICLES;loop++)
					{
						
						if (particle[loop].active)							// Si les particules sont viventes
						{

							particle[loop].Speed+=particle[loop].Acceleration;
							particle[loop].life-=particle[loop].Color.Alpha;
							//loop pour chaque particle i pour chaque le tableau de gravité
							for(unsigned __int16 i =0; i<sz;i++)
							{
								particle[loop].Gravity[i].Y-=particle[loop].Masse*EngineGravity;
								particle[loop].Position+=particle[loop].Gravity[i];
							}

							particle[loop].Position+=particle[loop].Speed;
							
							//Angle reduis 
							/*//* set the speed
							tmp->dx = r*sin(direction);
							tmp->dy = -r*cos(direction);
							SYSparticules[i].x = SYSx + cos(angle)*(((float)rand()/RAND_MAX)*(SYSreact->diam/2));	// placement aleatoire sur la source				
							SYSparticules[i].y = SYSy + sin(angle)*(((float)rand()/RAND_MAX)*(SYSreact->diam/2));		
							*/
							glColor4f(particle[loop].Color.Red,particle[loop].Color.Green,particle[loop].Color.Blue,particle[loop].Color.Alpha);
						//	glPushMatrix();
					//		glRotatef(particle[loop].Rotation.X,1,0,0);
					//		glRotatef(particle[loop].Rotation.Y,0,1,0);

							glBindTexture(GL_TEXTURE_2D,Texture);
							glBegin(GL_TRIANGLE_STRIP);			// Triangle Strip car c plus rapide
							glTexCoord2d(1,1); glVertex2f(particle[loop].Position.X+particle[loop].Dimension.Width,particle[loop].Position.Y+particle[loop].Dimension.Height); //Haut adroite
							glTexCoord2d(0,1); glVertex2f(particle[loop].Position.X-particle[loop].Dimension.Width,particle[loop].Position.Y+particle[loop].Dimension.Height); // Haut agauche
							glTexCoord2d(1,0); glVertex2f(particle[loop].Position.X+particle[loop].Dimension.Width,particle[loop].Position.Y-particle[loop].Dimension.Height); // bas adroite
							glTexCoord2d(0,0); glVertex2f(particle[loop].Position.X-particle[loop].Dimension.Width,particle[loop].Position.Y-particle[loop].Dimension.Height); // bas agauche
							glEnd();									
						//	glPopMatrix();
							if (particle[loop].life<0.0f)// Si la particule est morte
							{
								//for rand 
								//T oneOverX = 1 / Value; 
								//evite la division par Zero
								
								
								particle[loop].Angle=float(((rand()%100*Angle.Maximum )/100.0f)+Angle.Minimum)*(3.1415926535897932384626433832795 / 180);
								
								particle[loop].life=float((rand()%100*Life.Maximum )/100.0f)+Life.Minimum;// lui done une nouvele vie
								particle[loop].Color.Alpha=float((rand()%100*Fading.Maximum )/100.0f)+Fading.Minimum;// Met la vie de la particule aleatoirement
								particle[loop].Raduis=float((rand()%100*Raduis.Maximum )/100.0f)+Raduis.Minimum;
							
								particle[loop].Position.X = float((rand()%100*Position.Maximum.X )/100.0f)+Position.Minimum.X;
								particle[loop].Position.Y = float((rand()%100*Position.Maximum.Y )/100.0f)+Position.Minimum.Y;

								particle[loop].Speed.X = float((rand()%100*Speed.Maximum.X )/100.0f)+Speed.Minimum.X;
								particle[loop].Speed.Y = float((rand()%100*Speed.Maximum.Y )/100.0f)+Speed.Minimum.Y;
								for(unsigned __int16 i =0; i<sz;i++)
								{
								particle[loop].Gravity[i].X = float((rand()%100*(Gravity[i].Maximum.X) )/100.0f)+(Gravity[i].Minimum.X);
								particle[loop].Gravity[i].Y = float((rand()%100*(Gravity[i].Maximum.Y) )/100.0f)+(Gravity[i].Minimum.Y);
								}
								particle[loop].Acceleration.X = float((rand()%100*Acceleration.Maximum.X )/100.0f)+Acceleration.Minimum.X;
								particle[loop].Acceleration.Y = float((rand()%100*Acceleration.Maximum.Y )/100.0f)+Acceleration.Minimum.Y; 
								
								particle[loop].Direction.X = float((rand()%100*Direction.Maximum.X )/100.0f)+Direction.Minimum.X;
								particle[loop].Direction.Y = float((rand()%100*Direction.Maximum.Y )/100.0f)+Direction.Minimum.Y; 

								particle[loop].Dimension.Width  = float((rand()%100*Dimension.Maximum.Width )/100.0f)+Dimension.Minimum.Width;
								particle[loop].Dimension.Height = float((rand()%100*Dimension.Maximum.Height )/100.0f)+Dimension.Minimum.Height; 


								particle[loop].Rotation.X = float((rand()%100*Rotation.Maximum.X )/100.0f)+Rotation.Minimum.X;
								particle[loop].Rotation.Y = float((rand()%100*Rotation.Maximum.Y )/100.0f)+Rotation.Minimum.Y; 

								
								particle[loop].Masse=float((rand()%100*Masse.Maximum )/100.0f)+Masse.Minimum;
								particle[loop].Color.Red=ColorEffect[(loop+1)/(MAX_PARTICLES/NbrColors)][0];
								particle[loop].Color.Green=ColorEffect[(loop+1)/(MAX_PARTICLES/NbrColors)][1];
								particle[loop].Color.Blue=ColorEffect[(loop+1)/(MAX_PARTICLES/NbrColors)][2];
								
							}

						}
					}
					glPopMatrix();
				}
			};
		}
	}
}

}
#endif