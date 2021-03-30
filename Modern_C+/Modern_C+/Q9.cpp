// 다음을 싱글톤으로 표현하시오
/*
class App
{
private:
	App();
	virtual ~App();
};
*/

class App
{
public:
	static App* MakeApp()
	{
		if (m_Instance == nullptr)
		{
			m_Instance = new App;
		}

		return m_Instance;
	}

	static void CleanApp()
	{
		if (m_Instance != nullptr)
		{
			delete m_Instance;
			m_Instance = nullptr;
		}
	}

private:
	App() {}
	virtual ~App() {}

	static App* m_Instance;
};

App* App::m_Instance = nullptr;

void main()
{
	App* app = App::MakeApp();

	App::CleanApp();
}