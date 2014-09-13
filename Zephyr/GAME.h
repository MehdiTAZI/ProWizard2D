#ifndef GAMEPLAYING_H
#define GAMEPLAYING_H

void FIRELUNSH()
	{
		if (DEFEULT_MISSILE == PLAYER_FIRE1)
			{
				PFIRE.Update(30);
				PFIRE.Position.Y +=3;
				if(PFIRE.Position.Y>=GAME->Parameter.Height)PFIRE.Visible=false;
			}
		if (DEFEULT_MISSILE == PLAYER_FIRE2)
			{
			PFIRE.Update(30);
			PFIRE.Position.Y +=2;
			if(PFIRE.Position.Y>=GAME->Parameter.Height)PFIRE.Visible=false;
			}

		if (DEFEULT_C_MISSILE == COMPUTER_FIRE)
			{
			CFIRE.Update(30);
			CFIRE1.Update(30);
			CFIRE.Position.Y -=3;
			CFIRE1.Position.Y -=3;
			if(CFIRE.Position.Y<=0)CFIRE.Visible=false;
			if (CFIRE1.Position.Y<=0)CFIRE1.Visible=false;
			}
	}

void GAMEOVER()
	{
		MessageBox(0,"Oh My Gad!!!!You Lose  T_T restard this level ;)","GAME OVER !!",32);
		Computer.Visible=true;
		Player.Visible=true;
		CFIRE.Visible=false;
		CFIRE1.Visible=false;
		PFIRE.Visible=false;

		INITLVL(currentlvl);
	}
void FINAl()
	{
		MessageBox(0,"YEAH!!!!Good Game ^_^ You Win ;)","GOOD GAME !!",32);
		currentlvl =0;
	}
void WINNER()
	{
		EXPLD_ANI = EXPLD_NOTHING;
		if (currentlvl>=3)FINAl();
		//STAGE SUIVANT
		Computer.Visible=true;
		Player.Visible=true;
		CFIRE.Visible=false;
		CFIRE1.Visible=false;
		PFIRE.Visible=false;
		INITLVL(currentlvl+1);
	}
void INITLVL(int lvl)
	{
	if(lvl ==LVL_ONE)
		{
		BackGroundLvl.Color.Set(0,100,0,100);
		FIREPOS = 100;
		currentlvl=1;
		SND.Stop();
		SND.Open("Data\\Music1.ogg");
		SND.Play();
		CFIRE.Dimension.Set(32,32);
		CFIRE1.Dimension.Set(32,32);	
		SNDFIRE.Open("DATA\\FIRE1.wav");
		Computer.Color.Set(20,20,100,100);
		tga_loader.LoadOpenGLTexture("Data\\MUR1.tga", &MUR, filtering);
		tga_loader.LoadOpenGLTexture("Data\\FIRE1.tga", &FIRE, filtering);
		tga_loader.LoadOpenGLTexture("Data\\ENEMY1.tga", &ENEMY, filtering);
		CFIRE.SetPicture(FIRE);
		CFIRE1.SetPicture(FIRE);
		CFIRE.Init(4,1,1000);
		CFIRE1.Init(4,1,1000);
		Life = 10;
		score.Dimension.Set(Life*40,20);
		Computer.Dimension.Set(89,95);
		Player.Position.Set((GAME->Parameter.Width/2)-Player.Dimension.Width,0);
		Computer.Position.Set((GAME->Parameter.Width/2)-Computer.Dimension.Width,GAME->Parameter.Height-Computer.Dimension.Height);
		Computer.SetPicture(ENEMY);
		for(int i=0;i<6;i++)Wall[i].SetPicture(MUR);
		}
	if(lvl ==LVL_TWO)
		{
		BackGroundLvl.Color.Set(100,0,0,100);
		FIREPOS = 34;
		currentlvl=2;
		CFIRE.Dimension.Set(32,86);
		SNDFIRE.Open("DATA\\FIRE2.wav");
		CFIRE1.Dimension.Set(32,86);
		SND.Stop();
		SND.Open("Data\\Music2.ogg");
		SND.Play();
		tga_loader.LoadOpenGLTexture("Data\\MUR2.tga", &MUR, filtering);
		tga_loader.LoadOpenGLTexture("Data\\FIRE2.tga", &FIRE, filtering);
		tga_loader.LoadOpenGLTexture("Data\\ENEMY2.tga", &ENEMY, filtering);
		Computer.Color.Set(100,100,100,100);
		CFIRE.SetPicture(FIRE);
		CFIRE1.SetPicture(FIRE);
		CFIRE.Init(6,1,1000);
		CFIRE1.Init(6,1,1000);
		Life = 10;
		score.Dimension.Set(Life*40,20);
		Player.Position.Set((GAME->Parameter.Width/2)-Player.Dimension.Width,0);
		Computer.Dimension.Set(85,68);
		Computer.Position.Set((GAME->Parameter.Width/2)-Computer.Dimension.Width,GAME->Parameter.Height-Computer.Dimension.Height);
		Computer.SetPicture(ENEMY);
		for(int i=0;i<6;i++)Wall[i].SetPicture(MUR);
		}
	if(lvl ==LVL_TREE)
		{
		BackGroundLvl.Color.Set(0,0,100,100);
		CFIRE.Dimension.Set(32,64);
		CFIRE1.Dimension.Set(32,64);
		FIREPOS = 74;
		currentlvl=3;
		Computer.Color.Set(90,0,90,100);
		SND.Stop();
		SNDFIRE.Open("DATA\\FIRE3.wav");
		SND.Open("Data\\Music3.ogg");
		SND.Play();
		tga_loader.LoadOpenGLTexture("Data\\MUR3.tga", &MUR, filtering);
		tga_loader.LoadOpenGLTexture("Data\\FIRE3.tga", &FIRE, filtering);
		tga_loader.LoadOpenGLTexture("Data\\ENEMY3.tga", &ENEMY, filtering);
		
		CFIRE.SetPicture(FIRE);
		CFIRE1.SetPicture(FIRE);
		CFIRE.Init(4,1,1000);
		CFIRE1.Init(4,1,1000);
	
		Life = 10;
		score.Dimension.Set(Life*40,20);
		Computer.Dimension.Set(96,80);
		Player.Position.Set((GAME->Parameter.Width/2)-Player.Dimension.Width,0);
		Computer.Position.Set((GAME->Parameter.Width/2)-Computer.Dimension.Width,GAME->Parameter.Height-Computer.Dimension.Height);
		Computer.SetPicture(ENEMY);
		for(int i=0;i<6;i++)Wall[i].SetPicture(MUR);
		}
	}


