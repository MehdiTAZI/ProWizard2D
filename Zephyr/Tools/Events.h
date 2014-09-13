#ifndef Events_H
#define Events_H

class PW_Events
{
protected:
	// Variable heritables
	unsigned char*	pKeyBoard;	// Le clavier
	PWI_Vector2D MousePos;		// Position de la souris
	bool MouseState[3];			// Etat des boutons	
	PW_Events()
	{
	}
	virtual ~ PW_Events()
	{
	}
public : 

	/*
	Methodes a surcharger pour permettre la gestion des differentes phases du Moteur
	*/
	
    virtual void OnActivate () = 0;
	
	virtual void OnClick () = 0;
	

	virtual void OnMouseUp(int Key) = 0;
	virtual void OnMouseDown(int Key) = 0;
	virtual void OnMouseMove() = 0;

	virtual void OnInit () = 0;

	virtual void OnKeyPress (int Key) = 0;
	virtual void OnKeyDown (int Key) = 0;
	virtual void OnKeyUp (int Key) = 0;

	virtual void Update () = 0;
	virtual void Draw () = 0;
	virtual void OnResize ()=0;
	virtual void OnExit ()=0;
	

};
#endif