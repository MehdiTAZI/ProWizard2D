#ifndef computer_H
#define computer_H

void ComputerMovement()
	{
	if (CWMXACTIVE==false)
		{
		T.UpDate();
		//si seconde est :  0 < s < 10 ou 20<s<30 ou 40<s<50
		if (  T.Seconde < 10 || T.Seconde < 30 && T.Seconde > 20 || T.Seconde < 50 && T.Seconde > 40 )CWMX = Opr.Random<int>(0,GAME->Parameter.Width-Computer.Dimension.Width);
		}

	Computer.SetFrame(2);
	if (Computer.Position.X!=CWMX)
		{
		if (Computer.Position.X>CWMX)
			{	
			Computer.SetFrame(0);
			Computer.Position.X -=1;
			}

		if (Computer.Position.X<CWMX)
			{
			Computer.SetFrame(1);
			Computer.Position.X +=1;
			}

		CWMXACTIVE = true;		
		}
	else
		{
		CWMXACTIVE=false;
		}
	}


void ComputerFire()
	{
	if (Player.Position.X>Computer.Position.X && Player.Position.X<Computer.Position.X+Computer.Dimension.Width || Computer.Position.X>Player.Position.X && Computer.Position.X<Player.Position.X+Player.Dimension.Width)
		{
		if(CFIRE1.Visible==false)
			{	

			SNDFIRE.Play(3);

			CFIRE1.Position.Set(Computer.Position.X,(Computer.Position.Y-Computer.Dimension.Height)+FIREPOS);
			DEFEULT_C_MISSILE=COMPUTER_FIRE;
			CFIRE1.Visible=true;
			}
		if(CFIRE.Visible==false)
			{	

			SNDFIRE.Play(4);

			CFIRE.Position.Set(Computer.Position.X+Computer.Dimension.Width-10,(Computer.Position.Y-Computer.Dimension.Height)+FIREPOS);
			DEFEULT_C_MISSILE=COMPUTER_FIRE;
			CFIRE.Visible=true;
			}
		}

	}
void ComputerIA()
	{

	if(Computer.Visible==true)
		{
			ComputerMovement();
			ComputerFire();
		}

	}




void WALLMOVE()
	{
	for (int i=0 ;i<3;i++)
		{
		if (Wall[i].Position.X>GAME->Parameter.Width)Wall[i].Position.X=0;
		Wall[i].Position.X +=1;
		}
	for (int i=3 ;i<6;i++)
		{
		if (Wall[i].Position.X<0)Wall[i].Position.X=GAME->Parameter.Width;
		Wall[i].Position.X -=1;
		}
	}



#endif