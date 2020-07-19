#pragma once

#include "RE/MemoryManager.h"
#include "RE/hkArray.h"
#include "RE/hkVector4.h"


namespace RE
{
	class hkContactPoint;
	class hkpCharacterProxy;
	class hkpRigidBody;
	struct hkpRootCdPoint;
	struct hkpSimplexSolverInput;


	struct hkpCharacterObjectInteractionEvent
	{
	public:
		// members
		hkVector4	  position;			  // 00
		hkVector4	  normal;			  // 10
		float		  objectImpulse;	  // 20
		float		  timestep;			  // 24
		float		  projectedVelocity;  // 28
		float		  objectMassInv;	  // 2C
		hkpRigidBody* body;				  // 30
		UInt64		  pad38;			  // 38
	};
	STATIC_ASSERT(sizeof(hkpCharacterObjectInteractionEvent) == 0x40);


	struct hkpCharacterObjectInteractionResult
	{
	public:
		// members
		hkVector4 objectImpulse;	// 00
		hkVector4 impulsePosition;	// 10
	};
	STATIC_ASSERT(sizeof(hkpCharacterObjectInteractionResult) == 0x20);


	class hkpCharacterProxyListener
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpCharacterProxyListener;


		virtual ~hkpCharacterProxyListener();  // 00

		// add
		virtual void ProcessConstraintsCallback(const hkpCharacterProxy* a_proxy, const hkArray<hkpRootCdPoint>& a_manifold, hkpSimplexSolverInput& a_input);				   // 01 - { return; }
		virtual void ContactPointAddedCallback(const hkpCharacterProxy* a_proxy, const hkpRootCdPoint& a_point);															   // 02 - { return; }
		virtual void ContactPointRemovedCallback(const hkpCharacterProxy* a_proxy, const hkpRootCdPoint& a_point);															   // 03 - { return; }
		virtual void CharacterInteractionCallback(hkpCharacterProxy* a_proxy, hkpCharacterProxy* a_otherProxy, const hkContactPoint& a_contact);							   // 04 - { return; }
		virtual void ObjectInteractionCallback(hkpCharacterProxy* a_proxy, const hkpCharacterObjectInteractionEvent& a_input, hkpCharacterObjectInteractionResult& a_output);  // 05 - { return; }

		TES_HEAP_REDEFINE_NEW();
	};
	STATIC_ASSERT(sizeof(hkpCharacterProxyListener) == 0x8);
}
