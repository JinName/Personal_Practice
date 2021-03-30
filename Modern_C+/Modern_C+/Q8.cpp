// 다음의 빈칸을 완성하시오.

class Factory
{
public:
	Stu* MakeStud();
};

class Stu
{
	//_____________________?

private:
	Stu();
	virtual ~Stu();
};

// 정답 : friend class Factory; ??