#pragma once
class Deliver
{
public:
	Deliver(void);
	~Deliver(void);
	Deliver(int _max, int _A, int _B, int _C, int _D, int _E, int _F, int _G, int _H, int _I, int _J, int _count_type); // 입력 받는 값을 설정
	void set_A(int _A){d_A = _A;}; // A값 설정
	void set_B(int _B){d_B = _B;};
	void set_C(int _C){d_C = _C;}; 
	void set_D(int _D){d_D = _D;}; 
	void set_E(int _E){d_E = _E;}; 
	void set_F(int _F){d_F = _F;}; 
	void set_G(int _G){d_G = _G;}; 
	void set_H(int _H){d_H = _H;}; 
	void set_I(int _I){d_I = _I;}; 
	void set_J(int _J){d_J = _J;};
	void set_count(int _count){count_type = _count;};
	void set_max(int _max){max = _max;};
	int Get_max(){return max;};
	int Get_count(){return count_type;}
	int Get_A(){return d_A;}; // A 값 리턴
	int Get_B(){return d_B;};
	int Get_C(){return d_C;};
	int Get_D(){return d_D;};
	int Get_E(){return d_E;};
	int Get_F(){return d_F;};
	int Get_G(){return d_G;};
	int Get_H(){return d_H;};
	int Get_I(){return d_I;};
	int Get_J(){return d_J;};




private:
	// 각 장소로 배달 해야 할 물품
	int max; // 최대로 실을 수 있는 물품의 양
	int count_type; // 현재 택배 차의 위치를 알려줌
	int d_A; // A로 배달 해야 할 물품
	int d_B;
	int d_C;
	int d_D;
	int d_E;
	int d_F;
	int d_G;
	int d_H;
	int d_I;
	int d_J;
	
	
};

