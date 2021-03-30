// 5. 프로그램의 잘못된 부분을 수정하시오

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

// 정답 : int Total() -> int Total() const

// 상수 함수에서 다른 멤버함수를 호출할때, 호출하는 함수 또한 상수 함수여야 한다.