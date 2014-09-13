#ifndef collision_H
#define collision_H

void TestCollision()
	{	
	//Collision JOEUR ET COMPUTER AVEC LES MURS
	if (Player.Position.X>GAME->Parameter.Width-Player.Dimension.Width) Player.Position.X =GAME->Parameter.Width-Player.Dimension.Width;
	if (Computer.Position.X>GAME->Parameter.Width-Computer.Dimension.Width) Computer.Position.X =GAME->Parameter.Width-Computer.Dimension.Width;
	if (Player.Position.X<0) Player.Position.X =0;
	if (Computer.Position.X<0) Computer.Position.X =0;

	if (Player.Position.Y>GAME->Parameter.Height-Player.Dimension.Height) Player.Position.Y =GAME->Parameter.Height-Player.Dimension.Height;
	if (Computer.Position.Y>GAME->Parameter.Height-Computer.Dimension.Height) Computer.Position.Y =GAME->Parameter.Height-Computer.Dimension.Height;
	if (Player.Position.Y<0) Player.Position.Y =0;
	if (Computer.Position.Y<0) Computer.Position.Y=0;

	/*******************************/
	if (Col.IfCollision(Player,Computer))
		{
		SNDEXPL.Play(5);
		Player.Visible=false;
		Computer.Visible=false;
		CWMX = Opr.Random<int>(0,GAME->Parameter.Width-Computer.Dimension.Width);
		Explod.Position.Set(Computer.Position);
		ExplodC.Position.Set(Player.Position);
		Player.Position.Set((GAME->Parameter.Width/2)-Player.Dimension.Width,0);	
		Computer.Position.Set((GAME->Parameter.Width/2)-Computer.Dimension.Width,GAME->Parameter.Height-Computer.Dimension.Height);
		EXPLD_ANI = EXPLD_PLAYER + EXPLD_COMPUTER;
		Explod.SetFrame(0);
		ExplodC.SetFrame(0);
		}
/*******************************/
	for(int i=0;i<6;i++)
		if (Col.IfCollision(Player,Wall[i]))
			{
			SNDEXPL.Play(6);
			Life -=1;
			score.Dimension.Set(Life*40,20);
			Player.Visible=false;
			Explod.Position.Set(Player.Position);
			Player.Position.Set((GAME->Parameter.Width/2)-Player.Dimension.Width,0);	
			EXPLD_ANI = EXPLD_ANI + EXPLD_PLAYER;
			Explod.SetFrame(0);
			if (Life<=0)GAMEOVER();
			}
/*******************************/
		if (Col.IfCollision(Computer,PFIRE))
			{
			if (Computer.Visible==true)
				{
					if(PFIRE.Visible==true)
						{
						SNDFIREP.Stop(1);
						SNDEXPL.Play(7);
						Life +=1;
						score.Dimension.Set(Life*40,20);
						Computer.Visible=false;
						CWMX = Opr.Random<int>(0,GAME->Parameter.Width-Computer.Dimension.Width);
						PFIRE.Visible=false;
						ExplodC.Position.Set(Computer.Position);
						Computer.Position.Set((GAME->Parameter.Width/2)-Computer.Dimension.Width,GAME->Parameter.Height-Computer.Dimension.Height);
						EXPLD_ANI = EXPLD_ANI + EXPLD_COMPUTER;
						ExplodC.SetFrame(0);
						if (Life>=20)WINNER();
						}
				}
			}
		
		/*******************************/
		if (Col.IfCollision(Player,CFIRE))
			{
			if (Player.Visible==true)
				{
				if(CFIRE.Visible==true)
					{
					SNDFIRE.Stop(4);
					SNDEXPL.Play(8);
				Life -=1;
				score.Dimension.Set(Life*40,20);
				Player.Visible=false;
				CFIRE.Visible=false;
				Explod.Position.Set(Player.Position);
				Player.Position.Set((GAME->Parameter.Width/2)-Player.Dimension.Width,0);	
				EXPLD_ANI = EXPLD_ANI + EXPLD_PLAYER;
				Explod.SetFrame(0);
				if (Life<=0)GAMEOVER();
				}
				}
			}
		if (Col.IfCollision(Player,CFIRE1))
			{
			if (Player.Visible==true)
				{
				if(CFIRE1.Visible==true)
					{
					SNDFIRE.Stop(3);
					SNDEXPL.Play(9);
					Life -=1;
					score.Dimension.Set(Life*40,20);
					Player.Visible=false;
					CFIRE1.Visible=false;
					Explod.Position.Set(Player.Position);
					Player.Position.Set((GAME->Parameter.Width/2)-Player.Dimension.Width,0);	
					EXPLD_ANI = EXPLD_ANI + EXPLD_PLAYER;
					Explod.SetFrame(0);
					if (Life<=0)GAMEOVER();
					}
				}
			}
		/********************************/
		for(int i=0;i<6;i++)
			if (Col.IfCollision(PFIRE,Wall[i]))
				{
				SNDFIREP.Stop(1);
				PFIRE.Visible=false;
				}
			/********************************/
							
				for(int i=0;i<6;i++)
					if (Col.IfCollision(CFIRE,Wall[i]))
						{
						SNDFIRE.Stop(4);
						CFIRE.Visible=false;
					
						}
					for(int i=0;i<6;i++)
						if (Col.IfCollision(CFIRE1,Wall[i]))
							{
							SNDFIRE.Stop(3);
							CFIRE1.Visible=false;
					
							}
					/********************************/
					if (Col.IfCollision(CFIRE,PFIRE))
						{
						SNDFIRE.Stop(4);
						SNDFIREP.Stop(1);
						CFIRE.Visible=false;
						PFIRE.Visible=false;
						
						}
					if (Col.IfCollision(CFIRE1,PFIRE))
						{
						SNDFIRE.Stop(3);
						SNDFIREP.Stop(1);
						CFIRE1.Visible=false;
						PFIRE.Visible=false;
						
						}
	}

#endif