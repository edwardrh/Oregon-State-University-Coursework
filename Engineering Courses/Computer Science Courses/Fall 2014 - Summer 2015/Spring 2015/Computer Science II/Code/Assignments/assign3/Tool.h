#ifndef TOOL_H
#define TOOL_H

class Tool{
	private:
		int strength;
		char type;
	public:
		Tool();
		virtual void setStrength(int);
};

#endif