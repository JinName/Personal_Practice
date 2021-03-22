#pragma once

// 기본 템플릿
template <typename T1, typename T2>
class ClassTemplate {};

// 명시적 템플릿 특수화
template <>
class ClassTemplate<int, double> {}; // int 형 선언에 대한 명시적 템플릿 특수화

// 부분 템플릿 특수화
template <typename T1>
class ClassTemplate<T1, double> {};

// 템플릿 상속 
// ex) 싱글톤 템플릿을 활용해 상속으로 새로운 싱글톤 클래스를 만드는 형식
template <typename T>
class Base {};

class Derived : public Base<Derived> {};

template <typename C1, typename C2>
void sum() {};

// 템플릿 함수 부분특수화는 지원하지않음.
// 함수 오버로딩을 통해 해결해야함.
template <typename C1>
void sum<C1, int>() {}; // x