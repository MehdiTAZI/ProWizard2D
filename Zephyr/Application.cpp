#include "ProWiz.h"
#include"Declaration.h"
#include "Collision.h"
#include "Computer.h"
#include"Intro.h"
#include"GAME.H"
int rfrsh;
/*
Fonctions de mise a jour des variables et de dessin
*/

	void ProWiz::MainApp :: Update()
	{	

	if(SND.GetCurrentPosition()>=SND.GetLength() || SND.GetCurrentPosition() <0 )SND.Play();
	if (CURRENT_FORM==IN_GAME)
		{
		Player.SetFrame(2);
		if (GAME->pKeyBoard[ProWiz::KeyCode::LEFT])
			{
			if(Player.Visible==true)
				{
				Player.SetFrame(0);
				Player.Position.X -= 1;
				}
			}
			
		if (GAME->pKeyBoard[ProWiz::KeyCode::RIGHT])
			{
			if(Player.Visible==true)
				{
				Player.Position.X += 1;
				Player.SetFrame(1);
				}
				
			}
			
		if (GAME->pKeyBoard[ProWiz::KeyCode::DOWN])
			{
			if(Player.Visible==true)Player.Position.Y -= 1;
			}
			
		if (GAME->pKeyBoard[ProWiz::KeyCode::UP])
			{
			if(Player.Visible==true)Player.Position.Y += 1;
			}

		}
	}	
	void ProWiz::MainApp :: Draw() 
	{
	if (BEGIN==true)
		{
		if (CURRENT_FORM==IN_MENU)
			{
			STAT.Enable(ProWiz::State::BLENDING);
			Intro();

			}
		
			{


			if (CURRENT_FORM==IN_GAME)
				{
				TestCollision();
				ComputerIA();
				WALLMOVE();
				}
			STAT.Enable(ProWiz::State::ALPHA_TEST);
			STAT.Enable(ProWiz::State::TRANSPATENCY);
			STAT.Enable(ProWiz::State::BLENDING);
			
			DrawItem();
			Sleep(rfrsh);

			}
		}
	}

	/*Evenements */
	void ProWiz::MainApp :: OnActivate()
	{

	}

	void ProWiz::MainApp :: OnClick()
	{
	
	}
	
	void ProWiz::MainApp :: OnMouseUp(int Key)
	{
	
	}
	
	void ProWiz::MainApp :: OnMouseDown(int Key)
	{
				
	}
	
	void ProWiz::MainApp :: OnMouseMove()
	{

	}

	void ProWiz::MainApp :: OnJoyAxisMove(int XValue,int YValue)
	{
	
	}

	void ProWiz::MainApp :: OnJoyButtonDown(int Button)
	{
	
	}	

	void ProWiz::MainApp :: OnJoyButtonUp(int Button)
	{
		//Bug 2Joy-> les deux ce declanche
	}

	void ProWiz::MainApp :: OnJoyBallMove(int XValue,int YValue)
	{
		
	}

	void ProWiz::MainApp :: OnJoyHat(int Direction)
	{
	
	}

	void ProWiz::MainApp :: OnInit()
	{	
	Initialise();
	BEGIN=true;
	}
	
	void ProWiz::MainApp :: OnKeyPress(int Key)
	{
	
	if (Key!=ProWiz::KeyCode::ESCAPE)
		{
		if (CURRENT_FORM==IN_MENU)
			{
			if (Key!=ProWiz::KeyCode::p)
				{
				INITLVL(LVL_ONE);
				CURRENT_FORM = IN_GAME;
				}

			}
		if (CURRENT_FORM==IN_GAME)
			{
			if(Key==ProWiz::KeyCode::_1)Player.Color.Set(100,100,100,100);
			if(Key==ProWiz::KeyCode::_2)Player.Color.Set(100,0,0,100);
			if(Key==ProWiz::KeyCode::_3)Player.Color.Set(0,100,0,100);
			if(Key==ProWiz::KeyCode::_4)Player.Color.Set(0,0,100,100);
			if(Key==ProWiz::KeyCode::_5)Player.Color.Set(100,100,100,70);
			if(Key==ProWiz::KeyCode::_6)Player.Color.Set(100,100,100,40);
			if(Key==ProWiz::KeyCode::_7)Player.Color.Set(100,0,100,100);
			if(Key==ProWiz::KeyCode::_8)Player.Color.Set(100,100,0,100);
			if(Key==ProWiz::KeyCode::_9)Player.Color.Set(0,100,100,50);
				if(Key==ProWiz::KeyCode::F1)
				 {
					currentlvl=1;
					INITLVL(currentlvl);
				 }
			 if(Key==ProWiz::KeyCode::F2)
				 {
				 currentlvl=2;
				 INITLVL(currentlvl);
				 }
			 if(Key==ProWiz::KeyCode::F3)
				 {
				 currentlvl=3;
				 INITLVL(currentlvl);
				 }
	if(Player.Visible==true)
	{
			if (Key==ProWiz::KeyCode::z)
				{
					if(PFIRE.Visible==false)
						{
						SNDFIREP.Play(1);
						PFIRE.Color.Set(100,100,100,100);
						PFIRE.Position.Set(Player.Position.X+(Player.Dimension.Width/2)-PFIRE.Dimension.Width/2,(Player.Position.Y+Player.Dimension.Height)-30);
						DEFEULT_MISSILE=PLAYER_FIRE1;
						PFIRE.Visible=true;
						}
				}
			if (Key==ProWiz::KeyCode::x )
				{
				if(PFIRE.Visible==false)
					{

					SNDFIREP.Play(1);
					PFIRE.Color.Set(0,100,0,100);
					PFIRE.Position.Set(Player.Position.X+(Player.Dimension.Width/2)-PFIRE.Dimension.Width/2,(Player.Position.Y+Player.Dimension.Height)-30);
					DEFEULT_MISSILE=PLAYER_FIRE2;
					PFIRE.Visible=true;
					
					}
				}
	}
			}
		}
	else
		{GAME->Quit();}


	}


	void ProWiz::MainApp :: OnKeyDown(int Key)
	{

	}
	void ProWiz::MainApp :: OnKeyUp(int Key)
	{
	if(CURRENT_FORM !=IN_MENU )
		{
		if (Key==ProWiz::KeyCode::p)
			{
				SND.SetPaused(!SND.GetPaused());
				if (CURRENT_FORM==IN_GAME){CURRENT_FORM=IN_PAUSE;return;}
				if (CURRENT_FORM==IN_PAUSE){CURRENT_FORM=IN_GAME;return;}
			}
		}

	}

	void ProWiz::MainApp :: OnResize()
	{

	}
	void ProWiz::MainApp :: OnExit()
	{
	STAT.Disable(ProWiz::State::ALPHA_TEST);
	STAT.Disable(ProWiz::State::TRANSPATENCY);
	STAT.Disable(ProWiz::State::BLENDING);
			Destroy();
	}
	ProWiz::MainApp* GAME = new ProWiz::MainApp;

	int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
	{
			
			if(MessageBox(0,"Would you like to start game with full screen mode parameter?","FullScreen ?",MB_YESNO|MB_ICONQUESTION)==IDYES)fs=true;
			CURRENT_FORM = IN_MENU;
			if(MessageBox(0,"Would you like to use Refresh Time based on FPS Speed or Hardward Speed","FPS TIME ?",MB_YESNO|MB_ICONQUESTION)==IDYES)rfrsh=10;
				
			GAME->Init(800,600,32, fs,false,"c:\p.bmp");

			GAME->Run();

			delete GAME;
 			return 0;
	}
	