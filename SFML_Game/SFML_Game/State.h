#ifndef STATE_H
#define STATE_H


class State
{
public:
	virtual void Init() = 0;
	virtual void HandleInput() = 0; //³apanie zdarzeñ
	virtual void Update(float dt) = 0;
	virtual void Render() = 0; // generowanie i wyœwietlanie
};

#endif