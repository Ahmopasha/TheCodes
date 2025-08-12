class Car
{
	public:
		virtual void start() = 0;
		
		virtual void run() = 0;
		
		virtual void stop() = 0;
};

//----------------------------------------------------------

class ECar : public Car
{
	public:
		virtual void charge() = 0;
};

//----------------------------------------------------------

class Tesla : public ECar
{
	public:
		void start() override
		{
			std::cout << "The Tesla just started.\n";
		}
		
		void run() override
		{
			std::cout << "The Tesla just started running.\n";
		}
		
		void stop() override
		{
			std::cout << "The Tesla just stopped.\n";
		}
		
		void charge() override
		{
			std::cout << "The Tesla just started charging.\n";
		}
};

//----------------------------------------------------------

class Audi : public Car
{
	public:
		void start() override
		{
			std::cout << "The Audi just started.\n";
		}
		
		void run() override
		{
			std::cout << "The Audi just started running.\n";
		}
		
		void stop() override
		{
			std::cout << "The Audi just stopped.\n";
		}
};

//----------------------------------------------------------

class Mercedes : public Car
{
	public:
		void start() override
		{
			std::cout << "The Mercedes just started.\n";
		}
		
		void run() override
		{
			std::cout << "The Mercedes just started running.\n";
		}
		
		void stop() override
		{
			std::cout << "The Mercedes just stopped.\n";
		}
		
		virtual void open_sunroof()
		{
			std::cout << "The sunroof of Mercedes just opened.\n";
		}
};

//----------------------------------------------------------

class Mercedes_S500 : public Mercedes
{
	public:
		void start() override
		{
			std::cout << "The Mercedes_S500 just started.\n";
		}
		
		void run() override
		{
			std::cout << "The Mercedes_S500 just started running.\n";
		}
		
		void stop() override
		{
			std::cout << "The Mercedes_S500 just stopped.\n";
		}
		
		void open_sunroof()
		{
			std::cout << "The sunroof of Mercedes_S500 just opened.\n";
		}
		
		void lock_differential()
		{
			std::cout << "The differential of Mercedes_S500 just locked.\n";
		}
};

//----------------------------------------------------------

inline Car* create_random_car()
{
	static std::mt19937 eng{ std::random_device{}() };
	static std::uniform_int_distribution<> dist{0, 3}; // '0' ve '3' rakamları dahildir.
	
	switch(dist(eng))
	{
		case 0: std::cout << "The Tesla case.\n"; return new Tesla;
		case 1: std::cout << "The Audi case.\n"; return new Audi;
		case 2: std::cout << "The Mercedes case.\n"; return new Mercedes;
		case 3: std::cout << "The Mercedes_S500 case.\n"; return new Mercedes_S500;
		default: return nullptr;
	}
}

//----------------------------------------------------------

void car_game(Car* carPtr)
{
	carPtr->start();
	carPtr->run();
	carPtr->stop();
	std::cout << "//----------------------------------------------------------\n";
}

//----------------------------------------------------------