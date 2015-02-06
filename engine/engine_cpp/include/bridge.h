#ifndef _VOIDUM_BRIDGE_
#define _VOIDUM_BRIDGE_

#include "base.h"
#include <list>

namespace voidum
{
	class Driver;
	class Locator;

	class VOIDUM_API Bridge
	{
	public:
		//find bridge by name
		static Bridge* Find(const text& name);

	protected:
		text _Name;
		text _EndPoint;
		std::list<Locator*> _Locators;

	public:
		Bridge(const text& name);
		virtual ~Bridge();

	public:
		//get alias name
		const text& GetName();

		//get end point
		const text& GetEndPoint();

		//get locator by target + source
		Locator* GetLocator(int target, const text& source);

	public:
		//get host mode
		virtual int GetHostMode() = 0;

		//create locator
		virtual Locator* CreateLocator() = 0;

	public:
		//connect to endpoint
		virtual bool Connect(const text& endpoint) = 0;

		//match driver for target
		virtual Driver* Match(const text& target) = 0;

	public:
		//enable bridge
		void Enable();

		//disable bridge
		void Disable();
	};
}

#endif