void DrawExplosion()
	{
	if (EXPLD_ANI==EXPLD_PLAYER)
		{

		Explod.Draw();

		if(Explod.GetFrame()>9)
			{
			Player.Visible=true;
			EXPLD_ANI =EXPLD_NOTHING;
			Explod.SetFrame(0);
			}
		Explod.Update(50);
		}

	if (EXPLD_ANI==EXPLD_COMPUTER + EXPLD_PLAYER)
		{

		ExplodC.Draw();

		if(ExplodC.GetFrame()>9)
			{
			Computer.Visible=true;
			EXPLD_ANI =EXPLD_ANI - EXPLD_COMPUTER;
			ExplodC.SetFrame(0);
			}
		ExplodC.Update(50);

		Explod.Draw();

		if(Explod.GetFrame()>9)
			{
			Player.Visible=true;
			EXPLD_ANI =EXPLD_ANI - EXPLD_PLAYER;
			Explod.SetFrame(0);
			}
		Explod.Update(50);
		}
	
if (EXPLD_ANI==EXPLD_COMPUTER)
	{
	ExplodC.Draw();

	if(ExplodC.GetFrame()>9)
		{
		Computer.Visible=true;
		EXPLD_ANI =EXPLD_NOTHING;
		ExplodC.SetFrame(0);
		}
	ExplodC.Update(50);
	}

	}

void DrawPauses()
	{
	if (CURRENT_FORM==IN_PAUSE)
		{
			if(BldPause>=100)bldf=-0.1;
			if(BldPause<=0)bldf=+0.1;		

			BldPause += bldf;

			Pausd.Color.Set(100,100,100,BldPause);
			Pausd.Draw();
		}
	}


void DrawItem()
{		
	if (CURRENT_FORM==IN_GAME)
		{
				BackGroundLvl.Draw();
				Player.Draw();
				Computer.Draw();
				score.Draw();
				FIRELUNSH();
				CFIRE.Draw();
				CFIRE1.Draw();
				PFIRE.Draw();
				for(int i=0;i<6;i++)Wall[i].Update(100);
				for(int i=0;i<6;i++)Wall[i].Draw();
				DrawExplosion();
		}
	DrawPauses();	
}

#endif