#include <iostream>

class triangle
{
private : 
	float   hight;
	float   width;

public : 
	triangle(float h = 0.0f, float w = 0.0f) : hight(h), width(w) {};

	void	show(void)
	{
		std::cout << "width : " << width << "  |  hight : " << hight << std::endl;
	}

	triangle	operator+(const triangle &c1)
	{
		triangle c;

		c.hight = this->hight + c1.hight;
		c.width = this->width + c1.width;

		return (c);
	}

	triangle&	operator=(const triangle &c1)
	{
		if (this != &c1)
		{
			this->hight = c1.hight;
			this->width = c1.width;
		}
		return (*this);
	}
};

/*

		3. Unary Operator Overloading

		+ (unary plus)

		- (unary minus)

		++ (increment)

		-- (decrement)

		! (logical NOT)

		~ (bitwise NOT)
*/

class Number {
private:
	int value;

public:
	Number(int v = 0) : value(v) {}

	// Overload unary minus
	Number operator-() const
	{
		return Number(-value);
	}
	void show() const { std::cout << value << std::endl;}
};

class Counter 
{
private:
	int value;
public:
	Counter(int v = 0) : value(v) {}

	// Prefix increment (++obj)
	Counter& operator++()
	{
		++value;
		return *this;
	}

	// Postfix increment (obj++)
	Counter operator++(int)
	{
		Counter temp = *this;
		value++;
		return temp;
	}

	void show() const { std::cout << value << std::endl;}
};

int main()
{
	triangle c1(2.0), c2(3.37, 1.337), c3;

	c1.show();
	c2.show();
	c3.show();

	c3 = c1 + c2;

	c3.show();

	return (0);
}

