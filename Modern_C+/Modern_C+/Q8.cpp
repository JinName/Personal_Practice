// ������ ��ĭ�� �ϼ��Ͻÿ�.

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

// ���� : friend class Factory; ??