#pragma once

namespace dg { namespace app {
	
	class Application
	{
	public:
		bool running = false;
		
		void start();

		virtual void onInit() = 0;
		virtual void onUpdate() = 0;
		virtual void onDestroy() = 0;
	};

} }