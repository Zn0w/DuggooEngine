#pragma once

namespace dg { namespace app {
	
	class Application
	{
	public:
		bool running = false;

		// Struct(containing renderer and maybe window)
		
		void start();

		virtual void onInit() = 0;
		virtual void onUpdate() = 0;
		virtual void onDestroy() = 0;
	};

} }