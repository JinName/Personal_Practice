#pragma once

// �⺻ ���ø�
template <typename T1, typename T2>
class ClassTemplate {};

// ����� ���ø� Ư��ȭ
template <>
class ClassTemplate<int, double> {}; // int �� ���� ���� ����� ���ø� Ư��ȭ

// �κ� ���ø� Ư��ȭ
template <typename T1>
class ClassTemplate<T1, double> {};

// ���ø� ��� 
// ex) �̱��� ���ø��� Ȱ���� ������� ���ο� �̱��� Ŭ������ ����� ����
template <typename T>
class Base {};

class Derived : public Base<Derived> {};

template <typename C1, typename C2>
void sum() {};

// ���ø� �Լ� �κ�Ư��ȭ�� ������������.
// �Լ� �����ε��� ���� �ذ��ؾ���.
template <typename C1>
void sum<C1, int>() {}; // x