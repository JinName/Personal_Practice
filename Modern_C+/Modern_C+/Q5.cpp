// 5. ���α׷��� �߸��� �κ��� �����Ͻÿ�

class Foo
{
public:
	void Set(int _k, int _m) { k = _k, m = _m; }
	int GetK() const { return k; }
	int GetM() const { return m; }
	int GetAvr() const { return Total() / 2; }

private:
	int Total() { return k + m; }

	int k;
	int m;
};

// ���� : int Total() -> int Total() const

// ��� �Լ����� �ٸ� ����Լ��� ȣ���Ҷ�, ȣ���ϴ� �Լ� ���� ��� �Լ����� �Ѵ�.