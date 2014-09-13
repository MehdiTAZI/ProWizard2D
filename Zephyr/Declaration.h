#ifndef Declaration_H
#define Declaration_H

int CURRENT_FORM,currentlvl,FIREPOS,DEFEULT_MISSILE, DEFEULT_C_MISSILE,CWMX,Life,EXPLD_ANI;
bool BEGIN,CWMXACTIVE,fs;

TGALoader tga_loader;
TGAFiltering filtering;
extern ProWiz::MainApp* GAME;
void GAMEOVER();
void WINNER();
void INITLVL(int lvl);
void FINAl();

ProWiz::Math::Operations Opr;
ProWiz::Tools::Time T;
ProWiz::Physics::Collision<float> Col;
ProWiz::SoundManager::SoundEngine SND,SNDEXPL,SNDFIRE,SNDFIREP;
ProWiz::GraphicsManager::Drawing::GeometryObjects::Rectangle<float> IntroScrenn,Pausd,score;
ProWiz::GraphicsManager::Drawing::Sprite<float> Player,Computer,Explod,ExplodC,CFIRE,CFIRE1,PFIRE,*Wall ;
ProWiz::GraphicsManager::Drawing::GeometryObjects::Scroller<float> BackGroundLvl;
ProWiz::State::State STAT;
float BldIntro,BldPause,bldf;
GLuint INTRO,PLAYER,PFIREW,EXPLOD,PAUSE,MUR, FIRE ,ENEMY,LVL ;
#endif