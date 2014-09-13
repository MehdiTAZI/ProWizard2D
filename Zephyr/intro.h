#ifndef GAMEINTRO_H
#define GAMEINTRO_H


void Initialise()
	{

	if (BEGIN==false)return;
			filtering = TGA_LINEAR;/*TGA_BILINEAR TGA_LINEAR TGA_NO_FILTER*/

			Wall = new ProWiz::GraphicsManager::Drawing::Sprite<float>[6];
			GAME->SetApplicationTitle("Zephyr Fight Plane Game By Tazi Mehdi");
			
			SNDEXPL.InitEngine();
			SNDFIRE.InitEngine();
			SNDFIREP.InitEngine();
			
			SNDEXPL.Open("DATA\\explod.wav");
			SNDFIREP.Open("DATA\\FIRE.wav");
			

			SND.InitEngine();
			SND.Open("DATA\\MENU.OGG");
			SND.Play();
			
			 tga_loader.LoadOpenGLTexture("Data\\intro.tga", &INTRO, filtering);
			 tga_loader.LoadOpenGLTexture("Data\\Player.tga", &PLAYER, filtering);
			 tga_loader.LoadOpenGLTexture("Data\\FIREW.tga", &PFIREW, filtering);
			 tga_loader.LoadOpenGLTexture("Data\\EXPLOD.tga", &EXPLOD, filtering);
			 tga_loader.LoadOpenGLTexture("Data\\PAUSE.tga", &PAUSE, filtering);
				tga_loader.LoadOpenGLTexture("Data\\LVL.tga", &LVL, filtering);
			
			score.Position.Set(0,0);
			score.Color.Set(50,50,50,50);
			score.Textured=true;
			score.Picture=166565;


			bldf = 0.1;
			Pausd.Dimension.Set(512,128);
			Pausd.Position.Set((GAME->Parameter.Width/2)-Pausd.Dimension.Width/2,(GAME->Parameter.Height/2)-Pausd.Dimension.Height/2);
			Pausd.Color.Set(255,255,255,0);
			Pausd.Textured=true;
			Pausd.Picture = PAUSE;

			BackGroundLvl.Dimension.Set(800,600);
			BackGroundLvl.Position.Set(0,0);
			BackGroundLvl.scrolling.Set(0,-0.005);
			BackGroundLvl.Textured=true;


	//intro Screen
			IntroScrenn.Dimension.Set(512,512);
			IntroScrenn.Position.Set((GAME->Parameter.Width/2)-IntroScrenn.Dimension.Width/2,(GAME->Parameter.Height/2)-IntroScrenn.Dimension.Height/2);
			
			IntroScrenn.Textured=true;
			IntroScrenn.Picture=INTRO;
	
	//WALLS
			for(int i=0;i<6;i++)Wall[i].Dimension.Set(96,96);
			for(int i=0;i<6;i++)Wall[i].Animate(true);	
			for(int i=0;i<6;i++)Wall[i].Init(2,32,1000);
			Wall[0].Position.Set(0,GAME->Parameter.Height - (GAME->Parameter.Height/4)-126);	
			Wall[1].Position.Set(266,GAME->Parameter.Height - (GAME->Parameter.Height/4)-126);	
			Wall[2].Position.Set(532,GAME->Parameter.Height - (GAME->Parameter.Height/4)-126);	
			
			Wall[3].Position.Set(133,GAME->Parameter.Height/4-20);	
			Wall[4].Position.Set(399,GAME->Parameter.Height/4-20);	
			Wall[5].Position.Set(665,GAME->Parameter.Height/4-20);	
			
			//PLAYER
			Player.Dimension.Set(42,55);
			Player.Animate(true);
			Player.Init(1,3,1000);	
			Player.SetPicture(PLAYER);

			PFIRE.Dimension.Set(32,64);
			PFIRE.Animate(true);
			PFIRE.Init(4,1,1000);
			PFIRE.SetPicture(PFIREW);
			PFIRE.Visible= false;


			CFIRE.Animate(true);
			
			CFIRE.Visible= false;

			
			CFIRE1.Animate(true);
			
			CFIRE1.Visible= false;

			Explod.Dimension.Set(96,98);
			Explod.Animate(true);
			Explod.Init(1,11,1000);
			Explod.SetPicture(EXPLOD);

			ExplodC.Dimension.Set(96,98);
			ExplodC.Animate(true);
			ExplodC.Init(1,11,1000);
			ExplodC.SetPicture(EXPLOD);

			//Computer 
			Computer.Animate(true);
			Computer.Init(1,3,1000);

			
			BackGroundLvl.Picture=LVL;

	}
void Destroy()
	{	

	tga_loader.Free();
	tga_loader.~TGALoader();

	SNDEXPL.Close();
	SNDFIRE.Close();
	SNDFIREP.Close();
	SNDEXPL.DestroyEngine();
	SNDFIRE.DestroyEngine();
	SNDFIREP.DestroyEngine();
	SND.Close();
	SND.DestroyEngine();
	delete[] Wall;
	}
void Intro()
	{
	//ANIMATION
	if(BldIntro<100)
		{	
		IntroScrenn.Color.Set(100,100,100,BldIntro);
		BldIntro += 0.1;
		}

	IntroScrenn.Draw();
	}

#endif