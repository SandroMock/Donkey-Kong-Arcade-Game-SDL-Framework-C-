/*****************************************************************************
* Project: SDLFramework
* File   : CircCollObject.h
* Date   : 26.02.2020
* Author : Marcus Schaal (MS)
*
* These coded instructions, statements, and computer programs contain
* proprietary information of the author and are protected by Federal
* copyright law. They may not be disclosed to third parties or copied
* or duplicated in any form, in whole or in part, without the prior
* written consent of the author.
*
* History:
*	26.02.20	MS	Created
*	01.03.20	MS	+Getter/Setter
*	04.03.20	MS	+SetCollPos
******************************************************************************/
#pragma once
#include "GameObject.h"
#include "CircleCollider.h"

class CCircCollObject :
	public CGameObject
{
public:
	/*************************************************************************/
	// Getter/Setter
	/*************************************************************************/
	//Getter
	inline float GetRadius() { return m_pCircleCollider->GetRadius(); }

	inline CCircleCollider& GetCollider() //Collider
	{
		return *m_pCircleCollider;
	}

	//Setter
	inline float SetCollX( float _x ) 
	{ 
		return m_pCircleCollider->SetCollX( _x ); 
	}

	inline float SetCollY( float _y ) 
	{ 
		return m_pCircleCollider->SetCollY( _y ); 
	}

	inline void SetCollPos( float _x, float _y )
	{
		m_pCircleCollider->SetCollPos( _x, _y );
	}

	inline void SetRadius( float _radius ) 
	{ 
		m_pCircleCollider->SetRadius( _radius ); 
	}
	/*************************************************************************/

	/*************************************************************************/
	//Engine-Methoden
	/*************************************************************************/
	int Initialize( float _x, float _y, int _w, int _h );
	int Update();
	void Finalize();
	/*************************************************************************/

private:
	/*************************************************************************/
	//Attribute
	/*************************************************************************/
	//Komponenten
	CCircleCollider* m_pCircleCollider = nullptr;
	/*************************************************************************/
};

